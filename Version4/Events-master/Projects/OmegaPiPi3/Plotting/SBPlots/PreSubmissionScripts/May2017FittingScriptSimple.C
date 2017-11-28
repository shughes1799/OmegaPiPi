
{

  //TFile *f = new TFile("March2017Eta1295MCNormT0to1.root","RECREATE");
  //TFile *f = new TFile("March2017BasicNoOmegaMassCorrNormalisation.root","RECREATE");
  //TFile *f = new TFile("March2017ErrorTestingNorm.root","RECREATE");
  // TFile *f = new TFile("May2017ThesisFitsSBMassXDeltaCut.root","RECREATE");
  //TFile *f = new TFile("May2017ThesisFitsSWFixedMassXLorentz.root","RECREATE");
  //TFile *f = new TFile("May2017FittingIntegralTests","RECREATE");
  TFile *f = new TFile("Oct2017FittingIntegralTests","RECREATE");

 //TFile *myFile = TFile::Open("Dec2016TestRun4.root");
 // TFile *myFile = TFile::Open("Jan2017Normalisation2HalfWidthSB1675Rho.root");
 //TFile *myFile = TFile::Open("Dec2016TestRun10Bins.root");
 //TFile *myFile = TFile::Open("Feb2017NormPS10MilDataHalfWidthSB.root");
 //TFile *myFile = TFile::Open("Feb2017BinnedEgamma3p3to3p9.root");
 //TFile *myFile = TFile::Open("Feb2017BinnedT2to5.root");
 //TFile *myFile = TFile::Open("March2017Eta1295MCDataT0to1.root");
 //TFile *myFile = TFile::Open("March2017BinnedT2to5MX1p25to1p33.root");
  //TFile *myFile = TFile::Open("March2017BasicNoOmegaMassCorr.root");
  //TFile *myFile = TFile::Open("March2017TwoDimSBEightBins.root");
  //TFile *myFile = TFile::Open("March2017ErrorTesting.root");
  //TFile *myFile = TFile::Open("March2017ErrorTestingSubtractedAdjNorm2.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Feb2017MoreHistos.root");
  //TFile *myFile = TFile::Open("Jan2017BinnedMassXSubtractionsDeltas5.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB5A2Decays1milSubtraction1.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/May2017Basic5BinsMassXVersion4.root");
  //TFile *myFile = TFile::Open("May2017ErrorEgamma1p5to2p7SubtractedAdjNorm.root");
  // TFile *myFile = TFile::Open("May2017ErrorT0to1SubtractedAdjNorm.root");
  //TFile *myFile = TFile::Open("Jan2017Normalisation1.root");
  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/May2017Basic5BinsMassXVersionB1Stuff180Bins.root");
  //TFile *myFile = TFile::Open("May2017ErrorBase180BinsDeltaCutSubtractedAdjNorm.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Oct2017/Oct20175BinsMassXB1Cut100MeV.root");


 //Fit 1 fitting polynomial plus signal to determine signal magnitude for sideband Mass X.
 Double_t par1[7];
 Double_t par2[7];
 TH1F *fit_histo1;

 // //Fit Functions for extraction information about the peak at 1.3 GeV
  // TF1 *s1g2    = new TF1("s1g2","gaus",1.255,1.355);
  // TF1 *s1g1    = new TF1("s1g1","pol2",1.12,1.22);
  // TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",1.205,1.4);

//Fit Functions for extraction information about the peak at 1.65 GeV
 TF1 *s1g2    = new TF1("s1g2","gaus",1.6,1.68);
 //TF1 *s1g1    = new TF1("s1g1","pol2",1.72,1.87);
 TF1 *s1g1    = new TF1("s1g1","pol2",1.50,1.59);
 TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",1.54,1.82);


 //  //Test of Omega width
 // TF1 *s1g2    = new TF1("s1g2","gaus",0.76,0.8);
 // TF1 *s1g1    = new TF1("s1g1","pol2",0.82,0.84);
 // TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",0.722,0.842);

 total1->SetLineColor(2);
 s1g1->SetLineColor(3);
 s1g2->SetLineColor(3);

 
 fit_histo1 = MXSignal_All;
 //fit_histo1 = MassXSB;
 //fit_histo1 = MXE1p5to2p7Signal_All;
 //fit_histo1 = MmissAll_All;
 //fit_histo1 = MXDeltaCutSignal_All;
 //fit_histo1 = MXOmPiMCutSignal_All;

 fit_histo1->Fit(s1g1,"R");
 fit_histo1->Fit(s1g2,"R+");
 s1g1->GetParameters(&par1[0]);
 s1g2->GetParameters(&par1[3]);
 total1->SetParameters(par1);
 //fit_histo1->Fit(total1,"R+");
TFitResultPtr r = fit_histo1->Fit(total1,"R+S");

 fit_histo1->Draw();
 //fit_histo1->SetDirectory(f);

 total1->GetParameters(&par2[0]);

 //TF1 *events    = new TF1("events","gaus",1.22,1.35);
 //TF1 *events    = new TF1("events","gaus",0.722,0.842);
 TF1 *events    = new TF1("events","gaus",1.55,1.75);
 events->SetLineColor(2);

 events->SetParameters(total1->GetParameter(3),total1->GetParameter(4),total1->GetParameter(5));
 //Double_t IntegralGaus=events->Integral(1.24, 1.32);
 Double_t IntegralGaus=events->Integral(1.65, 1.75);
 //Double_t IntegralGaus=events->Integral(0.722, 0.842);
 Double_t binWidth = 0.8/180;
 //Double_t binWidth = 0.18/180;
 Double_t scaledEvents = IntegralGaus/binWidth;


 Double_t GausCon = events->GetParameter(0);
 Double_t GausConEr = 33.1961;
 Double_t GausConRat = GausConEr/GausCon;

 Double_t GausSigma = events->GetParameter(2);
 Double_t GausSigmaEr = 0.0148323;
 Double_t GausSigmaRat = GausSigmaEr/GausSigma;

 Double_t GausFWHM = GausSigma*2.35482*1000;
 Double_t GausFWHMer = GausSigmaEr*2.35482*1000;
 
 cout << "Param 1 and Error and Ratio " << GausCon << " " << GausConEr << " " << GausConRat << endl;
 cout << "Param 3 and Error and Ratio " << GausSigma << " " << GausSigmaEr << " " << GausSigmaRat<< endl;
 cout << "Gaus FWHM and Error " << GausFWHM << " " << GausFWHMer << endl;
 
 Double_t SimpleIntError = (TMath::Sqrt(((GausConEr/GausCon)**2)+((GausSigmaEr/GausSigma)**2))); 
 Double_t SimpEr = SimpleIntError*scaledEvents; 

 events->Draw("same");
 cout << "Integral of Total Events " << IntegralGaus << endl;
 cout << "Scaled Total Events " << scaledEvents << endl;
 cout << "Simple Error Percentage" << SimpleIntError << endl;
 cout << "Simple Error " << SimpEr << endl;

 f->Write();
 
  }


