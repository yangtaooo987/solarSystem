//solarsystem.hpp

#ifndef SOLARSYSTEM_HPP
#define SOLARSYSTEM_HPP

#include "stars.hpp"

//define STARS PARA
#define STARS_NUM 10

//set selfSpeed
#define TIMEPAST 1
#define SELFROTATE 3
enum STARS{
	Sun,
	Mercury,//水星
	Venus,//金星
	Earth,//地球
	Moon,//月亮
	Mars,//火星
	Jupiter,//木星
	Saturn,//土星
	Uranus,//天王星
	Nepture//海王星
};

class SolarSystem{
public:
	SolarSystem();
	~SolarSystem();

	void onDisplay();
	void onUpdate();
	void onKeyboard(unsigned char key,int x,int y);

private:
	Star *stars[STARS_NUM];

	//定义观察视角的参数
	GLdouble viewX,viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};

#endif SOLARSYSTEM_HPP