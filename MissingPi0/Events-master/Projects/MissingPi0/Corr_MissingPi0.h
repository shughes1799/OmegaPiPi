//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Aug 10 14:36:33 2017 by ROOT version 5.34/34
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/FirstStageProcessed/16FilesMissingPi0.root
//////////////////////////////////////////////////////////

#ifndef Corr_MissingPi0_h
#define Corr_MissingPi0_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Corr_MissingPi0 : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   THSParticle     *pim_0;
   THSParticle     *pim_1;
   THSParticle     *pip_0;
   THSParticle     *pip_1;
   THSParticle     *proton_0;
   THSParticle     *beam;
   TLorentzVector  *miss;
   Double_t        fgID;

   //Additional variables

   Double_t Mmiss;
   Double_t Egamma;
   Double_t MassProton;
   Double_t MassComb1;  //PiP Fast and PiM Fast
   Double_t MassComb2;  //PiP Fast and PiM Slow
   Double_t MassComb3;  //PiP Slow and PiM Fast
   Double_t MassComb4;  //PiP Slow and PiM Slow
   Double_t t;
   Double_t s;
  
   Double_t MassOmega1;  //PiP Fast and PiM Fast
   Double_t MassOmega2;  //PiP Fast and PiM Slow
   Double_t MassOmega3;  //PiP Slow and PiM Fast
   Double_t MassOmega4;  //PiP Slow and PiM Slow

   Double_t MassOmegaPiPi1;  //PiP Fast and PiM Fast
   Double_t MassOmegaPiPi2;  //PiP Fast and PiM Slow
   Double_t MassOmegaPiPi3;  //PiP Slow and PiM Fast
   Double_t MassOmegaPiPi4;  //PiP Slow and PiM Slow



   // List of branches
   TBranch        *b_pim_0;   //!
   TBranch        *b_pim_1;   //!
   TBranch        *b_pip_0;   //!
   TBranch        *b_pip_1;   //!
   TBranch        *b_proton_0;   //!
   TBranch        *b_beam;   //!
   TBranch        *b_miss;   //!
   TBranch        *b_fgID;   //!

   Corr_MissingPi0(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Corr_MissingPi0() { }
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

   ClassDef(Corr_MissingPi0,0);
};

#endif

#ifdef Corr_MissingPi0_cxx
void Corr_MissingPi0::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   pim_0 = 0;
   pim_1 = 0;
   pip_0 = 0;
   pip_1 = 0;
   proton_0 = 0;
   beam = 0;
   miss = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pim_0", &pim_0, &b_pim_0);
   fChain->SetBranchAddress("pim_1", &pim_1, &b_pim_1);
   fChain->SetBranchAddress("pip_0", &pip_0, &b_pip_0);
   fChain->SetBranchAddress("pip_1", &pip_1, &b_pip_1);
   fChain->SetBranchAddress("proton_0", &proton_0, &b_proton_0);
   fChain->SetBranchAddress("beam", &beam, &b_beam);
   fChain->SetBranchAddress("miss", &miss, &b_miss);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);
}

Bool_t Corr_MissingPi0::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Corr_MissingPi0_cxx
