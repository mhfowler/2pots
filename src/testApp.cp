#include "testApp.h"


//--------------------------------------------------------------
void testApp1::setup(){
}


//--------------------------------------------------------------
void testApp1::update(){
    
}

//--------------------------------------------------------------
void testApp1::draw(){
    
    // test firmata
    
    
    float varX = 16;
    float varY = 149;
    
    float now = ofGetElapsedTimef();
    ofSeedRandom(10);
    
    ofBackground(255, 255, 255);
    
    //    float x1 = ofMap(potA, 0, 255, 100, 500);
    //    float y1 = ofMap(potA, 0, 255, 100, 300);
    //    float x2 = ofMap(potB, 0, 255, 100, 500);
    //    float y2 = ofMap(potB, 0, 255, 100, 300);
    
    
    float x1 = 300;
    float y1 = 100;
    int rect_width = 400;
    int rect_height = 200;
    float x2 = x1 + rect_height;
    float y2 = y1 + rect_height;

    
    float aDelt = ofMap(params->potA, 0, 1024, 0, 400);
    float x1Delt = x1 + aDelt;
    
    float bDelt = ofMap(params->potB, 0, 1024, 0, 400);
    float x2Delt = x2 + bDelt;
    
    ofVec2f center = ofVec2f(0, 0);
    vector<ofPoint> linePoints = {
        
        ofPoint(
                x1Delt,
                y1
                ),
        ofPoint(
                x2Delt,
                y2
                ),
    };
    ofSetColor(0);
    ofPolyline line = ofPolyline(linePoints);
    line.draw();
    
    
    
    ofSetColor(255, 0, 0);
    ofDrawCircle(x1Delt, y1, 4);
    
    ofSetColor(0, 0, 255);
    ofDrawCircle(x2Delt, y2, 4);
    
    ofSetColor(0);
    vector<ofPoint> rectPoints = {
        ofPoint(
                x1,
                y1
                ),
        ofPoint(
                x1 + rect_width,
                100
                ),
        ofPoint(
                x1 + rect_width,
                y1 + rect_height
                ),
        ofPoint(
                x1,
                y1 + rect_height
                ),
        ofPoint(
                x1,
                y1
                )
    };
    ofPolyline rectLine = ofPolyline(rectPoints);
    rectLine.draw();
    
}

//--------------------------------------------------------------
void testApp1::cleanup(){
    
}
