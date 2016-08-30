#include "spiralsApp.h"


//--------------------------------------------------------------
void spiralsApp::setup(){
    
//    w = ofGetScreenWidth() + 600;
    w = 2040;
    h = 900;
    num_items = 508;
//    h = ofGetScreenHeight();
    num_items = floor(w/xspacing)*length_multiple;
    dx = (TWO_PI / period) * xspacing;
    
    cout << "w: " << w << endl;
        cout << "h: " << h << endl;
        cout << "num_items: " << num_items << endl;
         cout << "dx: " << dx << endl;
    
    for (int i = 0; i < num_items; i++) {
        yvalues.push_back(0);
        points.push_back(ofPoint(0, 0));
        triangle_struct new_struct {0,0,0,0,0,0};
        triangles.push_back(new_struct);
    }
    
    // calc the wave
    calcNewTriangles();
    calcWave();
    
}


//--------------------------------------------------------------
void spiralsApp::update(){
    
}

//--------------------------------------------------------------
void spiralsApp::draw(){
    
    float t = ofGetElapsedTimef();
    
    ofBackground(255, 255, 255);
    calcWave();
    
    int int_theta = int(theta);
    if (int_theta != last_update) {
        last_update = int_theta;
    };
    renderTrianglesWave();
    
}

//--------------------------------------------------------------
void spiralsApp::cleanup(){
}


//--------------------------------------------------------------
void spiralsApp::calcWave() {
    
    // Increment theta (try different values for
    // 'angular velocity' here
    float thetaFactor = ofMap(params->potA, 0, 1023, 0.1, 1.5);
//        float phaseFactor = ofMap(params->potB, 0, 1023, 0.5, 2);
//    phaseFactor = roundf(phaseFactor * 100) / 100;
    float phaseFactor = 1;
    //    float thetaFactor = 1;
    theta += 0.02 * thetaFactor;
    
//    float amplitudeFactor = ofMap(params->potB, 0, 1023, 50, 100);
    float amplitudeFactor = 60;
    
    // For every x value, calculate a y value with sine function
    float y_adj = 66;
//    cout << "y_adj: " << y_adj << endl;
    
    float x = theta;
    for (int i = 0; i < num_items; i++) {
        yvalues[i] = sin(x/phaseFactor)*amplitudeFactor;
        float pointx = fmod(x*xspacing*PI*2, w);
        float pointy = h/2+yvalues[i] - 0 + y_adj;
        points[i] = ofPoint(pointx, pointy);
        x+=dx;
    }
    
}


//--------------------------------------------------------------
void spiralsApp::calcNewTriangles() {
    
    for (int i = 0; i < num_items; i++) {
        ofPoint point = points[i];
        int max_triangle_size = 5;
        float x1 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        float y1 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        float x2 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        float y2 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        float x3 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        float y3 = ofRandom(0 - max_triangle_size, 0 + max_triangle_size);
        triangle_struct new_struct {x1,y1,x2,y2,x3,y3};
        triangles[i] = new_struct;
    };
    
}

//--------------------------------------------------------------
void spiralsApp::renderTrianglesWave() {
    
    
    ofBackground(255, 255, 255);
    ofSetColor(0);
//    ofBackground(100, 0, 100);
//    ofSetColor(200, 200, 0);
    
//    float timeFactor = ofMap(params->potB, 0, 1023, 1, 10);
    float timeFactor = 0.5;
    frameCounter += 0.03 * timeFactor;
    
    // calculate time point
//    float t = ofGetElapsedTimef();
    float t = frameCounter;
    int growthDuration = 10;
    int shrinkDuration = 10;
    int restPeriod = 4;
    int maxGrowth = 50;
    int totalCycleDuration = restPeriod + growthDuration*2;
    
    float tPhase = fmod(t, totalCycleDuration);
    float secondsAfterRest = tPhase - restPeriod;
    float gFactor = 0;
    if (secondsAfterRest < 0) {
        gFactor = 0;
    }
    else if (secondsAfterRest < growthDuration) {
        gFactor = secondsAfterRest;
    }
    else {
        float secondsOfShrink = secondsAfterRest - growthDuration;
        gFactor = growthDuration - secondsOfShrink;
    }
//    float growthFactor = ofMap(gFactor, 0, growthDuration, 1, maxGrowth);
    float growthFactor = ofMap(params->potB, 0, 1023, 1, maxGrowth);
    growthFactor = roundf(growthFactor * 100) / 100;
    growthFactor = growthFactor * growthFactor;
    
    //
    //    float growthFactor = ofMap(params->potA, 0, 1023, 1, 100);
    //    if (abs(growthFactor - previous_growth_factor) > 2) {
    //        previous_growth_factor = growthFactor;
    //    } else {
    //        growthFactor = previous_growth_factor;
    //    }
    // for loop
    
    for (int i = 0; i < num_items; i++) {
        ofPoint point = points[i];
        triangle_struct c_triangle = triangles[i];
        float tx1 = point.x + c_triangle.x1  * growthFactor;
        float ty1 = point.y + c_triangle.y1  * growthFactor;
        float tx2 = point.x + c_triangle.x2 * growthFactor;
        float ty2 = point.y + c_triangle.y2 * growthFactor;
        float tx3 = point.x + c_triangle.x3 * growthFactor;
        float ty3 = point.y + c_triangle.y3 * growthFactor;
        
        //        ofDrawCircle(point.x, point.y, 2);
        
        //        tx1 = 100;
        //        ty1 = 100;
        //        tx2 = 200;
        //        ty2 = 200;
        //        tx3 = 100;
        //        ty3 = 300;
        
        ofPolyline tLine = ofPolyline({
            ofPoint(tx1, ty1), ofPoint(tx2, ty2),
            ofPoint(tx3, ty3), ofPoint(tx1, ty1)
        });
        tLine.draw();
        //        ofDrawTriangle(tx1, ty1, tx2, ty2, tx3, ty3);
        //           ofDrawTriangle(100, 100, 200, 200, 100, 300);
    };
    
}


