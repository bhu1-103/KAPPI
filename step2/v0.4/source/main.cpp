#include <GL/glut.h>
#include <stdlib.h>
#include "synthwave.h"

float povX = 0.0f;
float povY = 0.0f;
float povZ = 0.0f;
float screenWidth = 1280;
float screenHeight = 720;
float arg1,arg2,arg3;

void initOpenGL() {
    glClearColor(0.2f, 0.0f, 0.2f, 1.0f); //deep dark purple bg
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,screenWidth/screenHeight,1.0f,50.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(povX,povY,3.0f+povZ, //eye position
                   0.0f,0.0f,0.0f, //center position
                   0.0f,1.0f,0.0f); //z axis direction

    //begin drawing
	draw_grid();
	draw_axes();
	draw_point(arg1,arg2,arg1);

	//glLineWidth(1.0f);
    glutSwapBuffers();
}

void keyboardCallback(unsigned char key, int x, int y)
{
        if(key == 'a'){povX -= 0.1f;glutPostRedisplay();}
        if(key == 'd'){povX += 0.1f;glutPostRedisplay();}
        if(key == 'w'){povY -= 0.1f;glutPostRedisplay();}
        if(key == 's'){povY += 0.1f;glutPostRedisplay();}
        if(key == 'q'){povZ -= 0.1f;glutPostRedisplay();}
        if(key == 'e'){povZ += 0.1f;glutPostRedisplay();}
}

int main(int argc, char** argv) {

	arg1 = atof(argv[1]);
	arg2 = atof(argv[2]);
	arg3 = atof(argv[3]);
	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(screenWidth, screenHeight);
    glViewport(0,0,screenWidth,screenHeight);
    glutCreateWindow("idk");
    initOpenGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardCallback);
    glutMainLoop();

    return 0;
}

