//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 17 15:12:24 2016 by ROOT version 5.34/23
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/May16filesMissingOmega/batch1.root
//////////////////////////////////////////////////////////

#ifndef Corrected5_h
#define Corrected5_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"
#include "THSLongPS.h"

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class Corrected5 : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   THSLongPS* fLPS;

   // Declaration of leaf types
   THSParticle     *pim_0;
   THSParticle     *pip_0;
   THSParticle     *proton_0;
   THSParticle     *beam;
   TLorentzVector  *miss;
   TLorentzVector  *MesonXTest;
   TLorentzVector  *missGammaP;
   Double_t        fgID;

   //Double's for further analysis

   Double_t Mmiss;
   Double_t Emiss;
   Double_t Egamma;
   Double_t MassProton;
   Double_t MassPiP; 
   Double_t MassPiM; 
   Double_t MassOmega;
   Double_t MassOmegaPiP;
   Double_t MassOmegaPiM;
   Double_t MassX;  //The consolidated meson (omegaPiPi)
   Double_t PhiX;
   Double_t ThetaX;
   Double_t MassPiPPiM; //The mass of the two detected pions 
   Double_t t;
   Double_t s;
   Double_t MassOmegaProton;
   Double_t MassPiPProton;
   Double_t MassPiMProton;
   Double_t MassPiPPiMProton;

   Double_t fCosTh;
   Double_t fSector;

   //Mass Squared Variables
   Double_t Mmiss2;
   Double_t Mass2Proton;
   Double_t Mass2PiP; 
   Double_t Mass2PiM; 
   Double_t Mass2Omega;
   Double_t Mass2OmegaPiP;
   Double_t Mass2OmegaPiM;
   Double_t Mass2X;  //The consolidated meson (omegaPiPi)

   Double_t MmissGammaP;

   // List of branches
   TBranch        *b_pim_0;   //!
   TBranch        *b_pip_0;   //!
   TBranch        *b_proton_0;   //!
   TBranch        *b_beam;   //!
   TBranch        *b_miss;   //!
   TBranch        *b_MesonXTest;   //!
   TBranch        *b_fgID;   //!
   TBranch        *b_missGammaP;   //!


 Corrected5(TTree * /*tree*/ =0) : fChain(0), fLPS(0) { }
   virtual ~Corrected5() { }
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

   ClassDef(Corrected5,0);
};

#endif

#ifdef Corrected5_cxx
void Corrected5::Init(TTree *tree)
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
   pip_0 = 0;
   proton_0 = 0;
   beam = 0;
   miss = 0;
   MesonXTest = 0;
   missGammaP = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pim_0", &pim_0, &b_pim_0);
   fChain->SetBranchAddress("pip_0", &pip_0, &b_pip_0);
   fChain->SetBranchAddress("proton_0", &proton_0, &b_proton_0);
   fChain->SetBranchAddress("beam", &beam, &b_beam);
   fChain->SetBranchAddress("miss", &miss, &b_miss);
   fChain->SetBranchAddress("MesonXTest", &MesonXTest, &b_MesonXTest);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);
   fChain->SetBranchAddress("missGammaP", &missGammaP, &b_missGammaP);
}

Bool_t Corrected5::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Corrected5_cxx
