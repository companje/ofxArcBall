#include "ofxArcBall.h"


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

void ofxArcBall::startDrag() {
    ofAddListener(ofEvents.mouseDragged, this, &ofxArcBall::mouseDragged);
	vDown = getMouseOnSphere();
	qDown = qTo;    
}

void ofxArcBall::stopDrag() {
    ofRemoveListener(ofEvents.mouseDragged, this, &ofxArcBall::mouseDragged);
}

void ofxArcBall::mouseDragged(ofMouseEventArgs &e) {	
    vTo = getMouseOnSphere();
    ofVec3f c = vDown.crossed(vTo);
	qTo = qDown * ofQuaternion(c.x,c.y,c.z,vDown.dot(vTo));
}

ofVec3f ofxArcBall::getMouseOnSphere() {
    ofVec3f v;
	v.x = ofMap(ofGetMouseX(),0,ofGetWidth(),-.5,.5);
	v.y = ofMap(ofGetMouseY(),0,ofGetHeight(),-.5,.5);
    if (v.squareLength()>1.0f) v.normalize();
    else v.z = sqrt(1.0f - v.squareLength());
    return v;
}

ofQuaternion ofxArcBall::getOrientation() {
    return qTo;
}