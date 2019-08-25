#include "pieces.h"

Pieces::Pieces(float x,float y) {
	this->x = x;
	this->y = y;
}

void Pieces::DrawObject() {
	for (float i = 0;i<0.1;i += 0.01)
		DrawCircle(this->x, this->y, i, 50, 0.1);
}

void Pieces::DrawCircle(float cx, float cy, float r, int num_segments, float depth)
{
	glBegin(GL_LINE_LOOP);
	float theta, x, y;
	for (float j = 0;j<depth;j += 0.001)
		for (int ii = 0; ii < num_segments; ii++)
		{
			theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
			x = r * cosf(theta);//calculate the x component
			y = r * sinf(theta);//calculate the y component
			glVertex3f(x + cx, y + cy, j);//output vertex
		}
	glEnd();
}