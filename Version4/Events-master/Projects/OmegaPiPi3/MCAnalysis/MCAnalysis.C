#define MCAnalysis_cxx
// The class definition in MCAnalysis.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("MCAnalysis.C")
// Root > T->Process("MCAnalysis.C","some options")
// Root > T->Process("MCAnalysis.C+")
//

#include "MCAnalysis.h"
#include <TH2.h>
#include <TStyle.h>


void MCAnalysis::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void MCAnalysis::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);

   fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
   
   fOutTree->Branch("PhiOmega",&PhiOmega,"PhiOmega/D");
   fOutTree->Branch("ThetaOmega",&ThetaOmega,"ThetaOmega/D");
   fOutTree->Branch("PhiMiss",&PhiMiss,"PhiMiss/D");
   fOutTree->Branch("ThetaMiss",&ThetaMiss,"ThetaMiss/D");
   fOutTree->Branch("PhiPiP",&PhiPiP,"PhiPiP/D");
   fOutTree->Branch("ThetaPiP",&ThetaPiP,"ThetaPiP/D");
   fOutTree->Branch("PhiPiM",&PhiPiM,"PhiPiM/D");
   fOutTree->Branch("ThetaPiM",&ThetaPiM,"ThetaPiM/D");
   fOutTree->Branch("PhiProton",&PhiProton,"PhiProton/D");
   fOutTree->Branch("ThetaProton",&ThetaProton,"ThetaProton/D");

}

Bool_t MCAnalysis::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either MCAnalysis::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   GetEntry(entry); //lazy and slow, you can speed the code up by getting the branches you need to use instead
   //Ready to do some analysis here, before the Fill
   
   TLorentzVector Omega = *miss;
   Omega.SetVectM(miss->Vect(),0.7826);  //Correcting the mass of the missing vector to the pdg omega mass.

   TLorentzVector p4;

   p4 = pip_0->P4();

   PhiPiP = p4.Phi();
   PhiPiP = PhiPiP*360/(2*TMath::Pi());
   ThetaPiP = p4.Theta();
   ThetaPiP = ThetaPiP*360/(2*TMath::Pi());

   p4 = pim_0->P4();

   PhiPiM = p4.Phi();
   PhiPiM = PhiPiM*360/(2*TMath::Pi());
   ThetaPiM = p4.Theta();
   ThetaPiM = ThetaPiM*360/(2*TMath::Pi());

   p4 = proton_0->P4();
  
   PhiProton = p4.Phi();
   PhiProton = PhiProton*360/(2*TMath::Pi());
   ThetaProton = p4.Theta();
   ThetaProton = ThetaProton*360/(2*TMath::Pi());

   p4 = *miss;

   PhiMiss = p4.Phi();
   PhiMiss = PhiMiss*360/(2*TMath::Pi());
   ThetaMiss = p4.Theta();
   ThetaMiss = ThetaMiss*360/(2*TMath::Pi());

   p4 = Omega;

   PhiOmega = p4.Phi();
   PhiOmega = PhiOmega*360/(2*TMath::Pi());
   ThetaOmega = p4.Theta();
   ThetaOmega = ThetaOmega*360/(2*TMath::Pi());

   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void MCAnalysis::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void MCAnalysis::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
