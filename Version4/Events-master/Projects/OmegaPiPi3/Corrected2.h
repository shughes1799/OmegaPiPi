//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May  2 11:57:19 2016 by ROOT version 5.34/23
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/PhaseSpaceEdGen1mil/Processed1/g11_simon_centos61001.bos.evt.recsis.root
//////////////////////////////////////////////////////////

#ifndef Corrected2_h
#define Corrected2_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include "THSOutput.h"

// Header file for the classes stored in the TTree if any.
#include <TLorentzVector.h>
#include <TObject.h>
#include <TVector3.h>

// Fixed size dimensions of array or collections stored in the TTree if any.
   const Int_t kMaxMCTruth = 3;

class Corrected2 : public TSelector, public THSOutput {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   THSParticle     *pim_0;
   THSParticle     *pip_0;
   THSParticle     *proton_0;
   THSParticle     *beam;
   TLorentzVector  *miss;
   Int_t           MCTruth_;
   UInt_t          MCTruth_fUniqueID[kMaxMCTruth];   //[MCTruth_]
   UInt_t          MCTruth_fBits[kMaxMCTruth];   //[MCTruth_]
   UInt_t          MCTruth_fP_fUniqueID[kMaxMCTruth];   //[MCTruth_]
   UInt_t          MCTruth_fP_fBits[kMaxMCTruth];   //[MCTruth_]
   Double_t        MCTruth_fP_fX[kMaxMCTruth];   //[MCTruth_]
   Double_t        MCTruth_fP_fY[kMaxMCTruth];   //[MCTruth_]
   Double_t        MCTruth_fP_fZ[kMaxMCTruth];   //[MCTruth_]
   Double_t        MCTruth_fE[kMaxMCTruth];   //[MCTruth_]
   TLorentzVector  *Proton;
   TLorentzVector  *PiP;
   TLorentzVector  *PiM;
   Double_t        fgID;

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


   //Frame of X meson variables
   Double_t FrameXBoostVTestX;
   Double_t FrameXBoostVTestY;
   Double_t FrameXBoostVTestZ;

   Double_t MassOmegaFrameX;
   Double_t PhiOmegaFrameX;
   Double_t ThetaOmegaFrameX;
   Double_t MassPiPFrameX;
   Double_t PhiPiPFrameX;
   Double_t ThetaPiPFrameX;
   Double_t MassPiMFrameX;
   Double_t PhiPiMFrameX;
   Double_t ThetaPiMFrameX;

   //Dot Product Variables

   Double_t AngleBeamFXandOmegaLab;
   Double_t AngleMesonXLabandOmegaFX;

   // List of branches
   TBranch        *b_pim_0;   //!
   TBranch        *b_pip_0;   //!
   TBranch        *b_proton_0;   //!
   TBranch        *b_beam;   //!
   TBranch        *b_miss;   //!
   TBranch        *b_MCTruth_;   //!
   TBranch        *b_MCTruth_fUniqueID;   //!
   TBranch        *b_MCTruth_fBits;   //!
   TBranch        *b_MCTruth_fP_fUniqueID;   //!
   TBranch        *b_MCTruth_fP_fBits;   //!
   TBranch        *b_MCTruth_fP_fX;   //!
   TBranch        *b_MCTruth_fP_fY;   //!
   TBranch        *b_MCTruth_fP_fZ;   //!
   TBranch        *b_MCTruth_fE;   //!
   TBranch        *b_Proton;   //!
   TBranch        *b_PiP;   //!
   TBranch        *b_PiM;   //!
   TBranch        *b_fgID;   //!

   Corrected2(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~Corrected2() { }
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

   ClassDef(Corrected2,0);
};

#endif

#ifdef Corrected2_cxx
void Corrected2::Init(TTree *tree)
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
   Proton = 0;
   PiP = 0;
   PiM = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("pim_0", &pim_0, &b_pim_0);
   fChain->SetBranchAddress("pip_0", &pip_0, &b_pip_0);
   fChain->SetBranchAddress("proton_0", &proton_0, &b_proton_0);
   fChain->SetBranchAddress("beam", &beam, &b_beam);
   fChain->SetBranchAddress("miss", &miss, &b_miss);
   fChain->SetBranchAddress("MCTruth", &MCTruth_, &b_MCTruth_);
   fChain->SetBranchAddress("MCTruth.fUniqueID", MCTruth_fUniqueID, &b_MCTruth_fUniqueID);
   fChain->SetBranchAddress("MCTruth.fBits", MCTruth_fBits, &b_MCTruth_fBits);
   fChain->SetBranchAddress("MCTruth.fP.fUniqueID", MCTruth_fP_fUniqueID, &b_MCTruth_fP_fUniqueID);
   fChain->SetBranchAddress("MCTruth.fP.fBits", MCTruth_fP_fBits, &b_MCTruth_fP_fBits);
   fChain->SetBranchAddress("MCTruth.fP.fX", MCTruth_fP_fX, &b_MCTruth_fP_fX);
   fChain->SetBranchAddress("MCTruth.fP.fY", MCTruth_fP_fY, &b_MCTruth_fP_fY);
   fChain->SetBranchAddress("MCTruth.fP.fZ", MCTruth_fP_fZ, &b_MCTruth_fP_fZ);
   fChain->SetBranchAddress("MCTruth.fE", MCTruth_fE, &b_MCTruth_fE);
   fChain->SetBranchAddress("Proton", &Proton, &b_Proton);
   fChain->SetBranchAddress("PiP", &PiP, &b_PiP);
   fChain->SetBranchAddress("PiM", &PiM, &b_PiM);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);
}

Bool_t Corrected2::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef Corrected2_cxx
