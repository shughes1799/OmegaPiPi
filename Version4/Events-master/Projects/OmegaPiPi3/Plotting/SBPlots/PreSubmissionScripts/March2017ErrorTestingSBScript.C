{
  //TFile *f = new TFile("March2017BasicSubtractedAdjNorm2.root","RECREATE");
  //TFile *f = new TFile("March2017Eta1295MCDataSubtractedT0to1NewFit.root","RECREATE");
  //TFile *f = new TFile("March2017BinnedT2to5MX1p25to1p33SubtractedAdjNorm.root","RECREATE");
  // TFile *f = new TFile("March2017TwoDimSBSubtractedTest2BinsNoOmegaCorr.root","RECREATE");
  //TFile *f = new TFile("March2017TwoDimSBEightBinsSubtractedAdjNorm.root","RECREATE");
  TFile *f = new TFile("March2017ErrorTestingSubtractedAdjNorm2.root","RECREATE");

  //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017Basic.root");
  //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017TwoDimSBTest2NoOmegaCorr.root ");
  // TFile *myFile = TFile::Open("March2017TwoDimSBEightBins.root");
  TFile *myFile = TFile::Open("March2017ErrorTesting.root");
  

  //Normalisation Parameters

  Double_t leftBack = 1178.15;
  Double_t signalBack = 1996.66;
  Double_t rightBack = 784.718;
  Double_t combNorm = signalBack/(leftBack+rightBack);

  Double_t leftBack1 = 73.6982;
  Double_t signalBack1 = 131.324;
  Double_t rightBack1 = 54.3619;
  Double_t leftNorm1   = signalBack1/leftBack1;
  Double_t rightNorm1  = signalBack1/rightBack1;
  Double_t combNorm1 = signalBack1/(leftBack1+rightBack1);

  Double_t leftBack2 = 158.203;
  Double_t signalBack2 = 271.378;
  Double_t rightBack2 = 108.257;
  Double_t combNorm2 = signalBack2/(leftBack2+rightBack2);

  Double_t leftBack3 = 206.854;
  Double_t signalBack3 = 364.418;
  Double_t rightBack3 = 153.635;
  Double_t combNorm3 = signalBack3/(leftBack3+rightBack3);

  Double_t leftBack4 = 219.884;
  Double_t signalBack4 = 390.406;
  Double_t rightBack4 = 160.334;
  Double_t combNorm4 = signalBack4/(leftBack4+rightBack4);

  Double_t leftBack5 = 201.251;
  Double_t signalBack5 = 345.976;
  Double_t rightBack5 = 138.123;
  Double_t combNorm5 = signalBack5/(leftBack5+rightBack5);

  Double_t leftBack6 = 154.94;
  Double_t signalBack6 = 261.622;
  Double_t rightBack6 = 100.626;
  Double_t combNorm6 = signalBack6/(leftBack6+rightBack6);

  Double_t leftBack7 = 101.589;
  Double_t signalBack7 = 157.687;
  Double_t rightBack7 = 53.0327;
  Double_t combNorm7 = signalBack7/(leftBack7+rightBack7);

  Double_t leftBack8 = 60.3308;
  Double_t signalBack8 = 71.9206;
  Double_t rightBack8 = 15.4887;
  Double_t combNorm8 = signalBack8/(leftBack8+rightBack8);



  // TFile *myFile = TFile::Open("SB4Plots4.root");

  // TTreeReader myReader("ntuple", myFile);

  TH1F *MassXSB = new TH1F("MassXSB", "Sideband subtracted Mass X;MassX (GeV)", 180, 1.1, 1.9);
 
  // TH1F *MassXNormSignal = new TH1F("MassXNormSignal", "Normalised Mass X Signal Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormLeft = new TH1F("MassXNormLeft", "Normalised Mass X Left Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormRight = new TH1F("MassXNormRight", "Normalised Mass X Right Region;MassX (GeV)", 180, 1.1, 1.9);
  // TH1F *MassXNormBothSB = new TH1F("MassXNormBothSB", "Normalised Mass X Side Regions;MassX (GeV)", 180, 1.1, 1.9);

 
  // TH2F *MassOmegavsMassXSg = new TH2F("MassOmegavsMassXSg", "Signal Region #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);
  // TH2F *MassOmegavsMassXBg = new TH2F("MassOmegavsMassXBg", "Background #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);
  TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted #omega vs Mass X(#omega#pi#pi);#omega (GeV);MassX(#omega#pi#pi) (GeV)",120,0.722,0.842,100,1.1,1.9);
  //TH2F *MassOmegavsMassXSB2 = new TH2F("MassOmegavsMassXSB2", "Sideband subtracted #omega vs Mass X;#omega p (GeV);MassX (GeV)",120,0.722,0.842,100,1.1,1.9);

  Int_t j2 = 1;

  
  for(int l=1;l<181;l++){
    
  //Normalised Sideband subtraction of signal region.
  Double_t bgXL = MXFullLeft_All->GetBinContent(l);
  Double_t bgXR = MXFullRight_All->GetBinContent(l);
  Double_t bgXSide = MXFullSide_All->GetBinContent(l);
  Double_t bgXSideEr = MXFullSide_All->GetBinError(l);
  cout << "Side Value and Bin Error " << bgXSide  << " "<< bgXSideEr << endl;
  //cout << "Left Value and Bin Error " << bgXL  << " "<<bgXEr << endl;
  bgXL = bgXL*combNorm;
  bgXR = bgXR*combNorm;
  bgXSide = bgXSide*combNorm;
  bgXSideEr = bgXSideEr*combNorm;
  cout << "Side Value and Bin Error (Norm) " << bgXSide  << " "<< bgXSideEr << endl;
  Double_t bgComb;
  bgComb = bgXL+bgXR;
  // bgXEr = bgXEr/2; //This is wrong
  Double_t signalX = MXFullSignal_All->GetBinContent(l);
  Double_t signalXEr = MXFullSignal_All->GetBinError(l);
  cout << "Signal Value and Bin Error (Norm) " << signalX  << " "<< signalXEr << endl;
  //Double_t subtractedX = signalX-bgComb;
  Double_t subtractedX = signalX-bgXSide;
  //cout << "Left Value and Bin Error " << bgXL  << " "<<bgXEr << endl;
  Double_t ErrorStep = (signalXEr*signalXEr+bgXSideEr*bgXSideEr);
  cout << "Error Step " << ErrorStep << endl;
  Double_t subtractedXEr = TMath::Sqrt(ErrorStep); //this is wrong
  //Double_t subtractedXEr = ErrorStep^(0.5); //this is wrong
  cout << "Subtracted Value and Bin Error (Norm) " << subtractedX  << " "<< subtractedXEr << endl;
  MassXSB->SetBinContent(l,subtractedX);
  MassXSB->SetBinError(l,subtractedXEr);

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
  
  MassXSB->SetDirectory(f);
  //MassPiPPiMSB->SetDirectory(f);
  //MassOmegavsMassXSB->SetDirectory(f);
  //MassOmegavsMassXSB2->SetDirectory(f);
  // MassOmegavsMassXSg->SetDirectory(f);
  //MassOmegavsMassXBg->SetDirectory(f);


 f->Write();

}
