// UTS Komputer Graphics @ Dr. David Hareva
// Name : Sudono Tanjung
// NIM : 00000012273
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif
#include <math.h>
#include <iostream>
#define PI 3.14159265;

static int hourAngle = 0, minAngle = 0, secAngle = 0, speedDetik = 0, speedMenit = 0, speedJam = 0;
static int speed = 0;
static int test = 0;

void special(int key, int, int) {
	switch (key) {
	case GLUT_KEY_LEFT: 
		test = 1;
		break;
	case GLUT_KEY_RIGHT: 
		test = 2;
		break;
	default: return;
	}
	glutPostRedisplay();
}

void lingkaran(float scale) {
	glPushMatrix();
	glScalef(scale, scale, 0.0);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i <= 300; i++) {
		double angle = 2 * (i / 300.0) * PI;

		double x = cos(angle);
		double y = sin(angle);
		glColor3f(0, 1, 0);
		glVertex2d(x, y);
	}
	glEnd();
	glPopMatrix();
}

void wireBox(GLdouble width, GLdouble height, GLdouble depth) {
	glPushMatrix();
	glScalef(width, height, depth);
	glutWireCube(1.0);
	glPopMatrix();
}




void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	// jarum detik, menit, dan jam                         
	secAngle = speedDetik;
	glPushMatrix();
	glRotatef((GLfloat)secAngle, 0.0, 0.0, 1.0);
	glTranslatef(0.5, 0.2, 0.0);
	glColor3f(1, 0, 0);
	wireBox(1.5, 0.2, 0.0);
	glPopMatrix();
	//menit
	minAngle = speedMenit;
	glPushMatrix();
	glRotatef((GLfloat)minAngle, 0.0, 0.0, 1.0);
	glTranslatef(1.5, 0.2, 0.0);
	glColor3f(1, 0, 0);
	wireBox(2.5, 0.2, 0.0);
	glPopMatrix();
	// jam
	hourAngle = speedJam;
	glPushMatrix();
	glRotatef((GLfloat)hourAngle, 0.0, 0.0, 1.0);
	glTranslatef(2.5, 0.2, 0.0);
	glColor3f(1, 0, 0);
	wireBox(3.5, 0.2, 0.0);
	glPopMatrix();
	// bingkai jam dan penunjuk jam
	lingkaran(4.0);



	glFlush();
}

void timer(int v) {
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //front view    
	std::cout << "a"<<std::endl;
	if (test == 1) {
		speed = 5;
		(speedDetik -= speed) %= 360;
		(speedMenit += speed-1) %= 360;
		(speedJam -= speed-2) %= 360;
	}
	if (test == 2) {
		speed = -5;
		(speedDetik += speed) %= 360;
		(speedMenit -= speed-1) %= 360;
		(speedJam += speed-2) %= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(1, timer, v); //10000/60
}



void reshape(GLint w, GLint h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, GLfloat(w) / GLfloat(h), 1.0, 20.0);
}


void init() {
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1, 2, 8, 0, 0, 0, 0, 1, 0);
}


int main2(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(80, 80);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Watch by David Hareva [xxxxxxx]");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(1000, timer, 0);
	glutSpecialFunc(special);
	init();
	glutMainLoop();
	return 0;
}