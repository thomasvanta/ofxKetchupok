#ifndef _OF_X_CSOUND_APP
#define _OF_X_CSOUND_APP
#include "ofMain.h"
//#include "CppSound.hpp"
//#include "csPerfThread.hpp"
#include <CsoundLib/CppSound.hpp> // umbeannt, damit in den Frameworks gesucht wird
#include <CsoundLib/csPerfThread.hpp> // umbenannt..
#include <string>
#include <stdio.h>

class ofxCsound {

public:
	void setupFile(string fileName);
	void quickSetup();
	int start();
	void stop();
	void pause();
	void setChan(const char *name, double val);
	MYFLT getChan(const char *name);
	void scoreEvent(char type, const float *pFields);

	CppSound *csound;
	CsoundPerformanceThread* csThread;

private:
	MYFLT received_myflt;


};
#endif // _OF_X_CSOUND_APP