# OmegaPiPi

Version 0.1 - 15/12/2017

Documentation for OmegaPiPi analysis.

User Details:
Simon Hughes
simon.hughes1799@gmail.com


GitHub Links:
Bulk of the code
https://github.com/shughes1799/OmegaPiPi

Filter Code:
On Genova servers – backup to github


Data Backup Locations:
Currently on 
thehub6/shughes on the nuclear physics group and
Volatile in JLAB under clas g11 smhughes


Introduction

The aim of this document is to provide sufficient documentation to allow a new user to make use of the code base already developed to continue the work I began during my PhD.

This analysis was carried out on the g11a dataset from CLAS, studying the channel γp → ωππp.

For more detail on the this see the third part of my thesis 'A Fast Timing Hodoscope for CLAS12 and the First Measurement of the γp → ωππp Decay Channel'. Should be available from the Edinburgh University Library or Jefferson Lab's Collection.

The analysis code is based on the HASPECT framework, which is detailed on this wiki:
https://wiki.ge.infn.it/haspect/index.php/AnalysisFramework

The framework was designed and managed by Dr. Derek Glazier.


Structure of the analysis

Before utilising the analysis framework the raw dataset was 'cooked' to produce the standard 'banks'   of CLAS data. This is then processed using the g11 filter code written my Prof. Marco Battaglieri. This code is written in Fortran and is used to select out events of interest from the complete dataset to produce a manageable sized file set for further analysis.
The g11 dataset is well understood and through multiple previous analyses corrections have been developed and checked to improve the description of the dataset.

The g11 filter code includes:

Energy Corrections
Momentum Corrections
Tagger Corrections
Particle Identification

The g11 filter code does not include:

Acceptance corrections
Background subtraction
Timing corrections
Fiducial Cuts

Details on how to run the filter code can be found at:
https://wiki.ge.infn.it/haspect/index.php/Info_on_unskimmed_g11_ntuples_and_how_to_run_the_filter_code

My own version of the filter code is stored at: shughes@farmui.ge.infn.it

The current version of the code requires the detection of 2 positively charged and one negatively charged particle, a missing mass of between ~0.6-1.0 GeV/c2 and up to 2 neutral particles. Or the detection of 3 positively charged and 2 negatively charged particles, a missing mass of between 0.01 and ~0.3 GeV and up to 2 neutrals. The neutral detection is meant for decays of π0 to 2 γ. However although neutrals are allowed in the filter code, I have not yet implemented a method to allow these events to pass through the main analysis code. This could provide a significant boost to the statisics available to analyse.

Significant issue with the filter code
At a late stage of the initial analysis I realised there was a problem with the files in batches 15 and 16 of the 20 batches of runs. This was due to the way I attempted to comment out excluded files rather than just removing them from the list. This caused all files after a comment to not process properly. These groups of files were excluded from the initial analysis, but could be added back into a future analysis to increase the statistics available by roughly 10%.


Program Structure
GitHub - https://github.com/shughes1799/OmegaPiPi

The HASPECT framework was designed to be flexible and adjustable the requirements of the user. To reduce the complexity of each program and limit unnecessary processing time. The analysis framework that acts on the filtered data is split into several stages.


Stage 1:
Initial Corrections and Conversion from g11 banks to Particles for Analysis.

	/home/s0677668/Haspect/Version8/Events-master/Projects/BaseCLAStoHS/Control_CLAStoHS.C
	/home/s0677668/Haspect/Version8/Events-master/Projects/BaseCLAStoHS/CLAStoHS.C
	/home/s0677668/Haspect/Version8/Events-master/Projects/BaseCLAStoHS/CLAStoHS.h

Stage 2:
Further corrections and creation of combination particle objects for analysis using the dataset created in Stage 1.

	/home/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/Corrections/Control_Corrected5.C
	/home/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/Corrections/Corrected5.C
	/home/s0677668/Haspect/Version5/Events-master/Projects/OmegaPiPi5/Corrections/Corrected5.h

Stage 3:
Background Subtraction usin either Sideband Subtraction and sWeights.

Stage 3a: Sideband Subtraction
Produce histograms for signal and sideband regions.
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/Control_SB5Selector.C
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/SB5Selector.C
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/SB5Selector.h

Fit polynomial to the sideband histograms of the missing mass, to determine normalisation values for the sidesbands.
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Nov2017SBNormalisationScript.C
Normalise sideband regions based on fit and subtract from signal region.
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/Acceptance/AcceptancePlots/Nov2017SBScript.C
	
Stage 3b: sWeights Subtraction

Fit discriminating variable (missing mass) using a guassian (signal) and a 3rd order Chebychev polynomial (background) around the omega peak to create event by event weights.
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/sWFitting/March2017FitHSSimpleBins.C
Apply weights to dataset produced in stage 2 to produce weighted histograms.
	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/Control_Feb2017sWeightPlotter.C
 	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/Feb2017sWeightPlotter.C
 	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/Feb2017sWeightPlotter.h

Stage 4:
Further scripts for fits to the histograms (Folder)
	/home/s0677668/Haspect/Version4/Events-	master/Projects/OmegaPiPi3/Plotting/SBPlots/PreSubmissionScripts/
Acceptance corrections for the histograms
	/home/s0677668/Haspect/Acceptance/Oct2017/Oct2017AcceptanceCorr2.C
	/home/s0677668/Haspect/Acceptance/Oct2017/run_analysis_acceptance3.C
	/home/s0677668/Haspect/Acceptance/Oct2017/analysis_acceptance3.C
	/home/s0677668/Haspect/Acceptance/Oct2017/analysis_acceptance3.h
Tests for beam-walk in the datafiles
	/home/s0677668/Haspect/Scripts/May2017BeamWalk.C 
	/home/s0677668/Haspect/Scripts/May2017BeamWalk.h 


Program structure

The programs used in stages 1 and 2 of the process along with the programs used to produce the histrograms in stage 3, all utilise the same basic structure. Stages 2 and 3 utilise the TSelector framework to streamline and improve consistency in he code. Their basic structure is produced using a configuration file, that is pointed to a datafile produced by the previous stage and configured for the requirements of the software. 

	/home/s0677668/Haspect/Version8/Events-master/Projects/OmegaPiPi8/sWeights/ConfigSel.C 


The main structure of the programs comprises 5 key functions that prepare for and process the data supplied to them. Within these additional functions or objects can be added to customise the programs. The set-up makes use of the scalable multi-threaded capabilities of the PROOF functions of ROOT. https://root.cern.ch/proof Every program is designed to be run on any number of cores, up to the limitations of the system running the program. 

Begin(): 		called every time a loop on the tree starts.
SlaveBegin(): 		called after Begin(), when on PROOF called only on the slave servers.
Process(): 		called for each event, in this function you decide what to read and fill your histograms.
SlaveTerminate()	called at the end of the loop on the tree, when on PROOF called only on the slave servers.
Terminate(): 		called at the end of the loop on the tree.

Both the begin functions are typically where objects and variables are initialised and process is where the actions of the code takes place. I typically initialised objects in SlaveBegin() seperately creating objects on each used core.

Most of the the other programs used are scripts which read in a particular root file, perform one of more operations on the histrograms or values from the tree and output further histograms are results.

Further detail on the structure of methods used and the reasoning behind the way background subtraction is carried out is detailed in my thesis.




