//
//  Thunder.hpp
//  final-project-DazedDreamer
//
//  Created by Snehil Chopra on 5/2/18.
//

#ifndef Thunder_hpp
#define Thunder_hpp

#include "ofMain.h"
#include <stdio.h>
#include "WeatherSimulation.hpp"

extern float LIGHTNING_THRESHOLD;

void initialize_thunderbolts();    // A function to intialize the vertices of each thunderbolt
void draw_thunder();               // Function to draw thunder onto the window

#endif /* Thunder_hpp */
