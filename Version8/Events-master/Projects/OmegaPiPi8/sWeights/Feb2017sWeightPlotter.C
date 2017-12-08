#define Feb2017sWeightPlotter_cxx
// The class definition in Feb2017sWeightPlotter.h has been generated automatically
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
// Root > T->Process("Feb2017sWeightPlotter.C")
// Root > T->Process("Feb2017sWeightPlotter.C","some options")
// Root > T->Process("Feb2017sWeightPlotter.C+")
//

#include "Feb2017sWeightPlotter.h"
#include <TH2.h>
#include <TH3.h>
#include <TStyle.h>


void Feb2017sWeightPlotter::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Feb2017sWeightPlotter::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
   //Get weights from file
   //Filename and object name should be passed via selector option
   TObjArray* OptList = option.Tokenize(":");
   if(OptList->GetEntries()>1){
     TString fname=((TObjString*)OptList->At(0))->String();
     TString wname=((TObjString*)OptList->At(1))->String();
     cout<<" SlaveBegin Opening weights "<<fname<<" "<<wname<<endl;

     fWeights=new THSWeights();
     fWeights->LoadSaved(fname,wname);
     cout<<"Printing WeightMap "<<endl;
     fWeights->PrintWeight();
   };
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

Bool_t Feb2017sWeightPlotter::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Feb2017sWeightPlotter::GetEntry() or TBranch::GetEntry()
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
   
   Int_t kinBin=0;//default to bins defined
   //Int_t kinBin=GetKinBin();//if fHisbins is defined need to give this meaningful arguments
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   //FillHistograms("Cut1",kinBin);
   //Fill histograms for each species
   // if(Egamma >= 2.7 && Egamma < 3.3){
   // if(t >= 2 && t < 5){
   // if(MassOmegaPiP >= 1.160 && MassOmegaPiP < 1.300){

   // if(MassX <= 1.82){
   if(Mmiss >= 0.722 && Mmiss < 0.842){
   //if(Mmiss >= 0.692 && Mmiss < 0.872){

       // if((MassOmegaPiP >= 1.16 && MassOmegaPiP < 1.30) || (MassOmegaPiM >= 1.16 && MassOmegaPiM < 1.30)){

       //if(MassPiPPiM >= 0.720 && MassPiPPiM < 0.820){



   if(fWeights){
     if(fWeights->GetEntryBinarySearch(fgID)){//find weight from fgID
       StrIntMap_t spec=fWeights->GetSpecies();
       for(StrIntMap_t::iterator itss=spec.begin();itss!=spec.end();++itss)
         FillHistograms(itss->first,kinBin);
     }
   }
   //  }
   //  }
     }
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void Feb2017sWeightPlotter::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Feb2017sWeightPlotter::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void Feb2017sWeightPlotter::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
  fOutput->Add(MapHist(new TH1F("MmissRecon"+sLabel,"Missing Mass (GeV) "+sLabel,180,0.69,0.87)));
  fOutput->Add(MapHist(new TH1F("MXRecon"+sLabel,"Mass of X (GeV) "+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MX100"+sLabel,"Mass of X (GeV) "+sLabel,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("t"+sLabel,"t distribution (GeV) "+sLabel,180,0,5)));
  // fOutput->Add(MapHist(new TH1F("Egamma"+sLabel,"Egamma distribution (GeV) "+sLabel,180,0,5)));

  // fOutput->Add(MapHist(new TH1F("MOmPiP"+sLabel,"MOmPiP"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiM"+sLabel,"MOmPiM"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiPMXCut"+sLabel,"MOmPiP MassX Cut"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiMMXCut"+sLabel,"MOmPiM MassX Cut"+sLabel,180,0.9,1.5)));

  // fOutput->Add(MapHist(new TH1F("MOmPiMt0to1"+sLabel,"MOmPiM0to1"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiMt1to2"+sLabel,"MOmPiM1to2"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiMt2to5"+sLabel,"MOmPiM2to5"+sLabel,180,0.9,1.5)));

  // fOutput->Add(MapHist(new TH1F("MOmPiMELow"+sLabel,"MOmPiM"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiMEMed"+sLabel,"MOmPiM"+sLabel,180,0.9,1.5)));
  // fOutput->Add(MapHist(new TH1F("MOmPiMEHigh"+sLabel,"MOmPiM"+sLabel,180,0.9,1.5)));

  // fOutput->Add(MapHist(new TH1F("MOmPiMt1to2EHigh"+sLabel,"MOmPiM, t1-2"+sLabel,180,0.9,1.5)));


  // fOutput->Add(MapHist(new TH1F("MXOmPiPCut"+sLabel,"Mass of X OmPiP Cut (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiPCutT0to1"+sLabel,"Mass of X OmPiP Cut, t0-1 (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiPCutT1to2"+sLabel,"Mass of X OmPiP Cut, t1-2 (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiPCutT2to5"+sLabel,"Mass of X OmPiP Cut, t2-5 (GeV)"+sLabel,180,1.1,1.9)));

  // fOutput->Add(MapHist(new TH1F("MXOmPiMCut"+sLabel,"Mass of X OmPiM Cut (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiMCutT0to1"+sLabel,"Mass of X OmPiM Cut, t0-1 (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiMCutT1to2"+sLabel,"Mass of X OmPiM Cut, t1-2 (GeV)"+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXOmPiMCutT2to5"+sLabel,"Mass of X OmPiM Cut, t2-5 (GeV)"+sLabel,180,1.1,1.9)));

  // fOutput->Add(MapHist(new TH1F("MProtonPiP"+sLabel,"MProtonPiP"+sLabel,180,1.05,1.8)));
  // fOutput->Add(MapHist(new TH1F("MProtonPiM"+sLabel,"MProtonPiM"+sLabel,180,1.05,1.8)));
  // fOutput->Add(MapHist(new TH1F("MXDeltaCut"+sLabel,"Mass of X Delta Cut (GeV)"+sLabel,180,1.1,1.9)));

  // fOutput->Add(MapHist(new TH1F("MXt0to1"+sLabel,"Mass of X, t0-1 (GeV) "+sLabel,180,1.1,1.9)));  
  // fOutput->Add(MapHist(new TH1F("MXt1to2"+sLabel,"Mass of X, t1-2 (GeV) "+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXt2to5"+sLabel,"Mass of X, t2-5 (GeV) "+sLabel,180,1.1,1.9)));

  // fOutput->Add(MapHist(new TH1F("MXE1p5to2p7"+sLabel,"Mass of X, Beam Energy 1.5-2.7 (GeV) "+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXE2p7to3p3"+sLabel,"Mass of X, Beam Energy 2.7-3.3 (GeV) "+sLabel,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MXE3p3to3p9"+sLabel,"Mass of X, Beam Energy 3.3-3.9 (GeV) "+sLabel,180,1.1,1.9)));

  // fOutput->Add(MapHist(new TH2F("tvsMX"+sLabel,"t vs MassX"+sLabel,100,0,4,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("EgammavsMX"+sLabel,"Beam Energy vs MassX"+sLabel,100,1.5,4,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MmissvsMX"+sLabel,"Mass #omega vs Mmiss(#omega#pi#pi)"+sLabel,120,0.722,0.842,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmvsMX"+sLabel,"Mass #omega vs MassX(#omega#pi#pi)"+sLabel,120,0.722,0.842,100,1.1,1.9)));

  //fOutput->Add(MapHist(new TH2F("MassOmPiPvsMX"+sLabel,"Mass #omega#pi^+ vs MassX(#omega#pi#pi)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MassOmPiMvsMX"+sLabel,"Mass #omega#pi^- vs MassX(#omega#pi#pi)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiPvst"+sLabel,"Mass #omega#pi^+ vs t"+sLabel,100,0.9,1.5,100,0,4)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiMvst"+sLabel,"Mass #omega#pi^- vs t"+sLabel,100,0.9,1.5,100,0,4)));

  // fOutput->Add(MapHist(new TH2F("MassOmPiPvsMXt0to1"+sLabel,"Mass #omega#pi^+ vs MassX(#omega#pi#pi) t(0-1)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiPvsMXt1to2"+sLabel,"Mass #omega#pi^+ vs MassX(#omega#pi#pi) t(1-2)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiPvsMXt2to5"+sLabel,"Mass #omega#pi^+ vs MassX(#omega#pi#pi) t(2-5)"+sLabel,100,0.9,1.5,100,1.1,1.9)));

  // fOutput->Add(MapHist(new TH2F("MassOmPiMvsMXt0to1"+sLabel,"Mass #omega#pi^- vs MassX(#omega#pi#pi) t(0-1)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiMvsMXt1to2"+sLabel,"Mass #omega#pi^- vs MassX(#omega#pi#pi) t(1-2)"+sLabel,100,0.9,1.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MassOmPiMvsMXt2to5"+sLabel,"Mass #omega#pi^- vs MassX(#omega#pi#pi) t(2-5)"+sLabel,100,0.9,1.5,100,1.1,1.9)));

 //October 2017
  fOutput->Add(MapHist(new TH2F("MassOmPiPvsMassOmPiM"+sLabel,"Mass #omega#pi^+ vs Mass #omega#pi^-"+sLabel,100,0.9,1.4,100,0.9,1.4)));
  fOutput->Add(MapHist(new TH2F("MassOmPiPvsMassOmPiMMassA2"+sLabel,"Mass #omega#pi^+ vs Mass #omega#pi^- MassA2 Cut"+sLabel,100,0.9,1.4,100,0.9,1.4)));
  fOutput->Add(MapHist(new TH2F("MassOmPiPvsMassOmPiMMassXCutHigh"+sLabel,"Mass #omega#pi^+ vs Mass #omega#pi^- MassX>1.5GeV Cut"+sLabel,100,0.9,1.4,100,0.9,1.4)));

  fOutput->Add(MapHist(new TH2F("MassOmPiPivsMassOmPiP"+sLabel,"Mass #omega#pi#pi vs Mass #omega#pi^+"+sLabel,100,1.1,1.8,100,0.9,1.4)));
  fOutput->Add(MapHist(new TH2F("MassOmPiPivsMassOmPiM"+sLabel,"Mass #omega#pi#pi vs Mass #omega#pi^-"+sLabel,100,1.1,1.8,100,0.9,1.4)));

  fOutput->Add(MapHist(new TH2F("Mass2OmPiPvsMass2OmPiM"+sLabel,"Mass^2 #omega#pi^+ vs Mass^2 #omega#pi^-"+sLabel,100,0.8,2.2,100,0.8,2.2)));
  fOutput->Add(MapHist(new TH2F("Mass2OmPiPivsMass2OmPiP"+sLabel,"Mass^2 #omega#pi#pi vs Mass^2 #omega#pi^+"+sLabel,100,1,3,100,0.8,2.2)));
  fOutput->Add(MapHist(new TH2F("Mass2OmPiPivsMass2OmPiM"+sLabel,"Mass^2 #omega#pi#pi vs Mass^2 #omega#pi^-"+sLabel,100,1,3,100,0.8,2.2)));


  //3D histograms
  fOutput->Add(MapHist(new TH3F("Mass2OmPiPvsMass2OmPiMvsT"+sLabel,"Mass^2 #omega#pi^+ vs Mass^2 #omega#pi^- vs t"+sLabel,100,0.8,2.2,100,0.8,2.2,100,0,5)));

 //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Feb2017sWeightPlotter::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());
   Double_t Weight=1;
   if(fWeights){
     if(fWeights->Size()>0)
       Weight=fWeights->GetWeight(sCut);
     if(fWeights->GotEntry()&&sCut==TString("All")) Weight=1;
     }
 //Find and fill weighted hist below here
 //e.g. FindHist("Mp1")->Fill(fp1->M(),Weight);
 //e.g. ((TH2F*)FindHist("Mp1VMmiss"))->Fill(fp1->M(),Mmiss,Weight);
   FindHist("MmissRecon")->Fill(Mmiss,Weight);
   FindHist("MXRecon")->Fill(MassX,Weight);
   // FindHist("MX100")->Fill(MassX,Weight);
   // FindHist("t")->Fill(t,Weight);
   // FindHist("Egamma")->Fill(Egamma,Weight);

   // FindHist("MOmPiP")->Fill(MassOmegaPiP,Weight);
   // FindHist("MOmPiM")->Fill(MassOmegaPiM,Weight);

   // if(MassOmegaPiP >= 1.155 && MassOmegaPiP < 1.305){    
   //   FindHist("MXOmPiPCut")->Fill(MassX,Weight);
   //   if(t >= 0 && t < 1){
   //     FindHist("MXOmPiPCutT0to1")->Fill(MassX,Weight);
   //   }
   //   if(t >= 1 && t < 2){
   //     FindHist("MXOmPiPCutT1to2")->Fill(MassX,Weight);
   //   }
   //   if(t >= 2 && t < 5){
   //     FindHist("MXOmPiPCutT2to5")->Fill(MassX,Weight);
   //   }
   // }
   // if(MassOmegaPiM >= 1.155 && MassOmegaPiM < 1.305){ 
   //   FindHist("MXOmPiMCut")->Fill(MassX,Weight);
   //   if(t >= 0 && t < 1){
   //     FindHist("MXOmPiMCutT0to1")->Fill(MassX,Weight);
   //   }
   //   if(t >= 1 && t < 2){
   //     FindHist("MXOmPiMCutT1to2")->Fill(MassX,Weight);
   //   }
   //   if(t >= 2 && t < 5){
   //     FindHist("MXOmPiMCutT2to5")->Fill(MassX,Weight);
   //   }
   // }

   // if(MassX >= 1.6 && MassX < 1.66){
   //   FindHist("MOmPiPMXCut")->Fill(MassOmegaPiP,Weight);
   //   FindHist("MOmPiMMXCut")->Fill(MassOmegaPiM,Weight);  
   // }

 


   // FindHist("MProtonPiP")->Fill(MassPiPProton,Weight);
   // FindHist("MProtonPiM")->Fill(MassPiMProton,Weight);

   // if(MassPiPProton <= 1.170 || MassPiPProton > 1.290){ 
   //   if(MassPiMProton <= 1.170 || MassPiMProton > 1.290){ 
   //     FindHist("MXDeltaCut")->Fill(MassX,Weight);
   //   }
   // }



   // ((TH2F*)FindHist("EgammavsMX"))->Fill(Egamma,MassX,Weight);
   // ((TH2F*)FindHist("tvsMX"))->Fill(t,MassX,Weight);
   // ((TH2F*)FindHist("MmissvsMX"))->Fill(Mmiss,MassX,Weight);
   // ((TH2F*)FindHist("MassOmvsMX"))->Fill(MassOmega,MassX,Weight);

   // ((TH2F*)FindHist("MassOmPiPvsMX"))->Fill(MassOmegaPiP,MassX,Weight);
   // ((TH2F*)FindHist("MassOmPiMvsMX"))->Fill(MassOmegaPiM,MassX,Weight);

   // ((TH2F*)FindHist("MassOmPiPvst"))->Fill(MassOmegaPiP,t,Weight);
   // ((TH2F*)FindHist("MassOmPiMvst"))->Fill(MassOmegaPiM,t,Weight);

   // if(t >= 0 && t < 1){
   //   //    ((TH2F*)FindHist("MassOmPiPvsMXt0to1"))->Fill(MassOmegaPiP,MassX,Weight);
   //   // ((TH2F*)FindHist("MassOmPiMvsMXt0to1"))->Fill(MassOmegaPiM,MassX,Weight);
   //   FindHist("MXt0to1")->Fill(MassX,Weight);
   //   // FindHist("MOmPiPt0to1")->Fill(MassOmegaPiP,Weight);
   //   FindHist("MOmPiMt0to1")->Fill(MassOmegaPiM,Weight);     
   // }
   // if(t >= 1 && t < 2){
   //   // ((TH2F*)FindHist("MassOmPiPvsMXt1to2"))->Fill(MassOmegaPiP,MassX,Weight);
   //   // ((TH2F*)FindHist("MassOmPiMvsMXt1to2"))->Fill(MassOmegaPiM,MassX,Weight);
   //   FindHist("MXt1to2")->Fill(MassX,Weight);
   //   // FindHist("MOmPiPt1to2")->Fill(MassOmegaPiP,Weight);
   //   FindHist("MOmPiMt1to2")->Fill(MassOmegaPiM,Weight);
   //   if(Egamma >= 3.3 && Egamma < 3.9){
   //     FindHist("MOmPiMt1to2EHigh")->Fill(MassOmegaPiM,Weight);
   //   }
   // }
   // if(t >= 2 && t < 5){
   //   // ((TH2F*)FindHist("MassOmPiPvsMXt2to5"))->Fill(MassOmegaPiP,MassX,Weight);
   //   // ((TH2F*)FindHist("MassOmPiMvsMXt2to5"))->Fill(MassOmegaPiM,MassX,Weight);
   //   FindHist("MXt2to5")->Fill(MassX,Weight);
   //   //FindHist("MOmPiPt2to5")->Fill(MassOmegaPiP,Weight);
   //   FindHist("MOmPiMt2to5")->Fill(MassOmegaPiM,Weight);
   // }

   // if(Egamma >= 1.5 && Egamma < 2.7){
   //   FindHist("MXE1p5to2p7")->Fill(MassX,Weight);
   //   FindHist("MOmPiMELow")->Fill(MassOmegaPiM,Weight);
   // }
   // if(Egamma >= 2.7 && Egamma < 3.3){
   //   FindHist("MXE2p7to3p3")->Fill(MassX,Weight);
   //   FindHist("MOmPiMEMed")->Fill(MassOmegaPiM,Weight);
   // }
   // if(Egamma >= 3.3 && Egamma < 3.9){
   //   FindHist("MXE3p3to3p9")->Fill(MassX,Weight);
   //   FindHist("MOmPiMEHigh")->Fill(MassOmegaPiM,Weight);
   // }

   //October 2017

   ((TH2F*)FindHist("MassOmPiPvsMassOmPiM"))->Fill(MassOmegaPiP,MassOmegaPiM,Weight);
   ((TH2F*)FindHist("Mass2OmPiPvsMass2OmPiM"))->Fill(Mass2OmegaPiP,Mass2OmegaPiM,Weight);

   // if(MassX >= 1.17 && MassX <= 1.47){
   //   ((TH2F*)FindHist("MassOmPiPvsMassOmPiMMassA2"))->Fill(MassOmegaPiP,MassOmegaPiM,Weight);
   // }

   // if(MassX >= 1.5){
   //   ((TH2F*)FindHist("MassOmPiPvsMassOmPiMMassXCutHigh"))->Fill(MassOmegaPiP,MassOmegaPiM,Weight);
   // }


   ((TH2F*)FindHist("MassOmPiPivsMassOmPiP"))->Fill(MassX,MassOmegaPiP,Weight);
   ((TH2F*)FindHist("MassOmPiPivsMassOmPiM"))->Fill(MassX,MassOmegaPiM,Weight);

   ((TH2F*)FindHist("Mass2OmPiPivsMass2OmPiP"))->Fill(Mass2X,Mass2OmegaPiP,Weight);
   ((TH2F*)FindHist("Mass2OmPiPivsMass2OmPiM"))->Fill(Mass2X,Mass2OmegaPiM,Weight);

   ((TH3F*)FindHist("Mass2OmPiPvsMass2OmPiMvsT"))->Fill(Mass2OmegaPiP,Mass2OmegaPiM,t,Weight);

}
