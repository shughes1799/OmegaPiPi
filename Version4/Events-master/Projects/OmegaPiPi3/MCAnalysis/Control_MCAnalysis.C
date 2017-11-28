{
  //Set up the input chain to be analysed
  TChain* tree=new TChain("HSParticles","datachain");
  tree->Add("/Disk/ds-sopa-group/np/thehubdata/thehub6/shughes/Haspect/OmegaPiPi/GeneratedEvents/PhaseSpaceEdGen1mil/Processed1/g11_simon_centos610*.bos.evt.recsis.root");
  //Set the ouput directory or file (if full file name is given just 1 file is created, while if a directory it will be created and filled with files of the same name as the input 
  gSystem->Setenv("HSOUT",
		  "/phys/linux/s0677668/Haspect/OmegaPiPPiMPDataPortion/2016/May/GeneratedData/PhaseSpaceAnalysis/");
   
  //Configure the analysis (i.e PROOF, source compilation...)
  TString HSANA=gSystem->Getenv("HSANA");
  gROOT->LoadMacro(HSANA+"/HSControl.C");
  TProof* prf=HSControl(kFALSE); //where the proof stuff is set, kTRUE means use PROOF
  
  //Use an event list from a previous analysis 
  //If only 1 file was output the event list will be in its top directory, so just give the file name
  //If many files were ouput the event list will be in the same directory with the name ParentEventList.root
  //HSEntryList("/PATH TO PERVIOUS EVENTLIST/ParentEventList.root");
  
  tree->Process("MCAnalysis.C++");
  
  //Not actually sure if this is needed or not...
  if(prf)prf->ClearData(TProof::kUnregistered | TProof::kForceClear);
}
