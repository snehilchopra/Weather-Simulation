//
//  Rain.cpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 5/2/18.
//
#include "ofMain.h"
#include "Rain.hpp"


/**
 * A function to draw the entire rain scene onto the window
 */
void draw_rain() {
    float x_pos, y_pos, z_pos;
    
    for (int particle_index = 0; particle_index < MAX_PARTICLES; particle_index+=1) {
        x_pos = particle_system[particle_index].x_coordinate;
        y_pos = particle_system[particle_index].y_coordinate;
        z_pos = particle_system[particle_index].z_coordinate - 40.0;
        
        // Draw particles
        glBegin(GL_LINES);
        {
            glColor3f(0.5, 0.5, 2.0);
            glVertex3f(x_pos, y_pos, z_pos);
            glVertex3f(x_pos, y_pos + 7.8, z_pos);
            
        }
        glEnd();
        
        // Adjust the speed of the particle in a manner that is random and gives
        // an effect of realistic rain
        if(descent < 0){
            particle_system[particle_index].y_coordinate += 0;
            particle_system[particle_index].x_coordinate += 0;
        }
        else {
            particle_system[particle_index].y_coordinate += (fmod(rand(), descent));

        }
        
        if (particle_system[particle_index].y_coordinate >= (rand() % (ofGetHeight()*8))) {
            initialize_particle(particle_index);
        }
    }
}
