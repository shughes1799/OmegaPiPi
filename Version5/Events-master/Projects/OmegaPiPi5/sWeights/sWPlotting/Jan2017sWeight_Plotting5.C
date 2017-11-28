#define Jan2017sWeight_Plotting5_cxx
// The class definition in Jan2017sWeight_Plotting5.h has been generated automatically
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
// Root > T->Process("Jan2017sWeight_Plotting5.C")
// Root > T->Process("Jan2017sWeight_Plotting5.C","some options")
// Root > T->Process("Jan2017sWeight_Plotting5.C+")
//

#include "Jan2017sWeight_Plotting5.h"
#include <TH2.h>
#include <TStyle.h>


void Jan2017sWeight_Plotting5::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Jan2017sWeight_Plotting5::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
   //Get weights from file
   fWeights=new THSWeights();
   //fWeights->SetMap(option,"WeightMap");
   //cout<<"Printing WeightMap "<<endl;
   //fWeights->PrintWeight();

   cout<<"Printing WeightMap "<<endl;
   fWeights->LoadSaved(option,"WeightMap");
   fWeights->PrintWeight();
  //if you want kinematic bins you must define fHisbins here
   //fHisbins=new TH*()
   if(fHisbins) fOutput->Add(fHisbins);
   //fHisbins->SetXTitle();//give useful axis name
   //fHisbins->SetYTitle();//give useful axis name
   THSHisto::ChangeNames();
   //THSHisto::LoadCut("Cut1");
   //Load histograms for each species that has a weight
   if(fWeights){
     StrIntMap_t spec=fWeights->GetSpecies();
     for(StrIntMap_t::iterator its=spec.begin();its!=spec.end();++its)
       THSHisto::LoadCut(its->first);
    }
   THSHisto::LoadHistograms();
}

Bool_t Jan2017sWeight_Plotting5::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Jan2017sWeight_Plotting5::GetEntry() or TBranch::GetEntry()
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
   
   //Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
   //FillHistograms("Cut1",0);
   //Fill histograms for each species
   if(Mmiss < 0.74 || Mmiss > 0.82) return kFALSE;

   if(fWeights){
     StrIntMap_t spec=fWeights->GetSpecies();
     for(StrIntMap_t::iterator itss=spec.begin();itss!=spec.end();++itss)
       FillHistograms(itss->first,0);
   }
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void Jan2017sWeight_Plotting5::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Jan2017sWeight_Plotting5::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void Jan2017sWeight_Plotting5::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
 fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass(GeV) "+sLabel,64,0.65,0.9)));
fOutput->Add(MapHist(new TH1F("MX"+sLabel,"Mass of X (GeV) "+sLabel,100,1.1,1.9)));
fOutput->Add(MapHist(new TH1F("MOPiP"+sLabel,"Mass of #omega#pi^{+} (GeV) "+sLabel,64,0.9,1.6)));
  fOutput->Add(MapHist(new TH1F("MOPiM"+sLabel,"Mass of #omega#pi^{-} (GeV) "+sLabel,64,0.9,1.6)));
 fOutput->Add(MapHist(new TH1F("MPiPProton"+sLabel,"M_{#pi+,Proton} (GeV) "+sLabel,64,1.05,1.8)));
  fOutput->Add(MapHist(new TH1F("MPiMProton"+sLabel,"M_{#pi-,Proton} (GeV) "+sLabel,64,1.05,1.8)));
fOutput->Add(MapHist(new TH1F("t"+sLabel,"t"+sLabel,64,0,4)));
 fOutput->Add(MapHist(new TH2F("MPiPProtonVMX"+sLabel,"M_{#pi+,Proton} vs M_{X} (GeV)"+sLabel,40,1.05,1.8,40,1.1,1.9)));
   fOutput->Add(MapHist(new TH2F("MPiMProtonVMX"+sLabel,"M_{#pi-,Proton} vs M_{X} (GeV)"+sLabel,40,1.05,1.8,40,1.1,1.9)));
  //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Jan2017sWeight_Plotting5::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());
  Double_t Weight=1;
  if(fWeights){
    if(fWeights->Size()>0)
      Weight=fWeights->GetWeight(sCut);
  }
  FindHist("Mmiss")->Fill(Mmiss,Weight);
  FindHist("MX")->Fill(MassX,Weight);
  FindHist("MOPiP")->Fill(MassOmegaPiP,Weight);
  FindHist("MOPiM")->Fill(MassOmegaPiM,Weight);
  FindHist("MPiPProton")->Fill(MassPiPProton,Weight);
  FindHist("MPiMProton")->Fill(MassPiMProton,Weight);
  
  ((TH2F*)FindHist("MPiPProtonVMX"))->Fill(MassPiPProton,MassX,Weight);
  ((TH2F*)FindHist("MPiMProtonVMX"))->Fill(MassPiMProton,MassX,Weight);
  
}
