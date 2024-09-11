#ifndef SYNTHWAVE_H //if not defined
#define SYNTHWAVE_H //define

#include <GL/glut.h>
#define PI 3.14159265 //because I wanted only half of the sun and most likely wont be using it anywhere else. changed to pi

extern const int circle_resolution;
extern const int sun_radius;
extern const int sun_distance_far;

void draw_sun();
void draw_grid();
void draw_axes();
void draw_point(float w, float x, float y, float z, char wlan_codes);
void pyramid(float x, float y, float z, float py_w, float py_h);
void draw_box(float room_height, float room_breadth, float room_hright);
void draw_circle(float posx, float posy, float circle_radius);

#endif
