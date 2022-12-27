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
	glPopMatrix();

	
	
	
	//****

	//the front door new version
	glPushMatrix();
	/*glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(14944444448.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(148888888898.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(14988888888.0f, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(148888888898.0f, 0, 200.0f);
	glEnd();*/
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
	glVertex3f(x-100, y, z);
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

/*
void skybox::Draw_train_two()
{

	//**the first side of the train
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //front
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1000.0f, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1000.0f, 1000.0f, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(1000.0f, 500.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1260.0f, 500.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1260.0f, 1000.0f, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(1000.0f, 1000.0f, 0.0f);

	
	glTexCoord2d(0,0);
	glVertex3f(1260.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 0.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f, 0.0f);
	glTexCoord2d(1,0);
	glVertex3f(1260.0f, 1000.0f, 0.0f);
	
	glEnd();

	//the door on left
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1260.0f, 0.0f, 1.0f);
	glTexCoord2d(0,1);
	glVertex3f(1000.0f, 0.0f, 1.0f);
	glTexCoord2d(1,1);
	glVertex3f(1000.0f, 500.0f, 1.0f);
	glTexCoord2d(1,0);
	glVertex3f(1260.0f, 500.0f, 1.0f);
	glEnd();
	glPopMatrix();

	//***the second side of the train
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS); //back
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(1000.0f, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1000.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);

	glTexCoord2d(0,0);
	glVertex3f(1000.0f, 500.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(1260.0f, 500.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1260.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(1000.0f, 1000.0f, 700.0f);

	
	glTexCoord2d(0,0);
	glVertex3f(1260.0f, 0.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(1260.0f, 1000.0f, 700.0f);
	glEnd();


	//the door on right
	glPushMatrix();
	glTranslated(xdoor1,0,0);
	glBindTexture(GL_TEXTURE_2D,door);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1260.0f, 0.0f, 699.0f);
	glTexCoord2d(0,1);
	glVertex3f(1000.0f, 0.0f, 699.0f);
	glTexCoord2d(1,1);
	glVertex3f(1000.0f, 500.0f, 699.0f);
	glTexCoord2d(1,0);
	glVertex3f(1260.0f, 500.0f, 699.0f);
	glEnd();
	glPopMatrix();
	

	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-1000.0f, 0.0f, 200.0f);
	glTexCoord2d(1,1);
	glVertex3f(-1000.0f, 1000.0f, 200.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 0.0f);


	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(-1000.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(-1000.0f, 1000.0f, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 200.0f);


	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 400.0f);
	glTexCoord2d(0,1);
	glVertex3f(-1000.0f, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 400.0f);

	glEnd();

	//the back door
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-998.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(-998.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(-998.0f, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(-998.0f, 0, 200.0f);
	glEnd();
	glPopMatrix();


	//the front door
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1497.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(1497.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(1497.0f, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(1497.0f, 0, 200.0f);
	glEnd();


	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1500.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 0.0f, 200.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f,200.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 0.0f);

	glTexCoord2d(0,0);
	glVertex3f(1500.0f, 0.0f, 400.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 400.0f);

	glTexCoord2d(0,0);
	glVertex3f(1500.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 200.0f);
	glEnd();
    
	//the roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-900.0f, 1200.0f, 100.0f);
	glTexCoord2d(0,1);
	glVertex3f(1400.0f, 1200.0f, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(1400.0f, 1200.0f, 600.0f);
	glTexCoord2d(1,0);
	glVertex3f(-900.0f, 1200.0f, 600.0f);
	glEnd();

	//the ground
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 0, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 0, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 0, 700.0f);
	glEnd();

	
	//the Left Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-900.0f, 1200.0f, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(1400.0f, 1200.0f, 100.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 00.0f);
	glEnd();



	//the right Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);
	glTexCoord2d(0,1);
	glVertex3f(-900.0f, 1200.0f, 600.0f);
	glTexCoord2d(1,1);
	glVertex3f(1400.0f, 1200.0f, 600.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 700.0f);
	glEnd();

	//back Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(-900.0f, 1200.0f, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(-900.0f, 1200.0f, 600.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);
	glEnd();

	//front Pillar for roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1500.0f, 1000.0f, 00.0f);
	glTexCoord2d(0,1);
	glVertex3f(1400.0f, 1200.0f, 100.0f);
	glTexCoord2d(1,1);
	glVertex3f(1400.0f, 1200.0f, 600.0f);
	glTexCoord2d(1,0);
	glVertex3f(1500.0f, 1000.0f, 700.0f);
	glEnd();

	
}

void skybox::DrawSeat()
{
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -50, 70);
	glTexCoord2d(1, 0);
	glVertex3d(-900, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(-900, 50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 50, 70);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(900, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(900, 50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 50, -70);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, -50, 70);
	glTexCoord2d(1, 0);
	glVertex3d(900, -50, 70);
	glTexCoord2d(1, 1);
	glVertex3d(900, 50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 50, 70);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(900, -50, 70);
	glTexCoord2d(0, 0);
	glVertex3d(900, -50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(900, 50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(900, 50, 70);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900, 50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(900, 50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(900, 50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-900, 50, 70);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-900,-50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(900, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(900, -50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-900, -50, 70);
	glEnd();
}

void skybox::DrawSmallSeat()
{
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100, -50, 70);
	glTexCoord2d(1, 0);
	glVertex3d(-100, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(-100, 50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(-100, 50, 70);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100, -50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(100, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(100, 50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(-100, 50, -70);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100, -50, 70);
	glTexCoord2d(1, 0);
	glVertex3d(100, -50, 70);
	glTexCoord2d(1, 1);
	glVertex3d(100, 50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-100, 50, 70);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(100, -50, 70);
	glTexCoord2d(0, 0);
	glVertex3d(100, -50, -70);
	glTexCoord2d(0, 1);
	glVertex3d(100, 50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(100, 50, 70);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100, 50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(100, 50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(100, 50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-100, 50, 70);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, chairs);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-100,-50, -70);
	glTexCoord2d(1, 0);
	glVertex3d(100, -50, -70);
	glTexCoord2d(1, 1);
	glVertex3d(100, -50, 70);
	glTexCoord2d(0, 1);
	glVertex3d(-100 , -50, 70);
	glEnd();
}

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
/*
void chair(){glBindTexture(GL_TEXTURE_2D,wood);
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
*/
