{
  TProof::Open("workers=2");
  TChain *mc_edgen = new TChain("h10");
  //mc_edgen->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun*.root");
  mc_edgen->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/July2017/psTests/psTestRun*.root");
  // mc_edgen->SetProof();
  mc_edgen->Process("MCOpt.C++");


}
