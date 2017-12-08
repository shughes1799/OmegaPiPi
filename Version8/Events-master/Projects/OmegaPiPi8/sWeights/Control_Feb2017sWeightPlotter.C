{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("HSParticles","datachain");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPS.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPSOct2017.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_100mil/CorrectedPS100MilEventsOct2017.root");
 tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Version2_Processed_100mil/CorrectedPS100MilEventsNoV2017v3.root");

   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/Eta1295/600kEventsEta1295MissingOmega.root");
   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   gSystem->Setenv("HSOUT",
		   // "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Feb2017SBCompT2to5WithCut.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Feb2017SBCompEgamma2p7to3p3WithCut.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Feb2017OmPiPB1Fit.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/March2017Eta1295MonteCarlo.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/March2017Basic10BinsMassX2.root");
		   //  "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/May2017Basic5BinsMassXVersionB1Stuff180Bins.root");
		   //  "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Oct2017/Oct2017Basic5BinsMassX.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Nov2017/Nov20175BinsMassX16FilesRealData.root");
		   // "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Nov2017/Nov20175BinsMassXPS100MilRecon.root");
   "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWPlots/Dec2017/Dec20175BinsMassXPS100MilReconCorr5MeV.root");


   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");

   //tree->Process("Test.C++","WEIGHTSFILEHERE.root:NameOfWeightsObject");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/BinTest2/WeightsbinFitTest2.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/SBCompT2to5/Weightsp722TOp842Gaus2ndOrderCheb.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/SBCompEgamma2p7to3p3/Weightsp722TOp842Gaus2ndOrderCheb.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/Eta1295MonteCarlo/Weightsp722TOp842Gaus2ndOrderCheb.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/phys/linux/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/sWeights/WeightMaps/TestLPS5/WeightsLPS.root");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/Basic10BinsMassX/Weightsp722TOp842Gaus2ndOrderCheb10BinsMassX.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/OctBasic5BinsMassXB1Cut140MeV/WeightsOctp722TOp842FiveBinsMassXB1Cut140MeV.root:WeightMap");
   // tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/Octp722TOp842FiveBinsMassXPhaseSpaceMC100mil/WeightsOctp722TOp842FiveBinsMassXPhaseSpaceMC100mil.root:WeightMap");
   //tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/Novp722TOp842FiveBinsMassX16FilesRealData/WeightsNovp722TOp842FiveBinsMassX16FilesRealData.root:WeightMap");
tree->Process("Feb2017sWeightPlotter.C++","/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/outBins/Decp692TOp872FiveBinsMassX100milRecon/WeightsDecp692TOp872FiveBinsMassX100milRecon.root:WeightMap");

   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
