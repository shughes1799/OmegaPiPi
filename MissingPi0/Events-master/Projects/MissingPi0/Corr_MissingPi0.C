#define Corr_MissingPi0_cxx
// The class definition in Corr_MissingPi0.h has been generated automatically
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
// Root > T->Process("Corr_MissingPi0.C")
// Root > T->Process("Corr_MissingPi0.C","some options")
// Root > T->Process("Corr_MissingPi0.C+")
//

#include "Corr_MissingPi0.h"
#include <TH2.h>
#include <TStyle.h>


void Corr_MissingPi0::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Corr_MissingPi0::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);

 fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
   //e.g. Make some objects to make branch with, these should be declared in the .h file 
   //e.g. fp1=new TLorentzVector();
 
 //e.g.  fOutTree->Branch("p1",&fp1,buff,split);
 fOutTree->Branch("Mmiss",&Mmiss,"Mmiss/D");
 fOutTree->Branch("Egamma",&Egamma,"Egamma/D");
 fOutTree->Branch("fgID",&fgID,"fgID/D");
 fOutTree->Branch("MassProton",&MassProton,"MassProton/D");
 fOutTree->Branch("MassComb1",&MassComb1,"MassComb1/D");
 fOutTree->Branch("MassComb2",&MassComb2,"MassComb2/D");
 fOutTree->Branch("MassComb3",&MassComb3,"MassComb3/D");
 fOutTree->Branch("MassComb4",&MassComb4,"MassComb4/D");
 fOutTree->Branch("t",&t,"t/D");
 fOutTree->Branch("s",&s,"s/D");
 fOutTree->Branch("MassOmega1",&MassOmega1,"MassOmega1/D");
 fOutTree->Branch("MassOmega2",&MassOmega2,"MassOmega2/D");
 fOutTree->Branch("MassOmega3",&MassOmega3,"MassOmega3/D");
 fOutTree->Branch("MassOmega4",&MassOmega4,"MassOmega4/D");
 fOutTree->Branch("MassOmegaPiPi1",&MassOmegaPiPi1,"MassOmegaPiPi1/D");
 fOutTree->Branch("MassOmegaPiPi2",&MassOmegaPiPi2,"MassOmegaPiPi2/D");
 fOutTree->Branch("MassOmegaPiPi3",&MassOmegaPiPi3,"MassOmegaPiPi3/D");
 fOutTree->Branch("MassOmegaPiPi4",&MassOmegaPiPi4,"MassOmegaPiPi4/D");
}

Bool_t Corr_MissingPi0::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Corr_MissingPi0::GetEntry() or TBranch::GetEntry()
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
   
    

   TLorentzVector Pi0 = *miss;
   Pi0.SetVectM(miss->Vect(),0.134977);

   Mmiss=miss->M();
   Egamma = beam->P4().E();

   if(Mmiss <= 0.02 || Mmiss >= 0.35) return kTRUE; 

   //Masses of the different combinations of pions
   TLorentzVector p4 = pim_0->P4()+pip_0->P4();
   TLorentzVector PionComb1 = p4;
   MassComb1 = p4.M();

   p4 = pim_1->P4()+pip_0->P4();
   TLorentzVector PionComb2 = p4;
   MassComb2 = p4.M();

   p4 = pim_0->P4()+pip_1->P4();
   TLorentzVector PionComb3 = p4;
   MassComb3 = p4.M();

   p4 = pim_1->P4()+pip_1->P4();
   TLorentzVector PionComb4 = p4;
   MassComb4 = p4.M();

   p4 = proton_0->P4();
   MassProton = p4.M();


   //Mandelstrum variables
   p4 = proton_0->P4();
   Double_t EnergyProton = p4.E();
   t = (-1)*((2*MassProton*MassProton)-(2*MassProton*EnergyProton));
   s = (MassProton*MassProton)+(2*Egamma*MassProton); //Might be calculated wrong.

   //Omega Combinations

   // p4 = pim_0->P4()+pip_0->P4()+*miss;
   p4 = pim_0->P4()+pip_0->P4()+Pi0;
   TLorentzVector OmegaComb1 = p4;
   OmegaComb1.SetVectM(p4.Vect(),0.78265);
   MassOmega1 = p4.M();

   // p4 = pim_1->P4()+pip_0->P4()+*miss;
   p4 = pim_1->P4()+pip_0->P4()+Pi0;
   TLorentzVector OmegaComb2 = p4;
   OmegaComb2.SetVectM(p4.Vect(),0.78265);
   MassOmega2 = p4.M();

   //p4 = pim_0->P4()+pip_1->P4()+*miss;
   p4 = pim_0->P4()+pip_1->P4()+Pi0;
   TLorentzVector OmegaComb3 = p4;
   OmegaComb3.SetVectM(p4.Vect(),0.78265);
   MassOmega3 = p4.M();

   // p4 = pim_1->P4()+pip_1->P4()+*miss;
   p4 = pim_1->P4()+pip_1->P4()+Pi0;
   TLorentzVector OmegaComb4 = p4;
   OmegaComb4.SetVectM(p4.Vect(),0.78265);
   MassOmega4 = p4.M();


   //OmegaPiPi vectors
   TLorentzVector OmegaPiPiComb1 = OmegaComb1+PionComb4;
   TLorentzVector OmegaPiPiComb2 = OmegaComb2+PionComb3;
   TLorentzVector OmegaPiPiComb3 = OmegaComb3+PionComb2;
   TLorentzVector OmegaPiPiComb4 = OmegaComb4+PionComb1;

   MassOmegaPiPi1 = OmegaPiPiComb1.M();
   MassOmegaPiPi2 = OmegaPiPiComb2.M();
   MassOmegaPiPi3 = OmegaPiPiComb3.M();
   MassOmegaPiPi4 = OmegaPiPiComb4.M();

   THSOutput::HSProcessFill();
   return kTRUE;
}

void Corr_MissingPi0::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Corr_MissingPi0::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
