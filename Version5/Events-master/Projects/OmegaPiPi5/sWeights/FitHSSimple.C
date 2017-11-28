
{
  // gInterpreter->AddIncludePath("$HSANA");
  gSystem->AddIncludePath("-I$HSANA/");
  gROOT->LoadMacro("$HSANA/THSBins.C++");
  gROOT->LoadMacro("$HSANA/THSWeights.C++");
  gROOT->LoadMacro("$HSANA/THSRooFit.C++");
 

  THSRooFit* RF=new THSRooFit("Simple");
  //THSRooFit* RF=new THSRooFit();
  // RF->SetOutDir("testSimple/");
  //RF->SetOutDir("/phys/linux/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/sWeights/WeightMaps/Version5Test/");
  RF->SetOutDir("WeightMaps/Version5Test");
  ///////////////////////////////Load Variables
  RF->LoadVariable("Mmiss[0.72,0.86]");//should be same name as variable in tree  
  RF->LoadAuxVars("Egamma[2,4]");//should be same name as variable in tree 
  // RF->LoadAuxVars("t[0,0.2]");//should be same name as variable in tree 

  /////////////////////////////Make Model Signal
  // RF->Factory("Gaussian::Signal( Mmiss, SIMm[0,-0.01,0.05], SIMw[0.001,0.0001,0.1] )");
  RF->Factory("Gaussian::Signal( Mmiss, SIMm[0.782,0.75,0.8], SIMw[0.01,0.001,0.08] )");
  RF->LoadSpeciesPDF("Signal");


  ////////////////////////////////Additional background
  // RF->Factory("Chebychev::BG(Mmiss,{a0[-0.8,-1,1],a1[-0.2,-1,1]})");
  RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1],a2[0.015,-1,1]})");
  //RF->Factory("Chebychev::BG(Mmiss,{a0[-0.39,-1,1],a1[-0.01,-1,1]})");
  RF->LoadSpeciesPDF("BG");

   ///////////////////////////Load Data
  TChain chain("HSParticles");
  //chain.AddFile("/home/dglazier/Dropbox/g11pipi/testfit/twopi_ppip_pmiss.root");
  chain.AddFile("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/batch1.root");
  RF->SetIDBranchName("fgID");
  //import to RooFit
  RF->LoadDataSet(&chain);
  gBenchmark->Start("Simple");
  RF->RunWeights();
  //RF->DrawTreeVar("MmissP",100,0.72,0.86);
  gBenchmark->Stop("Simple");
  gBenchmark->Print("Simple");

}
