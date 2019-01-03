#define Analysis_cxx
#include "Analysis.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analysis::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analysis.C
//      root> Analysis t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;
   
   TFile *OldFile = new TFile("OriginalTree.root");   //Get the Mother Root file
   TTree *OldTree = (TTree*)OldFile->Get("t1");       //Get the tree from the Mother Root File

   TFile *f1 = new TFile("NewFile.root","RECREATE");  //Create Daughter Root File 
   TTree *NewTree = OldTree->CloneTree(0);            //Clone the Tree from Mother File to a new Tree 

   NewTree->SetBranchAddress("i1",&i1);               //
   NewTree->SetBranchAddress("i2",&i2);               //
   NewTree->SetBranchAddress("i3",&i2);               //
   
   NewTree->SetBranchAddress("F1",&F1);               //Set All the branches as was in mother Root file
   NewTree->SetBranchAddress("F2",&F2);               //
   NewTree->SetBranchAddress("F3",&F3);               //

   NewTree->SetBranchAddress("v1",&v1);               //

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(i2<5) continue;                                  //Apply the cuts you want
      NewTree->Fill();                                    //Fill the new Root Tree
   }

   NewTree->Write();                                      //Write the New Tree in the New Root File
}
