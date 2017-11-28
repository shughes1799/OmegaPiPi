{
  //You need to have the enviroment variable HSANA defined to link to the THS source
  TString HSANA(gSystem->Getenv("HSANA"));
  gROOT->LoadMacro(HSANA+"/MakeHSSelector.C");

  //Set arguments for MakeHSSelector
 IsHisto=kTRUE;  //use THSHisto?
 IsAppendTree=kFALSE; //Append branches to the input tree
 IsNewTree=kFALSE;  //Output a brand new tree
 IsHSTree=kFALSE;   //Use THSOuput to THSParticle interface (probably not)
 IsQval=kFALSE;   //Use Qvalue event weighting algorithm
 IsSW=kTRUE;   //Use sWeights event weighting algorithm
 NLPS=0;   //Use Longitudinal phase space class with NLPS particles

 // FileName="/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root";   // The input filename containing the tree
 FileName="/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/Corrected_Data/16FilesCorrMissingPi0.root";
 TreeName="HSParticles";   // The name of the tree
 OutName="/home/s0677668/Haspect/MissingPi0/Events-master/Projects/MissingPi0/sWeights/sWPlotting";   // The name of the output directory or file
 SelName="Histo_sWeights_MissingPi0";    // The name of the selector to be produced

 //IsParent=kTRUE; //use connection with parent tree
 //StepN=0;        // If connecting with parent, which step number is its selector in
 //ParSel="";

 //Make the selector skeleton + control files in this directory 
 //This is based on the info given above
 MakeHSSelector();

}
