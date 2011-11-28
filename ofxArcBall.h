/*
 *  ofxArcBall.h
 *  arcballExample
 *
 *  Created by Rick Companje on 29-10-10.
 *  Copyright 2010 Globe4D. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofxArcBall {
public:
	
	ofxArcBall();
	~ofxArcBall();
	
	void mousePressed(ofMouseEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);

	ofVec3f mouseToSphere(float x, float y);
	
	void begin();
	void end();
	
	ofVec3f vDown,vTo;
	ofQuaternion qDown,qTo;
};
