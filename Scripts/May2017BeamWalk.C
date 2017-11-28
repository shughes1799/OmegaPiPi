// #define May2017BeamWalk_cxx

// #include "May2017BeamWalk.h"
// #include <TH2.h>
// #include <TStyle.h>
// #include <iostream>
// using namespace std;

// May2017BeamWalk::~May2017BeamWalk(){


{

  TFile *f = new TFile("BeamWalkTest.root","RECREATE");
  
  // TFile *myFile = TFile::Open("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun001.root");
  
  //double totE;
  //unsigned int pixel;//  <----   !!!!
  //TCanvas *c1= new TCanvas ("c1","c1",800,800);
  //gPad->Divide(0,2);
 
  
  // TH1F* Acceptance_Left = new TH1F("Acceptance_Left", "Acceptance Left Title",180,1.1,1.9); 
  //TH1F* Acceptance_Signal = new TH1F("Acceptance_Signal", "Acceptance Signal Title",180,1.1,1.9);
  //TH1F* Acceptance_Right = new TH1F("Acceptance_Right", "Acceptance Right Title",180,1.1,1.9);

  TH1F* EgammaHist = new TH1F("EgammaHist", "Egamma",100,0,4); 

  //double_t Egamma;
  
  
  // TFile *myfile= new TFile("pixels.root","READ");
  TFile *myfile= new TFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun001.root","READ");
  // Ttree *tree= (Ttree* myfile)->Get("tree");
  TTree *tree= (TTree*)myfile->Get("h10");
  
  //tree->SetBranchAddress("totE",&totE);
  //tree->SetBranchAddress("pixel",&pixel);
  
  h10->SetBranchAddress("Egamma",&E_gamma);
  //tree->SetBranchAddress("pixel",&pixel);
  
    
  
  
  entries= tree->GetEntries();
  for (int i=0; i<entries; i++)
    {
      tree->GetEntry(i);//            <-----     !!!!!!!!!!!!!
      EgammaHist->Fill(Egamma);
      //  h1->Fil(totE);
    }
  
  EgammaHist->Draw();
  EgammaHist->SetDirectory(f);
 
  
  
  f->Write();
 
}
