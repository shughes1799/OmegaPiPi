{
  //Set the input files
   TChain* tree=new TChain("h10","datachain");
   //   tree->Add("/home/dglazier/Work/data/kkpi/data*.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch1.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch2.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch3.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch4.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch5.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch6.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch7.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch8.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch9.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch10.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch11.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch12.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch13.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch14.root");
   // // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch15.root");
   // // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch16.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch17.root");
   // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch18.root");
   // // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch19.root");
   // // tree->Add(" /Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/skims2016/MissingPi0andMissingOmega1/batch20.root");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/eta1295EdGen/eta1295batch*.root");
   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun001.root");


  
   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
   // gSystem->Setenv("HSOUT",
   //		   "/home/dglazier/Work/data/kkpi/hs3/");
   gSystem->Setenv("HSOUT",
		   //   "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/May16filesMissingOmega/");
		   // "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/Feb2017Eta1295MissingOmega600k.root");
		   "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/PhaseSpace10mil/OneFileTest/OneFilePSTest.root");
 // gSystem->Setenv("HSOUT",
 // 		   "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/Version5Data/1stStageProcessedDatafiles/Test1/");
   
   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   HSControl(kTRUE,kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   
   //Use an event list from a previous analysis 
   //HSEntryList("~dglazier/Work/Research/HaSpect/data/pippippimMn_HS2/ParentEventList.root");
   
   //RUN
   //  tree->Process("CLAStoHS.C++","K+:K-:proton");
   tree->Process("CLAStoHS.C++","proton:pi+:pi-");
}
