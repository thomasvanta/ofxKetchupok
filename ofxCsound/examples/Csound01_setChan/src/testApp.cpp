#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	csnd.setupFile("testSetChannel.csd");
	/* If you want to write Csound-Code directly into the ofxCsound class, you can use the setup() function like this:
		csnd.setup();
	*/
	csnd.start();
}

//--------------------------------------------------------------
void testApp::update(){
	}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 0, 0);
	ofDrawBitmapString("click & drag inside the window to change pitch", 200, 170);
	ofDrawBitmapString("press 's' to start csound", 200, 200);
	ofDrawBitmapString("press 'space' to pause csound", 200, 230);

	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 's') {csnd.start();}		
	if (key == ' ') {csnd.pause();}
	//stop csound before app ends, to avoid crashing the thread
	if (key == 27) {csnd.stop();}
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){



}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// send mouse-y values to channel "freq"
	csnd.setChan("freq", y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

