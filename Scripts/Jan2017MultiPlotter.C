#include <TH2.h>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf
void Jan2017MultiPlotter(){
  
  //TFile *f = new TFile("40binLPSPlots1.root","RECREATE");
  
  TFile *f = new TFile("SidebandMassXDeltaCuts.root","RECREATE");

  // TFile *myFile = TFile::Open("/phys/linux/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/sWeights/sWPlotting/sWPlots/testLPS4bin30.root");
  // TFile *myFile = TFile::Open("/phys/linux/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/sWeights/sWPlotting/sWPlots/testLPSContracted2.root");
  
  
  TCanvas *c1 = new TCanvas("c1","MassX For Different Sideband Cuts",900,700);
  gStyle->SetOptStat(0);
  TCanvas *c2 = new TCanvas("c2","MassPiPProton for Different #Delta Cuts",900,700);
  gStyle->SetOptStat(0);
  TCanvas *c3 = new TCanvas("c3","MassPiMProton for Different #Delta Cuts",900,700);
  gStyle->SetOptStat(0);
 
  //c1->Divide(2,2,0,0);
  c1->Divide(3,2);
  // c2->Divide(2,2);
  // c3->Divide(2,2);
  // TH2F *h1 = new TH2F("h1","test1",10,0,1,20,0,20);
  // TH2F *h2 = new TH2F("h2","test2",10,0,1,20,0,100);
  // TH2F *h3 = new TH2F("h3","test3",10,0,1,20,-1,1);
  // TH2F *h4 = new TH2F("h4","test4",10,0,1,20,0,1000);

  //TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/Jan2017BinnedMassXSubtractionsDeltas2.root");
  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/LeftandRightSubPrecHalfSBLandRComp2.root");

  c1->cd(1);
  MassXSB->Draw();
  c1->cd(2);
  MassXLeftSubSB->Draw();
  c1->cd(3);
  MassXRightSubSB->Draw();
  c1->cd(4);
  MassXSBLR->Draw();
  c1->cd(5);
  MassXLeftSubSignalSB->Draw();

  TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB5A2Decays1milSubtraction1.root");

  c1->cd(6);
  MassXSB->Draw();



  // TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/Jan2017BinnedMassXSubtractionsDeltas3.root");

  // c1->cd(2);
  // MassXSB->Draw();
  // c2->cd(2);
  // MassPiPPro->Draw();
  // c3->cd(2);
  // MassPiMPro->Draw();


  // TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/Jan2017BinnedMassXSubtractionsDeltas4.root");

  // c1->cd(3);
  // MassXSB->Draw();
  // c2->cd(3);
  // MassPiPPro->Draw();
  // c3->cd(3);
  // MassPiMPro->Draw();

  // TFile *myFile = TFile::Open("/home/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/Jan2017BinnedMassXSubtractionsDeltas5.root");

  // c1->cd(4);
  // MassXSB->Draw();
  // c2->cd(4);
  // MassPiPPro->Draw();
  // c3->cd(4);
  // MassPiMPro->Draw();



  // for(int i=0;i<14;i++){
  // std::stringstream ss;
  // ss<<"MXSignalSector"<<i<<".00_";
  // std::string s = ss.str();
    
  // c1->cd(i+1);
  // ((TH1F*)(gDirectory->Get(s.c_str())))->Draw();
  // ss.str  ("");
  // }


// TCanvas *c2 = new TCanvas("c2","OmegaPiP Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c2->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MOPiPSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c2->cd(i+1);
//   ((TH1F*)(gDirectory->Get(s.c_str())))->Draw();
//   ss.str  ("");
//   }

// TCanvas *c3 = new TCanvas("c3","OmegaPiM Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c3->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MOPiMSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c3->cd(i+1);
//   ((TH1F*)(gDirectory->Get(s.c_str())))->Draw();
//   ss.str  ("");
//   }

// TCanvas *c4 = new TCanvas("c4","PiPProton Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c4->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MPiPProtonSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c4->cd(i+1);
//   ((TH1F*)(gDirectory->Get(s.c_str())))->Draw();
//   ss.str  ("");
//   }

//   TCanvas *c5 = new TCanvas("c5","PiMProton Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c5->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MPiPProtonSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c5->cd(i+1);
//   ((TH1F*)(gDirectory->Get(s.c_str())))->Draw();
//   ss.str  ("");
//   }

//  TCanvas *c6 = new TCanvas("c6","OPiPvsMassX Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c6->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MOPipVMXSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c6->cd(i+1);
//   ((TH2F*)(gDirectory->Get(s.c_str())))->Draw("colz");
//   ss.str  ("");
//   }

// TCanvas *c7 = new TCanvas("c7","OPiMvsMassX Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c7->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MOPimVMXSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c7->cd(i+1);
//   ((TH2F*)(gDirectory->Get(s.c_str())))->Draw("colz");
//   ss.str  ("");
//   }

//   TCanvas *c8 = new TCanvas("c8","PiPProtonvsMassX Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c8->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MPiPProtonVMXSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c8->cd(i+1);
//   ((TH2F*)(gDirectory->Get(s.c_str())))->Draw("colz");
//   ss.str  ("");
//   }

//   TCanvas *c9 = new TCanvas("c9","PiMProtonvsMassX Sectors",900,700);
//   gStyle->SetOptStat(0);
//   c9->Divide(4,4);

//   for(int i=0;i<14;i++){
//   std::stringstream ss;
//   ss<<"MPiMProtonVMXSignalSector"<<i<<".00_";
//   std::string s = ss.str();
    
//   c9->cd(i+1);
//   ((TH2F*)(gDirectory->Get(s.c_str())))->Draw("colz");
//   ss.str  ("");
//   }

  // c1->cd(1);
  // // gPad->SetTickx(2);
  // ((TH1F*)(gDirectory->Get("MXSignalSector0.00_")))->Draw();
  
  // c1->cd(2);
  // // gPad->SetTickx(2);
  // // gPad->SetTicky(2);
  // //h2->GetYaxis()->SetLabelOffset(0.01);
  // //MXSignalSector1.00_->Draw();
  // ((TH1F*)(gDirectory->Get("MXSignalSector1.00_")))->Draw();
    
    
  // c1->cd(3);
  // ((TH1F*)(gDirectory->Get("MXSignalSector2.00_")))->Draw();
   
 
  // // h3->Draw();
  
  // c1->cd(4);
  // ((TH1F*)(gDirectory->Get("MXSignalSector3.00_")))->Draw();
  // // gPad->SetTicky(2);


  


}
