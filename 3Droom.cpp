
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#include <Windows.h>

/* Global Variables */
//Light_0
GLfloat light_pos0[] = { 50, 50, 150, 1 };
GLfloat light_dir0[] = { 0, 0, -1 };
GLfloat light_cutoff0 = 30;
GLfloat light_amb0[] = { 0.5,0.5,0.5,1.0 };
GLfloat light_dif0[] = { 0.5,0.5,0.5,1.0 };
GLfloat light_spc0[] = { 0.8,0.8,0.8,1.0 };

//Light_1
GLfloat light_pos1[] = { 1, 99, 100, 1 };
GLfloat light_dir1[] = { 0.8, -1, -0.08 };
GLfloat light_cutoff1 = 10;
GLfloat light_amb1[] = { 0.8,0.2,0.2,1.0 };
GLfloat light_dif1[] = { 0.8,0.2,0.2,1.0 };
GLfloat light_spc1[] = { 1.0, 1.0,  1.0, 1.0 };

//Light_2
GLfloat light_pos2[] = { 25, 65, 21 ,1 };
GLfloat light_dir2[] = { 0.0, 0.0, 100 };
GLfloat light_cutoff2 = 180;
GLfloat light_amb2[] = { 0.5,0.5,0.5,1.0 };
GLfloat light_dif2[] = { 0.5,0.5,0.5,1.0 };
GLfloat light_spc2[] = { 0.8,0.8,0.8,1.0 };

static int cubeSize = 18;
static int teaportAngle = 0;
static int icosahedronAngle = 0;
static int teaportRoad = 10;
static int teaportSize = 8;
bool Light_0 = false;
bool Light_1 = false;
bool Light_2 = true;
bool teaportRotate = false;
bool cubeFlag = true;
bool cubeChangeOption = false;
bool icosahedronRotate = false;
bool teaportRoadOption = false;
bool teaportRoadDirection = false;
bool teaportSizeChangeOption = false;
bool teaportSizeDir = false;

void setLight0(bool option)
{
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, light_cutoff0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_amb0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_dif0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_spc0);

	if (option)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);
}

void setLight1(bool option)
{
	glLightfv(GL_LIGHT1, GL_POSITION, light_pos1);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, light_dir1);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, light_cutoff1);
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_amb1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_dif1);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_spc1);

	if (option)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);
}

void setLight2(bool option)
{
	glLightfv(GL_LIGHT2, GL_POSITION, light_pos2);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_dir2);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, light_cutoff2);
	glLightfv(GL_LIGHT2, GL_AMBIENT, light_amb2);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_dif2);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_spc2);

	if (option)
		glEnable(GL_LIGHT2);
	else
		glDisable(GL_LIGHT2);
}

void init(void) // All Setup For OpenGL Goes Here
{
	srand(time(NULL));
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHTING);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
}

void display(void) // Here's Where We Do All The Drawing
{
	// Place light source here
	setLight0(Light_0);
	setLight1(Light_1);
	setLight2(Light_2);

	// Draw walls and objects here
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Back wall
	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(0, 100, 0);
	glEnd();

	//N
	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(2.5, 42, 1);
	glVertex3f(5, 42, 1);
	glVertex3f(5, 77.5, 1);
	glVertex3f(2.5, 77.5, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(17.5, 42, 1);
	glVertex3f(20, 42, 1);
	glVertex3f(20, 77.5, 1);
	glVertex3f(17.5, 77.5, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(5, 77.5, 1);
	glVertex3f(17.5, 77.5, 1);
	glVertex3f(17.5, 80, 1);
	glVertex3f(5, 80, 1);
	glEnd();

	//U
	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(27.5, 44.5, 1);
	glVertex3f(30, 44.5, 1);
	glVertex3f(30, 80, 1);
	glVertex3f(27.5, 80, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(42.5, 44.5, 1);
	glVertex3f(45, 44.5, 1);
	glVertex3f(45, 80, 1);
	glVertex3f(42.5, 80, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(30, 42, 1);
	glVertex3f(42.5, 42, 1);
	glVertex3f(42.5, 44.5, 1);
	glVertex3f(30, 44.5, 1);
	glEnd();

	//A1
	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(52.5, 42, 1);
	glVertex3f(55, 42, 1);
	glVertex3f(55, 60, 1);
	glVertex3f(52.5, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(67.5, 42, 1);
	glVertex3f(70, 42, 1);
	glVertex3f(70, 60, 1);
	glVertex3f(67.5, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glLineWidth(12);
	glBegin(GL_LINES);
	glVertex3f(54, 60, 1);
	glVertex3f(62.5, 80, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glLineWidth(12);
	glBegin(GL_LINES);
	glVertex3f(68.5, 60, 1);
	glVertex3f(61, 80, 1);
	glEnd();

	//A2
	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(77.5, 42, 1);
	glVertex3f(80, 42, 1);
	glVertex3f(80, 60, 1);
	glVertex3f(77.5, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(92.5, 42, 1);
	glVertex3f(95, 42, 1);
	glVertex3f(95, 60, 1);
	glVertex3f(92.5, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(77.5, 57.5, 1);
	glVertex3f(92.5, 57.5, 1);
	glVertex3f(92.5, 60, 1);
	glVertex3f(77.5, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glBegin(GL_QUADS);
	glVertex3f(55, 57.5, 1);
	glVertex3f(67.5, 57.5, 1);
	glVertex3f(67.5, 60, 1);
	glVertex3f(55, 60, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glLineWidth(12);
	glBegin(GL_LINES);
	glVertex3f(79, 60, 1);
	glVertex3f(87.5, 80, 1);
	glEnd();

	glColor3ub(139, 125, 107);
	glLineWidth(12);
	glBegin(GL_LINES);
	glVertex3f(93.5, 60, 1);
	glVertex3f(86, 80, 1);
	glEnd();

	//Left wall
	glColor3ub(238, 232, 205);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 100);
	glVertex3f(0, 100, 100);
	glVertex3f(0, 100, 0);
	glEnd();

	glColor3ub(139, 119, 101);
	glBegin(GL_QUADS);
	glVertex3f(99, 20, 20);
	glVertex3f(99, 20, 80);
	glVertex3f(99, 80, 80);
	glVertex3f(99, 80, 20);
	glEnd();

	glColor3ub(135, 206, 255);
	glBegin(GL_QUADS);
	glVertex3f(99, 24, 24);
	glVertex3f(99, 24, 48);
	glVertex3f(99, 48, 48);
	glVertex3f(99, 48, 24);
	glEnd();

	glColor3ub(135, 206, 255);
	glBegin(GL_QUADS);
	glVertex3f(99, 24, 52);
	glVertex3f(99, 24, 76);
	glVertex3f(99, 48, 76);
	glVertex3f(99, 48, 52);
	glEnd();

	glColor3ub(135, 206, 255);
	glBegin(GL_QUADS);
	glVertex3f(99, 52, 24);
	glVertex3f(99, 52, 48);
	glVertex3f(99, 76, 48);
	glVertex3f(99, 76, 24);
	glEnd();

	glColor3ub(135, 206, 255);
	glBegin(GL_QUADS);
	glVertex3f(99, 52, 52);
	glVertex3f(99, 52, 76);
	glVertex3f(99, 76, 76);
	glVertex3f(99, 76, 52);
	glEnd();

	//Right wall
	glColor3ub(238, 232, 205);
	glBegin(GL_QUADS);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(100, 100, 100);
	glVertex3f(100, 0, 100);
	glEnd();

	//Top wall
	glColor3ub(238, 232, 205);
	glBegin(GL_QUADS);
	glVertex3f(0, 100, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(100, 100, 100);
	glVertex3f(0, 100, 100);
	glEnd();

	//Buttom wall
	glColor3ub(220, 220, 220);
	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 0, 100);
	glVertex3f(0, 0, 100);
	glEnd();

	//Draw Bed
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(205, 179, 139);
	glPushMatrix();
	glTranslatef(25, 20, 24);
	glScalef(10, 4, 2);
	glutSolidCube(5);
	glPopMatrix();
	glTranslatef(25, 5, 60);
	glScalef(10, 2, 14);
	glutSolidCube(5);
	glPopMatrix();

	//Quilt on the Bed
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(240, 255, 255);
	glPushMatrix();
	glTranslatef(25, 20, 40);
	glScalef(6, 2, 8);
	glutSolidCube(6);
	glPopMatrix();

	//Teaport                   
	if (teaportRotate)
	{
		teaportAngle = (teaportAngle + 12) % 360;
	}
	if (teaportRoadOption)
	{
		if (!teaportRoadDirection)
		{
			teaportRoad++;
			if (teaportRoad == 90)
			{
				teaportRoadDirection = !teaportRoadDirection;
			}
		}
		if (teaportRoadDirection)
		{
			teaportRoad--;
			if (teaportRoad == 10)
			{
				teaportRoadDirection = !teaportRoadDirection;
			}
		}
	}
	if (teaportSizeChangeOption)
	{
		if (!teaportSizeDir)
		{
			teaportSize++;
			if (teaportSize == 15)
			{
				teaportSizeDir = !teaportSizeDir;
			}
		}
		if (teaportSizeDir)
		{
			teaportSize--;
			if (teaportSize == 1)
			{
				teaportSizeDir = !teaportSizeDir;
			}
		}
	}
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(238, 197, 145);
	glTranslatef(60, 6, teaportRoad);
	glRotatef(teaportAngle, 0, 1, 0);
	glScalef(1, 1, 1);
	glutSolidTeapot(teaportSize);
	glPopMatrix();
	glFlush();

	//Cube
	if (cubeFlag && cubeChangeOption)
	{
		cubeSize--;
		if (cubeSize == 0)
			cubeFlag = false;
	}
	if (!cubeFlag && cubeChangeOption)
	{
		cubeSize++;
		if (cubeSize == 18)
			cubeFlag = true;
	}
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(238, 203, 173);
	glTranslatef(85, 15, 20);
	glRotatef(0, 1, 1, -1);
	glutSolidCube(cubeSize);
	glPopMatrix();
	glFlush();

	//Toplight
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(255, 255, 240);
	glTranslatef(50, 110, 60);
	glRotatef(0, 1, 1, -1);
	glutSolidCube(36);
	glPopMatrix();
	glFlush();

	//Icosahedron
	if (icosahedronRotate)
	{
		icosahedronAngle = (icosahedronAngle + 8) % 360;
	}
	glPushMatrix();
	glLoadIdentity();
	glColor3ub(139, 131, 120);
	glTranslatef(80, 10, 80);
	glRotatef(icosahedronAngle, 0, 0, 1);
	glScalef(8, 8, 8);
	glutSolidIcosahedron();
	glPopMatrix();
	glFlush();

	glutSwapBuffers();
}

void reshape(int w, int h) // Resize the GL Window. w=width, h=height
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(53, 1, 90, 400.0);
	gluLookAt(50, 50, 200, 50, 50, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y) // Handle the keyboard events here
{
	switch (key)
	{
	case'\033':
		exit(0);
		break;
	case '1':
		Light_0 = !Light_0;
		break;
	case '2':
		Light_1 = !Light_1;
		break;
	case '3':
		Light_2 = !Light_2;
		break;
	case '4':
		teaportRotate = !teaportRotate;
		break;
	case '5':
		cubeChangeOption = !cubeChangeOption;
		break;
	case '6':
		icosahedronRotate = !icosahedronRotate;
		break;
	case '7':
		teaportRoadOption = !teaportRoadOption;
		break;
	case '8':
		teaportSizeChangeOption = !teaportSizeChangeOption;
		break;
	}
}

void idle()
{
	Sleep(10);
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	/*Initialization of GLUT Library */
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	/*Create a window with title specified */
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3Droom");

	init();	/*not GLUT call, initialize several parameters */

	/*Register different CALLBACK function for GLUT to response
	with different events, e.g. window sizing, mouse click or
	keyboard stroke */
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(idle);

	/*Enter the GLUT event processing loop which never returns.
	it will call different registered CALLBACK according
	to different events. */
	glutMainLoop();
}
