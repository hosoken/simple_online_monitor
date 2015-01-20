void UpdateCanvas(){
  TVirtualPad *pad =0;
  int pad_id =0;
  
  TCanvas *mother = gPad->GetCanvas();

  while ( pad = mother->GetPad(pad_id++) ){
    pad->Modified();
  }
  
  mother->Update();
}
