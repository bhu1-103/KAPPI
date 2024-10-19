#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define PI 3.141592653589793

// Define constants
const double MAX_RADIUS = 20.0;
const double LEVEL_HEIGHT_MULTIPLIER = 6.0;    // Vertical spacing between levels (kept the same)
const double BASE_RADIUS_MULTIPLIER = 15.0;    // Increase this for more horizontal distance
const double LEVEL_RADIUS_MULTIPLIER = 1.5;    // Multiplier to increase the radius of each level

// Helper function for polar to cartesian conversion
void polar_to_cartesian(double radius, double angle, double *x, double *y) {
    *x = radius * sin(angle);
    *y = radius * cos(angle);
}

// Function to scatter points around a given center
void scatter_points(double x, double y, double max_radius, double z) {
    double radius = ((double)rand() / RAND_MAX) * max_radius;
    double angle = ((double)rand() / RAND_MAX) * 2 * PI;
    
    double scatter_x, scatter_y;
    polar_to_cartesian(radius, angle, &scatter_x, &scatter_y);
    
    printf("1 F %.2f %.2f %.2f ", x + scatter_x, y + scatter_y, z);
}

// Function to place a main object and scatter points around it
void place_object_with_neighbors(double r_low, double angle, double z) {
    double x, y;
    polar_to_cartesian(r_low, angle, &x, &y);
    
    printf("0 A %.2f %.2f %.2f ", x, y, z);  // Main object (AP)
    
    // Scatter points around the main object
    for (int i = 0; i < 75 - 28; i++) {  // Adjust range if necessary
        scatter_points(x, y, MAX_RADIUS, z);
    }
}

int main() {
    srand(time(0));  // Seed the random number generator
    
    // First level: 5 APs
    double level = 1.0;
    int ap_count = 5;
    double radius_multiplier = BASE_RADIUS_MULTIPLIER * pow(LEVEL_RADIUS_MULTIPLIER, level - 1);  // Increased radius for each level
    for (int i = 0; i < ap_count; i++) {
        double r_low = radius_multiplier;
        double angle = 2 * i * PI / ap_count;
        double z = level * LEVEL_HEIGHT_MULTIPLIER;
        
        place_object_with_neighbors(r_low, angle, z);
    }
    
    // Second level: 9 APs
    level = 2.0;
    ap_count = 9;
    radius_multiplier = BASE_RADIUS_MULTIPLIER * pow(LEVEL_RADIUS_MULTIPLIER, level - 1);  // Further increase the radius
    for (int i = 0; i < ap_count; i++) {
        double r_low = radius_multiplier;
        double angle = 2 * i * PI / ap_count;
        double z = level * LEVEL_HEIGHT_MULTIPLIER;
        
        place_object_with_neighbors(r_low, angle, z);
    }

    printf("\n");
    return 0;
}

