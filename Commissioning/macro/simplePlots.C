#define simplePlots_cxx
#include "simplePlots.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TProfile.h>
#include <TGraphAsymmErrors.h>

void simplePlots::Loop()
{
  if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  
  Long64_t nbytes = 0, nb = 0;

  // booking histos - kinematics
  TH1F *H_pt_EB = new TH1F("H_pt_EB","p_{T}, barrel",90, 0.,4500.);
  TH1F *H_pt_EE = new TH1F("H_pt_EE","p_{T}, endcap",90, 0.,4500.);
  H_pt_EB->Sumw2();
  H_pt_EE->Sumw2();
  H_pt_EB->GetXaxis()->SetTitle("pT [GeV]");
  H_pt_EE->GetXaxis()->SetTitle("pT [GeV]");

  TH1F *H_eta = new TH1F("H_eta","#eta",50, -2.6,2.6);
  H_eta->Sumw2();
  H_eta->GetXaxis()->SetTitle("#eta");


  // booking histos - energies
  TH1F *H_EmaxOverEtrue_EB = new TH1F("H_EmaxOverEtrue_EB","H_EmaxOverEtrue_EB",50, 0.,1.2);
  TH1F *H_EmaxOverEtrue_EE = new TH1F("H_EmaxOverEtrue_EE","H_EmaxOverEtrue_EE",50, 0.,1.2);
  H_EmaxOverEtrue_EB->Sumw2();
  H_EmaxOverEtrue_EE->Sumw2();
  H_EmaxOverEtrue_EB->SetTitle("");
  H_EmaxOverEtrue_EE->SetTitle("");
  H_EmaxOverEtrue_EB->GetXaxis()->SetTitle("Emax / Etrue");
  H_EmaxOverEtrue_EE->GetXaxis()->SetTitle("Emax / Etrue");

  TH1F *H_E25OverEtrue_EB = new TH1F("H_E25OverEtrue_EB","H_E25OverEtrue_EB",50, 0.,1.2);
  TH1F *H_E25OverEtrue_EE = new TH1F("H_E25OverEtrue_EE","H_E25OverEtrue_EE",50, 0.,1.2);
  H_E25OverEtrue_EB->Sumw2();
  H_E25OverEtrue_EE->Sumw2();
  H_E25OverEtrue_EB->SetTitle("");
  H_E25OverEtrue_EE->SetTitle("");
  H_E25OverEtrue_EB->GetXaxis()->SetTitle("E5x5 / Etrue");
  H_E25OverEtrue_EE->GetXaxis()->SetTitle("E5x5 / Etrue");

  TH1F *H_EneOverEtrue_EB = new TH1F("H_EneOverEtrue_EB","H_EneOverEtrue_EB",50, 0.,1.2);
  TH1F *H_EneOverEtrue_EE = new TH1F("H_EneOverEtrue_EE","H_EneOverEtrue_EE",50, 0.,1.2);
  H_EneOverEtrue_EB->Sumw2();
  H_EneOverEtrue_EE->Sumw2();
  H_EneOverEtrue_EB->SetTitle("");
  H_EneOverEtrue_EE->SetTitle("");
  H_EneOverEtrue_EB->GetXaxis()->SetTitle("Ene / Etrue");
  H_EneOverEtrue_EE->GetXaxis()->SetTitle("Ene / Etrue");

  TProfile *P_EmaxOverEtrueVsEtrue_EB = new TProfile("P_EmaxOverEtrueVsEtrue_EB","P_EmaxOverEtrueVsEtrue_EB",90, 0.,4500.);
  TProfile *P_EmaxOverEtrueVsEtrue_EE = new TProfile("P_EmaxOverEtrueVsEtrue_EE","P_EmaxOverEtrueVsEtrue_EE",90, 0.,4500.);
  P_EmaxOverEtrueVsEtrue_EB->SetTitle("");
  P_EmaxOverEtrueVsEtrue_EB->GetXaxis()->SetTitle("Etrue");
  P_EmaxOverEtrueVsEtrue_EB->GetYaxis()->SetTitle("Emax / Etrue");
  P_EmaxOverEtrueVsEtrue_EE->SetTitle("");
  P_EmaxOverEtrueVsEtrue_EE->GetXaxis()->SetTitle("Etrue");
  P_EmaxOverEtrueVsEtrue_EE->GetYaxis()->SetTitle("Emax / Etrue");

  TProfile *P_E25OverEtrueVsEtrue_EB = new TProfile("P_E25OverEtrueVsEtrue_EB","P_E25OverEtrueVsEtrue_EB",90, 0.,4500.);
  TProfile *P_E25OverEtrueVsEtrue_EE = new TProfile("P_E25OverEtrueVsEtrue_EE","P_E25OverEtrueVsEtrue_EE",90, 0.,4500.);
  P_E25OverEtrueVsEtrue_EB->SetTitle("");
  P_E25OverEtrueVsEtrue_EB->GetXaxis()->SetTitle("Etrue");
  P_E25OverEtrueVsEtrue_EB->GetYaxis()->SetTitle("E25 / Etrue");
  P_E25OverEtrueVsEtrue_EE->SetTitle("");
  P_E25OverEtrueVsEtrue_EE->GetXaxis()->SetTitle("Etrue");
  P_E25OverEtrueVsEtrue_EE->GetYaxis()->SetTitle("E25 / Etrue");

  TProfile *P_EneOverEtrueVsEtrue_EB = new TProfile("P_EneOverEtrueVsEtrue_EB","P_EneOverEtrueVsEtrue_EB",90, 0.,4500.);
  TProfile *P_EneOverEtrueVsEtrue_EE = new TProfile("P_EneOverEtrueVsEtrue_EE","P_EneOverEtrueVsEtrue_EE",90, 0.,4500.);
  P_EneOverEtrueVsEtrue_EB->SetTitle("");
  P_EneOverEtrueVsEtrue_EB->GetXaxis()->SetTitle("Etrue");
  P_EneOverEtrueVsEtrue_EB->GetYaxis()->SetTitle("Ene / Etrue");
  P_EneOverEtrueVsEtrue_EE->SetTitle("");
  P_EneOverEtrueVsEtrue_EE->GetXaxis()->SetTitle("Etrue");
  P_EneOverEtrueVsEtrue_EE->GetYaxis()->SetTitle("Ene / Etrue");




  // booking histos - H/E studies
  TH1F *H_trueEne_EB        = new TH1F("H_trueEne_EB","H_trueEne_EB",25, 0.,4500.);
  TH1F *H_trueEne_EE        = new TH1F("H_trueEne_EE","H_trueEne_EE",25, 0.,4500.);
  TH1F *H_trueEne_okHoE_EB  = new TH1F("H_trueEne_okHoE_EB", "H_trueEne_okHoE_EB", 25, 0.,4500.);
  TH1F *H_trueEne_okHoE_EE  = new TH1F("H_trueEne_okHoE_EE", "H_trueEne_okHoE_EE", 25, 0.,4500.);
  TH1F *H_trueEne_okHoET_EB = new TH1F("H_trueEne_okHoET_EB","H_trueEne_okHoET_EB",25, 0.,4500.);
  TH1F *H_trueEne_okHoET_EE = new TH1F("H_trueEne_okHoET_EE","H_trueEne_okHoET_EE",25, 0.,4500.);
  H_trueEne_EB->Sumw2();
  H_trueEne_EE->Sumw2();
  H_trueEne_okHoE_EB->Sumw2();
  H_trueEne_okHoE_EE->Sumw2();
  H_trueEne_okHoET_EB->Sumw2();
  H_trueEne_okHoET_EE->Sumw2();

  TH1F *H_trueEta        = new TH1F("H_trueEta",       "H_trueEta",       57,-2.5,2.5);
  TH1F *H_trueEta_okHoE  = new TH1F("H_trueEta_okHoE", "H_trueEta_okHoE", 57,-2.5,2.5);
  TH1F *H_trueEta_okHoET = new TH1F("H_trueEta_okHoET","H_trueEta_okHoET",57,-2.5,2.5);
  H_trueEta->Sumw2();
  H_trueEta_okHoE->Sumw2();
  H_trueEta_okHoET->Sumw2();

  TH1F *H_truePhi        = new TH1F("H_truePhi",       "H_truePhi",        72,-3.14,3.14);
  TH1F *H_truePhi_okHoE  = new TH1F("H_truePhi_okHoE", "H_truePhi_okHoE",  72,-3.14,3.14);
  TH1F *H_truePhi_okHoET = new TH1F("H_truePhi_okHoET","H_truePhi_okHoET", 72,-3.14,3.14);
  H_truePhi->Sumw2();
  H_truePhi_okHoE->Sumw2();
  H_truePhi_okHoET->Sumw2();

  TH1F *H_EneOverEtrue_okHoE_EB = new TH1F("H_EneOverEtrue_okHoE_EB","H_EneOverEtrue_okHoE_EB",50, 0.,1.2);
  TH1F *H_EneOverEtrue_okHoE_EE = new TH1F("H_EneOverEtrue_okHoE_EE","H_EneOverEtrue_okHoE_EE",50, 0.,1.2);
  TH1F *H_EneOverEtrue_noHoE_EB = new TH1F("H_EneOverEtrue_noHoE_EB","H_EneOverEtrue_noHoE_EB",50, 0.,1.2);
  TH1F *H_EneOverEtrue_noHoE_EE = new TH1F("H_EneOverEtrue_noHoE_EE","H_EneOverEtrue_noHoE_EE",50, 0.,1.2);
  H_EneOverEtrue_okHoE_EB->Sumw2();
  H_EneOverEtrue_okHoE_EE->Sumw2();
  H_EneOverEtrue_okHoE_EB->SetTitle("");
  H_EneOverEtrue_okHoE_EE->SetTitle("");
  H_EneOverEtrue_okHoE_EB->GetXaxis()->SetTitle("Ene / Etrue");
  H_EneOverEtrue_okHoE_EE->GetXaxis()->SetTitle("Ene / Etrue");

  TH1F *H_EneOverEtrue_okHoET_EB = new TH1F("H_EneOverEtrue_okHoET_EB","H_EneOverEtrue_okHoET_EB",50, 0.,1.2);
  TH1F *H_EneOverEtrue_okHoET_EE = new TH1F("H_EneOverEtrue_okHoET_EE","H_EneOverEtrue_okHoET_EE",50, 0.,1.2);
  TH1F *H_EneOverEtrue_noHoET_EB = new TH1F("H_EneOverEtrue_noHoET_EB","H_EneOverEtrue_noHoET_EB",50, 0.,1.2);
  TH1F *H_EneOverEtrue_noHoET_EE = new TH1F("H_EneOverEtrue_noHoET_EE","H_EneOverEtrue_noHoET_EE",50, 0.,1.2);
  H_EneOverEtrue_okHoET_EB->Sumw2();
  H_EneOverEtrue_okHoET_EE->Sumw2();
  H_EneOverEtrue_okHoET_EB->SetTitle("");
  H_EneOverEtrue_okHoET_EE->SetTitle("");
  H_EneOverEtrue_okHoET_EB->GetXaxis()->SetTitle("Ene / Etrue");
  H_EneOverEtrue_okHoET_EE->GetXaxis()->SetTitle("Ene / Etrue");




  // booking histos - 2012ID studies
  TH1F *H_trueEne_okSee_EB  = new TH1F("H_trueEne_okSee_EB", "H_trueEne_okSee_EB", 25, 0.,4500.);
  TH1F *H_trueEne_okSee_EE  = new TH1F("H_trueEne_okSee_EE", "H_trueEne_okSee_EE", 25, 0.,4500.);
  H_trueEne_okSee_EB->Sumw2();
  H_trueEne_okSee_EE->Sumw2();

  TH1F *H_trueEne_okChIso_EB  = new TH1F("H_trueEne_okChIso_EB", "H_trueEne_okChIso_EB", 25, 0.,4500.);
  TH1F *H_trueEne_okChIso_EE  = new TH1F("H_trueEne_okChIso_EE", "H_trueEne_okChIso_EE", 25, 0.,4500.);
  H_trueEne_okChIso_EB->Sumw2();
  H_trueEne_okChIso_EE->Sumw2();

  TH1F *H_trueEne_okNhIso_EB  = new TH1F("H_trueEne_okNhIso_EB", "H_trueEne_okNhIso_EB", 25, 0.,4500.);
  TH1F *H_trueEne_okNhIso_EE  = new TH1F("H_trueEne_okNhIso_EE", "H_trueEne_okNhIso_EE", 25, 0.,4500.);
  H_trueEne_okNhIso_EB->Sumw2();
  H_trueEne_okNhIso_EE->Sumw2();


  // loop over entries
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;


    // restricting the analysis to photons matching MC truth
    if (mctruth_trueEta<-800) continue;

    // true photon must be in the ECAL fiducial region
    if (fabs(mctruth_trueEta)>2.5) continue;
    if (fabs(mctruth_trueEta)>1.4442 && fabs(mctruth_trueEta)<1.566) continue;

    // also reco photon must be in the ECAL fiducial region
    if (fabs(kinematics_eta)>2.5) continue;
    if (fabs(kinematics_eta)>1.4442 &&fabs(kinematics_eta)<1.566) continue;
    
    
    // filling histos

    // full eta range
    H_eta -> Fill(kinematics_eta);

    if (mctruth_trueEnergy>200) { 
      H_trueEta -> Fill(mctruth_trueEta);
      H_truePhi -> Fill(mctruth_truePhi);
      if (identification_hoe<0.05)  H_trueEta_okHoE  -> Fill(mctruth_trueEta);
      if (identification_htoe<0.05) H_trueEta_okHoET -> Fill(mctruth_trueEta);
      if (identification_hoe<0.05)  H_truePhi_okHoE  -> Fill(mctruth_truePhi);
      if (identification_htoe<0.05) H_truePhi_okHoET -> Fill(mctruth_truePhi);
    }

    // EB / EE
    if (fabs(kinematics_eta)<1.5) {

      H_pt_EB  -> Fill(kinematics_pt);
      
      // energy studies
      H_EmaxOverEtrue_EB -> Fill(energy_eMax/mctruth_trueEnergy);
      H_E25OverEtrue_EB  -> Fill(energy_e5x5/mctruth_trueEnergy);
      H_EneOverEtrue_EB  -> Fill(energy_energy/mctruth_trueEnergy);
      P_EmaxOverEtrueVsEtrue_EB -> Fill(mctruth_trueEnergy, (energy_eMax/mctruth_trueEnergy));
      P_E25OverEtrueVsEtrue_EB  -> Fill(mctruth_trueEnergy, (energy_e5x5/mctruth_trueEnergy));
      P_EneOverEtrueVsEtrue_EB  -> Fill(mctruth_trueEnergy, (energy_energy/mctruth_trueEnergy));

      // H/E cut efficiency studies
      H_trueEne_EB -> Fill(mctruth_trueEnergy);
      if (identification_hoe<0.05)  H_trueEne_okHoE_EB  -> Fill(mctruth_trueEnergy);
      if (identification_htoe<0.05) H_trueEne_okHoET_EB -> Fill(mctruth_trueEnergy);
      if (identification_hoe<0.05)  H_EneOverEtrue_okHoE_EB  -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_htoe<0.05) H_EneOverEtrue_okHoET_EB -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_hoe>0.05)  H_EneOverEtrue_noHoE_EB  -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_htoe>0.05) H_EneOverEtrue_noHoET_EB -> Fill(energy_energy/mctruth_trueEnergy);

      // 2012 photon ID. Chiara, caveat: iso in a dR=0.4 cone (was 0.3) and no rho correction
      if (identification_sigmaIetaIeta<0.012)              H_trueEne_okSee_EB   -> Fill(mctruth_trueEnergy);
      if (isolation_chHadIso<2.6)                          H_trueEne_okChIso_EB -> Fill(mctruth_trueEnergy);
      if (isolation_nHadIso<(3.5 + 0.04*kinematics_pt))    H_trueEne_okNhIso_EB -> Fill(mctruth_trueEnergy);

    } else {      
      
      H_pt_EE  -> Fill(kinematics_pt);
      
      // energy studies
      H_EmaxOverEtrue_EE -> Fill(energy_eMax/mctruth_trueEnergy);
      H_E25OverEtrue_EE  -> Fill(energy_e5x5/mctruth_trueEnergy);
      H_EneOverEtrue_EE  -> Fill(energy_energy/mctruth_trueEnergy);
      P_EmaxOverEtrueVsEtrue_EE -> Fill(mctruth_trueEnergy, (energy_eMax/mctruth_trueEnergy));
      P_E25OverEtrueVsEtrue_EE  -> Fill(mctruth_trueEnergy, (energy_e5x5/mctruth_trueEnergy));
      P_EneOverEtrueVsEtrue_EE  -> Fill(mctruth_trueEnergy, (energy_energy/mctruth_trueEnergy));

      // H/E cut efficiency studies    
      H_trueEne_EE -> Fill(mctruth_trueEnergy);
      if (identification_hoe<0.05)  H_trueEne_okHoE_EE  -> Fill(mctruth_trueEnergy);
      if (identification_htoe<0.05) H_trueEne_okHoET_EE -> Fill(mctruth_trueEnergy);
      if (identification_hoe<0.05)  H_EneOverEtrue_okHoE_EE  -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_htoe<0.05) H_EneOverEtrue_okHoET_EE -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_hoe>0.05)  H_EneOverEtrue_noHoE_EE  -> Fill(energy_energy/mctruth_trueEnergy);
      if (identification_htoe>0.05) H_EneOverEtrue_noHoET_EE -> Fill(energy_energy/mctruth_trueEnergy);

      // 2012 photon ID. Chiara, caveat: iso in a dR=0.4 cone (was 0.3) and no rho correction
      if (identification_sigmaIetaIeta<0.034)              H_trueEne_okSee_EE   -> Fill(mctruth_trueEnergy);
      if (isolation_chHadIso<2.3)                          H_trueEne_okChIso_EE -> Fill(mctruth_trueEnergy);
      if (isolation_nHadIso<(2.9 + 0.04*kinematics_pt))    H_trueEne_okNhIso_EE -> Fill(mctruth_trueEnergy);
    }
    
  }  // loop over entries


  // Efficiencies
  TGraphAsymmErrors *h1_effHoE_EB = new TGraphAsymmErrors(H_trueEne_okHoE_EB,H_trueEne_EB);
  TGraphAsymmErrors *h1_effHoE_EE = new TGraphAsymmErrors(H_trueEne_okHoE_EE,H_trueEne_EE);
  h1_effHoE_EB->SetTitle("H/E cut efficiency");
  h1_effHoE_EE->SetTitle("H/E cut efficiency");
  h1_effHoE_EB->GetXaxis()->SetTitle("Etrue");
  h1_effHoE_EE->GetXaxis()->SetTitle("Etrue");
  h1_effHoE_EB->SetMarkerStyle(20);
  h1_effHoE_EE->SetMarkerStyle(20);
  h1_effHoE_EB->SetMarkerColor(4);
  h1_effHoE_EE->SetMarkerColor(2);
  // 
  TGraphAsymmErrors *h1_effHoET_EB = new TGraphAsymmErrors(H_trueEne_okHoET_EB,H_trueEne_EB);
  TGraphAsymmErrors *h1_effHoET_EE = new TGraphAsymmErrors(H_trueEne_okHoET_EE,H_trueEne_EE);
  h1_effHoET_EB->SetTitle("H/E cut efficiency");
  h1_effHoET_EE->SetTitle("H/E cut efficiency");
  h1_effHoET_EB->GetXaxis()->SetTitle("Etrue");
  h1_effHoET_EE->GetXaxis()->SetTitle("Etrue");
  h1_effHoET_EB->SetMarkerStyle(20);
  h1_effHoET_EE->SetMarkerStyle(20);
  h1_effHoET_EB->SetMarkerColor(3);
  h1_effHoET_EE->SetMarkerColor(7);
  // 
  TGraphAsymmErrors *h1_effHoEvsEta = new TGraphAsymmErrors(H_trueEta_okHoE,H_trueEta);
  h1_effHoEvsEta->SetTitle("H/E cut efficiency");
  h1_effHoEvsEta->SetTitle("#eta true");
  h1_effHoEvsEta->SetMarkerStyle(20);
  h1_effHoEvsEta->SetMarkerColor(4);
  //
  TGraphAsymmErrors *h1_effHoETvsEta = new TGraphAsymmErrors(H_trueEta_okHoET,H_trueEta);
  h1_effHoETvsEta->SetTitle("H/E cut efficiency");
  h1_effHoETvsEta->SetTitle("#eta true");
  h1_effHoETvsEta->SetMarkerStyle(20);
  h1_effHoETvsEta->SetMarkerColor(2);
  //
  TGraphAsymmErrors *h1_effHoEvsPhi = new TGraphAsymmErrors(H_truePhi_okHoE,H_truePhi);
  h1_effHoEvsPhi->SetTitle("H/E cut efficiency");
  h1_effHoEvsPhi->SetTitle("#phi true");
  h1_effHoEvsPhi->SetMarkerStyle(20);
  h1_effHoEvsPhi->SetMarkerColor(4);
  //
  TGraphAsymmErrors *h1_effHoETvsPhi = new TGraphAsymmErrors(H_truePhi_okHoET,H_truePhi);
  h1_effHoETvsPhi->SetTitle("H/E cut efficiency");
  h1_effHoETvsPhi->SetTitle("#phi true");
  h1_effHoETvsPhi->SetMarkerStyle(20);
  h1_effHoETvsPhi->SetMarkerColor(2);
  //
  //
  TGraphAsymmErrors *h1_effSee_EB = new TGraphAsymmErrors(H_trueEne_okSee_EB,H_trueEne_EB);
  TGraphAsymmErrors *h1_effSee_EE = new TGraphAsymmErrors(H_trueEne_okSee_EE,H_trueEne_EE);
  h1_effSee_EB->SetTitle("SigmaIeIe cut efficiency");
  h1_effSee_EE->SetTitle("SigmaIeIe cut efficiency");
  h1_effSee_EB->GetXaxis()->SetTitle("Etrue");
  h1_effSee_EE->GetXaxis()->SetTitle("Etrue");
  h1_effSee_EB->SetMarkerStyle(20);
  h1_effSee_EE->SetMarkerStyle(20);
  h1_effSee_EB->SetMarkerColor(4);
  h1_effSee_EE->SetMarkerColor(2);
  // 
  TGraphAsymmErrors *h1_effChIso_EB = new TGraphAsymmErrors(H_trueEne_okChIso_EB,H_trueEne_EB);
  TGraphAsymmErrors *h1_effChIso_EE = new TGraphAsymmErrors(H_trueEne_okChIso_EE,H_trueEne_EE);
  h1_effChIso_EB->SetTitle("chargedH isolation cut efficiency");
  h1_effChIso_EE->SetTitle("chargedH isolation cut efficiency");
  h1_effChIso_EB->GetXaxis()->SetTitle("Etrue");
  h1_effChIso_EE->GetXaxis()->SetTitle("Etrue");
  h1_effChIso_EB->SetMarkerStyle(20);
  h1_effChIso_EE->SetMarkerStyle(20);
  h1_effChIso_EB->SetMarkerColor(4);
  h1_effChIso_EE->SetMarkerColor(2);
  // 
  TGraphAsymmErrors *h1_effNhIso_EB = new TGraphAsymmErrors(H_trueEne_okNhIso_EB,H_trueEne_EB);
  TGraphAsymmErrors *h1_effNhIso_EE = new TGraphAsymmErrors(H_trueEne_okNhIso_EE,H_trueEne_EE);
  h1_effNhIso_EB->SetTitle("neutralH isolation cut efficiency");
  h1_effNhIso_EE->SetTitle("neutralH isolation cut efficiency");
  h1_effNhIso_EB->GetXaxis()->SetTitle("Etrue");
  h1_effNhIso_EE->GetXaxis()->SetTitle("Etrue");
  h1_effNhIso_EB->SetMarkerStyle(20);
  h1_effNhIso_EE->SetMarkerStyle(20);
  h1_effNhIso_EB->SetMarkerColor(4);
  h1_effNhIso_EE->SetMarkerColor(2);


  // Plots
  gStyle->SetOptStat(0);

  TCanvas c1a("c1a","c1a",1);
  H_pt_EB -> Draw();
  c1a.SaveAs("pT_EB.png");
  TCanvas c1b("c1b","c1b",1);
  H_pt_EE -> Draw();
  c1b.SaveAs("pT_EE.png");

  TCanvas c2("c2","c2",1);
  H_eta -> Draw();
  c2.SaveAs("eta.png");

  TCanvas c3a("c3a","c3a",1);
  H_EmaxOverEtrue_EB -> Draw("hist");
  c3a.SaveAs("EmaxOverEtrue_EB.png");
  TCanvas c3b("c3b","c3b",1);
  H_EmaxOverEtrue_EE -> Draw("hist");
  c3b.SaveAs("EmaxOverEtrue_EE.png");

  TCanvas c4a("c4a","c4a",1);
  H_E25OverEtrue_EB -> Draw("hist");
  c4a.SaveAs("E25OverEtrue_EB.png");
  TCanvas c4b("c4b","c4b",1);
  H_E25OverEtrue_EE -> Draw("hist");
  c4b.SaveAs("E25OverEtrue_EE.png");

  TCanvas c5a("c5a","c5a",1);
  H_EneOverEtrue_EB -> Draw("hist");
  c5a.SaveAs("EneOverEtrue_EB.png");
  TCanvas c5b("c5b","c5b",1);
  H_EneOverEtrue_EE -> Draw("hist");
  c5b.SaveAs("EneOverEtrue_EE.png");


  // cosmetics
  H_EmaxOverEtrue_EB->SetLineColor(2);
  H_E25OverEtrue_EB->SetLineColor(3);
  H_EneOverEtrue_EB->SetLineColor(4);
  H_EmaxOverEtrue_EE->SetLineColor(2);
  H_E25OverEtrue_EE->SetLineColor(3);
  H_EneOverEtrue_EE->SetLineColor(4);
  H_EmaxOverEtrue_EB->SetLineWidth(2);
  H_E25OverEtrue_EB->SetLineWidth(2);
  H_EneOverEtrue_EB->SetLineWidth(2);
  H_EmaxOverEtrue_EE->SetLineWidth(2);
  H_E25OverEtrue_EE->SetLineWidth(2);
  H_EneOverEtrue_EE->SetLineWidth(2);

  TLegend *leg;
  leg = new TLegend(0.25,0.3,0.5,0.55);
  leg->SetFillStyle(0);
  leg->SetBorderSize(0);
  leg->SetTextSize(0.05);
  leg->SetFillColor(0);
  leg->AddEntry(H_EmaxOverEtrue_EB, "Emax/Etrue", "l");
  leg->AddEntry(H_E25OverEtrue_EB,  "E25/Etrue", "l");
  leg->AddEntry(H_EneOverEtrue_EB,  "Ene/Etrue", "l");

  TCanvas c6a("c6a","c6a",1);  
  H_EneOverEtrue_EB  -> Draw("hist");
  H_E25OverEtrue_EB  -> Draw("samehist");
  H_EmaxOverEtrue_EB -> Draw("samehist");
  leg->Draw();
  c6a.SaveAs("ExOverEtrue_EB.png");
  TCanvas c6b("c6b","c6b",1);  
  H_EneOverEtrue_EE  -> Draw("hist");
  H_E25OverEtrue_EE  -> Draw("samehist");
  H_EmaxOverEtrue_EE -> Draw("samehist");
  leg->Draw();
  c6b.SaveAs("ExOverEtrue_EE.png");

  TCanvas c7a("c7a","c7a",1);
  P_EmaxOverEtrueVsEtrue_EB -> Draw();
  c7a.SaveAs("EmaxOverEtrueVsEtrue_EB.png");
  TCanvas c7b("c7b","c7b",1);
  P_EmaxOverEtrueVsEtrue_EE -> Draw();
  c7b.SaveAs("EmaxOverEtrueVsEtrue_EE.png");

  TCanvas c8a("c8a","c8a",1);
  P_E25OverEtrueVsEtrue_EB -> Draw();
  c8a.SaveAs("E25OverEtrueVsEtrue_EB.png");
  TCanvas c8b("c8b","c8b",1);
  P_E25OverEtrueVsEtrue_EE -> Draw();
  c8b.SaveAs("E25OverEtrueVsEtrue_EE.png");

  TCanvas c9a("c9a","c9a",1);
  P_EneOverEtrueVsEtrue_EB -> Draw();
  c9a.SaveAs("EneOverEtrueVsEtrue_EB.png");
  TCanvas c9b("c9b","c9b",1);
  P_EneOverEtrueVsEtrue_EE -> Draw();
  c9b.SaveAs("EneOverEtrueVsEtrue_EE.png");

  // cosmetics
  P_EmaxOverEtrueVsEtrue_EB->SetLineColor(2);
  P_E25OverEtrueVsEtrue_EB->SetLineColor(3);
  P_EneOverEtrueVsEtrue_EB->SetLineColor(4);
  P_EmaxOverEtrueVsEtrue_EE->SetLineColor(2);
  P_E25OverEtrueVsEtrue_EE->SetLineColor(3);
  P_EneOverEtrueVsEtrue_EE->SetLineColor(4);
  
  TH2F *myH = new TH2F("myH","",100,0,4500,100,0,1);
  myH->GetXaxis()->SetTitle("Etrue");
  myH->GetYaxis()->SetTitle("Ex / Etrue");

  TCanvas c10a("c10a","c10a",1);  
  myH->Draw();
  P_EmaxOverEtrueVsEtrue_EB -> Draw("same");
  P_E25OverEtrueVsEtrue_EB  -> Draw("same");
  P_EneOverEtrueVsEtrue_EB  -> Draw("same");
  leg->Draw();
  c10a.SaveAs("ExOverEtrueVsEtrue_EB.png");
  TCanvas c10b("c10b","c10b",1);  
  myH->Draw();
  P_EmaxOverEtrueVsEtrue_EE -> Draw("same");
  P_E25OverEtrueVsEtrue_EE  -> Draw("same");
  P_EneOverEtrueVsEtrue_EE  -> Draw("same");
  leg->Draw();
  c10b.SaveAs("ExOverEtrueVsEtrue_EE.png");



  TLegend *leg2;
  leg2 = new TLegend(0.25,0.15,0.5,0.4);
  leg2->SetFillStyle(0);
  leg2->SetBorderSize(0);
  leg2->SetTextSize(0.05);
  leg2->SetFillColor(0);
  leg2->AddEntry(h1_effHoE_EB,  "EB", "p");
  leg2->AddEntry(h1_effHoE_EE,  "EE", "p");
  leg2->AddEntry(h1_effHoET_EB, "EB, with tower", "p");
  leg2->AddEntry(h1_effHoET_EE, "EE, with tower", "p");

  TH2F *myH2 = new TH2F("myH2","",100,0,4500,100,0.8,1.);
  myH2->GetXaxis()->SetTitle("Etrue");
  myH2->GetYaxis()->SetTitle("H/E efficiency");

  TCanvas c11a("c11a","c11a",1);
  myH2->Draw();
  h1_effHoE_EB->Draw("sameP");
  h1_effHoE_EE->Draw("sameP");
  h1_effHoET_EB->Draw("sameP");
  h1_effHoET_EE->Draw("sameP");
  leg2->Draw();
  c11a.SaveAs("HoEcutEffVsEnergy.png");

  TLegend *leg3;
  leg3 = new TLegend(0.25,0.15,0.5,0.4);
  leg3->SetFillStyle(0);
  leg3->SetBorderSize(0);
  leg3->SetTextSize(0.05);
  leg3->SetFillColor(0);
  leg3->AddEntry(h1_effHoEvsEta,  "with cone",  "p");
  leg3->AddEntry(h1_effHoETvsEta, "with tower", "p");

  TH2F *myH3 = new TH2F("myH3","",100,-2.6,2.6,100,0.8,1.);
  myH3->GetXaxis()->SetTitle("#eta true");
  myH3->GetYaxis()->SetTitle("H/E efficiency");

  TCanvas c13a("c13a","c13a",1);
  myH3->Draw();
  h1_effHoEvsEta->Draw("sameP");
  h1_effHoETvsEta->Draw("sameP");
  leg3->Draw();
  c13a.SaveAs("HoEcutEffvsEta_ETgt200.png");

  TH2F *myH4 = new TH2F("myH4","",100,-3.15,3.15,100,0.8,1.);
  myH4->GetXaxis()->SetTitle("#phi true");
  myH4->GetYaxis()->SetTitle("H/E efficiency");

  TCanvas c14a("c14a","c14a",1);
  myH4->Draw();
  h1_effHoEvsPhi->Draw("sameP");
  h1_effHoETvsPhi->Draw("sameP");
  leg3->Draw();
  c14a.SaveAs("HoEcutEffvsPhi_ETgt200.png");


  TLegend *leg4;
  leg4 = new TLegend(0.25,0.15,0.5,0.4);
  leg4->SetFillStyle(0);
  leg4->SetBorderSize(0);
  leg4->SetTextSize(0.05);
  leg4->SetFillColor(0);
  leg4->AddEntry(H_EneOverEtrue_okHoE_EB, "H/E<0.05", "l");
  leg4->AddEntry(H_EneOverEtrue_noHoE_EB, "H/E>0.05", "l");
  
  TCanvas c15a("c15a","c15a",1);
  H_EneOverEtrue_okHoE_EB ->SetLineColor(2);
  H_EneOverEtrue_okHoE_EB ->SetLineWidth(2);
  H_EneOverEtrue_noHoE_EB ->SetLineColor(4);
  H_EneOverEtrue_noHoE_EB ->SetLineWidth(2);
  H_EneOverEtrue_okHoE_EB -> DrawNormalized("hist");
  H_EneOverEtrue_noHoE_EB -> DrawNormalized("samehist");
  leg4->Draw();
  c15a.SetLogy();
  c15a.SaveAs("EoverEtrue_passFailHoE_EB.png");

  TCanvas c15b("c15b","c15b",1);
  H_EneOverEtrue_okHoE_EE ->SetLineColor(2);
  H_EneOverEtrue_okHoE_EE ->SetLineWidth(2);
  H_EneOverEtrue_noHoE_EE ->SetLineColor(4);
  H_EneOverEtrue_noHoE_EE ->SetLineWidth(2);
  H_EneOverEtrue_okHoE_EE -> DrawNormalized("hist");
  H_EneOverEtrue_noHoE_EE -> DrawNormalized("samehist");
  leg4->Draw();
  c15b.SetLogy();
  c15b.SaveAs("EoverEtrue_passFailHoE_EE.png");

  TCanvas c15c("c15c","c15c",1);
  H_EneOverEtrue_okHoET_EB ->SetLineColor(2);
  H_EneOverEtrue_okHoET_EB ->SetLineWidth(2);
  H_EneOverEtrue_noHoET_EB ->SetLineColor(4);
  H_EneOverEtrue_noHoET_EB ->SetLineWidth(2);
  H_EneOverEtrue_okHoET_EB -> DrawNormalized("hist");
  H_EneOverEtrue_noHoET_EB -> DrawNormalized("samehist");
  leg4->Draw();
  c15c.SetLogy();
  c15c.SaveAs("EoverEtrue_passFailHoEwithTower_EB.png");

  TCanvas c15d("c15d","c15d",1);
  H_EneOverEtrue_okHoET_EE ->SetLineColor(2);
  H_EneOverEtrue_okHoET_EE ->SetLineWidth(2);
  H_EneOverEtrue_noHoET_EE ->SetLineColor(4);
  H_EneOverEtrue_noHoET_EE ->SetLineWidth(2);
  H_EneOverEtrue_okHoET_EE -> DrawNormalized("hist");
  H_EneOverEtrue_noHoET_EE -> DrawNormalized("samehist");
  leg4->Draw();
  c15d.SetLogy();
  c15d.SaveAs("EoverEtrue_passFailHoEwithTower_EE.png");


  

  TLegend *leg5;
  leg5 = new TLegend(0.25,0.15,0.5,0.4);
  leg5->SetFillStyle(0);
  leg5->SetBorderSize(0);
  leg5->SetTextSize(0.05);
  leg5->SetFillColor(0);
  leg5->AddEntry(h1_effSee_EB, "EB", "p");
  leg5->AddEntry(h1_effSee_EE, "EE", "p");

  TH2F *myH2b = new TH2F("myH2b","",100,0,4500,100,0.8,1.);
  myH2b->GetXaxis()->SetTitle("Etrue");
  myH2b->GetYaxis()->SetTitle("SigmaIeIe cut efficiency");

  TCanvas c16a("c16a","c16a",1);
  myH2b->Draw();
  h1_effSee_EB->Draw("sameP");
  h1_effSee_EE->Draw("sameP");
  leg5->Draw();
  c16a.SaveAs("SeecutEffVsEnergy.png");

  TH2F *myH2c = new TH2F("myH2c","",100,0,4500,100,0.8,1.);
  myH2c->GetXaxis()->SetTitle("Etrue");
  myH2c->GetYaxis()->SetTitle("chargedH isolation cut efficiency");

  TCanvas c16b("c16b","c16b",1);
  myH2c->Draw();
  h1_effChIso_EB->Draw("sameP");
  h1_effChIso_EE->Draw("sameP");
  leg5->Draw();
  c16b.SaveAs("ChHadronIsocutEffVsEnergy.png");

  TH2F *myH2d = new TH2F("myH2d","",100,0,4500,100,0.8,1.);
  myH2d->GetXaxis()->SetTitle("Etrue");
  myH2d->GetYaxis()->SetTitle("neutralH isolation cut efficiency");

  TCanvas c16c("c16c","c16c",1);
  myH2d->Draw();
  h1_effNhIso_EB->Draw("sameP");
  h1_effNhIso_EE->Draw("sameP");
  leg5->Draw();
  c16c.SaveAs("NHadronIsocutEffVsEnergy.png");
}
