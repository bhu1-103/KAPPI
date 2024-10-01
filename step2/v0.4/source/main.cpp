#include <GL/glut.h>
#include <stdlib.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <math.h>
#include "synthwave.h"
#include <string>
#include <cstring>

float povX = 0.0f;
float povY = 0.0f;
float povZ = 0.0f;
float screenWidth = 1280;
float screenHeight = 720;
float room_length = 7.0f;
float room_breadth = 5.0f;
float room_height = 3.0f;

std::vector<float> points;
std::vector<std::string> wlan_codes;  // Change from char to std::string

void initOpenGL() {
    glClearColor(0.2f, 0.0f, 0.2f, 1.0f); // Deep dark purple background
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, screenWidth / screenHeight, 1.0f, 5000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(povX, povY, 6.0f + povZ, // Eye position
              0.0f, 0.0f, 0.0f,      // Center position
              0.0f, 1.0f, 0.0f);     // Up direction

    // Begin drawing
    //draw_grid();
    draw_axes();
	glColor4f(1.0f,1.0f,1.0f,0.4f);
	/*draw_naked_circle(0.0f,0.0f,0.0f,05.0f);
	for(float rings=5.0f;rings<15.0f;rings+=1.0f)
		{
			draw_naked_circle(0.0f,0.0f,rings-5.0f,rings);
		}*/
    //draw_box(room_length, room_breadth, room_height);

    for (size_t i = 0; i < points.size(); i += 4) {
        draw_point(points[i], points[i+1] / 10.0f, points[i+2] / 10.0f, points[i+3] / 10.0f, wlan_codes[i/4].c_str());  // Adjust to use string



    }
    
    glutSwapBuffers();
}

void keyboardCallback(unsigned char key, int x, int y) {
    if (key == 'a') { povX -= 1.0f; glutPostRedisplay(); }
    if (key == 'd') { povX += 1.0f; glutPostRedisplay(); }
    if (key == 'w') { povY -= 1.0f; glutPostRedisplay(); }
    if (key == 's') { povY += 1.0f; glutPostRedisplay(); }
    if (key == 'q') { povZ -= 1.0f; glutPostRedisplay(); }
    if (key == 'e') { povZ += 1.0f; glutPostRedisplay(); }
}

int main(int argc, char** argv) {
    if (argc < 6 || (argc - 1) % 5 != 0) {
        std::cerr << "bruh " << argv[0] << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; i += 5) {
        if (i + 4 >= argc) {
            std::cerr << "even more bruh " << i << std::endl;
            return 1;
        }
        float x = atof(argv[i + 0]);
        std::string wlan_code = argv[i + 1];  // Change to std::string
        float y = atof(argv[i + 2]);
        float z = atof(argv[i + 3]);
        float w = atof(argv[i + 4]);
        points.push_back(x);
        points.push_back(y);
        points.push_back(z);
        points.push_back(w);
        wlan_codes.push_back(wlan_code);  // Store as string
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

