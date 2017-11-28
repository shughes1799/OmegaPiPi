{
  //Set up the input chain to be analysed
   TChain* tree=new TChain("HSParticles","datachain");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/Corrected_Data/16FilesIDCorrMissingPi0.root");
   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/MissingPi0Data/Corrected_Data/16FilesIDCorrMissingPi0.root");

   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   gSystem->Setenv("HSOUT",
		   "/home/s0677668/Haspect/MissingPi0/Events-master/Projects/MissingPi0/sWeights/sWPlotting/Histograms/MissPi0OmegaCut.root");
   
   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");

   // tree->Process("Histo_sWeights_MissingPi0.C++","WEIGHTSFILEHERE.root:NameOfWeightsObject");
   //tree->Process("Histo_sWeights_MissingPi0.C++","/home/s0677668/Haspect/MissingPi0/Events-master/Projects/MissingPi0/sWeights/sWFitting/Weights/Aug2017ExtRange/WeightsAug2017ExtRange.root:WeightMap");
   tree->Process("Histo_sWeights_MissingPi0.C++","/home/s0677668/Haspect/MissingPi0/Events-master/Projects/MissingPi0/sWeights/sWFitting/Weights/Aug2017IDFix/WeightsAug2017IDFix.root:WeightMap");


   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
