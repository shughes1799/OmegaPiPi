#define LongSP_cxx
// The class definition in LongSP.h has been generated automatically
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
// Root > T->Process("LongSP.C")
// Root > T->Process("LongSP.C","some options")
// Root > T->Process("LongSP.C+")
//

#include "LongSP.h"
#include <TH2.h>
#include <TStyle.h>


void LongSP::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void LongSP::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
   //Construct the LongPS object with number of particles in final state
   fLPS=new THSLongPS(4);
//IF using THSHisto can use next line to create cut for each sector
//Alternatively you could use the sector number do define a kinemtic bin and use fHisbins
//for(Int_t i=0;i<fLPS->GetNSector();i++)   THSHisto::LoadCut(fLPS->GetSectName(i));
  //Initialise the ouput tree
   Int_t buff=32000;
   Int_t split=0;//note split is important in the TSelector framework, if increased branches in subsequent selectors will be data members of the THSParticle object rather than the whole object (this can lead to name conflicts)
   //Only done once. THSOutput::FinishOutput Resets the tree before new files
   //If you want to save additional branches to a new file, do it here
   //If you are creating a HSParticle tree via fStrParticles then do not create a new tree here, just add the extra branches
   fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
  //e.g. Make some objects to make branch with, these should be declared in the .h file 
 //e.g. fp1=new TLorentzVector();
  //e.g.  fOutTree->Branch("p1",&fp1,buff,split);

   fOutTree->Branch("ftOmegaPiPPiM",&ftOmegaPiPPiM,"ftOmegaPiPPiM/F");
   fOutTree->Branch("ftOmegaPiP",&ftOmegaPiP,"ftOmegaPiP/F");
   fOutTree->Branch("ftOmegaPiM",&ftOmegaPiM,"ftOmegaPiM/F");
   fOutTree->Branch("ftPiPPiM",&ftPiPPiM,"ftPiPPiM/F");
   fOutTree->Branch("Mmiss",&Mmiss,"Mmiss/F");
   fOutTree->Branch("Eg",&Eg,"Eg/F");
   fOutTree->Branch("MOmegaPiPPiM",&MOmegaPiPPiM,"MOmegaPiPPiM/F");
   fOutTree->Branch("MOmegaPiP",&MOmegaPiP,"MOmegaPiP/F");
   fOutTree->Branch("MOmegaPiM",&MOmegaPiM,"MOmegaPiM/F");
   fOutTree->Branch("MPiPPiM",&MPiPPiM,"MPiPPiM/F");
   fOutTree->Branch("MTop",&fMTop,"MTop/F"); 
   fOutTree->Branch("MBot",&fMBot,"MBot/F"); 
   fOutTree->Branch("CosTh",&fMtop,"CosTh/F"); 
   fOutTree->Branch("Sector",&fSector,"Sector/F"); 

   Float_t ftOmegaPiPPiM;
   Float_t ftOmegaPiP;
   Float_t ftOmegaPiM;
   Float_t ftPiPPiM;
   
   Float_t  Mmiss;
   Float_t  Eg;
   
   Float_t  MOmegaPiPPiM;
   Float_t  MOmegaPiP;
   Float_t MOmegaPiM;
   Float_t  MPiPPiM;
   
   //LPS Variables
   Float_t fMTop; //Mass of particles in top branch
   Float_t fMBot; //MAss of particles on bottom branch
   Float_t fCosTh; //centre of mass cos(theta) for LPS events
   Float_t fSector; //sector number for LPS events

  //if you want kinematic bins you must define fHisbins here
   //fHisbins=new TH*()
   if(fHisbins) fOutput->Add(fHisbins);
   //fHisbins->SetXTitle();//give useful axis name
   //fHisbins->SetYTitle();//give useful axis name
   THSHisto::ChangeNames();
   THSHisto::LoadCut("Cut1");
   THSHisto::LoadHistograms();
}

Bool_t LongSP::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either LongSP::GetEntry() or TBranch::GetEntry()
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
   fLPS->Reset();
   //below you need to give the final state TLorentzVectors to fLPS. Replace ??? by the TLorentzVector object. The order gives the particle indice for the sectors
  fLPS->AddParticle(???);
  fLPS->AddParticle(???);
  fLPS->AddParticle(???);
  fLPS->AddParticle(???);
  fLPS->Analyse();
   //Ready to do some analysis here, before the Fill
   
   //Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
   FillHistograms("Cut1",0);
  // FillHistograms(fLPS->GetSectName(fLPS->GetSector()),kinBin);
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void LongSP::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void LongSP::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void LongSP::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  fOutput->Add(MapHist(new TH2F("MTopVMBot"+sLabel,"M_{Top} V M_{Bot}"+sLabel,200,0.2,2,200,0.2,2)));
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
  //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void LongSP::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());
  ((TH2F*)FindHist("MTopVMBot"))->Fill(fLPS->GetTopMass(),fLPS->GetBotMass());
}
