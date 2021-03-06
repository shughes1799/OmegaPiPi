{
  TString HSANA(gSystem->Getenv("HSANA"));
  gROOT->LoadMacro(HSANA+"/MakeHSSelector.C");

  //Set arguments for MakeHSSelector
 IsHisto=kTRUE;  //use THSHisto?
 IsAppendTree=kFALSE; //Append branches to the input tree
 IsNewTree=kFALSE;  //Output a brand new tree
 IsHSTree=kFALSE;   //Use THSOuput to THSParticle interface (probably not)
 FileName="/home/dglazier/Work/Research/HaSpect/data/g11pippippim_missn_HS/inp2_50.root";   // The input filename containing the tree
 TreeName="HSParticles";   // The name of the tree
 OutName="/home/dglazier/Work/Research/HaSpect/data/g11pippippim_missn_HS/Histo2.root";   // The name of the output directory or file
 SelName="ThreePiHisto2";    // The name of the selector to be produced

 //Make the selector skeleton + control files in this directory 
 //This is based on the info given above
 MakeHSSelector();

}
