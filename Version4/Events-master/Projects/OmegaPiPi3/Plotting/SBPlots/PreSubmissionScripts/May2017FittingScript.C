
{

  //TFile *f = new TFile("March2017Eta1295MCNormT0to1.root","RECREATE");
  //TFile *f = new TFile("March2017BasicNoOmegaMassCorrNormalisation.root","RECREATE");
  //TFile *f = new TFile("March2017ErrorTestingNorm.root","RECREATE");
  // TFile *f = new TFile("May2017ThesisFitsSBMassXDeltaCut.root","RECREATE");
  //TFile *f = new TFile("May2017ThesisFitsSWFixedMassXLorentz.root","RECREATE");
  TFile *f = new TFile("May2017FittingIntegralTest","RECREATE");

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
  //TFile *myFile = TFile::Open("SB5A2Decays1milSubtraction1.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/May2017Basic5BinsMassXVersion4.root");


 // //Fit 1 fitting polynomial plus signal to determine signal magnitude for sideband Mass X.
 // Double_t par1[7];
 // TH1F *fit_histo1;
 // TF1 *s1g2    = new TF1("s1g2","gaus",1.25,1.38);
 // //TF1 *s1g1    = new TF1("s1g1","pol3",1.1,1.24);
 // TF1 *s1g1    = new TF1("s1g1","pol2",1.1,1.24);
 // TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",1.14,1.4);
 // total1->SetLineColor(3);
 
 // fit_histo1 = MassXSB;


 // fit_histo1->Fit(s1g1,"R");
 // fit_histo1->Fit(s1g2,"R+");
 // s1g1->GetParameters(&par1[0]);
 // s1g2->GetParameters(&par1[3]);
 // total1->SetParameters(par1);
 // fit_histo1->Fit(total1,"R+");
 // fit_histo1->Draw();
 // // gPad->Update();
 // // TPaveStats *st = (TPaveStats*)fit_histo1->FindObject("stats");
 // // st->SetOptStat(mode);
 // // gStyle->SetOptFit(1111);
 // fit_histo1->SetDirectory(f);

// //Fit 2 fitting polynomial plus signal to determine signal magnitude for sWeights Mass X.
//  Double_t par1[7];
//  TH1F *fit_histo1;
//  TF1 *s1g2    = new TF1("s1g2","gaus",1.26,1.315);
//  //TF1 *s1g1    = new TF1("s1g1","pol3",1.15,1.25);
//  TF1 *s1g1    = new TF1("s1g1","pol2",1.15,1.25);
//  TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",1.24,1.34);
//  total1->SetLineColor(3);
 
//  fit_histo1 = MXSignal_All;

//  fit_histo1->Fit(s1g1,"R");
//  fit_histo1->Fit(s1g2,"R+");
//  s1g1->GetParameters(&par1[0]);
//  s1g2->GetParameters(&par1[3]);
//  total1->SetParameters(par1);
//  fit_histo1->Fit(total1,"R+");
//  fit_histo1->Draw();
//  // gPad->Update();
//  // TPaveStats *st = (TPaveStats*)fit_histo1->FindObject("stats");
//  // st->SetOptStat(mode);
//  // gStyle->SetOptFit(1111);
//  fit_histo1->SetDirectory(f);


 //Fit 1 fitting polynomial plus signal to determine signal magnitude for sideband Mass X.
 Double_t par1[7];
 Double_t par2[7];
 TH1F *fit_histo1;

// // Macro myfunc.C
// Double_t myfunction(Double_t *x, Double_t *par)
// {
//    Float_t xx =x[0];
//    // Double_t f = TMath::Abs(par[0]*sin(par[1]*xx)/xx);
//    Double_t f = (1/(TMath::Pi()*par[1]))*((par[1]*par[1])/((xx-par[0])*(xx-par[0])+par[1]*par[1]))
//    return f;
// }



//  (1/(TMath::Pi()*[2]))*(([2]*[2])/(([0]-[1])*([0]-[1])+[2]*[2]))


// // Macro myfunc.C
// Double_t normalgaus(Double_t *x, Double_t *par)
// {
//    Float_t xx =x[0];
//    // Double_t f = TMath::Abs(par[0]*sin(par[1]*xx)/xx);
//    Double_t f = ([0]/([2]*TMath::Sqrt(2*TMath::Pi())))  *   (exp(-0.5*    (((xx-[1])/[2])**2)            ))
//    return f;
// }




// fb2->SetParameters(0.2,1.3);
// fb2->Draw();

// TF1 *s1g2 = new TF1("myfunc",myfunction,1.25,1.31,2);
 TF1 *s1g2    = new TF1("s1g2","gaus",1.25,1.31);
 //TF1 *s1g1    = new TF1("s1g1","pol3",1.1,1.24);
 TF1 *s1g1    = new TF1("s1g1","pol2",1.15,1.21);
 // TF1 *s1g1    = new TF1("s1g1","pol2",1.32,1.36);
  TF1 *total1 = new TF1("total1","pol2(0)+gaus(3)",1.22,1.38);
 //TF1 *total1 = new TF1("total1","gaus(0)+pol2(3)",1.22,1.38);
 //TF1 *total1 = new TF1("total1","pol2(0)+myfunc(3)",1.22,1.38);
 total1->SetLineColor(3);
 
 fit_histo1 = MXSignal_All;


 fit_histo1->Fit(s1g1,"R");
 fit_histo1->Fit(s1g2,"R+");
 s1g1->GetParameters(&par1[0]);
 s1g2->GetParameters(&par1[3]);
 //s1g2->GetParameters(&par2[0]);
 total1->SetParameters(par1);
 //fit_histo1->Fit(total1,"R+");
TFitResultPtr r = fit_histo1->Fit(total1,"R+S");
//TFitResultPtr r = fit_histo1->Fit(total1, "S");

 fit_histo1->Draw();
 //fit_histo1->SetDirectory(f);

 total1->GetParameters(&par2[0]);
 // fit_histo1->Fit(s1g2,"R");
 // fit_histo1->Fit(s1g1,"R+");
 // s1g2->GetParameters(&par1[0]);
 // s1g1->GetParameters(&par1[3]);
 // total1->SetParameters(par1);
 // fit_histo1->Fit(total1,"R+");
 // fit_histo1->Draw();




 TF1 *events    = new TF1("events","gaus",1.19,1.4);
 events->SetLineColor(4);
 //events->SetParameter(0,par2[3]);
 //events->SetParameter(1,par2[4]);
 //events->SetParameter(2,par2[5]);
 events->SetParameters(total1->GetParameter(3),total1->GetParameter(4),total1->GetParameter(5));
 Double_t IntegralGaus=events->Integral(1.19, 1.4);
 Double_t binWidth = 0.8/180;
 //s1g2->Draw();
 Double_t scaledEvents = IntegralGaus/binWidth;

 // TMatrixDSym cov = r->GetCovarianceMatrix();
 // // r->Print("V"); 
 // TVirtualFitter *fitter = TVirtualFitter::GetFitter();
 // TMatrixD covMatrix1(3,3);

 // for (Int_t i=0; i<3; i++){
 //   for (Int_t j=0; j<3; j++){
 //     covMatrix1[i][j] = fitter->GetCovarianceMatrixElement(i+3,j+3);    
 //   }
 // }			
 // //covMatrix1.Print();
 
 // //Double_t IntErrGaus = total1->IntegralError(1.19,1.4,r->GetParams(), r->GetCovarianceMatrix()->GetMatrixArray() );
 // Double_t IntErrGaus = total1->IntegralError(1.25,1.31,events->GetParameters(), covMatrix1->GetMatrixArray() );
 // //Double_t IntErrGaus = events->IntegralError(1.19, 1.4, );
 // Double_t IntErrGausScaled = IntErrGaus/binWidth;
 
 // Double_t GausCon = events->GetParameter(0);
 // Double_t GausConEr = r->GetParError(3);
 // Double_t GausSigma = events->GetParameter(2);
 // Double_t GausSigmaEr = r->GetParError(5);

 Double_t GausCon = events->GetParameter(0);
 Double_t GausConEr = 72.7311;
 Double_t GausConRat = GausConEr/GausCon;

 Double_t GausSigma = events->GetParameter(2);
 Double_t GausSigmaEr = 0.00177764;
 Double_t GausSigmaRat = GausSigmaEr/GausSigma;
 
 cout << "Param 1 and Error and Ratio" << GausCon << " " << GausConEr << " " << GausConRat << endl;
 cout << "Param 3 and Error and Ratio" << GausSigma << " " << GausSigmaEr << " " << GausSigmaRat<< endl;
 
 Double_t SimpleIntError = /*TMath::Sqrt(2*TMath::Pi())**/(TMath::Sqrt(   ((GausConEr/GausCon)**2)+((GausSigmaEr/GausSigma)**2)   )    ); 
 Double_t SimpEr = SimpleIntError*scaledEvents; 


 // TF1 *eventsTest    = new TF1("eventsTest","gaus",1.19,1.4);
 // eventsTest->SetParameter(0,1);
 // eventsTest->SetParameter(1,par2[4]);
 // eventsTest->SetParameter(2,par2[5]);
 // Double_t IntegralGausTest=eventsTest->Integral(1.19, 1.4);
 // Double_t scaledEventsTest = IntegralGausTest/binWidth;

 events->Draw("same");
 cout << "Integral of Total Events " << IntegralGaus << endl;
 cout << "Scaled Total Events " << scaledEvents << endl;
 // cout << "Integral of Total Events Error " << IntErrGaus << endl;
 // cout << "Scaled Error " << IntErrGausScaled << endl;
 cout << "Simple Error Percentage" << SimpleIntError << endl;
 cout << "Simple Error " << SimpEr << endl;

 // cout << "Integral Events Test " << IntegralGausTest << endl;
 // cout << "Scaled Total Events Test " << scaledEventsTest << endl;

 // //file f1ex.C
//  double testfunc(double *x, double *par) {
//    double s;
//    s = sin(x[0]);
//    return s;
//  }
//  void f1ex() {
//    TF1 *f1 = new TF1("f1",testfunc,-6,6,0);
//    f1->Draw();
// }

 // gPad->Update();
 // TPaveStats *st = (TPaveStats*)fit_histo1->FindObject("stats");
 // st->SetOptStat(mode);
 // gStyle->SetOptFit(1111);
 
 //fit_histo1->SetDirectory(f);


 // Double_t IntegralLeft=total7->Integral(0.722, 0.752);
 // Double_t IntegralMiddle=total7->Integral(0.752, 0.812);
 // Double_t IntegralRight=total7->Integral(0.812, 0.842);
 // Double_t IntegralTotal=total7->Integral(0.722, 0.842);

 // cout << "Integral of Left Events " << IntegralLeft << endl;
 // cout << "Integral of Middle Events " << IntegralMiddle << endl;
 // cout << "Integral of Right Events " << IntegralRight << endl;
 // cout << "Integral of Total Events " << IntegralTotal << endl;




 // //Slice 8
 

 // //Slice 9
 // Double_t par9[7];
 // TH1D *slice_histo9;
 // TF1 *s9g2    = new TF1("s9g2","gaus",0.765,0.80);
 // TF1 *s9g1    = new TF1("s9g1","pol1",0.82,0.87);
 // TF1 *total9 = new TF1("total9","pol1(0)+gaus(2)",0.7,0.88);
 // total9->SetLineColor(3);
 
 // slice_histo9 = MOmvsMXAll_All->ProjectionX("Slice9 Fit",8,9);
 
 // slice_histo9->Fit(s9g1,"R");
 // slice_histo9->Fit(s9g2,"R+");
 // s9g1->GetParameters(&par9[0]);
 // s9g2->GetParameters(&par9[2]);
 // total9->SetParameters(par9);
 // slice_histo9->Fit(total9,"R+");
 // slice_histo9->Draw();
 // slice_histo9->SetDirectory(f);

 // //Slice 10
 // Double_t par10[7];
 // TH1D *slice_histo10;
 // TF1 *s10g2    = new TF1("s10g2","gaus",0.765,0.795);
 // TF1 *s10g1    = new TF1("s10g1","pol1",0.71,0.72);
 // TF1 *total10 = new TF1("total10","pol1(0)+gaus(2)",0.7,0.83);
 // total10->SetLineColor(3);
 
 // slice_histo10 = MOmvsMXAll_All->ProjectionX("Slice10 Fit",9,10);
 
 // slice_histo10->Fit(s10g1,"R");
 // slice_histo10->Fit(s10g2,"R+");
 // s10g1->GetParameters(&par10[0]);
 // s10g2->GetParameters(&par10[2]);
 // total10->SetParameters(par10);
 // slice_histo10->Fit(total10,"R+");
 // slice_histo10->Draw();
 // slice_histo10->SetDirectory(f);

 
 // px->Fit(g1,"R");
 // px->Fit(g2,"R+");
 // g1->GetParameters(&par[0]);
 // g2->GetParameters(&par[2]);
 // total->SetParameters(par);
 // px->Fit(total,"R+");
 
 // cout << "---------------------------------------------------------" << endl ;
 // cout << "---------------------------------------------------------" << endl ;
 // cout << "Fitting Result for Histogram "<< px->GetName() << endl;
 // cout << "---------------------------------------------------------" << endl ;
 // cout << "Polynomial [0] + [1] x + [2] x^2" << endl;
 // cout << "[0] =" << total->GetParameter(0);
 // cout << "[1] =" << total->GetParameter(1);
 // cout << "Gaussian [0] * exp( (x-[1])/ (2[2]^2) )" << endl;
 // cout << "[0] =" << total->GetParameter(2);
 // cout << "[1] =" << total->GetParameter(3);
 // cout << "[2] =" << total->GetParameter(4);
 // cout << "---------------------------------------------------------" << endl ;
 // cout << "---------------------------------------------------------" << endl ;
 // cout << "" <<	endl;

 // px->Draw();


 //MOmvsMXAll_All->FitSlicesX(total,1,10,0,"QNR");
 
 //MassOmegavsMassXSB->SetDirectory(f);

 //MOmvsMXAll_All_0->SetDirectory(f);
 //MOmvsMXAll_All_1->SetDirectory(f);
 //MOmvsMXAll_All_2->SetDirectory(f);
 //MOmvsMXAll_All_3->SetDirectory(f);
 //MOmvsMXAll_All_4->SetDirectory(f);
 //MOmvsMXAll_All_5->SetDirectory(f);
 
 f->Write();
 
  }


