//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jun 21 13:56:51 2016 by ROOT version 5.34/23
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/May16filesMissingOmega/batch1.root
//////////////////////////////////////////////////////////

#ifndef LongSP_h
#define LongSP_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"
#include "THSLongPS.h"

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>

// Fixed size dimensions of array or collections stored in the TTree if any.

class LongSP : public TSelector, public THSOutput {
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

   //Additional LP Lorentz Vectors
   TLorentzVector *pOmegaPiPPiM;

   TLorentzVector *OmegaPiPPiM;
   TLorentzVector *pPiPPiM;
   TLorentzVector *pOmegaPiP;
   TLorentzVector *pOmegaPiM;

   TLorentzVector *OmegaPiP;
   TLorentzVector *OmegaPiM;
   TLorentzVector *pOmega;
   TLorentzVector *pPiP;
   TLorentzVector *pPiM;
   TLorentzVector *PiPPiM;
 
   //Variables for LP

   Float_t ftOmegaPiPPiM;
   Float_t ftOmegaPiP;
   Float_t ftOmegaPiM;
   Float_t ftPiPPiM;
   
   Float_t Mmiss;
   Float_t Eg;
   
   Float_t MOmegaPiPPiM;
   Float_t MOmegaPiP;
   Float_t MOmegaPiM;
   Float_t MPiPPiM;
   
   //LPS Variables
   Float_t fMTop; //Mass of particles in top branch
   Float_t fMBot; //MAss of particles on bottom branch
   Float_t fCosTh; //centre of mass cos(theta) for LPS events
   Float_t fSector; //sector number for LPS events


   Double_t        fgID;
  //data members for new branches
  //you must define how they are processed for each event
  //e.g.   TLorentzVector  *fp1;

   // List of branches
   TBranch        *b_pim_0;   //!
   TBranch        *b_pip_0;   //!
   TBranch        *b_proton_0;   //!
   TBranch        *b_beam;   //!
   TBranch        *b_miss;   //!
   TBranch        *b_MesonXTest;   //!
   TBranch        *b_fgID;   //!

   LongSP(TTree * /*tree*/ =0) : fChain(0),fLPS(0) { }
   virtual ~LongSP() {SafeDelete(fLPS); }
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

   ClassDef(LongSP,0);
};

#endif

#ifdef LongSP_cxx
void LongSP::Init(TTree *tree)
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
}

Bool_t LongSP::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);
  THSOutput::InitOutTree();

   return kTRUE;
}

#endif // #ifdef LongSP_cxx
