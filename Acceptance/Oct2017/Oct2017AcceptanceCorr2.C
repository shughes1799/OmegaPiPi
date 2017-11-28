
{

  //TFile *f = new TFile("March2017Eta1295MCNormT0to1.root","RECREATE");
  //TFile *f = new TFile("March2017BasicNoOmegaMassCorrNormalisation.root","RECREATE");
  TFile *f = new TFile("TestAcceptanceNov2017SidebandSub.root","RECREATE");

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
  
  // TFile *myFile = TFile::Open("/home/s0677668/Haspect/EdGen/output/analysis_5_outputSimon.root");
  
  // TH2F *MC;
  // TH1D *MC_Left;
  // TH1D *MC_Signal;
  // TH1D *MC_Right;
  
  // MC = h2_mass_omega_vs_mass_omega_pi_pi;
  // MC->ProjectionY("MCLeft",1,30)->Draw();
  // MC_Left = MCLeft;
  // MC->ProjectionY("MCSignal",31,90)->Draw();
  // MC_Signal = MCSignal;
  // MC->ProjectionY("MCRight",91,120)->Draw();
  // MC_Right = MCRight;

  //Populating the MonteCarloData

  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Acceptance/Oct2017/PSFirst10mil.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Acceptance/Oct2017/PSMain100mil.root");

  TH1F *MCMassOmega;
  TH1F *MCMassOmegaPiPi;

  MCMassOmega = h1_mass_omega2;
  MCMassOmegaPiPi = h1_mass_omega_pi_pi;

  MCMassOmega->SetDirectory(f);
  MCMassOmegaPiPi->SetDirectory(f);



  //Populating the histograms of the reconstructed monte carlo data.
  
  //TFile *myFile = TFile::Open("May2017ErrorPhaseSpace10MilAccTest.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Oct2017PS10MilRecon.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Nov2017/Nov20175BinsMassXPS100MilRecon.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Nov2017PS100MilRecon100Signal40SBSubtracted.root");


  //TH1F *ReconMassOmega;
  TH1F *ReconMassOmegaPiPi;

  //ReconMassOmega = MmissMCReconAll_All;
  //ReconMassOmegaPiPi = MXFullMCReconAll_All;

  //ReconMassOmega = MmissMCReconSignal_All;
  ReconMassOmegaPiPi = MassXSBMCRecon;

  //ReconMassOmega->SetDirectory(f);
  ReconMassOmegaPiPi->SetDirectory(f);


  // TH2F *Recon;
  // TH1D *Recon_Left;
  // TH1D *Recon_Signal;
  // TH1D *Recon_Right;
  
  // Recon = MOmvsMXSigAndSide_All;
  // Recon->ProjectionY("ReconLeft",1,30)->Draw();
  // Recon_Left = ReconLeft;
  // Recon->ProjectionY("ReconSignal",31,90)->Draw();
  // Recon_Signal = ReconSignal;
  // Recon->ProjectionY("ReconRight",91,120)->Draw();
  // Recon_Right = ReconRight;


  
  // TH2F *Acceptance;
  // TH1D *Acceptance_Left;
  // TH1D *Acceptance_Signal;
  // TH1D *Acceptance_Reft;

  //new TH2F("MOmvsMX"+sLabel,"Mass_{Omega} vs MassX;Mass_{Omega};MassX"+sLabel,120,0.722,0.842,180,1.1,1.9)));
  TH1F* Acceptance_Left = new TH1F("Acceptance_Left", "Acceptance Left Title",180,1.1,1.9); 
  TH1F* Acceptance_Signal = new TH1F("Acceptance_Signal", "Acceptance Signal Title",180,1.1,1.9);
  TH1F* Acceptance_Right = new TH1F("Acceptance_Right", "Acceptance Right Title",180,1.1,1.9);

  TH1F* AcceptanceOmega_All = new TH1F("AcceptanceOmega_All", "Acceptance Omega Title",180,0.692,0.872);
  TH1F* AcceptanceOmegaPiPi_All = new TH1F("AcceptanceOmegaPiPi_All", "Acceptance OmegaPiPi Title",180,1.1,1.9);


  //*****************  DON'T FORGET ABOUT Sumw2 TO GET ERRORS TO WORK  ********************************

  // //Acceptance = (*Recon)/(*MC);
  // //Acceptance_Left->Divide(Recon_Left,MC_Left);
  // //Acceptance_Left = (Recon_Left)/(MC_Left);
  // Acceptance_Left->Divide(MC_Left,Recon_Left,1,1,"");
  // Acceptance_Signal->Divide(MC_Signal,Recon_Signal,1,1,"");
  // Acceptance_Right->Divide(MC_Right,Recon_Right,1,1,"");

  //AcceptanceOmega_All->Divide(MCMassOmega,ReconMassOmega,1,1,"");
  //AcceptanceOmegaPiPi_All->Divide(MCMassOmegaPiPi,ReconMassOmegaPiPi,1,1,"");

  //AcceptanceOmega_All->Divide(ReconMassOmega,MCMassOmega,1,1,"");
  AcceptanceOmegaPiPi_All->Divide(ReconMassOmegaPiPi,MCMassOmegaPiPi,1,1,"");

  // AcceptanceOmega_All->SetDirectory(f);
  AcceptanceOmegaPiPi_All->SetDirectory(f);

  //AcceptanceOmega_All->Draw();

  // //Acceptance_Left->Draw;
  // //Acceptance_Signal->Divide(Recon_Signal,MC_Signal);
  // //Acceptance_Right->Divide(Recon_Right,MC_Right);
  
  //Acceptance->SetDirectory(f);
  //Acceptance_Left->SetDirectory(f);
  //Acceptance_Signal->SetDirectory(f);
  //Acceptance_Right->SetDirectory(f);
  // AcceptanceOmegaPiPi_All->SetDirectory(f);

  //***************************************************************************************************
  //Implimenting the weighting on a histogram.

  //TFile *myFile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/AcceptanceTestingPlotsOct2017.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Nov2017/Nov20175BinsMassX16FilesRealData.root");

 // TH1F* AccCorMassXLeft;
 // TH1F* AccCorMassXSignal;
 // TH1F* AccCorMassXRight;

  TH1F* AccCorMassOmegaTest;
  TH1F* AccCorMassOmegaPiPiTest;

 // AccCorMassXLeft = MXFullLeft_All;
 // AccCorMassXSignal = MXFullSignal_All;
 // AccCorMassXRight = MXFullRight_All;

  //AccCorMassOmegaTest = MmissAll_All;
  //AccCorMassOmegaPiPiTest = MXFullAll_All;

  AccCorMassOmegaTest = MmissSignal_All;
  AccCorMassOmegaPiPiTest = MXSignal_All;

 // AccCorMassXLeft->Multiply(Acceptance_Left);
 // AccCorMassXSignal->Multiply(Acceptance_Signal);
 // AccCorMassXRight->Multiply(Acceptance_Right);

  //AccCorMassOmegaTest->Multiply(AcceptanceOmega_All);
  //AccCorMassOmegaPiPiTest->Multiply(AcceptanceOmegaPiPi_All);

  AccCorMassOmegaTest->Divide(AcceptanceOmega_All);
  AccCorMassOmegaPiPiTest->Divide(AcceptanceOmegaPiPi_All);

  //AccCorMassOmegaTest->SetDirectory(f);
  AccCorMassOmegaPiPiTest->SetDirectory(f);

  // AccCorMassXSignal->SetDirectory(f);

 //***************************************************************
 // // Simple Sideband Subtraction including acceptance effects, however has minimal impact on the signal region. As there are vastly more counts there.
 // TH1F* SimpleMassXSidebandSub = new TH1F("SimpleMassXSidebandSub", "SimpleMassXSidebandSub Title",180,1.1,1.9);
 // TH1F* SimpleCombinedSidebands = new TH1F("SimpleCombinedSidebands", "SimpleCombinedSidebands Title",180,1.1,1.9);

 // SimpleCombinedSidebands->Add(AccCorMassXLeft);
 // SimpleCombinedSidebands->Add(AccCorMassXRight);

 // SimpleMassXSidebandSub->Add(AccCorMassXSignal);

 // SimpleMassXSidebandSub->Add(SimpleCombinedSidebands,-1);

 //************************************************************
 // //Scaled sideband subtraction including scaling factors to try to rebalance the scales.
 // TH1F* ScaledMassXSidebandSub = new TH1F("ScaledMassXSidebandSub", "ScaledMassXSidebandSub Title",180,1.1,1.9);
 // TH1F* ScaledCombinedSidebands = new TH1F("ScaledCombinedSidebands", "ScaledCombinedSidebands Title",180,1.1,1.9);

 // ScaledCombinedSidebands->Add(SimpleCombinedSidebands,10.5);

 // ScaledMassXSidebandSub->Add(AccCorMassXSignal);
 // ScaledMassXSidebandSub->Add(ScaledCombinedSidebands,-1);
 

 // //****************************************
 // //Alternative strategy rescaling the signal region with the average of the two sidebands
 
 // TH1F* AccAvgSidebands = new TH1F("AccAvgSidebands", "AccAvgSidebands Title",180,1.1,1.9);
 
 // TH1F* AccCorMassXSignalFix = new TH1F("AccCorMassXSignalFix", "AccCorMassXSignalFix Title",180,1.1,1.9);
 

 
 // AccAvgSidebands->Add(Acceptance_Left);
 // AccAvgSidebands->Add(Acceptance_Right);
 // //AccAvgSidebands->Multiply(2);
 // for(int l=1;l<181;l++){
   
 //   //Normalised Sideband subtraction of signal region.
 //   Double_t AccFix = AccAvgSidebands->GetBinContent(l);
 //   AccFix = AccFix/2;
 //   Double_t AccFixEr = AccAvgSidebands->GetBinError(l);
 //   AccFixEr = AccFixEr/2;  //Dubious Error Fix.
   
 //   AccAvgSidebands->SetBinContent(l,AccFix);
 //   AccAvgSidebands->SetBinError(l,AccFixEr);
   
 // }
 
 // AccCorMassXSignalFix = MXFullSignal_All;
 // AccCorMassXSignalFix->Multiply(AccAvgSidebands);
 
 // TH1F* FixedMassXSidebandSub = new TH1F("FixedMassXSidebandSub", "FixedMassXSidebandSub Title",180,1.1,1.9);
 // TH1F* FixedCombinedSidebands = new TH1F("FixedCombinedSidebands", "FixedCombinedSidebands Title",180,1.1,1.9);
 
 // FixedCombinedSidebands->Add(AccCorMassXLeft);
 // FixedCombinedSidebands->Add(AccCorMassXRight);
 
 // FixedMassXSidebandSub->Add(AccCorMassXSignalFix);
 
 // FixedMassXSidebandSub->Add(FixedCombinedSidebands,-1);
 
 //Readout bit
 
 // MC->SetDirectory(f);
 // MC_Left->SetDirectory(f);
 // MC_Signal->SetDirectory(f);
 // MC_Right->SetDirectory(f);
 
 // Recon->SetDirectory(f);
 // Recon_Left->SetDirectory(f);
 // Recon_Signal->SetDirectory(f);
 // Recon_Right->SetDirectory(f);
 
 // Acceptance_Left->SetDirectory(f);
 // Acceptance_Signal->SetDirectory(f);
 // Acceptance_Right->SetDirectory(f);
 
 // AccCorMassXLeft->SetDirectory(f);
 // AccCorMassXSignal->SetDirectory(f);
 // AccCorMassXRight->SetDirectory(f);

 // SimpleMassXSidebandSub->SetDirectory(f);
 // SimpleCombinedSidebands->SetDirectory(f);

 //AccAvgSidebands->SetDirectory(f);
 //AccCorMassXSignalFix->SetDirectory(f);

 //FixedMassXSidebandSub->SetDirectory(f);

 // ScaledCombinedSidebands->SetDirectory(f);
 //ScaledMassXSidebandSub->SetDirectory(f);

  //Mass Omega
  // MCMassOmega->SetDirectory(f);
  // ReconMassOmega->SetDirectory(f);
  // AcceptanceOmega_All->SetDirectory(f);
  // AccCorMassOmegaTest->SetDirectory(f);

  //Mass OmegaPiPi
  // MCMassOmegaPiPi->SetDirectory(f);
  // ReconMassOmegaPiPi->SetDirectory(f);
  // AcceptanceOmegaPiPi_All->SetDirectory(f);
  // AccCorMassOmegaPiPiTest->SetDirectory(f);
  
  f->Write();
  
}


