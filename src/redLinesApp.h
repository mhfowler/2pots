#include "ofMain.h"
#include "subApp.h"

class  redLinesApp : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    
    void cDrawLine(ofPolyline line);
    
    int lastNumItems=0;
    
    ofPolyline line;
};
