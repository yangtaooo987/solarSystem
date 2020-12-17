//solarsystem.hpp

#ifndef SOLARSYSTEM_HPP
#define SOLARSYSTEM_HPP

#include "stars.hpp"

// 公转半径
#define SUN_RADIUS 48.74
#define MER_RADIUS  7.32
#define VEN_RADIUS 18.15
#define EAR_RADIUS 19.13
#define MOO_RADIUS  6.15
#define MAR_RADIUS 10.19
#define JUP_RADIUS 42.90
#define SAT_RADIUS 36.16
#define URA_RADIUS 25.56
#define NEP_RADIUS 24.78

// 距太阳的距离
#define MER_DIS   62.06
#define VEN_DIS  115.56
#define EAR_DIS  168.00
#define MOO_DIS   26.01
#define MAR_DIS  228.00
#define JUP_DIS  333.40
#define SAT_DIS  428.10
#define URA_DIS 848.00
#define NEP_DIS 949.10

// 运动速度
#define MER_SPEED   87.0
#define VEN_SPEED  225.0
#define EAR_SPEED  365.0
#define MOO_SPEED   30.0
#define MAR_SPEED  687.0
#define JUP_SPEED 1298.4
#define SAT_SPEED 3225.6
#define URA_SPEED 3066.4
#define NEP_SPEED 6014.8

//define STARS PARA
#define STARS_NUM 10

//set selfSpeed
#define TIMEPAST 1
#define SELFROTATE 3

#define SET_VALUE_3(name,value0,value1,value2)\
	((name)[0])=(value0),((name)[1])=(value1),((name)[2])=(value2)

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
	Neptune//海王星
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