//stars.cpp
//solarsystem

#include "stars.hpp"

#define PI 3.1415926535

Star::Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star* parenStar){
//TODO;
};

void Star::drawStar(){
	//TODO:
}

void Star::update(long timeSpan){

}

Planet::Planet(GLfloat radius,GLfloat distance,GLfloat speed,GLfloat selfSpeed,Star* parentStar,GLfloat rgbColor[3]):

Star(radius,distance,speed,selfSpeed,parentStar){

}

void Planet::drawPlanet(){

}

LightPlanet::LightPlanet(GLfloat radius,GLfloat distance,GLfloat speed,GLfloat selfSpeed,Star* parentStar,GLfloat rgbColor[3]):
Planet(radius,distance,speed,selfSpeed,parentStar,rgbColor){

}

void LightPlanet::drawLight(){

}

