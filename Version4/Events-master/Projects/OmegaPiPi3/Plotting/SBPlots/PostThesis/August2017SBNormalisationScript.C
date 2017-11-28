
{

  //TFile *f = new TFile("March2017Eta1295MCNormT0to1.root","RECREATE");
  //TFile *f = new TFile("March2017BasicNoOmegaMassCorrNormalisation.root","RECREATE");
  TFile *f = new TFile("Aug2017NormSig60SB30Gap30.root","RECREATE");

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
  // TFile *myFile = TFile::Open("May2017ErrorBase180Bins.root");
  TFile *myFile = TFile::Open("Aug2017Sig60SB30Gap30.root");

 //TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted Mass Omega vs Mass X;Mass #omega (GeV);MassX (GeV)",100,0.69,0.88,100,1.1,1.9);
 
 
 //Slice 7 fitting polymial to determine the background in the signal region.
 Double_t par7[7];
 TH1F *slice_histo7;
 TF1 *s7g2    = new TF1("s7g2","gaus",0.765,0.80);
 TF1 *s7g1    = new TF1("s7g1","pol3",0.85,0.87);
 TF1 *total7 = new TF1("total7","pol3(0)",0.692,0.872);
 total7->SetLineColor(3);
 
 slice_histo7 = MmissSide_All;

 //slice_histo7 = MOmvsMXSide1_All->ProjectionX("Slice7 Fit",1,20);
 //slice_histo7 = MOmvsMXSide2_All->ProjectionX("Slice7 Fit",21,30);
 //slice_histo7 = MOmvsMXSide3_All->ProjectionX("Slice7 Fit",31,40);
 //slice_histo7 = MOmvsMXSide4_All->ProjectionX("Slice7 Fit",41,50);
 //slice_histo7 = MOmvsMXSide5_All->ProjectionX("Slice7 Fit",51,60);
 //slice_histo7 = MOmvsMXSide6_All->ProjectionX("Slice7 Fit",61,70);
 //slice_histo7 = MOmvsMXSide7_All->ProjectionX("Slice7 Fit",71,80);
 //slice_histo7 = MOmvsMXSide8_All->ProjectionX("Slice7 Fit",81,100);


 slice_histo7->Fit(s7g1,"R");
 slice_histo7->Fit(s7g2,"R+");
 s7g1->GetParameters(&par7[0]);
 s7g2->GetParameters(&par7[4]);
 total7->SetParameters(par7);
 slice_histo7->Fit(total7,"R+");
 slice_histo7->Draw();
 slice_histo7->SetDirectory(f);

 Double_t IntegralLeft=total7->Integral(0.692, 0.722);
 Double_t IntegralMiddle=total7->Integral(0.752, 0.812);
 Double_t IntegralRight=total7->Integral(0.842, 0.872);
 Double_t IntegralTotal=total7->Integral(0.692, 0.872);

 cout << "Integral of Left Events " << IntegralLeft << endl;
 cout << "Integral of Middle Events " << IntegralMiddle << endl;
 cout << "Integral of Right Events " << IntegralRight << endl;
 cout << "Integral of Total Events " << IntegralTotal << endl;

 //MOmvsMXAll_All_0->SetDirectory(f);
 //MOmvsMXAll_All_1->SetDirectory(f);
 //MOmvsMXAll_All_2->SetDirectory(f);
 //MOmvsMXAll_All_3->SetDirectory(f);
 //MOmvsMXAll_All_4->SetDirectory(f);
 //MOmvsMXAll_All_5->SetDirectory(f);
 
 f->Write();
 
  }


