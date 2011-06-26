#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	csnd.setupFile("testEvents.csd");
	csnd.start();
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 0, 0);
	ofDrawBitmapString("Use 1, 2, 3 and 4 to trigger Note-Events to Csound!", 200, 170);
	ofDrawBitmapString("press 's' to start csound", 200, 200);
	ofDrawBitmapString("press 'space' to pause csound", 200, 230);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 's') {csnd.start();}		
	if (key == ' ') {csnd.pause();}
	
	// use numbers to trigger events
	if (key == '1') {float myArray[] = {1, 0, 1, 740}; 
		csnd.scoreEvent('i', myArray);}
	if (key == '2') {float myArray[] = {1, 0, 1, 400}; 
		csnd.scoreEvent('i', myArray);}
	if (key == '3') {float myArray[] = {1, 0, 1, 1740}; 
		csnd.scoreEvent('i', myArray);}
	if (key == '4') {float myArray[] = {1, 0, 1, 1240}; 
		csnd.scoreEvent('i', myArray);}
	
	//stop csound before app ends, to avoid crashing the thread
	if (key == 27) {printf("Csound thread stopped.\n"); 
		csnd.stop();}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){



}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

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

