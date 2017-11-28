
{

  //TFile *f = new TFile("March2017Eta1295MCNormT0to1.root","RECREATE");
  //TFile *f = new TFile("March2017BasicNoOmegaMassCorrNormalisation.root","RECREATE");
  TFile *f = new TFile("Acceptance2017BaseFile.root","RECREATE");

 //TFile *myFile = TFile::Open("Dec2016TestRun4.root");
 // TFile *myFile = TFile::Open("Jan2017Normalisation2HalfWidthSB1675Rho.root");
 //TFile *myFile = TFile::Open("Dec2016TestRun10Bins.root");
 //TFile *myFile = TFile::Open("Feb2017NormPS10MilDataHalfWidthSB.root");
 // TFile *myFile = TFile::Open("Feb2017BinnedEgamma3p3to3p9.root");
 //TFile *myFile = TFile::Open("Feb2017BinnedT2to5.root");
 //TFile *myFile = TFile::Open("March2017Eta1295MCDataT0to1.root");
 //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017BasicNoOmegaMassCorr.root");
  //TFile *myFile = TFile::Open("March2017TwoDimSBEightBins.root");
  //TFile *myFile = TFile::Open("March2017ErrorTesting.root");
  //TFile *myFile = TFile::Open("May2017ErrorBase180Bins.root");



 //TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted Mass Omega vs Mass X;Mass #omega (GeV);MassX (GeV)",100,0.69,0.88,100,1.1,1.9);
 
  TH1::SetDefaultSumw2(); 	

 //Populating the histograms of the edgen data
  
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/EdGen/output/analysis_5_outputSimon.root");
  
  TH2F *MC;
  TH1D *MC_Left;
  TH1D *MC_Signal;
  TH1D *MC_Right;
  
  MC = h2_mass_omega_vs_mass_omega_pi_pi;
  MC->ProjectionY("MCLeft",1,30)->Draw();
  MC_Left = MCLeft;
  MC->ProjectionY("MCSignal",31,90)->Draw();
  MC_Signal = MCSignal;
  MC->ProjectionY("MCRight",91,120)->Draw();
  MC_Right = MCRight;

  //Populating the histograms of the reconstructed monte carlo data.
  
  TFile *myFile = TFile::Open("May2017ErrorPhaseSpace10Mil.root");
  
  TH2F *Recon;
  TH1D *Recon_Left;
  TH1D *Recon_Signal;
  TH1D *Recon_Right;
  
  Recon = MOmvsMXSigAndSide_All;
  Recon->ProjectionY("ReconLeft",1,30)->Draw();
  Recon_Left = ReconLeft;
  Recon->ProjectionY("ReconSignal",31,90)->Draw();
  Recon_Signal = ReconSignal;
  Recon->ProjectionY("ReconRight",91,120)->Draw();
  Recon_Right = ReconRight;
  
  // TH2F *Acceptance;
  // TH1D *Acceptance_Left;
  // TH1D *Acceptance_Signal;
  // TH1D *Acceptance_Reft;

  //new TH2F("MOmvsMX"+sLabel,"Mass_{Omega} vs MassX;Mass_{Omega};MassX"+sLabel,120,0.722,0.842,180,1.1,1.9)));
  TH1F* Acceptance_Left = new TH1F("Acceptance_Left", "Acceptance Left Title",180,1.1,1.9); 
  TH1F* Acceptance_Signal = new TH1F("Acceptance_Signal", "Acceptance Signal Title",180,1.1,1.9);
  TH1F* Acceptance_Right = new TH1F("Acceptance_Right", "Acceptance Right Title",180,1.1,1.9);

  //*****************  DON'T FORGET ABOUT Sumw2 TO GET ERRORS TO WORK  ********************************

  //Acceptance = (*Recon)/(*MC);
  //Acceptance_Left->Divide(Recon_Left,MC_Left);
  //Acceptance_Left = (Recon_Left)/(MC_Left);
  Acceptance_Left->Divide(MC_Left,Recon_Left,1,1,"");
  Acceptance_Signal->Divide(MC_Signal,Recon_Signal,1,1,"");
  Acceptance_Right->Divide(MC_Right,Recon_Right,1,1,"");
  //Acceptance_Left->Draw;
  //Acceptance_Signal->Divide(Recon_Signal,MC_Signal);
  //Acceptance_Right->Divide(Recon_Right,MC_Right);
  
  //Acceptance->SetDirectory(f);
  //Acceptance_Left->SetDirectory(f);
  //Acceptance_Signal->SetDirectory(f);
  //Acceptance_Right->SetDirectory(f);


  //***************************************************************************************************
  //Implimenting the weighting on a histogram.

 TFile *myFile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/AcceptanceTestingPlots.root");

 TH1F* AccCorMassXLeft;
 TH1F* AccCorMassXSignal;
 TH1F* AccCorMassXRight;

 AccCorMassXLeft = MXFullLeft_All;
 AccCorMassXSignal = MXFullSignal_All;
 AccCorMassXRight = MXFullRight_All;
 
 AccCorMassXLeft->Multiply(Acceptance_Left);
 AccCorMassXSignal->Multiply(Acceptance_Signal);
 AccCorMassXRight->Multiply(Acceptance_Right);
 
  
 MC->SetDirectory(f);
 MC_Left->SetDirectory(f);
 MC_Signal->SetDirectory(f);
 MC_Right->SetDirectory(f);
 
 Recon->SetDirectory(f);
 Recon_Left->SetDirectory(f);
 Recon_Signal->SetDirectory(f);
 Recon_Right->SetDirectory(f);
 
 Acceptance_Left->SetDirectory(f);
 Acceptance_Signal->SetDirectory(f);
 Acceptance_Right->SetDirectory(f);
 
 AccCorMassXLeft->SetDirectory(f);
 AccCorMassXSignal->SetDirectory(f);
 AccCorMassXRight->SetDirectory(f);
 
 f->Write();
  
}


