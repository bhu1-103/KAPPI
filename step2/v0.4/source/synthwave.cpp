#include "synthwave.h"
#include <math.h>

const int circle_resolution = 100;
const int sun_radius = 10;
const int sun_distance_far = 20;

void draw_circle(float posx, float posy, float circle_radius)
{
	glColor4f(1.0f,0.0f,1.0f,0.1f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(posx,posy,0.0f);
		for(int i = 0; i < circle_resolution; i++)
		{
			float angle = 2 * PI * (float)i / (float)circle_resolution;
			float x = circle_radius * sinf(angle);
			float y = circle_radius * cosf(angle);
			glVertex3f(posx+x,posy+y,0.0f);
		}
		glVertex3f(posx+0.0f,posy+float(circle_radius),0.0f);
	glEnd();
}

void draw_box(float room_length, float room_breadth, float room_height)
{
	glColor4f(0.0f,1.0f,1.0f,1.0f);
	glBegin(GL_LINE_STRIP);
		glVertex3f(0.0f		  ,room_breadth,	   0.0f);
		glVertex3f(0.0f		  ,0.0f		   ,	   0.0f);
		glVertex3f(room_length,0.0f		   ,	   0.0f);
		glVertex3f(room_length,room_breadth,	   0.0f);
		glVertex3f(0.0f		  ,room_breadth,	   0.0f);
		glVertex3f(0.0f		  ,room_breadth,room_height);
		glVertex3f(room_length,room_breadth,room_height);
		glVertex3f(room_length,		   0.0f,room_height);
		glVertex3f(0.0f		  ,		   0.0f,room_height);
		glVertex3f(0.0f		  ,room_breadth,room_height);
	glEnd();

	glBegin(GL_LINES);
		glVertex3f(0.0f		  ,0.0f		   ,	   0.0f);
		glVertex3f(0.0f		  ,		   0.0f,room_height);

		glVertex3f(room_length,0.0f		   ,	   0.0f);
		glVertex3f(room_length,		   0.0f,room_height);

		glVertex3f(room_length,room_breadth,	   0.0f);
		glVertex3f(room_length,room_breadth,room_height);
	glEnd();
}

void draw_point(float w, float x, float y, float z, char wlan_code)
{
	glLineWidth(10.0f); //normal to x-y plane
	glBegin(GL_LINES);
	glColor4f(0.0f,0.0f,0.0f,0.3f);
	glVertex3f(x,y,z);
	glVertex3f(x,y,0.0f);
	glEnd();

	glPointSize(w == 0.0f ? 40.0f : 15.0f);
	glBegin(GL_POINTS);
	switch (wlan_code) {
		case 'A': glColor4f(1.0f, 0.0f, 0.0f, 1.0f); break; // Bright Red
		case 'B': glColor4f(1.0f, 0.5f, 0.0f, 1.0f); break; // Bright Orange
		case 'C': glColor4f(1.0f, 1.0f, 0.0f, 1.0f); break; // Neon Yellow
		case 'D': glColor4f(0.0f, 1.0f, 0.0f, 1.0f); break; // Neon Green
		case 'E': glColor4f(0.0f, 1.0f, 1.0f, 1.0f); break; // Bright Cyan
		case 'F': glColor4f(0.0f, 0.0f, 1.0f, 1.0f); break; // Bright Blue
		case 'G': glColor4f(1.0f, 0.0f, 1.0f, 1.0f); break; // Magenta
		case 'H': glColor4f(1.0f, 0.5f, 0.5f, 1.0f); break; // Light Coral
		case 'I': glColor4f(0.5f, 0.5f, 0.0f, 1.0f); break; // Olive Green
		case 'J': glColor4f(0.8f, 0.8f, 0.0f, 1.0f); break; // Bright Yellow
		case 'K': glColor4f(0.8f, 0.0f, 0.0f, 1.0f); break; // Dark Red
		case 'L': glColor4f(0.0f, 0.8f, 0.0f, 1.0f); break; // Bright Green
		case 'M': glColor4f(0.5f, 0.0f, 0.5f, 1.0f); break; // Purple
		case 'N': glColor4f(1.0f, 0.8f, 0.0f, 1.0f); break; // Laser Lemon
		default: glColor4f(1.0f, 0.0f, 0.0f, 1.0f); break; // Default Bright Red
	}
	glVertex3f(x,y,z);
	glEnd();
	if (w == 0.0f){draw_circle(x,y,1.0f);}
}

void draw_grid()
{
	glColor4f(1.0f,0.0f,1.0f,1.0f);
	glLineWidth(2.0f);
	for(float i=-50;i<=50;i=i+1) //simple for loop to draw many squares
	{
		glBegin(GL_LINES);
			glVertex3f(i,+50.0f,0.0f);
			glVertex3f(i,-50.0f,0.0f);
		glEnd();

		glBegin(GL_LINES);
			glVertex3f(+50.0f,i,0.0f);
			glVertex3f(-50.0f,i,0.0f);
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
