#include "ofApp.h"
#include "WeatherSimulation.hpp"
#include "Rain.hpp"
#include "Snow.hpp"
#include "Thunder.hpp"
#include "Wind.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    ofSetVerticalSync(true);
    
    // Set up the control panel
    control_panel.setup("Parameters");
    control_panel.add(rain.setup("Rain", false, 20, 20));
    control_panel.add(snow.setup("Snow", false, 20, 20));
    control_panel.add(thunder.setup("Thunder", false, 20, 20));
    control_panel.add(descent_speed.setup("Descent Speed", 20, 0.1, 100));
    control_panel.add(thunder_frequency.setup("Thunder Frequency", LIGHTNING_THRESHOLD, 0, 9.99));
    control_panel.add(wind.setup("Wind", false, 20, 20));
    control_panel.add(right_wind.setup("Right wind direction", false, 20, 20));
    control_panel.add(left_wind.setup("Left wind direction", false, 20, 20));
    
    // Initialize all particles
    initialize();
    ofBackground(ofColor::black);
    
    // Load all background music
    instruction_manual.load("ins.png");
    background_snow_sound.load("snow.mp3");
    background_rain_sound.load("rain.mp3");
    background_windy_rain_sound.load("windy_rain.mp3");
    background_thunder_sound.load("thunder.mp3");

    // Play appropriate music according to the scene
    play_appropriate_music();
    
    // Setup the camera
    cam_pos = ofVec3f(-12,-0.2,0);
    camera.lookAt(cam_pos);
    camera.rotate(180, camera.getXAxis());
}

//--------------------------------------------------------------
void ofApp::update(){
    if((is_raining != rain) || (is_thunder != thunder) || (is_windy != wind) || (is_snowing != snow)){
        is_play_music = true;
    }
    
    is_raining = rain;
    is_thunder = thunder;
    is_snowing = snow;
    is_windy = wind;
    is_wind_direction_left = left_wind;
    is_wind_direction_right = right_wind;
    descent = descent_speed;
    LIGHTNING_THRESHOLD = 10 - thunder_frequency;
    manage_wind();
    
    if(is_play_music){
        play_appropriate_music();
        is_play_music = false;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    if(is_instruction_manual_open){
        ofSetHexColor(0xffffff);
        instruction_manual.draw(0,0,ofGetWidth(),ofGetHeight());
        
    } else {
        camera.begin();
        ofSetHexColor(0xff0000);
        initialize_thunderbolts();
        draw_weather();
        camera.end();
        ofDisableDepthTest();
        control_panel.draw();
        ofSetHexColor(0x32cd32);
        ofDrawBitmapString("Press 'h' for instruction manual", ofGetWidth() - 260, 17);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(!(is_instruction_manual_open)){
        if (key == 'r'){
            is_raining = !is_raining;
            rain = !rain;
            play_appropriate_music();
        }
        
        if (key == 's'){
            is_snowing = !is_snowing;
            snow = !snow;
            play_appropriate_music();
        }
        
        if (key == 't'){
            is_thunder = !is_thunder;
            thunder = !thunder;
            play_appropriate_music();
        }
        
        if(key == 'w'){
            is_windy = !is_windy;
            wind = !wind;
            play_appropriate_music();
        }
        
        if(is_windy){
            if(key == OF_KEY_RIGHT){
                right_wind = true;
                left_wind = false;
            }
            if(key == OF_KEY_LEFT){
                left_wind = true;
                right_wind = false;
            }
        }
        
        if (key == OF_KEY_UP){
            thunder_frequency = thunder_frequency + 0.2;
        }
        
        if (key == OF_KEY_DOWN){
            thunder_frequency = thunder_frequency - 0.1;
        }
    
        if (key == 'o'){
            descent_speed = descent_speed - 0.8;
        }
        
        if (key == 'i'){
            descent_speed = descent_speed + 0.8;
        }
    }
    
    if (key == 'h'){
        is_instruction_manual_open = !is_instruction_manual_open;
        if(!(is_instruction_manual_open)){
            play_appropriate_music();
        } else {
            background_thunder_sound.stop();
            background_windy_rain_sound.stop();
            background_snow_sound.stop();
            background_rain_sound.stop();
        }
    }
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

//--------------------------------------------------------------
void ofApp::play_appropriate_music(){
    if(is_raining){
        if(is_windy){
            background_windy_rain_sound.play();
        } else {
            background_rain_sound.play();
        }
    } else {
        background_windy_rain_sound.stop();
        background_rain_sound.stop();
    }
    
    if(is_thunder){
        background_thunder_sound.play();
    } else {
        background_thunder_sound.stop();
    }
    
    if(is_snowing){
        background_snow_sound.play();
    } else {
        background_snow_sound.stop();
    }
}

//--------------------------------------------------------------
void ofApp::draw_weather(){
    if(is_raining){
        if(is_windy){
            draw_windy_rain();
        } else {
            draw_rain();
        }
    }
    
    if(is_snowing){
        if(is_windy){
            draw_windy_snow();
        } else {
            draw_snow();
        }
    }
    
    if(is_thunder){
        draw_thunder();
    }
}

//--------------------------------------------------------------
void ofApp::manage_wind(){
    if (!wind){
        right_wind = false;
        left_wind = false;
        return;
    }
    
    if(!left_wind){
        right_wind = true;
    } else {
        right_wind = false; 
    }
    
    if((wind) && (!is_wind_direction_left) && (!is_wind_direction_right)){
        right_wind = true;
        return;
    }
}




