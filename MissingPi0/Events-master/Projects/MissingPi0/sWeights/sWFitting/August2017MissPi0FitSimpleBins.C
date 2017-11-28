
{
  gSystem->AddIncludePath("-I$HSANA/");
  gROOT->LoadMacro("$HSANA/THSBins.C+");
  gROOT->LoadMacro("$HSANA/THSWeights.C+");
  gROOT->LoadMacro("$HSANA/THSRooFit.C++");
  gROOT->LoadMacro("$HSANA/THSsPlot.C++");

  //THSsPlot* RF=new THSsPlot("Aug2017p065TOp300Basic3rdOrder");
  THSsPlot* RF=new THSsPlot("Aug2017IDFix");
  //RF->SetOutDir("outBins/SBCompEgamma3p3to3p9");
  //  RF->SetOutDir("Weights/Aug2017MissPi0Basic5BinsMassX");
  RF->SetOutDir("Weights/Aug2017IDFix");

  RF->SetBinnedFit(); //For parameter fits do binned chi2
  RF->SetSPlotRange(0.08,0.25); //Use a differnt range for sFit
 ///////////////////////////////Load Variables
  RF->LoadVariable("Mmiss[0.08,0.25]");//should be same name as variable in tree
  // RF->LoadBinVars("Egamma",1,3.3,3.9);//should be same name as variable in tree 
  // RF->LoadBinVars("MassX",5,1.1,1.9);//should be same name as variable in tree 
  RF->LoadBinVars("MassOmegaPiPi1",3,1.1,1.9);//should be same name as variable in tree 
  //RF->LoadBinVars("t",1,2,5);//should be same name as variable in tree
  //RF->LoadBinVars("MassOmegaPiM",1,1.16,1.30);

  /////////////////////////////Make Model Signal
  // RF->Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  // RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.782,0.75,0.8], SIMw[0.01,0.001,0.08] )");
  RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.135,0.12,0.15], SIMw[0.01,0.001,0.08] )");
  RF->LoadSpeciesPDF("Signal");

  ////////////////////////////////Additional background
  // RF->Factory("Chebychev::BG(Mmiss,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
  RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1],a2[0.015,-1,1]})");  //Third Order
  //RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1]})");  //Second Order
  // RF->Factory("Chebychev::BG(Mmiss,{a0[0,-1,1],a1[-0.01,-1,1],a2[0.0,-1,1],a3[0.0,-1,1]})");  //Fourth Order
  RF->LoadSpeciesPDF("BG");

   ///////////////////////////Load Data
  TChain chain("HSParticles");
  //chain.AddFile("Data.root");
  //chain.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root");
  // chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPS.root");
  //chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/Eta1295/600kEventsEta1295MissingOmega.root");
  chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/Corrected_Data/16FilesIDCorrMissingPi0.root");

  RF->SetIDBranchName("fgID");
  //import to RooFit
  RF->LoadDataSet(&chain);
  gBenchmark->Start("Binned");
  RF->RunWeights(4);//argument gives number of parameter fits to perform
  //RF->DrawTreeVar("MassX",100,1.1,1.9);
  RF->DrawTreeVar("MassOmega1",100,0.3,1.3);
  RF->DrawTreeVar("MassOmega2",100,0.3,1.3);
  RF->DrawTreeVar("MassOmega3",100,0.3,1.3);
  RF->DrawTreeVar("MassOmega4",100,0.3,1.3);
  RF->DrawTreeVar("MassOmegaPiPi1",100,1.1,1.9);
  RF->DrawTreeVar("MassOmegaPiPi2",100,1.1,1.9);
  RF->DrawTreeVar("MassOmegaPiPi3",100,1.1,1.9);
  RF->DrawTreeVar("MassOmegaPiPi4",100,1.1,1.9);
  //RF->DrawTreeVar("M2",100,0,10);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");

  RF->GetWeights()->Save();

  //chain deleted so recreate for extra plots  
  //TChain chain2("MyModel");
  //chain2.AddFile("Data.root");
 


}
