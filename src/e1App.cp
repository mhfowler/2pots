#include "e1App.h"


//--------------------------------------------------------------
void e1App::setup(){

    
}


//--------------------------------------------------------------
void e1App::update(){
    
}

void e1App::cDrawLine(ofPolyline line) {
    
    vector<ofPoint> points = line.getVertices();
    
    
    //    float tPeriod = ofMap(params->potB, 0, 1023, 1/10.0, 20);
    //    float maxMultiple = ofGetMouseY();
    //    cout << "maxMultpile: " << maxMultiple << endl;
    //    float t = ofGetElapsedTimef();
    float maxMultiple = 50;
//    float maxMultiple = ofGetMouseY();
    //    maxMultiple = ofMap(sin(t*tPeriod), -1, 1, 1, 200);
    
    
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
void e1App::draw(){
    
    ofBackground(255, 255, 255);
    
    float t = ofGetElapsedTimef() / 5.0;
    int t_seconds = int(t);
      ofSeedRandom(t_seconds);
    
//    ofSeedRandom(12);
    
//    ofSeedRandom(int(sfmod(ofGetElapsedTimef()/4.0, 10)));
    
    float h = ofGetScreenHeight();
    float w = ofGetScreenWidth();
    
    ofNoFill();
    ofSetColor(0);
//    ofDrawCircle(0, h/2.0, 200);
//    ofDrawCircle(w, h/2.0, 200);
    
    float deltaA = ofMap(params->potA, 0, 1023, 1, 105);
//    float deltaB = ofMap(params->potB, 0, 1023, 1, 100);
    
    
//    float numAngles = ofMap(params->potB, 0, 1023, 2, 32);
//    float lineLensth = 50;
    float lineLength = ofMap(params->potB, 0, 1023, 10, 200);
    int numAngles = 4;
    cout << "lineLength: " << lineLength << endl;
    
    // 45,431
    int numItems = deltaA;
    cout << "numItems: " << numItems << endl;
//    float randVal = h / numItems;
    
//    int numItems = 100;
    
//        int numItems = 100;
    
    
    vector<ofPoint> points;
    ofPoint prevPoint = ofPoint(ofGetScreenWidth() / 2.0, ofGetScreenHeight() / 2.0);
    points.push_back(prevPoint);
    
    float lower_w = 50;
    float upper_w = w - 50;
    float lower_h = 50;
    float upper_h = h - 50;
    
 
    
    for (int j=1; j<numItems; j++) {
//        float bonus = ofMap(j % 10, 0, 10.0, 0, 10);
        int dir = ofRandom(0, numAngles * 2);
        float theta = dir*PI / numAngles;
        float randLineLength = lineLength + ofRandom(-lineLength, 500);
        ofDrawCircle(prevPoint.x, prevPoint.y, 5);
        ofPoint newPoint = ofPoint(
                           prevPoint.x + cos(theta)*randLineLength ,
                           prevPoint.y - sin(theta)*randLineLength
                           );
        if (newPoint.x < lower_w) {
            newPoint.x = lower_w + abs((lower_w-newPoint.x));
        }
        if (newPoint.y < lower_h) {
            newPoint.y = lower_h + abs((lower_h-newPoint.y));
        }
        if (newPoint.x > upper_w) {
            newPoint.x = upper_w - abs((newPoint.x - upper_w));
        }
        if (newPoint.y > upper_h) {
            newPoint.y = upper_h - abs((newPoint.y - upper_h));
        }
        
        
//        int mode = ofRandom(0, 3);
//        ofPoint newPoint;
//        if (mode == 0) {
//            newPoint = ofPoint(
//                                       prevPoint.x + 20,
//                                       prevPoint.y - 30
//                                       );
//        }
//        else if (mode == 1) {
//            newPoint = ofPoint(
//                                       prevPoint.x + 50 ,
//                                       prevPoint.y - 10
//                                       );
//        }
//        else if (mode == 2) {
//            newPoint = ofPoint(
//                                       prevPoint.x + 30 ,
//                                       prevPoint.y - 15
//                                       );
//        }
        points.push_back(newPoint);
        prevPoint = newPoint;
    }
    ofDrawCircle(prevPoint.x, prevPoint.y, 5);
    
    ofSetColor(0);
    ofPolyline line = ofPolyline(points);
//    line.draw();
    cDrawLine(line);
    
    
    
}

//--------------------------------------------------------------
void e1App::cleanup(){
    
}
