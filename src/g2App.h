#include "ofMain.h"
#include "subApp.h"

class  g2App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    vector<ofPoint> pathPoints;
    
    void cDrawLine(ofPolyline line);
    
    float frameCounter = 0;
};
