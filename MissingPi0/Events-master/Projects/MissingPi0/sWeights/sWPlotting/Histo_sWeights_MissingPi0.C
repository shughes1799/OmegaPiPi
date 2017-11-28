#define Histo_sWeights_MissingPi0_cxx
// The class definition in Histo_sWeights_MissingPi0.h has been generated automatically
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
// Root > T->Process("Histo_sWeights_MissingPi0.C")
// Root > T->Process("Histo_sWeights_MissingPi0.C","some options")
// Root > T->Process("Histo_sWeights_MissingPi0.C+")
//

#include "Histo_sWeights_MissingPi0.h"
#include <TH2.h>
#include <TStyle.h>


void Histo_sWeights_MissingPi0::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Histo_sWeights_MissingPi0::SlaveBegin(TTree * /*tree*/)
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

Bool_t Histo_sWeights_MissingPi0::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Histo_sWeights_MissingPi0::GetEntry() or TBranch::GetEntry()
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


   //Selection around the region that is weighted, selecting outside of this screws up the results.
   if(Mmiss >= 0.08 && Mmiss <= 0.25){
     
     //Selecting the closest candidate to an omega

     
     PickMassOmegaPiPi = MassOmegaPiPi1;
     
     MassDiff1 = TMath::Abs(MassOmega1-0.078265);
     MassDiff2 = TMath::Abs(MassOmega2-0.078265);
     MassDiff3 = TMath::Abs(MassOmega3-0.078265);
     MassDiff4 = TMath::Abs(MassOmega4-0.078265);
     
     PickMassDiff = MassDiff1;
     PickMassOmega = MassOmega1;
     
     if(MassDiff2 < PickMassDiff){
       PickMassOmegaPiPi = MassOmegaPiPi2;
       PickMassDiff = MassDiff2;
       PickMassOmega = MassOmega2;
     }
     if(MassDiff3 < PickMassDiff){
       PickMassOmegaPiPi = MassOmegaPiPi3;
       PickMassDiff = MassDiff3;
       PickMassOmega = MassOmega3;
     }
     if(MassDiff4 < PickMassDiff){
       PickMassOmegaPiPi = MassOmegaPiPi4;
       PickMassDiff = MassDiff4;
       PickMassOmega = MassOmega4;
     }
     
     

   // cout << "Mass Difference 2 " << MassDiff << endl;



   if(fWeights){
     if(fWeights->GetEntryBinarySearch(fgID)){//find weight from fgID
       StrIntMap_t spec=fWeights->GetSpecies();
       for(StrIntMap_t::iterator itss=spec.begin();itss!=spec.end();++itss)
         FillHistograms(itss->first,kinBin);
     }
   }
   
   }
   
   THSOutput::HSProcessFill(); 
   
   
   return kTRUE;
}

void Histo_sWeights_MissingPi0::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Histo_sWeights_MissingPi0::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void Histo_sWeights_MissingPi0::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
 fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass (GeV) "+sLabel,180,0.02,0.32)));
 fOutput->Add(MapHist(new TH1F("MassOmega1"+sLabel,"Mass of Omega1 (GeV) "+sLabel,180,0.3,1.3)));
 fOutput->Add(MapHist(new TH1F("MassOmega2"+sLabel,"Mass of Omega2 (GeV) "+sLabel,180,0.3,1.3)));
 fOutput->Add(MapHist(new TH1F("MassOmega3"+sLabel,"Mass of Omega3 (GeV) "+sLabel,180,0.3,1.3)));
 fOutput->Add(MapHist(new TH1F("MassOmega4"+sLabel,"Mass of Omega4 (GeV) "+sLabel,180,0.3,1.3)));
 fOutput->Add(MapHist(new TH1F("MassOmegaPiPi1"+sLabel,"Mass of OmegaPiPi1 (GeV) "+sLabel,180,1.1,1.9)));
 fOutput->Add(MapHist(new TH1F("MassOmegaPiPi2"+sLabel,"Mass of OmegaPiPi2 (GeV) "+sLabel,180,1.1,1.9)));
 fOutput->Add(MapHist(new TH1F("MassOmegaPiPi3"+sLabel,"Mass of OmegaPiPi3 (GeV) "+sLabel,180,1.1,1.9)));
 fOutput->Add(MapHist(new TH1F("MassOmegaPiPi4"+sLabel,"Mass of OmegaPiPi4 (GeV) "+sLabel,180,1.1,1.9)));
 fOutput->Add(MapHist(new TH1F("PickMassOmegaPiPi"+sLabel,"Pick Mass of OmegaPiPi (GeV) "+sLabel,180,1.1,1.9)));

  //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void Histo_sWeights_MissingPi0::FillHistograms(TString sCut,Int_t bin){
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
   FindHist("Mmiss")->Fill(Mmiss,Weight);
   FindHist("MassOmega1")->Fill(MassOmega1,Weight);
   FindHist("MassOmega2")->Fill(MassOmega2,Weight);
   FindHist("MassOmega3")->Fill(MassOmega3,Weight);
   FindHist("MassOmega4")->Fill(MassOmega4,Weight);
   
   if(MassOmega1  >= 0.73 && MassOmega1 <= 0.83){
     FindHist("MassOmegaPiPi1")->Fill(MassOmegaPiPi1,Weight);
   }
   if(MassOmega2  >= 0.73 && MassOmega2 <= 0.83){
     FindHist("MassOmegaPiPi2")->Fill(MassOmegaPiPi2,Weight);
   }
   if(MassOmega3  >= 0.73 && MassOmega3 <= 0.83){
     FindHist("MassOmegaPiPi3")->Fill(MassOmegaPiPi3,Weight);
   }
   if(MassOmega4  >= 0.73 && MassOmega4 <= 0.83){
     FindHist("MassOmegaPiPi4")->Fill(MassOmegaPiPi4,Weight);
   }
   if(PickMassOmega  >= 0.73 && PickMassOmega <= 0.83){
   FindHist("PickMassOmegaPiPi")->Fill(PickMassOmegaPiPi,Weight);
   }
}
