#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    serial.setup("/dev/tty.usbmodem1421", 9600);
    
    // replace the string below with the serial port for your Arduino board
    // you can get this from the Arduino application or via command line
    // for OSX, in your terminal type "ls /dev/tty.*" to get a list of serial devices
    ard.connect("/dev/tty.usbmodem1421", 57600);
    
    // listen for EInitialized notification. this indicates that
    // the arduino is ready to receive commands and it is safe to
    // call setupArduino()
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    //    setupArduino(23);
    
    bSetupArduino	= false;	// flag so we setup arduino when its ready, you don't need to touch this :)
    
    
    
    // init all the apps
        for (int i = 0; i < apps.size(); i++) {
            subApp * appPointer = apps[i];
            appPointer->init(&params);
        }
    
//         currentApp = &testApp;
             currentApp = apps[0];
//         currentApp = &b1App;
//              currentApp = &spiralsApp;
//        currentApp = &h1App;
    
//             currentApp = &c1App;
//             currentApp = &a2App;
//    currentApp = &line1App;
    
    currentApp->setup();
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    // remove listener because we don't need it anymore
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    // it is now safe to send commands to the Arduino
    bSetupArduino = true;
    
    // print firmware name and version to the console
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    
    // Note: pins A0 - A5 can be used as digital input and output.
    // Refer to them as pins 14 - 19 if using StandardFirmata from Arduino 1.0.
    // If using Arduino 0022 or older, then use 16 - 21.
    // Firmata pin numbering changed in version 2.3 (which is included in Arduino 1.0)
    
    // set pins D4 and D6 to digital input
    //    ard.sendDigitalPinMode(4, ARD_INPUT);
    //    ard.sendDigitalPinMode(6, ARD_INPUT);
    
    // set pin D5 & D7 as digital output
    
    //ARD_ANALOG ?
    lastButtonPress = ofGetElapsedTimef();
    ard.sendAnalogPinReporting(0, ARD_ANALOG);
    ard.sendAnalogPinReporting(2, ARD_ANALOG);
//    ard.sendAnalogPinReporting(3, ARD_ANALOG);
    
//    ard.sendDigitalPinMode(7, ARD_INPUT);
       ard.sendDigitalPinMode(5, ARD_INPUT);
//    ard.sendDigital(7, ARD_HIGH); // connect internal pull-up resistor
    //    ard.sendDigitalPinMode(7, ARD_OUTPUT);
    
    // Listen for changes on the digital and analog pins
    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    
    // update the arduino, get any data or messages.
    // the call to ard.update() is required
    ard.update();
    
    // do not send anything until the arduino has been set up
    if (bSetupArduino) {
        // fade the led connected to pin D11
        //        ard.sendPwm(3, (int)(120 + 128 * sin(ofGetElapsedTimef())));   // pwm...
//        ard.sendPwm(3, params.potA);
//        ard.sendPwm(5, params.potB);
        //            ard.sendDigital(3, ARD_HIGH);
    }
    
    
}



// digital pin event handler, called whenever a digital pin value has changed
// note: if an analog pin has been set as a digital pin, it will be handled
// by the digitalPinChanged function rather than the analogPinChanged function.

//--------------------------------------------------------------
void ofApp::digitalPinChanged(const int & pinNum) {
//    int bState = ard.getDigital(pinNum);
    
    int buttonState = ard.getDigital(pinNum);
    float now = ofGetElapsedTimef();
    
//    if (pinNum == 7 && buttonState == ARD_LOW && now - lastButtonPress > 0.3) {
////    if (pinNum == 7 && buttonState == ARD_LOW) {
//        lastButtonPress = now;
//        buttonAPressed();
//    }
    
//    if (pinNum == 7 && buttonState == 1 && now - lastButtonPress > 0.1) {
//        lastButtonPress = now;
//        buttonAPressed();
//
//    if (pinNum == 5 && buttonState == 1 && now - lastButtonPress > 0.4) {
    if (pinNum == 5 && buttonState == 1) {
        lastButtonPress = now;
        buttonAPressed();
    }
    
       cout << "pinNum: "  << pinNum << endl;
    cout << "bstate: " << buttonState << endl;
    //    potA = ard.getAnalog(0);
    //    potB = ard.getAnalog(2);
}

void ofApp::analogPinChanged(const int & pinNum) {
    // do something with the digital input. here we're simply going to print the pin number and
    // value to the screen each time it changes
    //    buttonState = "digital pin: " + ofToString(pinNum) + " = " + ofToString(ard.getDigital(pinNum));
    //    int state;
    int val = ard.getAnalog(pinNum);
    if (pinNum == 0) {
        if (abs(val - params.potA) > 10) {
            params.potA = ofMap(val, 0, 1023, 1023, 0);
            currentApp->update();
//            cout << "potA: " << params.potA << endl;
        };
    }
    else if (pinNum == 2) {
        if (abs(val - params.potB) > 10) {
        params.potB = ofMap(val, 0, 1023, 1023, 0);
        currentApp->update();
//        cout << "potB: " << params.potA << endl;
        }
//    else if (pinNum == 3) {
//        int newPinState = ofMap(val, 0, 1023, 0, apps.size()+1);
//        if (newPinState > apps.size()) {
//            newPinState = apps.                                                                            size();
//        }
//        if (newPinState != buttonAState) {
//            cout << "pinState: " << newPinState << endl;
//            buttonAState = newPinState;
//            currentApp = apps[buttonAState];
//            currentApp->setup();
//            currentApp->update();
//        }
//                //        cout << "potB: " << params.potA << endl;
//    };
    };
    //    else state = ARD_LOW;
    //    if(pinNum == 4) {
    //        ard.sendDigital(5, state);
    //        if(state == ARD_HIGH) beat1.play();
    //    } else if(pinNum == 6) {
    //        ard.sendDigital(7, state);
    //        if(state == ARD_HIGH) beat2.play();
    //    }
}

//--------------------------------------------------------------
void ofApp::buttonAPressed(){
    // TODO:
    buttonAState += 1;
    buttonAState = buttonAState % apps.size();
    currentApp = apps[buttonAState];
    currentApp->setup();
}


//--------------------------------------------------------------
void ofApp::update(){
    updateArduino();
    currentApp->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentApp->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 106) {
        buttonAPressed();
    }
    else if (key == 32) {
        buttonAPressed();
    }
    else if (key == 101) {
        increasePotA();
    }
    else if (key == 119) {
        decreasePotA();
    }
    else if (key == 105) {
        increasePotB();
    }
    else if (key == 117) {
        decreasePotB();
    }
    
}

void ofApp::increasePotA() {
    params.potA = min(1023, params.potA + 10);
}

void ofApp::decreasePotA() {
    params.potA = max(0, params.potA - 10);
}

void ofApp::increasePotB() {
    params.potB = min(1023, params.potB + 10);
}

void ofApp::decreasePotB() {
    params.potB = max(0, params.potB - 10);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
