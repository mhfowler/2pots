#include "h1App.h"


//--------------------------------------------------------------
void h1App::setup(){
}


//--------------------------------------------------------------
void h1App::update(){
    
}

//--------------------------------------------------------------
void h1App::draw(){
    
    ofBackground(255, 255, 255);
    
//    float x1 = 100;
//    float y1 = 300;
//    float x2 = 300;
//    float y2 = 100;
//    
//    ofVec2f center = ofVec2f(0, 0);
//    vector<ofPoint> linePoints = {
//        
//        ofPoint(
//                x1,
//                y1
//                ),
//        ofPoint(
//                x2,
//                y2
//                ),
//    };
//    ofSetColor(0);
//    ofPolyline line = ofPolyline(linePoints);
//    line.draw();
    
    float h = ofGetScreenHeight();
    float w = ofGetScreenWidth();
    
//    ofFill(0);
    float col1 = ofMap(params->potB, 0, 1023, 0, 255);
//    float col2 = ofMap(params->potA, 0, 1023, 0, 255÷/2.0);
//    float col = col1 + col2;
    float col = col1;
    
    ofSetColor(col, col, col);
    ofBeginShape();
    ofVertex(0,0);
    ofVertex(w, 0);
    ofVertex(w, h);
    ofVertex(0, h);
    ofVertex(0, 0);
    ofEndShape();
    
}

//--------------------------------------------------------------
void h1App::cleanup(){
    
}
