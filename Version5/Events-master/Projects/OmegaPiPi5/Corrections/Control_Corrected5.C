{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("HSParticles","datachain");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/May16filesMissingOmega/batch1.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/Feb2017Eta1295MissingOmega600k.root");
   //tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/May16filesMissingOmega/batch*.root");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version8Data/1stStageProcessedDatafiles/PS10mil/FullStatsPS10mil.root");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_100mil/PS100MilEventsOct2017.root");
   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Version2_Processed_100mil/PS100MilEventsNoV2017.root");



   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   gSystem->Setenv("HSOUT",
		   // "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/test2.root");
		   // "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPSTestJan2017.root");
		   //"/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/Eta1295/600kEventsEta1295MissingOmega.root");
		   //"/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/OmegaMassTest/16FilesNoOmegaMassCorrection.root");
		   //		   "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version8Data/CorrectedData/PhaseSpace10mil/PS10milCorrected.root");
		   // "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Processed_100mil/CorrectedPS100MilEventsOct2017.root");
		   //"/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/CorrectedData/16FilesID/Test16FilesLPSOct2017.root");
		   "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/August2017/Phase_Space_Flat_100mil/Version2_Processed_100mil/CorrectedPS100MilEventsNoV2017v3.root");

   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kTRUE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");

   tree->Process("Corrected5.C++");

   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
