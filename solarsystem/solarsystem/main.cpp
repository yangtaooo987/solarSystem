//main.cpp
//solarSystem
#include <GL\glut.h>
#include <stdlib.h>
#include <stdio.h>
#include "solarsystem.hpp"

//����ͼ�δ��ڵĻ�����
#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

SolarSystem solarsystem;

//����ע��Glut�Ļص�
void onDisplay(void){
	solarsystem.onDisplay();
}
void onUpdate(void){
	solarsystem.onUpdate();
}
void onKeyboard(unsigned char key, int x, int y){
	solarsystem.onKeyboard(key,x,y);
}


int main(int argc, char *argv[])

{
	//��ʼ��
	glutInit(&argc, argv);
	//��ʾģʽ
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//����λ��
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	//���ڳߴ�
	glutInitWindowSize(WIDTH, HEIGHT);
	//�������ڣ����ڱ���Ϊ��FirstOpenGLProgram��
	glutCreateWindow("SolarSystem virtual");
	//���ƻص�����
	glutDisplayFunc(onDisplay);

	glutIdleFunc(onUpdate);

	glutKeyboardFunc(onKeyboard);

	glutMainLoop();

	getchar();

	return 0;

}