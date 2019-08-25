//**************************************
// Name: Bouncing Ball Program in OpenGL
// Description:A HomeWork Assignment for CS381 (Fall 1998). It's a classic "bouncing ball" program that uses the OpenGL Libraries which can be found elsewhere on this site. I used the GLUT event handler interface to control Mouse functions.Found at: http://modzer0.cs.uaf.edu/~hartsock/C_Cpp/OpenGL/GLBounce.html
// By: Found on the World Wide Web
//**************************************

/************************************************************************\
|	
|	Shawn R. Hartsock
|	CS 381
|	Prof: Hartman
|	due: 10/12/1998
|
|	GLBounce.c
|		a bouncing baby Polygon! Watch where you click! Right and Left Mouse
|		Buttons Do stuff! Wow! ;}
|
\************************************************************************/
																																		 /**/
//#include "include\Angel.h"
# include <GL/glut.h>	

																																			/**/
/**************GLOBALS***************************************************/
double spin = 0.0, scale = 1.0, scaleOffset = -0.005;
int tx = 60, ty = 67, dy = 2, dx =3, DIRspin = 1, HEXsize = 1; 
int hex[13][2] ={{ 0,0 },
									{ 0,27 },{ 26,12},{26,-12},{ 0,-27},{-26,-12},{-26,12 },
									{-54,0 },{-24,51},{24,51 },{ 54,0 },{ 24,-51},{-24,-51} };
int Green[18] = {	0,1,9 , 0,2,10 , 0,3,11 , 0,4,12 , 0,5,7 , 0,6,8	};
int Purple[18]	= {	0,2,9 , 0,3,10 , 0,4,11 , 0,5,12 , 0,6,7 , 0,1,8	};
/************************************************************************\
|	I didn't wanna use globals but...
|	had troubles with pointers, then Global Structs, then Dynamic Memory... 
|	**sigh** sometimes simple is better, even if it is a little ugly
|	
|	spin ...angle of rotation
|	scale...proportion of scaling (default identity or 1)	changed by:
|	scaleOffset amount of Shrink or Grow... summed into scale over a loop
|
|
|	tx,ty... Translate x,y
|	dx,dy... change in x,y
|	DIRspin is Direction of Spin.. + or -
|	HEXsize determines Shrink or Grow.
|
|	Green and Purple specify order for drawing verticies, hex specifies
|	the verticies to draw.
\************************************************************************/
/************************************************************************\
|	HexTriangles() || Draws a green and Purple six pointed star...
|	|| (This one is my wife's favorite)
\*****************/
void HexTriangles(){
	int ii = 0, x = 0, y =0;
	double R = 0.0, G = 0.5, B= 0.0;
 glColor3d(R,G,B);	
	glBegin(GL_TRIANGLES);
		for(ii = 0; ii < 18; ii++){
			x = hex[Green[ii]][0];
			y = hex[Green[ii]][1];
			/* Iterates over Green */
			if(Green[ii] == 0){ glColor3d(0.0,0.0,0.0);}
			glVertex2i(x,y);
			R = B += 0.02;
			glColor3d(R,G,B);
		}
		R = 5.0; G = 0.0; B = 5.0;
		for(ii = 0; ii < 18; ii++){
			x = hex[Purple[ii]][0];
			y = hex[Purple[ii]][1];
			/* Iterates over Purple */
			if(Green[ii] == 0){ glColor3d(0.8,0.8,0.8);}
			glVertex2i(x,y);
			G += 0.02;
			glColor3d(R,G,B);
		}
	
	glEnd();
}
/************************************************************************\
|	display || The Default drawing function called at start up...
|					|| I'm a little dubious as to the order... this is the order
|					|| that things finally work in, but WHY?
\**********/
void display(void) {
 glClear (GL_COLOR_BUFFER_BIT);
	glPushMatrix(); /* Put onto matrix stack? */
	glTranslatef(tx,ty,0); /* Move to/from tx,ty */
	glRotatef(spin, 0.0, 0.0, 1.0); /* rotate about z axis by spin degrees */
	glScalef(scale, scale, 0.0);/* shrink or grow by scale in x,y */
	HexTriangles(); /* now draw the pixels? */
	glPopMatrix(); /* take off of stack*/
	glutSwapBuffers(); /* swap drawn w/ shown */
} 
/************************************************************************\
|	BounceDisplay || The Idle Function... and bouncing function.
\****************/
void BounceDisplay(void) {
	/*Meat*of*the*Program:*************************\
	| Deflect off of the walls by the amount you|
	| exceeded each wall, don't worry about angles |
	| they will take care of themselves... just|
	| the individual x or y intercepts need to be |
	| calculated... the new position will |
	| intrinsically be the vector sum of the dx,dy |
	| vectors. |
	\**********************************************/
	
	int Radius = 54;
	if(HEXsize < 100){
		scale += scaleOffset; /* grow/shrink by offset */
		HEXsize++;
	}
	else {
		HEXsize = 0;/* Reset loop*/
		scaleOffset *= -1; /* Flip grow/shrink */
	}
	Radius *= scale;
	/* Remember Radius must be in scale too. */
	if(DIRspin < 0){
		spin = spin - 2.0; /* ClockWise*/
	}
	else{
		spin = spin + 2.0; /* CounterClockWise */
	}
	if(spin > 360.0){
		spin = spin - 360.0; /* Keep small */
	}
	if(spin < -360.0){
		spin = spin + 360.0;
	}
	tx += dx; /* Move center over */
	ty += dy; /* by dx,dy (applied by translation) */
	if((tx + Radius) > 600){
		DIRspin *= -1;				/* reverse spin! */
		dx*= -1;/* reverse dx!*/
		tx -= (tx + Radius) - 600; /*Boing! 
		center moved - "spare change" 
		left over from dx */
	}
	if((tx - Radius) < 0 ){
		DIRspin *= -1;
		dx*= -1;
		tx += -1 * (tx - Radius); /* Boing!
		The object is deflected by the amount it exceeded
		the lower bound... don't need no stinking angles.
		AND no popping about! it's smooth baby... ie:
		the object appears to move at constant speed.
		*/
	}
	if((ty + Radius) > 400){
		DIRspin *= -1;
		dy *= -1;
		ty -= (ty + Radius) - 400; /*Boing! same as dx */
	}
	if ((ty - Radius) < 0 ){
		DIRspin *= -1;
		dy *= -1;
		ty += -1 * (ty - Radius); /*Boing! same as dx */
	}
	glutPostRedisplay();/* Make Sure you redraw everything */
}
/************************************************************************\
|	init() || GL initialization... called at start up...
\**********/
void init (void) {
glClearColor (0.0, 0.0, 0.0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0, 600, 0, 400, -1.0, 1.0);
	 glMatrixMode(GL_MODELVIEW);
}
/************************************************************************\
|	mouse() || GLUT event loop handler nifty huh?
\**********/
void mouse(int button, int state, int Mx, int My) {
	/************************************************\
	|	Why is it that I have to flip the Y but not the|
	|	X co-ordinate? Puzzles me so... The Y axis in |
	|	WIN32 must be opposite the GLUT axis... AHHH! |
	|	very yucky... Easily compensated for tho' if|
	|	you know yer window scale. |
	\************************************************/
	switch(button){
		case GLUT_LEFT_BUTTON:
			if (state == GLUT_DOWN){
				tx = Mx;/* NOT Weird*/
				ty = 400 - My; /* IS Weird*/
				/* Note: bad in fullscreen mode*/
				break;
			}
		case GLUT_RIGHT_BUTTON:
			if(state == GLUT_DOWN){
				DIRspin *= -1; /* change
				direction of spin */
				break;
			}
		default:
			break;
	} /* switch */
}
/************************************************************************\
|	main ||
\**********/
int main(int argc, char** argv) {
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (600, 400); 
glutInitWindowPosition (100, 100);
glutCreateWindow ("GLBounce! (point, click right,left)");
init();
glutDisplayFunc(display);
	 glutIdleFunc(BounceDisplay);
	 glutMouseFunc(mouse);
glutMainLoop();
return 0;/* ANSI C requires main to return int. */
}
