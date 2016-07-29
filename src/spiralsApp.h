#include "ofMain.h"
#include "subApp.h"

typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
} triangle_struct;

class spiralsApp : public subApp {
public:
    void setup();
    void update();
    void draw();
    void cleanup();
    
    
    int length_multiple = 4;
    int xspacing = 16;    // Distance between each horizontal location
    int w;                // Width of entire wave
    int h;
    float theta = 0.0;      // Start angle at 0
    float amplitude = 75.0; // Height of wave
    float period = 500.0;   // How many pixels before the wave repeats
    float dx;               // Value for incrementing x
    vector<float> yvalues;  // Using an array to store height values for the wave
    vector<ofPoint> points;
    int num_items;
    vector<triangle_struct> triangles;
    
    void calcWave();
    void calcNewTriangles();
    void renderTrianglesWave();
    
    int last_update=0;
    float previous_growth_factor = 0;
    
    float frameCounter = 0;
};
