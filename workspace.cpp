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
	gluLookAt(movX, movY, movZ, lX, lY, -50, 0, 1, 0);
	if (keys['D'])
		movX += 5;
	if (keys['A'])
		movX -= 5;
	if (keys['W'])
		movY += 1;
	if (keys['S'])
		movY -= 5;
	if (keys['Z'])
		movZ += 5;
	if (keys['X'])
		movZ -= 5;
	if (keys[VK_LEFT])
		lX += 20;
	if (keys[VK_RIGHT])
		lX -= 20;
	if (keys[VK_UP])
		lY += 4;
	if (keys[VK_DOWN])
		lY -= 4;
}

int wood;
int bed_cover;
int cushion;
int cupboard;
int door;
int book;
int radio;
int paint;
int carpet;
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
	wood = LoadTexture("brown.bmp",255);
	bed_cover= LoadTexture("bed.bmp",255);
	cushion= LoadTexture("coc.bmp",255);
	cupboard= LoadTexture("cupboard.bmp",255);
	door=LoadTexture("d.bmp",255);
	book=LoadTexture("book.bmp",255);
	radio=LoadTexture("rad.bmp",255);
	paint=LoadTexture("paint.bmp",255);
	carpet=LoadTexture("carpet.bmp",255);
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
    

	glBindTexture(GL_TEXTURE_2D,image);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(-1000.0f, 1000.0f, 0.0f);
	glTexCoord2d(0,1);
	glVertex3f(1500.0f, 1000.0f, 0.0f);
	glTexCoord2d(1,1);
	glVertex3f(1500.0f, 1000.0f, 700.0f);
	glTexCoord2d(1,0);
	glVertex3f(-1000.0f, 1000.0f, 700.0f);
	glEnd();

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
}
void drawbox2(){
	  glBegin(GL_QUADS);
   glVertex3d(400,0,0);
   glVertex3d(800,0,0);
   glVertex3d(800,50,0);
   glVertex3d(400,50,0);

   glVertex3d(800,0,0);
   glVertex3d(800,0,200);
   glVertex3d(800,50,200);
   glVertex3d(800,50,0);

   glVertex3d(400,0,0);
   glVertex3d(400,0,200);
   glVertex3d(400,50,200);
   glVertex3d(400,50,0);

    glVertex3d(400,0,200);
   glVertex3d(800,0,200);
   glVertex3d(800,50,200);
   glVertex3d(400,50,200);

   glVertex3d(400,0,0);
    glVertex3d(800,0,0);
	glVertex3d(800,0,200);
    glVertex3d(400,0,200);
	  
    glVertex3d(400,50,0);
    glVertex3d(800,50,0);
	glVertex3d(800,50,200);
    glVertex3d(400,50,200);
    glEnd();
}



void Rail(float width,float hight, float depth)
{
 glBegin(GL_QUADS);

 for (float i = -depth; i < depth ; i = i + 1.6)
 {
  // Front Face
  glColor3f(120.0f, 127.0f, 127.0f);
  glVertex3f(-width/2, -hight/2, hight / 2 - i);
  glVertex3f(width / 2, -hight / 2, hight / 2 - i);
  glVertex3f(width / 2, hight / 2, hight / 2 - i);
  glVertex3f(-width / 2, hight / 2, hight / 2 - i);
  // Back Face
  glColor3f(120.0f, 127.0f, 127.0f);
  glVertex3f(-width / 2, -hight / 2, -hight / 2 - i);
  glVertex3f(-width / 2, hight / 2, -hight / 2 - i);
  glVertex3f(width / 2, hight / 2, -hight / 2 - i);
  glVertex3f(width / 2, -hight / 2, -hight / 2 - i);
  // Top Face

  glColor3f(120.0f, 12.0f, 12.0f);
  glVertex3f(-width / 2, hight / 2, -hight / 2 - i);
  glVertex3f(-width / 2, hight / 2, hight / 2 - i);
  glVertex3f(width / 2, hight / 2, hight / 2 - i);
  glVertex3f(width / 2, hight / 2, -hight / 2 - i);
  // Bottom Face

  glColor3f(120.0f, 127.0f, 127.0f);
  glVertex3f(-width / 2, -hight / 2, -hight / 2 - i);
  glVertex3f(width / 2, -hight / 2, -hight / 2 - i);
  glVertex3f(width / 2, -hight / 2, hight / 2 - i);
  glVertex3f(-width / 2, -hight / 2, hight / 2 - i);

 }

 // Right face
 glColor3f(120.0f, 127.0f, 127.0f);
 glVertex3f(width/2, -hight, -depth);
 glVertex3f(width/2, hight, -depth);
 glVertex3f(width/2, hight, depth);
 glVertex3f(width/2, -hight, depth);

 // Left Face
 glColor3f(120.0f, 127.0f, 127.0f);
 glVertex3f(-width / 2, -hight, -depth);
 glVertex3f(-width / 2, -hight, depth);
 glVertex3f(-width / 2, hight, depth);
 glVertex3f(-width / 2, hight, -depth);
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
  x = center.x + radius * cos(theta);
  y = center.y + radius * sin(theta);
  glVertex3f(x, y, center.z);
  theta = theta + .5;
 }

 for (int step = 0; step <= steps; step++)
 {
  float x = center.x + (radius- radius/6) * cos(theta);
  float y = center.y + (radius - radius / 6) * sin(theta);
  glVertex3f(x, y, center.z);
  theta = theta + .5;
  x = center.x + (radius - radius / 6) * cos(theta);
  y = center.y + (radius - radius / 6) * sin(theta);
  glVertex3f(x, y, center.z);
  theta = theta + .5;
 }
 glEnd();

 glBegin(GL_LINES);
 float x, y;                                  /*this is code for diameters cyrcle*/
 for (float angle = 0.0f; angle <= (2.0f * 3.14f); angle += 0.8f)
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
void drawbox(){

   glBindTexture(GL_TEXTURE_2D,cupboard);
   /*
     glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
   glVertex3d(700,0,0);
       glTexCoord2d(1,1);
   glVertex3d(700,100,0);
       glTexCoord2d(0,1);
   glVertex3d(400,100,0);
    glEnd();
	*/
	glBindTexture(GL_TEXTURE_2D,wood);
	  glBegin(GL_QUADS);
     glTexCoord2d(0,0);
   glVertex3d(700,0,0);
   glTexCoord2d(1,0);
   glVertex3d(700,0,100);
   glTexCoord2d(1,1);
   glVertex3d(700,100,100);
   glTexCoord2d(0,1);
   glVertex3d(700,100,0);
  

       glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
   glVertex3d(400,0,100);
       glTexCoord2d(1,1);
   glVertex3d(400,100,100);
       glTexCoord2d(0,1);
   glVertex3d(400,100,0);

       glTexCoord2d(0,0);
    glVertex3d(400,0,100);
	    glTexCoord2d(1,0);
   glVertex3d(700,0,100);
       glTexCoord2d(1,1);
   glVertex3d(700,100,100);
       glTexCoord2d(0,1);
   glVertex3d(400,100,100);

       glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
    glVertex3d(700,0,0);
	    glTexCoord2d(1,1);
	glVertex3d(700,0,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,0,100);
	  
	    glTexCoord2d(0,0);
    glVertex3d(400,100,0);
	    glTexCoord2d(1,0);
    glVertex3d(700,100,0);
	    glTexCoord2d(1,1);
	glVertex3d(700,100,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,100,100);
	  
  
   glEnd();

}



void drawcolumn(){
	   glBegin(GL_QUADS);  ///right_side
   glVertex3d(400,0,0);
   glVertex3d(420,0,0);
   glVertex3d(420,200,0);
   glVertex3d(400,200,0);
   
   glVertex3d(420,0,0);
   glVertex3d(420,0,100);
   glVertex3d(420,200,100);
   glVertex3d(420,200,0);

   glVertex3d(400,0,100);
   glVertex3d(420,0,100);
   glVertex3d(420,200,100);
   glVertex3d(420,200,100);

   
    glVertex3d(400,0,0);
   glVertex3d(400,0,100);
   glVertex3d(400,200,100);
   glVertex3d(400,200,0);

   glVertex3d(400,0,0);
    glVertex3d(420,0,0);
	glVertex3d(420,0,100);
    glVertex3d(400,0,100);
	  
    glVertex3d(400,200,0);
    glVertex3d(420,200,0);
	glVertex3d(420,200,100);
    glVertex3d(400,200,100);
}
void draw_cupboard(){
	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,1);
	glVertex3f(450,50,0);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(450,100,100);
	glTexCoord2d(0,1);
	glVertex3f(450,100,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,100,100);
	glTexCoord2d(0,1);
	glVertex3f(400,100,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(450,100,100);
	glTexCoord2d(0,1);
	glVertex3f(400,100,100);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glTexCoord2d(0,0);
	glVertex3f(450,100,0);
	glTexCoord2d(1,0);
	glVertex3f(450,100,100);
	glTexCoord2d(1,1);
	glVertex3f(400,100,100);
	glTexCoord2d(0,1);
	glVertex3f(400,100,0);

	glEnd();

}
void draw_library(){

   glBindTexture(GL_TEXTURE_2D,book);
   
     glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
   glVertex3d(700,0,0);
       glTexCoord2d(1,1);
   glVertex3d(700,100,0);
       glTexCoord2d(0,1);
   glVertex3d(400,100,0);
    glEnd();
	
	glBindTexture(GL_TEXTURE_2D,wood);
	  glBegin(GL_QUADS);
     glTexCoord2d(0,0);
   glVertex3d(700,0,0);
   glTexCoord2d(1,0);
   glVertex3d(700,0,100);
   glTexCoord2d(1,1);
   glVertex3d(700,100,100);
   glTexCoord2d(0,1);
   glVertex3d(700,100,0);
  

       glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
   glVertex3d(400,0,100);
       glTexCoord2d(1,1);
   glVertex3d(400,100,100);
       glTexCoord2d(0,1);
   glVertex3d(400,100,0);

       glTexCoord2d(0,0);
    glVertex3d(400,0,100);
	    glTexCoord2d(1,0);
   glVertex3d(700,0,100);
       glTexCoord2d(1,1);
   glVertex3d(700,100,100);
       glTexCoord2d(0,1);
   glVertex3d(400,100,100);

       glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
    glVertex3d(700,0,0);
	    glTexCoord2d(1,1);
	glVertex3d(700,0,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,0,100);
	  
	    glTexCoord2d(0,0);
    glVertex3d(400,100,0);
	    glTexCoord2d(1,0);
    glVertex3d(700,100,0);
	    glTexCoord2d(1,1);
	glVertex3d(700,100,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,100,100);
	  
  
   glEnd();

}


	
void drawradio(){
	glBindTexture(GL_TEXTURE_2D,radio);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,1);
	glVertex3f(450,50,0);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(450,50,100);
	glTexCoord2d(0,1);
	glVertex3f(450,50,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,50,100);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,wood);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,100);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(450,50,100);
	glTexCoord2d(0,1);
	glVertex3f(400,50,100);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,100);
	glTexCoord2d(1,1);
	glVertex3f(400,0,100);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glVertex3f(450,50,0);
	glVertex3f(450,50,100);
	glVertex3f(400,50,100);
	glVertex3f(400,50,0);

	glEnd();

}

void draw_cushion(){
	glPushMatrix(); //cushion
	glBindTexture(GL_TEXTURE_2D,cushion);
	glTranslated(0,53,60);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,1);
	glVertex3f(450,50,0);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,150);
	glTexCoord2d(1,1);
	glVertex3f(450,50,150);
	glTexCoord2d(0,1);
	glVertex3f(450,50,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,0);
	glTexCoord2d(1,0);
	glVertex3f(400,0,150);
	glTexCoord2d(1,1);
	glVertex3f(400,50,150);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);

	glTexCoord2d(0,0);
	glVertex3f(400,0,150);
	glTexCoord2d(1,0);
	glVertex3f(450,0,150);
	glTexCoord2d(1,1);
	glVertex3f(450,50,150);
	glTexCoord2d(0,1);
	glVertex3f(400,50,150);

	glTexCoord2d(0,0);
	glVertex3f(450,0,0);
	glTexCoord2d(1,0);
	glVertex3f(450,0,150);
	glTexCoord2d(1,1);
	glVertex3f(400,0,150);
	glTexCoord2d(0,1);
	glVertex3f(400,0,0);

	glTexCoord2d(0,0);
	glVertex3f(450,50,0);
	glTexCoord2d(1,0);
	glVertex3f(450,50,150);
	glTexCoord2d(1,1);
	glVertex3f(400,50,150);
	glTexCoord2d(0,1);
	glVertex3f(400,50,0);
	glEnd();
	glPopMatrix();
}
void draw_bed(){
	 glBindTexture(GL_TEXTURE_2D,wood);
   glBegin(GL_QUADS); //bad
   glTexCoord2d(0,0);
   glVertex3d(400,0,0);
   glTexCoord2d(1,0);
   glVertex3d(850,0,0);
   glTexCoord2d(1,1);
   glVertex3d(850,50,0);
   glTexCoord2d(0,1);
   glVertex3d(400,50,0);

   glTexCoord2d(0,0);
   glVertex3d(850,0,0);
   glTexCoord2d(1,0);
   glVertex3d(850,0,250);
   glTexCoord2d(1,1);
   glVertex3d(850,50,250);
   glTexCoord2d(0,1);
   glVertex3d(850,50,0);

   glTexCoord2d(0,0);
   glVertex3d(400,0,0);
   glTexCoord2d(1,0);
   glVertex3d(400,0,250);
   glTexCoord2d(1,1);
   glVertex3d(400,50,250);
   glTexCoord2d(0,1);
   glVertex3d(400,50,0);


   glTexCoord2d(0,0);
    glVertex3d(400,0,250);
	glTexCoord2d(1,0);
   glVertex3d(850,0,250);
   glTexCoord2d(1,1);
   glVertex3d(850,50,250);
   glTexCoord2d(0,1);
   glVertex3d(400,50,250);

   glTexCoord2d(0,0);
   glVertex3d(400,0,0);
   glTexCoord2d(1,0);
    glVertex3d(850,0,0);
	glTexCoord2d(1,1);
	glVertex3d(850,0,250);
	glTexCoord2d(0,1);
    glVertex3d(400,0,250);
	  
	glTexCoord2d(0,0);
    glVertex3d(400,50,0);
	glTexCoord2d(1,0);
    glVertex3d(850,50,0);
	glTexCoord2d(1,1);
	glVertex3d(850,50,250);
	glTexCoord2d(0,1);
    glVertex3d(400,50,250);
	glEnd();
	glBindTexture(GL_TEXTURE_2D,bed_cover);
	glBegin(GL_QUADS);
    glTexCoord2d(0,0);
    glVertex3d(400,52,0);
	glTexCoord2d(1,0);
    glVertex3d(850,52,0);
	glTexCoord2d(1,1);
	glVertex3d(850,52,250);
	glTexCoord2d(0,1);
    glVertex3d(400,52,250);
    
    glEnd();

    glBindTexture(GL_TEXTURE_2D,wood);
	glTranslated(0,-20,0);
	glBegin(GL_QUADS);//bed_front

	glTexCoord2d(0,0);
	glVertex3d(400,0,0);
	glTexCoord2d(1,0);
    glVertex3d(400,0,250);
	glTexCoord2d(1,1);
    glVertex3d(400,150,250);
	glTexCoord2d(0,1);
	glVertex3d(400,150,0);

	glTexCoord2d(0,0);//bed_back
	glVertex3d(850,0,0);
	glTexCoord2d(1,0);
    glVertex3d(850,0,250);
	glTexCoord2d(0,1);
    glVertex3d(850,90,250);
	glTexCoord2d(1,1);
	glVertex3d(850,90,0);
	glEnd();


}
void draw_wardrope(){
	glBindTexture(GL_TEXTURE_2D,door);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
    glVertex3d(400,0,100);
   glTexCoord2d(1,0);
   glVertex3d(800,0,100);
   glTexCoord2d(1,1);
   glVertex3d(800,500,100);
   glTexCoord2d(0,1);
   glVertex3d(400,500,100);
	 glEnd();

	 glBindTexture(GL_TEXTURE_2D,wood);
	 glBegin(GL_QUADS);
	 glTexCoord2d(0,0);
   glVertex3d(400,0,0);
    glTexCoord2d(1,0);
   glVertex3d(800,0,0);
    glTexCoord2d(1,1);
   glVertex3d(800,500,0);
    glTexCoord2d(0,1);
   glVertex3d(400,500,0);

    glTexCoord2d(0,0);
   glVertex3d(800,0,0);
       glTexCoord2d(1,0);
   glVertex3d(800,0,100);
       glTexCoord2d(1,1);
   glVertex3d(800,500,100);
       glTexCoord2d(0,1);
   glVertex3d(700,500,0);

    glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
   glVertex3d(400,0,100);
       glTexCoord2d(1,1);
   glVertex3d(400,500,100);
       glTexCoord2d(0,1);
   glVertex3d(400,500,0);

       glTexCoord2d(0,0);
   glVertex3d(400,0,0);
       glTexCoord2d(1,0);
    glVertex3d(800,0,0);
    glTexCoord2d(1,1);
	glVertex3d(800,0,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,0,100);
	  
	    glTexCoord2d(0,0);
    glVertex3d(400,500,0);
	    glTexCoord2d(1,0);
    glVertex3d(800,500,0);
	    glTexCoord2d(1,1);
	glVertex3d(800,500,100);
	    glTexCoord2d(0,1);
    glVertex3d(400,500,100);
	  
  
   glEnd();
}
void draw_paintig(){
	 glBindTexture(GL_TEXTURE_2D,paint);
	glBegin(GL_QUADS);

	glTexCoord2d(0,0);
	glVertex3d(450,0,0);
	glTexCoord2d(1,0);
    glVertex3d(450,0,300);
	glTexCoord2d(1,1);
    glVertex3d(450,150,300);
	glTexCoord2d(0,1);
	glVertex3d(450,150,0);
	glEnd();
   


}
int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	//the camera
	Camera();
	glTranslated(0, 0, -15);
	//the skybox
	skybox();
	
	//the first train
	glTranslated(0,100,-350);
	glPushMatrix();
    Draw_train();
  
   glPushMatrix();
   glTranslated(-1380,20,420);
   draw_bed();
   glTranslated(0,20,-380);
   draw_bed();
   glPopMatrix();

   glPushMatrix();
   glTranslated(-1380,0,300);
   draw_cupboard();
   glPopMatrix();
    
   glPushMatrix();
   glTranslated(10,0,0);
   draw_wardrope();
    glTranslated(0,0,590);
	  drawbox();

	 glRotated(90,0,1,0);
	 glTranslated(-500,0,450);
	 
	drawradio();
	glPopMatrix();

	glPushMatrix();
    glTranslated(0,300,590);
	draw_library();
	glPopMatrix();

	glPushMatrix();
glTranslated(-1380,300,200);
	draw_paintig();
	glPopMatrix();

	glTranslated(-250,0,200);
	glBindTexture(GL_TEXTURE_2D,carpet);
	glBegin(GL_QUADS);
	glTexCoord2d(0,0);
   glVertex3d(300,0,0);
   glTexCoord2d(1,0);
    glVertex3d(950,0,0);
	glTexCoord2d(1,1);
	glVertex3d(950,0,350);
	glTexCoord2d(0,1);
    glVertex3d(300,0,350);
	  
	glEnd();

    

	
	
	
	/////////////
	/*
	glBegin(GL_QUADS);
	glVertex3f(400,0,0);
	glVertex3f(450,0,0);
	glVertex3f(450,50,0);
	glVertex3f(400,50,0);

	
	glVertex3f(450,0,0);
	glVertex3f(450,0,200);
	glVertex3f(450,50,200);
	glVertex3f(450,50,0);

	glVertex3f(400,0,0);
	glVertex3f(400,0,200);
	glVertex3f(400,50,200);
	glVertex3f(400,50,0);

	glVertex3f(400,0,200);
	glVertex3f(450,0,200);
	glVertex3f(450,50,200);
	glVertex3f(400,50,200);

	glVertex3f(450,0,0);
	glVertex3f(450,0,200);
	glVertex3f(400,0,200);
	glVertex3f(400,0,0);

	glVertex3f(450,50,0);
	glVertex3f(450,50,200);
	glVertex3f(400,50,200);
	glVertex3f(400,50,0);

	glEnd();
	*/

	glPopMatrix();
	
	
	//Wheel(Point(0,0,0),10.0);
	
	
	//Rail();
	glPushMatrix();
	glRotated(90,0,1,0);
	//Rail(780,0.6,20000);
	glPopMatrix();
	
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

/*	This Code Creates Our OpenGL Window.  Parameters Are:					*
*	title			- Title To Appear At The Top Of The Window				*
*	width			- Width Of The GL Window Or Fullscreen Mode				*
*	height			- Height Of The GL Window Or Fullscreen Mode			*
*	bits			- Number Of Bits To Use For Color (8/16/24/32)			*
*	fullscreenflag	- Use Fullscreen Mode (TRUE) Or Windowed Mode (FALSE)	*/

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
