#include "wavesApp.h"


//--------------------------------------------------------------
void wavesApp::setup(){
}


//--------------------------------------------------------------
void wavesApp::update(){
    
}

void wavesApp::cDrawLine(ofPolyline line) {
    
    vector<ofPoint> points = line.getVertices();
    
    
//    float tPeriod = ofMap(params->potB, 0, 1023, 1/10.0, 20);
//    float maxMultiple = ofGetMouseY();
//    cout << "maxMultpile: " << maxMultiple << endl;
//    float t = ofGetElapsedTimef();
    float maxMultiple = 50;
//    maxMultiple = ofMap(sin(t*tPeriod), -1, 1, 1, 200);

    
    float deltaMax = params->potB;

//    float deltaMax = 500;
    
    float delta = ofMap(deltaMax, 0, 1023, 0, maxMultiple);
    
    float w = ofGetScreenWidth();
    
    float divBy = 1213;
//    cout << "divBy: " << divBy << endl;
    float delta_w = w / divBy;
    
    ofPoint prevPoint;
    for (int i = 1; i < points.size(); i++) {
        ofPoint prevPoint = points[i-1];
        ofPoint point = points[i];
        ofDrawLine(prevPoint, point);
        for (int j=1; j<delta; j++) {
        ofDrawLine(
            ofPoint(prevPoint.x + i*j*delta_w, prevPoint.y + i*j*delta_w),
               ofPoint(point.x + i*j*delta_w, point.y + i*j*delta_w)
                   );
        }
    };
    
}

//--------------------------------------------------------------
void wavesApp::draw(){
    
    ofBackground(255, 255, 255);
    
    vector<ofPoint> sPoints;
    
//    float num_h_rows = ofGetScreenHeight() / 100.00;
//    float num_w_cols = ofGetScreenWidth() / 100.00;
//    float rowHeight = ofGetScreenHeight() / num_h_rows;
//    float colWidth = ofGetScreenWidth() / num_w_cols;
    
    float colDelta = ofMap(params->potA, 0, 1023, 0, 400);
    
    int num_h_rows = 9;
    int num_w_cols = 40;
    int rowHeight = ofGetScreenHeight() / (num_h_rows-2);
    int colWidth = ofGetScreenWidth() / 10.0 + colDelta;
    
//    int rowHeight = 10;
//    int colWidth = 10;
    

    
    ofSetColor(255, 0, 0);
    for (int i = 0; i < num_w_cols; i++) {
    for (int j = 0; j < num_h_rows; j++) {
        float x = colWidth * i;
        float y = rowHeight * j;
        sPoints.push_back(ofPoint(x, y));
    }
    }
    
    ofSetColor(0);
    ofPolyline sLine = ofPolyline(sPoints);
    cDrawLine(sLine);
    

    float endDelta = ofMap(params->potB, 0, 1023, 0, ofGetScreenHeight());
    
    ofPolyline line1 = ofPolyline({
        ofPoint(0, 100), ofPoint(ofGetScreenWidth(), 130)
    });
    line1.draw();
    
}

//--------------------------------------------------------------
void wavesApp::cleanup(){
    
}
