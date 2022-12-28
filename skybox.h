#pragma once
#include "Point.h"

class skybox
{
public:
	static void skyboxfirst(int x ,int y , int z ,int front , int back ,int left , int right , int top ,int bottm);
	static void skyboxsecond(int x ,int y , int z ,int front , int back ,int left , int right , int top ,int bottm);
	static void Draw_train(int image,int x, int y,int z ,int zdoor2 ,int door,int xdoor1);
	static void Draw_train_two(int image,int x, int y,int z ,int zdoor2 ,int door,int xdoor1);
	static void Draw_third_trian(int x,int y,int z,int image,int wood ,int chairs,int door,int zdoor2 ,int xdoor1);
	static void DrawSeat(int chairs,int x,int y,int z);
	static void DrawSmallSeat();
	static void DrawChairsBracket();
	static void Wheel(Point center, float radius);
	static void test1(float width, float hight, float depth,int iron,int wall);
	static void wheels(float distance, float width, Point center, float radius);
	static void test(float width, float hight, float depth ,int wall);
	static void drawcube(float x, float y, float z, int texture, int isInside);
	static void bed(float WIDTH, float HIGHT, float DEPTH, int textureLeg, int TextureBed);

	static void drawBoxNasser(double x ,double y , double z , int imagePicked );
	static void drawCabinNasser(int wood1);
	static void drawTableNasser(int wood1);
	static void drawCoachNasser (int wood1,int chairs);
	static void drawBedNasser(int wood1,int chairs);

	

	static void DrawChairs();
	static void train();
	static void TV();
	static void drawBox4(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void drawBox2(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6,int image7,int image8);
	static void drawBox3(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void chair();
	static void drowhead();

	
};

