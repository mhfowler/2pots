#include "face1App.h"


//--------------------------------------------------------------
void face1App::setup(){
}


//--------------------------------------------------------------
void face1App::update(){
    
}

//--------------------------------------------------------------
void face1App::draw(){
    
    ofBackground(255, 255, 255);
    
    float x1 = 100;
    float y1 = 300;
    float x2 = 300;
    float y2 = 100;
    
    vector<ofPoint> points;
    
    float startPos = 100;
    
//    int numPoints = max(ofGetMouseY(), 1);
    float numPoints = ofMap(params->potA, 0, 1023, 15, 1000);
    cout << "numPoints: " << numPoints << endl;
    
    float randVal = ofMap(params->potB, 0, 1023, 0, 5);
    cout << "randVal: " << randVal << endl;
//    int numPoints = 100;
    float col_width = ofGetScreenWidth() / numPoints;
    float row_height = (ofGetScreenHeight()-200) / numPoints;

    for (int i = 0; i < numPoints; i++) {
        int ypos = i * row_height;
        for (int j=1; j< numPoints; j++) {
            int direction = i % 2;
            int xpos = j * col_width;
            if (direction == 1) {
                xpos = (numPoints-j) * row_height;
            }
            ofPoint point = ofPoint(startPos + xpos + ofRandom(-randVal, randVal), startPos + ypos + ofRandom(-randVal, randVal));
            points.push_back(point);
        }
    };
    
    ofSetColor(0);
    ofPolyline line = ofPolyline(points);
    line.draw();
    
}

//--------------------------------------------------------------
void face1App::cleanup(){
    
}
