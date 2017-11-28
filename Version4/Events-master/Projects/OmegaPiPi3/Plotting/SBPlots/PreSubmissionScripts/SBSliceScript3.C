
{

 TFile *f = new TFile("Dec2016SBSliceA2Region2.root","RECREATE");

 TFile *myFile = TFile::Open("Dec2016TestRun4.root");
 //TFile *myFile = TFile::Open("Dec2016TestRun10Bins.root");

 //TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted Mass Omega vs Mass X;Mass #omega (GeV);MassX (GeV)",100,0.69,0.88,100,1.1,1.9);
 
 
 MOmvsMXAll_All->SetDirectory(f);

 TF1 *f1 = new TF1("f1","gaus",0.765,0.81);
 TF1 *f2 = new TF1("f2","pol3",0.7,0.88);

 TF1 *comb = new TF1("comb","gaus(0)+pol3(3)",0.7,0.88);

 //TObjArray aSlices;
 //MOmvsMXAll_All->FitSlicesX(comb,1,100,0,"QNR");

 //MOmvsMXAll_All_1->Draw();

 // MOmvsMXAll_All->ProjectionX("px",40,50);
 //MOmvsMXAll_All->ProjectionX("px",40,70)



 // px->Fit(f1,"R");
 // px->Fit(f2,"R+");

 // f3->SetParameter(0,17000);
 // f3->SetParameter(1,0.78);
 // f3->SetParameter(2,0.01);
 // f3->SetParameter(3,-136179);
 // f3->SetParameter(4,427599);
 // f3->SetParameter(5,-300274);

 //px->Fit(f1,"R");
 //px->Fit(f2,"R+");


 //px->Fit(comb,"R");
 //px->gStyle->SetOptFit(1111);




 // Lorenzo Fitting Code
    
 MOmvsMXAll_All->ProjectionX("px",5,6);
 TH1D *slice_histo[100];

 char name_histo[100];

Double_t par[7];
 TF1 *g2    = new TF1("g2","gaus",0.765,0.80);
 TF1 *g1    = new TF1("g1","pol1",0.82,0.87);
 //TF1 *g1    = new TF1("g1","pol2",0.82,0.87);
 //TF1 *g1    = new TF1("g1","pol3",0.7,0.87);

 TF1 *total = new TF1("total","pol1(0)+gaus(2)",0.7,0.88);
 //TF1 *total = new TF1("total","pol2(0)+gaus(3)",0.7,0.88);
 // TF1 *total = new TF1("total","pol3(0)+gaus(4)",0.7,0.88);
 total->SetLineColor(3);



//  int numbin = 10;
//  for (i=0; i<numbin; i++) {
//    sprintf(name_histo,"slice_%i",i);
//    slice_histo[i] =  MOmvsMXAll_All->ProjectionX(name_histo,i,(i+1));

//    slice_histo[i]->Fit(g1,"R");
//    slice_histo[i]->Fit(g2,"R+");
//    g1->GetParameters(&par[0]);
//    g2->GetParameters(&par[2]);
//    total->SetParameters(par);
//    slice_histo[i]->Fit(total,"R+");

//    slice_histo[i]->Draw();

//    slice_histo[i]->SetDirectory(f);
// }

 ///////////////////////////////////////////////////////////////////////////////////////////////////////
 //Fitting for individual bins
 //10 Bins

 //Slice 1
 Double_t par1[7];
 TH1D *slice_histo1;
 TF1 *s1g2    = new TF1("s1g2","gaus",0.765,0.80);
 TF1 *s1g1    = new TF1("s1g1","pol1",0.82,0.87);
 TF1 *total1 = new TF1("total1","pol1(0)+gaus(2)",0.7,0.88);
 total1->SetLineColor(3);

 slice_histo1 = MOmvsMXAll_All->ProjectionX("Slice Fit",18,21);
 
 slice_histo1->Fit(s1g1,"R");
 slice_histo1->Fit(s1g2,"R+");
 s1g1->GetParameters(&par1[0]);
 s1g2->GetParameters(&par1[2]);
 total1->SetParameters(par1);
 slice_histo1->Fit(total1,"R+");
 slice_histo1->Draw();
 slice_histo1->SetDirectory(f);

 //Slice 2
 Double_t par2[7];
 TH1D *slice_histo2;
 TF1 *s2g2    = new TF1("s2g2","gaus",0.765,0.80);
 TF1 *s2g1    = new TF1("s2g1","pol1",0.82,0.84);
 TF1 *total2 = new TF1("total2","pol1(0)+gaus(2)",0.7,0.88);
 total2->SetLineColor(3);

 slice_histo2 = MOmvsMXAll_All->ProjectionX("Slice2 Fit",22,25);
 
 slice_histo2->Fit(s2g1,"R");
 slice_histo2->Fit(s2g2,"R+");
 s2g1->GetParameters(&par2[0]);
 s2g2->GetParameters(&par2[2]);
 total2->SetParameters(par2);
 slice_histo2->Fit(total2,"R+");
 slice_histo2->Draw();
 slice_histo2->SetDirectory(f);

 //Slice 3
 Double_t par3[7];
 TH1D *slice_histo3;
 TF1 *s3g2    = new TF1("s3g2","gaus",0.765,0.80);
 TF1 *s3g1    = new TF1("s3g1","pol1",0.82,0.87);
 TF1 *total3 = new TF1("total3","pol1(0)+gaus(2)",0.7,0.88);
 total3->SetLineColor(3);
 
 slice_histo3 = MOmvsMXAll_All->ProjectionX("Slice3 Fit",26,29);
 
 slice_histo3->Fit(s3g1,"R");
 slice_histo3->Fit(s3g2,"R+");
 s3g1->GetParameters(&par3[0]);
 s3g2->GetParameters(&par3[2]);
 total3->SetParameters(par3);
 slice_histo3->Fit(total3,"R+");
 slice_histo3->Draw();
 slice_histo3->SetDirectory(f);

 //Slice 4
 Double_t par4[7];
 TH1D *slice_histo4;
 TF1 *s4g2    = new TF1("s4g2","gaus",0.765,0.80);
 TF1 *s4g1    = new TF1("s4g1","pol1",0.82,0.87);
 TF1 *total4 = new TF1("total4","pol1(0)+gaus(2)",0.7,0.88);
 total4->SetLineColor(3);
 
 slice_histo4 = MOmvsMXAll_All->ProjectionX("Slice4 Fit",30,33);
 
 slice_histo4->Fit(s4g1,"R");
 slice_histo4->Fit(s4g2,"R+");
 s4g1->GetParameters(&par4[0]);
 s4g2->GetParameters(&par4[2]);
 total4->SetParameters(par4);
 slice_histo4->Fit(total4,"R+");
 slice_histo4->Draw();
 slice_histo4->SetDirectory(f);

 //Slice 5
 Double_t par5[7];
 TH1D *slice_histo5;
 TF1 *s5g2    = new TF1("s5g2","gaus",0.765,0.80);
 TF1 *s5g1    = new TF1("s5g1","pol1",0.82,0.87);
 TF1 *total5 = new TF1("total5","pol1(0)+gaus(2)",0.7,0.88);
 total5->SetLineColor(3);
 
 slice_histo5 = MOmvsMXAll_All->ProjectionX("Slice5 Fit",34,37);
 
 slice_histo5->Fit(s5g1,"R");
 slice_histo5->Fit(s5g2,"R+");
 s5g1->GetParameters(&par5[0]);
 s5g2->GetParameters(&par5[2]);
 total5->SetParameters(par5);
 slice_histo5->Fit(total5,"R+");
 slice_histo5->Draw();
 slice_histo5->SetDirectory(f);

 // //Slice 6
 // Double_t par6[7];
 // TH1D *slice_histo6;
 // TF1 *s6g2    = new TF1("s6g2","gaus",0.765,0.80);
 // TF1 *s6g1    = new TF1("s6g1","pol1",0.82,0.87);
 // TF1 *total6 = new TF1("total6","pol1(0)+gaus(2)",0.7,0.88);
 // total6->SetLineColor(3);
 
 // slice_histo6 = MOmvsMXAll_All->ProjectionX("Slice6 Fit",5,6);
 
 // slice_histo6->Fit(s6g1,"R");
 // slice_histo6->Fit(s6g2,"R+");
 // s6g1->GetParameters(&par6[0]);
 // s6g2->GetParameters(&par6[2]);
 // total6->SetParameters(par6);
 // slice_histo6->Fit(total6,"R+");
 // slice_histo6->Draw();
 // slice_histo6->SetDirectory(f);

 // //Slice 7
 // Double_t par7[7];
 // TH1D *slice_histo7;
 // TF1 *s7g2    = new TF1("s7g2","gaus",0.765,0.80);
 // TF1 *s7g1    = new TF1("s7g1","pol1",0.82,0.87);
 // TF1 *total7 = new TF1("total7","pol1(0)+gaus(2)",0.7,0.88);
 // total7->SetLineColor(3);
 
 // slice_histo7 = MOmvsMXAll_All->ProjectionX("Slice7 Fit",6,7);
 
 // slice_histo7->Fit(s7g1,"R");
 // slice_histo7->Fit(s7g2,"R+");
 // s7g1->GetParameters(&par7[0]);
 // s7g2->GetParameters(&par7[2]);
 // total7->SetParameters(par7);
 // slice_histo7->Fit(total7,"R+");
 // slice_histo7->Draw();
 // slice_histo7->SetDirectory(f);

 // //Slice 8
 // Double_t par8[7];
 // TH1D *slice_histo8;
 // TF1 *s8g2    = new TF1("s8g2","gaus",0.765,0.80);
 // TF1 *s8g1    = new TF1("s8g1","pol1",0.82,0.87);
 // TF1 *total8 = new TF1("total8","pol1(0)+gaus(2)",0.7,0.88);
 // total8->SetLineColor(3);
 
 // slice_histo8 = MOmvsMXAll_All->ProjectionX("Slice8 Fit",7,8);
 
 // slice_histo8->Fit(s8g1,"R");
 // slice_histo8->Fit(s8g2,"R+");
 // s8g1->GetParameters(&par8[0]);
 // s8g2->GetParameters(&par8[2]);
 // total8->SetParameters(par8);
 // slice_histo8->Fit(total8,"R+");
 // slice_histo8->Draw();
 // slice_histo8->SetDirectory(f);

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


// /////////////////////////////Make Model Signal
// // RF->Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
// RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.782,0.75,0.8], SIMw[0.01,0.001,0.08] )");
// RF->LoadSpeciesPDF("Signal");

// ////////////////////////////////Additional background
// // RF->Factory("Chebychev::BG(Mmiss,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
// RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1],a2[0.015,-1,1]})");
// RF->LoadSpeciesPDF("BG");
