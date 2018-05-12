//
//  Snow.cpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 5/2/18.
//
#include "ofMain.h"
#include "Snow.hpp"

/**
 * A function to draw vertically falling snow.
 */
void draw_snow(){
    float x_pos, y_pos, z_pos;
    
    for (int particle_index = 0; particle_index < MAX_PARTICLES; particle_index+=1) {
        x_pos = particle_system[particle_index].x_coordinate;
        y_pos = particle_system[particle_index].y_coordinate;
        z_pos = particle_system[particle_index].z_coordinate - 40;
        
        // Draw particles
        glBegin(GL_TRIANGLE_STRIP);
        {
            glColor3f(1.0, 1.0, 1.0);
            glTexCoord2d(1,1);
            glVertex3f(x_pos+(fmod(rand(),3.3f)),y_pos+(fmod(rand(),3.4f)),z_pos+(fmod(rand(),1.1f)));
            glTexCoord2d(0,1);
            glVertex3f(x_pos-(fmod(rand(),1.5f)),y_pos-(fmod(rand(),3.0f)),z_pos - (fmod(rand(),2.9f)));
            glTexCoord2d(1,0);
            glVertex3f(x_pos+(fmod(rand(),2.1f)),y_pos-(fmod(rand(),1.87f)),z_pos + (fmod(rand(),3.1f)));
            glTexCoord2d(0,0);
            glVertex3f(x_pos-(fmod(rand(),4.1f)),y_pos-(fmod(rand(),2.201f)),z_pos);
        }
        glEnd();
        
        // Adjust the speed of the particle in a manner that is random and gives
        // an effect of realistic snow
        if(descent < 0){
            particle_system[particle_index].y_coordinate += 0;
            particle_system[particle_index].x_coordinate += 0;
        }
        else {
            particle_system[particle_index].y_coordinate += (fmod(rand(), descent));
        }
        
        if (particle_system[particle_index].y_coordinate >= (rand() % (ofGetHeight())*8)) {
            initialize_particle(particle_index);
        }
    }
}

