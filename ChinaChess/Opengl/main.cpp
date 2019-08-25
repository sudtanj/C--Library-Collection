#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<iostream>
#include <GLAux.h>	
#define _USE_MATH_DEFINES 
#include <math.h>
#include <sapi.h>
#include <map>

/* Global variables */
char title[] = "XiangQi";   
int refreshMills = 15,rotate = 0, coorx = 0, coory = 4, fontindex = 0, lastfps = 0, frames = 0,camerax = 0, cameray = 5, temp = 1;
GLuint texture[1];
ISpVoice * pVoice;
unsigned char* image;
bool open = false;
float chipSize = 0.17;
AUX_RGBImageRec *TextureImage[1];
FILE *File;
HRESULT hr;
struct chessPosition {
	float x;
	float y;
};
std::map<float, chessPosition> position;

/* Initialize OpenGL Graphics */
void speak(wchar_t const * text);
void generateBoard();
void OnMouseClick(int button, int state, int x, int y);
void DrawCircle(float cx, float cy, float r, int num_segments, float depth);
void drawChip(int total,float chesspositionx, float chesspositiony);
bool LoadGLTextures(char* data);
AUX_RGBImageRec *LoadBMP(char *Filename);
void speak(wchar_t const * text) {
	if (FAILED(::CoInitialize(NULL)))
		std::cout << "Failed to Initialize voice" << std::endl;
	hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&pVoice);
	if (SUCCEEDED(hr)){
		pVoice->Speak(text, 0, NULL);
		pVoice->Release();
	}
	::CoUninitialize();
}

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClearDepth(1.0f);                   // Set background depth to farthest
	glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
	glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
	glShadeModel(GL_SMOOTH);   // Enable smooth shading
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
	glGenTextures(1, &texture[0]);					
	glBindTexture(GL_TEXTURE_2D, texture[0]);
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
	glLoadIdentity();
	glPushMatrix();
	gluLookAt(camerax, cameray,1, coorx, coory, 0, 0, 1, 0);
	glTranslatef(0.0, 0.0, -5.0);
	glColor3f(0.9, 0.3, 0.2);
	glRotatef(90, 0, 0, 1);
	glScalef(1.0, 1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	LoadGLTextures("wood.bmp");
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	generateBoard();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(0.0, 0.0, 5.0);
	glPopMatrix();
	glPushMatrix();
	gluLookAt(camerax, cameray, 1, coorx, coory, 0, 0, 1, 0);
	glTranslatef(0.0, 0.001, -5.0);
	glColor3f(0.9, 0.3, 0.2);
	glRotatef(90, 0, 0, 1);
	glScalef(1.0, -1.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	LoadGLTextures("Board.bmp");
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -2.0f, -2.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 2.0f, -2.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 2.0f, 2.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -2.0f, 2.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glTranslatef(0.0, 0.0, 5.0);
	glPopMatrix();
	glLoadIdentity();
	glPushMatrix();
	gluLookAt(camerax, cameray, 1, coorx, coory, 0, 0, 1, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1.0, -1.0, 1.0);
	glTranslatef(-4.5, 3.1, -1.2);
	glColor3f(1.0f, 1.0f, 1.0f);
	drawChip(9,5, 0);
	temp = 1;
	for (float k = 0;k <= 0;k += 1)
		for (float j = 0;j <= 5;j += 0.42) {
			for (float i = 0;i < chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				if (temp == 5) 
					LoadGLTextures("piece/redking.bmp");
				else if (temp == 3 || temp == 7)
					LoadGLTextures("piece/redbishop.bmp");
				else if (temp == 1 || temp == 9)
					LoadGLTextures("piece/redcart.bmp");
				else if (temp == 2 || temp == 8) 
					LoadGLTextures("piece/redhorse.bmp");
				else if (temp == 4 || temp == 6) 
					LoadGLTextures("piece/redscholar.bmp");
				DrawCircle(2.8 + j, 0.08 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != 9) temp++; else break;
		}
	temp = 1;
	for (float k = 0;k <= 0;k += 1)
		for (float j = 0;j <= 5;j += 0.85) {
			for (float i = 0;i <chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				LoadGLTextures("piece/redprivate.bmp");
				DrawCircle(2.8 + j, 1.3 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != 5) temp++; else break;
		}
	temp = 1;
	for (float k = 0;k <= 0;k += 1)
		for (float j = 0;j <= 5;j += 0.85) {
			for (float i = 0;i < chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				LoadGLTextures("piece/blackprivate.bmp");
				DrawCircle(2.8 + j, 2.5 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != 5) temp++; else break;
		}
	temp = 1;
	for (float k = 0;k <= 0;k += 1)
		for (float j = 0;j <= 5;j += 2.53) {
			for (float i = 0;i < chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				LoadGLTextures("piece/blackcannon.bmp");
				DrawCircle(3.2 + j, 2.85 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != 2) temp++; else break;
		}
	temp = 1;
	for (float k = 0;k <= 0;k += 1)
		for (float j = 0;j <= 5;j += 2.53) {
			for (float i = 0;i < chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				LoadGLTextures("piece/redcannon.bmp");
				DrawCircle(3.2 + j, 0.95 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != 2) temp++; else	break;
		}
	glPopMatrix();
	glLoadIdentity();
	glFlush();
	glutSwapBuffers();
	if (open == false) {
		speak(L"これはキャラクターボイスのテストです。");
		speak(L"こんにちは、春香と申します。今日私はあなたのゲームガイドです。宜しくお願い致します。");
		speak(L"まずは歴史授業です。キーボードをタッチしないでください");
		speak(L"ウィキペディアでは,シャンチー（象棋、拼音：xiàngqí、ベトナム語ではcờ tướng/棋將）は、中国およびベトナムで盛んな将棋類であり、二人で行うボードゲーム（盤上遊戯）の一種である。中国では国家の正式のスポーツ種目になっている。");
		open = true;
	}
}

void drawChip(int total,float chesspositionx,float chesspositiony) {
	int temp = 1;
	for(float k=0;k<=chesspositiony;k+=1)
		for (float j = 0;j <= chesspositionx;j += 0.42) {
			for (float i = 0;i < chipSize;i += 0.01) {
				glEnable(GL_TEXTURE_2D);
				if (temp == 5) 
					LoadGLTextures("piece/blackking.bmp");
				else if (temp == 3 || temp == 7)
					LoadGLTextures("piece/blackbishop.bmp");
				else if (temp == 1 || temp == 9) 
					LoadGLTextures("piece/blackcart.bmp");
				else if (temp == 2 || temp == 8) 
					LoadGLTextures("piece/blackhorse.bmp");
				else if (temp == 4 || temp == 6) 
					LoadGLTextures("piece/blackscholar.bmp");
				DrawCircle(2.8 + j, 3.58 + k, i, 50, 0.1);
				glDisable(GL_TEXTURE_2D);
			}
			if (temp != total) temp++; else break;
		}
}

void DrawCircle(float cx, float cy, float r, int num_segments,float depth)
{
	float theta, x, y;
	if (position.find(cx+cy) == position.end()) {
		position[cx + cy].x = 0;
		position[cx + cy].y = 0;
	}
	else {
		glTranslatef(position[cx + cy].x, position[cx + cy].y, 0);
	}
	glBegin(GL_TRIANGLE_FAN);
	for (float j=0;j<depth;j+=0.001)
		for (int ii = 0; ii < num_segments; ii++)
		{
			theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
			x = r * cosf(theta);//calculate the x component
			y = r * sinf(theta);//calculate the y component
			if(j==0) glTexCoord2f((x / r + 1)*0.5, (y / r + 1)*0.5);
			glVertex3f(x + cx, y + cy,j);//output 
		}
	glEnd();
	if (position.find(cx + cy) != position.end()) {
		glTranslatef(-1*position[cx + cy].x, -1*position[cx + cy].y, 0);
	}
}
void generateBoard() {
	glBegin(GL_QUADS);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	// Back Face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5f, -1.0f, -1.0f);
	// Top Face
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
	// Bottom Face
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	// Right face
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -2.0f, -2.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 2.0f, -2.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 2.0f, 2.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -2.0f, 2.0f);
	// Left Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
	glEnd();
}

void timer(int value) {
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(refreshMills, timer, 0); // next timer call milliseconds later
}

void reshape(GLsizei width, GLsizei height) {  
	if (height == 0) height = 1;                // To prevent divide by 0
	glViewport(0, 0, width, height);
	// Set the aspect ratio of the clipping volume to match the viewport
	glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
	glLoadIdentity();             // Reset 
	gluPerspective(45.0f, (GLfloat)((GLfloat)width / (GLfloat)height), 0.1f, 3000.0f); //Enable perspective projection with fovy, aspect, zNear and zFar
}


void handleKeypress(unsigned char key, int, int) {
	if (key == 'm') {
		int x,temp=0;
		std::cout << "please select which one?" << std::endl;
		std::cin >> x;
		std::map<float,chessPosition>::iterator it;
		for (it = position.begin();it != position.end();it++)
		{
			if (temp == x) {
				it->second.x++;
				std::cout << it->second.y << std::endl;
				break;
			}
				temp++;
		}
		std::cin.ignore();
		std::cin.get();
	}
	if (key == 'w') {
		coory++;
	}
	else if (key == 'a') {
		coorx--;
	}
	else if (key == 'i') {
		cameray++;
	}
	else if (key == 'k') {
		cameray--;
	}
	else if (key == 'j') {
		camerax--;
	}
	else if (key == 'l') {
		camerax++;
	}
	switch (key) {
	case 'd':
		coorx++;
		coory++;
	case 's':
		coory--;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);           
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(840, 680);   
	glutInitWindowPosition(50, 50); 
	glutCreateWindow(title);          
	glutDisplayFunc(display);       
	glutReshapeFunc(reshape);       
	glutKeyboardFunc(handleKeypress);
	glutMouseFunc(OnMouseClick);
	initGL();   
	glutTimerFunc(0, timer, 0);     
	glutMainLoop();                 
	return EXIT_SUCCESS;
}

void OnMouseClick(int button, int state, int x, int y){
	if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)	{
		//store the x,y value where the click happened
		GLint viewport[4]; //var to hold the viewport info
		GLdouble modelview[16]; //var to hold the modelview info
		GLdouble projection[16]; //var to hold the projection matrix info
		GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
		GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //get the modelview info
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //get the projection matrix info
		glGetIntegerv(GL_VIEWPORT, viewport); //get the viewport info

		winX = (float)x;
		winY = (float)viewport[3] - (float)y;
		winZ = 0;

		//get the world coordinates from the screen coordinates
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);
		std::cout << worldX << " " << worldY <<" " << worldZ <<std::endl;
	}
}


AUX_RGBImageRec *LoadBMP(char *Filename){
	File = NULL;									
	if (!Filename)
		return NULL;									
	File = fopen(Filename, "r");			
	if (File){
		fclose(File);								
		return auxDIBImageLoad(Filename);				
	}
	return NULL;										
}

bool LoadGLTextures(char* data){								
	memset(TextureImage, 0, sizeof(void *) * 1);           	
	if (TextureImage[0] = LoadBMP(data)){									
		glTexImage2D(GL_TEXTURE_2D, 0, 3, TextureImage[0]->sizeX, TextureImage[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}
	if (TextureImage[0]){
		if (TextureImage[0]->data)							
			free(TextureImage[0]->data);					
		free(TextureImage[0]);	
		return TRUE;
	}
	return FALSE;										
}

