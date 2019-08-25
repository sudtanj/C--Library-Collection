#include <iostream>
#include <stdlib.h>
#include <Math.h>//Needed for "exit" function
#define M_PI 3.14
#define X 0.525731112119133606
#define Z 0.850650808352039932

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
float xcDot = 3.0f;
float ycDot = 2.0f;
float xcLine = 3.0f;
float ycLine = -1.0f;
float xcTriangle = 5.0f;
float ycTriangle = 0.5f;
int r=1.2;

//Called when a key is pressed
void handleKeypress(unsigned char key,int x, int y) //The key that was pressed
{    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			exit(0); //Exit the program
	}
}
//Initializes 3D rendering
void initRendering()
{
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h)
{
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0,                   //The near z clipping coordinate
				   200.0);                //The far z clipping coordinate
}

void drawDot()
{
	glBegin(GL_POINTS);
	//SIN Graph
	glColor3f(0.0f,0.0f,1.0f);
	for(float x = -3.25f; x <= 3.01f; x += 0.05f)
	{
		glVertex3f(x-3.0f, 2+-sin(x),-5.0f);
	}
	//COS Graph
	glColor3f(0.0f,1.0f,0.0f);
	for(float x = -3.25f; x <= 3.01f; x += 0.05f)
	{
		glVertex3f(x-3.0f, 2+-cos(x),-5.0f);
	}
	glEnd();
}
void drawSinLine()
{
	glBegin(GL_LINE_STRIP);
	//Sin Graph
	glColor3f(0.0f,0.0f,1.0f);
	for(float x = -3.25f; x <= 3.05f; x += 0.05f)
	{
		glVertex3f(x-3.0f, -2-sin(x),-5.0f);
	}
	glEnd();
}
void drawCosLine()
{
	glBegin(GL_LINE_STRIP);
	//COS Graph
	glColor3f(0.0f,1.0f,0.0f);
	for(float x = -3.25f; x <= 3.05f; x += 0.05f)
	{
		glVertex3f(x-3.0f, -2-cos(x),-5.0f);
	}
	glEnd();
}

void drawCircleDot()
{
	glBegin(GL_POINTS);
	for(float x = 0.0f; x<=6.275f;x+=0.05f)
	{
		glVertex3f(xcDot+r*cos(x), ycDot+r*sin(x),-5.0f);
	}
	glEnd();
}
void drawCircleLines()
{
	glBegin(GL_LINE_STRIP);
	for(float x = 0.0f; x<=6.35f;x+=0.05f)
	{
		glVertex3f(xcLine+r*cos(x), ycLine+r*sin(x),-5.0f);
	}
	glEnd();
}

void drawCircleTriangles()
{
	int lineAmount = 8; //# of triangles used to draw circle
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;

	glBegin(GL_LINES);
		for(int i = 0; i <= lineAmount;i++)
		{
			glVertex3f(
			    xcTriangle + (r * cos(i *  twicePi / lineAmount)),
			    ycTriangle + (r* sin(i * twicePi / lineAmount)), -5.0f);
			glVertex3f(xcTriangle,ycTriangle,-5.0f);
		}
	glEnd();

	glBegin(GL_LINE_LOOP);
	for(int i =0; i <= 300; i++)
	{
		double angle = 2 * 3.14 * i / 300;
		double x = cos(angle);
		double y = sin(angle);
		glVertex3d(xcTriangle+x,ycTriangle+y,-5.0);
	}
   glEnd();
}

void drawSphereWithTriangles(float radio, int divO, int divA,float x,float y)
{
    float px, py,pz;
    int i,j;
    float incO = 2*M_PI / divO;
    float incA = M_PI /divA;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0,0.5,0);
    for (i= 0 ; i<= divO; i++)
	{
        for (j = 0; j<=divA ; j++)
		{
            pz = cos (M_PI-(incA*j))*radio;
            py = sin (M_PI-(incA*j))*sin (incO*i)*radio;
            px = sin (M_PI-(incA*j))*cos (incO*i)*radio;
            glVertex3f (x+px, y+py, -5.0f+pz);

            pz = cos (M_PI-(incA*j))*radio;
            py = sin (M_PI-(incA*j))*sin (incO*(i+1))*radio;
            px = sin (M_PI-(incA*j))*cos (incO*(i+1))*radio;
            glVertex3f (x+px, y+py,-5.0f+pz);
   	    }
	}
glEnd();
}

void drawSphereWithWire()
{
	glutWireSphere(0.5,10,10);  //void glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
	//glutSolidSphere(GLdouble radius,GLint slices, GLint stacks);
}

void drawSphereWithPoints(GLfloat x,GLfloat y)
{
	glBegin(GL_POINTS);
	for(GLfloat phi =0;phi<180;phi+=4)
	{
		for(GLfloat theta=0;theta<360;theta+=4)
		{
			glVertex3f(x+(cos((phi/180)*M_PI)*0.9f*(sin((theta/180)*M_PI))),
			y+(0.9f*(sin((theta/180)*M_PI))*(sin((phi/180)*M_PI))),
			-5.0f+0.9f*(cos((theta/180)*M_PI)));
		}
	}
   glEnd();
}

void drawLines()
{
	glBegin(GL_LINES);
	//Y-Axis Dot
			glColor3f(1.0f,2.0f,0.0f);
			glVertex3f(-6.25f,1.0f,-5.0f);
			glVertex3f(-6.25f,3.0f,-5.0f);
	//X-Axis Dot
			glVertex3f(-6.25f,1.875f,-5.0f);
			glVertex3f(0.25f,1.875f,-5.0f);

	//Y-Axis Line
			glColor3f(1.0f,2.0f,0.0f);
			glVertex3f(-6.25f,-1.0f,-5.0f);
			glVertex3f(-6.25f,-3.0f,-5.0f);
	//X-Axis Line
			glVertex3f(-6.25f,-2.095f,-5.0f);
			glVertex3f(0.25f,-2.095f,-5.0f);

	//y-Axis Circle Dot
		glVertex3f(xcDot,ycDot+r,-5.0f);
		glVertex3f(xcDot,ycDot-r,-5.0f);
	//x-Axis Circle Dot
		glVertex3f(xcDot+r,ycDot,-5.0f);
		glVertex3f(xcDot-r,ycDot,-5.0f);

	//y-Axis Circle Line
		glVertex3f(xcLine,ycLine+r,-5.0f);
		glVertex3f(xcLine,ycLine-r,-5.0f);
	//x-Axis Circle Line
		glVertex3f(xcLine+r,ycLine,-5.0f);
		glVertex3f(xcLine-r,ycLine,-5.0f);

	glEnd();
}
//Draws the 3D scene
void drawScene() //Fungsi yang dipanggil
{
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glTranslatef(0.0f,0.0f,-4.0f);//move forward 4 units
    glPointSize(3.0f);


   	drawSphereWithTriangles(0.5, 25, 25,1.2,1.2);
    drawSphereWithPoints(0.0,0.0);
    drawCircleDot();
    drawCircleLines();
    drawCircleTriangles();
    drawDot();
    drawLines();
	drawSinLine();
	drawCosLine();


	glFlush();
	glutSwapBuffers(); //Send the 3D scene to the screen
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080); //Set the window size

	//Create the window
	glutCreateWindow("Lab CGK Week 3b");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene); //Nampilkan sesuatu di layar
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}









