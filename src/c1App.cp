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
    
    ofSetColor(0);
//    ofPolyline line = ofPolyline(linePoints);
//    line.draw();
    
    float w = ofGetScreenWidth();
        float h = ofGetScreenHeight();
    
    float curveFactor = 1/4.0;
    
    float c1x = ofMap(params->potA, 0, 1023, -w*curveFactor, w*curveFactor);
    float c1y = ofMap(params->potA, 0, 1023, -h*curveFactor, h*curveFactor);
    float c2x = ofMap(params->potB, 0, 1023, -w*curveFactor, w*curveFactor);
    float c2y = ofMap(params->potB, 0, 1023, -h*curveFactor, h*curveFactor);
    
    
    ofSeedRandom(10);
//    int num_items = 10;
    
//    float stringRand = 100;
    float stringRand = ofMap(params->potA, 0, 1023, 100, 500);
    
    int num_items = ofMap(params->potB, 0, 1023, 1, 50);
    
    
    float square_length = 200;
    float start_x = (w - (square_length + 4*stringRand)) / 2.0;
    float start_y = (h - (square_length + 4*stringRand))  / 2.0;
    
    vector<ofPoint> sPoints = {
      ofPoint(start_x, start_y),
        ofPoint(start_x + square_length, start_y),
        ofPoint(start_x + square_length, start_y + square_length),
        ofPoint(start_x, start_y + square_length),
        ofPoint(start_x, start_y)
    };
    
    for (int j=1; j<sPoints.size(); j++) {
        ofPoint prevPoint = sPoints[j-1];
        ofPoint nextPoint = sPoints[j];
        for (int i=0; i<num_items; i++) {
            ofPolyline p;
            ofPoint c1 = ofPoint(c1x, c1y);
            ofPoint v1 = ofPoint(ofRandom(prevPoint.x - stringRand, prevPoint.x + stringRand), ofRandom(prevPoint.y - stringRand, prevPoint.y + stringRand));
            ofPoint v2 = ofPoint(ofRandom(nextPoint.x - stringRand, nextPoint.x + stringRand), ofRandom(nextPoint.y - stringRand, nextPoint.y + stringRand));
            ofPoint c2 = ofPoint(c2x, c2y);
            
            p.curveTo(c1);
            p.curveTo(v1);
            p.curveTo(v2);
            p.curveTo(c2);
            
            p.draw();
        }
        
    }
    
    
    
 
    

    
}

//--------------------------------------------------------------
void c1App::cleanup(){
    
}
