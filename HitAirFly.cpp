#include <gl/glut.h>
#include <windows.h>
#include <list>
#include <time.h>
#include <iostream>
using namespace std;

class PositionList 
{
public:
	int x = 0;
	int y = 0;
	PositionList()
	{
		x = 0;
		y = 0;
	}
	PositionList(int xx, int yy)
	{
		x = xx;
		y = yy;
	}
};

list<PositionList> shellList, enemyList;
list<PositionList>::iterator iList, jList, kList;
int planePosX = 475;
int planePosY = 50;

void drawShellList(list<PositionList> &list)
{
	for (iList = list.begin(); iList != list.end(); iList++)
	{
		int x = iList->x;
		int y = iList->y;
		glPointSize(10);
		glColor3ub(100, 255, 100);
		glBegin(GL_POINTS);
		{
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
}

void drawEnemyList(list<PositionList> &list)
{
	for (iList = list.begin(); iList != list.end(); iList++)
	{
		int x = iList->x;
		int y = iList->y;
		glColor3ub(100, 100, 255);
		glBegin(GL_TRIANGLES);
		{
			glVertex2f(x, y);
			glVertex2f(x + 20, y + 20);
			glVertex2f(x - 20, y + 20);
		}
		glEnd();
		glColor3ub(255, 100, 100);
		glPointSize(10);
		glBegin(GL_POINTS);
		{
			glVertex2f(x, y);
		}
		glEnd();
	}
	glFlush();
}

void changeShellList(list<PositionList> &list)
{
	for (iList = list.begin(); iList != list.end(); iList++)
	{
		iList->y += 10;
	}
}

void changeEnemyList(list<PositionList> &list)
{
	for (iList = list.begin(); iList != list.end(); iList++)
	{
		iList->y -= 6;
	}
}

void drawPlane()
{
	for (iList = enemyList.begin(); iList != enemyList.end(); iList++)
	{
		glColor3f(0, 1, 0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex2f(planePosX, planePosY);
			glVertex2f(planePosX + 50, planePosY);
			glVertex2f(planePosX + 50, planePosY + 50);
			glVertex2f(planePosX + 25, planePosY + 75);
			glVertex2f(planePosX, planePosY + 50);
		}
		glEnd();
		glColor3f(1, 0, 0);
		glBegin(GL_TRIANGLE_FAN);
		{
			glVertex2f(planePosX - 25, planePosY);
			glVertex2f(planePosX + 75, planePosY);
			glVertex2f(planePosX + 50, planePosY + 30);
			glVertex2f(planePosX, planePosY + 30);
		}
		glEnd();
		glFlush();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_ACCUM_BUFFER_BIT);
	drawPlane();
	drawShellList(shellList);
	drawEnemyList(enemyList);
}

void reshape(int x, int y)
{
	glViewport(0, 0, x, y);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '\033':
		exit(0);
		break;
	case ' ':
		shellList.push_back(PositionList(planePosX + 25, planePosY + 75));
		break;
	}
}

void specialkey(GLint key, GLint x, GLint y) 
{
	if (key == GLUT_KEY_LEFT)
	{
		planePosX -= 20;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		planePosX += 20;
	}
	if (key == GLUT_KEY_UP)
	{
		planePosY += 20;
	}
	if (key == GLUT_KEY_DOWN)
	{
		planePosY -= 20;
	}
}

inline bool disCalc(list<PositionList>::iterator &s1, list<PositionList>::iterator &s2, int r)
{
	int x1 = s1->x, y1 = s1->y;
	int x2 = s2->x, y2 = s2->y;
	float dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	return dis < r;
}

void checkFunction()
{
	for (iList = shellList.begin(); iList != shellList.end(); iList++)
	{
		for (jList = enemyList.begin(); jList != enemyList.end(); jList++)
		{
			if (disCalc(iList, jList, 10))
			{
				jList = enemyList.erase(jList);
				iList = shellList.erase(iList);
			}
			if (jList == enemyList.end())
			{
				break;
			}
		}
		if (iList == shellList.end())
		{
			break;
		}
	}
}

void idle()
{
	static int createTime = 100;
	createTime--;
	if (createTime == 0) 
	{
		createTime = 100;
		enemyList.push_back(PositionList(rand() % 1000, 1000));
	}
	Sleep(10);
	changeEnemyList(enemyList);
	changeShellList(shellList);
	checkFunction();
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	srand(time(0));
	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("HitAirFly");
	glClearColor(0, 0, 0, 0);
	gluOrtho2D(0, 1000, 0, 1000);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkey);
	glutIdleFunc(idle);
	glutMainLoop();
	return 0;
}
