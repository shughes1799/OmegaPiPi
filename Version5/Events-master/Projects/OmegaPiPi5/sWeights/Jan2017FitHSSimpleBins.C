
{
  gSystem->AddIncludePath("-I$HSANA/");
  gROOT->LoadMacro("$HSANA/THSBins.C+");
  gROOT->LoadMacro("$HSANA/THSWeights.C+");
  gROOT->LoadMacro("$HSANA/THSRooFit.C++");

  // THSRooFit* RF=new THSRooFit("binFit16Files5MassXBinsEgt3");
  THSRooFit* RF=new THSRooFit("Test16FilesLPS");
  // RF->SetOutDir("outBins/");
  RF->SetOutDir("WeightMaps/Jan2017matchSB1massbin");
  RF->SetBinnedFit(); //For parameter fits do binned chi2
  //RF->SetSPlotRange(0.75,0.82); //Use a differnt range for sFit
 ///////////////////////////////Load Variables
  // RF->LoadVariable("Mmiss[0,10]");//should be same name as variable in tree
  // RF->LoadBinVars("Eg",1,3,4);//should be same name as variable in tree 
  // RF->LoadBinVars("M1",4,0,10);//should be same name as variable in tree 

  //RF->LoadVariable("Mmiss[0.737,0.827]");//should be same name as variable in tree  
  RF->LoadVariable("Mmiss[0.692,0.872]");//should be same name as variable in tree  
  //RF->LoadBinVars("Egamma",1,2.5,4);//should be same name as variable in tree 
  RF->LoadBinVars("MassX",1,1.1,1.9);//should be same name as variable in tree 
  // RF->LoadBinVars("Sector",14,-0.5,13.5);

  /////////////////////////////Make Model Signal
  // RF->Factory("Gaussian::Signal( Mmiss, SIMm[6,4,7], SIMw[0.2,0.0001,3] )");
  RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.782,0.75,0.8], SIMw[0.01,0.001,0.08] )");
  RF->LoadSpeciesPDF("Signal");

  ////////////////////////////////Additional background
  // RF->Factory("Chebychev::BG(Mmiss,{a0[0.1,-0.4,0.4],a1[-0.1,-0.3,0.3]})");
  RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1],a2[0.015,-1,1]})");
  RF->LoadSpeciesPDF("BG");

   ///////////////////////////Load Data
  // TChain chain("MyModel");
  TChain chain("HSParticles");
  // chain.AddFile("Data.root");
  //chain.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root");
  //chain.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch2.root")
  // chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch*.root");
  // chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test.root");
  chain.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPS.root");
  RF->SetIDBranchName("fgID");
  //import to RooFit
  RF->LoadDataSet(&chain);
  gBenchmark->Start("Binned");
  RF->RunWithBins(10);//argument gives number of parameter fits to perform
  // RF->DrawTreeVar("M1",100,0,10);
  // RF->DrawTreeVar("M2",100,0,10);
  RF->DrawTreeVar("MassX",100,1.1,1.9);
  gBenchmark->Stop("Binned");
  gBenchmark->Print("Binned");
  RF->GetWeights()->Save();
  //chain deleted so recreate for extra plots  
  //TChain chain2("MyModel");
  // TChain chain2("HSParticles");
  // chain2.AddFile("Data.root");
  // chain2.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root");
  //chain2.Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch*.root");


}
