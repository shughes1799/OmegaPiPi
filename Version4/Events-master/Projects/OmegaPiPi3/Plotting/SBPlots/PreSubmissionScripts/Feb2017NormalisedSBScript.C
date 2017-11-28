{
  
  //TFile *f = new TFile("SB4Elt3Subtraction1.root","RECREATE");
  //  TFile *f = new TFile("SB4MCPhaseSpaceSubtraction1.root","RECREATE");
  // TFile *f = new TFile("SB5PhaseSpace1milSubtraction1lt3GeV.root","RECREATE");
  // TFile *f = new TFile("SB5PSDecays10milSubtraction1.root","RECREATE");
  // TFile *f = new TFile("SB5PSandA2Decays10milSubtraction1.root","RECREATE");
  //  TFile *f = new TFile("LeftandRightSubPrecHalfSBLandRComp2.root","RECREATE");
  //TFile *f = new TFile("Dec2016BinnedMassXSubtractions1.root","RECREATE");
  //TFile *f = new TFile("Dec2016BinnedMassXSubtractionsDeltas1.root","RECREATE");
  //TFile *f = new TFile("Jan2017BinnedMassXSubtractionsDeltas5.root","RECREATE");
  //TFile *f = new TFile("Jan2017MassXSubtractions1675RhoSearch170Width.root","RECREATE");
  // TFile *f = new TFile("Jan2017MassXSubtractionsBinsT2_5.root","RECREATE");
  //TFile *f = new TFile("Jan2017Normalisation2SubtractionHalfWidthSB1675Rho.root","RECREATE");
  //TFile *f = new TFile("Feb2017SubHalfWidthBackFigsPS10Mil.root","RECREATE");
  //TFile *f = new TFile("Feb2017BinnedEgamma3p3to3p9SubtractedAdjNorm.root","RECREATE");
  //TFile *f = new TFile("March2017BasicSubtractedAdjNorm2.root","RECREATE");
  //TFile *f = new TFile("March2017Eta1295MCDataSubtractedT0to1NewFit.root","RECREATE");
  TFile *f = new TFile("March2017BinnedT2to5MX1p25to1p33SubtractedAdjNorm.root","RECREATE");

  //TFile *f = new TFile("SB4Subtraction4.root","RECREATE");
  // TFile *myFile = TFile::Open("SB4Elt3Plots2.root");
  // TFile *myFile = TFile::Open("SB1MilPhaseSpace1lt3GeV.root ");
  // TFile *myFile = TFile::Open("SB10MilPSandA2Decays1.root");
  //TFile *myFile = TFile::Open("LeftRightTestPreciseHalfSB.root");
  //TFile *myFile = TFile::Open("Dec2016TestMassXBins3.root");
  //TFile *myFile = TFile::Open("Dec2016TestMassXBins4Deltas.root");
  // TFile *myFile = TFile::Open("Jan2017TestMassXBinsinT2_5.root");
  //TFile *myFile = TFile::Open("Jan2017Normalisation2HalfWidthSB.root");
  //TFile *myFile = TFile::Open("Feb2017NormPS10MilDataHalfWidthSB.root");
  //TFile *myFile = TFile::Open("Feb2017BinnedEgamma3p3to3p9.root");
  //TFile *myFile = TFile::Open("Feb2017BinnedT0to1.root");
  //TFile *myFile = TFile::Open("March2017Eta1295MCDataT0to1.root");
  //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017Basic.root");
  TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  

  //Normalisation Parameters
  Double_t leftBack = 14.8768;
  Double_t signalBack = 27.3392;
  Double_t rightBack = 11.2176;
  Double_t leftNorm   = signalBack/leftBack;
  Double_t rightNorm  = signalBack/rightBack;
  Double_t combNorm = signalBack/(leftBack+rightBack);

  // TFile *myFile = TFile::Open("SB4Plots4.root");

  // TTreeReader myReader("ntuple", myFile);
  
  //TH1F *MmissMidBG = new TH1F("MidBG", "Sideband assumed background in the signal region", 90, 0.69, 0.87);
  //TH1F *MmissSignal = new TH1F("Signal", "Signal, Sideband Background Subtracted", 90, 0.69, 0.87);

 

  TH1F *MassXSB = new TH1F("MassXSB", "Sideband subtracted Mass X;MassX (GeV)", 180, 1.1, 1.9);
 
  TH1F *MassXNormSignal = new TH1F("MassXNormSignal", "Normalised Mass X Signal Region;MassX (GeV)", 180, 1.1, 1.9);
  TH1F *MassXNormLeft = new TH1F("MassXNormLeft", "Normalised Mass X Left Region;MassX (GeV)", 180, 1.1, 1.9);
  TH1F *MassXNormRight = new TH1F("MassXNormRight", "Normalised Mass X Right Region;MassX (GeV)", 180, 1.1, 1.9);
  TH1F *MassXNormBothSB = new TH1F("MassXNormBothSB", "Normalised Mass X Side Regions;MassX (GeV)", 180, 1.1, 1.9);

 // TH1F *MassXSBBin1 = new TH1F("MassXSBBin1", "Sideband subtracted Mass X Bin1;MassX (GeV)", 50, 1.22, 1.42);
  // TH1F *MassXSBBin2 = new TH1F("MassXSBBin2", "Sideband subtracted Mass X Bin2;MassX (GeV)", 50, 1.22, 1.42);
  // TH1F *MassXSBBin3 = new TH1F("MassXSBBin3", "Sideband subtracted Mass X Bin3;MassX (GeV)", 50, 1.22, 1.42);
  // TH1F *MassXSBBin4 = new TH1F("MassXSBBin4", "Sideband subtracted Mass X Bin4;MassX (GeV)", 50, 1.22, 1.42);
  // TH1F *MassXSBBin5 = new TH1F("MassXSBBin5", "Sideband subtracted Mass X Bin5;MassX (GeV)", 50, 1.22, 1.42);

  //TH1F *MassPiPProSB = new TH1F("MassPiPPro", "Sideband subtracted Mass PiPPro; Mass #pi^+ proton (GeV)", 100, 1, 1.9);
  //TH1F *MassPiMProSB = new TH1F("MassPiMPro", "Sideband subtracted Mass PiMPro; Mass #pi^- proton", 100, 1, 1.9);

  //TH2F *MassPiPProvsMassXSB = new TH2F("MassPiPProvsMassXSB", "Sideband subtracted #pi^{+}p vs Mass X;#pi^{+}p (GeV);MassX (GeV)",100,1,1.9,100,1.1,1.9);
  //TH2F *MassPiMProvsMassXSB = new TH2F("MassPiMProvsMassXSB", "Sideband subtracted #pi^{-}p vs Mass X;#pi^{-}p (GeV);MassX (GeV)",100,1,1.9,100,1.1,1.9);

  //TH2F *MassPiPProvsMassOmSB = new TH2F("MassPiPProvsMassOmSB", "Sideband subtracted #pi^{+}p vs Mass #omega;#pi^{+}p (GeV);Mass #omega (GeV)",100,1,1.9,100,0.692,0.872);
  //TH2F *MassPiMProvsMassOmSB = new TH2F("MassPiMProvsMassOmSB", "Sideband subtracted #pi^{-}p vs Mass #omega;#pi^{-}p (GeV);Mass #omega (GeV)",100,1,1.9,100,0.692,0.872);

  //TH1F *MmissSignal = new TH1F("Signal", "Signal, Sideband Background Subtracted", 100, 0.692, 0.872);
 
//   TH1F *ThetaXSB = new TH1F("ThetaXSB", "Sideband subtracted Theta X; #theta (Deg)", 100, 0, 30);
//   TH1F *PhiXSB = new TH1F("PhiXSB", "Sideband subtracted Phi X; #phi (Deg)", 100, -180, 180);
//   TH1F *EgammaSB = new TH1F("EgammaSB", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);
//   TH1F *tSB = new TH1F("tSB", "Sideband subtracted t; t (GeV)", 100, 0, 4);
//   TH1F *sSB = new TH1F("sSB", "Sideband subtracted s; s (GeV)", 100, 4, 8.5);
//   TH1F *AngleBFXOL = new TH1F("AngleBFXOL","Angle Beam frame X and Omega Lab; angle (deg)",100,0,90);
//   TH1F *AngleXLOFX = new TH1F("AngleXLOFX","Angle Meson X Lab and Omega Frame X; angle (deg)",100,0,180);

//   TH1F *MassOmProSB = new TH1F("MassOmPro", "Sideband subtracted Mass OmegaProton", 100, 1.7, 2.5);
//   TH1F *MassOmPiPSB = new TH1F("MassOmPiP", "Sideband subtracted Mass OmegaPiP", 100, 0.8, 1.7);
//   TH1F *MassOmPiMSB = new TH1F("MassOmPiM", "Sideband subtracted Mass OmegaPiM", 100, 0.8, 1.7);
//   TH1F *MassPiPProSB = new TH1F("MassPiPPro", "Sideband subtracted Mass PiPPro", 100, 1, 1.9);
//   TH1F *MassPiMProSB = new TH1F("MassPiMPro", "Sideband subtracted Mass PiMPro", 100, 1, 1.9);
//  TH1F *MassPiPPiMSB = new TH1F("MassPiPPiM", "Sideband subtracted Mass PiPPiM", 100, 0.6, 1);
//   TH1F *MassPiPPiMProSB = new TH1F("MassPiPPiMPro", "Sideband subtracted Mass PiPPiMPro", 100, 1.2, 2.1);

//   //Weighted Histograms
//   TH1F *MassXWeightedSB = new TH1F("MassXWeightedSB", "Sideband subtracted Mass X;MassX (GeV)", 100, 1.1, 1.9);
  
//   TH1F *EgammaWeightedSB = new TH1F("EgammaWeightedSB", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);


//   // TH2F *MassXvsPiPPiMSB = new TH2F("MassXvsPiPPiM", "Sideband subtracted Mass PiPPiM",100,0.8,1.9,100,0.2,1.1);
//   TH2F *ThetaXvsMassXSB = new TH2F("ThetaXvsMassXSB", "Sideband subtracted Theta X vs Mass X;#theta (Deg);MassX (GeV)",100,0,30,100,1.1,1.9);
//   TH2F *PhiXvsMassXSB = new TH2F("PhiXvsMassXSB", "Sideband subtracted Phi X vs Mass X;#phi (Deg);MassX (GeV)",100,-180,180,100,1.1,1.9);
//   TH2F *EgammavsMassXSB = new TH2F("EgammavsMassXSB", "Sideband subtracted Beam energy vs mass X;Beam Energy (GeV);MassX (GeV)",100,1.5,4,100,1.1,1.9);
//   TH2F *tvsMassXSB = new TH2F("tvsMassXSB", "Sideband subtracted t vs mass X;t (GeV);MassX (GeV)",100,0,3,100,1.1,1.9);
//   TH2F *svsMassXSB = new TH2F("svsMassXSB", "Sideband subtracted s vs mass X;s (GeV);MassX (GeV)",100,4,8.5,100,1.1,1.9);
//   TH2F *AngleBFXOLvsMassXSB = new TH2F("AngleBFXOLvsMassXSB", "Angle Beam frame X and Omega Lab vs Mass X; Angle (deg); MassX (GeV)",100,0,90,100,1.1,1.9);
//   TH2F *AngleXLOFXvsMassXSB = new TH2F("AngleXLOFXvsMassXSB","Angle Meson X Lab and Omega Frame X; angle (deg); MassX (GeV)",100,0,180,100,1.1,1.9);

//   TH2F *MassOmProvsMassXSB = new TH2F("MassOmProvsMassXSB", "Sideband subtracted #omega p vs Mass X;#omega p (GeV);MassX (GeV)",100,1.7,2.5,100,1.1,1.9);
//   TH2F *MassOmPiPvsMassXSB = new TH2F("MassOmPiPvsMassXSB", "Sideband subtracted #omega #pi^{+} vs Mass X;#omega#pi^{+} (GeV);MassX (GeV)",100,0.8,1.7,100,1.1,1.9);
// TH2F *MassOmPiMvsMassXSB = new TH2F("MassOmPiMvsMassXSB", "Sideband subtracted #omega #pi^{-} vs Mass X;#omega#pi^{-} (GeV);MassX (GeV)",100,0.8,1.7,100,1.1,1.9);
//  TH2F *MassPiPProvsMassXSB = new TH2F("MassPiPProvsMassXSB", "Sideband subtracted #pi^{+}p vs Mass X;#pi^{+}p (GeV);MassX (GeV)",100,1,1.9,100,1.1,1.9);
//  TH2F *MassPiMProvsMassXSB = new TH2F("MassPiMProvsMassXSB", "Sideband subtracted #pi^{-}p vs Mass X;#pi^{-}p (GeV);MassX (GeV)",100,1,1.9,100,1.1,1.9);
//  TH2F *MassPiPPiMvsMassXSB = new TH2F("MassPiPPiMvsMassXSB", "Sideband subtracted #pi^{+}#pi^{-} vs Mass X;#pi^{+}#pi^{+} (GeV);MassX (GeV)",100,0.2,1.1,100,1.1,1.9);
// TH2F *MassPiPPiMProvsMassXSB = new TH2F("MassPiPPiMProvsMassXSB", "Sideband subtracted #pi^{+}#pi^{-}p vs Mass X;#pi^{+}#pi^{+}p (GeV);MassX (GeV)",100,1.2,2.1,100,1.1,1.9);

// //Left and Right Histograms
//  TH1F *MassXSBLR = new TH1F("MassXSBLR", "Sideband subtraction divided by 2 Comparrison Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXSBLR2 = new TH1F("MassXSBLR2", "Sideband Addition divided by 2 Comparrison Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXSBLR3 = new TH1F("MassXSBLR3", "Sideband Subtraction + Difference between sidebands, Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXSignalSB = new TH1F("MassXSignalSB", "Signal Region, Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXLeftSB = new TH1F("MassXLeftSB", "Left Sideband, Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXRightSB = new TH1F("MassXRightSB", "Right Sideband, Mass X;MassX (GeV)", 100, 1.1, 1.9);



//  TH1F *MassXLeftSubSB = new TH1F("MassXLeftSubSB", "Only Left Sideband Subtracted, Mass X;MassX (GeV)", 100, 1.1, 1.9);
//  TH1F *MassXRightSubSB = new TH1F("MassXRightSubSB", "Only Right Sideband Subtracted, Mass X;MassX (GeV)", 100, 1.1, 1.9);

  TH1F *MassXLeftSubSignalSB = new TH1F("MassXLeftSubSignalSB", "Left region, Signal Subtracted, Mass X;MassX (GeV)", 180, 1.1, 1.9);
  TH1F *MassXRightSubSignalSB = new TH1F("MassXRightSubSignalSB", "Right region, Signal Subtracted, Mass X;MassX (GeV)", 180, 1.1, 1.9);
 
  TH1F *MassXSignalSubLeftSB = new TH1F("MassXSubLeftSB", "Signal region, Subtracted Left SB, Mass X;MassX (GeV)", 180, 1.1, 1.9);
  TH1F *MassXSignalSubRightSB = new TH1F("MassXSubRightSB", "Signal region, Subtracted Right SB, Mass X;MassX (GeV)", 180, 1.1, 1.9);

  TH1F *MassPiPPiMSB = new TH1F("MassPiPPiM", "Sideband subtracted Mass PiPPiM", 100, 0.2, 1);

  Int_t j2 = 1;

  // for(int i=1;i<31;i++){
  //   //Sideband Subtraction for Missing Mass
  //   Double_t leftbin = MmissSide_All->GetBinContent(i);
  //   Double_t rightbin = MmissSide_All->GetBinContent(i+60);
  //   Double_t bothbin = leftbin + rightbin;
  //   bothbin = bothbin/2;

  //   MidBG->SetBinContent(i+30,bothbin);

  //   Double_t signalbin = MmissSignal_All->GetBinContent(i+30);
  //   Double_t subtractedbin = signalbin - bothbin;
  //   Signal->SetBinContent(i+30,subtractedbin);
  // }

  for(int u=1;u<101;u++){

    //Normalised Sideband subtraction of signal region PiPi.
    Double_t bgXL = MPiPPiMLeft_All->GetBinContent(u);
    Double_t bgXR = MPiPPiMRight_All->GetBinContent(u);
    //Double_t bgXEr = MPiPPiMSide_All->GetBinError(u);
    bgXL = bgXL*combNorm;
    bgXR = bgXR*combNorm;
    Double_t bgComb;
    bgComb = bgXL+bgXR;
    // bgXEr = bgXEr/2; //This is wrong
    Double_t signalX = MPiPPiMSignal_All->GetBinContent(u);
    //Double_t signalXEr = MPiPPiMSignal_All->GetBinError(u);
    Double_t subtractedX = signalX-bgComb;
    //Double_t subtractedXEr = ((signalXEr^2)-(bgXEr)^2)^(0.5); //this is wrong
    MassPiPPiMSB->SetBinContent(u,subtractedX);
    
    
  }
  
  for(int l=1;l<181;l++){
    
  //Normalised Sideband subtraction of signal region.
  Double_t bgXL = MXFullLeft_All->GetBinContent(l);
  Double_t bgXR = MXFullRight_All->GetBinContent(l);
  //Double_t bgXEr = MXFullSide_All->GetBinError(l);
  bgXL = bgXL*combNorm;
  bgXR = bgXR*combNorm;
  Double_t bgComb;
  bgComb = bgXL+bgXR;
  // bgXEr = bgXEr/2; //This is wrong
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  //Double_t signalXEr = MXFullSignal_All->GetBinError(l);
  Double_t subtractedX = signalX-bgComb;
  //Double_t subtractedXEr = ((signalXEr^2)-(bgXEr)^2)^(0.5); //this is wrong
  MassXSB->SetBinContent(l,subtractedX);

// Histograms of normalised regions before subtraction
  MassXNormSignal->SetBinContent(l,signalX);
  MassXNormLeft->SetBinContent(l,bgXL);
  MassXNormRight->SetBinContent(l,bgXR);
  MassXNormBothSB->SetBinContent(l,bgComb);
 
  //Left and right sub signal region normalised to signal region
  Double_t LeftX = MXFullLeft_All->GetBinContent(l);
  LeftX = LeftX*leftNorm;
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  Double_t subtractedX = (LeftX-signalX);
  MassXLeftSubSignalSB->SetBinContent(l,subtractedX);

  Double_t RightX = MXFullRight_All->GetBinContent(l);
  RightX = RightX*rightNorm;
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  Double_t subtractedX = (RightX-signalX);
  MassXRightSubSignalSB->SetBinContent(l,subtractedX);

  //Signal sub left or right normalised
  Double_t LeftX = MXFullLeft_All->GetBinContent(l);
  LeftX = LeftX*leftNorm;
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  Double_t subtractedX = (signalX-LeftX);
  MassXSignalSubLeftSB->SetBinContent(l,subtractedX);

  Double_t RightX = MXFullRight_All->GetBinContent(l);
  RightX = RightX*rightNorm;
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  Double_t subtractedX = (signalX-RightX);
  MassXSignalSubRightSB->SetBinContent(l,subtractedX);




 }

// for(int m=1;m<51;m++){

// //Mass of X Meson for bin 1, with sideband subtraction 
//   Double_t bgX = MXSide1_All->GetBinContent(m);
//   bgX = bgX/2;
//   Double_t signalX = MXSignal1_All->GetBinContent(m);
//   Double_t subtractedX = signalX-bgX;
//   MassXSBBin1->SetBinContent(m,subtractedX);

//   //Mass of X Meson for bin 2, with sideband subtraction 
//   Double_t bgX = MXSide2_All->GetBinContent(m);
//   bgX = bgX/2;
//   Double_t signalX = MXSignal2_All->GetBinContent(m);
//   Double_t subtractedX = signalX-bgX;
//   MassXSBBin2->SetBinContent(m,subtractedX);

//   //Mass of X Meson for bin 3, with sideband subtraction 
//   Double_t bgX = MXSide3_All->GetBinContent(m);
//   bgX = bgX/2;
//   Double_t signalX = MXSignal3_All->GetBinContent(m);
//   Double_t subtractedX = signalX-bgX;
//   MassXSBBin3->SetBinContent(m,subtractedX);

//   //Mass of X Meson for bin 4, with sideband subtraction 
//   Double_t bgX = MXSide4_All->GetBinContent(m);
//   bgX = bgX/2;
//   Double_t signalX = MXSignal4_All->GetBinContent(m);
//   Double_t subtractedX = signalX-bgX;
//   MassXSBBin4->SetBinContent(m,subtractedX);

//   //Mass of X Meson for bin 5, with sideband subtraction 
//   Double_t bgX = MXSide5_All->GetBinContent(m);
//   bgX = bgX/2;
//   Double_t signalX = MXSignal5_All->GetBinContent(m);
//   Double_t subtractedX = signalX-bgX;
//   MassXSBBin5->SetBinContent(m,subtractedX);
//  }

  
for(int j=1;j<101;j++){

  //Dec2016 Sidebands

  //Mass of X Meson for all data
  // Double_t bgX = MXFullSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXFullSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSB->SetBinContent(j,subtractedX);

  //Mass of X Meson for bin 1, with sideband subtraction 
  // Double_t bgX = MXSide1_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXSignal1_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSBBin1->SetBinContent(j,subtractedX);

  // //Mass of X Meson for bin 2, with sideband subtraction 
  // Double_t bgX = MXSide2_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXSignal2_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSBBin2->SetBinContent(j,subtractedX);

  // //Mass of X Meson for bin 3, with sideband subtraction 
  // Double_t bgX = MXSide3_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXSignal3_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSBBin3->SetBinContent(j,subtractedX);

  // //Mass of X Meson for bin 4, with sideband subtraction 
  // Double_t bgX = MXSide4_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXSignal4_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSBBin4->SetBinContent(j,subtractedX);

  // //Mass of X Meson for bin 5, with sideband subtraction 
  // Double_t bgX = MXSide5_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXSignal5_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSBBin5->SetBinContent(j,subtractedX);


  // //Plots looking for delta contributions

  // //Mass of PiPProton, with sideband subtraction for all data
  // Double_t bgX = MPiPProSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MPiPProSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassPiPProSB->SetBinContent(j,subtractedX);

  // //Mass of PiMProton, with sideband subtraction for all data
  // Double_t bgX = MPiMProSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MPiMProSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassPiMProSB->SetBinContent(j,subtractedX);



  //cout << "Cycle Start " << j2 << endl;

  // //Mass of X Meson, with sideband subtraction
  // Double_t bgX = MXSide_All->GetBinContent(j);
  // bgX = bgX;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXSB->SetBinContent(j,subtractedX);

  // //Theta of X Meson, with sideband subtraction
  // Double_t bgX = ThetaXSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = ThetaXSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // ThetaXSB->SetBinContent(j,subtractedX);
  
  // //Phi of X Meson, with sideband subtraction
  // Double_t bgX = PhiXSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = PhiXSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // PhiXSB->SetBinContent(j,subtractedX);

  // //Beam Energy, with sideband subtraction
  // Double_t bgX = EgammaSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = EgammaSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // EgammaSB->SetBinContent(j,subtractedX);

  //t, with sideband subtraction
  // Double_t bgX = tSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = tSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // tSB->SetBinContent(j,subtractedX);

  // //s, with sideband subtraction
  // Double_t bgX = sSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = sSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // sSB->SetBinContent(j,subtractedX);

  // //Angle between Beam Frame X and Omega Lab
  // Double_t bg = AngleBeamFXandOmegaLabSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = AngleBeamFXandOmegaLabSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // AngleBFXOL->SetBinContent(j,subtracted);

  // //Angle between Meson X Lab and Omega Frame X
  // Double_t bg = AngleMesonXLabandOmegaFXSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = AngleMesonXLabandOmegaFXSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // AngleXLOFX->SetBinContent(j,subtracted);

  // //Mass of Combinations of Mesons Plots
  // Double_t bg = MOmProSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MOmProSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassOmProSB->SetBinContent(j,subtracted);

  // Double_t bg = MOmPiPSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MOmPiPSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassOmPiPSB->SetBinContent(j,subtracted);

  // Double_t bg = MOmPiMSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MOmPiMSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassOmPiMSB->SetBinContent(j,subtracted);

  // Double_t bg = MPiPProSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MPiPProSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassPiPProSB->SetBinContent(j,subtracted);

  // Double_t bg = MPiMProSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MPiMProSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassPiMProSB->SetBinContent(j,subtracted);

  // Double_t bg = MPiPPiMSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MPiPPiMSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassPiPPiMSB->SetBinContent(j,subtracted);

  // Double_t bg = MPiPPiMProSide_All->GetBinContent(j);
  // bg = bg/2;
  // Double_t signal = MPiPPiMProSignal_All->GetBinContent(j);
  // Double_t subtracted = signal-bg;
  // MassPiPPiMProSB->SetBinContent(j,subtracted);


  // //Weighted Histograms

  // Double_t bgX = MXWeightSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = MXWeightSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // MassXWeightedSB->SetBinContent(j,subtractedX);

  // Double_t bgX = EgammaWeightSide_All->GetBinContent(j);
  // bgX = bgX/2;
  // Double_t signalX = EgammaWeightSignal_All->GetBinContent(j);
  // Double_t subtractedX = signalX-bgX;
  // EgammaWeightedSB->SetBinContent(j,subtractedX);

  // //Left and Right Plots

  // //Mass of X Meson
  // Double_t LeftX = MXLeft_All->GetBinContent(j);
  // // bgX = bgX/2;
  // Double_t RightX = MXRight_All->GetBinContent(j);
  // Double_t subtractedX = (LeftX-RightX);
  // MassXSBLR->SetBinContent(j,subtractedX);


  // Double_t LeftX = MXLeft_All->GetBinContent(j);
  // Double_t RightX = MXRight_All->GetBinContent(j);
  // Double_t CombX = (LeftX+RightX);
  // MassXSBLR2->SetBinContent(j,CombX);

  // Double_t bgX = MXSide_All->GetBinContent(j);
  // bgX = bgX;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX2 = signalX-bgX+subtractedX;
  // MassXSBLR3->SetBinContent(j,subtractedX2);

  // Double_t bgX = MXSignal_All->GetBinContent(j);
  // //bgX = bgX;
  // //Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX2 = bgX;
  // MassXSignalSB->SetBinContent(j,subtractedX2);

  // Double_t bgX = MXLeft_All->GetBinContent(j);
  // bgX = bgX*2;
  // //Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX2 = bgX;
  // MassXLeftSB->SetBinContent(j,subtractedX2);

  // Double_t bgX = MXRight_All->GetBinContent(j);
  // bgX = bgX*2;
  // //Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX2 = bgX;
  // MassXRightSB->SetBinContent(j,subtractedX2);

  // Double_t LeftX = MXLeft_All->GetBinContent(j);
  // LeftX = LeftX*2;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX = (signalX-LeftX);
  // MassXLeftSubSB->SetBinContent(j,subtractedX);

  // Double_t RightX = MXRight_All->GetBinContent(j);
  // RightX = RightX*2;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX = (signalX-RightX);
  // MassXRightSubSB->SetBinContent(j,subtractedX);

  // Double_t LeftX = MXLeft_All->GetBinContent(j);
  // LeftX = LeftX*2;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX = (LeftX-signalX);
  // MassXLeftSubSignalSB->SetBinContent(j,subtractedX);

  // Double_t RightX = MXRight_All->GetBinContent(j);
  // RightX = RightX*2;
  // Double_t signalX = MXSignal_All->GetBinContent(j);
  // Double_t subtractedX = (RightX-signalX);
  // MassXRightSubSignalSB->SetBinContent(j,subtractedX);

  for(int k=1;k<101;k++){
    //   //Mass of X vs Mass of PiPPiM
    //   Double_t bgMXvsPiPPiM2 = MXvsPiPPiMSide_All->GetBinContent(j2,k);
    //   bgMXvsPiPPiM2 = bgMXvsPiPPiM2/2;
    //   Double_t sgMXvsPiPPiM2 = MXvsPiPPiMSignal_All->GetBinContent(j2,k);
    //   Double_t subMXvsPiPPiM2 = sgMXvsPiPPiM2-bgMXvsPiPPiM2;
    //   MassXvsPiPPiMSB->SetBinContent(j2,k,subMXvsPiPPiM2); 
  
    // //Phi X vs MassX (Switched the variable names at one point so they are backwards)
    // Double_t bgMXvsPhiX = PhiXvsMXSide_All->GetBinContent(j2,k);
    // bgMXvsPhiX = bgMXvsPhiX/2;
    // Double_t sgMXvsPhiX = PhiXvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subMXvsPhiX = sgMXvsPhiX-bgMXvsPhiX;
    // PhiXvsMassXSB->SetBinContent(j2,k,subMXvsPhiX); 
 
    // //Theta X vs MassX (Switched the variable names at one point so they are backwards)
    // Double_t bgMXvsThetaX = ThetaXvsMXSide_All->GetBinContent(j2,k);
    // bgMXvsThetaX = bgMXvsThetaX/2;
    // Double_t sgMXvsThetaX = ThetaXvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subMXvsThetaX = sgMXvsThetaX-bgMXvsThetaX;
    // ThetaXvsMassXSB->SetBinContent(j2,k,subMXvsThetaX);

    // //Egamma vs Mass of X 
    // Double_t bgEgammavsMX = EgammavsMXSide_All->GetBinContent(j2,k);
    // bgEgammavsMX = bgEgammavsMX/2;
    // Double_t sgEgammavsMX = EgammavsMXSignal_All->GetBinContent(j2,k);
    // Double_t subEgammavsMX = sgEgammavsMX-bgEgammavsMX;
    // EgammavsMassXSB->SetBinContent(j2,k,subEgammavsMX);

    // //t vs Mass of X
    // Double_t bgtvsMX = tvsMXSide_All->GetBinContent(j2,k);
    // bgtvsMX = bgtvsMX/2;
    // Double_t sgtvsMX = tvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtvsMX = sgtvsMX-bgtvsMX;
    // tvsMassXSB->SetBinContent(j2,k,subtvsMX);
    
    // //s vs Mass of X
    // Double_t bgsvsMX = svsMXSide_All->GetBinContent(j2,k);
    // bgsvsMX = bgsvsMX/2;
    // Double_t sgsvsMX = svsMXSignal_All->GetBinContent(j2,k);
    // Double_t subsvsMX = sgsvsMX-bgsvsMX;
    // svsMassXSB->SetBinContent(j2,k,subsvsMX);

    // //Angle between Beam Frame X and Omega Lab vs MassX
    // Double_t bg = AngleBeamFXandOmegaLabvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = AngleBeamFXandOmegaLabvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // AngleBFXOLvsMassXSB->SetBinContent(j2,k,subtracted);

    // //Angle between Meson X Lab and Omega Frame X
    // Double_t bg = AngleMesonXLabandOmegaFXvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = AngleMesonXLabandOmegaFXvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // AngleXLOFXvsMassXSB->SetBinContent(j2,k,subtracted);


    // //2D Plots of Combination particles vs MassX

    // Double_t bg = MOmProvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MOmProvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassOmProvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MOmPiPvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MOmPiPvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassOmPiPvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MOmPiMvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MOmPiMvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassOmPiMvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiPProvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiPProvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiPProvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiMProvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiMProvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiMProvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiPProvsMOmSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiPProvsMOmSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiPProvsMassOmSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiMProvsMOmSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiMProvsMOmSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiMProvsMassOmSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiPPiMvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiPPiMvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiPPiMvsMassXSB->SetBinContent(j2,k,subtracted);

    // Double_t bg = MPiPPiMProvsMXSide_All->GetBinContent(j2,k);
    // bg = bg/2;
    // Double_t signal = MPiPPiMProvsMXSignal_All->GetBinContent(j2,k);
    // Double_t subtracted = signal-bg;
    // MassPiPPiMProvsMassXSB->SetBinContent(j2,k,subtracted);

  }
  // cout << "Cycle End " << j2 << endl;
  j2++;
}
 j2=1;

 //Dec 2016 Outputs

 MassXSB->SetDirectory(f);
 // MassXSBBin1->SetDirectory(f);
 // MassXSBBin2->SetDirectory(f);
 // MassXSBBin3->SetDirectory(f);
 // MassXSBBin4->SetDirectory(f);
 // MassXSBBin5->SetDirectory(f);

 // MassPiPProSB->SetDirectory(f);
 //  MassPiMProSB->SetDirectory(f);

 //  MassPiPProvsMassXSB->SetDirectory(f);
 //  MassPiMProvsMassXSB->SetDirectory(f);

 //  MassPiPProvsMassOmSB->SetDirectory(f);
 //  MassPiMProvsMassOmSB->SetDirectory(f);

 //  MassPiPPiMSB->SetDirectory(f);

 MassXLeftSubSignalSB->SetDirectory(f);
 MassXRightSubSignalSB->SetDirectory(f);

 MassXSignalSubLeftSB->SetDirectory(f);
 MassXSignalSubRightSB->SetDirectory(f);

 MassXNormSignal->SetDirectory(f);
 MassXNormLeft->SetDirectory(f);
 MassXNormRight->SetDirectory(f);
 MassXNormBothSB->SetDirectory(f);

 MassPiPPiMSB->SetDirectory(f);
 // tSB->SetDirectory(f);
 //Old Plots

 // ThetaXSB->SetDirectory(f);
 // PhiXSB->SetDirectory(f);
 // EgammaSB->SetDirectory(f);
 // tSB->SetDirectory(f);
 // sSB->SetDirectory(f);
 // AngleBFXOL->SetDirectory(f);
 // AngleXLOFX->SetDirectory(f);

 // MassXWeightedSB->SetDirectory(f);
 // EgammaWeightedSB->SetDirectory(f);

 // ThetaXvsMassXSB->SetDirectory(f);
 // PhiXvsMassXSB->SetDirectory(f);
 // EgammavsMassXSB->SetDirectory(f);
 // tvsMassXSB->SetDirectory(f);
 // svsMassXSB->SetDirectory(f);
 // AngleBFXOLvsMassXSB->SetDirectory(f);
 // AngleXLOFXvsMassXSB->SetDirectory(f);

 // MassOmProSB->SetDirectory(f);
 // MassOmPiPSB->SetDirectory(f);
 // MassOmPiMSB->SetDirectory(f);
 // MassPiPProSB->SetDirectory(f);
 // MassPiMProSB->SetDirectory(f);
 // MassPiPPiMSB->SetDirectory(f);
 // MassPiPPiMProSB->SetDirectory(f);

 // MassOmProvsMassXSB->SetDirectory(f);
 // MassOmPiPvsMassXSB->SetDirectory(f);
 // MassOmPiMvsMassXSB->SetDirectory(f);
 // MassPiPProvsMassXSB->SetDirectory(f);
 // MassPiMProvsMassXSB->SetDirectory(f);
 // MassPiPPiMvsMassXSB->SetDirectory(f);
 // MassPiPPiMProvsMassXSB->SetDirectory(f);

 // MassXSBLR->SetDirectory(f);
 // MassXSBLR2->SetDirectory(f);
 // MassXSBLR3->SetDirectory(f);
 // MassXSignalSB->SetDirectory(f);
 // MassXLeftSB->SetDirectory(f);
 // MassXRightSB->SetDirectory(f);
 // MassXLeftSubSB->SetDirectory(f);
 // MassXRightSubSB->SetDirectory(f);
 // MassXLeftSubSignalSB->SetDirectory(f);
 // MassXRightSubSignalSB->SetDirectory(f);


 f->Write();

}
