import FWCore.ParameterSet.Config as cms

process = cms.PSet()

process.fwliteInput = cms.PSet(
    fileNames   = cms.vstring(
        'file:GJets_HT-600toInf_myOutputFile_1.root'),  
    #'root://eoscms//eos/cms/store/relval/CMSSW_7_0_0_pre11/RelValProdTTbar/GEN-SIM-RECO/START70_V4-v1/00000/0EA82C3C-646A-E311-9CB3-0025905A6070.root'), ## mandatory
    maxEvents   = cms.int32(100),                      ## optional
    )

process.fwliteOutput = cms.PSet(
    fileName  = cms.string('analyzeFWLdiphot.root'),  ## mandatory
    )

process.DiphotonsBasic = cms.PSet(
    ## input specific for this analyzer
    #muons = cms.InputTag('muons')
)
