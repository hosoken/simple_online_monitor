void ResetAll(){
  TIter next( gDirectory->GetList() );
  
  TObject *obj=0;
  
  while(obj = next()){
    if(obj->IsA()->InheritsFrom("TH1")){
      ((TH1*)obj)->Reset();
    }else if(obj->IsA()->InheritsFrom("TH2")){
      ((TH2*)obj)->Reset();
    }
  }
  
}
