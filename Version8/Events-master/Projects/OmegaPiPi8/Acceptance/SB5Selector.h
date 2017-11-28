//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Apr 25 14:06:16 2016 by ROOT version 5.34/23
// from TTree HSParticles/A tree containing reconstructed particles
// found on file: /phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/April/RealData/FurtherExtendedTest4/batch1.root
//////////////////////////////////////////////////////////

#ifndef SB5Selector_h
#define SB5Selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TH2.h>
#include "THSOutput.h"

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class SB5Selector : public TSelector, public THSOutput {
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
   Double_t        FrameBoostVTestX;
   Double_t        FrameXBoostVTestY;
   Double_t        FrameXBoostVTestZ;
   Double_t        MassOmegaFrameX;
   Double_t        PhiOmegaFrameX;
   Double_t        ThetaOmegaFrameX;
   Double_t        MassPiPFrameX;
   Double_t        PhiPiPFrameX;
   Double_t        ThetaPiPFrameX;
   Double_t        MassPiMFrameX;
   Double_t        PhiPiMFrameX;
   Double_t        ThetaPiMFrameX;
   Double_t        AngleBeamFXandOmegaLab;
   Double_t        AngleMesonXLabandOmegaFX;
   Double_t        fgID;

   //Weighting Variables and objects
   Double_t SignalEnergyWeight;
   Double_t SideEnergyWeight;

   TFile *WeightingFile;

   TH1F *EWSignal;
   TH1F *EWSide;

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
   TBranch        *b_MassPiPPiMProton; //!
   TBranch        *b_FrameXBoostVTestX;   //!
   TBranch        *b_FrameXBoostVTestY;   //!
   TBranch        *b_FrameXBoostVTestZ;   //!
   TBranch        *b_MassOmegaFrameX;   //!
   TBranch        *b_PhiOmegaFrameX;   //!
   TBranch        *b_ThetaOmegaFrameX;   //!
   TBranch        *b_MassPiPFrameX;   //!
   TBranch        *b_PhiPiPFrameX;   //!
   TBranch        *b_ThetaPiPFrameX;   //!
   TBranch        *b_MassPiMFrameX;   //!
   TBranch        *b_PhiPiMFrameX;   //!
   TBranch        *b_ThetaPiMFrameX;   //!
   TBranch        *b_AngleBeamFXandOmegaLab;   //!
   TBranch        *b_AngleMesonXLabandOmegaFX;   //!
   TBranch        *b_fgID;   //!

   SB5Selector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~SB5Selector() { }
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

   //Simon Functions
   virtual Double_t EnergyWeightingSignal(Double_t SigEW);
   virtual Double_t EnergyWeightingSide(Double_t SideEW);

   ClassDef(SB5Selector,0);
};

#endif

#ifdef SB5Selector_cxx
void SB5Selector::Init(TTree *tree)
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
   fChain->SetBranchAddress("FrameBoostVTestX", &FrameBoostVTestX, &b_FrameXBoostVTestX);
   fChain->SetBranchAddress("FrameXBoostVTestY", &FrameXBoostVTestY, &b_FrameXBoostVTestY);
   fChain->SetBranchAddress("FrameXBoostVTestZ", &FrameXBoostVTestZ, &b_FrameXBoostVTestZ);
   fChain->SetBranchAddress("MassOmegaFrameX", &MassOmegaFrameX, &b_MassOmegaFrameX);
   fChain->SetBranchAddress("PhiOmegaFrameX", &PhiOmegaFrameX, &b_PhiOmegaFrameX);
   fChain->SetBranchAddress("ThetaOmegaFrameX", &ThetaOmegaFrameX, &b_ThetaOmegaFrameX);
   fChain->SetBranchAddress("MassPiPFrameX", &MassPiPFrameX, &b_MassPiPFrameX);
   fChain->SetBranchAddress("PhiPiPFrameX", &PhiPiPFrameX, &b_PhiPiPFrameX);
   fChain->SetBranchAddress("ThetaPiPFrameX", &ThetaPiPFrameX, &b_ThetaPiPFrameX);
   fChain->SetBranchAddress("MassPiMFrameX", &MassPiMFrameX, &b_MassPiMFrameX);
   fChain->SetBranchAddress("PhiPiMFrameX", &PhiPiMFrameX, &b_PhiPiMFrameX);
   fChain->SetBranchAddress("ThetaPiMFrameX", &ThetaPiMFrameX, &b_ThetaPiMFrameX);
   fChain->SetBranchAddress("AngleBeamFXandOmegaLab", &AngleBeamFXandOmegaLab, &b_AngleBeamFXandOmegaLab);
   fChain->SetBranchAddress("AngleMesonXLabandOmegaFX", &AngleMesonXLabandOmegaFX, &b_AngleMesonXLabandOmegaFX);
   fChain->SetBranchAddress("fgID", &fgID, &b_fgID);
}

Bool_t SB5Selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.
   THSOutput::HSNotify(fChain);

   return kTRUE;
}

#endif // #ifdef SB5Selector_cxx
