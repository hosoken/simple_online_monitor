#ifndef RootHelper_h
#define RootHelper_h

#include <TROOT.h>
#include <TH1.h>
#include <TH2.h>
#include <TString.h>
#include <TGraph.h>

inline TH1F* HB1( int id, const char *title, 
		 int nbinx, double xlow, double xhigh )
{
  TH1F* h1 = new TH1F( Form("h%d",id), title, nbinx, xlow, xhigh );
  return h1;
}

inline TH2F* HB2( int id, const char *title,
		 int nbinx, double xlow, double xhigh,
		 int nbiny, double ylow, double yhigh )
{
  TH2F* h2 = new TH2F( Form("h%d",id), title, nbinx, xlow, xhigh,
			 nbiny, ylow, yhigh );
  return h2;
}

inline void HF1( const char *name, double x, double w=1.0 )
{
  if( TH1 *h = (TH1*)gROOT->FindObject(name) )
    h->Fill( x, w );
}

inline void HF1( int id, double x, double w=1.0 )
{
  HF1( Form("h%d",id), x, w );
}

inline void HF2( const char *name, double x, double y, double w=1.0 )
{
  if( TH2 *h = (TH2*)gROOT->FindObject(name) )
    h->Fill( x, y, w );
}

inline void HF2( int id, double x, double y, double w=1.0 )
{
  HF2( Form("h%d",id), x, y, w );
}

inline TGraph* GB1( int id, const char *title )
{
  TGraph *g = new TGraph();
  g->SetName(Form("g%d",id));
  g->SetTitle(title);
  return g;
}

inline void GF1( int id, double x)
{
  if( TGraph *g = (TGraph*)gROOT->FindObject(Form("g%d",id)) ){
    int gc = g->GetN();
    g->SetPoint(gc, gc, x);
  }
}

#endif
