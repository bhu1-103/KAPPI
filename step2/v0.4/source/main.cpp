#include <GL/glut.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iostream>
#include "synthwave.h"

float povX = 0.0f;
float povY = 0.0f;
float povZ = 0.0f;
float screenWidth = 1280;
float screenHeight = 720;

std::vector<float> points;

void initOpenGL() {
    glClearColor(0.2f, 0.0f, 0.2f, 1.0f); // Deep dark purple background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, screenWidth / screenHeight, 1.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(povX, povY, 3.0f + povZ, // Eye position
              4.0f, 3.0f, 0.0f,      // Center position
              0.0f, 1.0f, 0.0f);     // Up direction

    // Begin drawing
    draw_grid();
    draw_axes();

    for (size_t i = 0; i < points.size(); i += 4) {
        draw_point(points[i], points[i+1] / 10.0f, points[i+2] / 10.0f, points[i+3] / 10.0f);
    }
	
    glutSwapBuffers();
}

void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 'a') { povX -= 0.1f; glutPostRedisplay(); }
    if (key == 'd') { povX += 0.1f; glutPostRedisplay(); }
    if (key == 'w') { povY -= 0.1f; glutPostRedisplay(); }
    if (key == 's') { povY += 0.1f; glutPostRedisplay(); }
    if (key == 'q') { povZ -= 0.1f; glutPostRedisplay(); }
    if (key == 'e') { povZ += 0.1f; glutPostRedisplay(); }
}

int main(int argc, char** argv) {
    if (argc < 5 || (argc - 1) % 4 != 0) {
        std::cerr << "bruh " << argv[0] << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i += 4) {
        if (i + 3 >= argc) {
            std::cerr << "Error: Missing coordinates for point at index " << i << std::endl;
            return 1;
        }
        float x = atof(argv[i]);
        float y = atof(argv[i + 1]);
        float z = atof(argv[i + 2]);
        float w = atof(argv[i + 3]);
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
        points.push_back(w);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(static_cast<int>(screenWidth), static_cast<int>(screenHeight));
    glViewport(0, 0, static_cast<int>(screenWidth), static_cast<int>(screenHeight));
    glutCreateWindow("lol");
    initOpenGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardCallback);
    glutMainLoop();

    return 0;
}

