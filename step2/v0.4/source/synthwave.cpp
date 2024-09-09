#include "synthwave.h"
#include <math.h>

const int circle_resolution = 100;
const int sun_radius = 10;
const int sun_distance_far = 20;

void draw_sun()
{
	glColor3f(1.0f,0.0f,0.2f);
	glBegin(GL_TRIANGLE_FAN); //to understand what a triangle fan is, look at an n64 game and think, "the models in those games were made of triangles"
		glVertex3f(0.0f,sun_distance_far,0.0f);
		
		for(int i = 0; i < circle_resolution+1; i++) 
		{
			float angle = 2 * HALF_PI * (float)i / (float)circle_resolution; //resolution here means the number of triangles to combine to make a circle
			float x = sun_radius * cosf(angle); //to find x co-ordinate, we use cos()
			float z = sun_radius * sinf(angle); //to find z co-ordinate, we use sin()
			glVertex3f(x,sun_distance_far,z);   //make the triangle fan
		}

		glVertex3f(sun_radius,sun_distance_far,0.0f); //end the triangle fan
	glEnd();
}

void draw_point(float x, float y, float z)
{
	glColor3f(1.0f,0.0f,0.7f);
	glPointSize(30.0f); //tip of the point
	glBegin(GL_POINTS);
		glVertex3f(x,y,z);
	glEnd();
	
	glLineWidth(10.0f); //normal to x-y plane
	glBegin(GL_LINES);
	glColor4f(1.0f,0.0f,0.0f,0.5f);
		glVertex3f(x,y,z);
		glVertex3f(x,y,0.0f);
	glEnd();
}

void draw_grid()
{
	glColor4f(1.0f,0.0f,1.0f,1.0f);
	glLineWidth(2.0f);
	for(float i=-50;i<=50;i=i+0.5) //simple for loop to draw many squares
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
