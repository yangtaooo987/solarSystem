//main.cpp
//solarSystem
#include <GL\glut.h>
#include "solarsystem.hpp"

//创建图形窗口的基本宏
#define WINDOW_X_POS 50
#define WINDOW_Y_POS 50
#define WIDTH 700
#define HEIGHT 700

//用于注册Glut的回调
void onDisplay(void);
void onUpdate(void);
void onKeyboard(unsigned char key, int x, int y);


int main(int argc, char *argv[])

{
	//初始化
	glutInit(&argc, argv);
	//显示模式
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	//窗口位置
	glutInitWindowPosition(WINDOW_X_POS, WINDOW_Y_POS);
	//窗口尺寸
	glutInitWindowSize(WIDTH, HEIGHT);
	//创建窗口，窗口标题为“FirstOpenGLProgram”
	glutCreateWindow("SolarSystem virtual");
	//绘制回调函数
	glutDisplayFunc(onDisplay);

	glutIdleFunc(onUpdate);

	glutKeyboardFunc(onKeyboard);

	glutMainLoop();

	return 0;

}