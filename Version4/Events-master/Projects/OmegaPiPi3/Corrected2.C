#define Corrected2_cxx
// The class definition in Corrected2.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// Root > T->Process("Corrected2.C")
// Root > T->Process("Corrected2.C","some options")
// Root > T->Process("Corrected2.C+")
//

#include "Corrected2.h"
#include <TH2.h>
#include <TStyle.h>


void Corrected2::Begin(TTree * /*tree*/)
{
   THSOutput::HSBegin(fInput,fOutput);
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void Corrected2::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   THSOutput::HSSlaveBegin(fInput,fOutput);

 fOutTree=new TTree("HSParticles","A tree containing reconstructed particles"); 
   //e.g. Make some objects to make branch with, these should be declared in the .h file 
   //e.g. fp1=new TLorentzVector();


  //e.g.  fOutTree->Branch("p1",&fp1,buff,split);
   fOutTree->Branch("Mmiss",&Mmiss,"Mmiss/D");
   fOutTree->Branch("Egamma",&Egamma,"Egamma/D");
   fOutTree->Branch("MassProton",&MassProton,"MassProton/D");
   fOutTree->Branch("MassPiP",&MassPiP,"MassPiP/D");
   fOutTree->Branch("MassPiM",&MassPiM,"MassPiM/D");
   fOutTree->Branch("MassOmega",&MassOmega,"MassOmega/D");
   fOutTree->Branch("MassOmegaPiP",&MassOmegaPiP,"MassOmegaPiP/D");
   fOutTree->Branch("MassOmegaPiM",&MassOmegaPiM,"MassOmegaPiM/D");
   fOutTree->Branch("MassX",&MassX,"MassX/D");
   fOutTree->Branch("PhiX",&PhiX,"PhiX/D");
   fOutTree->Branch("ThetaX",&ThetaX,"ThetaX/D");
   fOutTree->Branch("MassPiPPiM",&MassPiPPiM,"MassPiPPiM/D");
   fOutTree->Branch("t",&t,"t/D");
   fOutTree->Branch("s",&s,"s/D");
   fOutTree->Branch("MassOmegaProton",&MassOmegaProton,"MassOmegaProton/D");
   fOutTree->Branch("MassPiPProton",&MassPiPProton,"MassPiPProton/D");
   fOutTree->Branch("MassPiMProton",&MassPiMProton,"MassPiMProton/D");
   fOutTree->Branch("MassPiPPiMProton",&MassPiPPiMProton,"MassPiPPiMProton/D");

   fOutTree->Branch("FrameBoostVTestX",&FrameXBoostVTestX,"FrameXBoostVTestX/D");
   fOutTree->Branch("FrameXBoostVTestY",&FrameXBoostVTestY,"FrameXBoostVTestY/D");
   fOutTree->Branch("FrameXBoostVTestZ",&FrameXBoostVTestZ,"FrameXBoostVTestZ/D");

   fOutTree->Branch("MassOmegaFrameX",&MassOmegaFrameX,"MassOmegaFrameX/D");
   fOutTree->Branch("PhiOmegaFrameX",&PhiOmegaFrameX,"PhiOmegaFrameX/D");
   fOutTree->Branch("ThetaOmegaFrameX",&ThetaOmegaFrameX,"ThetaOmegaFrameX/D");
   fOutTree->Branch("MassPiPFrameX",&MassPiPFrameX,"MassPiPFrameX/D");
   fOutTree->Branch("PhiPiPFrameX",&PhiPiPFrameX,"PhiPiPFrameX/D");
   fOutTree->Branch("ThetaPiPFrameX",&ThetaPiPFrameX,"ThetaPiPFrameX/D");
   fOutTree->Branch("MassPiMFrameX",&MassPiMFrameX,"MassPiMFrameX/D");
   fOutTree->Branch("PhiPiMFrameX",&PhiPiMFrameX,"PhiPiMFrameX/D");
   fOutTree->Branch("ThetaPiMFrameX",&ThetaPiMFrameX,"ThetaPiMFrameX/D");

   fOutTree->Branch("AngleBeamFXandOmegaLab",&AngleBeamFXandOmegaLab,"AngleBeamFXandOmegaLab/D");
   fOutTree->Branch("AngleMesonXLabandOmegaFX",&AngleMesonXLabandOmegaFX,"AngleMesonXLabandOmegaFX/D");

}

Bool_t Corrected2::Process(Long64_t entry)
{
   THSOutput::HSProcessStart(entry);
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either Corrected2::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.
   GetEntry(entry); //lazy and slow, you can speed the code up by getting the branches you need to use instead
   //Ready to do some analysis here, before the Fill

   TLorentzVector Omega = *miss;
   Omega.SetVectM(miss->Vect(),0.7826);  //Correcting the mass of the missing vector to the pdg omega mass.
  
   Mmiss=miss->M();
   MassProton=Proton->M();
   MassPiP=PiP->M();
   MassPiM=PiM->M();
   MassOmega=Omega.M();
   
   //cout << "Missing Mass " << Mmiss << endl;

   if(Mmiss <= 0.68 || Mmiss >= 0.88) return kTRUE;

   TLorentzVector p4 = Omega+pip_0->P4();
   //  TLorentzVector p4 = *miss+pip_0->P4();
   MassOmegaPiP=p4.M();


   p4 = Omega+pim_0->P4();
   // p4 = *miss+pim_0->P4();
   MassOmegaPiM=p4.M();

   //Defining the properties of the Combined meson, OmegaPiPi
   p4 = Omega+pim_0->P4()+pip_0->P4();
   //p4 = *miss+pim_0->P4()+pip_0->P4();
   MassX=p4.M();
   PhiX=p4.Phi();
   PhiX=PhiX*360/(2*TMath::Pi());
   ThetaX=p4.Theta();
   ThetaX=ThetaX*360/(2*TMath::Pi());

   TVector3 FrameXBoostV = p4.BoostVector();  //Determining the boost vector for transformation to the rest frame of Meson X
   TLorentzVector OmegaFrameX = Omega;
   OmegaFrameX.Boost(-FrameXBoostV);
   TLorentzVector PiPFrameX = pip_0->P4();
   PiPFrameX.Boost(-FrameXBoostV);
   TLorentzVector PiMFrameX = pim_0->P4();
   PiMFrameX.Boost(-FrameXBoostV);
   TLorentzVector BeamFrameX = beam->P4();
   BeamFrameX.Boost(-FrameXBoostV);

   TVector3 BoostTest = OmegaFrameX.Vect()+PiPFrameX.Vect()+PiMFrameX.Vect();
   FrameXBoostVTestX = BoostTest.X();
   FrameXBoostVTestY = BoostTest.Y();
   FrameXBoostVTestZ = BoostTest.Z();

   //cout <<  "Sum of Boosted Vectors " << BoostTest.X() << " "  << BoostTest.Y() << " " << BoostTest.Z() << " " << BoostTest.Mag() << " "<< endl;

   MassOmegaFrameX=OmegaFrameX.M();
   PhiOmegaFrameX=OmegaFrameX.Phi();
   ThetaOmegaFrameX=OmegaFrameX.Theta();
   
   MassPiPFrameX=PiPFrameX.M();
   PhiPiPFrameX=PiPFrameX.Phi();
   ThetaPiPFrameX=PiPFrameX.Theta();

   MassPiMFrameX=PiMFrameX.M();
   PhiPiMFrameX=PiMFrameX.Phi();
   ThetaPiMFrameX=PiMFrameX.Theta();

   //Angle between vectors in the lab and meson X frame.

   
   TVector3 BeamFX = BeamFrameX.Vect();
   TVector3 OmegaL = Omega.Vect();
   TVector3 MesonXL = p4.Vect();
   TVector3 OmegaFX = OmegaFrameX.Vect();
   // cout << "BeamXdotOmegaLab " << BeamFX.Dot(OmegaL) << " " << BeamFX.Mag() << " " << OmegaL.Mag() << endl;

   AngleBeamFXandOmegaLab = TMath::ACos((BeamFX.Dot(OmegaL))/(BeamFX.Mag()*OmegaL.Mag()));
   AngleBeamFXandOmegaLab = AngleBeamFXandOmegaLab*360/(2*TMath::Pi());
   AngleMesonXLabandOmegaFX = TMath::ACos((MesonXL.Dot(OmegaFX))/(MesonXL.Mag()*OmegaFX.Mag()));
   AngleMesonXLabandOmegaFX = AngleMesonXLabandOmegaFX*360/(2*TMath::Pi());

   //p4 = *PiP+*PiM;
   p4 = pim_0->P4()+pip_0->P4();
   MassPiPPiM=p4.M();

   p4 = proton_0->P4()+Omega;
   MassOmegaProton=p4.M();

   p4 = proton_0->P4()+pip_0->P4();
   MassPiPProton=p4.M();

   p4 = proton_0->P4()+pim_0->P4();
   MassPiMProton=p4.M();

   p4 = proton_0->P4()+pip_0->P4()+pim_0->P4();
   MassPiPPiMProton = p4.M();

   //Calculating s and t mandelstam variables
   Egamma = beam->P4().E();
   Double_t EnergyProton = Proton->E();
   t = (-1)*((2*MassProton*MassProton)-(2*MassProton*EnergyProton));
   s = (MassProton*MassProton)+(2*Egamma*MassProton); //Might be calculated wrong.


   //Weighting the data to reflect the energy of the g11 data, mainly for monte carlo to be comparable.


   
   THSOutput::HSProcessFill(); 


   return kTRUE;
}

void Corrected2::SlaveTerminate()
{
   THSOutput::HSSlaveTerminate();
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void Corrected2::Terminate()
{
   THSOutput::HSTerminate();
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

}

// Double_t CLAStoHS::GetWeight(Double_t *par, Double_t x) {
//   // *par need to be an array with the 7 parameters that you get from the previous fit)                                                                                              
//   // x is the invariant mass that need to have a wieghting factor                                                                                                                    
//   // You will feed your weighted plots with  Fill(mass,GetWeight(par,mass)) for 1 dimension and Fill(whatever,mass,GetWeight(par,mass)) for 2 dimensions                             
//   // Par need the one correct for this combination of particles                                                                                                                      
      
//   // TF1 *total = new TF1("total","pol3(0)+gaus(4)",0.63,0.95);
//   total->SetParameters(par);
//   // TF1 *g2    = new TF1("g2","gaus",0.74,0.82);
//   g2->SetParameters(&par[5]);
    
//   Double_t weight_v =  g2->Eval(x)/total->Eval(x);
  
//   //  delete total;
//   //  delete g2;

  
//     return weight_v;
// }
