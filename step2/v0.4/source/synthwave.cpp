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

void draw_point(float w, float x, float y, float z)
{
	glLineWidth(10.0f); //normal to x-y plane
	glBegin(GL_LINES);
	glColor4f(1.0f,1.0f,1.0f,0.5f);
	glVertex3f(x,y,z);
	glVertex3f(x,y,0.0f);

	glEnd();
	if(w==1.0f){glColor4f(1.0f,0.0f,0.0f,1.0f);glPointSize(10.0f);} //Station
	else {glColor4f(1.0f,1.0f,0.0f,1.0f);glPointSize(20.0f);} //AP
	//glColor3f(0.0f,1.0f,1.0f);
	//glPointSize(20.0f); //tip of the point
	glBegin(GL_POINTS);
		glVertex3f(x,y,z);
	glEnd();
}

void pyramid(float x, float y, float z, float py_w, float py_h)
{
	glColor4f(1.0,0.0,1.0,0.3);
	glBegin(GL_TRIANGLES);
		glVertex3f(  x+0.0f,  y+0.0f, z+0.0f); //triangle 1
		glVertex3f(x+py_w/2,y+py_w/2, z+py_h);
		glVertex3f(  x+py_w,  y+0.0f, z+0.0f);
		glVertex3f(  x+py_w,  y+0.0f, z+0.0f); //triangle 2
		glVertex3f(x+py_w/2,y+py_w/2, z+py_h);
		glVertex3f(  x+py_w,  y+py_w, z+0.0f);
		glVertex3f(  x+py_w,  y+py_w, z+0.0f); //triangle 3
		glVertex3f(x+py_w/2,y+py_w/2, z+py_h);
		glVertex3f(  x+0.0f,  y+py_w, z+0.0f);
		glVertex3f(  x+0.0f,  y+py_w, z+0.0f); //triangle 4
		glVertex3f(x+py_w/2,y+py_w/2, z+py_h);
		glVertex3f(  x+0.0f,  y+0.0f, z+0.0f);
	glEnd();

	glLineWidth(5.0f); //this part of the code is for making the thick borders
	glColor4f(1.0f,0.0f,1.0f,1.0f); //the code just before this serves the purpose of making the pyramids/mountains have a sort of translucent look
	glBegin(GL_LINES);
		glVertex3f(x+0.0f,y+0.0f,0.0f);
		glVertex3f(x+py_w,y+0.0f,0.0f);
		glVertex3f(x+py_w,y+0.0f,0.0f);
		glVertex3f(x+py_w,y+py_w,0.0f);
		glVertex3f(x+py_w,y+py_w,0.0f);
		glVertex3f(x+0.0f,y+py_w,0.0f);
		glVertex3f(x+0.0f,y+py_w,0.0f);
		glVertex3f(x+0.0f,y+0.0f,0.0f);
	glEnd(); //so satisfying

	
	glBegin(GL_LINES); //for drawing the square base of the pyramid
		glVertex3f(  x+0.0f,  y+0.0f,+0.0f);
		glVertex3f(x+py_w/2,y+py_w/2, py_h);
		glVertex3f(  x+py_w,  y+0.0f,+0.0f);
		glVertex3f(x+py_w/2,y+py_w/2, py_h);
		glVertex3f(  x+py_w,  y+py_w,+0.0f);
		glVertex3f(x+py_w/2,y+py_w/2, py_h);
		glVertex3f(  x+0.0f,  y+py_w,+0.0f);
		glVertex3f(x+py_w/2,y+py_w/2, py_h);
	glEnd(); //even more satisfying
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
