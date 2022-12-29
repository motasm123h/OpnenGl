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
	static void table_for_playstation_room(int x,int y ,int z,int tbale_texture,int iron,int cris);
	

	static void DrawChairs();
	static void train();
	static void TV();
	static void drawBox4(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void drawBox2(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6,int image7,int image8);
	static void drawBox3(float x,float y,float z,int image1,int image2,int image3,int image4,int image5,int image6);
	static void chair();
	static void drowhead();

	
};

class bed_room{

	public:
    static void table(int wood);
	static void  draw_cupboard(int wood,int x1,int x2,int y1,int y2,int z1,int z2);
	static void draw_bed(int bed_cover,int wood,int x1,int x2,int y1,int y2,int z1,int z2,int bed_front,int bed_back);
	static void draw_wardrope(int door,int wood,int x1,int x2,int y1,int y2,int z1,int z2);
    static void  drawbox(int cupboard,int wood,int x1,int x2,int y1,int y2,int z1,int z2);
	static void drawradio(int radio,int wood,int x1,int x2,int y1,int y2,int z1,int z2);
	static void draw_library(int book,int wood,int x1,int x2,int y1,int y2,int z1,int z2);
	static void carpett(int carpet,int x1,int x2,int z1,int z2);
	static void draw_paintig(int paint,int x1,int y1,int y2,int z1,int z2);
	static void draw_chair(int wood);
	static void draw_table(int wood);
	static void draw_bedroom(int wood,int bed_cover,int door,int cupboard,int radio,int book,int carpet,int paint);
};
