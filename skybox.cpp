#include "skybox.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <math.h>
#include <texture.h>




void skybox::Draw_train(int image,int door,int zdoor2 ,int xdoor1,int x,int y,int z)
{

	//**the first side of the train left
	//the new vesion
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //front
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, 0.0f);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, 0.0f);
	
	glEnd();
	
	//the new vrsion the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 2.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 2.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, 2.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, 2.0f);
	glEnd();
	glPopMatrix();


	//***the second side of the train left
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //back
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, z);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, z);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, z);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, z);
	glEnd();

	
	//the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z-2);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z-2);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, z-2);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, z-2);
	glEnd();
	glPopMatrix();
	glEnd();

	//****

	//*****
	//the back of the train
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);
	glEnd();

	//the front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z/3);
	glTexCoord2d(1,1);
	glVertex3f(x, y,z/3);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, z/2+50);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/2+50);

	glTexCoord2d(0,0);
	glVertex3f(x, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/3);

	glEnd();
	glPopMatrix();

	
	
	
	//****

	//the front door new version
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-2, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x-2, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x-2, 0, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x-2, 0, z/3);
	glEnd();
	glPopMatrix();
	

	//****
	//the roof new 
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+600, y+200, 100);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+600, y+200, z-100);
	glEnd();

	//****

	//the ground
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, 0, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, 0, z);
	glEnd();


	//the Left Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 00.0f);
	glEnd();



	//the right Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z);
	glEnd();

	//back Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);
	glEnd();

	//front Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, 1000.0f, z);
	glEnd();

	
}



void skybox::Draw_train_two(int image,int door,int zdoor2 ,int xdoor1,int x,int y,int z)
{

	//**the first side of the train left
	//the new vesion
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //front
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, 0.0f);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, 0.0f);
	
	glEnd();
	
	//the new vrsion the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 2.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 2.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, 2.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, 2.0f);
	glEnd();
	glPopMatrix();


	//***the second side of the train left
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //back
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, z);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, z);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, z);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, z);
	glEnd();

	
	//the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z-2);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z-2);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, z-2);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, z-2);
	glEnd();
	glPopMatrix();
	glEnd();

	//****



	//****
	//new back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, 0.0f, z/3);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y,z/3);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, z/2+50);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z/2+50);

	glTexCoord2d(0,0);
	glVertex3f(-x+500, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z/3);
	glEnd();
	glPopMatrix();


	//the new dooor
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+498, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(-x+498, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(-x+498, 0, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(-x+498, 0, z/3);
	glEnd();
	glPopMatrix();

	//****



	//the front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z/3);
	glTexCoord2d(1,1);
	glVertex3f(x, y,z/3);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, z/2+50);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/2+50);

	glTexCoord2d(0,0);
	glVertex3f(x, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/3);
	glPopMatrix();

	
	//the back door

	
	
	//****

	//the front door new version
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(144448.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(148898.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(145488.0f, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(148898.0f, 0, 200.0f);
	glEnd();
	glPopMatrix();
	


	///*****
	//the front door new version
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-2, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x-2, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x-2, 0, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x-2, 0, z/3);
	glEnd();
	glPopMatrix();


	//****
	//the roof new 
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+600, y+200, 100);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+600, y+200, z-100);
	glEnd();

	//****

	//the ground
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, 0, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, 0, z);
	glEnd();


	//the Left Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 00.0f);
	glEnd();



	//the right Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z);
	glEnd();

	//back Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);
	glEnd();

	//front Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, 1000.0f, z);
	glEnd();


	
}


void skybox::DrawSeat(int chairs,int x,int y,int z)
{
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(-x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, -z);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x,-y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, -y,z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, -y, z);
	glEnd();
}
/*

void skybox::DrawChairsBracket()
{

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -100, 20);
	glTexCoord2d(1, 0);
	glVertex3d(-900, -100, -20);
	glTexCoord2d(1, 1);
	glVertex3d(-900, 100, -20);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 100, 20);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -100, -20);
	glTexCoord2d(1, 0);
	glVertex3d(900, -100, -20);
	glTexCoord2d(1, 1);
	glVertex3d(900, 100, -20);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 100, -20);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -100, 20);
	glTexCoord2d(1, 0);
	glVertex3d(900, -100, 20);
	glTexCoord2d(1, 1);
	glVertex3d(900, 100, 20);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 100, 20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(900, -100, 20);
	glTexCoord2d(0, 0);
	glVertex3d(900, -100, -20);
	glTexCoord2d(0, 1);
	glVertex3d(900, 100, -20);
	glTexCoord2d(1, 1);
	glVertex3d(900, 100, 20);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, 100, -20);
	glTexCoord2d(1, 0);
	glVertex3d(900, 100, -20);
	glTexCoord2d(1, 1);
	glVertex3d(900, 100, 20);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 100, 20);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900,-100, -20);
	glTexCoord2d(1, 0);
	glVertex3d(900, -100, -20);
	glTexCoord2d(1, 1);
	glVertex3d(900, -100, 20);
	glTexCoord2d(0, 1);
	glVertex3d(-900 , -100, 20);
	glEnd();
}

void skybox::DrawChairs()
{
//first chairs
	glPushMatrix();
	glTranslated(-90,50,75);
	skybox::DrawSeat();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-94,105,30);
	skybox::DrawChairsBracket();
	glPopMatrix();
	


	//second chairs
	glPushMatrix();
	glTranslated(-90,50,625);
	skybox::DrawSeat();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-94,105,670);
	skybox::DrawChairsBracket();
	glPopMatrix();


	//third
	glPushMatrix();
	glTranslated(1390,50,625);
	skybox::DrawSmallSeat();
	glPopMatrix();

	//four
	glPushMatrix();
	glTranslated(1390,50,75);
	skybox::DrawSmallSeat();
	glPopMatrix();
}

void skybox::train()
{
	//draw the train
	skybox::Draw_train_two();
	skybox::DrawChairs();
	
}

void skybox::TV()
{
	glPushMatrix();
	glTranslated(0,400,680);
	glRotated(360,0,1,0);
	glBindTexture(GL_TEXTURE_2D,pes);
	glBegin(GL_QUADS);
	glTexCoord2d(1,1);
	glVertex3f(-200.0f, 0.0f, 10.0f);
	
	glTexCoord2d(0,1);
	glVertex3f(200.0f, 0.0f, 10.0f);
	
	glTexCoord2d(0,0);
	glVertex3f(200.0f, 200.0f, 10.0f);
	
	glTexCoord2d(1,0);
	glVertex3f(-200.0f, 200.0f, 10.0f);
	glEnd();
	glPopMatrix();

}
*/


void skybox::skyboxfirst(int x ,int y, int z ,int front ,int back ,int right ,int left ,int top ,int bottm)
{
	
	
	//glBindTexture(GL_TEXTURE_2D, front);
	//glBegin(GL_QUADS);
	//glTexCoord2d(1, 0);
	//glVertex3d(x, -y, z);
	//glTexCoord2d(0, 0);
	//glVertex3d(x, -y, -z);
	//glTexCoord2d(0, 1);
	//glVertex3d(x, y, -z);
	//glTexCoord2d(1, 1);
	//glVertex3d(x, y, z);
	//glEnd();

	
	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(-x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, -z);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(-x, y, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, bottm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x,-y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, -y, z);
	glEnd();


}

void skybox::skyboxsecond(int x ,int y, int z ,int front ,int back ,int right ,int left ,int top ,int bottm)
{
	//glBindTexture(GL_TEXTURE_2D, back);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(-x, -y, z);
	//glTexCoord2d(1, 0);
	//glVertex3d(-x, -y, -z);
	//glTexCoord2d(1, 1);
	//glVertex3d(-x, y, -z);
	//glTexCoord2d(0, 1);
	//glVertex3d(-x, y, z);
	//glEnd();


	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, -z);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(-x, y, z);
	glEnd();

	/*glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glEnd();*/

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, bottm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x,-y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, -y, z);
	glEnd();


}

void skybox::skyboxthird(int x ,int y, int z ,int front ,int back ,int right ,int left ,int top ,int bottm)
{
	//glBindTexture(GL_TEXTURE_2D, back);
	//glBegin(GL_QUADS);
	//glTexCoord2d(0, 0);
	//glVertex3d(-x, -y, z);
	//glTexCoord2d(1, 0);
	//glVertex3d(-x, -y, -z);
	//glTexCoord2d(1, 1);
	//glVertex3d(-x, y, -z);
	//glTexCoord2d(0, 1);
	//glVertex3d(-x, y, z);
	//glEnd();


	glBindTexture(GL_TEXTURE_2D, left);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, -y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, -z);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(-x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(1, 1);
	glVertex3d(-x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(0, 1);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x, y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, y, z);
	glEnd();


	glBindTexture(GL_TEXTURE_2D, bottm);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-x,-y, -z);
	glTexCoord2d(1, 0);
	glVertex3d(x, -y, -z);
	glTexCoord2d(1, 1);
	glVertex3d(x, -y, z);
	glTexCoord2d(0, 1);
	glVertex3d(-x, -y, z);
	glEnd();


}


void skybox::drawBox4(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6){
	
	glPushMatrix();

		//right side
		glBindTexture(GL_TEXTURE_2D,image1);
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y-300,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,z);
		glEnd();



		//left side
		glBindTexture(GL_TEXTURE_2D,image2);
		glBegin(GL_QUADS);	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y-2,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y-300,-z);
		glEnd();
		
		//back
		glBindTexture(GL_TEXTURE_2D,image3);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y-2,-z);
		glEnd();

	

		//front
		glBindTexture(GL_TEXTURE_2D,image4);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y-300,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y-300,z);
		glEnd();
		
		//top
		glBindTexture(GL_TEXTURE_2D,image5);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y-300,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,y-300,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y-2,-z);
		glEnd();

		//bottom
		glBindTexture(GL_TEXTURE_2D,image6);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,-y,-z);
		glEnd();
	
		glPopMatrix();
};
	
void skybox::drawBox2(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6,int door,int glass){
	glPushMatrix();
	
	//front
	glBindTexture(GL_TEXTURE_2D,image1);
	glBegin(GL_QUADS); 
    glColor4f(255,255,255,1);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-x+6,y,z);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-x+6,-y,z);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(x,-y,z);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(x,y,z);
    glEnd();
  

	


	//back
	glBindTexture(GL_TEXTURE_2D,image1);
	glBegin(GL_QUADS);
    glColor4f(255,255,255,1);
    glTexCoord2f(0.0f,1.0f);
    glVertex3f(-x+6,y,-z);
    glTexCoord2f(0.0f,0.0f);
    glVertex3f(-x+6,-y,-z);
    glTexCoord2f(1.0f,0.0f);
    glVertex3f(x,-y,-z);
    glTexCoord2f(1.0f,1.0f);
    glVertex3f(x,y,-z);
    glEnd();
  


		
	
	//rightdown
	glBindTexture(GL_TEXTURE_2D,image3);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(x,0,z);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x,-y,z);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x,-y,-z);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(x,0,-z);
	glEnd();
	
	//right up
	glBindTexture(GL_TEXTURE_2D,glass);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(x,y,z);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(x,0,z);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x,0,-z);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(x,y,-z);
	glEnd();


	//*******
	glPushMatrix();
	glTranslated(0,-500,-350);
	glBindTexture(GL_TEXTURE_2D,image1);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x, 0.0f, 200.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x, 1000.0f, 200.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x, 1000.0f, 0.0f);


	glTexCoord2d(0,0);
	glVertex3f(-x, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x, 1000.0f, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x, 1000.0f, 200.0f);


	glTexCoord2d(0,0);
	glVertex3f(-x, 0.0f, 400.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x, 1000.0f, 400.0f);

	glEnd();

	//the back door
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	//glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+4, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+4, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+4, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+4, 0, 200.0f);
	glEnd();
	glPopMatrix();

	glPopMatrix();

	//*******
		
	//top
	glBindTexture(GL_TEXTURE_2D,image5);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-x,y,-z);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-x,y,z);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x,y,z);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(x,y,-z);
	glEnd();
		
	
	//bottom
	glBindTexture(GL_TEXTURE_2D,image6);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f,1.0f);
	glVertex3f(-x,-y,-z);
	glTexCoord2f(0.0f,0.0f);
	glVertex3f(-x,-y,z);
	glTexCoord2f(1.0f,0.0f);
	glVertex3f(x,-y,z);
	glTexCoord2f(1.0f,1.0f);
	glVertex3f(x,-y,-z);
	glEnd(); 
	



	glPopMatrix();
 

};

void skybox::drawBox3(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6){
		glPushMatrix();

		//front
		glBindTexture(GL_TEXTURE_2D,image3);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();

		//back
		glBindTexture(GL_TEXTURE_2D,image4);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y,z);
		glEnd();
		
		//top
		glBindTexture(GL_TEXTURE_2D,image5);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();
		
		
		//bottom
		glBindTexture(GL_TEXTURE_2D,image6);
		glBegin(GL_QUADS);
	
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,-y,-z);
		glEnd();

		//left
		glBindTexture(GL_TEXTURE_2D,image1);
		glBegin(GL_QUADS);
		glColor4f(255,255,255,1);
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x+6,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x+6,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();

		//right
		glBindTexture(GL_TEXTURE_2D,image1);
		glBegin(GL_QUADS);
		glColor4f(255,255,255,1);
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x+4,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x+4,y,z);
		glEnd();
		glPopMatrix();
	

};

float angle = 0, angl = 0;
GLUquadric* quadric = gluNewQuadric();
void  skybox::Wheel(Point center, float radius)
{
	int steps = 360;
	float theta = 0;
	glBegin(GL_POINTS);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, center.z);
		theta = theta + .5;
	}
	gluCylinder(quadric, radius - 0.7, radius - 0.7, radius / 12, 14 * radius, 25 * radius);
	glEnd();
	glBegin(GL_LINES);
	float x, y; 
		for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.9f)
		{
			x = (radius - radius / 6) * cos(angle);
			y = (radius - radius / 6) * sin(angle);
			glColor3f(1.0f, 1.0f, 0);
			glVertex3f(x, y, 0.0f);
			glVertex3f(center.x, center.y, center.z);
		}
	glEnd();
}

void skybox::wheels(float distance, float width, Point center, float radius)
	{
	glTranslated(0, 0, -5);
	//Draw well first
	glPushMatrix();
	glTranslated(4 * radius + distance, 0, 0);
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.3;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5, 75 * radius, 100 * radius);
	glPopMatrix();

	//Draw well second
	glPushMatrix();
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.3;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5, 75 * radius, 100 * radius);
	glPopMatrix();

	//Draw well third
	glPushMatrix();
	glTranslated(8.5 * radius + distance, 0, 0);
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.3;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5, 75 * radius, 100 * radius);
	glPopMatrix();


	glPushMatrix();
	glTranslated(0, 0, -width);
	//Draw well first
	glPushMatrix();
	glTranslated(4 * radius + distance, 0, 0);
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.3;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5, 75 * radius, 100 * radius);
	glPopMatrix();

	//Draw well second
	glPushMatrix();
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.3;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5,  75* radius, 100 * radius);
	glPopMatrix();

	//Draw well third
	glPushMatrix();
	glTranslated(8.5* radius + distance, 0, 0);
	glRotated(angl, 0, 0, 1);
	angl = angl + 0.5;
	skybox::Wheel(Point(0, 0, 0), radius);
	gluCylinder(quadric, radius, radius, radius / 5, 75 * radius, 100 * radius);
	glPopMatrix();
	glPopMatrix();
}

void skybox::test(float width, float hight, float depth ,int wall)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wall);
	glBegin(GL_QUADS);

	for (float i = -depth; i < depth; i = i + 4)
	{

		// front face
		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(-width / 1.5, hight / 3.5, hight / 2 - i);
		// back face
		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(-width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		// top face

		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(-width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		// bottom face

		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(-width / 1.5, -hight / 3.5, hight / 2 - i);

		// right face
		glTexCoord2f(0, 0);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);

		// left face
		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(-width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(-width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(-width / 1.5, -hight / 3.5, hight / 2 - i);
	}
	glDisable(GL_TEXTURE_2D);
	glEnd();

	//test1(width, hight, depth);
}

void skybox::test1(float width, float hight, float depth,int iron,int wall)
{
	skybox::test(width, hight, depth, wall);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, iron);
	glBegin(GL_QUADS);
	///start
	           
	// left face
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2, -hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2, hight + 0.5, -depth);

	//top left face 
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2.4, hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2, hight + 0.5, -depth);

	//right left face 
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2.4, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2.4, -hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2.4, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2.4, hight + 0.5, -depth);

	///end

	///start
	// right face
	glTexCoord2f(0, 0);
	glVertex3f(width / 2, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2, -hight + 0.5, depth);

	//top right face 
	glTexCoord2f(0, 0);
	glVertex3f(width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2.4, hight + 0.5, depth);

	//left right face
	glTexCoord2f(0, 0);
	glVertex3f(width / 2.4, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2.4, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2.4, -hight + 0.5, depth);
	///end
	glEnd();
}


void skybox::Draw_third_trian(int x,int y,int z,int image,int wood ,int chairs,int door,int zdoor2 ,int xdoor1)
{

	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //front
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, 0.0f);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, y, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, 0.0f);
	
	glEnd();
	
	//the new vrsion the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, 2.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, 2.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, 2.0f);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, 2.0f);
	glEnd();
	glPopMatrix();


	//***the second side of the train left
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //back
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);

	glTexCoord2d(0,0);
	glVertex3f(x-500, y/2, z);
	glTexCoord2d(0,1);
	glVertex3f(x-240, y/2, z);
	glTexCoord2d(1,1);
	glVertex3f(x-240, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-500, y, z);

	
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y, z);
	glEnd();

	
	//the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-240, 0.0f, z-2);
	glTexCoord2d(0,1);
	glVertex3f(x-500, 0.0f, z-2);
	glTexCoord2d(1,1);
	glVertex3f(x-500, y/2, z-2);
	glTexCoord2d(1,0);
	glVertex3f(x-240, y/2, z-2);
	glEnd();
	glPopMatrix();
	glEnd();

	//****



	//****
	//new back
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, 0.0f, z/3);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y,z/3);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, z/2+50);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z/2+50);

	glTexCoord2d(0,0);
	glVertex3f(-x+500, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z/3);
	glEnd();
	glPopMatrix();


	//the new dooor
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+498, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(-x+498, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(-x+498, 0, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(-x+498, 0, z/3);
	glEnd();
	glPopMatrix();
	//****



	//the front
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z/3);
	glTexCoord2d(1,1);
	glVertex3f(x, y,z/3);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(x, 0.0f, z/2+50);
	glTexCoord2d(0,1);
	glVertex3f(x, 0.0f, z);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/2+50);

	glTexCoord2d(0,0);
	glVertex3f(x, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x, y, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z/3);
	glEnd();
	glPopMatrix();

	
	//the back door

	
	
	//****

	//the front door new version	


	///*****
	//the front door new version
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x-2, y/2-100, z/3);
	glTexCoord2d(0,1);
	glVertex3f(x-2, y/2-100, z/2+50);
	glTexCoord2d(1,1);
	glVertex3f(x-2, 0, z/2+50);
	glTexCoord2d(1,0);
	glVertex3f(x-2, 0, z/3);
	glEnd();
	glPopMatrix();


	//****
	//the roof new 
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+600, y+200, 100);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+600, y+200, z-100);
	glEnd();

	//****

	//the ground
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(x, 0, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(x, 0, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, 0, z);
	glEnd();


	//the Left Pillar for roof
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,0);
	glVertex3f(x, y, 00.0f);
	glEnd();



	//the right Pillar for roof
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, y, z);
	glEnd();

	//back Pillar for roof
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+600, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+600, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y, z);
	glEnd();

	//front Pillar for roof
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(x-100, y+200, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(x-100, y+200, z-100);
	glTexCoord2d(1,0);
	glVertex3f(x, 1000.0f, z);
	glEnd();



    //........................
	//......the seats and columns......
	//.........the seats......

	
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 0.0f);
	glVertex3f(-200.0f, 150.0f, 0.0f);
	glVertex3f(-200.0f, 130.0f, 0.0f);
	glVertex3f(-800.0f, 130.0f, 0.0f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-800.0f, 150.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-200.0f, 150.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-200.0f, 150.0f, 180.0f);
	glTexCoord2d(1,0);
	glVertex3f(-800.0f, 150.0f, 180.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 180.0f);
	glVertex3f(-200.0f, 150.0f, 180.0f);
	glVertex3f(-200.0f, 130.0f, 180.0f);
	glVertex3f(-800.0f, 130.0f, 180.0f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-800.0f, 130.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-200.0f, 130.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-200.0f, 130.0f, 180.0f);
	glTexCoord2d(1,0);
	glVertex3f(-800.0f, 130.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 0.0f);
	glVertex3f(-800.0f, 150.0f, 180.0f);
	glVertex3f(-800.0f, 130.0f, 180.0f);
	glVertex3f(-800.0f, 130.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-200.0f, 150.0f, 0.0f);
	glVertex3f(-200.0f, 150.0f, 180.0f);
	glVertex3f(-200.0f, 130.0f, 180.0f);
	glVertex3f(-200.0f, 130.0f, 0.0f);
	glEnd();
	
	//
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 2.0f);
	glVertex3f(-200.0f, 150.0f, 2.0f);
	glVertex3f(-200.0f, 350.0f, 2.0f);
	glVertex3f(-800.0f, 350.0f, 2.0f);
	glEnd();
	////////

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-800.0f, 150.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(-200.0f, 150.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(-200.0f, 150.0f, 520.0f);
	glTexCoord2d(1,0);
	glVertex3f(-800.0f, 150.0f, 520.0f);
	glEnd();
	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 520.0f);
	glVertex3f(-200.0f, 150.0f, 520.0f);
	glVertex3f(-200.0f, 130.0f, 520.0f);
	glVertex3f(-800.0f, 130.0f, 520.0f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(-800.0f, 130.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(-200.0f, 130.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(-200.0f, 130.0f, 520.0f);
	glTexCoord2d(1,0);
	glVertex3f(-800.0f, 130.0f, 520.0f);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-800.0f, 150.0f, 520.0f);
	glVertex3f(-800.0f, 150.0f, 700.0f);
	glVertex3f(-800.0f, 130.0f, 700.0f);
	glVertex3f(-800.0f, 130.0f, 520.0f);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-200.0f, 150.0f, 520.0f);
	glVertex3f(-200.0f, 150.0f, 700.0f);
	glVertex3f(-200.0f, 130.0f, 700.0f);
	glVertex3f(-200.0f, 130.0f, 520.0f);
	glEnd();
	
	//
	glBegin(GL_QUADS);
	glColor3f(255,255,255);
	glVertex3f(-800.0f, 150.0f, 699.0f);
	glVertex3f(-200.0f, 150.0f, 699.0f);
	glVertex3f(-200.0f, 350.0f, 699.0f);
	glVertex3f(-800.0f, 350.0f, 699.0f);
	glEnd();
	
	//////////	
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(700.0f, 150.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1300.0f, 150.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1300.0f, 150.0f, 180.0f);
	glTexCoord2d(1,0);
	glVertex3f(700.0f, 150.0f, 180.0f);
	glEnd();
	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 180.0f);
	glVertex3f(1300.0f, 150.0f, 180.0f);
	glVertex3f(1300.0f, 130.0f, 180.0f);
	glVertex3f(700.0f, 130.0f, 180.0f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(700.0f, 130.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1300.0f, 130.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1300.0f, 130.0f, 180.0f);
	glTexCoord2d(1,0);
	glVertex3f(700.0f, 130.0f, 180.0f);
	glEnd();

	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 0.0f);
	glVertex3f(700.0f, 150.0f, 180.0f);
	glVertex3f(700.0f, 130.0f, 180.0f);
	glVertex3f(700.0f, 130.0f, 0.0f);
	glEnd(); 
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1300.0f, 150.0f, 0.0f);
	glVertex3f(1300.0f, 150.0f, 180.0f);
	glVertex3f(1300.0f, 130.0f, 180.0f);
	glVertex3f(1300.0f, 130.0f, 0.0f);
	glEnd();
	
	//
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 2.0f);
	glVertex3f(1300.0f, 150.0f, 2.0f);
	glVertex3f(1300.0f, 350.0f, 2.0f);
	glVertex3f(700.0f, 350.0f, 2.0f);
	glEnd();
	////////
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 700.0f);
	glVertex3f(1300.0f, 150.0f, 700.0f);
	glVertex3f(1300.0f, 130.0f, 700.0f);
	glVertex3f(700.0f, 130.0f, 700.0f);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(700.0f, 150.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(1300.0f, 150.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1300.0f, 150.0f, 520.0f);
	glTexCoord2d(1,0);
	glVertex3f(700.0f, 150.0f, 520.0f);
	glEnd();
	 glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 520.0f);
	glVertex3f(1300.0f, 150.0f, 520.0f);
	glVertex3f(1300.0f, 130.0f, 520.0f);
	glVertex3f(700.0f, 130.0f, 520.0f);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glTexCoord2d(0,0);
	glVertex3f(700.0f, 130.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(1300.0f, 130.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1300.0f, 130.0f, 520.0f);
	glTexCoord2d(1,0);
	glVertex3f(700.0f, 130.0f, 520.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 700.0f);
	glVertex3f(700.0f, 150.0f, 520.0f);
	glVertex3f(700.0f, 130.0f, 520.0f);
	glVertex3f(700.0f, 130.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1300.0f, 150.0f, 700.0f);
	glVertex3f(1300.0f, 150.0f, 520.0f);
	glVertex3f(1300.0f, 130.0f, 520.0f);
	glVertex3f(1300.0f, 130.0f, 700.0f);
	glEnd();
	
	//

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(700.0f, 150.0f, 698.0f);
	glVertex3f(1300.0f, 150.0f, 698.0f);
	glVertex3f(1300.0f, 350.0f, 698.0f);
	glVertex3f(700.0f, 350.0f, 698.0f);
	glEnd();



	//........the columns........
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 800.0f, 0.0f);
	glVertex3f(-900.0f, 780.0f, 0.0f);
	glVertex3f(-900.0f, 780.0f, 200.0f);
	glVertex3f(-900.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 800.0f, 0.0f);
	glVertex3f(-880.0f, 800.0f, 0.0f);
	glVertex3f(-880.0f, 800.0f, 200.0f);
	glVertex3f(-900.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 800.0f, 0.0f);
	glVertex3f(-880.0f, 780.0f, 0.0f);
	glVertex3f(-880.0f, 780.0f, 200.0f);
	glVertex3f(-880.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 0.0f);
	glVertex3f(-880.0f, 780.0f, 0.0f);
	glVertex3f(-880.0f, 780.0f, 200.0f);
	glVertex3f(-900.0f, 780.0f, 200.0f);
	glEnd();

	////.......


	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 200.0f);
	glVertex3f(-880.0f, 780.0f, 200.0f);
	glVertex3f(-880.0f, 0.0f, 200.0f);
	glVertex3f(-900.0f, 0.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 200.0f);
	glVertex3f(-900.0f, 780.0f, 180.0f);
	glVertex3f(-900.0f, 0.0f, 180.0f);
	glVertex3f(-900.0f, 0.0f, 200.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 180.0f);
	glVertex3f(-880.0f, 780.0f, 180.0f);
	glVertex3f(-880.0f, 0.0f, 180.0f);
	glVertex3f(-900.0f, 0.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 780.0f, 200.0f);
	glVertex3f(-880.0f, 780.0f, 180.0f);
	glVertex3f(-880.0f, 0.0f, 180.0f);
	glVertex3f(-880.0f, 0.0f, 200.0f);
	glEnd();

	////........
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 200.0f, 0.0f);
	glVertex3f(-900.0f, 180.0f, 0.0f);
	glVertex3f(-900.0f, 180.0f, 200.0f);
	glVertex3f(-900.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 200.0f, 0.0f);
	glVertex3f(-880.0f, 200.0f, 0.0f);
	glVertex3f(-880.0f, 200.0f, 200.0f);
	glVertex3f(-900.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 200.0f, 0.0f);
	glVertex3f(-880.0f, 180.0f, 0.0f);
	glVertex3f(-880.0f, 180.0f, 200.0f);
	glVertex3f(-880.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 180.0f, 0.0f);
	glVertex3f(-880.0f, 180.0f, 0.0f);
	glVertex3f(-880.0f, 180.0f, 200.0f);
	glVertex3f(-900.0f, 180.0f, 200.0f);
	glEnd();

	/////.............
	//...........
	//////.............
	///////...........

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 800.0f, 0.0f);
	glVertex3f(1400.0f, 780.0f, 0.0f);
	glVertex3f(1400.0f, 780.0f, 200.0f);
	glVertex3f(1400.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 800.0f, 0.0f);
	glVertex3f(1380.0f, 800.0f, 0.0f);
	glVertex3f(1380.0f, 800.0f, 200.0f);
	glVertex3f(1400.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 800.0f, 0.0f);
	glVertex3f(1380.0f, 780.0f, 0.0f);
	glVertex3f(1380.0f, 780.0f, 200.0f);
	glVertex3f(1380.0f, 800.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 0.0f);
	glVertex3f(1380.0f, 780.0f, 0.0f);
	glVertex3f(1380.0f, 780.0f, 200.0f);
	glVertex3f(1400.0f, 780.0f, 200.0f);
	glEnd();

	////.......


	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 200.0f);
	glVertex3f(1380.0f, 780.0f, 200.0f);
	glVertex3f(1380.0f, 0.0f, 200.0f);
	glVertex3f(1400.0f, 0.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 200.0f);
	glVertex3f(1400.0f, 780.0f, 180.0f);
	glVertex3f(1400.0f, 0.0f, 180.0f);
	glVertex3f(1400.0f, 0.0f, 200.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 180.0f);
	glVertex3f(1380.0f, 780.0f, 180.0f);
	glVertex3f(1380.0f, 0.0f, 180.0f);
	glVertex3f(1400.0f, 0.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 780.0f, 200.0f);
	glVertex3f(1380.0f, 780.0f, 180.0f);
	glVertex3f(1380.0f, 0.0f, 180.0f);
	glVertex3f(1380.0f, 0.0f, 200.0f);
	glEnd();

	////........
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 200.0f, 0.0f);
	glVertex3f(1400.0f, 180.0f, 0.0f);
	glVertex3f(1400.0f, 180.0f, 200.0f);
	glVertex3f(1400.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 200.0f, 0.0f);
	glVertex3f(1380.0f, 200.0f, 0.0f);
	glVertex3f(1380.0f, 200.0f, 200.0f);
	glVertex3f(1400.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 200.0f, 0.0f);
	glVertex3f(1380.0f, 180.0f, 0.0f);
	glVertex3f(1380.0f, 180.0f, 200.0f);
	glVertex3f(1380.0f, 200.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 180.0f, 0.0f);
	glVertex3f(1380.0f, 180.0f, 0.0f);
	glVertex3f(1380.0f, 180.0f, 200.0f);
	glVertex3f(1400.0f, 180.0f, 200.0f);
	glEnd();


	///..........
	///..........

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 200.0f);
	glVertex3f(-880.0f, 680.0f, 200.0f);
	glVertex3f(1380.0f, 680.0f, 200.0f);
	glVertex3f(1380.0f, 700.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 200.0f);
	glVertex3f(-880.0f, 700.0f, 180.0f);
	glVertex3f(1380.0f, 700.0f, 180.0f);
	glVertex3f(1380.0f, 700.0f, 200.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 180.0f);
	glVertex3f(-880.0f, 680.0f, 180.0f);
	glVertex3f(1380.0f, 680.0f, 180.0f);
	glVertex3f(1380.0f, 700.0f, 180.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 680.0f, 200.0f);
	glVertex3f(-880.0f, 680.0f, 180.0f);
	glVertex3f(1380.0f, 680.0f, 180.0f);
	glVertex3f(1380.0f, 680.0f, 200.0f);
	glEnd();





	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 500.0f);
	glVertex3f(-880.0f, 680.0f, 500.0f);
	glVertex3f(1380.0f, 680.0f, 500.0f);
	glVertex3f(1380.0f, 700.0f, 500.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 500.0f);
	glVertex3f(-880.0f, 700.0f, 520.0f);
	glVertex3f(1380.0f, 700.0f, 520.0f);
	glVertex3f(1380.0f, 700.0f, 500.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 700.0f, 520.0f);
	glVertex3f(-880.0f, 680.0f, 520.0f);
	glVertex3f(1380.0f, 680.0f, 520.0f);
	glVertex3f(1380.0f, 700.0f, 520.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 680.0f, 500.0f);
	glVertex3f(-880.0f, 680.0f, 520.0f);
	glVertex3f(1380.0f, 680.0f, 520.0f);
	glVertex3f(1380.0f, 680.0f, 500.0f);
	glEnd();


	///............
	///............


	///????? ???????

	//.............
	/////..............
	////...............
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 800.0f, 500.0f);
	glVertex3f(-900.0f, 780.0f, 500.0f);
	glVertex3f(-900.0f, 780.0f, 700.0f);
	glVertex3f(-900.0f, 800.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 800.0f, 500.0f);
	glVertex3f(-880.0f, 800.0f, 500.0f);
	glVertex3f(-880.0f, 800.0f, 700.0f);
	glVertex3f(-900.0f, 800.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 800.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 700.0f);
	glVertex3f(-880.0f, 800.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 700.0f);
	glVertex3f(-900.0f, 780.0f, 700.0f);
	glEnd();

	////.......


	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 0.0f, 500.0f);
	glVertex3f(-900.0f, 0.0f, 500.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 500.0f);
	glVertex3f(-900.0f, 780.0f, 520.0f);
	glVertex3f(-900.0f, 0.0f, 520.0f);
	glVertex3f(-900.0f, 0.0f, 500.0f);
	glEnd();
	
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-900.0f, 780.0f, 520.0f);
	glVertex3f(-880.0f, 780.0f, 520.0f);
	glVertex3f(-880.0f, 0.0f, 520.0f);
	glVertex3f(-900.0f, 0.0f, 520.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(-880.0f, 780.0f, 500.0f);
	glVertex3f(-880.0f, 780.0f, 520.0f);
	glVertex3f(-880.0f, 0.0f, 520.0f);
	glVertex3f(-880.0f, 0.0f, 500.0f);
	glEnd();

	////........
	//glBegin(GL_QUADS);
	//glColor3f(1,1,1);
	//glVertex3f(-900.0f, 200.0f, 500.0f);
	//glVertex3f(-900.0f, 180.0f, 500.0f);
	//glVertex3f(-900.0f, 180.0f, 700.0f);
	//glVertex3f(-900.0f, 200.0f, 700.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//glColor3f(1,1,1);
	//glVertex3f(-900.0f, 200.0f, 500.0f);
	//glVertex3f(-880.0f, 200.0f, 500.0f);
	//glVertex3f(-880.0f, 200.0f, 700.0f);
	//glVertex3f(-900.0f, 200.0f, 700.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//glColor3f(1,1,1);
	//glVertex3f(-880.0f, 200.0f, 500.0f);
	//glVertex3f(-880.0f, 180.0f, 500.0f);
	//glVertex3f(-880.0f, 180.0f, 700.0f);
	//glVertex3f(-880.0f, 200.0f, 700.0f);
	//glEnd();

	//glBegin(GL_QUADS);
	//glColor3f(1,1,1);
	//glVertex3f(-900.0f, 180.0f, 500.0f);
	//glVertex3f(-880.0f, 180.0f, 500.0f);
	//glVertex3f(-880.0f, 180.0f, 700.0f);
	//glVertex3f(-900.0f, 180.0f, 700.0f);
	//glEnd();



	/////.........
	//.....
	///........
	//???????? ??????? ?????????
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 800.0f, 500.0f);
	glVertex3f(1400.0f, 780.0f, 500.0f);
	glVertex3f(1400.0f, 780.0f, 700.0f);
	glVertex3f(1400.0f, 800.0f, 700.0f);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 800.0f, 500.0f);
	glVertex3f(1380.0f, 800.0f, 500.0f);
	glVertex3f(1380.0f, 800.0f, 700.0f);
	glVertex3f(1400.0f, 800.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 800.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 700.0f);
	glVertex3f(1380.0f, 800.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 700.0f);
	glVertex3f(1400.0f, 780.0f, 700.0f);
	glEnd();

	////.......

	//??????? ???????? ???????
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 0.0f, 500.0f);
	glVertex3f(1400.0f, 0.0f, 500.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 500.0f);
	glVertex3f(1400.0f, 780.0f, 520.0f);
	glVertex3f(1400.0f, 0.0f, 520.0f);
	glVertex3f(1400.0f, 0.0f, 500.0f);
	glEnd();
	//
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 780.0f, 520.0f);
	glVertex3f(1380.0f, 780.0f, 520.0f);
	glVertex3f(1380.0f, 0.0f, 520.0f);
	glVertex3f(1400.0f, 0.0f, 520.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 780.0f, 500.0f);
	glVertex3f(1380.0f, 780.0f, 520.0f);
	glVertex3f(1380.0f, 0.0f, 520.0f);
	glVertex3f(1380.0f, 0.0f, 500.0f);
	glEnd();

	//........
	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 200.0f, 500.0f);
	glVertex3f(1400.0f, 180.0f, 500.0f);
	glVertex3f(1400.0f, 180.0f, 700.0f);
	glVertex3f(1400.0f, 200.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 200.0f, 500.0f);
	glVertex3f(1380.0f, 200.0f, 500.0f);
	glVertex3f(1380.0f, 200.0f, 700.0f);
	glVertex3f(1400.0f, 200.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1380.0f, 200.0f, 500.0f);
	glVertex3f(1380.0f, 180.0f, 500.0f);
	glVertex3f(1380.0f, 180.0f, 700.0f);
	glVertex3f(1380.0f, 200.0f, 700.0f);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1,1,1);
	glVertex3f(1400.0f, 180.0f, 500.0f);
	glVertex3f(1380.0f, 180.0f, 500.0f);
	glVertex3f(1380.0f, 180.0f, 700.0f);
	glVertex3f(1400.0f, 180.0f, 700.0f);
	glEnd();


	glPopMatrix();



//	//......................
//	//..........the windows........
//	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
//	glEnable(GL_BLEND);
//	
//glBegin(GL_QUADS);
//	glColor4f(1,1,1,0.5);;
//	glVertex3f(-800.0f, 400.0f, 0.0f);
//	glVertex3f(-200.0f, 400.0f, 0.0f);
//	glVertex3f(-200.0f, 700.0f, 0.0f);
//	glVertex3f(-800.0f, 700.0f, 0.0f);
//	glEnd();
//	
//	glBegin(GL_QUADS);
//	glColor4f(1,1,1,0.5);
//	glVertex3f(700.0f, 400.0f, 0.0f);
//	glVertex3f(1300.0f, 400.0f, 0.0f);
//	glVertex3f(1300.0f, 700.0f, 0.0f);
//	glVertex3f(700.0f, 700.0f, 0.0f);
//	glEnd();
//	 glBegin(GL_QUADS);
//	glColor4f(1,1,1,0.5);
//	glVertex3f(-800.0f, 400.0f, 700.0f);
//	glVertex3f(-200.0f, 400.0f, 700.0f);
//	glVertex3f(-200.0f, 700.0f, 700.0f);
//	glVertex3f(-800.0f, 700.0f, 700.0f);
//	glEnd();
//	
//	glBegin(GL_QUADS);
//	glColor4f(1,1,1,0.5);
//	glVertex3f(700.0f, 400.0f, 700.0f);
//	glVertex3f(1300.0f, 400.0f, 700.0f);
//	glVertex3f(1300.0f, 700.0f, 700.0f);
//	glVertex3f(700.0f, 700.0f, 700.0f);
//	glEnd();
//	glDisable(GL_BLEND);
//
	


	
}

void skybox::drawBoxNasser(double x ,double y , double z , int imagePicked ){
		//under side 
   glPushMatrix();
   glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0,0,0);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0+x,0,0);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0+x,0,0-z);
   glTexCoord2d(0.50,0);
   glVertex3d(0,0,0-z);
   glEnd();
   glPopMatrix();
   //upper side 
   
   glPushMatrix();
   glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0,0+y,0);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0+x,0+y,0);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0+x,0+y,0-z);
   glTexCoord2d(0.50,0);
   glVertex3d(0,0+y,0-z);
   glEnd();
   glPopMatrix();
   
   //side 1 front 
   glPushMatrix();
   glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0,0,0);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0,0+y,0);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0,0+y,0-z);
   glTexCoord2d(0.50,0);
   glVertex3d(0,0,0-z);
   glEnd();
   glPopMatrix();
   
   //side 1 back 
   glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0+x,0,0);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0+x,0+y,0);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0+x,0+y,0-z);
   glTexCoord2d(0.50,0);
   glVertex3d(0+x,0,0-z);
   glEnd();
   glPopMatrix();
   //side 1 right 
   glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0,0,0);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0+x,0,0);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0+x,0+y,0);
   glTexCoord2d(0.50,0);
   glVertex3d(0,0+y,0);
   glEnd();
   glPopMatrix();
   //side 1 left 
   glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,imagePicked);
   glBegin(GL_QUADS);
   glTexCoord2d(0.50,0.33);
   glVertex3d(0,0,0-z);
   glTexCoord2d(0.25,0.33);
   glVertex3d(0+x,0,0-z);
   glTexCoord2d(0.25,0.1);
   glVertex3d(0+x,0+y,0-z);
   glTexCoord2d(0.50,0);
   glVertex3d(0,0+y,0-z);
   glEnd();
   glPopMatrix();

		
}

void skybox::drawCabinNasser(int wood1){

  
	//side pannel right floor 1
	glPushMatrix();
   glTranslated(0,0.2,0);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();
	//side pannel left floor 1
	glPushMatrix();
   glTranslated(0,0.2,-5.8);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();


	//side pannel right floor2
	glPushMatrix();
    glTranslated(0,2.2,-1.8);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();
	//side pannel left floor 2
	glPushMatrix();
   glTranslated(0,2.2,-4);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();

	//side pannel right floor 3
	glPushMatrix();
   glTranslated(0,4.2,-1.8);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();
	//side pannel left floor 3
	glPushMatrix();
   glTranslated(0,4.2,-4);
    drawBoxNasser(2,1.8,0.2,wood1);
    glPopMatrix();
	 //floor 1
   	glPushMatrix();
    drawBoxNasser(2,0.2,6,wood1);
    glPopMatrix();
	//floor 2 
		glPushMatrix();
   glTranslated(0,2,0);
    drawBoxNasser(2,0.2,6,wood1);
    glPopMatrix();

	//floor 3
		glPushMatrix();
   glTranslated(0,4,0);
    drawBoxNasser(2,0.2,6,wood1);
    glPopMatrix();
	//floor 3
		glPushMatrix();
   glTranslated(0,6,0);
    drawBoxNasser(2,0.2,6,wood1);
    glPopMatrix();

}
void skybox::drawTableNasser(int wood1){
	glPushMatrix();
   glTranslated(0,3,0);
   drawBoxNasser(4,0.3,4,wood1);
   glPopMatrix();

   glPushMatrix();
   drawBoxNasser(0.2,3,0.2,wood1);
   glPopMatrix();

   glPushMatrix();
   glTranslated(3.8,0,0);
   drawBoxNasser(0.2,3,0.2,wood1);
   glPopMatrix();

   glPushMatrix();
   glTranslated(3.8,0,-3.8);
   drawBoxNasser(0.2,3,0.2,wood1);
   glPopMatrix();

   glPushMatrix();
   glTranslated(0,0,-3.8);
   drawBoxNasser(0.2,3,0.2,wood1);
   glPopMatrix();
}
void skybox::drawCoachNasser (int wood1,int chairs){
	
   //floor
   glPushMatrix();
   drawBoxNasser(4,1,4,wood1);
   glPopMatrix();
   //hand 1
   glPushMatrix();
   glTranslated(0,1,0);
   drawBoxNasser(4,2,1,wood1);
   glPopMatrix();
   //hand2
   glPushMatrix();
   glTranslated(0,1,-3);
   drawBoxNasser(4,2,1,wood1);
   glPopMatrix();
   glPushMatrix();
   glTranslated(3,1,-1);
   drawBoxNasser(1,2,2,wood1);
   glPopMatrix();
   //cution
   glPushMatrix();
   glTranslated(0,1,-1);
   drawBoxNasser(3,0.5,2,chairs);
   glPopMatrix();
}
void skybox::drawBedNasser(int wood1,int chairs){

	glPushMatrix();
    glPushMatrix();
    skybox::drawBoxNasser(7.3,1,4,wood1);
	glPopMatrix();

	//mattress
	glPushMatrix();
	glTranslated(0,1,-0.2);
	skybox::drawBoxNasser(7,0.2,3.6,chairs);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,1,0);
	skybox::drawBoxNasser(0.5,1,4,chairs);
	glPopMatrix();

	glPopMatrix();
}


void drawBox(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6){
	
		//front
		glBindTexture(GL_TEXTURE_2D,image1);
		glBegin(GL_QUADS);	    
		glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,z);
		glEnd();


		//back
		glBindTexture(GL_TEXTURE_2D,image2);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y,-z);
		glEnd();
		
		//right
		glBindTexture(GL_TEXTURE_2D,image3);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,-z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();

		glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_QUADS);
		glColor4f(1,1,1,1);
		glVertex3f(x,y/2,z/10);
		glVertex3f(x,-y/2,z/10);
		glVertex3f(x,-y/2,-z/10);
		glVertex3f(x,y/2,-z/10);
		glEnd();
		glDisable(GL_BLEND);
		glPopMatrix();


		//left
		glBindTexture(GL_TEXTURE_2D,image4);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(-x,y,z);
		glEnd();
		
		//top
		glBindTexture(GL_TEXTURE_2D,image5);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,y,-z);
		glEnd();
		
		//bottom
		glBindTexture(GL_TEXTURE_2D,image6);
		glBegin(GL_QUADS);
	    glTexCoord2f(0.0f,1.0f);
		glVertex3f(-x,-y,-z);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-x,-y,z);
		glTexCoord2f(1.0f,0.0f);
		glVertex3f(x,-y,z);
		glTexCoord2f(1.0f,1.0f);
		glVertex3f(x,-y,-z);

	glEnd();};

void bed_room::table(int wood)
{

		glBindTexture(GL_TEXTURE_2D,wood);

	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,1);
	glVertex3f(700,25,0);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);

	glTexCoord2d(0,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(700,25,100);
	glTexCoord2d(0,1);
	glVertex3f(700,25,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(700,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,100);

	glTexCoord2d(0,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glVertex3f(700,25,0);
	glVertex3f(700,25,100);
	glVertex3f(400,25,100);
	glVertex3f(400,25,0);
	glEnd();

	//legs
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,0);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,0);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,10);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,10);

	glTexCoord2d(0,0);
	glVertex3f(410,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(410,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(410,0,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(400,0,10);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glEnd();

		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(690,0,0);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,0);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,0);
	glTexCoord2d(0,1);
	glVertex3f(700,0,0);

	glTexCoord2d(0,0);
	glVertex3f(690,0,10);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,10);
	glTexCoord2d(0,1);
	glVertex3f(700,0,10);

	glTexCoord2d(0,0);
	glVertex3f(700,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(700,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(700,0,10);
	glTexCoord2d(0,1);
	glVertex3f(700,0,0);

	glTexCoord2d(0,0);
	glVertex3f(690,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(690,0,10);
	glTexCoord2d(0,1);
	glVertex3f(690,0,0);

	glEnd();

	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(690,0,90);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,90);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,90);
	glTexCoord2d(0,1);
	glVertex3f(700,0,90);

	glTexCoord2d(0,0);
	glVertex3f(690,0,100);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,100);
	glTexCoord2d(0,1);
	glVertex3f(700,0,100);

	glTexCoord2d(0,0);
	glVertex3f(700,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(700,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(700,0,100);
	glTexCoord2d(0,1);
	glVertex3f(700,0,90);

	glTexCoord2d(0,0);
	glVertex3f(690,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(690,0,100);
	glTexCoord2d(0,1);
	glVertex3f(690,0,90);

	glEnd();
	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,90);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,90);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);

	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,100);

	glTexCoord2d(0,0);
	glVertex3f(410,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(410,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(410,0,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);


	glTexCoord2d(0,0);
	glVertex3f(400,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,90);

	glEnd();


}
void bed_room::draw_cupboard(int wood,int x1,int x2,int y1,int y2,int z1,int z2){
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z1);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z1);

	glTexCoord2d(0,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x2,y2,z1);

	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x1,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z1);

	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z2);

	glTexCoord2d(0,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y1,z1);

	glTexCoord2d(0,1);
	glVertex3f(x2,y2,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(1,1);
	glVertex3f(x1,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z1);

	glEnd();

}
void bed_room::draw_bed(int bed_cover,int wood,int x1,int x2,int y1,int y2,int z1,int z2,int bed_front,int bed_back){
	 glBindTexture(GL_TEXTURE_2D,wood);
   glBegin(GL_QUADS); //bad
   glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
   glTexCoord2d(1,0);
   glVertex3d(x2,y1,z1);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z1);
   glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);

   glTexCoord2d(0,0);
   glVertex3d(x2,y1,z1);
   glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x2,y2,z1);

   glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
   glTexCoord2d(1,0);
   glVertex3d(x1,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x1,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);


   glTexCoord2d(0,0);
    glVertex3d(x1,y1,z2);
	glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x1,y2,z2);

   glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
   glTexCoord2d(1,0);
    glVertex3d(x2,y1,z1);
	glTexCoord2d(1,1);
	glVertex3d(x2,y1,z2);
	glTexCoord2d(0,1);
    glVertex3d(x1,y1,z2);
	  
	glTexCoord2d(0,0);
    glVertex3d(x1,y2,z1);
	glTexCoord2d(1,0);
    glVertex3d(x2,y2,z1);
	glTexCoord2d(1,1);
	glVertex3d(x2,y2,z2);
	glTexCoord2d(0,1);
    glVertex3d(x1,y2,z2);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,bed_cover);
	glBegin(GL_QUADS);
    glTexCoord2d(0,0);
    glVertex3d(x1,y2+2,z1);
	glTexCoord2d(1,0);
    glVertex3d(x2,y2+2,z1);
	glTexCoord2d(1,1);
	glVertex3d(x2,y2+2,z2);
	glTexCoord2d(0,1);
    glVertex3d(x1,y2+2,z2);
    
    glEnd();

    glBindTexture(GL_TEXTURE_2D,wood);
	glTranslated(0,-20,0);
	glBegin(GL_QUADS);//bed_front

	glTexCoord2d(0,0);
	glVertex3d(x1,y1,z1);
	glTexCoord2d(1,0);
    glVertex3d(x1,y1,z2);
	glTexCoord2d(1,1);
    glVertex3d(x1,bed_front,z2);
	glTexCoord2d(0,1);
	glVertex3d(x1,bed_front,z1);

	glTexCoord2d(0,0);//bed_back
	glVertex3d(x2,y1,z1);
	glTexCoord2d(1,0);
    glVertex3d(x2,y1,z2);
	glTexCoord2d(0,1);
    glVertex3d(x2,bed_back,z2);
	glTexCoord2d(1,1);
	glVertex3d(x2,bed_back,z1);
	glEnd();


}
void bed_room::draw_wardrope(int door,int wood,int x1,int x2,int y1,int y2,int z1,int z2){
	glBindTexture(GL_TEXTURE_2D,door);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
    glVertex3d(x1,y1,z2);
   glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x1,y2,z2);
	 glEnd();

	 glBindTexture(GL_TEXTURE_2D,wood);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
    glTexCoord2d(1,0);
   glVertex3d(x2,y1,z1);
    glTexCoord2d(1,1);
   glVertex3d(x2,y2,z1);
    glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);

    glTexCoord2d(0,0);
   glVertex3d(x2,y1,z1);
       glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x2,y2,z1);

    glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
   glVertex3d(x1,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x1,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);

       glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
    glVertex3d(x2,y1,z1);
    glTexCoord2d(1,1);
	glVertex3d(x2,y1,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y1,z2);
	  
	    glTexCoord2d(0,0);
    glVertex3d(x1,y2,z1);
	    glTexCoord2d(1,0);
    glVertex3d(x2,y2,z1);
	    glTexCoord2d(1,1);
	glVertex3d(x2,y2,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y2,z2);
	  
  
   glEnd();
}
 void bed_room::drawbox(int cupboard,int wood,int x1,int x2,int y1,int y2,int z1,int z2){

   glBindTexture(GL_TEXTURE_2D,cupboard);
   /*
     glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
   glVertex3d(x2,y1,z1);
       glTexCoord2d(1,1);
   glVertex3d(x2,y2,z1);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);
    glEnd();
	*/
	glBindTexture(GL_TEXTURE_2D,wood);
	  glBegin(GL_QUADS);
     glTexCoord2d(0,0);
   glVertex3d(x2,y1,z1);
   glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x2,y2,z1);
  

       glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
   glVertex3d(x1,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x1,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);

       glTexCoord2d(0,0);
    glVertex3d(x1,y1,z2);
	    glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z2);

       glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
    glVertex3d(x2,y1,z1);
	    glTexCoord2d(1,1);
	glVertex3d(x2,y1,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y1,z2);
	  
	    glTexCoord2d(0,0);
    glVertex3d(x1,y2,z1);
	    glTexCoord2d(1,0);
    glVertex3d(x2,y2,z1);
	    glTexCoord2d(1,1);
	glVertex3d(x2,y2,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y2,z2);
	  
  
   glEnd();

}          
 void bed_room::draw_library(int book,int wood,int x1,int x2,int y1,int y2,int z1,int z2){

   glBindTexture(GL_TEXTURE_2D,book);
   
     glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,z1);
   glVertex3d(x2,y1,0);
       glTexCoord2d(1,1);
   glVertex3d(x2,y2,z1);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);
    glEnd();
	
	glBindTexture(GL_TEXTURE_2D,wood);
	  glBegin(GL_QUADS);
     glTexCoord2d(0,0);
   glVertex3d(x2,y1,z1);
   glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
   glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
   glTexCoord2d(0,1);
   glVertex3d(x2,y2,z1);
  

       glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
   glVertex3d(x1,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x1,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z1);

       glTexCoord2d(0,0);
    glVertex3d(x1,y1,z2);
	    glTexCoord2d(1,0);
   glVertex3d(x2,y1,z2);
       glTexCoord2d(1,1);
   glVertex3d(x2,y2,z2);
       glTexCoord2d(0,1);
   glVertex3d(x1,y2,z2);

       glTexCoord2d(0,0);
   glVertex3d(x1,y1,z1);
       glTexCoord2d(1,0);
    glVertex3d(x2,y1,z1);
	    glTexCoord2d(1,1);
	glVertex3d(x2,y1,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y1,z2);
	  
	    glTexCoord2d(0,0);
    glVertex3d(x1,y2,z1);
	    glTexCoord2d(1,0);
    glVertex3d(x2,y2,z1);
	    glTexCoord2d(1,1);
	glVertex3d(x2,y2,z2);
	    glTexCoord2d(0,1);
    glVertex3d(x1,y2,z2);
	  
  
   glEnd();

}
  void bed_room::drawradio(int radio,int wood,int x1,int x2,int y1,int y2,int z1,int z2){
	glBindTexture(GL_TEXTURE_2D,radio);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z1);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z1);

	glTexCoord2d(0,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x2,y2,z1);

	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x1,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z1);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x2,y2,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y2,z2);

	glTexCoord2d(0,0);
	glVertex3f(x2,y1,z1);
	glTexCoord2d(1,0);
	glVertex3f(x2,y1,z2);
	glTexCoord2d(1,1);
	glVertex3f(x1,y1,z2);
	glTexCoord2d(0,1);
	glVertex3f(x1,y1,z1);

	glVertex3f(x2,y2,z1);
	glVertex3f(x2,y2,z2);
	glVertex3f(x1,y2,z2);
	glVertex3f(x1,y2,z1);

	glEnd();

} 
  void bed_room:: carpett(int carpet,int x1,int x2,int z1,int z2){
	glBindTexture(GL_TEXTURE_2D,carpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
   glVertex3d(x1,0.1,z1);
   glTexCoord2d(1,0);
    glVertex3d(x2,0.1,z1);
	glTexCoord2d(1,1);
	glVertex3d(x2,0.1,z2);
	glTexCoord2d(0,1);
    glVertex3d(x1,0.1,z2);
	 
	glEnd();}
 void bed_room::draw_paintig(int paint,int x1,int y1,int y2,int z1,int z2){
	 glBindTexture(GL_TEXTURE_2D,paint);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3d(x1,y1,z1);
	glTexCoord2d(1,0);
    glVertex3d(x1,y1,z2);
	glTexCoord2d(1,1);
    glVertex3d(x1,y2,z2);
	glTexCoord2d(0,1);
	glVertex3d(x1,y2,z1);
	glEnd();
   


}
void bed_room::draw_table(int wood){

		glBindTexture(GL_TEXTURE_2D,wood);

	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,1);
	glVertex3f(700,25,0);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);

	glTexCoord2d(0,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(700,25,100);
	glTexCoord2d(0,1);
	glVertex3f(700,25,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(700,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,100);

	glTexCoord2d(0,0);
	glVertex3f(700,0,0);
	glTexCoord2d(1,0);
	glVertex3f(700,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glVertex3f(700,25,0);
	glVertex3f(700,25,100);
	glVertex3f(400,25,100);
	glVertex3f(400,25,0);
	glEnd();

	//legs
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,0);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,0);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,10);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,10);

	glTexCoord2d(0,0);
	glVertex3f(410,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(410,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(410,0,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(400,0,10);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glEnd();

		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(690,0,0);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,0);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,0);
	glTexCoord2d(0,1);
	glVertex3f(700,0,0);

	glTexCoord2d(0,0);
	glVertex3f(690,0,10);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,10);
	glTexCoord2d(0,1);
	glVertex3f(700,0,10);

	glTexCoord2d(0,0);
	glVertex3f(700,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(700,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(700,0,10);
	glTexCoord2d(0,1);
	glVertex3f(700,0,0);

	glTexCoord2d(0,0);
	glVertex3f(690,-100,0);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,10);
	glTexCoord2d(1,1);
	glVertex3f(690,0,10);
	glTexCoord2d(0,1);
	glVertex3f(690,0,0);

	glEnd();

	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(690,0,90);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,90);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,90);
	glTexCoord2d(0,1);
	glVertex3f(700,0,90);

	glTexCoord2d(0,0);
	glVertex3f(690,0,100);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(700,-100,100);
	glTexCoord2d(0,1);
	glVertex3f(700,0,100);

	glTexCoord2d(0,0);
	glVertex3f(700,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(700,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(700,0,100);
	glTexCoord2d(0,1);
	glVertex3f(700,0,90);

	glTexCoord2d(0,0);
	glVertex3f(690,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(690,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(690,0,100);
	glTexCoord2d(0,1);
	glVertex3f(690,0,90);

	glEnd();
	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,90);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,90);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);

	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(410,-100,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,100);

	glTexCoord2d(0,0);
	glVertex3f(410,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(410,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(410,0,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);


	glTexCoord2d(0,0);
	glVertex3f(400,-100,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-100,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,90);

	glEnd();


}
void bed_room::draw_chair(int wood){
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(500,0,0);
	glTexCoord2d(1,1);
	glVertex3f(500,25,0);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);

	glTexCoord2d(0,0);
	glVertex3f(500,0,0);
	glTexCoord2d(1,0);
	glVertex3f(500,0,100);
	glTexCoord2d(1,1);
	glVertex3f(500,25,100);
	glTexCoord2d(0,1);
	glVertex3f(500,25,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(500,0,100);
	glTexCoord2d(1,1);
	glVertex3f(500,25,100);
	glTexCoord2d(0,1);
	glVertex3f(400,25,100);

	glTexCoord2d(0,0);
	glVertex3f(500,0,0);
	glTexCoord2d(1,0);
	glVertex3f(500,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glVertex3f(500,25,0);
	glVertex3f(500,25,100);
	glVertex3f(400,25,100);
	glVertex3f(400,25,0);
	glEnd();

	//legs
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,0);
	glTexCoord2d(1,1);
	glVertex3f(410,-50,0);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,10);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(410,-50,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,10);

	glTexCoord2d(0,0);
	glVertex3f(410,-50,0);
	glTexCoord2d(1,0);
	glVertex3f(410,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(410,0,10);
	glTexCoord2d(0,1);
	glVertex3f(410,0,0);

	glTexCoord2d(0,0);
	glVertex3f(400,-50,0);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(400,0,10);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glEnd();

		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(490,0,0);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,0);
	glTexCoord2d(1,1);
	glVertex3f(500,-50,0);
	glTexCoord2d(0,1);
	glVertex3f(500,0,0);

	glTexCoord2d(0,0);
	glVertex3f(490,0,10);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(500,-50,10);
	glTexCoord2d(0,1);
	glVertex3f(500,0,10);

	glTexCoord2d(0,0);
	glVertex3f(500,-50,0);
	glTexCoord2d(1,0);
	glVertex3f(500,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(500,0,10);
	glTexCoord2d(0,1);
	glVertex3f(500,0,0);

	glTexCoord2d(0,0);
	glVertex3f(490,-50,0);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,10);
	glTexCoord2d(1,1);
	glVertex3f(490,0,10);
	glTexCoord2d(0,1);
	glVertex3f(490,0,0);

	glEnd();

	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(490,0,90);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,90);
	glTexCoord2d(1,1);
	glVertex3f(500,-50,90);
	glTexCoord2d(0,1);
	glVertex3f(500,0,90);

	glTexCoord2d(0,0);
	glVertex3f(490,0,100);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(500,-50,100);
	glTexCoord2d(0,1);
	glVertex3f(500,0,100);

	glTexCoord2d(0,0);
	glVertex3f(500,-50,90);
	glTexCoord2d(1,0);
	glVertex3f(500,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(500,0,100);
	glTexCoord2d(0,1);
	glVertex3f(500,0,90);

	glTexCoord2d(0,0);
	glVertex3f(490,-50,90);
	glTexCoord2d(1,0);
	glVertex3f(490,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(490,0,100);
	glTexCoord2d(0,1);
	glVertex3f(490,0,90);

	glEnd();
	
		glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,90);
	glTexCoord2d(1,1);
	glVertex3f(410,-50,90);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);

	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(410,-50,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,100);

	glTexCoord2d(0,0);
	glVertex3f(410,-50,90);
	glTexCoord2d(1,0);
	glVertex3f(410,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(410,0,100);
	glTexCoord2d(0,1);
	glVertex3f(410,0,90);


	glTexCoord2d(0,0);
	glVertex3f(400,-50,90);
	glTexCoord2d(1,0);
	glVertex3f(400,-50,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,90);

	glEnd();

	//back
	glBegin(GL_QUADS);
    glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(500,0,0);
	glTexCoord2d(1,1);
	glVertex3f(500,120,0);
	glTexCoord2d(0,1);
	glVertex3f(400,120,0);
	glEnd();}

void bed_room::draw_bedroom(int wood,int bed_cover,int door,int cupboard,int radio,int book,int carpet,int paint){
	glPushMatrix();
	glTranslated(-1380,20,420);
	bed_room::draw_bed(bed_cover,wood,400,850,0,50,0,250,150,90);
	glTranslated(0,20,-380);
	bed_room::draw_bed(bed_cover,wood,400,850,0,50,0,250,150,90);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-1380,0,300);
	bed_room::draw_cupboard( wood,400,450,0,100,0,100);
	glPopMatrix();
    
	glPushMatrix();
	glTranslated(10,0,0);
	bed_room::draw_wardrope( door, wood,400,800,0,500,0,100);
    glTranslated(0,0,590);
	bed_room::drawbox( cupboard, wood,400,700,0,100,0,100);

	glRotated(90,0,1,0);
	glTranslated(-500,0,450);
	 
	bed_room::drawradio(radio, wood, 400, 450, 0,50, 0, 100);
	glPopMatrix();

	glPushMatrix();
    glTranslated(0,300,590);
	bed_room::draw_library(book,wood,490,700,0,100,0,100);
	glPopMatrix();

	glPushMatrix();
    glTranslated(-1380,300,200);
	bed_room::draw_paintig( paint,450,0,150,0,300);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-250,0,200);
	bed_room:: carpett(carpet,300,950,0,350);
	glPopMatrix();

	glPushMatrix();
	//CHAIR
    glTranslated(-400,55,500);
	bed_room::draw_chair(wood);
	glPopMatrix();
	 glTranslated(-500,105,590);
	bed_room::draw_table(wood);

	}


void skybox::table_for_playstation_room(int x,int y ,int z,int tbale_texture,int iron,int cris)
{


	//????? ?????????
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, 100.0f, 20.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y, 20.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y, z);
	glEnd();



	//front left tawlah
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y-35, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+250, y-35, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+250, 0, z);
	glEnd();



	//front left tawlah
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, 0, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y-35, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+250, y-35, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+250, 0, z);
	glEnd();


	//front left tawlah
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y-35, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y-35, 20);
	glTexCoord2d(1,1);
	glVertex3f(-x+250, y-35, 20);
	glTexCoord2d(1,0);
	glVertex3f(-x+250, y-35, z);
	glEnd();



	//front right tawlah
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+250, 0, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+250, y-35, z);
	glTexCoord2d(1,1);
	glVertex3f(-x, y-35, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, 0, z);
	glEnd();


	//front right tawlah
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+250, y-35, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+250, y-35, 20);
	glTexCoord2d(1,1);
	glVertex3f(-x, y-35, 20);
	glTexCoord2d(1,0);
	glVertex3f(-x, y-35, z);
	glEnd();




	/**************          back ***/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y, 20.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y, 20.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, 0, 20.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x, 0, 20.0f);
	glEnd();




	/**************          right ***/
	
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y, 20);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, 0, 20);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, 0, z);
	glEnd();



	/**************          left ***/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y, z);
	glTexCoord2d(0,1);
	glVertex3f(-x, y, 20.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x, 0, 20.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x, 0, z);
	glEnd();




		/**************          ground ***/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, 0, z);
	glTexCoord2d(0,1);
	glVertex3f(-x, 0.0f, 20.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, 0, 20.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, 0, z);
	glEnd();


	//the end of the table


	///????? ??????????

	//front display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y, z-50);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+20, z-50);
	glTexCoord2d(1,1);
	glVertex3f(-x+300, y+20, z-50);
	glTexCoord2d(1,0);
	glVertex3f(-x+300, y, z-50);
	glEnd();

	//back display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y+20, z-75);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+20, z-75);
	glTexCoord2d(1,1);
	glVertex3f(-x+300, y+20, z-75);
	glTexCoord2d(1,0);
	glVertex3f(-x+300, y, z-75);
	glEnd();


	//left display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y+20, z-50);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+20, z-75);
	glTexCoord2d(1,1);
	glVertex3f(-x+200, y, z-75);
	glTexCoord2d(1,0);
	glVertex3f(-x+200, y, z-50);
	glEnd();



	
	//right display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+300, y, z-50);
	glTexCoord2d(0,1);
	glVertex3f(-x+300, y, z-75);
	glTexCoord2d(1,1);
	glVertex3f(-x+300, y+20, z-75);
	glTexCoord2d(1,0);
	glVertex3f(-x+300, y+20, z-50);
	glEnd();





	//right display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y+20, z-50);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+20, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+300, y+20, 100.0f);
	glTexCoord2d(1,0);
	glVertex3f(-x+300, y+20, z-50);
	glEnd();



	
	//button  display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y+2, z-50);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+2, z-75);
	glTexCoord2d(1,1);
	glVertex3f(-x+300, y+2, z-75);
	glTexCoord2d(1,0);
	glVertex3f(-x+300, y+2, z-50);
	glEnd();



	//??? ????? ??????? ???????
	//front display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+245, y+20, z-55);
	glTexCoord2d(0,1);
	glVertex3f(-x+245, 140.0f, z-55);
	glTexCoord2d(1,1);
	glVertex3f(-x+255, 140.0f, z-55);
	glTexCoord2d(1,0);
	glVertex3f(-x+255, y+20, z-55);
	glEnd();

	//back display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+245, y+20, z-70);
	glTexCoord2d(0,1);
	glVertex3f(-x+245, 140.0f, z-70);
	glTexCoord2d(1,1);
	glVertex3f(-x+255, 140.0f, z-70);
	glTexCoord2d(1,0);
	glVertex3f(-x+255, y+20, z-70);
	glEnd();


	//left display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+245, 140.0f, z-55);
	glTexCoord2d(0,1);
	glVertex3f(-x+245, 140.0f, z-70);
	glTexCoord2d(1,1);
	glVertex3f(-x+245, y+20, z-70);
	glTexCoord2d(1,0);
	glVertex3f(-x+245, y+20, z-55);
	glEnd();



	
	//right display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+255, y+20, z-55);
	glTexCoord2d(0,1);
	glVertex3f(-x+255, y+20, z-70);
	glTexCoord2d(1,1);
	glVertex3f(-x+255, 140.0f, z-70);
	glTexCoord2d(1,0);
	glVertex3f(-x+255, 140.0f, z-55);
	glEnd();





	//right display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+245, 140.0f, z-55);
	glTexCoord2d(0,1);
	glVertex3f(-x+245, 140.0f, z-70);
	glTexCoord2d(1,1);
	glVertex3f(-x+255, 140.0f, z-70);
	glTexCoord2d(1,0);
	glVertex3f(-x+255, 140.0f, z-55);
	glEnd();


	//button  display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+245, y+20, z-55);
	glTexCoord2d(0,1);
	glVertex3f(-x+245, y+20, z-70);
	glTexCoord2d(1,1);
	glVertex3f(-x+255, y+20, z-70);
	glTexCoord2d(1,0);
	glVertex3f(-x+255, y+20, z-55);
	glEnd();



	//??????
	/*****************************************************************************/
	//front  display
	glBindTexture(GL_TEXTURE_2D,cris);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+400, y+40, z-52);
	glTexCoord2d(0,1);
	glVertex3f(-x+400, y+170, z-52);
	glTexCoord2d(1,1);
	glVertex3f(-x+100, y+170, z-52);
	glTexCoord2d(1,0);
	glVertex3f(-x+100, y+40, z-52);
	glEnd();



	//grround  display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+100, y+40, z-52);
	glTexCoord2d(0,1);
	glVertex3f(-x+100, y+40, z-67);
	glTexCoord2d(1,1);
	glVertex3f(-x+400, y+40, z-67);
	glTexCoord2d(1,0);
	glVertex3f(-x+400, y+40, z-52);
	glEnd();



	//back  display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+400, y+40, z-67);
	glTexCoord2d(0,1);
	glVertex3f(-x+400, y+170, z-67);
	glTexCoord2d(1,1);
	glVertex3f(-x+100, y+170, z-67);
	glTexCoord2d(1,0);
	glVertex3f(-x+100, y+40, z-67);
	glEnd();


	//left display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+100, y+40, z-52);
	glTexCoord2d(0,1);
	glVertex3f(-x+100, y+40, z-67);
	glTexCoord2d(1,1);
	glVertex3f(-x+100, y+170, z-67);
	glTexCoord2d(1,0);
	glVertex3f(-x+100, y+170, z-52);



	//right  display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+400, y+40, z-52);
	glTexCoord2d(0,1);
	glVertex3f(-x+400, y+40, z-67);
	glTexCoord2d(1,1);
	glVertex3f(-x+400, y+170, z-67);
	glTexCoord2d(1,0);
	glVertex3f(-x+400, y+170, z-52);

	//top display
	glBindTexture(GL_TEXTURE_2D,iron);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+100, y+170, z-52);
	glTexCoord2d(0,1);
	glVertex3f(-x+100, y+170, z-67);
	glTexCoord2d(1,1);
	glVertex3f(-x+400, y+170, z-67);
	glTexCoord2d(1,0);
	glVertex3f(-x+400, y+170, z-52);	
	glEnd();
	


	//????
	//ground
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-400, y+340, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-400,y+340, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+340, z);
	glEnd();

	//top
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x,y+350, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-400, y+350, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-400, y+350, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+350, z);
	glEnd();

	//left
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x, y+350, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x, y+350, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+340, z);
	glEnd();

	//right
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y+340, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+350, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+350, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y+340, z);
	glEnd();


	/*font*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+340, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+350, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+350, z);
	glEnd();


	
	/*back*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+340, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+350, 0);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+350, 0);
	glEnd();



	/* 2raf right/******************************************************************/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+500, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+300, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y+340, z);
	glEnd();
		
	/* 2raf left*/		
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+490, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+490, y+300, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+490, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+490, y+340, z);
	glEnd();


	/* 2raf groun*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+490, y+300, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+490, y+300, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+500, y+300, 0);
	glEnd();


	/* 2raf back*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+490, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+340, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+300, 0);
	glTexCoord2d(1,0);
	glVertex3f(-x+490, y+300, 0);
	glEnd();


	/* 2raf front*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+490, y+340, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+500, y+340, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+500, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+490, y+300, z);
	glEnd();


	/********************  raff left                                *********** ************/
		
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+10, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+10, y+300, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+10, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+10, y+340, z);
	glEnd();
		
		/* 2raf left*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x, y+300, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+340, z);
	glEnd();


			/* 2raf groun*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+300, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x, y+300, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+10, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x+10, y+300, 0);
	glEnd();





	/* 2raf back*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+10, y+340, 0);
	glTexCoord2d(1,1);
	glVertex3f(-x+10,y+300, 0);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+300, 0);
	glEnd();


			/* 2raf front*/
	glBindTexture(GL_TEXTURE_2D,tbale_texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x, y+340, z);
	glTexCoord2d(0,1);
	glVertex3f(-x+10, y+340, z);
	glTexCoord2d(1,1);
	glVertex3f(-x+10, y+300, z);
	glTexCoord2d(1,0);
	glVertex3f(-x, y+300, z);
	glEnd();

	/**********************************************************     end raff**********************************************/



	/****************photo*/
	glBindTexture(GL_TEXTURE_2D,cris);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+300, y+350, z-125);
	glTexCoord2d(1,0);
	glVertex3f(-x+400, y+350, z-125);
	glTexCoord2d(1,1);
	glVertex3f(-x+400, y+450, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+300, y+450, 0);
	glEnd();



	/****************photo*/
	glBindTexture(GL_TEXTURE_2D,cris);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-x+200, y+350, z-125);
	glTexCoord2d(1,0);
	glVertex3f(-x+100, y+350, z-125);
	glTexCoord2d(1,1);
	glVertex3f(-x+100, y+450, 0);
	glTexCoord2d(0,1);
	glVertex3f(-x+200, y+450, 0);
	glEnd();
	/****************************************/

}         
