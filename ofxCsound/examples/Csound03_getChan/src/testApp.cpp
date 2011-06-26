#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	csnd.setupFile("randomSine.csd");
	csnd.start();

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	received_x = csnd.getChan("point_x");
	received_y = csnd.getChan("point_y");
	//printf("val X: %f , val Y: %f \n", received_x, received_y);
	
	ofBackground(0, 0, 0);
	ofSetColor(255, received_y*255, received_x*255);
	ofFill();
	ofBeginShape();
		ofVertex(received_y*700,received_y*1000);
		ofVertex(received_x*700, 700);
		ofVertex(received_x*700,received_y*1000);
	ofEndShape();

	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key == 's') {csnd.start();}
	if (key == ' ') {csnd.pause();}
	
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

