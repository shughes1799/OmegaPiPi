{
  TProof::Open("workers=2");
  TChain *mc_edgen = new TChain("h10");
  // mc_edgen->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun*.root");
  //mc_edgen->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/First_10mil/ps_flat_*.root");
  mc_edgen->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Main_100mil/ps_flat_*.root");
  mc_edgen->SetProof();
  mc_edgen->Process("analysis_acceptance3.C++");


}
