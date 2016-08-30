#include "g1App.h"
#include "path_data_g1.h"


void g1App::cDrawLine(ofPolyline line) {
    
    vector<ofPoint> points = line.getVertices();
    
    float maxMultiple = 50;

    
    float deltaMax = params->potB;
    cout << "deltaMax: " << deltaMax << endl;
    float delta;
    if (deltaMax < 58) {
        delta = 0;
    }
    else {
        delta = ofMap(deltaMax, 58, 1023, 0, maxMultiple);
    }
    
    //    float deltaMax = 500;
    
//    float extendFactor = ofMap(params->potA, 0, 1023, 1, 0.4);
    float extendFactor = 1;
//        float extendFactor = 1;
    cout << "extendFactor: " << extendFactor << endl;

    
    float w = ofGetScreenWidth();
    
    float divBy = 1213;
    //    cout << "divBy: " << divBy << endl;
    float delta_w = 5;
    
    ofPoint prevPoint;
    
    ofPoint newPoint;
    
    vector<ofPoint> adjustedPoints;
    
    prevPoint = points[0];
    ofPoint prevAdjustedPoint = points[0];
    adjustedPoints.push_back(prevPoint);
//    delta = 0;
    
    for (int i = 1; i < points.size(); i++) {
        ofPoint prevPoint = points[i-1];
        ofPoint nextPoint = points[i];
        ofPoint delta = (nextPoint - prevPoint) * extendFactor;
        ofPoint adjustedPoint = prevAdjustedPoint + delta;
        adjustedPoints.push_back(adjustedPoint);
        prevAdjustedPoint = adjustedPoint;
    }
    
    for (int i = 1; i < adjustedPoints.size(); i++) {
        ofPoint prevPoint = adjustedPoints[i-1];
        ofPoint point = adjustedPoints[i];
        ofDrawLine(prevPoint, point);
        for (int j=1; j<delta; j++) {
            
//             at an angle
            ofDrawLine(
                       ofPoint(prevPoint.x + j*delta_w, prevPoint.y + j*delta_w),
                       ofPoint(point.x + j*delta_w, point.y + j*delta_w)
                       );
        }
    };
    
}


//--------------------------------------------------------------
void g1App::setup(){

//    float pathData[] = {100.0, 200.0, 300.0, 400.0};
    
    int dataLen = (sizeof(pathDataArray)/sizeof(*pathDataArray));
    
//    int dataLen = 8;
    
    float w = ofGetScreenWidth();
    float h = ofGetScreenHeight();
//
//    float x_adj = ofGetMouseX();
//    float y_adj = ofGetMouseY();
//    cout << "x_adj: " << x_adj << endl;
//    cout << "y_adj: " << y_adj << endl;
    float x_adj = 103;
    float y_adj = 30;
    
    for (int i = 0; i < dataLen / 2.0; i++){
        float x = pathDataArray[i*2] * 0.25 + x_adj;
        float y = pathDataArray[i*2 + 1] * 0.25 + y_adj;
        pathPoints.push_back(ofPoint(x, y));
    }
    
}


//--------------------------------------------------------------
void g1App::update(){
    
}

//--------------------------------------------------------------
void g1App::draw(){
    
    ofBackground(255, 255, 255);
    
    ofSetColor(0);
    ofPolyline pLine = ofPolyline(pathPoints);
//    pLine.draw();
    
    cDrawLine(pLine);
    
}

//--------------------------------------------------------------
void g1App::cleanup(){
    
}
