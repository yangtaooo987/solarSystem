#ifndef STARS_HPP
#define STARS_HPP


#include <GL/glut.h>

// class Star
class Star{
public:
	//�뾶
	GLfloat radius;
	//����Ĺ�ת����ת
	GLfloat speed, selfSpeed;
	//��������ľ�͸��ڵ��������ĵľ���
	GLfloat distance;
	//�������ɫ
	GLfloat rgbaColor[4];

	//���ڵ�����
	Star * parentStar;

	//���캯��
	Star(GLfloat radius,GLfloat distance,GLfloat speed,GLfloat selfSpeend,
		Star* parentStar);

	//��������
	void drawStar();

	//�ṩĬ�ϻ�ͼʵ��
	virtual void draw(){ drawStar(); }
	//����ˢ��ʱ��
	virtual void update(long timeSpan);

protected:
	GLfloat alphaSelf, alpha;
};

class Planet : public Star{
public:
	Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parentStar,
		GLfloat rgbColor[3]);
	//���Ӷ��������еĻ��Ʋ���
	void drawPlanet();
	//��д�·���
	virtual void draw(){ drawPlanet(); drawStar(); }
};

//�ṩ��Դ�ĺ���
class LightPlanet :public Planet{
public:
	LightPlanet(GLfloat Radius, GLfloat Distance, GLfloat speed, GLfloat selfSpeed, Star* parentStar,
		GLfloat rgbColor[]);
	//���ƹ���
	void drawLight();
	virtual void draw(){ drawLight(); drawPlanet(); drawStar(); }
};

#endif STARS_HPP















