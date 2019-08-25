#include "board.h"
#include <iostream>
Board::Board() {

}

void Board::drawBoard() {
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -2.0f, -2.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 2.0f, -2.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 2.0f, 2.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -2.0f, 2.0f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.5f, -1.0f, 2.0f);
	glVertex3f(0.5f, 1.0f, 2.0f);
	glVertex3f(0.5f, 1.0f, 2.0f);
	glVertex3f(0.5f, -1.0f, 2.0f);
	glEnd();
	glColor3f(1.0f, 1.0f, 1.0f);
	glLineWidth(2.0f);
	glBegin(GL_LINES);
	for (float i = -2.0f;i < 2.0f;i+=0.3) {
		glVertex3f(1.0f, i, -2.0f);
		glVertex3f(1.0f, i, 2.0f);
	}
	glEnd();
	glRotatef(90, 1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	for (float i = -2.0f;i < 2.0f;i += 0.3) {
		glVertex3f(1.0f, i, -2.0f);
		glVertex3f(1.0f, i, 2.0f);
	}
	glEnd();
}