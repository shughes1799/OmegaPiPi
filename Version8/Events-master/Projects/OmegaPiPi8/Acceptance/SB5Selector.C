#define SB5Selector_cxx
// The class definition in SB5Selector.h has been generated automatically
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
// Root > T->Process("SB5Selector.C")
// Root > T->Process("SB5Selector.C","some options")
// Root > T->Process("SB5Selector.C+")
//

#include "SB5Selector.h"
#include <TH2.h>
#include <TStyle.h>


void SB5Selector::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void SB5Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);
  //if you want kinematic bins you must define fHisbins here
   //fHisbins=new TH*()
   if(fHisbins) fOutput->Add(fHisbins);
   //fHisbins->SetXTitle();//give useful axis name
   //fHisbins->SetYTitle();//give useful axis name
   THSHisto::ChangeNames();
   THSHisto::LoadCut("Signal");
   THSHisto::LoadCut("Side");
   THSHisto::LoadCut("Left");
   THSHisto::LoadCut("Right");
   THSHisto::LoadCut("SigAndSide");
   THSHisto::LoadCut("All");

   // THSHisto::LoadCut("All");
   // THSHisto::LoadCut("Signal1");
   // THSHisto::LoadCut("Side1");
   // THSHisto::LoadCut("Left1");
   // THSHisto::LoadCut("Right1");
  
   
   // THSHisto::LoadCut("Signal2");
   // THSHisto::LoadCut("Side2");
   // THSHisto::LoadCut("Left2");
   // THSHisto::LoadCut("Right2");

   // THSHisto::LoadCut("Signal3");
   // THSHisto::LoadCut("Side3");
   // THSHisto::LoadCut("Left3");
   // THSHisto::LoadCut("Right3");

   // THSHisto::LoadCut("Signal4");
   // THSHisto::LoadCut("Side4");
   // THSHisto::LoadCut("Left4");
   // THSHisto::LoadCut("Right4");

   // THSHisto::LoadCut("Signal5");
   // THSHisto::LoadCut("Side5");
   // THSHisto::LoadCut("Left5");
   // THSHisto::LoadCut("Right5");

   // THSHisto::LoadCut("Signal6");
   // THSHisto::LoadCut("Side6");
   // THSHisto::LoadCut("Left6");
   // THSHisto::LoadCut("Right6");

   // THSHisto::LoadCut("Signal7");
   // THSHisto::LoadCut("Side7");
   // THSHisto::LoadCut("Left7");
   // THSHisto::LoadCut("Right7");

   // THSHisto::LoadCut("Signal8");
   // THSHisto::LoadCut("Side8");
   // THSHisto::LoadCut("Left8");
   // THSHisto::LoadCut("Right8");


   THSHisto::LoadHistograms();

   //Energy Weighting code, flawed currently
   //WeightingFile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/EnergyWeighting/EnergyWeighting1.root");
   // TH1F *EgammaSB = new TH1F("EgammaSB", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);
   // TH1F *EWSignal = new TH1F("EWSignal", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);
   // EWSignal = (TH1F*)WeightingFile->Get("EnergyWeightsSignalSB");
   // EWSide = (TH1F*)WeightingFile->Get("EnergyWeightsSideSB");

   //Loading histograms for weighting
   // TFile *Weightingfile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/EnergyWeighting/EnergyWeighting1.root");

}

Bool_t SB5Selector::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either SB5Selector::GetEntry() or TBranch::GetEntry()
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

   // Double_t NumberOfBins = 100;
   // Double_t MaxValue = 4;
   // Double_t MinValue = 1.5;

   // Int_t WeightBin = ((Egamma/NumberOfBins)*(MaxValue-MinValue))+((MaxValue-MinValue)/NumberOfBins); 

   // Double_t SignalEnergyWeight = EnergyWeightsSignalSB->GetBinContent(WeightBin);
   // Double_t SideEnergyWeight = EnergyWeightsSideSB->GetBinContent(WeightBin);

   // EnergyWeightingSignal(Egamma);   //Weighting for the Signal Events to match the energy spread of the real data, flawed currently.
   // EnergyWeightingSide(Egamma);     //Weighting for the Side Events to match the energy spread of the real data, flawed currently.


   // Old Sideband Selections
  
   //Delta Selections
   // if(MassPiPProton <= 1.170 || MassPiPProton > 1.290 ){
   //  if(MassPiMProton <= 1.170 || MassPiMProton > 1.290 ){

   //1675 Meson Selection with a rho. Rho mass = 0.77549  width = 0.1462 in pdg
   // if(MassPiPPiM >= 0.700 && MassPiPPiM < 0.850){ 
     
   //if(t >= 0 && t < 1){
   //if(Egamma >= 3.3 && Egamma < 3.9){
   //if(MassX >= 1.25 && MassX <1.33){
       
   if(Mmiss >= 0.722 && Mmiss < 0.752){   // 30 width sideband
   //if(Mmiss >= 0.692 && Mmiss < 0.732){ //40 width sideband
     FillHistograms("Side",0);
     FillHistograms("Left",0);
     FillHistograms("SigAndSide",0);
   }
   if(Mmiss >= 0.752 && Mmiss < 0.812){  //60 width signal
   //if(Mmiss >= 0.732 && Mmiss < 0.832){ //100 width signal
     FillHistograms("Signal",0);
     FillHistograms("SigAndSide",0);
   }
   if(Mmiss >= 0.812 && Mmiss < 0.842){ //30 width sideband
   //if(Mmiss >= 0.832 && Mmiss < 0.872){ //40 width sideband
     FillHistograms("Side",0);
     FillHistograms("Right",0);
     FillHistograms("SigAndSide",0);
   }
   
       // }
   //  }
   // }



   FillHistograms("All",0);

     //New Mass X binned sideband selections

   //Mass X Bin 1 looking around the A2 Peak

   // if (MassX >= 1.1 && MassX < 1.26){   //Width in MassX of the first bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side1",0);
//        FillHistograms("Left1",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal1",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side1",0);
//        FillHistograms("Right1",0);
//      }
//    }
//    if (MassX >= 1.26 && MassX < 1.34){   //Width in MassX of the second bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side2",0);
//        FillHistograms("Left2",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal2",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side2",0);
//        FillHistograms("Right2",0);
//      }
//    }
//    if (MassX >= 1.34 && MassX < 1.42){   //Width in MassX of the third bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side3",0);
//        FillHistograms("Left3",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal3",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side3",0);
//        FillHistograms("Right3",0);
//      }
//    }
//  if (MassX >= 1.42 && MassX < 1.50){   //Width in MassX of the fourth bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side4",0);
//        FillHistograms("Left4",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal4",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side4",0);
//        FillHistograms("Right4",0);
//      }
//    }
//  if (MassX >= 1.50 && MassX < 1.58){   //Width in MassX of the fifth bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side5",0);
//        FillHistograms("Left5",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal5",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side5",0);
//        FillHistograms("Right5",0);
//      }
//    }
// if (MassX >= 1.58 && MassX < 1.66){   //Width in MassX of the sixth bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side6",0);
//        FillHistograms("Left6",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal6",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side6",0);
//        FillHistograms("Right6",0);
//      }
//    }
// if (MassX >= 1.66 && MassX < 1.74){   //Width in MassX of the seventh bin
//      if(Mmiss >= 0.692 && Mmiss < 0.752){
//        FillHistograms("Side7",0);
//        FillHistograms("Left7",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal7",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side7",0);
//        FillHistograms("Right7",0);
//      }
//    }
// if (MassX >= 1.74 && MassX < 1.90){   //Width in MassX of the eighth bin
//      if(Mmiss >= 0.722 && Mmiss < 0.752){
//        FillHistograms("Side8",0);
//        FillHistograms("Left8",0);
//      }
//      if(Mmiss >= 0.752 && Mmiss < 0.812){
//        FillHistograms("Signal8",0);
       
//      }
//      if(Mmiss >= 0.812 && Mmiss < 0.842){
//        FillHistograms("Side8",0);
//        FillHistograms("Right8",0);
//      }
//    }





   //FillHistograms("All",0);
   
   //EnterKinBinList(kinBin,entry);//save evente in kinematic bins entry lists
   THSOutput::HSProcessFill(); 
   

   return kTRUE;
}

void SB5Selector::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void SB5Selector::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}
void SB5Selector::HistogramList(TString sLabel){
  TDirectory::AddDirectory(kFALSE); //do not add to current directory
  //now define all histograms and add to Output
  //label includes kinematic bin and additional cut name
  // e.g fOutput->Add(MapHist(new TH1F("Mp1"+sLabel,"M_{p1}"+sLabel,100,0,2)));
  // fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass"+sLabel,100,0.68,0.88)));
  // fOutput->Add(MapHist(new TH1F("MX"+sLabel,"M_{X}"+sLabel,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("ThetaX"+sLabel,"Theta_{X}"+sLabel,100,0,30)));
  // fOutput->Add(MapHist(new TH1F("PhiX"+sLabel,"Phi_{X}"+sLabel,100,-180,180)));
  // fOutput->Add(MapHist(new TH1F("Egamma"+sLabel,"Beam Energy"+sLabel,100,1.5,4)));
  // fOutput->Add(MapHist(new TH1F("t"+sLabel,"t"+sLabel,100,0,4)));
  // fOutput->Add(MapHist(new TH1F("s"+sLabel,"s"+sLabel,100,4,8.5)));
  // fOutput->Add(MapHist(new TH1F("AngleBeamFXandOmegaLab"+sLabel,"AngleBeamFXandOmegaLab"+sLabel,100,0,90)));
  // fOutput->Add(MapHist(new TH1F("AngleMesonXLabandOmegaFX"+sLabel,"AngleMesonXLabandOmegaFX"+sLabel,100,0,180)));

  // fOutput->Add(MapHist(new TH1F("MOmPro"+sLabel,"MOmPro"+sLabel,100,1.7,2.5)));
  //fOutput->Add(MapHist(new TH1F("MOmPiP"+sLabel,"MOmPiP"+sLabel,100,0.8,1.7)));
  //fOutput->Add(MapHist(new TH1F("MOmPiM"+sLabel,"MOmPiM"+sLabel,100,0.8,1.7)));;
  // fOutput->Add(MapHist(new TH1F("MPiPPro"+sLabel,"MPiPPro"+sLabel,100,1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MPiMPro"+sLabel,"MPiMPro"+sLabel,100,1,1.9)));
  // fOutput->Add(MapHist(new TH1F("MPiPPiM"+sLabel,"MPiPPiM"+sLabel,100,0.2,1.1)));
  // fOutput->Add(MapHist(new TH1F("MPiPPiMPro"+sLabel,"MPiPPiMPro"+sLabel,100,1.2,2.1)));
 
  // //fOutput->Add(MapHist(new TH1F(""+sLabel,""+sLabel,100,0,3)));
  
  // fOutput->Add(MapHist(new TH2F("ThetaXvsMX"+sLabel,"Theta_{X} vs MassX"+sLabel,100,0,30,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("PhiXvsMX"+sLabel,"Phi_{X} vs MassX"+sLabel,100,-180,180,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("EgammavsMX"+sLabel,"Beam Energy vs MassX"+sLabel,100,1.5,4,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("tvsMX"+sLabel,"t vs MassX"+sLabel,100,0,3,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("svsMX"+sLabel,"s vs MassX"+sLabel,100,4,8.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("AngleBeamFXandOmegaLabvsMX"+sLabel,"AngleBeamFXandOmegaLabvsMX vs MassX"+sLabel,100,0,90,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("AngleMesonXLabandOmegaFXvsMX"+sLabel,"AngleMesonXLabandOmegaFXvsMX vs MassX"+sLabel,100,0,180,100,1.1,1.9)));

  // fOutput->Add(MapHist(new TH2F("MOmProvsMX"+sLabel,"Mass_{OmegaPro} vs MassX;Mass_{OmegaPro};MassX"+sLabel,100,1.7,2.5,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MOmPiPvsMX"+sLabel,"Mass_{OmegaPiP} vs MassX;Mass_{OmegaPiP};MassX"+sLabel,100,0.8,1.7,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MOmPiMvsMX"+sLabel,"Mass_{OmegaPiM} vs MassX;Mass_{OmegaPiM};MassX"+sLabel,100,0.8,1.7,100,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MPiPProvsMX"+sLabel,"Mass_{PiPPro} vs MassX;Mass_{PiPPro};MassX"+sLabel,100,1,1.9,100,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MPiMProvsMX"+sLabel,"Mass_{PiMPro} vs MassX;Mass_{PiMPro};MassX"+sLabel,100,1,1.9,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MPiPPiMvsMX"+sLabel,"Mass_{PiPPiM} vs MassX;Mass_{PiPPiM};MassX"+sLabel,100,0.2,1.1,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MPiPPiMProvsMX"+sLabel,"Mass_{PiPPiMPro} vs MassX;Mass_{PiPPiM};MassX"+sLabel,100,1.2,2.1,100,1.1,1.9)));

  //Dec 2016 Histos
  // fOutput->Add(MapHist(new TH2F("MOmvsMX"+sLabel,"Mass_{Omega} vs MassX;Mass_{Omega};MassX"+sLabel,120,0.722,0.842,180,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MOmvsMXWide"+sLabel,"Mass_{Omega} vs MassX;Mass_{Omega};MassX"+sLabel,180,0.692,0.872,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MOmvsMXNarrowBin"+sLabel,"Mass_{Omega} vs MassX;Mass_{Omega};MassX"+sLabel,10,0.722,0.842,100,1.1,1.9)));
  //fOutput->Add(MapHist(new TH2F("MXvsMOm"+sLabel,"MassX vs Mass_{Omega};MassX;Mass_{Omega}"+sLabel,100,1.1,1.9,100,0.69,0.88)));

  //fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass"+sLabel,180,0.692,0.872)));
  fOutput->Add(MapHist(new TH1F("Mmiss"+sLabel,"Missing Mass"+sLabel,180,0.692,0.872)));

  //fOutput->Add(MapHist(new TH1F("MXFull"+sLabel,"M_{X}"+sLabel,180,1.1,1.9)));
  fOutput->Add(MapHist(new TH1F("MXFull"+sLabel,"M_{X}"+sLabel,180,1.1,1.9)));
  //fOutput->Add(MapHist(new TH1F("MX"+sLabel,"M_{X}"+sLabel,50,1.22,1.42)));

  //fOutput->Add(MapHist(new TH1F("MPiPPro"+sLabel,"MPiPPro"+sLabel,180,1.05,1.8)));
  //fOutput->Add(MapHist(new TH1F("MPiMPro"+sLabel,"MPiMPro"+sLabel,180,1.05,1.8)));

  // fOutput->Add(MapHist(new TH2F("MPiPProvsMX"+sLabel,"Mass_{PiPPro} vs MassX;Mass_{PiPPro};MassX"+sLabel,100,1,1.9,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("MPiMProvsMX"+sLabel,"Mass_{PiMPro} vs MassX;Mass_{PiMPro};MassX"+sLabel,100,1,1.9,100,1.1,1.9)));

  // fOutput->Add(MapHist(new TH2F("MPiPProvsMOm"+sLabel,"Mass_{PiPPro} vs Mass #omega;Mass_{PiPPro};Mass #omega"+sLabel,100,1,1.9,100,0.692,0.872)));
  // fOutput->Add(MapHist(new TH2F("MPiMProvsMOm"+sLabel,"Mass_{PiMPro} vs Mass #omega;Mass_{PiMPro};Mass #omega"+sLabel,100,1,1.9,100,0.692,0.872)));

  //Jan 2017

 
  // fOutput->Add(MapHist(new TH1F("t"+sLabel,"t"+sLabel,100,0,4)));

  // fOutput->Add(MapHist(new TH2F("MPiPPiMvsMX"+sLabel,"Mass_{PiPPiM} vs MassX;Mass_{PiPPiM};MassX"+sLabel,100,0.2,1.1,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("tvsMX"+sLabel,"t vs MassX"+sLabel,100,0,3,100,1.1,1.9)));

  //Weighted Hisograms
  // fOutput->Add(MapHist(new TH1F("MXWeight"+sLabel,"M_{X}"+sLabel,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH1F("EgammaWeight"+sLabel,"Beam Energy"+sLabel,100,1.5,4)));

  //Feb 2017
  // fOutput->Add(MapHist(new TH1F("Egamma"+sLabel,"Beam Energy"+sLabel,100,1.5,4)));
  // fOutput->Add(MapHist(new TH1F("t"+sLabel,"t"+sLabel,100,0,4)));

  //fOutput->Add(MapHist(new TH1F("MOmPiP"+sLabel,"MOmPiP"+sLabel,180,0.9,1.5)));
  //fOutput->Add(MapHist(new TH1F("MOmPiM"+sLabel,"MOmPiM"+sLabel,180,0.9,1.5)));

  // fOutput->Add(MapHist(new TH2F("tvsMX"+sLabel,"t vs MassX"+sLabel,100,0,4,100,1.1,1.9)));
  // fOutput->Add(MapHist(new TH2F("EgammavsMX"+sLabel,"Beam Energy vs MassX"+sLabel,100,1.5,4,100,1.1,1.9)));

  // //March 2017
  // fOutput->Add(MapHist(new TH1F("MPiPPiM"+sLabel,"MPiPPiM"+sLabel,100,0.2,1)));
  // fOutput->Add(MapHist(new TH1F("MOmega"+sLabel,"MOmega"+sLabel,100,0.2,2)));



  //end of histogram list
  TDirectory::AddDirectory(kTRUE); //back to normal
}
void SB5Selector::FillHistograms(TString sCut,Int_t bin){
  fCurrCut=sCut;
  fCurrBin=bin;
  //Get histogram from list
  //Fill histogram
  // e.g. FindHist("Mp1")->Fill(fp1->M());
  // FindHist("Mmiss")->Fill(Mmiss);
  // FindHist("MX")->Fill(MassX);
  // FindHist("ThetaX")->Fill(ThetaX);
  // FindHist("PhiX")->Fill(PhiX);
  // FindHist("Egamma")->Fill(Egamma);
  // FindHist("t")->Fill(t);
  // FindHist("s")->Fill(s);
  // FindHist("AngleBeamFXandOmegaLab")->Fill(AngleBeamFXandOmegaLab);
  // FindHist("AngleMesonXLabandOmegaFX")->Fill(AngleMesonXLabandOmegaFX);

  // FindHist("MOmPro")->Fill(MassOmegaProton);
  // FindHist("MOmPiP")->Fill(MassOmegaPiP);
  // FindHist("MOmPiM")->Fill(MassOmegaPiM);
  // FindHist("MPiPPro")->Fill(MassPiPProton);
  // FindHist("MPiMPro")->Fill(MassPiMProton);
  // FindHist("MPiPPiM")->Fill(MassPiPPiM);
  // FindHist("MPiPPiMPro")->Fill(MassPiPPiMProton);

  // FindHist("PhiXvsMX")->Fill(PhiX,MassX);
  // FindHist("ThetaXvsMX")->Fill(ThetaX,MassX);
  // FindHist("EgammavsMX")->Fill(Egamma,MassX);
  // FindHist("tvsMX")->Fill(t,MassX);
  // FindHist("svsMX")->Fill(s,MassX);
  // FindHist("AngleBeamFXandOmegaLabvsMX")->Fill(AngleBeamFXandOmegaLab,MassX);
  // FindHist("AngleMesonXLabandOmegaFXvsMX")->Fill(AngleMesonXLabandOmegaFX,MassX);

  // FindHist("MOmProvsMX")->Fill(MassOmegaProton,MassX);
  // FindHist("MOmPiPvsMX")->Fill(MassOmegaPiP,MassX);
  // FindHist("MOmPiMvsMX")->Fill(MassOmegaPiM,MassX);
  // FindHist("MPiPProvsMX")->Fill(MassPiPProton,MassX);
  // FindHist("MPiMProvsMX")->Fill(MassPiMProton,MassX);
  // FindHist("MPiPPiMvsMX")->Fill(MassPiPPiM,MassX);
  // FindHist("MPiPPiMProvsMX")->Fill(MassPiPPiMProton,MassX);


  // Dec 2016
  // FindHist("MOmvsMX")->Fill(Mmiss,MassX);
  // FindHist("MOmvsMXWide")->Fill(Mmiss,MassX);
  // FindHist("MOmvsMXNarrowBin")->Fill(Mmiss,MassX);
  //FindHist("MXvsMOm")->Fill(MassX,Mmiss);

  //  FindHist("Mmiss")->Fill(Mmiss);
  //FindHist("MXFull")->Fill(MassX);

  FindHist("Mmiss")->Fill(Mmiss);
  FindHist("MXFull")->Fill(MassX);
  
  //FindHist("MX")->Fill(MassX);

  // FindHist("MPiPPro")->Fill(MassPiPProton);
  // FindHist("MPiMPro")->Fill(MassPiMProton);

  // FindHist("MPiPProvsMX")->Fill(MassPiPProton,MassX);
  // FindHist("MPiMProvsMX")->Fill(MassPiMProton,MassX);

  // FindHist("MPiPProvsMOm")->Fill(MassPiPProton,Mmiss);
  // FindHist("MPiMProvsMOm")->Fill(MassPiMProton,Mmiss);

  //Jan 2017

  //FindHist("MPiPPiM")->Fill(MassPiPPiM);
  // FindHist("t")->Fill(t);

  // FindHist("tvsMX")->Fill(t,MassX);
  // FindHist("MPiPPiMvsMX")->Fill(MassPiPPiM,MassX);
 
  // if(Mmiss >= 0.69 && Mmiss < 0.75){
  //   FindHist("MXWeight")->Fill(MassX,SideEnergyWeight);
  //   FindHist("EgammaWeight")->Fill(Egamma,SideEnergyWeight);
  // }
  // if(Mmiss >= 0.75 && Mmiss < 0.81){
  //   FindHist("MXWeight")->Fill(MassX,SignalEnergyWeight);
  //   FindHist("EgammaWeight")->Fill(Egamma,SignalEnergyWeight);  
  // }
  // if(Mmiss >= 0.81 && Mmiss < 0.87){
  //   FindHist("MXWeight")->Fill(MassX,SideEnergyWeight);
  //   FindHist("EgammaWeight")->Fill(Egamma,SideEnergyWeight);
  // }

  //Feb2017

  // FindHist("Egamma")->Fill(Egamma);
  // FindHist("t")->Fill(t);
  // FindHist("MOmPiP")->Fill(MassOmegaPiP);
  // FindHist("MOmPiM")->Fill(MassOmegaPiM);

  // FindHist("EgammavsMX")->Fill(Egamma,MassX);
  // FindHist("tvsMX")->Fill(t,MassX);

  // //March2017
  // FindHist("MOmega")->Fill(MassOmega);
  
}

Double_t SB5Selector::EnergyWeightingSignal(Double_t SigEW){
  
  Double_t NumberOfBins = 100;
  Double_t MaxValue = 4;
  Double_t MinValue = 1.5;
  
  // Int_t WeightBin = ((SigEW/NumberOfBins)*(MaxValue-MinValue))+((MaxValue-MinValue)/NumberOfBins); 
  // Int_t WeightBin = EnergyWeightSignalSB->FindBin(SigEW);
  
  // EWSignal = (TH1F*)WeightingFile.Get(EnergyWeightsSignalSB);

  Int_t WeightBin = EWSignal->FindBin(SigEW);

  SignalEnergyWeight = EWSignal->GetBinContent(WeightBin);
  
  return SignalEnergyWeight;
}

Double_t SB5Selector::EnergyWeightingSide(Double_t SideEW){
  
  Double_t NumberOfBins2 = 100;
  Double_t MaxValue2 = 4;
  Double_t MinValue2 = 1.5;
  
  // Int_t WeightBin = ((SigEW/NumberOfBins)*(MaxValue-MinValue))+((MaxValue-MinValue)/NumberOfBins); 
  // Int_t WeightBin = EnergyWeightSignalSB->FindBin(SigEW);
  
  // EWSignal = (TH1F*)WeightingFile.Get(EnergyWeightsSignalSB);

  Int_t WeightBin2 = EWSide->FindBin(SideEW);

  SideEnergyWeight = EWSide->GetBinContent(WeightBin2);
  
  return SideEnergyWeight;
}



// TFile *Weightingfile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/EnergyWeighting/EnergyWeighting1.root");

// Double_t SignalWeight = EnergyWeightsSignalSB->GetBinContent(j);
// Double_t SideWeight = EnergyWeightsSideSB->GetBinContent(j);
