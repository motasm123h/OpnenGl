#include "skybox.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <texture.h>

void skybox::rip_of_the_skybox()
{
	
	//glBindTexture(GL_TEXTURE_2D, front);
	glColor3d(0,1,1);
	glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	glVertex3d(-100000, -4000, -4000);
	//glTexCoord2d(1, 0);
	glVertex3d(100000, -4000, -4000);
	//glTexCoord2d(1, 1);
	glVertex3d(100000, 4000, -4000);
	//glTexCoord2d(0, 1);
	glVertex3d(-100000, 4000, -4000);
	glEnd();

	glColor3d(0,0,1);
	//glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	glVertex3d(-100000, -4000, 4000);
	//glTexCoord2d(1, 0);
	glVertex3d(100000, -4000, 4000);
	//glTexCoord2d(1, 1);
	glVertex3d(100000, 4000, 4000);
	//glTexCoord2d(0, 1);
	glVertex3d(-100000, 4000, 4000);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, left);
	glColor3d(0.3,1,0.5);
	glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	glVertex3d(-100000, -4000, 4000);
	//glTexCoord2d(1, 0);
	glVertex3d(-100000, -4000, -4000);
	//glTexCoord2d(1, 1);
	glVertex3d(-100000, 4000, -4000);
	//glTexCoord2d(0, 1);
	glVertex3d(-100000, 4000, 4000);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, right);
	glColor3d(0,0.6,0);
	glBegin(GL_QUADS);
	//glTexCoord2d(1, 0);
	glVertex3d(100000, -4000, 4000);
	//glTexCoord2d(0, 0);
	glVertex3d(100000, -4000, -4000);
	//glTexCoord2d(0, 1);
	glVertex3d(100000, 4000, -4000);
	//glTexCoord2d(1, 1);
	glVertex3d(100000, 4000, 4000);
	glEnd();

	//glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	glVertex3d(-100000, 4000, -4000);
	//glTexCoord2d(1, 0);
	glVertex3d(100000, 4000, -4000);
	//glTexCoord2d(1, 1);
	glVertex3d(100000, 4000, 4000);
	//glTexCoord2d(0, 1);
	glVertex3d(-100000, 4000, 4000);
	glEnd();
}