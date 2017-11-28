#define sWCuts_cxx
// The class definition in sWCuts.h has been generated automatically
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
// Root > T->Process("sWCuts.C")
// Root > T->Process("sWCuts.C","some options")
// Root > T->Process("sWCuts.C+")
//

#include "sWCuts.h"
#include <TH2.h>
#include <TStyle.h>


void sWCuts::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void sWCuts::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);

// //Construct the LongPS object with number of particles in final state
//    fLPS=new THSLongPS(4);

   fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
   //e.g. Make some objects to make branch with, these should be declared in the .h file 
   //e.g. fp1=new TLorentzVector();

   fOutTree->Branch("Mmiss",&Mmiss,"Mmiss/D");
   fOutTree->Branch("Egamma",&Egamma,"Egamma/D");
   fOutTree->Branch("MassProton",&MassProton,"MassProton/D");
   fOutTree->Branch("MassPiP",&MassPiP,"MassPiP/D");
   fOutTree->Branch("MassPiM",&MassPiM,"MassPiM/D");
   fOutTree->Branch("MassOmega",&MassOmega,"MassOmega/D");
   fOutTree->Branch("MassOmegaPiP",&MassOmegaPiP,"MassOmegaPiP/D");
   fOutTree->Branch("MassOmegaPiM",&MassOmegaPiM,"MassOmegaPiM/D");
   fOutTree->Branch("MassX",&MassX,"MassX/D");
   // fOutTree->Branch("PhiX",&PhiX,"PhiX/D");
   // fOutTree->Branch("ThetaX",&ThetaX,"ThetaX/D");
   fOutTree->Branch("MassPiPPiM",&MassPiPPiM,"MassPiPPiM/D");
   fOutTree->Branch("t",&t,"t/D");
   fOutTree->Branch("s",&s,"s/D");
   fOutTree->Branch("MassOmegaProton",&MassOmegaProton,"MassOmegaProton/D");
   fOutTree->Branch("MassPiPProton",&MassPiPProton,"MassPiPProton/D");
   fOutTree->Branch("MassPiMProton",&MassPiMProton,"MassPiMProton/D");
   fOutTree->Branch("MassPiPPiMProton",&MassPiPPiMProton,"MassPiPPiMProton/D");
   fOutTree->Branch("fgID",&fgID,"fgID/D");
   // fOutTree->Branch("CosTh",&fCosTh,"CosTh/D"); 
   // fOutTree->Branch("Sector",&fSector,"Sector/D"); 

   fOutTree->Branch("Mass2Proton",&Mass2Proton,"Mass2Proton/D");
   fOutTree->Branch("Mass2PiP",&Mass2PiP,"Mass2PiP/D");
   fOutTree->Branch("Mass2PiM",&Mass2PiM,"Mass2PiM/D");
   fOutTree->Branch("Mass2Omega",&Mass2Omega,"Mass2Omega/D");
   fOutTree->Branch("Mass2OmegaPiP",&Mass2OmegaPiP,"Mass2OmegaPiP/D");
   fOutTree->Branch("Mass2OmegaPiM",&Mass2OmegaPiM,"Mass2OmegaPiM/D");
   fOutTree->Branch("Mass2X",&Mass2X,"Mass2X/D");

}

Bool_t sWCuts::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either sWCuts::GetEntry() or TBranch::GetEntry()
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

   //if((MassOmegaPiP >= 1.17 && MassOmegaPiP < 1.29) || (MassOmegaPiM >= 1.17 && MassOmegaPiM < 1.29)){

   if(MassPiPPiM >= 0.720 && MassPiPPiM < 0.820){


   
   THSOutput::HSProcessFill(); 
  }

   return kTRUE;
}

void sWCuts::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void sWCuts::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
