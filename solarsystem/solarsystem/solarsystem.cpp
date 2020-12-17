//solarsystem

#include "solarsystem.hpp"
#include <stdlib.h>

#define REST 700
#define REST_Z (REST)
#define REST_Y (-REST)

#define OFFSET 20

void SolarSystem::onDisplay(){

	//���viewport������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//���������ɫ����
	glClearColor(.7f,.7f,.7f,.1f);
	//ָ����ǰ����ΪͶӰ����
	glMatrixMode(GL_PROJECTION);
	//��ָ���ľ���ָ��Ϊ��λ����
	glLoadIdentity();
	//ָ����ǰ�Ĺ۲��Ӿ���
	gluPerspective(75.0f,1.0f,1.0f,400000000);
	//
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(viewX,viewY,viewZ,centerX,centerY,centerZ,upX,upY,upZ);

	//���õ�һ����Դ
	glEnable(GL_LIGHT0);
	//���ù�Դ
	glEnable(GL_LIGHTING);
	//������Ȳ���
	glEnable(GL_DEPTH_TEST);

	//��������
	for (int i = 0; i < STARS_NUM;i++){
		stars[i]->draw();
	}

	//ʵ��˫����Ļ���������
	glutSwapBuffers();

}

void SolarSystem::onUpdate(){
	for (int i = 0; i < STARS_NUM;i++){
		stars[i] ->update(TIMEPAST);//���������λ��
	}
	this->onDisplay();//ˢ����ʾ

}

void SolarSystem::onKeyboard(unsigned char key,int x,int y){
	switch(key){
	
		case 'w':viewY += OFFSET; break;
		case 's':viewZ += OFFSET; break;
		case 'S':viewZ -= OFFSET; break;
		case 'a':viewX -= OFFSET; break;
		case 'd':viewX += OFFSET; break;
		case 'x':viewY -= OFFSET; break;
		case 'r':
			viewX = 0; viewY = REST_Y; viewZ = REST_Z;
			centerX = centerY = centerZ = 0;
			upX = upY = 0; upZ = 1;
			break;
		case 27:exit(0); break;
		default:break;

	}

}

SolarSystem::SolarSystem(){
	//�����ӽ�
	viewX = 0;
	viewY = REST_Y;
	viewZ = REST_Z;
	centerX = centerY = centerZ = 0;
	upX = upY = 0;
	upZ = 1;

	//̫��
	GLfloat rgbColor[3] = { 1, 0, 0 };
	stars[Sun] = new LightPlanet(SUN_RADIUS,0,0,SELFROTATE,0,rgbColor);
	//ˮ��
	SET_VALUE_3(rgbColor, .2, .2, .5);
	stars[Sun] = new Planet(MER_RADIUS,MER_DIS,MER_SPEED,SELFROTATE,stars[Sun],rgbColor);
	// ����
	SET_VALUE_3(rgbColor, 1, .7, 0);
	stars[Venus] = new Planet(VEN_RADIUS, VEN_DIS, VEN_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ����
	SET_VALUE_3(rgbColor, 0, 1, 0);
	stars[Earth] = new Planet(EAR_RADIUS, EAR_DIS, EAR_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ����
	SET_VALUE_3(rgbColor, 1, 1, 0);
	stars[Moon] = new Planet(MOO_RADIUS, MOO_DIS, MOO_SPEED, SELFROTATE, stars[Earth], rgbColor);
	// ����
	SET_VALUE_3(rgbColor, 1, .5, .5);
	stars[Mars] = new Planet(MAR_RADIUS, MAR_DIS, MAR_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ľ��
	SET_VALUE_3(rgbColor, 1, 1, .5);
	stars[Jupiter] = new Planet(JUP_RADIUS, JUP_DIS, JUP_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ����
	SET_VALUE_3(rgbColor, .5, 1, .5);
	stars[Saturn] = new Planet(SAT_RADIUS, SAT_DIS, SAT_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ������
	SET_VALUE_3(rgbColor, .4, .4, .4);
	stars[Uranus] = new Planet(URA_RADIUS, URA_DIS, URA_SPEED, SELFROTATE, stars[Sun], rgbColor);
	// ������
	SET_VALUE_3(rgbColor, .5, .5, 1);
	stars[Neptune] = new Planet(NEP_RADIUS, NEP_DIS, NEP_SPEED, SELFROTATE, stars[Sun], rgbColor);
}

SolarSystem::~SolarSystem(){
	for (int i = 0; i < STARS_NUM;i++){
		delete stars[i];
	}
}