#include "ofMain.h"
#include "subApp.h"

class  g1App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    vector<ofPoint> pathPoints;
    
    void cDrawLine(ofPolyline line);
};
