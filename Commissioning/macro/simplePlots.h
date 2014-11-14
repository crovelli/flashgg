//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 13 12:36:26 2014 by ROOT version 5.30/02
// from TTree singlePhotons/singlePhotons
// found on file: analyzeFWLdiphot.root
//////////////////////////////////////////////////////////

#ifndef simplePlots_h
#define simplePlots_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

class simplePlots {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Float_t         kinematics_pt;
   Float_t         kinematics_eta;
   Float_t         kinematics_phi;
   Float_t         energy_eMax;
   Float_t         energy_e5x5;
   Float_t         energy_energy;
   Float_t         energy_energyInitial;
   Float_t         energy_energyRegression;
   Float_t         identification_e1x5;
   Float_t         identification_e2x5;
   Float_t         identification_sigmaIetaIeta;
   Float_t         identification_r9;
   Float_t         identification_hoe;
   Float_t         identification_h1oe;
   Float_t         identification_h2oe;
   Float_t         identification_htoe;
   Float_t         identification_ht1oe;
   Float_t         identification_ht2oe;
   Char_t          identification_passEleVeto;
   Char_t          identification_hasPixelSeed;
   Float_t         isolation_trackIso;
   Float_t         isolation_ecalIso;
   Float_t         isolation_hcalIso;
   Float_t         isolation_chHadIso;
   Float_t         isolation_nHadIso;
   Float_t         isolation_photonIso;
   Float_t         mctruth_trueEnergy;
   Float_t         mctruth_truePt;
   Float_t         mctruth_trueEta;
   Float_t         mctruth_truePhi;
   Float_t         mctruth_minDR;

   // List of branches
   TBranch        *b_kinematics;   //!
   TBranch        *b_energy;   //!
   TBranch        *b_identification;   //!
   TBranch        *b_isolation;   //!
   TBranch        *b_mctruth;   //!

   simplePlots(TTree *tree=0);
   virtual ~simplePlots();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef simplePlots_cxx
simplePlots::simplePlots(TTree *tree)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("analyzeFWLdiphot.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("analyzeFWLdiphot.root");
      }
      f->GetObject("singlePhotons",tree);

   }
   Init(tree);
}

simplePlots::~simplePlots()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t simplePlots::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t simplePlots::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void simplePlots::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("kinematics", &kinematics_pt, &b_kinematics);
   fChain->SetBranchAddress("energy", &energy_eMax, &b_energy);
   fChain->SetBranchAddress("identification", &identification_e1x5, &b_identification);
   fChain->SetBranchAddress("isolation", &isolation_trackIso, &b_isolation);
   fChain->SetBranchAddress("mctruth", &mctruth_trueEnergy, &b_mctruth);
   Notify();
}

Bool_t simplePlots::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void simplePlots::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t simplePlots::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef simplePlots_cxx
