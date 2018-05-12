//
//  WeatherSimulation.hpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 4/20/18.
//

#ifndef WeatherSimulation_hpp
#define WeatherSimulation_hpp

#include "ofMain.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>

const int MAX_PARTICLES = 5000;
const int MAX_THUNDERBOLTS = 10;

extern float descent;
extern bool is_raining;
extern bool is_snowing;
extern bool is_windy;
extern bool is_thunder;
extern bool is_wind_direction_right;
extern bool is_wind_direction_left;

struct Particles{
    // Position
    float x_coordinate;
    float y_coordinate;
    float z_coordinate;
};

// Particle System
extern Particles particle_system[MAX_PARTICLES];
extern ofPolyline thunderbolts[MAX_THUNDERBOLTS];

// GENERAL FUNCTIONS
void initialize_particle(int i);                 // Initialize each particle
void initialize();                               // Initialize the particles

#endif /* WeatherSimulation_hpp */
