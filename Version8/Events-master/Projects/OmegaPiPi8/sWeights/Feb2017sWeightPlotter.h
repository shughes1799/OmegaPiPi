//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 31 15:04:37 2017 by ROOT version 5.34/34
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root
//////////////////////////////////////////////////////////

#ifndef Feb2017sWeightPlotter_h
#define Feb2017sWeightPlotter_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"
#include "THSWeights.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Feb2017sWeightPlotter : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Double_t        Mmiss;
   Double_t        Egamma;
   Double_t        MassProton;
   Double_t        MassPiP;
   Double_t        MassPiM;
   Double_t        MassOmega;
   Double_t        MassOmegaPiP;
   Double_t        MassOmegaPiM;
   Double_t        MassX;
   Double_t        PhiX;
   Double_t        ThetaX;
   Double_t        MassPiPPiM;
   Double_t        t;
   Double_t        s;
   Double_t        MassOmegaProton;
   Double_t        MassPiPProton;
   Double_t        MassPiMProton;
   Double_t        MassPiPPiMProton;
   Double_t        fgID;
   
   Double_t        Mass2Proton;
   Double_t        Mass2PiP;
   Double_t        Mass2PiM;
   Double_t        Mass2Omega;
   Double_t        Mass2OmegaPiP;
   Double_t        Mass2OmegaPiM;
   Double_t        Mass2X;


   //Data members for reading sWeights
   THSWeights* fWeights;
   // List of branches
   TBranch        *b_Mmiss;   //!
   TBranch        *b_Egamma;   //!
   TBranch        *b_MassProton;   //!
   TBranch        *b_MassPiP;   //!
   TBranch        *b_MassPiM;   //!
   TBranch        *b_MassOmega;   //!
   TBranch        *b_MassOmegaPiP;   //!
   TBranch        *b_MassOmegaPiM;   //!
   TBranch        *b_MassX;   //!
   TBranch        *b_PhiX;   //!
   TBranch        *b_ThetaX;   //!
   TBranch        *b_MassPiPPiM;   //!
   TBranch        *b_t;   //!
   TBranch        *b_s;   //!
   TBranch        *b_MassOmegaProton;   //!
   TBranch        *b_MassPiPProton;   //!
   TBranch        *b_MassPiMProton;   //!
   TBranch        *b_MassPiPPiMProton;   //!
   TBranch        *b_fgID;   //!

   TBranch        *b_Mass2Proton;   //!
   TBranch        *b_Mass2PiP;   //!
   TBranch        *b_Mass2PiM;   //!
   TBranch        *b_Mass2Omega;   //!
   TBranch        *b_Mass2OmegaPiP;   //!
   TBranch        *b_Mass2OmegaPiM;   //!
   TBranch        *b_Mass2X;   //!

   Feb2017sWeightPlotter(TTree * /*tree*/ =0) : fChain(0),fWeights(0) { }
   virtual ~Feb2017sWeightPlotter() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();
//Add THSHisto functions
   virtual void HistogramList(TString sLabel);
   virtual void FillHistograms(TString sCut,Int_t bin);

   ClassDef(Feb2017sWeightPlotter,0);
};

#endif

#ifdef Feb2017sWeightPlotter_cxx
void Feb2017sWeightPlotter::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("Mmiss", &Mmiss, &b_Mmiss);
   fChain->SetBranchAddress("Egamma", &Egamma, &b_Egamma);
   fChain->SetBranchAddress("MassProton", &MassProton, &b_MassProton);
   fChain->SetBranchAddress("MassPiP", &MassPiP, &b_MassPiP);
   fChain->SetBranchAddress("MassPiM", &MassPiM, &b_MassPiM);
   fChain->SetBranchAddress("MassOmega", &MassOmega, &b_MassOmega);
   fChain->SetBranchAddress("MassOmegaPiP", &MassOmegaPiP, &b_MassOmegaPiP);
   fChain->SetBranchAddress("MassOmegaPiM", &MassOmegaPiM, &b_MassOmegaPiM);
   fChain->SetBranchAddress("MassX", &MassX, &b_MassX);
   fChain->SetBranchAddress("PhiX", &PhiX, &b_PhiX);
   fChain->SetBranchAddress("ThetaX", &ThetaX, &b_ThetaX);
   fChain->SetBranchAddress("MassPiPPiM", &MassPiPPiM, &b_MassPiPPiM);
   fChain->SetBranchAddress("t", &t, &b_t);
   fChain->SetBranchAddress("s", &s, &b_s);
   fChain->SetBranchAddress("MassOmegaProton", &MassOmegaProton, &b_MassOmegaProton);
   fChain->SetBranchAddress("MassPiPProton", &MassPiPProton, &b_MassPiPProton);
   fChain->SetBranchAddress("MassPiMProton", &MassPiMProton, &b_MassPiMProton);
   fChain->SetBranchAddress("MassPiPPiMProton", &MassPiPPiMProton, &b_MassPiPPiMProton);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);

   fChain->SetBranchAddress("Mass2Proton", &Mass2Proton, &b_Mass2Proton);
   fChain->SetBranchAddress("Mass2PiP", &Mass2PiP, &b_Mass2PiP);
   fChain->SetBranchAddress("Mass2PiM", &Mass2PiM, &b_Mass2PiM);
   fChain->SetBranchAddress("Mass2Omega", &Mass2Omega, &b_Mass2Omega);
   fChain->SetBranchAddress("Mass2OmegaPiP", &Mass2OmegaPiP, &b_Mass2OmegaPiP);
   fChain->SetBranchAddress("Mass2OmegaPiM", &Mass2OmegaPiM, &b_Mass2OmegaPiM);
   fChain->SetBranchAddress("Mass2X", &Mass2X, &b_Mass2X);
}

Bool_t Feb2017sWeightPlotter::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Feb2017sWeightPlotter_cxx
