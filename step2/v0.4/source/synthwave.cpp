#include "synthwave.h"
#include <math.h>

const int circle_resolution = 100;
const int sun_radius = 10;
const int sun_distance_far = 20;

void draw_point(float w, float x, float y, float z, char wlan_code)
{
	glLineWidth(10.0f); //normal to x-y plane
	glBegin(GL_LINES);
	glColor4f(0.0f,0.0f,0.0f,0.3f);
	glVertex3f(x,y,z);
	glVertex3f(x,y,0.0f);
	glEnd();

	glPointSize(w == 0.0f ? 20.0f : 5.0f);
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
	glColor3f(0.0f,0.0f,0.0f);
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
