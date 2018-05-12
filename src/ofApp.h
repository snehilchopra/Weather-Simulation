#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{
    ofSoundPlayer background_rain_sound;
    ofSoundPlayer background_windy_rain_sound;
    ofSoundPlayer background_snow_sound;
    ofSoundPlayer background_thunder_sound;
    ofEasyCam camera;
    ofVec3f cam_pos;
    bool is_instruction_manual_open = false;
    ofImage instruction_manual;
    ofBoxPrimitive flash_box;
    ofxPanel control_panel;
    ofxToggle rain;
    ofxToggle snow;
    ofxToggle thunder;
    ofxFloatSlider thunder_frequency;
    ofxToggle wind;
    ofxToggle right_wind;
    ofxToggle left_wind;
    ofxFloatSlider descent_speed;
    ofxFloatSlider thunderbolts;
    bool is_play_music = false;

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void play_appropriate_music();             // A function to play the appropriate music based on the current scene
    void draw_weather();                       // A function to draw the correct weather onto the screen
    void manage_wind();                        // A function to manage wind
};
