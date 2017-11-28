#define sWeight_Plotting5_cxx
// The class definition in sWeight_Plotting5.h has been generated automatically
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
// Root > T->Process("sWeight_Plotting5.C")
// Root > T->Process("sWeight_Plotting5.C","some options")
// Root > T->Process("sWeight_Plotting5.C+")
//

#include "sWeight_Plotting5.h"
#include <TH2.h>
#include <TStyle.h>


void sWeight_Plotting5::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void sWeight_Plotting5::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
   //Get weights from file
    fWeights=new THSWeights();
    
    cout<<"Printing WeightMap "<<endl;
    fWeights->LoadSaved(option,"WeightMap");
    fWeights->PrintWeight();
  
//if you want kinematic bins you must define fHisbins here
    fHisbins=new TH1F("LPS","LPS",14,-0.5,13.5);
   if(fHisbins) fOutput->Add(fHisbins);
   fHisbins->SetXTitle("Sector");//give useful axis name
   // fHisbins->SetYTitle();//give useful axis name
  
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

Bool_t sWeight_Plotting5::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either sWeight_Plotting5::GetEntry() or TBranch::GetEntry()
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
   
   if(Mmiss < 0.72 || Mmiss > 0.86) return kFALSE;
   Int_t kinBin=GetKinBin(Sector);//if fHisbins is defined need to give this meaningful arguments
   //FillHistograms("Cut1",kinBin);
   //FillHistograms("Cut1",0);
   //Fill histograms for each species
   if(fWeights){
     if(fWeights->GetEntryBinarySearch(fgID)){
       StrIntMap_t spec=fWeights->GetSpecies();
       for(StrIntMap_t::iterator itss=spec.begin();itss!=spec.end();++itss)
   	 FillHistograms(itss->first,kinBin);
     }
   }


   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void sWeight_Plotting5::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void sWeight_Plotting5::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void sWeight_Plotting5::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
 //sWeights Histos
  fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass(GeV) "+sLabel,64,0.65,0.9)));
  // fOutput->Add(MapHist(new TH1F("MmissNW"+sLabel,"M_{miss}"+sLabel,64,0.65,0.9)));
  fOutput->Add(MapHist(new TH1F("MX"+sLabel,"Mass of X (GeV) "+sLabel,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXNW"+sLabel,"M_{X}"+sLabel,64,1.1,1.9)));
  fOutput->Add(MapHist(new TH1F("MOPiP"+sLabel,"Mass of #omega#pi^{+} (GeV) "+sLabel,64,0.9,1.6)));
  fOutput->Add(MapHist(new TH1F("MOPiM"+sLabel,"Mass of #omega#pi^{-} (GeV) "+sLabel,64,0.9,1.6)));
  // fOutput->Add(MapHist(new TH1F("MPiPPiM"+sLabel,"M_{#pi+,#pi-}"+sLabel,64,0.25,1.0)));

  //fOutput->Add(MapHist(new TH1F("MProton"+sLabel,"M_{Proton}"+sLabel,64,0.9,1)));
  //fOutput->Add(MapHist(new TH1F("MOmegaProton"+sLabel,"M_{#omega,Proton}"+sLabel,64,1.7,2.4)));
  fOutput->Add(MapHist(new TH1F("MPiPProton"+sLabel,"M_{#pi+,Proton} (GeV) "+sLabel,64,1.05,1.8)));
  fOutput->Add(MapHist(new TH1F("MPiMProton"+sLabel,"M_{#pi-,Proton} (GeV) "+sLabel,64,1.05,1.8)));
  //fOutput->Add(MapHist(new TH1F("MPiPPiMProton"+sLabel,"M_{#pi+,#pi-,Proton}"+sLabel,64,1.2,2.2)));

  fOutput->Add(MapHist(new TH1F("t"+sLabel,"t"+sLabel,64,0,4)));
  // fOutput->Add(MapHist(new TH1F("Egamma"+sLabel,"Egamma"+sLabel,64,2.1,4)));

  fOutput->Add(MapHist(new TH2F("MOPipVMX"+sLabel,"M_{#omega,p1} vs M_{X} (GeV)"+sLabel,40,0.9,1.5,40,1.1,1.9)));
  fOutput->Add(MapHist(new TH2F("MOPimVMX"+sLabel,"M_{#omega,m1} vs M_{X} (GeV)"+sLabel,40,0.9,1.5,40,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MPiPPiMVMX"+sLabel,"M_{p1m1} vs M_{X}"+sLabel,40,0.25,0.9,40,1.1,1.9)));

  // fOutput->Add(MapHist(new TH2F("MOPimVMOPip"+sLabel,"M_{#omega,#pi+} vs M_{#omega,#pi-}"+sLabel,40,0.9,1.5,40,0.9,1.5)));

   fOutput->Add(MapHist(new TH2F("MPiPProtonVMX"+sLabel,"M_{#pi+,Proton} vs M_{X} (GeV)"+sLabel,40,1.05,1.8,40,1.1,1.9)));
   fOutput->Add(MapHist(new TH2F("MPiMProtonVMX"+sLabel,"M_{#pi-,Proton} vs M_{X} (GeV)"+sLabel,40,1.05,1.8,40,1.1,1.9)));


  // fOutput->Add(MapHist(new TH2F("tVMX"+sLabel,"t vs M_{X}"+sLabel,40,0,4,40,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("tVMOmegaPiP"+sLabel,"t vs M_{#omega,#pi+}"+sLabel,40,0,4,40,0.9,1.6)));
  // fOutput->Add(MapHist(new TH2F("tVMOmegaPiM"+sLabel,"t vs M_{#omega,#pi-}"+sLabel,40,0,4,40,0.9,1.6)));

  //fOutput->Add(MapHist(new TH2F("EgammaVMX"+sLabel,"t vs M_{X}"+sLabel,40,2.1,3.9,40,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("EgammaVMOmegaPiP"+sLabel,"t vs M_{#omega,#pi+}"+sLabel,40,2.1,3.9,40,0.9,1.6)));
  //fOutput->Add(MapHist(new TH2F("EgammaVMOmegaPiM"+sLabel,"t vs M_{#omega,#pi-}"+sLabel,40,2.1,3.9,40,0.9,1.6)));

  //fOutput->Add(MapHist(new TH2F("MmissVMX"+sLabel,"M_{X} vs M_{Mmiss}"+sLabel,40,0.67,0.89,40,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MmissVMXNW"+sLabel,"M_{X} vs M_{Mmiss}"+sLabel,40,0.67,0.89,40,1.1,1.9)));

  //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void sWeight_Plotting5::FillHistograms(TString sCut,Int_t bin){
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
   // FindHist("MmissNW")->Fill(Mmiss);
   FindHist("MX")->Fill(MassX,Weight);
   // FindHist("MXNW")->Fill(MassX);
   FindHist("MOPiP")->Fill(MassOmegaPiP,Weight);
   FindHist("MOPiM")->Fill(MassOmegaPiM,Weight);
   //  FindHist("MPiPPiM")->Fill(MassPiPPiM,Weight);

   //FindHist("MProton")->Fill(MassProton,Weight);
   // FindHist("MOmegaProton")->Fill(MassOmegaProton,Weight);
   FindHist("MPiPProton")->Fill(MassPiPProton,Weight);
   FindHist("MPiMProton")->Fill(MassPiMProton,Weight);
   // FindHist("MPiPPiMProton")->Fill(MassPiPPiMProton,Weight);

   FindHist("t")->Fill(t,Weight);
   // FindHist("Egamma")->Fill(Egamma,Weight);
   
   ((TH2F*)FindHist("MOPipVMX"))->Fill(MassOmegaPiP,MassX,Weight);
   ((TH2F*)FindHist("MOPimVMX"))->Fill(MassOmegaPiM,MassX,Weight);
   // ((TH2F*)FindHist("MPiPPiMVMX"))->Fill(MassPiPPiM,MassX,Weight);
   // ((TH2F*)FindHist("MOPimVMOPip"))->Fill(MassOmegaPiM,MassOmegaPiP,Weight);
   
   ((TH2F*)FindHist("MPiPProtonVMX"))->Fill(MassPiPProton,MassX,Weight);
   ((TH2F*)FindHist("MPiMProtonVMX"))->Fill(MassPiMProton,MassX,Weight);

   // ((TH2F*)FindHist("tVMX"))->Fill(t,MassX,Weight);
   // ((TH2F*)FindHist("tVMOmegaPiP"))->Fill(t,MassOmegaPiP,Weight);
   // ((TH2F*)FindHist("tVMOmegaPiM"))->Fill(t,MassOmegaPiM,Weight);

   // ((TH2F*)FindHist("EgammaVMX"))->Fill(Egamma,MassX,Weight);
   // ((TH2F*)FindHist("EgammaVMOmegaPiP"))->Fill(Egamma,MassOmegaPiP,Weight);
   // ((TH2F*)FindHist("EgammaVMOmegaPiM"))->Fill(Egamma,MassOmegaPiM,Weight);

   // ((TH2F*)FindHist("MmissVMX"))->Fill(Mmiss,MassX,Weight);
   // ((TH2F*)FindHist("MmissVMXNW"))->Fill(Mmiss,MassX);
}
