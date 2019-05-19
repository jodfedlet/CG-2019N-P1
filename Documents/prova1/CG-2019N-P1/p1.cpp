#include "GL/gl.h"
#include "GL/glut.h"
/*
to compile
 g++ translation.cpp -o make -lglut -lGLU -lGL
 ./make

*/

GLfloat escala = 1;
GLfloat rotation = 0;
GLfloat movx, movy;


void Desenha(){
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5,5,-5,5);

	glScalef(escala,escala,0);
	glRotatef(rotation,0,0,1);
	glTranslatef(movx,movy,0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
/*
	O codigo vai ser aqui
*/

	glFlush();

}
void Teclas(unsigned char tecla, GLint x, GLint y){
	switch(tecla){
		case '+':
			escala++;
			break;
		case '-':
		 	escala--;
		 	break;
		case '1':
			rotation+=3;
			break;
		case '2':
		 	rotation-=3;
		 	break;


	}
	Desenha();
}
void TeclasEspeciais(GLint tecla, GLint x, GLint y){
	switch(tecla){
		case GLUT_KEY_UP: movy++;
				break;
		case GLUT_KEY_DOWN: movy--;
				break;
		case GLUT_KEY_LEFT: movx--;
				break;
		case GLUT_KEY_RIGHT: movx++;
				break;
	}
	Desenha();

}

int main(int argc, char** argv){

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(800,600);
	glutInitWindowPosition(320,150);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("Primeiro app openGl");
	glutKeyboardFunc(Teclas);
	glutSpecialFunc(TeclasEspeciais);
	
	glutDisplayFunc(Desenha);
	glClearColor(0,0,1,0);
	glutMainLoop();
	
	return 0;
}
