
{
  gSystem->AddIncludePath("-I$HSANA/");
  gROOT->LoadMacro("$HSANA/THSBins.C+");
  gROOT->LoadMacro("$HSANA/THSWeights.C+");
  gROOT->LoadMacro("$HSANA/THSRooFit.C++");
  gROOT->LoadMacro("$HSANA/THSsPlot.C++");

  //THSsPlot* RF=new THSsPlot("Octp722TOp842FiveBinsMassXB1Cut120MeV");
  //THSsPlot* RF=new THSsPlot("Octp722TOp842FiveBinsMassXRhoCut100MeV");
  THSsPlot* RF=new THSsPlot("Decp692TOp872FiveBinsMassX100milReconCorr6MeV");

  //RF->SetOutDir("outBins/SBCompEgamma3p3to3p9");
  //RF->SetOutDir("outBins/OctBasic5BinsMassXRhoCut100MeV");
  //RF->SetOutDir("outBins/Novp722TOp842FiveBinsMassX16FilesRealData");
  RF->SetOutDir("outBins/Decp692TOp872FiveBinsMassX100milReconCorr6MeV");
  RF->SetBinnedFit(); //For parameter fits do binned chi2
  RF->SetSPlotRange(0.692,0.872); //Use a differnt range for sFit
 ///////////////////////////////Load Variables
  RF->LoadVariable("Mmiss[0.692,0.872]");//should be same name as variable in tree
  // RF->LoadBinVars("Egamma",1,3.3,3.9);//should be same name as variable in tree 
  RF->LoadBinVars("MassX",5,1.1,1.9);//should be same name as variable in tree 
  //RF->LoadBinVars("t",1,2,5);//should be same name as variable in tree
  //RF->LoadBinVars("MassOmegaPiM",1,1.18,1.28);
  // RF->LoadBinVars("MassOmegaPiP",1,1.18,1.28);

  /////////////////////////////Make Model Signal
  // RF->Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.782,0.75,0.8], SIMw[0.01,0.001,0.08] )");
  RF->LoadSpeciesPDF("Signal");

  ////////////////////////////////Additional background
  // RF->Factory("Chebychev::BG(Mmiss,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
  RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1],a2[0.015,-1,1]})");
  RF->LoadSpeciesPDF("BG");

   ///////////////////////////Load Data
  TChain chain("HSParticles");
  //chain.AddFile("Data.root");
  //chain.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root");
  //chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPS.root");
  //chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/Eta1295/600kEventsEta1295MissingOmega.root");
  //chain.Add("/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWCutData/Oct2017RhoCut100MeV.root");
  //chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_100mil/CorrectedPS100MilEventsOct2017.root");
  chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Version2_Processed_100mil/CorrectedPS100MilEventsDec2017v4.root");


  RF->SetIDBranchName("fgID");
  //import to RooFit
  RF->LoadDataSet(&chain);
  gBenchmark->Start("Binned");
  RF->RunWeights(4);//argument gives number of parameter fits to perform
  RF->DrawTreeVar("MassX",100,1.1,1.9);
  //RF->DrawTreeVar("M2",100,0,10);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");

  RF->GetWeights()->Save();

  //chain deleted so recreate for extra plots  
  //TChain chain2("MyModel");
  //chain2.AddFile("Data.root");
 


}
