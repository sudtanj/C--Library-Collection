#pragma once
#define _USE_MATH_DEFINES 
#include <math.h>
#include <GL/glut.h> 

class Pieces {
	private:
		float x;
		float y;
		void DrawCircle(float cx, float cy, float r, int num_segments, float depth);
	public:
		Pieces(float x,float y);
		void DrawObject();
};