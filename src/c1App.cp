#include "c1App.h"


//--------------------------------------------------------------
void c1App::setup(){
}


//--------------------------------------------------------------
void c1App::update(){
    
}

//--------------------------------------------------------------
void c1App::draw(){
    
    ofBackground(255, 255, 255);
    
    float x1 = 100;
    float y1 = 300;
    float x2 = 300;
    float y2 = 100;
    
    ofVec2f center = ofVec2f(0, 0);
    vector<ofPoint> linePoints = {
        
        ofPoint(
                x1,
                y1
                ),
        ofPoint(
                x2,
                y2
                ),
    };
    ofSetColor(0);
    ofPolyline line = ofPolyline(linePoints);
    line.draw();
    
}

//--------------------------------------------------------------
void c1App::cleanup(){
    
}
