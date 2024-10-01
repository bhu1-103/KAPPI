#include "synthwave.h"
#include <math.h>
#include <cstring>

const int circle_resolution = 100;
const int sun_radius = 10;
const int sun_distance_far = 20;

void draw_circle(float posx, float posy, float circle_radius)
{
	glColor4f(1.0f,0.0f,1.0f,0.1f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(posx,posy,0.0f);
		for(int i = 0; i < circle_resolution; i++) //more the resolution, more the circle curves.
		{
			float angle = 2 * PI * (float)i / (float)circle_resolution;
			float x = circle_radius * sinf(angle); //super proud of this one
			float y = circle_radius * cosf(angle); //pure bliss, isn't it?
			glVertex3f(posx+x,posy+y,0.0f);
		}
		glVertex3f(posx+0.0f,posy+float(circle_radius),0.0f);
	glEnd();
}

void draw_naked_circle(float posx, float posy, float posz, float circle_radius)
{
	glBegin(GL_LINE_STRIP);
		glVertex3f(posx,posy,posz);
		for(int i = 0; i < circle_resolution; i++) //more the resolution, more the circle curves.
		{
			float angle = 2 * PI * (float)i / (float)circle_resolution;
			float x = circle_radius * sinf(angle); //super proud of this one
			float y = circle_radius * cosf(angle); //pure bliss, isn't it?
			glVertex3f(posx+x,posy+y,posz);
		}
		glVertex3f(posx+0.0f,posy+float(circle_radius),0.0f);
	glEnd();
}

void draw_box(float room_length, float room_breadth, float room_height) //the blue box you see which also doubles as a border
{
	glColor4f(0.0f,1.0f,1.0f,1.0f);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.0f		  ,room_breadth,       0.0f);
		glVertex3f(0.0f		  ,0.0f	       ,       0.0f); //dont ask why the 0.0f is on the left
		glVertex3f(room_length	  ,0.0f        ,       0.0f);
		glVertex3f(room_length	  ,room_breadth,       0.0f);
		glVertex3f(0.0f		  ,room_breadth,       0.0f);
		glVertex3f(0.0f		  ,room_breadth,room_height);
		glVertex3f(room_length	  ,room_breadth,room_height);
		glVertex3f(room_length	  ,	   0.0f,room_height); //and now on the right
		glVertex3f(0.0f		  ,	   0.0f,room_height); //i do what i like.
		glVertex3f(0.0f		  ,room_breadth,room_height);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(0.0f		,0.0f     ,        0.0f);
		glVertex3f(0.0f         ,0.0f      ,room_height);

		glVertex3f(room_length,0.0f        ,	   0.0f);
		glVertex3f(room_length,0.0f        ,room_height);

		glVertex3f(room_length,room_breadth,       0.0f);
		glVertex3f(room_length,room_breadth,room_height);
	glEnd();
}


void draw_point(float w, float x, float y, float z, const char* wlan_code) {
    glLineWidth(10.0f); // Normal to x-y plane
    glBegin(GL_LINES);
    glColor4f(0.0f, 0.0f, 0.0f, 0.3f);
    glVertex3f(x, y, z);
    glVertex3f(x, y, 0.0f);
    glEnd();

    glPointSize(w == 0.0f ? 10.0f : 3.0f); // 0 is Access Point and 1 is Station
    glBegin(GL_POINTS);

    // Using if-else statements for string comparison
    if (strcmp(wlan_code, "A") == 0) {
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // Bright Red
    } else if (strcmp(wlan_code, "B") == 0) {
        glColor4f(1.0f, 0.5f, 0.0f, 1.0f); // Bright Orange
    } else if (strcmp(wlan_code, "C") == 0) {
        glColor4f(1.0f, 1.0f, 0.0f, 1.0f); // Neon Yellow
    } else if (strcmp(wlan_code, "D") == 0) {
        glColor4f(0.0f, 1.0f, 0.0f, 1.0f); // Neon Green
    } else if (strcmp(wlan_code, "E") == 0) {
        glColor4f(0.0f, 1.0f, 1.0f, 1.0f); // Bright Cyan
    } else if (strcmp(wlan_code, "F") == 0) {
        glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // Bright Blue
    } else if (strcmp(wlan_code, "G") == 0) {
        glColor4f(1.0f, 0.0f, 1.0f, 1.0f); // Magenta
    } else if (strcmp(wlan_code, "H") == 0) {
        glColor4f(1.0f, 0.5f, 0.5f, 1.0f); // Light Coral
    } else if (strcmp(wlan_code, "I") == 0) {
        glColor4f(0.5f, 0.5f, 0.0f, 1.0f); // Olive Green
    } else if (strcmp(wlan_code, "J") == 0) {
        glColor4f(0.8f, 0.8f, 0.0f, 1.0f); // Bright Yellow
    } else if (strcmp(wlan_code, "K") == 0) {
        glColor4f(0.8f, 0.0f, 0.0f, 1.0f); // Dark Red
    } else if (strcmp(wlan_code, "L") == 0) {
        glColor4f(0.0f, 0.8f, 0.0f, 1.0f); // Bright Green
    } else if (strcmp(wlan_code, "M") == 0) {
        glColor4f(0.5f, 0.0f, 0.5f, 1.0f); // Purple
    } else if (strcmp(wlan_code, "N") == 0) {
        glColor4f(1.0f, 0.8f, 0.0f, 1.0f); // Laser Lemon
    } else {
        glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // Default Bright Red
    }

    glVertex3f(x, y, z);
    glEnd();

    if (w == 0.0f) {
        draw_circle(x, y, 1.0f);
    }
}



void draw_grid()
{
	glColor4f(1.0f,0.0f,1.0f,1.0f);
	glLineWidth(2.0f);
	for(float i=-1000;i<=1000;i=i+1) //simple for loop to draw many squares
	{
		glBegin(GL_LINES);
			glVertex3f(i,+1000.0f,0.0f);
			glVertex3f(i,-1000.0f,0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(+1000.0f,i,0.0f);
			glVertex3f(-1000.0f,i,0.0f);
		glEnd();
	}
}

void draw_axes()
{
	glColor4f(0.0f,0.0f,0.0f,1.0f);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
		glVertex2f(-50.0f,0.0f);
		glVertex2f(+50.0f,0.0f);

		glVertex2f(0.0f,-50.0f);
		glVertex2f(0.0f,+50.0f);

		glVertex3f(0.0f,0.0f,-50.0f);
		glVertex3f(0.0f,0.0f,+50.0f);
	glEnd();
}
