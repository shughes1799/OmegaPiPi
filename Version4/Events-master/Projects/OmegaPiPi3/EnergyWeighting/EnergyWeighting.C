#include <TH2.h>
void EnergyWeighting() {
  
  TFile *f = new TFile("EnergyWeighting1.root","RECREATE");
  TFile *RealDatafile = TFile::Open("/phys/linux/s0677668/Haspect/Version2/Events-master/Projects/PiPiOmega2/Plotting/Sideband4/SBPlots/SB4Plots4.root");
  
  TH1F *RealEnergySignalH = (TH1F*)EgammaSignal_All->Clone("RealEnergySignalH");
  TH1F *RealEnergySideH = (TH1F*)EgammaSide_All->Clone("RealEnergySideH");
  
  TFile *MCDatafile = TFile::Open("/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB10MilPSDecays1.root");
  
  TH1F *MCEnergySignalH = (TH1F*)EgammaSignal_All->Clone("MCEnergySignalH");
  TH1F *MCEnergySideH = (TH1F*)EgammaSide_All->Clone("MCEnergySideH");

  TH1F *EnergyWeightsSignalSB = new TH1F("EnergyWeightsSignalSB", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);
  TH1F *EnergyWeightsSideSB = new TH1F("EnergyWeightsSideSB", "Sideband subtracted Beam Energy; Beam Energy (GeV)", 100, 1.5, 4);
  
  

  //RealEnergyH.Divide(&MCEnergyH);
  *EnergyWeightsSignalSB = ((*RealEnergySignalH) / (*MCEnergySignalH));
  *EnergyWeightsSideSB = ((*RealEnergySideH) / (*MCEnergySideH));
  
  RealEnergySignalH->SetDirectory(f);
  RealEnergySideH->SetDirectory(f);
  MCEnergySignalH->SetDirectory(f);
  MCEnergySideH->SetDirectory(f);

  EnergyWeightsSignalSB->SetName("EnergyWeightsSignalSB");
  EnergyWeightsSideSB->SetName("EnergyWeightsSideSB");

  EnergyWeightsSignalSB->SetDirectory(f);
  EnergyWeightsSideSB->SetDirectory(f);
  
  f->Write();
  
}
