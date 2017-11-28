#include <TH2.h>
#include <TF1.h>

void SBSliceScript() {

 TFile *f = new TFile("Dec2016SBSliceTest1.root","RECREATE");

 //TFile *myFile = TFile::Open("Dec2016TestRun4.root");
 TFile *myFile = TFile::Open("Dec2016TestRun10Bins.root");

 TH2F *MassOmegavsMassXSB = new TH2F("MassOmegavsMassXSB", "Sideband subtracted Mass Omega vs Mass X;Mass #omega (GeV);MassX (GeV)",100,0.69,0.88,100,1.1,1.9);
 
 
 MOmvsMXAll_All->Draw("COLZ");

 TF1 *f1 = new TF1("f1","gaus",0.76,0.81);
 TF1 *f2 = new TF1("f2","pol2",0.7,0.88);

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

 int numbin = 10;
 for (i=0; i<numbin; i++) {
   sprintf(name_histo,"slice_%i",i);
   slice_histo[i] =  MOmvsMXAll_All->ProjectionX(name_histo,i,(i+1));
 }



 Double_t par[5];
 TF1 *g2    = new TF1("g2","gaus",0.76,0.80);
 TF1 *g1    = new TF1("g1","pol1",0.82,0.87);
 TF1 *total = new TF1("total","pol1(0)+gaus(2)",0.7,0.88);
 total->SetLineColor(3);
 px->Fit(g1,"R");
 px->Fit(g2,"R+");
 g1->GetParameters(&par[0]);
 g2->GetParameters(&par[2]);
 total->SetParameters(par);
 px->Fit(total,"R+");
 
 cout << "---------------------------------------------------------" << endl ;
 cout << "---------------------------------------------------------" << endl ;
 cout << "Fitting Result for Histogram "<< px->GetName() << endl;
 cout << "---------------------------------------------------------" << endl ;
 cout << "Polynomial [0] + [1] x + [2] x^2" << endl;
 cout << "[0] =" << total->GetParameter(0);
 cout << "[1] =" << total->GetParameter(1);
 cout << "Gaussian [0] * exp( (x-[1])/ (2[2]^2) )" << endl;
 cout << "[0] =" << total->GetParameter(2);
 cout << "[1] =" << total->GetParameter(3);
 cout << "[2] =" << total->GetParameter(4);
 cout << "---------------------------------------------------------" << endl ;
 cout << "---------------------------------------------------------" << endl ;
 cout << "" <<	endl;

 px->Draw();


 MOmvsMXAll_All->FitSlicesX(total,1,10,0,"QNR");
 
 //MassOmegavsMassXSB->SetDirectory(f);

 MOmvsMXAll_All_0->SetDirectory(f);
 MOmvsMXAll_All_1->SetDirectory(f);
 MOmvsMXAll_All_2->SetDirectory(f);
 MOmvsMXAll_All_3->SetDirectory(f);
 MOmvsMXAll_All_4->SetDirectory(f);
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
