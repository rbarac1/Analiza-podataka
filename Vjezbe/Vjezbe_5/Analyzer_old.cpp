#define Analyzer_cxx
#include "Analyzer.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Analyzer::Loop()
{
//   In a ROOT session, you can do:
//      root> .L Analyzer.C
//      root> Analyzer t
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

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}

void Analyzer::PlotHistogram()
{
  TH1F* Histo_pT1 = new TH1F("pT1","pT1",50,0,300);
  TH1F* Histo_pT2 = new TH1F("pT2","pT2",50,0,300);
  TH1F* Histo_Higgs = new TH1F("pT_Higgs","pT_Higgs",50,0,300);
  TLorentzVector P1,P2,P;
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
     Long64_t ientry = LoadTree(jentry);
     if (ientry < 0) break;
     nb = fChain->GetEntry(jentry);   nbytes += nb;
     Histo_pT1->Fill(sqrt(pow(DecayParticle1_px,2)+pow(DecayParticle1_py,2)));
     Histo_pT2->Fill(sqrt(pow(DecayParticle2_px,2)+pow(DecayParticle2_py,2)));
     P1.SetPxPyPzE(DecayParticle1_px,DecayParticle1_py,DecayParticle1_pz,DecayParticle1_E);
     P2.SetPxPyPzE(DecayParticle2_px,DecayParticle2_py,DecayParticle2_pz,DecayParticle2_E);
     P=P1+P2;
     Histo_Higgs->Fill(P.Pt());
  }
  gStyle->SetOptStat(0);
  TCanvas* canvas = new TCanvas();
  canvas->SetCanvasSize(1500, 700);
  TLegend* legend = new TLegend(0.6,0.75,0.9,0.9);
  Histo_pT1->SetTitle("Transverse momentum distribution of decay particles");
  Histo_pT1->GetXaxis()->SetTitle("pT");
  Histo_pT1->GetYaxis()->SetTitle("# Events");
  Histo_pT1->SetFillColor(kRed);
  legend->SetHeader("Simulation","C"); // option "C" allows to center the header
  legend->AddEntry(Histo_pT1,"pT1 distibution","f");
  legend->AddEntry(Histo_pT2,"pT2 distibution","f");
  canvas->Divide(2,1);
  canvas->cd(1);
  Histo_pT1->Draw();
  Histo_pT2->Draw("same");
  legend->Draw();
  canvas->cd(2);
  Histo_Higgs->SetTitle("Transverse momentum distribution of Higgs boson");
  Histo_Higgs->GetXaxis()->SetTitle("pT");
  Histo_Higgs->GetYaxis()->SetTitle("# Events");
  Histo_Higgs->Draw();
  canvas->SaveAs("Histo_pT.pdf");
  canvas->SaveAs("Histo_pT.png");
}
