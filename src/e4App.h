#include "ofMain.h"
#include "subApp.h"

class  e4App : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    ofPolyline line;
    ofPolyline rectLine;
    
    void cDrawLine(ofPolyline line);
};
