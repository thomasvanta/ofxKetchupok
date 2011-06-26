/*
 TODO:
 - put whole csound framework into ofxcsound
 - use audioloop/Soundstream
 */

#include "ofxCsound.h"

//-------------------------------------------------
void ofxCsound::setupFile(string fileName) {
	/* search for file in OF/data */
	fileName = ofToDataPath(fileName);
	/* make instance of csound */
	csound = new CppSound;
	/* compile the instrument and score from .csd file */
	csound->Compile((char*)fileName.c_str());
	/* start csound in it's own thread */
	csThread = new CsoundPerformanceThread(csound->getCsound());
}
//-------------------------------------------------
void ofxCsound::quickSetup() {
	/* create string that holds an entire csd file 
	 ATTENTION! - tabs or spaces in csdText can cause csound compile errors!*/ 
std::string csdText = "<CsoundSynthesizer> \n\
<CsOptions> \n\
csound -odac -g  temp.orc temp.sco \n\
</CsOptions>  \n\
<CsInstruments>  \n\
sr = 44100  \n\
kr = 4410  \n\
ksmps = 10  \n\
nchnls = 1  \n\
instr 1  \n\
k1 chnget \"freq\" \n\
a1 oscil 10000, k1+200, 1  \n\
out a1  \n\
endin   \n\
</CsInstruments>   \n\
<CsScore>  \n\
f1 0 1024 10 1  \n\
i1 0 100    \n\
</CsScore> \n\
</CsoundSynthesizer>";

	/* make instance of csound */
	csound = new CppSound;
	/* set the csd text */ 
	csound->setCSD(csdText); 
	/* export csd text for performance */ 
	csound->exportForPerformance(); 
	/* compile the instrument and score from csd text */ 
	csound->compile();
	/* start csound in it's own thread */
	csThread = new CsoundPerformanceThread(csound->getCsound());
	
} 
//-------------------------------------------------
int ofxCsound::start()
{	
	csThread->Play();	
}
//-------------------------------------------------
void ofxCsound::pause()
{	
	csThread->Pause();	
}
//-------------------------------------------------
void ofxCsound::stop()
{
	csThread->Stop();
	delete csThread;
}
//-------------------------------------------------
void ofxCsound::setChan(const char *name, double value)
{
	csound->SetChannel(name, value);
}

//-------------------------------------------------
MYFLT ofxCsound::getChan(const char *name)
{
	received_myflt = csound->GetChannel(name);
	return (received_myflt);
}

//-------------------------------------------------
void ofxCsound::scoreEvent(char type, const float *pFields)
{	
	csound->ScoreEvent(type, pFields, sizeof(pFields));
}




