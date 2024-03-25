// Tell emacs that this is a C++ source
//  -*- C++ -*-.
// ----------------------------------------------------------------------------
// 'TracksInJetsQAMaker.h'
// Derek Anderson
// 03.25.2024
//
// A small Fun4All module to produce QA plots for tracks,
// hits, and more.
// ----------------------------------------------------------------------------

#ifndef TRACKSINJETSQAMAKER_H
#define TRACKSINJETSQAMAKER_H

// c++ utilities
#include <string>
#include <vector>
#include <utility>
// root libraries
#include <TH1.h>
#include <TH2.h>
#include <TFile.h>
// fun4all libraries
#include <fun4all/SubsysReco.h>
#include <phool/PHCompositeNode.h>
#include <fun4all/Fun4AllReturnCodes.h>



// TracksInJetsQAMaker definition --------------------------------------------

class TracksInJetsQAMaker : public SubsysReco {

  public:

    // ctor/dtor
    TracksInJetsQAMaker(const std::string &name = "TracksInJetsQAMaker", const std::string& sOutFileName = "tracksinjets.root");
    ~TracksInJetsQAMaker() override;

    // f4a methods
    int  Init(PHCompositeNode* topNode)          override;
    int  InitRun(PHCompositeNode* topNode)       override;
    int  process_event(PHCompositeNode* topNode) override;
    int  ResetEvent(PHCompositeNode* topNode)    override;
    int  EndRun(const int runnumber)             override;
    int  End(PHCompositeNode* topNode)           override;
    int  Reset(PHCompositeNode*  /*topNode*/)    override;

   private:

     // io members
     TFile* m_outFile = NULL;

     // top level information
     int64_t m_runNum = 0;
     int64_t m_evtNum = 0;

};  // end TracksInJetsQAMaker

#endif

// end ------------------------------------------------------------------------