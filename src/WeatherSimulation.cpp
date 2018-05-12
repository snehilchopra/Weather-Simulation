//
//  WeatherSimulation.cpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 4/20/18.
//
#include "WeatherSimulation.hpp"

// GLOBAL VARIABLES
float descent = 20.0;
bool is_snowing = false;
bool is_raining = false;
bool is_thunder = false;
bool is_windy = false;
bool is_wind_direction_right = true;
bool is_wind_direction_left = false;
Particles particle_system[MAX_PARTICLES];
ofPolyline thunderbolts[MAX_THUNDERBOLTS];

// FUNCTIONS

/**
 * An initialize function to give/revive a particle to it's initial stage
 */
void initialize_particle(int i) {
    particle_system[i].x_coordinate = ofRandom(0,ofGetWidth()*2);
    particle_system[i].y_coordinate = -25.0;
    particle_system[i].z_coordinate = ofRandom(-200.0, 200.0);
}

/**
 * A helper function to initialize all particles at once
 */
void initialize() {
    // Initialize particles
    for (int i = 0; i < MAX_PARTICLES; i++) {
        initialize_particle(i);
    }
}

