#pragma once
#include <GL/glut.h>
#include <SOIL.h>

class Board {
	private:
		int x;
		int y;
	public:
		GLuint tex;
		Board();
		void drawBoard();
};