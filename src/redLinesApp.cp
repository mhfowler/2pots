#include "redLinesApp.h"


//--------------------------------------------------------------
void redLinesApp::setup(){
    
    
}


//--------------------------------------------------------------
void redLinesApp::update(){
    
}

void redLinesApp::cDrawLine(ofPolyline line) {
    
    vector<ofPoint> points = line.getVertices();
    
    float delta = ofMap(params->potB, 0, 1023, 0, 50);
    
    ofPoint prevPoint;
    for (int i = 1; i < points.size(); i++) {
        ofPoint prevPoint = points[i-1];
        ofPoint point = points[i];
        ofDrawLine(prevPoint, point);
        for (int j=1; j<delta; j++) {
            ofDrawLine(
                       ofPoint(prevPoint.x + i*j, prevPoint.y + i*j),
                       ofPoint(point.x + i*j, point.y + i*j)
                       );
        }
    };
    
}

//--------------------------------------------------------------
void redLinesApp::draw(){
    
 ofSeedRandom(10);
    
    ofBackground(255, 255, 255);
    ofSetColor(255, 0, 0);
    
    
//    int num_deltaA = ofMap(params->potA, 0, 1023, 3, 50);
//    int num_deltaB = ofMap(params->potB, 0, 1023, 3, 50);
//    int num_items = ofMap(params->potA + params->potB, 0, 2050, 3, 100);
    
//    float maxMultiple = ofGetMouseY();
//    float maxMultiple = 356; // full screen
    float maxMultiple = 183;
//    cout << "maxMultiple: " << maxMultiple << endl;
    
        int num_deltaA = ofMap(params->potA, 0, 1023, 3, 50);
    
    
    int num_deltaB = 1;
    if (params->potB > 10) {
        num_deltaB = ofMap(params->potB, 10, 1023, 1, maxMultiple);
    }    
    
    int num_items = num_deltaA * num_deltaB;
    
    
//    cout << "potaA: " << params->potA << endl;
//        cout << "potaB: " << params->potB << endl;
//        cout << "num_deltaA: " << num_deltaA << endl;
//    cout << "num_deltaB: " << num_deltaB << endl;
//    cout << params->potA << " | " << params->potB << " | " << endl;
    
    
    
    if (abs(num_items - lastNumItems) > 2) {
        lastNumItems = num_items;
    float x1 = 100;
    float y1 = 300;
    float x2 = 300;
    float y2 = 100;
    
    ofVec2f center = ofVec2f(0, 0);
    vector<ofPoint> linePoints;
        
    float w = ofGetScreenWidth();
    float h = ofGetScreenHeight();
    
    for (int i=0; i<num_items; i++) {
        ofPoint p = ofPoint(ofRandom(0, w), ofRandom(0, h));
        linePoints.push_back(p);
    }
    
    ofSetColor(255, 0, 0);
    line = ofPolyline(linePoints);
    }
//    line.draw();
    line.draw();
    
//    cDrawLine(line);
    
}

//--------------------------------------------------------------
void redLinesApp::cleanup(){
    
}
