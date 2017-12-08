{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("HSParticles","datachain");
   // tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/April/RealData/FurtherExtendedTest4/batch*.root");
   // tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/April/GeneratedData/1milPhaseSpace/1MilFiltered.root");
   //tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/May/GeneratedData/1milPhaseSpace/g11_simon_centos610*.bos.evt.recsis.root");
   // tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/May/GeneratedData/1milA2Decays/A2Decays*.root");
   // tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/May/GeneratedData/10milPSDecays/PSTestFullPhiMissOmega1.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPS.root");  // IMPORTANT FILE
   // tree->Add("/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/May/GeneratedData/10milPSDecays/PSTestFullPhiMissOmega1.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/Eta1295/600kEventsEta1295MissingOmega.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/OmegaMassTest/16FilesNoOmegaMassCorrection.root");
   ///tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version8Data/CorrectedData/PhaseSpace10mil/PS10milCorrected.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_10mil/CorrectedPS10MilEventsOct2017.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_100mil/CorrectedPS100MilEventsOct2017.root");
   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Version2_Processed_100mil/CorrectedPS100MilEventsNoV2017v3.root");



   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   //  gSystem->Setenv("HSOUT",
   //		   "/phys/linux/s0677668/Haspect/Version2/Events-master/Projects/PiPiOmega2/Plotting/Sideband4/SBPlots/SB4MCPhaseSpacePlots1.root");
   //  gSystem->Setenv("HSOUT",
   //		   "/phys/linux/s0677668/Haspect/Version2/Events-master/Projects/PiPiOmega2/Plotting/Sideband4/SBPlots/SB4Elt3Plots2.root");
 // gSystem->Setenv("HSOUT",
 //		   "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB1MilPhaseSpace1.root");
   // gSystem->Setenv("HSOUT",
   //		   "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB1MilA2Decays1.root");
   gSystem->Setenv("HSOUT",
		   //   "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/SB10MilPSDecays3.root");
		   //		   "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/Feb2017NormPS10MilDataHalfWidthSB.root"); 
		   // "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017Eta1295MCDataT0to1.root");
		   // "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017BinnedT2to5MX1p25to1p33.root");
		   //"/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017BasicNoOmegaMassCorr.root");
		   //  "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017TwoDimSBEightBins.root");
		   //"/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017TwoDimSBTest2NoOmegaCorr.root");
		   //"/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/March2017ErrorTesting.root");
		   //		   "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/May2017ErrorBase180BinsDeltaCut.root");
		   //  "/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/May2017ErrorPhaseSpace10MilAccTest.root");
   //"/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/AcceptanceTestingPlots.root");
   //"/phys/linux/s0677668/Haspect/Version4/Events-master/Projects/OmegaPiPi3/Plotting/SBPlots/PostThesis/Aug2017Sig60SB30Gap20.root");
		   //  "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Oct2017PS10MilRecon.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Nov2017PS100MilRecon100Signal40SB.root");
		   //"/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Nov2017Data16Files100Signal40SB.root");
		   // "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Dec2017Data16Files100signal40SBCorr5MeV.root");
		   "/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Dec2017PS100MilRecon100Signal40SBCorr5MeV.root");

   
   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");

   tree->Process("SB5Selector.C++");

   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
