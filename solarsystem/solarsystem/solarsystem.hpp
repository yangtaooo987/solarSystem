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
	Mercury,//ˮ��
	Venus,//����
	Earth,//����
	Moon,//����
	Mars,//����
	Jupiter,//ľ��
	Saturn,//����
	Uranus,//������
	Nepture//������
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

	//����۲��ӽǵĲ���
	GLdouble viewX,viewY, viewZ;
	GLdouble centerX, centerY, centerZ;
	GLdouble upX, upY, upZ;
};

#endif SOLARSYSTEM_HPP