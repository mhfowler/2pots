#include "d1App.h"


//--------------------------------------------------------------
void d1App::setup(){
}


//--------------------------------------------------------------
void d1App::update(){
    
}

void d1App::cDrawLine(ofPolyline line) {
    
    vector<ofPoint> points = line.getVertices();
    
    vector<ofPoint> newPoints;
    
    int randVal = 10;
    
    for (int i = 0; i < points.size(); i++) {
        ofPoint oldPoint = points[i];
        ofPoint newPoint = ofPoint(
            oldPoint.x + ofRandom(-randVal, randVal),
            oldPoint.y + ofRandom(-randVal, randVal)
                                   );
        newPoints.push_back(newPoint);
    };
    ofPolyline newLine = ofPolyline(newPoints);
    newLine.draw();
}

//--------------------------------------------------------------
void d1App::draw(){
    
    ofBackground(255, 255, 255);
    
    
    for (int i=0; i<20; i++) {
    
    vector<ofPoint> line1Points = {
        
        ofPoint(
                100,
                300
                ),
        ofPoint(
                300,
                100
                ),
    };
    
    vector<ofPoint> line2Points = {
        
        ofPoint(
                100,
                100
                ),
        ofPoint(
                400,
                400
                ),
    };
    
    vector<ofPoint> line3Points = {
        
        ofPoint(
                500,
                400
                ),
        ofPoint(
                800,
                100
                ),
    };
    
    ofSetColor(0);
    
    ofPolyline line1 = ofPolyline(line1Points);
//    line1.draw();
        cDrawLine(line1);
    
    ofPolyline line2 = ofPolyline(line2Points);
//    line2.draw();
              cDrawLine(line2);
    
    ofPolyline line3 = ofPolyline(line3Points);
//    line3.draw();
              cDrawLine(line3);
    
    ofNoFill();
    ofDrawCircle(400 + 30 + ofRandom(-10, 10), 400 + 30 + ofRandom(-10, 10), 50);
        
    }
    
    
    
    
}

//--------------------------------------------------------------
void d1App::cleanup(){
    
}
