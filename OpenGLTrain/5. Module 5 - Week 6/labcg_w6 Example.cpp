#include <iostream>
#include <stdlib.h> //Needed for "exit" function
#include <math.h>

//Lab Week 6
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
using namespace std;
//Posisi kotak untuk penggambaran awal
GLfloat x[4] = {2.0, 2.0 ,3.0, 3.0}; //Titik benda
GLfloat y[4] = {0.0, 1.0, 1.0, 0.0};

//Titik setiap kotak x,y,z (z constant karena 2D), akan digunakan untuk perkalian matrix
GLfloat xy1[3][1] = {2.0, 0.0, 1.0};
GLfloat xy2[3][1] = {2.0, 1.0, 1.0};
GLfloat xy3[3][1] = {3.0, 1.0, 1.0};
GLfloat xy4[3][1] = {3.0, 0.0, 1.0};

//Untuk menyimpan hasil sehingga bisa digambar
GLfloat xyResult1[3][1];
GLfloat xyResult2[3][1];
GLfloat xyResult3[3][1];
GLfloat xyResult4[3][1];

//Matrix transformation
GLfloat Txz [3][3] = {{1,0,0}, {0,1,-5}, {0,0,1}}; //Pindahkan objek ke titik 0,0
GLfloat Rfz [3][3] = {{0,-1,0}, {-1,0,0}, {0,0,1}}; //Reflection terhadap 0,0
GLfloat Txz1 [3][3] = {{1,0,0}, {0,1,5}, {0,0,1}}; //Kembalikan objek hasil refleksi ke posisi awal

//Menyimpan hasil perkalian matrix
GLfloat TxzRfz [3][3]; //Txz dikali Rfz
GLfloat result [3][3]; //Hasil perkalian yang kemudian akan dikalikan dengan setiap titik kotak

//Garis y=-x+5, garis reflection
GLfloat xLine [2] = {5,0}; //
GLfloat yLine [2] = {0,5};

float sum=0; //menyimpan penjumlahan sementara
void handleKeypress(unsigned char key,int x, int y)
{    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			exit(0); //Exit the program
	}
}
void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(double)w / (double)h,1.0,200.0);
}

//Function perkalian matrix
void MatrixMulti()
{

	for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 3; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{
		    //second then first
		    //yang berarti matrix ke-2 * matrix ke-1 (hanya untuk indexing array saja)
          sum = sum + Rfz[c][k]*Txz[k][d];
        }
        TxzRfz[c][d] = sum; //memasukkan hasil perkalian ke array

      }
    }

    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 3; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{
          sum = sum + Txz1[c][k]*TxzRfz[k][d]; //second then first
        }
        result[c][d] = sum; //memasukkan hasil perkalian ke array hasil
      }
    }
    //Setelah mendapatkan hasilnya, kita kalikan semua titik awal kotak dengan matrix
    //untuk mendapatkan posisi terbaru setelah reflection
    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 1; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{

          sum = sum + result[c][k]*xy1[k][d]; //second then first
        }
        xyResult1[c][d] = sum;
      }
    }

    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 1; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{
          sum = sum + result[c][k]*xy2[k][d]; //second then first
        }
        xyResult2[c][d] = sum;
      }
    }

    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 1; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{
          sum = sum + result[c][k]*xy3[k][d]; //second then first
        }
        xyResult3[c][d] = sum;
      }
    }

    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 1; d++)
	  {
	  	sum = 0;
        for (int k = 0; k < 3; k++)
		{
          sum = sum + result[c][k]*xy4[k][d]; //second then first
        }
        xyResult4[c][d] = sum;
      }
    }

//Untuk debugging hasil apakah sesuai dengan perhitungan manual
    for (int c = 0; c < 3; c++)
	{
      for (int d = 0; d < 1; d++)
       cout<<xyResult1[c][d]<<" ";

      cout<<endl;
    }

}
//mengambar garis carthesian
void drawLineCarthesian()
{
	glBegin(GL_LINES);
	glVertex3f(-15.0f,0.0f,-15.0f); //x-axis
	glVertex3f(15.0f,0.0f,-15.0f);
	glVertex3f(0.0f,15.0f,-15.0f); //y-axis
	glVertex3f(0.0f,-15.0f,-15.0f);

	glEnd();
}
//menggambar kotak awal
void drawInitSquare()
{
	glBegin(GL_QUADS);
	for(int i=0;i<4;i++)
	{
		glVertex3f(x[i],y[i],-15.0f);
	}
	glEnd();
}
//menggambar kotak hasil
void drawResultSquare()
{
	glBegin(GL_QUADS);
	glVertex3f(xyResult1[0][0],xyResult1[1][0],-15.0f);
	glVertex3f(xyResult2[0][0],xyResult2[1][0],-15.0f);
	glVertex3f(xyResult3[0][0],xyResult3[1][0],-15.0f);
	glVertex3f(xyResult4[0][0],xyResult4[1][0],-15.0f);

	glEnd();
}

//menggambar garis reflection
void drawLine()
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	for(int i=0;i<2;i++)
	{
		glVertex3f(xLine[i],yLine[i],-15.0f);
	}
	glEnd();
}

//Menggambar Scene
void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glColor3f(1.0f, 0.0f, 0.0f);

    //memanggil function
	drawLineCarthesian();
	drawInitSquare();
	drawInitSquare();
	drawLine();
	MatrixMulti();
	drawResultSquare();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Lab CGK Week 6");
	initRendering();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutMainLoop();
	return 0;
}









