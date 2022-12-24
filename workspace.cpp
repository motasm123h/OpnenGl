#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>

#include "texture.h"
#include "skybox.h"

HDC			hDC = NULL;		// Private GDI Device Context
HGLRC		hRC = NULL;		// Permanent Rendering Cntext
HWND		hWnd = NULL;		// Holds Our Window Handle
HINSTANCE	hInstance;		// Holds The Instance Of The Application

bool	keys[256];			// Array Used For The Keyboard Routine
bool	active = TRUE;		// Window Active Flag Set To TRUE By Default
bool	fullscreen = FALSE;	// Fullscreen Flag Set To Fullscreen Mode By Default

//
GLfloat	zaxis = -5.0f;
GLfloat	zaxisx = 0.0f;// Depth Into The Screen
GLfloat	xrot;				// X Rotation
GLfloat	yrot;				// Y Rotation
GLfloat xspeed;				// X Rotation Speed
GLfloat yspeed;				// Y Rotation Speed
float Light_Ambient[] = { 1.0,0.0,0.0,0 };
float Light_Diffuse[] = { 1,0,0,0 };
float Light_Specular[] = { 1,1,1,1 };
float Light_Position[] = { 0,0,20,0 };

float Cone_Ambient[] = { 0.1,0.1,0.1,1 };
float Cone_Diffuse[] = { 0.2,0.1,0.9,1 };
float Cone_Specular[] = { 1,1,1,1 };
float Cone_Shininess = 50;


int back, front, left, right, top , image;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat z = 20.0;

double movX, movY, movZ;
double lX, lY;
double th = 0;
double tmax = 0;
int wood=0 , iron=0;
float angle = 0;
double xdoor1, zdoor2;
float chairs = 0,topChairs=0,door=0;



LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

LRESULT	CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);	// Declaration For WndProc

GLvoid ReSizeGLScene(GLsizei width, GLsizei height)		// Resize And Initialize The GL Window
{
	if (height == 0)										// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);						// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

														// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 0.1f, 200000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}


void Camera()
{
	gluLookAt(movX, movY, movZ, lX, lY, -5, 0, 1, 0);
	if (keys['D'])
		movX += 10;
	if (keys['A'])
		movX -= 10;
	if (keys['W'])
		movY += 5;
	if (keys['S'])
		movY -= 5;
	if (keys['Z'])
		movZ += 5;
	if (keys['X'])
		movZ -= 5;
	if (keys[VK_LEFT])
		lX += 80;
	if (keys[VK_RIGHT])
		lX -= 7;
	if (keys[VK_UP])
		lY += 1;
	if (keys[VK_DOWN])
		lY -= 5;
}


void Camera_two()
{
  gluLookAt(movX, 0.1*cos(movZ+movX), movZ, lX+movX, lY, -5+movZ, 0, 1, 0);
  if (keys['D'])
    movX += 0.1;
  if (keys['A'])
    movX -= 0.1;
  if (keys['S'])
    movZ += 0.1;
  if (keys['W'])
    movZ -= 0.1;
  if (keys[VK_RIGHT])
    lX += 0.1;
  if (keys[VK_LEFT])
    lX -= 0.1;
  if (keys[VK_UP])
    lY += 0.1;
  if (keys[VK_DOWN]&& lY>=0.05)
    lY -= 0.1;

}

void moveDoor(){
	if (keys['O']) 
	 xdoor1 -= 0.9;
   if(keys['P'])
	 xdoor1 += 0.9;
    if (keys['L'])
	   zdoor2 += 0.9;
   if(keys['K'])
	   zdoor2 -= 0.9;
}

int InitGL(GLvoid)										// All Setup For OpenGL Goes Here
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	glEnable(GL_TEXTURE_2D);
	back = LoadTexture("back4.bmp",255);
	front = LoadTexture("front.bmp",255);
	left = LoadTexture("left.bmp",255);
	right = LoadTexture("right.bmp",255);
	top = LoadTexture("top.bmp",255);
	image = LoadTexture("woodeen.bmp",255);
	wood = LoadTexture("wall.bmp",255);
	iron = LoadTexture("iron.bmp",255);
	chairs=LoadTexture("chairs.bmp",255);
	topChairs=LoadTexture("topChairs.bmp",255);
	door=LoadTexture("door.bmp",255);
	return TRUE;										// Initialization Went OK
}

void skybox()
{
	
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-20000, -8000, 8000);
	glTexCoord2d(1, 0);
	glVertex3d(-20000, -8000, -8000);
	glTexCoord2d(1, 1);
	glVertex3d(-20000, 8000, -8000);
	glTexCoord2d(0, 1);
	glVertex3d(-20000, 8000, 8000);
	glEnd();




	glBindTexture(GL_TEXTURE_2D, right);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-20000, -8000, -8000);
	glTexCoord2d(1, 0);
	glVertex3d(20000, -8000, -8000);
	glTexCoord2d(1, 1);
	glVertex3d(20000, 8000, -8000);
	glTexCoord2d(0, 1);
	glVertex3d(-20000, 8000, -8000);
	glEnd();

	
	glBindTexture(GL_TEXTURE_2D, front);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-20000, -8000, 8000);
	glTexCoord2d(1, 0);
	glVertex3d(20000, -8000, 8000);
	glTexCoord2d(1, 1);
	glVertex3d(20000, 8000, 8000);
	glTexCoord2d(0, 1);
	glVertex3d(-20000, 8000, 8000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, back);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 0);
	glVertex3d(20000, -8000, 8000);
	glTexCoord2d(0, 0);
	glVertex3d(20000, -8000, -8000);
	glTexCoord2d(0, 1);
	glVertex3d(20000, 8000, -8000);
	glTexCoord2d(1, 1);
	glVertex3d(20000, 8000, 8000);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-20000, 8000, -8000);
	glTexCoord2d(1, 0);
	glVertex3d(20000, 8000, -8000);
	glTexCoord2d(1, 1);
	glVertex3d(20000, 8000, 8000);
	glTexCoord2d(0, 1);
	glVertex3d(-20000, 8000, 8000);
	glEnd();



	glBindTexture(GL_TEXTURE_2D, top);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-20000,-8000, -8000);
	glTexCoord2d(1, 0);
	glVertex3d(20000, -8000, -8000);
	glTexCoord2d(1, 1);
	glVertex3d(20000, -8000, 8000);
	glTexCoord2d(0, 1);
	glVertex3d(-20000, -8000, 8000);
	glEnd();
}

void Draw_train()
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


	//the back of the train
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 0.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(-1000.0f, 0.0f, 700.0f);
	glTexCoord2d(1,1);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 0.0f);
	glEnd();

	//the front
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
    
	//the front door
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D,door);
	glTranslated(0,0,zdoor2);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(1498.0f, 400.0f, 200.0f);
	glTexCoord2d(0,1);
	glVertex3f(1498.0f, 400.0f, 400.0f);
	glTexCoord2d(1,1);
	glVertex3f(1498.0f, 0, 400.0f);
	glTexCoord2d(1,0);
	glVertex3f(1498.0f, 0, 200.0f);
	glEnd();
	glPopMatrix();

	//the roof
	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-900.0f, 1200.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1400.0f, 1200.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1400.0f, 1200.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-900.0f, 1200.0f, 700.0f);
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

void Draw_train_two()
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

void test(float width, float hight, float depth)
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, wood);
	glBegin(GL_QUADS);

	for (float i = -depth; i < depth; i = i + 2.5)
	{

		// Front Face
		glColor3f(0.55, 0.35, 0.11);
		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(-width / 1.5, hight / 3.5, hight / 2 - i);
		// Back Face
		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(-width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		// Top Face

		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(-width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		// Bottom Face

		glTexCoord2f(0, 0);
		glVertex3f(-width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(-width / 1.5, -hight / 3.5, hight / 2 - i);

		// Right face
		glTexCoord2f(0, 0);
		glVertex3f(width / 1.5, -hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 0);
		glVertex3f(width / 1.5, hight / 3.5, -hight / 2 - i);
		glTexCoord2f(1, 1);
		glVertex3f(width / 1.5, hight / 3.5, hight / 2 - i);
		glTexCoord2f(0, 1);
		glVertex3f(width / 1.5, -hight / 3.5, hight / 2 - i);

		// Left Face
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

void test1(float width, float hight, float depth)
{
	test(width, hight, depth);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, iron);
	glBegin(GL_QUADS);
	///Start

	// Left Face
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2, -hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2, hight + 0.5, -depth);

	//Top LEFT FACE 
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2.4, hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2, hight + 0.5, -depth);

	//right LEFT FACE 
	glTexCoord2f(0, 0);
	glVertex3f(-width / 2.4, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(-width / 2.4, -hight + 0.5, depth);
	glTexCoord2f(1, 1);
	glVertex3f(-width / 2.4, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(-width / 2.4, hight + 0.5, -depth);

	///End

	///Start
	// Right face
	glTexCoord2f(0, 0);
	glVertex3f(width / 2, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2, -hight + 0.5, depth);

	//Top RIGHT FACE 
	glTexCoord2f(0, 0);
	glVertex3f(width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2.4, hight + 0.5, depth);

	//left RIGHT FACE
	glTexCoord2f(0, 0);
	glVertex3f(width / 2.4, -hight + 0.5, -depth);
	glTexCoord2f(1, 0);
	glVertex3f(width / 2.4, hight + 0.5, -depth);
	glTexCoord2f(1, 1);
	glVertex3f(width / 2.4, hight + 0.5, depth);
	glTexCoord2f(0, 1);
	glVertex3f(width / 2.4, -hight + 0.5, depth);
	///End
	glEnd();
}

void Wheel(Point center, float radius)
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

	glPushMatrix();
	glTranslated(0, 0, -0.35);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + (radius - radius / 6) * cos(theta);
		float y = center.y + (radius - radius / 6) * sin(theta);
		glVertex3f(x, y, center.z);
		theta = theta + .5;
	}
	glPopMatrix();

	glEnd();

	glPushMatrix();
	glTranslatef(0, 0, +0.5);
	glBegin(GL_POINTS);
	for (int step = 0; step <= steps; step++)
	{
		float x = center.x + radius * cos(theta);
		float y = center.y + radius * sin(theta);
		glVertex3f(x, y, center.z);
		theta = theta + .5;
	}
	glEnd();
	glPopMatrix();

	glBegin(GL_LINES);
	float x, y;                                  /*this is code for diameters cyrcle*/
	for (angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.8f)
	{
		x = (radius - radius / 6) * cos(angle);
		y = (radius - radius / 6) * sin(angle);
		glColor3f(1.0f, 1.0f, 0);
		glVertex3f(x, y, 0.0f);
		glColor3f(1.0f, 0.0f, 0);
		glVertex3f(center.x, center.y, center.z);
	}
	glEnd();
}

void DrawSeat()
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

void DrawSmallSeat()
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

void DrawChairsBracket()
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

void DrawChairs()
{
//first chairs
	glPushMatrix();
	glTranslated(-90,50,75);
	DrawSeat();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-94,105,30);
	DrawChairsBracket();
	glPopMatrix();
	


	//second chairs
	glPushMatrix();
	glTranslated(-90,50,625);
	DrawSeat();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-94,105,670);
	DrawChairsBracket();
	glPopMatrix();


	//third
	glPushMatrix();
	glTranslated(1390,50,625);
	DrawSmallSeat();
	glPopMatrix();

	//four
	glPushMatrix();
	glTranslated(1390,50,75);
	DrawSmallSeat();
	glPopMatrix();
}

void train()
{
	//draw the train
	Draw_train_two();
	DrawChairs();
	
}


GLUquadric* quadric=gluNewQuadric();
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(0, 0, -15);
	//the camera
	Camera();
	moveDoor();
	Draw_train();
	//the skybox
	//skybox();

	glPushMatrix();
	glTranslated(2800,0,0);
	train();
	glPopMatrix();

	
    //glTranslated(-8,0,-4);
    //glTranslatef(0,0,Tzval);
   // ownTranslatef(0,0,Tzval);
    


	
	//glPushMatrix();
	//Draw_train();
	//glPopMatrix();
	//



	
	return TRUE;
}

GLvoid KillGLWindow(GLvoid)								// Properly Kill The Window
{
	if (fullscreen)										// Are We In Fullscreen Mode?
	{
		ChangeDisplaySettings(NULL, 0);					// If So Switch Back To The Desktop
		ShowCursor(TRUE);								// Show Mouse Pointer
	}

	if (hRC)											// Do We Have A Rendering Context?
	{
		if (!wglMakeCurrent(NULL, NULL))					// Are We Able To Release The DC And RC Contexts?
		{
			MessageBox(NULL, "Release Of DC And RC Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}

		if (!wglDeleteContext(hRC))						// Are We Able To Delete The RC?
		{
			MessageBox(NULL, "Release Rendering Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		}
		hRC = NULL;										// Set RC To NULL
	}

	if (hDC && !ReleaseDC(hWnd, hDC))					// Are We Able To Release The DC
	{
		MessageBox(NULL, "Release Device Context Failed.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hDC = NULL;										// Set DC To NULL
	}

	if (hWnd && !DestroyWindow(hWnd))					// Are We Able To Destroy The Window?
	{
		MessageBox(NULL, "Could Not Release hWnd.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hWnd = NULL;										// Set hWnd To NULL
	}

	if (!UnregisterClass("OpenGL", hInstance))			// Are We Able To Unregister Class
	{
		MessageBox(NULL, "Could Not Unregister Class.", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		hInstance = NULL;									// Set hInstance To NULL
	}
}



BOOL CreateGLWindow(char* title, int width, int height, int bits, bool fullscreenflag)
{
	GLuint		PixelFormat;			// Holds The Results After Searching For A Match
	WNDCLASS	wc;						// Windows Class Structure
	DWORD		dwExStyle;				// Window Extended Style
	DWORD		dwStyle;				// Window Style
	RECT		WindowRect;				// Grabs Rectangle Upper Left / Lower Right Values
	WindowRect.left = (long)0;			// Set Left Value To 0
	WindowRect.right = (long)width;		// Set Right Value To Requested Width
	WindowRect.top = (long)0;				// Set Top Value To 0
	WindowRect.bottom = (long)height;		// Set Bottom Value To Requested Height

	fullscreen = fullscreenflag;			// Set The Global Fullscreen Flag

	hInstance = GetModuleHandle(NULL);				// Grab An Instance For Our Window
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;	// Redraw On Size, And Own DC For Window.
	wc.lpfnWndProc = (WNDPROC)WndProc;					// WndProc Handles Messages
	wc.cbClsExtra = 0;									// No Extra Window Data
	wc.cbWndExtra = 0;									// No Extra Window Data
	wc.hInstance = hInstance;							// Set The Instance
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);			// Load The Default Icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);			// Load The Arrow Pointer
	wc.hbrBackground = NULL;									// No Background Required For GL
	wc.lpszMenuName = NULL;									// We Don't Want A Menu
	wc.lpszClassName = "OpenGL";								// Set The Class Name

	if (!RegisterClass(&wc))									// Attempt To Register The Window Class
	{
		MessageBox(NULL, "Failed To Register The Window Class.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;											// Return FALSE
	}

	if (fullscreen)												// Attempt Fullscreen Mode?
	{
		DEVMODE dmScreenSettings;								// Device Mode
		memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
		dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
		dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
		dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height
		dmScreenSettings.dmBitsPerPel = bits;					// Selected Bits Per Pixel
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		// Try To Set Selected Mode And Get Results.  NOTE: CDS_FULLSCREEN Gets Rid Of Start Bar.
		if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
		{
			// If The Mode Fails, Offer Two Options.  Quit Or Use Windowed Mode.
			if (MessageBox(NULL, "The Requested Fullscreen Mode Is Not Supported By\nYour Video Card. Use Windowed Mode Instead?", "GL template", MB_YESNO | MB_ICONEXCLAMATION) == IDYES)
			{
				fullscreen = FALSE;		// Windowed Mode Selected.  Fullscreen = FALSE
			}
			else
			{
				// Pop Up A Message Box Letting User Know The Program Is Closing.
				MessageBox(NULL, "Program Will Now Close.", "ERROR", MB_OK | MB_ICONSTOP);
				return FALSE;									// Return FALSE
			}
		}
	}

	if (fullscreen)												// Are We Still In Fullscreen Mode?
	{
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
		dwStyle = WS_POPUP;										// Windows Style
		ShowCursor(FALSE);										// Hide Mouse Pointer
	}
	else
	{
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
	}

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);		// Adjust Window To True Requested Size

																	// Create The Window
	if (!(hWnd = CreateWindowEx(dwExStyle,							// Extended Style For The Window
		"OpenGL",							// Class Name
		title,								// Window Title
		dwStyle |							// Defined Window Style
		WS_CLIPSIBLINGS |					// Required Window Style
		WS_CLIPCHILDREN,					// Required Window Style
		0, 0,								// Window Position
		WindowRect.right - WindowRect.left,	// Calculate Window Width
		WindowRect.bottom - WindowRect.top,	// Calculate Window Height
		NULL,								// No Parent Window
		NULL,								// No Menu
		hInstance,							// Instance
		NULL)))								// Dont Pass Anything To WM_CREATE
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Window Creation Error.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
		1,											// Version Number
		PFD_DRAW_TO_WINDOW |						// Format Must Support Window
		PFD_SUPPORT_OPENGL |						// Format Must Support OpenGL
		PFD_DOUBLEBUFFER,							// Must Support Double Buffering
		PFD_TYPE_RGBA,								// Request An RGBA Format
		bits,										// Select Our Color Depth
		0, 0, 0, 0, 0, 0,							// Color Bits Ignored
		0,											// No Alpha Buffer
		0,											// Shift Bit Ignored
		0,											// No Accumulation Buffer
		0, 0, 0, 0,									// Accumulation Bits Ignored
		16,											// 16Bit Z-Buffer (Depth Buffer)  
		0,											// No Stencil Buffer
		0,											// No Auxiliary Buffer
		PFD_MAIN_PLANE,								// Main Drawing Layer
		0,											// Reserved
		0, 0, 0										// Layer Masks Ignored
	};

	if (!(hDC = GetDC(hWnd)))							// Did We Get A Device Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Device Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))	// Did Windows Find A Matching Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Find A Suitable PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!SetPixelFormat(hDC, PixelFormat, &pfd))		// Are We Able To Set The Pixel Format?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Set The PixelFormat.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!(hRC = wglCreateContext(hDC)))				// Are We Able To Get A Rendering Context?
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Create A GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	if (!wglMakeCurrent(hDC, hRC))					// Try To Activate The Rendering Context
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Can't Activate The GL Rendering Context.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	ShowWindow(hWnd, SW_SHOW);						// Show The Window
	SetForegroundWindow(hWnd);						// Slightly Higher Priority
	SetFocus(hWnd);									// Sets Keyboard Focus To The Window
	ReSizeGLScene(width, height);					// Set Up Our Perspective GL Screen

	if (!InitGL())									// Initialize Our Newly Created GL Window
	{
		KillGLWindow();								// Reset The Display
		MessageBox(NULL, "Initialization Failed.", "ERROR", MB_OK | MB_ICONEXCLAMATION);
		return FALSE;								// Return FALSE
	}

	return TRUE;									// Success
}

LRESULT CALLBACK WndProc(HWND	hWnd,			// Handle For This Window
	UINT	uMsg,			// Message For This Window
	WPARAM	wParam,			// Additional Message Information
	LPARAM	lParam)			// Additional Message Information
{
	switch (uMsg)									// Check For Windows Messages
	{
	case WM_ACTIVATE:							// Watch For Window Activate Message
	{
		if (!HIWORD(wParam))					// Check Minimization State
		{
			active = TRUE;						// Program Is Active
		}
		else
		{
			active = FALSE;						// Program Is No Longer Active
		}

		return 0;								// Return To The Message Loop
	}

	case WM_SYSCOMMAND:							// Intercept System Commands
	{
		switch (wParam)							// Check System Calls
		{
		case SC_SCREENSAVE:					// Screensaver Trying To Start?
		case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
			return 0;							// Prevent From Happening
		}
		break;									// Exit
	}

	case WM_CLOSE:								// Did We Receive A Close Message?
	{
		PostQuitMessage(0);						// Send A Quit Message
		return 0;								// Jump Back
	}

	case WM_KEYDOWN:							// Is A Key Being Held Down?
	{
		keys[wParam] = TRUE;					// If So, Mark It As TRUE
		return 0;								// Jump Back
	}

	case WM_KEYUP:								// Has A Key Been Released?
	{
		keys[wParam] = FALSE;					// If So, Mark It As FALSE
		return 0;								// Jump Back
	}

	case WM_SIZE:								// Resize The OpenGL Window
	{
		ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));  // LoWord=Width, HiWord=Height
		return 0;								// Jump Back
	}
	}

	// Pass All Unhandled Messages To DefWindowProc
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE	hInstance,			// Instance
	HINSTANCE	hPrevInstance,		// Previous Instance
	LPSTR		lpCmdLine,			// Command Line Parameters
	int			nCmdShow)			// Window Show State
{
	MSG		msg;									// Windows Message Structure
	BOOL	done = FALSE;								// Bool Variable To Exit Loop

														// Ask The User Which Screen Mode They Prefer
														//if (MessageBox(NULL,"Would You Like To Run In Fullscreen Mode?", "Start FullScreen?",MB_YESNO|MB_ICONQUESTION)==IDNO)
	{
		fullscreen = FALSE;							// Windowed Mode
	}

	// Create Our OpenGL Window
	if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
	{
		return 0;									// Quit If Window Was Not Created
	}

	while (!done)									// Loop That Runs While done=FALSE
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))	// Is There A Message Waiting?
		{
			if (msg.message == WM_QUIT)				// Have We Received A Quit Message?
			{
				done = TRUE;							// If So done=TRUE
			}
			else									// If Not, Deal With Window Messages
			{
				TranslateMessage(&msg);				// Translate The Message
				DispatchMessage(&msg);				// Dispatch The Message
			}
		}
		else										// If There Are No Messages
		{
			// Draw The Scene.  Watch For ESC Key And Quit Messages From DrawGLScene()
			if (active)								// Program Active?
			{
				if (keys[VK_ESCAPE])				// Was ESC Pressed?
				{
					done = TRUE;						// ESC Signalled A Quit
				}
				else								// Not Time To Quit, Update Screen
				{
					DrawGLScene();					// Draw The Scene
					SwapBuffers(hDC);				// Swap Buffers (Double Buffering)
				}
			}

			if (keys[VK_F1])						// Is F1 Being Pressed?
			{
				keys[VK_F1] = FALSE;					// If So Make Key FALSE
				KillGLWindow();						// Kill Our Current Window
				fullscreen = !fullscreen;				// Toggle Fullscreen / Windowed Mode
														// Recreate Our OpenGL Window
				if (!CreateGLWindow("OpenGL template", 640, 480, 16, fullscreen))
				{
					return 0;						// Quit If Window Was Not Created
				}
			}
		}
	}

	// Shutdown
	KillGLWindow();									// Kill The Window
	return (msg.wParam);							// Exit The Program
}
