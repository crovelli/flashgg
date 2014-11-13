import FWCore.ParameterSet.Config as cms

process = cms.PSet()

process.fwliteInput = cms.PSet(
    fileNames   = cms.vstring(
        #'file:RSGravToGG_kMpl-02_M-5000_Tune4C_OutputFile_2.root'),
        'root://eoscms//eos/cms/store/group/phys_higgs/cmshgg/flashgg/ExoPhys14/alphaV1-96-g5e4dc54/RSGravToGG_kMpl-02_M-5000_Tune4C_13TeV-pythia8/ExoPhys14-alphaV1-96-g5e4dc54-v1-Phys14DR-PU20bx25_PHYS14_25_V1-v1/141112_020912/0000/myOutputFile_1.root',
        'root://eoscms//eos/cms/store/group/phys_higgs/cmshgg/flashgg/ExoPhys14/alphaV1-96-g5e4dc54/RSGravToGG_kMpl-02_M-5000_Tune4C_13TeV-pythia8/ExoPhys14-alphaV1-96-g5e4dc54-v1-Phys14DR-PU20bx25_PHYS14_25_V1-v1/141112_020912/0000/myOutputFile_2.root',
        'root://eoscms//eos/cms/store/group/phys_higgs/cmshgg/flashgg/ExoPhys14/alphaV1-96-g5e4dc54/RSGravToGG_kMpl-02_M-5000_Tune4C_13TeV-pythia8/ExoPhys14-alphaV1-96-g5e4dc54-v1-Phys14DR-PU20bx25_PHYS14_25_V1-v1/141112_020912/0000/myOutputFile_3.root'),
    maxEvents   = cms.int32(-1),                
    )

process.fwliteOutput = cms.PSet(
    fileName  = cms.string('analyzeFWLdiphot.root'),  
    )

process.DiphotonsBasic = cms.PSet(
    ## input specific for this analyzer
    #muons = cms.InputTag('muons')
)
