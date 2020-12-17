#ifndef STARS_HPP
#define STARS_HPP


#include <GL/glut.h>

// class Star
class Star{
public:
	//半径
	GLfloat radius;
	//星球的公转和自转
	GLfloat speed, selfSpeed;
	//星球的中心距和父节点星球中心的距离
	GLfloat distance;
	//星球的颜色
	GLfloat rgbaColor[4];

	//父节点星球
	Star * parentStar;

	//构造函数
	Star(GLfloat radius,GLfloat distance,GLfloat speed,GLfloat selfSpeend,
		Star* parentStar);

	//绘制星球
	void drawStar();

	//提供默认画图实现
	virtual void draw(){ drawStar(); }
	//参数刷新时间
	virtual void update(long timeSpan);

protected:
	GLfloat alphaSelf, alpha;
};

class Planet : public Star{
public:
	Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parentStar,
		GLfloat rgbColor[3]);
	//增加对行星特有的绘制材料
	void drawPlanet();
	//重写新方法
	virtual void draw(){ drawPlanet(); drawStar(); }
};

//提供光源的恒星
class LightPlanet :public Planet{
public:
	LightPlanet(GLfloat Radius, GLfloat Distance, GLfloat speed, GLfloat selfSpeed, Star* parentStar,
		GLfloat rgbColor[]);
	//绘制光照
	void drawLight();
	virtual void draw(){ drawLight(); drawPlanet(); drawStar(); }
};

#endif STARS_HPP















