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

//float Cone_Ambient[] = { 0.1,0.1,0.1,1 };
//float Cone_Diffuse[] = { 0.2,0.1,0.9,1 };
//float Cone_Specular[] = { 1,1,1,1 };
//float Cone_Shininess = 50;


int back, front, left, right, top , image,pes;
GLfloat x = 0.0;
GLfloat y = 0.0;
GLfloat z = 20.0;
GLfloat color[]={1,80,70,4};

double movX, movY, movZ;
double lX, lY;
double th = 0;
double tmax = 0;
double xdoor1, zdoor2;
int wood=0 , iron=0,ironwall=0,glass=0,controll=0,chairs = 0,topChairs=0,door=0,grass,OUTER,downbed;
int wintop,winbottm,winleft,winright,winfront,winback;
int springtop,springbottm,sringleft,springright,springfront,springback;
int auttop,autbottm,autleft,autright,autfront,autback;


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
		movX += 100;
	if (keys['A'])
		movX -= 100;
	if (keys['W'])
		movY += 10;
	if (keys['S'])
		movY -= 10;
	if (keys['Z'])
		movZ += 15;
	if (keys['X'])
		movZ -= 15;
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
	image = LoadTexture("woodeen.bmp",255);
	wood = LoadTexture("wall.bmp",255);
	iron = LoadTexture("iron.bmp",255);
	glass = LoadTexture("glass.bmp",255);
	controll = LoadTexture("controll.bmp",255);
	ironwall = LoadTexture("ironwall.bmp",255);
	door=LoadTexture("door.bmp",255);
	chairs=LoadTexture("chairs.bmp",255);
	grass=LoadTexture("grass.bmp",25);
	OUTER = LoadTexture("Data/wall.bmp");
	downbed = LoadTexture("Data/bed.bmp");

	//winter
	wintop=LoadTexture("wintop.bmp",255);
	winbottm=LoadTexture("winbottm.bmp",255);
	winleft=LoadTexture("winleft.bmp",255);
	winright=LoadTexture("winright.bmp",255);
	winback=LoadTexture("winback.bmp",255);
	winfront=LoadTexture("winfront.bmp",255);
	//spring
	springtop=LoadTexture("springtop.bmp",255);
	springbottm=LoadTexture("springbottm.bmp",255);
	sringleft=LoadTexture("springleft.bmp",255);
	springright=LoadTexture("springright.bmp",255);
	springfront=LoadTexture("springfront.bmp",255);
	springback=LoadTexture("springback.bmp",255);
	//aut
	auttop=LoadTexture("auttop.bmp",255);
	autbottm=LoadTexture("autbottm.bmp",255);
	autleft=LoadTexture("autleft.bmp",255);
	autright=LoadTexture("autright.bmp",255);
	autfront=LoadTexture("autfront.bmp",255);
	autback=LoadTexture("autback.bmp",255);

	return TRUE;										// Initialization Went OK
}
//capte
void drawhead()
{
		glPushMatrix();
		skybox::drawBox2(600,500,350,ironwall,ironwall,iron,ironwall,iron,ironwall,door,glass);
		
		glPushMatrix();
		glTranslated(400,-250,0);
		glScaled(0.96,0.47,0.29);
		skybox::drawBox4(150,500,1200,ironwall,ironwall,ironwall,ironwall,controll,ironwall);
		glPopMatrix();


		glPushMatrix();
		glTranslated(1170,-250,0);
		glScaled(0.96,0.47,0.2);
		skybox::drawBox3(600,500,1200,iron,ironwall,ironwall,ironwall,ironwall,ironwall);
		glPopMatrix();
		
		//glPushMatrix();
		//glTranslated(0,-410,120);
		//glScaled(1.5,1.5,1.5);
		//skybox::DrawSmallSeat();
		//glPopMatrix();

		//glPushMatrix();
		//glTranslated(0,-410,-120);
		//glScaled(1.5,1.5,1.5);
		//skybox::DrawSmallSeat();
		//glPopMatrix();
		//glPopMatrix();
}

void secondTrin()
{

	glPushMatrix();
	skybox::Draw_train_two(ironwall,door,zdoor2,xdoor1,1800,1000,700);
	
	//«·ﬂ‰»«Ì« 
	glPushMatrix();
	glTranslated(0,60,80);
	skybox::DrawSeat(chairs,1250,50,70);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,60,610);
	skybox::DrawSeat(chairs,1250,50,70);
	glPopMatrix();
	
	//«·ﬂ‰»«Ì«  «·’€«—
	glPushMatrix();
	glTranslated(1650,60,610);
	skybox::DrawSeat(chairs,100,50,70);
	glPopMatrix();
	
	glPushMatrix();
	glTranslated(1650,60,100);
	skybox::DrawSeat(chairs,100,50,70);
	glPopMatrix();

	//«·”‰«œ…
	glPushMatrix();
	glTranslated(0,160,30);
	skybox::DrawSeat(chairs,1250,50,15);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,160,680);
	skybox::DrawSeat(chairs,1250,50,15);
	glPopMatrix();

	glPopMatrix();
}

void firstTrain()
{
	glPushMatrix();
	skybox::Draw_train(ironwall,door,zdoor2,xdoor1,1800,1000,700);
	glPushMatrix();
	glTranslated(300,20,660);
	glScaled(70,70,80);
	//glRotated(90,0,1,0);
	skybox::drawBedNasser(image,chairs);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-300,20,660);
	glScaled(70,70,80);
	//glRotated(90,0,1,0);
	skybox::drawBedNasser(image,chairs);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-900,20,660);
	glScaled(70,70,80);
	//glRotated(90,0,1,0);
	skybox::drawBedNasser(image,chairs);
	glPopMatrix();	
	glPopMatrix();

	glPushMatrix();
	glTranslated(1200,20,660);
	glScaled(50,50,50);
	glRotated(90,0,1,0);
	skybox::drawCabinNasser(image);
	glPopMatrix();

	glPushMatrix();
	glTranslated(-980,20,660);
	glScaled(50,50,50);
	glRotated(90,0,1,0);
	skybox::drawCabinNasser(image);
	glPopMatrix();	
	glPopMatrix();
}


int DrawGLScene(GLvoid)									// Here's Where We Do All The Drawing
{	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslated(0, 0, -15);
	Camera();
	moveDoor();


	glPushMatrix();
	skybox::skyboxfirst(12000,4000,8000,winback,winleft,winright,winfront,wintop,winbottm);
	glPopMatrix();

	glPushMatrix();
	glTranslated(24300,0,0);
	skybox::skyboxsecond(12000,4000,8000,springfront,springback,springright,sringleft,springtop,springbottm);
	glPopMatrix();
	glPushMatrix();
	glTranslated(49000,0,0);
	skybox::skyboxsecond(12000,4000,8000,autfront,autback,autright,autleft,auttop,grass);
	glPopMatrix();
	glPushMatrix();
	
	glPushMatrix();

	glRotated(90, 0, 1, 0);
	glPushMatrix();
	glTranslated(0, -3950, -0);
	skybox::test1(300, 1.5, 11000, iron, ironwall);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -3950, 24000);
	skybox::test1(300, 1.5, 13000, iron, ironwall);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -3950, 50000);
	skybox::test1(300, 1.5, 13000, iron, ironwall);
	glPopMatrix();
	glPopMatrix();
	


	//the first 
	glPushMatrix();
	glTranslated(-8000,-3930,-310);
	firstTrain();
	glPopMatrix();

	//the second
	glPushMatrix();	
	glTranslated(-4700,-3930,-310);
	secondTrin();
	glPopMatrix();

	///the third
	glPushMatrix();
	glTranslated(-1400,-3930,-310);
	skybox::Draw_third_trian(1800,1000,700,image,ironwall,chairs,door,zdoor2,xdoor1);
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
