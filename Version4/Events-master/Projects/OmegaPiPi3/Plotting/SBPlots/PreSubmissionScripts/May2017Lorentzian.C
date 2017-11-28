
Double_t fitf(Double_t *x, Double_t *par)
{

  //Lorentzian
  // Double_t fitval = par[2]*(    (par[1]*par[1])/ (     ((x-par[0])*(x-par[0])) + (par[1]*par[1])    )        );
  // Double_t fitval = par[2]*(par[1]**2 / ((x-par[0])**2 + par[1]**2));
  // Double_t fitval = par[2]*(pow(par[1],2) / (pow((x[0]-par[0]),2) + pow(par[1],2)));

   //Gaussian
  // Double_t fitval = par[0]*TMath::Exp(-0.5*((x-par[1])/par[2])**2     );

   //Polynomial
  
  Double_t fitval = 0; 
  //fitval = par[0]+(par[1]*x[0])+par[2]*pow(x[0],2);

  //Polynomial + Lorentz
  // fitval = par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+(par[3]*(pow(0.105,2) / (pow((x[0]-1.318),2) + pow(0.105,2)))) ;

  //Background Pol
  //fitval = (433./8000)*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4));


  //Lower Range Value
  fitval = (36./936)*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4));
  //fitval = fitval*(433/8000);
  // fitval = (par[0]*(433/8000)+(par[1]*x[0]*(433/8000))+par[2]*pow(x[0],2)*(433/8000)+par[3]*pow(x[0],3)*(433/8000)+par[4]*pow(x[0],4)*(433/8000));

  
   return fitval;
}

Double_t fitf2(Double_t *x, Double_t *par)
{
  
  Double_t fitval2 = 0; 
 
  //Higher Range Value
  fitval2 = (32./936)*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4));

  
   return fitval2;
}

Double_t fitfBW(Double_t *x, Double_t *par)
{
  
  Double_t fitvalBW = 0; 
 
  //Higher Range Value
  // fitvalBW = (43.5/936)*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4));

  Double_t m = 1.318;
  Double_t w = 0.107;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW = (par[5])*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4))+(par[6])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2))));

  // (k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2))));
  
   return fitvalBW;
}

//Plots the A2 breit wignar.
Double_t fitfBW2(Double_t *x, Double_t *par)
{
  
  Double_t fitvalBW2 = 0; 
 
  //Higher Range Value
  // fitvalBW = (43.5/936)*(par[0]+(par[1]*x[0])+par[2]*pow(x[0],2)+par[3]*pow(x[0],3)+par[4]*pow(x[0],4));

  Double_t m = 1.318;
  Double_t w = 0.107;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW2 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2))));

  // (k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2))));
  
   return fitvalBW2;
}

//Plots the pi2(1670)
Double_t fitfBW3(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW3 = 0; 
  Double_t m = 1.672.2;
  Double_t w = 0.260;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW3 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW3;
}

//Plots the a0(1450)
Double_t fitfBW4(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW4 = 0; 
  Double_t m = 1.474;
  Double_t w = 0.265;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW4 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW4;
}

//Plots the omega(1670)
Double_t fitfBW5(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW5 = 0; 
  Double_t m = 1.667;
  Double_t w = 0.168;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW5 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW5;
}
//Plots the omega(1420)
Double_t fitfBW6(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW6 = 0; 
  Double_t m = 1.425;
  Double_t w = 0.225;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW6 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW6;
}
//Plots the pi1(1600)
Double_t fitfBW7(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW7 = 0; 
  Double_t m = 1.662;
  Double_t w = 0.241;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW7 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW7;
}
//Plots the omega(1650)
Double_t fitfBW8(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW8 = 0; 
  Double_t m = 1.670;
  Double_t w = 0.315;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW8 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW8;
}
//Plots the Phi(1680)
Double_t fitfBW9(Double_t *x, Double_t *par)
{  
  Double_t fitvalBW9 = 0; 
  Double_t m = 1.680;
  Double_t w = 0.150;
  Double_t gamma = TMath::Sqrt(pow(m,2)*(pow(m,2)+pow(w,2)));
  Double_t k = (2*TMath::Sqrt(2)*m*w*gamma)/(TMath::Pi()*TMath::Sqrt(pow(m,2)+gamma)) ;

  fitvalBW9 = (par[0])*(k/(pow((pow(x[0],2)-pow(m,2)),2) + (pow(m,2)*pow(w,2)))); 
  return fitvalBW9;
}



void May2017Lorentzian()
{
  TFile *f = new TFile("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/May2017/May2017Basic5BinsMassXVersionB1Stuff180Bins.root");
  //TFile *f = new TFile("May2017ErrorBase180BinsSubtractedAdjNorm.root");
   
   //TCanvas *c1 = new TCanvas("c1","the fit canvas",500,400);

   //   TH1F *hpx = (TH1F*)f->Get("hpx");
  TH1F *hpx = (TH1F*)f->Get("MXSignal_All");
  TH1F *hpx2 = (TH1F*)f->Get("MXBG_All");
  //  TH1F *hpx = (TH1F*)f->Get("MassXSB");
  // TH1F *hpx = (TH1F*)f->Get("MXBG_All");

// Creates a Root function based on function fitf above
   TF1 *bg    = new TF1("bg","pol4",1.15,1.45);
   //TF1 *bg    = new TF1("bg","pol4",1.12,1.25);
   TF1 *s1g1    = new TF1("s1g1","pol2",1.12,1.22);
   //TF1 *s1g2    = new TF1("s1g2","gaus",1.255,1.315);
   // TF1 *func = new TF1("fitf",fitf,-2,2,3);
   TF1 *func = new TF1("fitf",fitf,1.15,1.45,5);   //Current sWeights values
   TF1 *func2 = new TF1("fitf2",fitf2,1.15,1.45,5);   //Current sWeights values
   TF1 *func3 = new TF1("fitfBW",fitfBW,1.15,1.285,7);   //Pol + BW
   TF1 *func4 = new TF1("fitfBW2",fitfBW2,1.2,1.436,1);   //BW 1320
   TF1 *func5 = new TF1("fitfBW3",fitfBW3,1.5,1.85,1);   //BW 1670
   TF1 *func6 = new TF1("fitfBW4",fitfBW4,1.3,1.65,1);   //BW 1450
   TF1 *func7 = new TF1("fitfBW5",fitfBW5,1.5,1.85,1);   //BW 1670
   TF1 *func8 = new TF1("fitfBW6",fitfBW6,1.25,1.6,1);   //BW 1420
   TF1 *func9 = new TF1("fitfBW7",fitfBW7,1.5,1.85,1);   //BW 1600
   TF1 *func10 = new TF1("fitfBW8",fitfBW8,1.5,1.85,1);   //BW 1650
   TF1 *func11 = new TF1("fitfBW9",fitfBW9,1.5,1.85,1);   //BW 1680

   //TF1 *func = new TF1("fitf",fitf,1.15,1.28,4);   //Current Sideband values
   
   // Sets initial values and parameter names

   //polynomial
   //func->SetParameters(66946.9,-118464,52427);

   //pol + lorentz
   //func->SetParameters(66946.9,-118464,52427,10000);

   //for 1.15 to 1.45 fit to sweights bg  
   //func->SetParameters(3.54076e07,-1.06426e08,1.18985e08,-5.86603e07,1.07724e07);  //version 1
   func->SetParameters(3.54076e07,-1.06426e08,1.18985e08,-5.86603e07,1.07724e07);  //version 2

   func2->SetParameters(3.54076e07,-1.06426e08,1.18985e08,-5.86603e07,1.07724e07);  //version 2

   func3->SetParameters(3.54076e07,-1.06426e08,1.18985e08,-5.86603e07,1.07724e07,(37.5/936),100);

   func4->SetParameter(0,150);
   func5->SetParameter(0,150);
   func6->SetParameter(0,150);
   func7->SetParameter(0,150);
   func8->SetParameter(0,150);
   func9->SetParameter(0,150);
   func10->SetParameter(0,150);
   func11->SetParameter(0,150);

   //Set Line Colors
   func4->SetLineColor(8);
   func5->SetLineColor(1);
   func6->SetLineColor(2);
   func7->SetLineColor(3);
   func8->SetLineColor(4);
   func9->SetLineColor(5);
   func10->SetLineColor(6);
   func11->SetLineColor(7);
 






   //TestParam
   // func->SetParameters(3.54070e+07,-1.06426e+08, 1.18984e+08,-5.86603e+07,1.07713e+07);


   //func->SetParameters(1.318,0.105,1000);
   //func->SetParameters(1.28,0.04,1200);

   //Fixing function parameters
   func3->SetParLimits(0,3.54076e07,3.54076e07);
   func3->SetParLimits(1,-1.06426e08,-1.06426e08);
   func3->SetParLimits(2,1.18985e08,1.18985e08);
   func3->SetParLimits(3,-5.86603e07,-5.86603e07);
   func3->SetParLimits(4,1.07724e07,1.07724e07);
   func3->SetParLimits(5,(32./936),(36./936));
   


   //Gaus usermade function;
   //func->SetParameters(1800,1.29,0.026);

   //func->SetParNames("Constant","Mean_value","Sigma");
   //func->SetParNames("Mass","Width","Height");
   func->SetParNames("Constant","x","x2","Height");

   cout << "Test " << endl;

   TH1::Sumw2;
// Fit histogram in range defined by function
   // hpx->Fit("s1g1","r");
   //hpx->Fit("bg","r");
   //hpx->Draw();
   //hpx2->Scale(0.054125);  
   hpx->Fit("fitfBW","r");

   //func->Draw("same");
   // func2->Draw("same");
   func4->Draw("same");
   func5->Draw("same");
   func6->Draw("same");
   func7->Draw("same");
   func8->Draw("same");
   func9->Draw("same");
   func10->Draw("same");
   func11->Draw("same");

   // hpx2->Draw("same");
   // hpx2->Fit("bg","r");
    //func->Draw();
   //hpx->Fit("fitf","r");
   //hpx->Fit("s1g2","r");
   Double_t IntegralError;
   Double_t IntegralGaus=func4->Integral(1.15, 1.45);
  
   Double_t IntegralGaus2;
   //  IntegralError = func4->IntegralError(1.15,1.45);

  

   cout << "Integral of Total Events " << IntegralGaus/0.004444 << endl;
//   cout << "Integral of Total Events 2" << IntegralGaus2 << endl;
   //  cout << "Integral Error of Total Events" << IntegralError << endl;

// Gets integral of function between fit limits
   // printf("Integral of function = %g\n",func->Integral(-2,2));
}
