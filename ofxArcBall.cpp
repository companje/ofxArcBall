#include "ofxArcBall.h"

ofxArcBall::ofxArcBall() {
	ofAddListener(ofEvents.mousePressed, this, &ofxArcBall::mousePressed);
	ofAddListener(ofEvents.mouseDragged, this, &ofxArcBall::mouseDragged);
}

void ofxArcBall::begin() {
	float angle;
	ofVec3f axis;
	qTo.getRotate(angle, axis);
    
	ofPushMatrix();
	ofRotate(angle,axis.x,axis.y,axis.z);
}

void ofxArcBall::end() {
	ofPopMatrix();
}

void ofxArcBall::mousePressed(ofMouseEventArgs &e) {
	vDown = mouseToSphere(e.x,e.y);
	qDown = qTo;
}

void ofxArcBall::mouseDragged(ofMouseEventArgs &e) {	
	vTo = mouseToSphere(e.x,e.y);
	float x = vDown.crossed(vTo).x;
	float y = vDown.crossed(vTo).y;
	float z = vDown.crossed(vTo).z;
	float w = vDown.dot(vTo);
	 
	qTo = qDown * ofQuaternion(x,y,z,w);
}

ofVec3f ofxArcBall::mouseToSphere(float x, float y) {  //0...ofGetWidth()
    ofVec3f v(x,y);
	v.x = ofMap(x,0,ofGetWidth(),-0.5,0.5);
	v.y = ofMap(y,0,ofGetHeight(),-0.5,0.5);
    if (v.squareLength()>1.0f) v.normalize();
    else v.z = sqrt(1.0f - v.squareLength());
    return v;
}

ofxArcBall::~ofxArcBall() {
	//ofRemoveListener(ofEvents.mousePressed, this, &ofxArcBall::mousePressed);
	//ofRemoveListener(ofEvents.mouseDragged, this, &ofxArcBall::mouseDragged);
}
