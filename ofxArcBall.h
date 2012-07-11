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
    void startDrag();
    void stopDrag();
	void begin();
	void end();
    ofQuaternion getOrientation();
    
protected:
    void mouseDragged(ofMouseEventArgs &e);
    ofVec3f getMouseOnSphere();
    ofVec3f vDown,vTo;
	ofQuaternion qDown,qTo;
};
