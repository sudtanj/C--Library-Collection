#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <cmath>
#include <math.h>

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
	#include <OpenGL/OpenGL.h>
	#include <GLUT/glut.h>
#else
//#include <GL/glew.h>
#include <GL/glut.h>
#endif
using namespace std;
GLfloat Offset = 3.6;
GLfloat xy1[3][1] = {-0.4, 0.2f, 1.0f}; //-4,2
GLfloat xy2[3][1] = {-0.3, 0.4f, 1.0f}; // -3,4
GLfloat xy3[3][1] = {-0.2f, 0.2f, 1.0f}; // -2,2

GLfloat xyResult1[3][1];
GLfloat xyResult2[3][1];
GLfloat xyResult3[3][1];

//Isi matrix untuk perkalian
GLfloat Tx [3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};

	GLfloat Reflection[3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};

	GLfloat Rotasi[3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};

	GLfloat Txi [3][3] = {
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0},
	};

GLfloat TxReflection[3][3];
GLfloat TxReflectionRotasi[3][3];
GLfloat Hasil[3][3];

void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) {    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			exit(0); //Exit the program
	}
}
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera

	//GLAPI void GLAPIENTRY gluPerspective (GLdouble fovy, GLdouble aspect, GLdouble zNear, GLdouble zFar);
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

void MatrixMulti()
{
    //Isi perkalian matrix disini
}

void drawLines()
{
    glBegin(GL_LINES); // COORDINATE LINES
		glColor3f( 1.0f, 1.0f, 1.0f);
		int max_lin = 2.0f;
		// horizontal
		glVertex3f(-max_lin, 0.0f, -5.0f);
		glVertex3f(max_lin, 0.0f, -5.0f);
		//vertical
		glVertex3f(0.0, max_lin, -5.0f);
		glVertex3f(0.0, -max_lin, -5.0f);

		//major tick vertical
		for (int i = -19 ; i < 20 ; i++) {
		//glColor3f( 1.0f, 0.0f, 0.0f);
		float tick = 0.07f;
			glVertex3f(0.0+i*0.1, tick, -5.0f);
			glVertex3f(0.0+i*0.1, 0.0, -5.0f);
		}

		//major tick horizontal
		for (int i = -19 ; i < 20 ; i++) {
		//glColor3f( 1.0f, 0.0f, 0.0f);
		float tick = 0.07f;
			glVertex3f(tick, 0.0+i*0.1, -5.0f);
			glVertex3f(0.0, 0.0+i*0.1, -5.0f);
		}

		// reflection line y = 2x -5;

		glVertex3f(-2.0f, -1.8f, -5.0f);
		glVertex3f(1.8f , 2.0f, -5.0f);

	glEnd(); //End coordianate
}

void drawTriangle()
{
	glBegin(GL_TRIANGLES); //Start triangle coordinates

		glVertex3f(-0.4, 0.2f, -5.0f); //-4,2
		glVertex3f(-0.3, 0.4f, -5.0f); // -3,4
		glVertex3f(-0.2f, 0.2f, -5.0f); // -2,2

        //Menggambar hasil
		glColor3f(1.0,0.0,0.0);
		glVertex3f(xyResult1[0][0],xyResult1[1][0]-Offset,-5.0f);
		glVertex3f(xyResult2[0][0],xyResult2[1][0]-Offset,-5.0f);
		glVertex3f(xyResult3[0][0],xyResult3[1][0]-Offset,-5.0f);


	glEnd(); //End triangle coordinates
}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	MatrixMulti();
	drawLines();
    drawTriangle();

	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 400); //Set the window size

	//Create the window
	glutCreateWindow("Lab Week 6");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}









