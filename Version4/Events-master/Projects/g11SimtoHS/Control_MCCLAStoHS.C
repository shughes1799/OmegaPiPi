{
  //LOAD precompiled eloss library
  // setenv ELOSS /home/dglazier/Dropbox/HaSpect/Analysis/eloss_hs
   gSystem->Load("libPhysics");
   gSystem->Load("$ELOSS/libeloss");
   gInterpreter->AddIncludePath("$ELOSS");
  //ELOSS loaded
   
  //Set up the input chain to be analysed
   TChain* tree=new TChain("h10","datachain");
   // tree->Add("YOURINPUTFILES");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/PhaseSpaceEdGen1mil/g11_simon_centos610*.bos.evt.recsis.root");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/PhaseSpaceEdGen1mil/g11_simon_centos61001.bos.evt.recsis.root");
   //tree->Add("/phys/linux/s0677668/Haspect/g11_centos61001.bos.evt.recsis.root");
   // tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/A2EdGen1mil/A2Decays*.root");
   //   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/PhaseSpaceTest/PSFullTheta100kEvents.root");
   tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/PSRun*.root");


   //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
 //  gSystem->Setenv("HSOUT",
 //		   "YOUROUTPUTDIRECTORYORFILE");
   gSystem->Setenv("HSOUT",
		 "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/ps10mil/MCAnalysis/PSTestFullPhiMissOmega1.root");
   // gSystem->Setenv("HSOUT",
   //		 "/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/A2EdGen1mil/Processed1/");
 
   //Configure the analysis (i.e PROOF, source compilation...)
   TString HSANA=gSystem->Getenv("HSANA");
   gROOT->LoadMacro(HSANA+"/HSControl.C");
   TProof* prf=HSControl(kTRUE,kFALSE); //where the proof stuff is set, kTRUE means use PROOF
   // TProof* prf=HSControl(kFALSE);
   if(prf){
     //prf->Load(TString(gSystem->Getenv("ROOTSYS"))+"/lib/libPhysics.so");
     TString ELOSS=gSystem->Getenv("ELOSS");
     prf->Load(ELOSS+"/libeloss.so");
     prf->AddIncludePath(ELOSS);
   }	

   //Use an event list from a previous analysis 
   //If only 1 file was output the event list will be in its top directory, so just give the file name
   //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
   //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");
   
   //particle final state, if you expect a missing particle preceed its name with AT and it will be found in the mc truth values
   // tree->Process("MCCLAStoHS.C++","pi-:pi+:ATproton");
   tree->Process("MCCLAStoHS.C++","pi-:pi+:proton");
   // tree->Process("MCCLAStoHS.C++","pi-:pi+:pi-:pi+:proton");
   // tree->Process("MCCLAStoHS.C++","pi-:pi+:proton:ATpi+:ATpi-:ATpi0");

   // tree->Process("MCCLAStoHS.C++","K-:K+:proton");
   //Not actually sure if this is needed or not...
   if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
 }
