{
  //TFile *f = new TFile("March2017BasicSubtractedAdjNorm2.root","RECREATE");
  //TFile *f = new TFile("March2017Eta1295MCDataSubtractedT0to1NewFit.root","RECREATE");
  //TFile *f = new TFile("March2017BinnedT2to5MX1p25to1p33SubtractedAdjNorm.root","RECREATE");
  // TFile *f = new TFile("March2017TwoDimSBSubtractedTest2BinsNoOmegaCorr.root","RECREATE");
  //TFile *f = new TFile("March2017TwoDimSBEightBinsSubtractedAdjNorm.root","RECREATE");
  //TFile *f = new TFile("March2017ErrorTestingSubtractedAdjNorm2.root","RECREATE");
  //TFile *f = new TFile("May2017ErrorT2to5SubtractedAdjNorm.root","RECREATE");
  //TFile *f = new TFile("May2017ErrorBase180BinsSubtractedAdjNorm.root","RECREATE");
  //TFile *f = new TFile("Aug2017Sig60SB30Gap30Subtracted.root","RECREATE");
  //TFile *f = new TFile("Nov2017Data16Files100Signal40SBSubtracted.root","RECREATE");
  //TFile *f = new TFile("Nov2017PS100MilRecon100Signal40SBSubtracted.root","RECREATE");
  //TFile *f = new TFile("Dec2017Data16Files60Signal30SBSubtracted.root","RECREATE");
  TFile *f = new TFile("Dec2017PS100MilRecon60Signal30SBCorr6MeVSubtracted.root","RECREATE");

  //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017Basic.root");
  //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017TwoDimSBTest2NoOmegaCorr.root ");
  // TFile *myFile = TFile::Open("March2017TwoDimSBEightBins.root");
  //TFile *myFile = TFile::Open("March2017ErrorTesting.root");
  //TFile *myFile = TFile::Open("Feb2017BinnedT2to5.root");
  //TFile *myFile = TFile::Open("Feb2017BinnedEgamma3p3to3p9.root");
  //TFile *myFile = TFile::Open("May2017ErrorBase180Bins.root");
  //TFile *myFile = TFile::Open("Aug2017Sig60SB30Gap30.root");
  //TFile *myFile = TFile::Open("Nov2017Data16Files100Signal40SB.root");
  //TFile *myFile = TFile::Open("Nov2017PS100MilRecon100Signal40SB.root");
  //TFile *myFile = TFile::Open("Dec2017Data16Files60Signal30SB.root");
  TFile *myFile = TFile::Open("Dec2017PS100MilRecon60Signal30SBCorr6MeV.root");
 
  

  //Normalisation Parameters

  Double_t leftBack = 298.471;
  Double_t signalBack = 585.367;
  Double_t rightBack = 218.374;
  Double_t combNorm = signalBack/(leftBack+rightBack);


  // TFile *myFile = TFile::Open("SB4Plots4.root");

  // TTreeReader myReader("ntuple", myFile);

  
  //TH1F *MassXSB = new TH1F("MassXSB", "Sideband subtracted Mass X;Mass(GeV)", 180, 1.1, 1.9);
  TH1F *MassXSBMCRecon = new TH1F("MassXSBMCRecon", "Sideband subtracted Mass X;Mass(GeV)", 180, 1.1, 1.9);

  // TH1F *MassPiPProSB = new TH1F("MassPiPProSB", "Sideband Subtracted p#pi^{+};Mass(GeV)", 180, 1.05, 1.8);
  // TH1F *MassPiMProSB = new TH1F("MassPiMProSB", "Sideband Subtracted p#pi^{-};Mass(GeV)", 180, 1.05, 1.8);
  // TH1F *MassOmPiPSB = new TH1F("MassOmPiPSB", "Sideband Subtracted #omega#pi^{+};Mass(GeV)", 180, 0.9, 1.5);
  // TH1F *MassOmPiMSB = new TH1F("MassOmPiMSB", "Sideband Subtracted #omega#pi^{-};Mass(GeV)", 180, 0.9, 1.5);
 
  // TH1F *MassXNormSignal = new TH1F("MassXNormSignal", "Normalised Mass X Signal Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormLeft = new TH1F("MassXNormLeft", "Normalised Mass X Left Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormRight = new TH1F("MassXNormRight", "Normalised Mass X Right Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormBothSB = new TH1F("MassXNormBothSB", "Normalised Mass X Side Regions;MassX (GeV)", 180, 1.1, 1.9);

 
  // TH2F *MassOmegavsMassXSg = new TH2F("MassOmegavsMassXSg", "Signal Region #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);
  // TH2F *MassOmegavsMassXBg = new TH2F("MassOmegavsMassXBg", "Background #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);
  // TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted #omega vs Mass X(#omega#pi#pi);#omega (GeV);MassX(#omega#pi#pi) (GeV)",120,0.722,0.842,100,1.1,1.9);
  //TH2F *MassOmegavsMassXSB2 = new TH2F("MassOmegavsMassXSB2", "Sideband subtracted #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);

  Int_t j2 = 1;

  
  for(int l=1;l<181;l++){
    
  //Normalised Sideband subtraction of signal region for MassX
  Double_t bgXL = MXFullMCReconLeft_All->GetBinContent(l);
  Double_t bgXR = MXFullMCReconRight_All->GetBinContent(l);
  Double_t bgXSide = MXFullMCReconSide_All->GetBinContent(l);
  Double_t bgXSideEr = MXFullMCReconSide_All->GetBinError(l);
  // cout << "Side Value and Bin Error " << bgXSide  << " "<< bgXSideEr << endl;
  //cout << "Left Value and Bin Error " << bgXL  << " "<<bgXEr << endl;
  bgXL = bgXL*combNorm;
  bgXR = bgXR*combNorm;
  bgXSide = bgXSide*combNorm;
  bgXSideEr = bgXSideEr*combNorm;
  // cout << "Side Value and Bin Error (Norm) " << bgXSide  << " "<< bgXSideEr << endl;
  Double_t bgComb;
  bgComb = bgXL+bgXR;
  // bgXEr = bgXEr/2; //This is wrong
  Double_t signalX = MXFullMCReconSignal_All->GetBinContent(l);
  Double_t signalXEr = MXFullMCReconSignal_All->GetBinError(l);
  //cout << "Signal Value and Bin Error (Norm) " << signalX  << " "<< signalXEr << endl;
  //Double_t subtractedX = signalX-bgComb;
  Double_t subtractedX = signalX-bgXSide;
  //cout << "Left Value and Bin Error " << bgXL  << " "<<bgXEr << endl;
  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
  //cout << "Error Step " << ErrorStep << endl;
  Double_t subtractedXEr = TMath::Sqrt(ErrorStep); 
  //Double_t subtractedXEr = ErrorStep^(0.5); //this is wrong
  //cout << "Subtracted Value and Bin Error (Norm) " << subtractedX  << " "<< subtractedXEr << endl;
  MassXSBMCRecon->SetBinContent(l,subtractedX);
  MassXSBMCRecon->SetBinError(l,subtractedXEr);

 // //Normalised Sideband subtraction of signal region for PiPPro
 //  Double_t bgXL = MPiPProLeft_All->GetBinContent(l);
 //  Double_t bgXR = MPiPProRight_All->GetBinContent(l);
 //  Double_t bgXSide = MPiPProSide_All->GetBinContent(l);
 //  Double_t bgXSideEr = MPiPProSide_All->GetBinError(l);
 //  bgXL = bgXL*combNorm;
 //  bgXR = bgXR*combNorm;
 //  bgXSide = bgXSide*combNorm;
 //  bgXSideEr = bgXSideEr*combNorm;
 //  Double_t bgComb;
 //  bgComb = bgXL+bgXR;
 //  Double_t signalX = MPiPProSignal_All->GetBinContent(l);
 //  Double_t signalXEr = MPiPProSignal_All->GetBinError(l);
 //  Double_t subtractedX = signalX-bgXSide;
 //  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
 //  Double_t subtractedXEr = TMath::Sqrt(ErrorStep); 
 //  MassPiPProSB->SetBinContent(l,subtractedX);
 //  MassPiPProSB->SetBinError(l,subtractedXEr);

 //  //Normalised Sideband subtraction of signal region for PiMPro
 //  Double_t bgXL = MPiMProLeft_All->GetBinContent(l);
 //  Double_t bgXR = MPiMProRight_All->GetBinContent(l);
 //  Double_t bgXSide = MPiMProSide_All->GetBinContent(l);
 //  Double_t bgXSideEr = MPiMProSide_All->GetBinError(l);
 //  bgXL = bgXL*combNorm;
 //  bgXR = bgXR*combNorm;
 //  bgXSide = bgXSide*combNorm;
 //  bgXSideEr = bgXSideEr*combNorm;
 //  Double_t bgComb;
 //  bgComb = bgXL+bgXR;
 //  Double_t signalX = MPiMProSignal_All->GetBinContent(l);
 //  Double_t signalXEr = MPiMProSignal_All->GetBinError(l);
 //  Double_t subtractedX = signalX-bgXSide;
 //  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
 //  Double_t subtractedXEr = TMath::Sqrt(ErrorStep);
 //  MassPiMProSB->SetBinContent(l,subtractedX);
 //  MassPiMProSB->SetBinError(l,subtractedXEr);

 //  //Normalised Sideband subtraction of signal region for OmPiP
 //  Double_t bgXL = MOmPiPLeft_All->GetBinContent(l);
 //  Double_t bgXR = MOmPiPRight_All->GetBinContent(l);
 //  Double_t bgXSide = MOmPiPSide_All->GetBinContent(l);
 //  Double_t bgXSideEr = MOmPiPSide_All->GetBinError(l);
 //  bgXL = bgXL*combNorm;
 //  bgXR = bgXR*combNorm;
 //  bgXSide = bgXSide*combNorm;
 //  bgXSideEr = bgXSideEr*combNorm;
 //  Double_t bgComb;
 //  bgComb = bgXL+bgXR;
 //  Double_t signalX = MOmPiPSignal_All->GetBinContent(l);
 //  Double_t signalXEr = MOmPiPSignal_All->GetBinError(l);
 //  Double_t subtractedX = signalX-bgXSide;
 //  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
 //  Double_t subtractedXEr = TMath::Sqrt(ErrorStep);
 //  MassOmPiPSB->SetBinContent(l,subtractedX);
 //  MassOmPiPSB->SetBinError(l,subtractedXEr);

 //  //Normalised Sideband subtraction of signal region for OmPiM
 //  Double_t bgXL = MOmPiMLeft_All->GetBinContent(l);
 //  Double_t bgXR = MOmPiMRight_All->GetBinContent(l);
 //  Double_t bgXSide = MOmPiMSide_All->GetBinContent(l);
 //  Double_t bgXSideEr = MOmPiMSide_All->GetBinError(l);
 //  bgXL = bgXL*combNorm;
 //  bgXR = bgXR*combNorm;
 //  bgXSide = bgXSide*combNorm;
 //  bgXSideEr = bgXSideEr*combNorm;
 //  Double_t bgComb;
 //  bgComb = bgXL+bgXR;
 //  Double_t signalX = MOmPiMSignal_All->GetBinContent(l);
 //  Double_t signalXEr = MOmPiMSignal_All->GetBinError(l);
 //  Double_t subtractedX = signalX-bgXSide;
 //  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
 //  Double_t subtractedXEr = TMath::Sqrt(ErrorStep);
 //  MassOmPiMSB->SetBinContent(l,subtractedX);
 //  MassOmPiMSB->SetBinError(l,subtractedXEr);

  }


  
  // for(int j=1;j<11;j++){
    
  //   for(int k=1;k<31;k++){
  //     //Mass of Omega vs Mass of X Bin 1 part 1
  //     Double_t bgL = MOmvsMXLeft1_All->GetBinContent(k,j2);
  //     Double_t bgR = MOmvsMXRight1_All->GetBinContent(k+90,j2);
  //     // cout << "bgL, BgR " << bgL << " " << bgR << " " << endl;
  //     bgL = bgL*combNorm1;
  //     bgR = bgR*combNorm1;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal1_All->GetBinContent((k*2)+29,j2);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2,sub);
  //     // cout << "Comb Norm, BgComb, sg, sub " << combNorm1 << " " << bgComb << " " << sg << " " << sub << endl;

  //     Double_t sg2 = MOmvsMXSignal1_All->GetBinContent((k*2)+30,j2);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2,sub2);
  //     // cout << "Comb Norm, BgComb, sg2, sub2 " << combNorm1 << " " << bgComb << " " << sg2 << " " << sub2 << endl;

  //     //Mass of Omega vs Mass of X Bin 1 part 2
  //     Double_t bgL = MOmvsMXLeft1_All->GetBinContent(k,j2+10);
  //     Double_t bgR = MOmvsMXRight1_All->GetBinContent(k+90,j2+10);
  //     bgL = bgL*combNorm1;
  //     bgR = bgR*combNorm1;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal1_All->GetBinContent((k*2)+29,j2+10);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+10,sub);

  //     Double_t sg2 = MOmvsMXSignal1_All->GetBinContent((k*2)+30,j2+10);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+10,sub2);

  //     //Mass of Omega vs Mass of X Bin 2
  //     Double_t bgL = MOmvsMXLeft2_All->GetBinContent(k,j2+20);
  //     Double_t bgR = MOmvsMXRight2_All->GetBinContent(k+90,j2+20);
  //     bgL = bgL*combNorm2;
  //     bgR = bgR*combNorm2;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal2_All->GetBinContent((k*2)+29,j2+20);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+20,sub);
  //     cout << "Comb Norm, BgComb, sg, sub " << combNorm2 << " " << bgComb << " " << sg << " " << sub << endl;
  //     Double_t sg2 = MOmvsMXSignal2_All->GetBinContent((k*2)+30,j2+20);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+20,sub2);
  //     cout << "Comb Norm, BgComb, sg2, sub2 " << combNorm2 << " " << bgComb << " " << sg2 << " " << sub2 << endl;


  //     //Mass of Omega vs Mass of X Bin 3
  //     Double_t bgL = MOmvsMXLeft3_All->GetBinContent(k,j2+30);
  //     Double_t bgR = MOmvsMXRight3_All->GetBinContent(k+90,j2+30);
  //     bgL = bgL*combNorm3;
  //     bgR = bgR*combNorm3;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal3_All->GetBinContent((k*2)+29,j2+30);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+30,sub);

  //     Double_t sg2 = MOmvsMXSignal3_All->GetBinContent((k*2)+30,j2+30);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+30,sub2);

  //     //Mass of Omega vs Mass of X Bin 4
  //     Double_t bgL = MOmvsMXLeft4_All->GetBinContent(k,j2+40);
  //     Double_t bgR = MOmvsMXRight4_All->GetBinContent(k+90,j2+40);
  //     //cout << "bgL, BgR " << bgL << " " << bgR << " " << endl;
  //     bgL = bgL*combNorm4;
  //     bgR = bgR*combNorm4;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal4_All->GetBinContent((k*2)+29,j2+40);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+40,sub);
  //     //cout << "Comb Norm4, BgComb, sg, sub " << combNorm4 << " " << bgComb << " " << sg << " " << sub << endl;

  //     Double_t sg2 = MOmvsMXSignal4_All->GetBinContent((k*2)+30,j2+40);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+40,sub2);

  //    //Mass of Omega vs Mass of X Bin 5
  //     Double_t bgL = MOmvsMXLeft5_All->GetBinContent(k,j2+50);
  //     Double_t bgR = MOmvsMXRight5_All->GetBinContent(k+90,j2+50);
  //     bgL = bgL*combNorm5;
  //     bgR = bgR*combNorm5;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal5_All->GetBinContent((k*2)+29,j2+50);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+50,sub);

  //     Double_t sg2 = MOmvsMXSignal5_All->GetBinContent((k*2)+30,j2+50);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+50,sub2);

  //     //Mass of Omega vs Mass of X Bin 6
  //     Double_t bgL = MOmvsMXLeft6_All->GetBinContent(k,j2+60);
  //     Double_t bgR = MOmvsMXRight6_All->GetBinContent(k+90,j2+60);
  //     bgL = bgL*combNorm6;
  //     bgR = bgR*combNorm6;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal6_All->GetBinContent((k*2)+29,j2+60);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+60,sub);

  //     Double_t sg2 = MOmvsMXSignal6_All->GetBinContent((k*2)+30,j2+60);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+60,sub2);

  //     //Mass of Omega vs Mass of X Bin 7
  //     Double_t bgL = MOmvsMXLeft7_All->GetBinContent(k,j2+70);
  //     Double_t bgR = MOmvsMXRight7_All->GetBinContent(k+90,j2+70);
  //     bgL = bgL*combNorm7;
  //     bgR = bgR*combNorm7;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal7_All->GetBinContent((k*2)+29,j2+70);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+70,sub);

  //     Double_t sg2 = MOmvsMXSignal7_All->GetBinContent((k*2)+30,j2+70);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+70,sub2);

  //     //Mass of Omega vs Mass of X Bin 8 part 1
  //     Double_t bgL = MOmvsMXLeft8_All->GetBinContent(k,j2+80);
  //     Double_t bgR = MOmvsMXRight8_All->GetBinContent(k+90,j2+80);
  //     bgL = bgL*combNorm8;
  //     bgR = bgR*combNorm8;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal8_All->GetBinContent((k*2)+29,j2+80);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+80,sub);
     
  //     Double_t sg2 = MOmvsMXSignal8_All->GetBinContent((k*2)+30,j2+80);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+80,sub2);

  //     //Mass of Omega vs Mass of X Bin 8 part 2
  //     Double_t bgL = MOmvsMXLeft8_All->GetBinContent(k,j2+90);
  //     Double_t bgR = MOmvsMXRight8_All->GetBinContent(k+90,j2+90);
  //     bgL = bgL*combNorm8;
  //     bgR = bgR*combNorm8;
  //     Double_t bgComb = (bgL+bgR)/2;
  //     Double_t sg = MOmvsMXSignal8_All->GetBinContent((k*2)+29,j2+90);
  //     Double_t sub = sg-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+29,j2+90,sub);
     
  //     Double_t sg2 = MOmvsMXSignal8_All->GetBinContent((k*2)+30,j2+90);
  //     Double_t sub2 = sg2-bgComb;
  //     MassOmegavsMassXSB->SetBinContent((k*2)+30,j2+90,sub2);

  // }
    // cout << "Cycle End " << j2 << endl;
    j2++;
    // }
  j2=1;
  
  MassXSBMCRecon->SetDirectory(f);
  // MassPiPProSB->SetDirectory(f);
  // MassPiMProSB->SetDirectory(f);
  // MassOmPiPSB->SetDirectory(f);
  // MassOmPiMSB->SetDirectory(f);

  //MassPiPPiMSB->SetDirectory(f);
  //MassOmegavsMassXSB->SetDirectory(f);
  //MassOmegavsMassXSB2->SetDirectory(f);
  //MassOmegavsMassXSg->SetDirectory(f);
  //MassOmegavsMassXBg->SetDirectory(f);


 f->Write();

}
