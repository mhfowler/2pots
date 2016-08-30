#include "g2App.h"
#include "path_data_g2.h"


void g2App::cDrawLine(ofPolyline line) {
    
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
    
//    delta = 0;
    
    //    float deltaMax = 500;
    
    float w = ofGetScreenWidth();
    
    float sinFactor = ofMap(params->potA, 0, 1023, 0, 2);
    
    float divBy = 1213;
    //    cout << "divBy: " << divBy << endl;
    float delta_w = 5;
    
    ofPolyline l = ofPolyline(points);
    l = l.getResampledBySpacing(5);
    points = l.getVertices();
    
//    float t = fmod(ofGetElapsedTimef() / 2.0, 10);
    frameCounter += 0.02;
    frameCounter = fmod(frameCounter, 10);
    float t = frameCounter;
    if (t > 5) {
        t = 5 - (t-5);
    }
    t = t + 2;
//    t = sin(t / 10.0);
//    float tFactor = ofGetMouseY();
//    cout << "tFactor: " << tFactor << endl;
//       float t = ofGetElapsedTimef() / ofGetMouseY();
    
    vector<ofPoint> wavePoints;
    for (int i = 0; i < points.size(); i++) {
        ofPoint point = points[i];
        ofPoint wavePoint = ofPoint(
        point.x + ofMap(sin(t*(point.y/40.0)), -1, 1, -30, 30)*sinFactor,
                                    point.y);
        wavePoints.push_back(wavePoint);
    }
    
    ofPoint prevPoint;
    for (int i = 1; i < wavePoints.size(); i++) {
        ofPoint prevPoint = wavePoints[i-1];
        ofPoint point = wavePoints[i];
        ofDrawLine(prevPoint, point);
        for (int j=1; j<delta; j++) {
            
            // at an angle
//            ofDrawLine(
//                       ofPoint(prevPoint.x + j*delta_w, prevPoint.y + j*delta_w),
//                       ofPoint(point.x + j*delta_w, point.y + j*delta_w)
//                       );
            
            ofDrawLine(
                       ofPoint(prevPoint.x + j*delta_w, prevPoint.y),
                       ofPoint(point.x + j*delta_w, point.y)
                       );
        }
        for (int j=1; j<delta; j++) {
            
            // at an angle
            //            ofDrawLine(
            //                       ofPoint(prevPoint.x + j*delta_w, prevPoint.y + j*delta_w),
            //                       ofPoint(point.x + j*delta_w, point.y + j*delta_w)
            //                       );
            
            ofDrawLine(
                       ofPoint(prevPoint.x - j*delta_w, prevPoint.y),
                       ofPoint(point.x - j*delta_w, point.y)
                       );
        }
    };
    
}


//--------------------------------------------------------------
void g2App::setup(){

//    float pathData[] = {100.0, 200.0, 300.0, 400.0};
    
    int dataLen = (sizeof(pathDataArray)/sizeof(*pathDataArray));
    
//    int dataLen = 8;
//
    for (int i = 0; i < dataLen / 2.0; i++){
        float x = pathDataArray[i*2] * 0.25 + 400;
        float y = pathDataArray[i*2 + 1] * 0.25 - 100;
        pathPoints.push_back(ofPoint(x, y));
    }
    
}


//--------------------------------------------------------------
void g2App::update(){
    
}

//--------------------------------------------------------------
void g2App::draw(){
    
    ofBackground(255, 255, 255);
    
    ofSetColor(0);
    ofPolyline pLine = ofPolyline(pathPoints);
//    pLine.draw();
    
    cDrawLine(pLine);
    
}

//--------------------------------------------------------------
void g2App::cleanup(){
    
}
