//
//  Wind.cpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 5/2/18.
//

#include "Wind.hpp"

/**
 * A function to draw rain using Opengl geometric primitives
 */
void draw_windy_rain(){
    float x_pos, y_pos, z_pos;
    
    for (int particle_index = 0; particle_index < MAX_PARTICLES; particle_index+=1) {
        x_pos = particle_system[particle_index].x_coordinate;
        y_pos = particle_system[particle_index].y_coordinate;
        z_pos = particle_system[particle_index].z_coordinate - 40;
        
        // Draw particles
        glBegin(GL_LINES);
        {
            glColor3f(0.5, 0.5, 2.0);
            glVertex3f(x_pos, y_pos, z_pos);
            
            if(is_wind_direction_left){
                glVertex3f(x_pos - (fmod(rand(), 3.1f)) - 1.5f, y_pos + 6.8, z_pos);
            }
            if(is_wind_direction_right){
                glVertex3f(x_pos + (fmod(rand(), 3.1f)) - 1.5f, y_pos + 6.8, z_pos);
            }
            
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
            if(is_wind_direction_left){
                particle_system[particle_index].x_coordinate -= (fmod(rand(), descent));
            }
            if(is_wind_direction_right){
                particle_system[particle_index].x_coordinate += (fmod(rand(), descent));
            }
        }
        
        if (particle_system[particle_index].y_coordinate >= (rand() % (ofGetHeight()*8))) {
            initialize_particle(particle_index);
        }
        
    }
}


/**
 * A function to draw windy snow using OpenGL geometric primitives
 */
void draw_windy_snow(){
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
            if(is_wind_direction_left){
                particle_system[particle_index].x_coordinate -= (fmod(rand(), descent));
            }
            if(is_wind_direction_right){
                particle_system[particle_index].x_coordinate += (fmod(rand(), descent));
            }
        }
        
        if (particle_system[particle_index].y_coordinate >= (rand() % (ofGetHeight())*8)) {
            initialize_particle(particle_index);
        }
    }
}


