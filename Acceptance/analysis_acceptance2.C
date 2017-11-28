#define analysis_acceptance2_cxx
// The class definition in analysis_acceptance.h has been generated automatically
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
// Root > T->Process("analysis_acceptance.C")
// Root > T->Process("analysis_acceptance.C","some options")
// Root > T->Process("analysis_acceptance.C+")
//

#include "analysis_acceptance2.h"
#include <TH2.h>
#include <TStyle.h>
#include <iostream>

void analysis_acceptance2::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

void analysis_acceptance2::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

   //Monte Carlo Value Plots
   h1_mass_proton  = new TH1F("h1_mass_proton","Mass proton; GeV",200,0.,2.0);
   h1_mass_pip1  = new TH1F("h1_mass_pip1","Mass #pi^{+}; GeV",200,0.,0.3);
   h1_mass_pim1  = new TH1F("h1_mass_pim1","Mass #pi^{-}; GeV",200,0.,0.3);
   h1_mass_pi0  = new TH1F("h1_mass_pi0","Mass #pi^{0}; GeV",200,0.,0.3);
   h1_mass_pip2  = new TH1F("h1_mass_pip2","Mass #pi^{+}; GeV",200,0.,0.3);
   h1_mass_pim2  = new TH1F("h1_mass_pim2","Mass #pi^{-}; GeV",200,0.,0.3);


   h1_mass_omega  = new TH1F("h1_mass_omega","Mass #omega; GeV",200,0.,2.0);
   h1_mass_omega2  = new TH1F("h1_mass_omega2","Mass #omega; GeV",200,0.,2.0);
   h1_mass_omega3  = new TH1F("h1_mass_omeg3","Mass #omega; GeV",200,0.,2.0);
   h1_mass_omega4  = new TH1F("h1_mass_omega4","Mass #omega; GeV",200,0.,2.0);

   h1_mass_omega_pi_pi  = new TH1F("h1_mass_omega_pi_pi","Invariant Mass (#omega + #pi^{+} + #pi^{-}); GeV",200,0.,2.0);
   h1_mass_omega_pi_pi2  = new TH1F("h1_mass_omega_pi_pi2","Invariant Mass (#omega + #pi^{+} + #pi^{-}); GeV",200,0.,2.0);

   //Reconstructed value plots
   h1_mass_proton_recon  = new TH1F("h1_mass_proton_recon","Mass proton recon; GeV",200,0.,2.0);
   h1_mass_pip1_recon  = new TH1F("h1_mass_pip1_recon","Mass pip1 recon; GeV",200,0.,0.3);
   h1_mass_pim1_recon  = new TH1F("h1_mass_pim1_recon","Mass pim1 recon; GeV",200,0.,0.3);

   //Filtered Reconstructed plots
   h1_mass_proton_recon_filt  = new TH1F("h1_mass_proton_recon_filt","Mass proton recon filt; GeV",200,0.,2.0);
   h1_mass_pip1_recon_filt  = new TH1F("h1_mass_pip1_recon_filt","Mass pip1 recon filt; GeV",200,0.,0.3);
   h1_mass_pim1_recon_filt  = new TH1F("h1_mass_pim1_recon_filt","Mass pim1 recon filt; GeV",200,0.,0.3);

   h1_mass_missing_recon_filt  = new TH1F("h1_mass_missing_recon_filt","Mass missing recon filt; GeV",180,0.69,0.87);
   h1_mass_omegapipi_recon_filt  = new TH1F("h1_mass_omegapipi_recon_filt","Mass #omega#pi#pi recon filt; GeV",200,1,2.0);

   //Beam Spread Histograms

   //Left Sidebands
   h1_missing_throwleft_getleft  = new TH1F("h1_missing_throwleft_getleft","Mass Missing Throw Left Get Left; GeV",180,0.722,0.752);
   h1_missing_throwleft_getsignal  = new TH1F("h1_missing_throwleft_getsignal","Mass Missing Throw Left Get Signal; GeV",180,0.752,0.812);
   h1_missing_throwleft_getright  = new TH1F("h1_missing_throwleft_getright","Mass Missing Throw Left Get Right; GeV",180,0.812,0.842);

   //Signal Region
   h1_missing_throwsignal_getleft  = new TH1F("h1_missing_throwsignal_getleft","Mass Missing Throw Signal Get Left; GeV",180,0.722,0.752);
   h1_missing_throwsignal_getsignal  = new TH1F("h1_missing_throwsignal_getsignal","Mass Missing Throw Signal Get Signal; GeV",180,0.752,0.812);
   h1_missing_throwsignal_getright  = new TH1F("h1_missing_throwsignal_getright","Mass Missing Throw Signal Get Right; GeV",180,0.812,0.842);
   //Right Sideband
   h1_missing_throwright_getleft  = new TH1F("h1_missing_throwright_getleft","Mass Missing Throw Right Get Left; GeV",180,0.722,0.752);
   h1_missing_throwright_getsignal  = new TH1F("h1_missing_throwright_getsignal","Mass Missing Throw Right Get Signal; GeV",180,0.752,0.812);
   h1_missing_throwright_getright  = new TH1F("h1_missing_throwright_getright","Mass Missing Throw Right Get Right; GeV",180,0.812,0.842);

   //OmegaPiPi for left signal and right throw and get.
   h1_omegapipi_throwleft_getleft  = new TH1F("h1_omegapipi_throwleft_getleft","Mass Omegapipi Throw Left Get Left; GeV",60,1.1,1.9);
   h1_omegapipi_throwleft_getsignal  = new TH1F("h1_omegapipi_throwleft_getsignal","Mass Omegapipi Throw Left Get Signal; GeV",60,1.1,1.9);
   h1_omegapipi_throwleft_getright  = new TH1F("h1_omegapipi_throwleft_getright","Mass Omegapipi Throw Left Get Right; GeV",60,1.1,1.9);

   //Signal Region
   h1_omegapipi_throwsignal_getleft  = new TH1F("h1_omegapipi_throwsignal_getleft","Mass Omegapipi Throw Signal Get Left; GeV",180,1.1,1.9);
   h1_omegapipi_throwsignal_getsignal  = new TH1F("h1_omegapipi_throwsignal_getsignal","Mass Omegapipi Throw Signal Get Signal; GeV",180,1.1,1.9);
   h1_omegapipi_throwsignal_getright  = new TH1F("h1_omegapipi_throwsignal_getright","Mass Omegapipi Throw Signal Get Right; GeV",180,1.1,1.9);
   //Right Sideband
   h1_omegapipi_throwright_getleft  = new TH1F("h1_omegapipi_throwright_getleft","Mass Omegapipi Throw Right Get Left; GeV",60,1.1,1.9);
   h1_omegapipi_throwright_getsignal  = new TH1F("h1_omegapipi_throwright_getsignal","Mass Omegapipi Throw Right Get Signal; GeV",60,1.1,1.9);
   h1_omegapipi_throwright_getright  = new TH1F("h1_omegapipi_throwright_getright","Mass Omegapipi Throw Right Get Right; GeV",60,1.1,1.9);




   // h2_pimomega_pipomega = new TH2F("h2_pimomega_pipomega","Dalitz ;M^{2}(#pi^{-}#omega);M^{2}(#pi^{+}#omega)",200,0.,2.0,200,0.,2.0);
   // h1_omega1  = new TH1F("h1_omega1","Mass #omega (fast #pi^{+} fast #pi^{-}); GeV",200,0.,2.0);
   // h1_omega2  = new TH1F("h1_omega2","Mass #omega (fast #pi^{+} slow #pi^{-}); GeV",200,0.,2.0);
   // h1_omega3  = new TH1F("h1_omega3","Mass #omega (slow #pi^{+} fast #pi^{-}); GeV",200,0.,2.0);
   // h1_omega4  = new TH1F("h1_omega4","Mass #omega (slow #pi^{+} slow #pi^{-}); GeV",200,0.,2.0);

   // h1_omega_pi_pi_to_5pi_vertex_sep = new TH1F("h1_omega_pi_pi_to_5pi_vertex_sep","Seperation Distance; Unit of distance",200,-0.0000000001,0.0000000001);

   //Simon Histo
   // h2_mass_omega_vs_mass_omega_pi_pi  = new TH2F("h2_mass_omega_vs_mass_omega_pi_pi","Mass #omega vs Mass #omega#pi#pi;Mass(#omega);Mass(#pi^{+}#pi^{-}#omega)",120,0.722,0.842,180,1.1,1.9);

   fOutput->Add(h1_mass_proton);
   fOutput->Add(h1_mass_pip1);
   fOutput->Add(h1_mass_pim1);
   fOutput->Add(h1_mass_pi0);
   fOutput->Add(h1_mass_pip2);
   fOutput->Add(h1_mass_pim2);

   fOutput->Add(h1_mass_omega);
   fOutput->Add(h1_mass_omega2);
   fOutput->Add(h1_mass_omega3);
   fOutput->Add(h1_mass_omega4);
   fOutput->Add(h1_mass_omega_pi_pi);
   fOutput->Add(h1_mass_omega_pi_pi2);

   fOutput->Add(h1_mass_proton_recon);
   fOutput->Add(h1_mass_pip1_recon);
   fOutput->Add(h1_mass_pim1_recon);

   fOutput->Add(h1_mass_proton_recon_filt);
   fOutput->Add(h1_mass_pip1_recon_filt);
   fOutput->Add(h1_mass_pim1_recon_filt);
   fOutput->Add(h1_mass_missing_recon_filt);
   fOutput->Add(h1_mass_omegapipi_recon_filt);

   fOutput->Add(h1_missing_throwleft_getleft);
   fOutput->Add(h1_missing_throwleft_getsignal);
   fOutput->Add(h1_missing_throwleft_getright);

   fOutput->Add(h1_missing_throwsignal_getleft);
   fOutput->Add(h1_missing_throwsignal_getsignal);
   fOutput->Add(h1_missing_throwsignal_getright);

   fOutput->Add(h1_missing_throwright_getleft);
   fOutput->Add(h1_missing_throwright_getsignal);
   fOutput->Add(h1_missing_throwright_getright);

   fOutput->Add(h1_omegapipi_throwleft_getleft);
   fOutput->Add(h1_omegapipi_throwleft_getsignal);
   fOutput->Add(h1_omegapipi_throwleft_getright);

   fOutput->Add(h1_omegapipi_throwsignal_getleft);
   fOutput->Add(h1_omegapipi_throwsignal_getsignal);
   fOutput->Add(h1_omegapipi_throwsignal_getright);

   fOutput->Add(h1_omegapipi_throwright_getleft);
   fOutput->Add(h1_omegapipi_throwright_getsignal);
   fOutput->Add(h1_omegapipi_throwright_getright);


   // fOutput->Add(h2_pimomega_pipomega);
   // fOutput->Add(h1_omega1);
   // fOutput->Add(h1_omega2);
   // fOutput->Add(h1_omega3);
   // fOutput->Add(h1_omega4);

   // fOutput->Add(h1_omega_pi_pi_to_5pi_vertex_sep);

   //Simon Additions
   // fOutput->Add(h2_mass_omega_vs_mass_omega_pi_pi);



}

Bool_t analysis_acceptance2::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either analysis_acceptance2::GetEntry() or TBranch::GetEntry()
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

  b_mcnentr->GetEntry(entry); 
  b_mcid->GetEntry(entry);
  b_mcw->GetEntry(entry);
  b_mctheta->GetEntry(entry);
  b_mcphi->GetEntry(entry); 
  b_mcp->GetEntry(entry);  
  b_mcm->GetEntry(entry);
  b_taghit->GetEntry(entry);
  b_E_gamma->GetEntry(entry);

  b_gpart->GetEntry(entry);
  b_id->GetEntry(entry);
  b_p->GetEntry(entry);
  b_m->GetEntry(entry);
  b_cx->GetEntry(entry);
  b_cy->GetEntry(entry);
  b_cz->GetEntry(entry);

  b_vx->GetEntry(entry);
  b_vy->GetEntry(entry);
  b_vz->GetEntry(entry);

  b_taggoodhit->GetEntry(entry);
  b_dt_st_tag->GetEntry(entry);
  b_tag_energy->GetEntry(entry);

  // TLorentzVector v4_sum;
  // TVector3 v3_pi0(1,2,3);
  // TVector3 v3_proton(1,2,3);
  // TLorentzVector v4_pi0;
  // TLorentzVector v4_proton;
  // TLorentzVector target;
  // TLorentzVector beam;
  // TLorentzVector Wtg;
  // double inv_mass_pi0;
  // v3_proton.SetMag(mcp[0]);
  // v3_proton.SetTheta(mctheta[0]);
  // v3_proton.SetPhi(mcphi[0]);
  // v4_proton.SetXYZM(v3_proton.X(),v3_proton.Y(),v3_proton.Z(),mcm[0]);
  // v3_pi0.SetMag(mcp[1]);
  // v3_pi0.SetTheta(mctheta[1]);
  // v3_pi0.SetPhi(mcphi[1]);
  // v4_pi0.SetXYZM(v3_pi0.X(),v3_pi0.Y(),v3_pi0.Z(),mcm[1]);

  //Monte Carlo Particles

  TLorentzVector v4_miss;
  TLorentzVector v4_pip1;
  TLorentzVector v4_pip2;
  TLorentzVector v4_pim1;
  TLorentzVector v4_pim2;
  TLorentzVector v4_pi0;
  TLorentzVector v4_proton;
  TLorentzVector v4_omega;
  TLorentzVector v4_omega2;
  TLorentzVector v4_omega3;
  TLorentzVector v4_omega4;
  TLorentzVector v4_omegapipi;
  TLorentzVector v4_omegapipi2;
  TVector3 v3_miss(1,2,3);
  TVector3 v3_pip1(1,2,3);
  TVector3 v3_pip2(1,2,3);
  TVector3 v3_pim1(1,2,3);
  TVector3 v3_pim2(1,2,3);
  TVector3 v3_pi0(1,2,3);
  TVector3 v3_proton(1,2,3);

  // cout << "MCID 0 " << mcid[0] << endl;
  // cout << "MCID 1 " << mcid[1] << endl;
  // cout << "MCID 2 " << mcid[2] << endl;
  // cout << "MCID 3 " << mcid[3] << endl;
  // cout << "MCID 4 " << mcid[4] << endl;
  // cout << "MCID 5 " << mcid[5] << endl;

  v3_proton.SetMag(mcp[0]);
  v3_proton.SetTheta(mctheta[0]/180*TMath::Pi());
  v3_proton.SetPhi(mcphi[0]/180*TMath::Pi());
  v4_proton.SetXYZM(v3_proton.X(),v3_proton.Y(),v3_proton.Z(),mcm[0]);

  // cout << "Theta Proton " << mctheta[0] <<" " << mctheta[0]/180*TMath::Pi()  << ""<< v3_proton.Theta() << endl;
  // cout << "Phi Proton " << mcphi[0] << " " << mcphi[0]/180*TMath::Pi() << " " << v3_proton.Phi() << endl;

  //check the order of the pions.
  v3_pip1.SetMag(mcp[1]);
  v3_pip1.SetTheta(mctheta[1]/180*TMath::Pi());
  v3_pip1.SetPhi(mcphi[1]/180*TMath::Pi());
  v4_pip1.SetXYZM(v3_pip1.X(),v3_pip1.Y(),v3_pip1.Z(),mcm[1]);
  v3_pim1.SetMag(mcp[2]);
  v3_pim1.SetTheta(mctheta[2]/180*TMath::Pi());
  v3_pim1.SetPhi(mcphi[2]/180*TMath::Pi());
  v4_pim1.SetXYZM(v3_pim1.X(),v3_pim1.Y(),v3_pim1.Z(),mcm[2]);
  v3_pip2.SetMag(mcp[4]);
  v3_pip2.SetTheta(mctheta[4]/180*TMath::Pi());
  v3_pip2.SetPhi(mcphi[4]/180*TMath::Pi());
  v4_pip2.SetXYZM(v3_pip2.X(),v3_pip2.Y(),v3_pip2.Z(),mcm[4]);
  v3_pim2.SetMag(mcp[5]);
  v3_pim2.SetTheta(mctheta[5]/180*TMath::Pi());
  v3_pim2.SetPhi(mcphi[5]/180*TMath::Pi());
  v4_pim2.SetXYZM(v3_pim2.X(),v3_pim2.Y(),v3_pim2.Z(),mcm[5]);
  //Pi0 if its needed.
  v3_pi0.SetMag(mcp[3]);
  v3_pi0.SetTheta(mctheta[3]/180*TMath::Pi());
  v3_pi0.SetPhi(mcphi[3]/180*TMath::Pi());
  v4_pi0.SetXYZM(v3_pi0.X(),v3_pi0.Y(),v3_pi0.Z(),mcm[3]);

  // cout << "Theta PiP2 " << v3_pip2.Theta() << endl;
  // cout << "Phi PiP2 " << v3_pip2.Phi() << endl;

  //Combined Particles
  v4_omega = v4_pip1 + v4_pim1 + v4_pi0;
  v4_omegapipi = v4_pip2 + v4_pim2 + v4_omega;

  v4_omega2 = v4_pip2 + v4_pim2 + v4_pi0;
  v4_omegapipi2 = v4_pip1 + v4_pim1 + v4_omega;

  v4_omega3 = v4_pip1 + v4_pim2 + v4_pi0;
  v4_omega4 = v4_pip2 + v4_pim1 + v4_pi0;



  h1_mass_proton->Fill(v4_proton.M());
  h1_mass_pip1->Fill(v4_pip1.M());
  h1_mass_pim1->Fill(v4_pim1.M());
  h1_mass_pi0->Fill(v4_pi0.M());
  h1_mass_pip2->Fill(v4_pip2.M());
  h1_mass_pim2->Fill(v4_pim2.M());

  h1_mass_omega->Fill(v4_omega.M());
  h1_mass_omega2->Fill(v4_omega2.M());
  h1_mass_omega3->Fill(v4_omega3.M());
  h1_mass_omega4->Fill(v4_omega4.M());
  h1_mass_omega_pi_pi->Fill(v4_omegapipi.M());
  h1_mass_omega_pi_pi2->Fill(v4_omegapipi2.M());

  //Reconstructed Data

  TLorentzVector Recon_v4_miss;
  TLorentzVector Recon_v4_pip1;
  TLorentzVector Recon_v4_pip2;
  TLorentzVector Recon_v4_pim1;
  TLorentzVector Recon_v4_pim2;
  TLorentzVector Recon_v4_pi0;
  TLorentzVector Recon_v4_proton;
  TLorentzVector Recon_v4_omega;
  TLorentzVector Recon_v4_omega2;
  TLorentzVector Recon_v4_omega3;
  TLorentzVector Recon_v4_omega4;
  TLorentzVector Recon_v4_omegapipi;
  TLorentzVector Recon_v4_omegapipi2;
  TVector3 Recon_v3_miss(1,2,3);
  TVector3 Recon_v3_pip1(1,2,3);
  TVector3 Recon_v3_pip2(1,2,3);
  TVector3 Recon_v3_pim1(1,2,3);
  TVector3 Recon_v3_pim2(1,2,3);
  TVector3 Recon_v3_pi0(1,2,3);
  TVector3 Recon_v3_proton(1,2,3);

  //TLorentzVector target;
  //TLorentzVector beam;
  TLorentzVector Wtg;


  // Gpart is the variables for p,vx,vy,vz,id,m
  pCount = 0;
  pipCount = 0;
  pimCount = 0;
  target.SetPxPyPzE(0.0, 0.0, 0.0,0.9383);
  // beam.SetPxPyPzE(0.0, 0.0,E_gamma[0],E_gamma[0]);
  // Wtg = beam + target;

  //cout << "Beam Energy and Target Energy " << beam.E() << " " << target.E() << endl;

  for(int l=0;l<gpart;l++){

  if(id[l] == 2212){
    Recon_v3_proton.SetXYZ(cx[l]*p[l],cy[l]*p[l],cz[l]*p[l]);
    Recon_v4_proton.SetXYZM(Recon_v3_proton.X(),Recon_v3_proton.Y(),Recon_v3_proton.Z(),m[l]);
    pCount++;
    h1_mass_proton_recon->Fill(Recon_v4_proton.M());
  }
  
  if(id[l] == 211){
    Recon_v3_pip1.SetXYZ(cx[l]*p[l],cy[l]*p[l],cz[l]*p[l]);
    Recon_v4_pip1.SetXYZM(Recon_v3_pip1.X(),Recon_v3_pip1.Y(),Recon_v3_pip1.Z(),m[l]);
    pipCount++;
    h1_mass_pip1_recon->Fill(Recon_v4_pip1.M());
  }

  if(id[l] == -211){
    Recon_v3_pim1.SetXYZ(cx[l]*p[l],cy[l]*p[l],cz[l]*p[l]);
    Recon_v4_pim1.SetXYZM(Recon_v3_pim1.X(),Recon_v3_pim1.Y(),Recon_v3_pim1.Z(),m[l]);
    pimCount++;
    h1_mass_pim1_recon->Fill(Recon_v4_pim1.M());
  }


  } //end of loop


  if(!MakeBeam(0,2.0)) return kTRUE;
  //MakeBeam(0,2.0);

 //target.SetPxPyPzE(0.0, 0.0, 0.0,0.9383);
  //  beam.SetPxPyPzE(0.0, 0.0,E_gamma[0],E_gamma[0]);
 
 //cout << "Beam Energy " << beam.M() << endl;

  Wtg = beam + target;


  if(pCount == 1 && pipCount == 1 && pimCount == 1 && gpart == 3){
    h1_mass_proton_recon_filt->Fill(Recon_v4_proton.M());
    h1_mass_pip1_recon_filt->Fill(Recon_v4_pip1.M());
    h1_mass_pim1_recon_filt->Fill(Recon_v4_pim1.M());

    //Setting masses to pdg values.
    Recon_v4_proton.SetXYZM(Recon_v4_proton.X(),Recon_v4_proton.Y(),Recon_v4_proton.Z(),0.938);
    Recon_v4_pip1.SetXYZM(Recon_v4_pip1.X(),Recon_v4_pip1.Y(),Recon_v4_pip1.Z(),0.13957);
    Recon_v4_pim1.SetXYZM(Recon_v4_pim1.X(),Recon_v4_pim1.Y(),Recon_v4_pim1.Z(),0.13957);

    Recon_v4_miss = Wtg-Recon_v4_proton-Recon_v4_pip1-Recon_v4_pim1;
    h1_mass_missing_recon_filt->Fill(Recon_v4_miss.M());


    //Recon_v4_miss.SetXYZM(Recon_v4_miss.X(),Recon_v4_miss.Y(),Recon_v4_miss.Z(),0.7826);
    Recon_v4_omega = Recon_v4_miss;
    Recon_v4_omega.SetXYZM(Recon_v4_miss.X(),Recon_v4_miss.Y(),Recon_v4_miss.Z(),0.7826);

    Recon_v4_omegapipi = Recon_v4_omega + Recon_v4_pim1 + Recon_v4_pip1;

    h1_mass_omegapipi_recon_filt->Fill(Recon_v4_omegapipi.M());

    //Making histrograms for comparing the montecarlo to the reconstructed results.

//Monte Carlo Left
    if(v4_omega2.M() >= 0.722 && v4_omega2.M() < 0.752){  //Left

      if(Recon_v4_miss.M() >= 0.722 && Recon_v4_miss.M() < 0.752){
	h1_missing_throwleft_getleft->Fill(Recon_v4_miss.M());
	// Recon_v4_miss.SetXYZM(Recon_v4_miss.X(),Recon_v4_miss.Y(),Recon_v4_miss.Z(),0.7826);
	// Recon_v4_omegapipi = Recon_v4_miss + Recon_v4_pim1 + Recon_v4_pip1;
	h1_omegapipi_throwleft_getleft->Fill(Recon_v4_omegapipi.M());
	  }
      if(Recon_v4_miss.M() >= 0.752 && Recon_v4_miss.M() < 0.812){
	h1_missing_throwleft_getsignal->Fill(Recon_v4_miss.M());
	// Recon_v4_miss.SetXYZM(Recon_v4_miss.X(),Recon_v4_miss.Y(),Recon_v4_miss.Z(),0.7826);
	// Recon_v4_omegapipi = Recon_v4_miss + Recon_v4_pim1 + Recon_v4_pip1;
	h1_omegapipi_throwleft_getsignal->Fill(Recon_v4_omegapipi.M());
	  }
      if(Recon_v4_miss.M() >= 0.812 && Recon_v4_miss.M() < 0.842){
	h1_missing_throwleft_getright->Fill(Recon_v4_miss.M());
	// Recon_v4_miss.SetXYZM(Recon_v4_miss.X(),Recon_v4_miss.Y(),Recon_v4_miss.Z(),0.7826);
	// Recon_v4_omegapipi = Recon_v4_miss + Recon_v4_pim1 + Recon_v4_pip1;
	h1_omegapipi_throwleft_getright->Fill(Recon_v4_omegapipi.M());

	  }
    }
    
    //MontCarlo Signal
    if(v4_omega2.M() >= 0.752 && v4_omega2.M() < 0.812){ //Signal

      if(Recon_v4_miss.M() >= 0.722 && Recon_v4_miss.M() < 0.752){
	h1_missing_throwsignal_getleft->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwsignal_getleft->Fill(Recon_v4_omegapipi.M());
      }
      if(Recon_v4_miss.M() >= 0.752 && Recon_v4_miss.M() < 0.812){
	h1_missing_throwsignal_getsignal->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwsignal_getsignal->Fill(Recon_v4_omegapipi.M());
      }
      if(Recon_v4_miss.M() >= 0.812 && Recon_v4_miss.M() < 0.842){
	h1_missing_throwsignal_getright->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwsignal_getright->Fill(Recon_v4_omegapipi.M());
      }
      

    }

    //MonteCarlo Right
    if(v4_omega2.M() >= 0.812 && v4_omega2.M() < 0.842){  //Right

      if(Recon_v4_miss.M() >= 0.722 && Recon_v4_miss.M() < 0.752){
	h1_missing_throwright_getleft->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwright_getleft->Fill(Recon_v4_omegapipi.M());
      }
      if(Recon_v4_miss.M() >= 0.752 && Recon_v4_miss.M() < 0.812){
	h1_missing_throwright_getsignal->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwright_getsignal->Fill(Recon_v4_omegapipi.M());
      }
      if(Recon_v4_miss.M() >= 0.812 && Recon_v4_miss.M() < 0.842){
	h1_missing_throwright_getright->Fill(Recon_v4_miss.M());
	h1_omegapipi_throwright_getright->Fill(Recon_v4_omegapipi.M());
      }


    }



  }

  pCount = 0;
  pipCount = 0;
  pimCount = 0;

   return kTRUE;
}

void analysis_acceptance2::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void analysis_acceptance2::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.

  TFile file_out("analysis_acceptance_output.root","recreate");
  TList *outlist = GetOutputList();
  
  outlist->Write();
  file_out.Write();
  file_out.Close();
}

Bool_t analysis_acceptance2::MakeBeam(Float_t Tmid,Float_t Tcut){
  //Find a photon within a Tcut window of Tmid  
  //and throw away events with more than one photon
  Bool_t gotGamma=kFALSE;
// cout << "taggoodhit " << taggoodhit << endl;
// cout << "dt_st_tag[0] " << dt_st_tag[0] << endl;
// cout << "dt_st_tag[1] " << dt_st_tag[1] << endl;
// cout << "dt_st_tag[2] " << dt_st_tag[2] << endl;
// cout << "tag energy[0] " << tag_energy[0] << endl;
// cout << "tag energy[1] " << tag_energy[1] << endl;
  for(Int_t im=0;im<taggoodhit;im++) if(TMath::Abs(dt_st_tag[im])+Tmid<Tcut){
      if(gotGamma==kTRUE)return kFALSE; //ambigous photon event throw away for now
      
      //beam.SetXYZT(0,0,tag_energy[im],tag_energy[im]);
      beam.SetPxPyPzE(0,0,tag_energy[im],tag_energy[im]);
 // cout << "Beam Energy " << beam.E() << endl;
      // fHSgamma->SetTime(vertex_time[im]);//=-tr_time
      gotGamma=kTRUE;
    }
  if(!gotGamma) return kFALSE; //didn't get a photon event no good
  return kTRUE; //got one good photon
}
