#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <iostream>

/*
to compile
 g++ p1.cpp -o make -lglut -lGLU -lGL
 ./make

*/

GLfloat angleZ = 0.0f;
GLfloat angleX = 0.0f;


void Display(){
	// Set Background Color
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	//glLoadIdentity();

	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity( );
	   glOrtho(-10, 10, 10, -10, 1, 10);

	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity( );
	   gluLookAt(3, 4, 2,  //from. Posicao onde a camera esta posicionada
	             0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
	             0, 0, 1); //up. Vetor Up.

	    glRotated(angleZ,0.0f,0.0f,1.0f);
	    glRotated(angleX,1.0f,0.0f,0.0f);

		glBegin(GL_QUADS);

			    glColor3f(1.0f,0.0f,0.0f); //red part
			    glVertex3f(1.0f,1.0f,1.0f);
			    glVertex3f(1.0f,1.0f,-1.0f);
			    glVertex3f(-1.0f,1.0f,-1.0f);
			    glVertex3f(-1.0f,1.0f,1.0f);


			    glColor3f(0.0f,1.0f,0.0f); //green part
			    glVertex3f(1.0f,-1.0f,1.0f);
			    glVertex3f(1.0f,-1.0f,-1.0f);
			    glVertex3f(1.0f,1.0f,-1.0f);
			    glVertex3f(1.0f,1.0f,1.0f);


			    glColor3f(0.0f,0.0f,1.0f); //blue part
			    glVertex3f(-1.0f,-1.0f,1.0f);
			    glVertex3f(-1.0f,-1.0f,-1.0f);
			    glVertex3f(1.0f,-1.0f,-1.0f);
			    glVertex3f(1.0f,-1.0f,1.0f);


			    glColor3f(1.0f,1.0f,0.0f); //yellow part
			    glVertex3f(-1.0f,1.0f,1.0f);
			    glVertex3f(-1.0f,1.0f,-1.0f);
			    glVertex3f(-1.0f,-1.0f,-1.0f);
			    glVertex3f(-1.0f,-1.0f,1.0f);


			    glColor3f(0.0f,1.0f,1.0f); //face cyan
			    glVertex3f(1.0f,1.0f,-1.0f);
			    glVertex3f(1.0f,-1.0f,-1.0f);
			    glVertex3f(-1.0f,-1.0f,-1.0f);
			    glVertex3f(-1.0f,1.0f,-1.0f);


			    glColor3f(1.0f,0.0f,1.0f); //face magenta
			    glVertex3f(1.0f,-1.0f,1.0f);
			    glVertex3f(1.0f,1.0f,1.0f);
			    glVertex3f(-1.0f,1.0f,1.0f);
			    glVertex3f(-1.0f,-1.0f,1.0f);

	    glEnd();

		glFlush();
		glutSwapBuffers();

	}

int main(int argc, char** argv){

	// Initialize GLUT and process user parameters
	glutInit(&argc, argv);

	// Request double buffered true color window with Z-buffer
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(640,480);
	glutInitWindowPosition(320,150);
	
	glutCreateWindow("Prova 1 De CG");

	//gluPerspective(70,(double)640/480,1,1000);
	glEnable(GL_DEPTH_TEST);
	
	glutDisplayFunc(Display);
	
	glutMainLoop();
	
	return 0;
}
