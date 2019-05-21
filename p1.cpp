/*
Implementar uma aplicação gráfica usando OpenGL que mostre dois cubos coloridos girando,
um ao centro da tela e outro orbitando ao redor desse primeiro cubo.

Autor: Jod Fedlet PIERRE
email: fedletpierre15@gmail.com

github: jodfedlet

to compile
 g++ p1.cpp -o make -lglut -lGLU -lGL
 ./make
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <GL/gl.h>
#include <iostream>


GLfloat translate = 5;
GLfloat angleX = 0;
GLfloat angleY = 0;
GLfloat angleYY = 0;

//Define how many frames per seconds we want our
// applications to run.
const unsigned int FRAMES_PER_SECOND = 30;
const unsigned int UPDATE_INTERVAL_MS = 1000 / FRAMES_PER_SECOND;

void cube(){
	glScalef(0.5f,0.5f,0.5f);
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

}


void Display(){
	// Set Background Color
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	// Clear screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	   glMatrixMode(GL_PROJECTION);
	   glLoadIdentity( );
	   glOrtho(-10, 10, 10, -10, 1, 10);

	   glMatrixMode(GL_MODELVIEW);
	   glLoadIdentity( );
	   gluLookAt(3, 4, 2,  //from. Posicao onde a camera esta posicionada
	             0, 0, 0,  //to. Posicao absoluta onde a camera esta vendo
	             0, 0, 0.5); //up. Vetor Up.

	    
	    

	   	
	   	glRotatef(angleY,0.0f,1.0f,0.0f);
	    glPushMatrix();
	    glRotatef(angleYY,0.0f,1.0f,0.0f);
	   			cube();//chamando o 1o cubo
	    glPopMatrix();

	   
	    glTranslatef(translate,0.0f,0.0f);
	 

	    glPushMatrix();
	    
		    glRotatef(angleY,0.0f,1.0f,0.0f);
		   	glRotatef(angleX,1.0f,0.0f,0.0f);
		   
	    	 cube();//chamando o 2o cubo
	    glPopMatrix();

		
		glutSwapBuffers();

	}

	void update(int value)
{
	// Update the angle of rotation
	angleY += 0.5;
	angleYY += -0.8;
	
	angleX += 0.8;
	

	// Request a new frame rendering
	glutPostRedisplay();

	// Re-schedule the update() function to be called after a few
	// milliseconds again.
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
}


void mouse(int button, int state, int x, int y)
{
	std::cout << "Mouse pressed: button=" << button << ", state=" << state << ", x=" << x << " y=" << y << std::endl;
}

void initView()
{
	// We want a window to the world that is a rectangle starting at (0,0)
	// and ending at (WIDTH, HEIGHT).
	glViewport(0, 0, 640, 480);
	
	// Adjust the global projection (camera)
	glMatrixMode(GL_PROJECTION);
	
	// Reset any existing projection settings and adjust the field-of-view (FOV)
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 200.0);
	
	// From now on, every transformation is to be applied on each object, e.g. modelview.
	glMatrixMode(GL_MODELVIEW);
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
	// Schedule the update() function to be called after a few
	// milliseconds (calculated as 1000 milliseconds divided by FPS).
	glutTimerFunc(UPDATE_INTERVAL_MS, update, 0);
	
	glutMainLoop();
	
	return 0;
}
