#pragma once
#include "Point.h"

class skybox
{
public:
	static void skyboxfirst(int x ,int y , int z ,int front , int back ,int left , int right , int top ,int bottm);
	static void skyboxsecond(int x ,int y , int z ,int front , int back ,int left , int right , int top ,int bottm);
	static void Draw_train(int image,int x, int y,int z ,int zdoor2 ,int door,int xdoor1);
	static void Draw_train_two();
	static void DrawSeat();
	static void DrawSmallSeat();
	static void DrawChairsBracket();
	static void DrawChairs();
	static void train();
	static void TV();
	static void drawBox4(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void drawBox2(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6,int image7,int image8);
	static void drawBox3(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void chair();
	static void drowhead();

	
};

