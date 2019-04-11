#include <gl/glut.h>
#include <windows.h>
#include <list>
#include <time.h>
#include <iostream>
using namespace std;
#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

class Pillar
{
public:
	int value = 0;
	int pos = 0;
	bool isJudgePillar = true;
	Pillar()
	{
		value = 0;
		pos = 0;
	}
	Pillar(int x, int y)
	{
		value = x;
		pos = y;
	}
};

list<Pillar> pillarList;
list<Pillar>::iterator iList, jList;
int gap = 250;
int jump = 0;
int pillarSpeed = 60;
float dropSpeed = 0;

void drawMe()
{
	glColor3ub(240, 255, 240);
	glBegin(GL_QUADS);
	glVertex2f(250, 275 + jump);
	glVertex2f(300, 275 + jump);
	glVertex2f(300, 325 + jump);
	glVertex2f(250, 325 + jump);
	glEnd();
	glColor3f(1, 0, 0);
	glBegin(GL_TRIANGLES);
	glVertex2f(300, 325 + jump);
	glVertex2f(320, 315 + jump);
	glVertex2f(300, 300 + jump);
	glEnd();
	glColor3f(0, 0, 0);
	glPointSize(12);
	glBegin(GL_POINTS);
	{
		glVertex2f(285, 310 + jump);
	}
	glEnd();
}

void drawPillar()
{
	for (iList = pillarList.begin(); iList != pillarList.end(); iList++)
	{
		glColor3ub(119, 136, 153);
		glBegin(GL_QUADS);
		glVertex2f(iList->pos, 0);
		glVertex2f(iList->pos + 75, 0);
		glVertex2f(iList->pos + 75, 600 - iList->value - gap);
		glVertex2f(iList->pos, 600 - iList->value - gap);
		glEnd();
		glColor3ub(54, 54, 54);
		glBegin(GL_QUADS);
		glVertex2f(iList->pos - 10, 600 - iList->value - gap);
		glVertex2f(iList->pos + 85, 600 - iList->value - gap);
		glVertex2f(iList->pos + 85, 600 - iList->value - gap + 20);
		glVertex2f(iList->pos - 10, 600 - iList->value - gap + 20);
		glEnd();
		glColor3ub(119, 136, 153);
		glBegin(GL_QUADS);
		glVertex2f(iList->pos, 600 - iList->value);
		glVertex2f(iList->pos + 75, 600 - iList->value);
		glVertex2f(iList->pos + 75, 600);
		glVertex2f(iList->pos, 600);
		glEnd();
		glColor3ub(54, 54, 54);
		glBegin(GL_QUADS);
		glVertex2f(iList->pos - 10, 600 - iList->value);
		glVertex2f(iList->pos + 85, 600 - iList->value);
		glVertex2f(iList->pos + 85, 600 - iList->value + 20);
		glVertex2f(iList->pos - 10, 600 - iList->value + 20);
		glEnd();
	}
}

inline void movePillar()
{
	for (iList = pillarList.begin(); iList != pillarList.end(); iList++)
	{
		iList->pos -= 6;
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
	drawMe();
	drawPillar();
	glFlush();
}

inline void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
}

void mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		dropSpeed = 10;
	}
}

void checkPillarBird()
{
	for (iList = pillarList.begin(); iList != pillarList.end(); iList++)
	{
		if (iList->pos <= 300 && iList->isJudgePillar == true)
		{
			if ((275 + jump) < (600 - iList->value - gap + 20) || (325 + jump) > (600 - iList->value) || jump < -275)
			{
				MessageBox(0, TEXT("TRY AGAIN ?"), TEXT("GAME OVER"), MB_OK);
				pillarList.clear();
				jump = 0;
				return;
			}
		}
		if (iList->pos <= 125)
		{
			iList->isJudgePillar = false;
		}
	}
}

void birdMove()
{
	jump += dropSpeed;
	dropSpeed -= 0.8;
}

void idle()
{
	static int createTime = pillarSpeed;
	createTime--;
	if (createTime == 0)
	{
		createTime = pillarSpeed;
		pillarList.push_back(Pillar(rand() % (600 - gap), 900));
	}
	Sleep(10);
	birdMove();
	movePillar();
	checkPillarBird();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	srand(time(0));
	pillarList.push_back(Pillar(100, 900));
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HappyBird");
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, 1000, 0, 600);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
