//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Aug 14 14:22:57 2017 by ROOT version 5.34/34
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/Corrected_Data/16FilesCorrMissingPi0.root
//////////////////////////////////////////////////////////

#ifndef Histo_sWeights_MissingPi0_h
#define Histo_sWeights_MissingPi0_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"
#include "THSWeights.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class Histo_sWeights_MissingPi0 : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Double_t        Mmiss;
   Double_t        Egamma;
   Double_t        MassProton;
   Double_t        MassComb1;
   Double_t        MassComb2;
   Double_t        MassComb3;
   Double_t        MassComb4;
   Double_t        t;
   Double_t        s;
   Double_t        MassOmega1;
   Double_t        MassOmega2;
   Double_t        MassOmega3;
   Double_t        MassOmega4;
   Double_t        MassOmegaPiPi1;
   Double_t        MassOmegaPiPi2;
   Double_t        MassOmegaPiPi3;
   Double_t        MassOmegaPiPi4;
   Double_t        fgID;

   //Additional Variables
   Double_t PickMassDiff;
   Double_t PickMassOmegaPiPi;
   Double_t PickMassOmega;
   Double_t MassDiff1;
   Double_t MassDiff2;
   Double_t MassDiff3;
   Double_t MassDiff4;

   //Data members for reading sWeights
   THSWeights* fWeights;
   // List of branches
   TBranch        *b_Mmiss;   //!
   TBranch        *b_Egamma;   //!
   TBranch        *b_MassProton;   //!
   TBranch        *b_MassComb1;   //!
   TBranch        *b_MassComb2;   //!
   TBranch        *b_MassComb3;   //!
   TBranch        *b_MassComb4;   //!
   TBranch        *b_t;   //!
   TBranch        *b_s;   //!
   TBranch        *b_MassOmega1;   //!
   TBranch        *b_MassOmega2;   //!
   TBranch        *b_MassOmega3;   //!
   TBranch        *b_MassOmega4;   //!
   TBranch        *b_MassOmegaPiPi1;   //!
   TBranch        *b_MassOmegaPiPi2;   //!
   TBranch        *b_MassOmegaPiPi3;   //!
   TBranch        *b_MassOmegaPiPi4;   //!
   TBranch        *b_fgID;   //!

   Histo_sWeights_MissingPi0(TTree * /*tree*/ =0) : fChain(0),fWeights(0) { }
   virtual ~Histo_sWeights_MissingPi0() { }
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

   ClassDef(Histo_sWeights_MissingPi0,0);
};

#endif

#ifdef Histo_sWeights_MissingPi0_cxx
void Histo_sWeights_MissingPi0::Init(TTree *tree)
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
   fChain->SetBranchAddress("MassComb1", &MassComb1, &b_MassComb1);
   fChain->SetBranchAddress("MassComb2", &MassComb2, &b_MassComb2);
   fChain->SetBranchAddress("MassComb3", &MassComb3, &b_MassComb3);
   fChain->SetBranchAddress("MassComb4", &MassComb4, &b_MassComb4);
   fChain->SetBranchAddress("t", &t, &b_t);
   fChain->SetBranchAddress("s", &s, &b_s);
   fChain->SetBranchAddress("MassOmega1", &MassOmega1, &b_MassOmega1);
   fChain->SetBranchAddress("MassOmega2", &MassOmega2, &b_MassOmega2);
   fChain->SetBranchAddress("MassOmega3", &MassOmega3, &b_MassOmega3);
   fChain->SetBranchAddress("MassOmega4", &MassOmega4, &b_MassOmega4);
   fChain->SetBranchAddress("MassOmegaPiPi1", &MassOmegaPiPi1, &b_MassOmegaPiPi1);
   fChain->SetBranchAddress("MassOmegaPiPi2", &MassOmegaPiPi2, &b_MassOmegaPiPi2);
   fChain->SetBranchAddress("MassOmegaPiPi3", &MassOmegaPiPi3, &b_MassOmegaPiPi3);
   fChain->SetBranchAddress("MassOmegaPiPi4", &MassOmegaPiPi4, &b_MassOmegaPiPi4);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);
}

Bool_t Histo_sWeights_MissingPi0::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Histo_sWeights_MissingPi0_cxx
