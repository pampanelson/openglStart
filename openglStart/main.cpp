//
//  main.cpp
//  openglStart
//
//  Created by Pampa Nie on 2019/7/26.
//  Copyright © 2019 Pampa Nie. All rights reserved.
//

#ifdef __APPLE__
/* Defined before OpenGL and GLUT includes to avoid deprecation messages */
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
#endif

#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "utils/LoadShader.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    
    GLuint programID = LoadShaders("./shaders/start.vert", "./shaders/start.frag");
    glUseProgram(programID);
    
    
    glEnd();
    glFlush();
}
int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1600,900);
    glutCreateWindow("opengl Glut Demo");
    glutDisplayFunc(display);
    glutMainLoop();
}
