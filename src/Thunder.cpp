//
//  Thunder.cpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 5/2/18.
//

#include "Thunder.hpp"

float LIGHTNING_THRESHOLD = 3.2;

/**
 * A function to give each thunderbolt its random vertices
 */
void initialize_thunderbolts(){
    float thunderbolts_to_be_drawn = ofRandom(0, MAX_THUNDERBOLTS);
    
    for(int current_thunder_line = 0; current_thunder_line < thunderbolts_to_be_drawn; current_thunder_line++){
        // For clearing all the vertexes previously assigned
        thunderbolts[current_thunder_line].clear();
        
        int number_of_vertices = ofRandom(20,30);
        float y_coordinate_of_current_vertex = 0;
        float x_coordinate_of_current_vertex = ofRandom(0,ofGetWidth()*2);
        float z_coordinate_of_current_vertex = ofRandom(0, ofRandom(-200,200));
        ofPoint temp_point;
        temp_point.set(x_coordinate_of_current_vertex, y_coordinate_of_current_vertex, z_coordinate_of_current_vertex);
        thunderbolts[current_thunder_line].addVertex(temp_point);
        
        // Holds the maximum y-coordinate the current thunderbolt can descent to
        float y_limit = fmod(rand(),ofGetHeight());
        
        for(int current_vertice = 0; current_vertice < number_of_vertices; current_vertice++){
            if(y_coordinate_of_current_vertex >= y_limit){
                break;
            }
            
            x_coordinate_of_current_vertex += (ofRandom(-(rand()%30),rand()%30));
            y_coordinate_of_current_vertex += rand() % 100;
            z_coordinate_of_current_vertex += (ofRandom(-(rand()%30), rand() % 30));
            temp_point.set(x_coordinate_of_current_vertex, y_coordinate_of_current_vertex, z_coordinate_of_current_vertex);
            thunderbolts[current_thunder_line].addVertex(temp_point);
            
        }
    }
}

/**
 * A function to draw thunder onto the scene
 */
void draw_thunder(){
    // A variable that acts as the probability factor that decides whether or not thunder will be displayed
    float decider = rand() % 11;
    
    // LIGHTINING_THRESHOLD is the threshold value which dictates how frequently lightning occurs
    if (decider > LIGHTNING_THRESHOLD){
        for(ofPolyline current_thunderbolt: thunderbolts){
            ofSetHexColor(0xeff4ff);
            current_thunderbolt.draw();
        }
    }
}
