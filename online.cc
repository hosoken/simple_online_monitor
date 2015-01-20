#include <cstdio>
#include <cstdlib>

#include <TSystem.h>
#include <TApplication.h>
#include <TBrowser.h>
#include <TThread.h>
#include <TMacro.h>
#include <TRandom.h>

#include "RootHelper.h"

void defineHistgrams(TList *list){
  
  TObject *obj=0;
  
  for(int i=0;i<4;i++){
    obj = HB1(100+i,Form("ADC %02d",i),1000,0,1000);
    list->Add(obj);
  }
  
  return;
}

void defineMacros(TList *list){
  
  TMacro* m=0;

  m = new TMacro;
  m->AddLine("{gPad->GetCanvas()->Clear();"
	     "gPad->GetCanvas()->Update();}");
  m->SetName("Clear Canvas");
  list->Add(m);
  
  m = new TMacro;
  m->ReadFile("./Macros/UpdateCanvas.C");
  m->SetName("Update Canvas");
  list->Add(m);
  
  m = new TMacro;
  m->ReadFile("./Macros/ResetAll.C");
  m->ReadFile("./Macros/UpdateCanvas.C");
  m->SetName("Reset All");
  list->Add(m);

  return;
}

void decode(){
 
  HF1(100,gRandom->Gaus(200,10)); 
  HF1(101,gRandom->Gaus(400,10)); 
  HF1(102,gRandom->Gaus(600,10)); 
  HF1(103,gRandom->Gaus(800,10)); 
  
  return;
}

void* process(void*){
  while(1){
    usleep(10000);
    gSystem->ProcessEvents();
  }
  return 0;
}

int main(int argc,char **argv)
{
  gROOT->SetStyle("Default");
  TApplication theApp("App", 0, 0);
  TList *hist_list = new TList;
  hist_list->SetName("Histgrams");
  TBrowser browser("Browser",hist_list,"Online Monitor");

  defineHistgrams(hist_list);

  TList *macro_list = new TList;
  macro_list->SetName("Macros");

  defineMacros(macro_list);
  browser.Add(macro_list);
  

  TThread *t1 = new TThread("t1",process);
  t1->Run();

 
  while(1){
    usleep(1000);
    decode();
  }

  
  return 0;
}


