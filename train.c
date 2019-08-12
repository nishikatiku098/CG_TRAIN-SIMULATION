#include<GL/glut.h>
#include<Math.h>
#include<stdio.h>
#include<string.h>
#define pi 3.14
GLint i, j, win = 0;
GLfloat angle, xpos = 1300, anglenew = 45, ypos = 1300;
void sky()
{
	glBegin(GL_QUADS);
	glVertex2f(0, 550);
	glVertex2f(1300, 550);
	glColor3f(0.8, 0.5, 0.7);
	glVertex2f(1300, 1300);
	glVertex2f(0, 1300);
	glEnd();
	glFlush();
}
void road()
{
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(1300, 0);
	glColor3f(0.7, 0.9, 0);
	glVertex2f(1300, 550);
	glVertex2f(0, 550);
	glEnd();
	glFlush();
}
void circle(float x, float y, float r)  /*for wheels*/
{
	/*creating object*/
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0; angle <= 2 * pi; angle += 0.1)
	{
		glVertex2f((x + (r) * cos(angle)), (y + (r) * sin(angle)));
	}
	glEnd();
	glFlush();

	/*creating object outline*/
	glPointSize(3.0);
	glColor3f(0, 0, 0);
	glBegin(GL_POINTS);
	for (angle = 0; angle <= 2 * pi; angle += 0.2)
	{
		glVertex2f((x + r * cos(angle)), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();
}
void circle_en(float x, float y, float r) /*engine front bulge*/
{
	/*creating object*/
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0; angle <= 2 * pi; angle += 0.1)
	{
		glVertex2f((x + r * cos(angle) + xpos), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();

	/*creating object outline*/
	glColor3f(0, 0, 0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	for (angle = 0; angle <= 2 * pi; angle += 0.0001)
	{
		glVertex2f((x + r * cos(angle) + xpos), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();
}
void semicircle(float x, float y, float r)/*engine top semicircle*/
{
	/*creating object*/
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0; angle <= pi; angle += 0.1)
	{
		glVertex2f((x + r * cos(angle) + xpos), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();

	/*creating object outline*/
	glColor3f(0, 0, 0);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	for (angle = 0; angle <= pi; angle += 0.0001)
	{
		glVertex2f((x + r * cos(angle) + xpos), (y + r * sin(angle)));
	}
	glEnd();
	glFlush();
}
void elec()/*outline for electric wire*/
{
	glBegin(GL_LINES);
	glVertex2f(1300, 1000);
	glVertex2f(0, 1000);
	glVertex2f(1300, 1100);
	glVertex2f(0, 1100);
	glEnd();
	glFlush();

}
void elecline()/*electric wire*/
{
	glBegin(GL_LINES);
	glVertex2f(500 + xpos, 900);/*vertical line originating from engine top*/
	glVertex2f(500 + xpos, 970);

	glVertex2f(500 + xpos, 970);/*slant line 1*/
	glVertex2f(600 + xpos, 1100);

	glVertex2f(600 + xpos, 1100);/*slant line 2*/
	glVertex2f(590 + xpos, 1000);

	glVertex2f(590 + xpos, 1000);/*slant line 3*/
	glVertex2f(500 + xpos, 970);

	glEnd();
	glFlush();

}
void track()/*railway track outline*/
{
	glBegin(GL_LINES);
	glVertex2f(0, 350);
	glVertex2f(1300, 350);
	glVertex2f(1300, 600);
	glVertex2f(0, 600);
	glEnd();
	glFlush();
}
void slant(float x, float y)/*slant lines for railway track */
{
	glBegin(GL_LINES);
	glVertex2f(0 + x, 340 + y);
	glVertex2f(100 + x,610 + y);
	glEnd();
	glFlush();
}
void window(float x, float y)/*window for bogies*/
{
	/*creating object*/
	glBegin(GL_QUADS);
	glVertex2f(920 - x + xpos, 720 - y);
	glVertex2f(1000 - x + xpos, 720 - y);
	glColor3f(1, 1, 1);
	glVertex2f(1000 - x + xpos, 600 - y);
	glVertex2f(920 - x + xpos, 600 - y);
	glEnd();
	glFlush();

	/*creating object outline*/
	glLineWidth(2.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(920 - x + xpos, 720 - y);
	glVertex2f(1000 - x + xpos, 720 - y);
	glVertex2f(1000 - x + xpos, 600 - y);
	glVertex2f(920 - x + xpos, 600 - y);
	glEnd();
	glFlush();
}
void windowe()/*window for engine*/
{
	/*creating object*/
	glBegin(GL_QUADS);
	glVertex2f(460 + xpos, 750);
	glVertex2f(540 + xpos, 750);
	glColor3f(1, 1, 1);
	glVertex2f(540 + xpos, 850);
	glVertex2f(460 + xpos, 850);
	glEnd();
	glFlush();

	/*creating object outline*/
	glLineWidth(2.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(460 + xpos, 750);
	glVertex2f(540 + xpos, 750);
	glVertex2f(540 + xpos, 850);
	glVertex2f(460 + xpos, 850);
	glEnd();
	glFlush();
}
void small_recte()/*bottom line for engine*/
{
	glBegin(GL_QUADS);
	glVertex2f(307 + xpos, 400);
	glVertex2f(450 + xpos, 400);
	glVertex2f(450 + xpos, 410);
	glVertex2f(307 + xpos, 410);
	glEnd();
	glFlush();
}
void small_rect(float x, float y)/* bottom line for bogies*/
{
	glBegin(GL_QUADS);
	glVertex2f(895 - x + xpos, 410 - y);
	glVertex2f(1205 - x + xpos, 410 - y);
	glVertex2f(1205 - x + xpos, 400 - y);
	glVertex2f(895 - x + xpos, 400 - y);
	glEnd();
	glFlush();
}
void draw_engine()
{
	/*creating object*/
	glBegin(GL_QUADS);
	glVertex2f(450 + xpos, 400);
	glVertex2f(550 + xpos, 400);
	glVertex2f(550 + xpos, 855);
	glVertex2f(450 + xpos, 855);
	glEnd();
	glBegin(GL_QUADS);
	glVertex2f(345 + xpos, 400);
	glVertex2f(550 + xpos, 400);
	glVertex2f(550 + xpos, 750);
	glVertex2f(345 + xpos, 750);
	glEnd();
	glFlush();

	/*creating object outline*/
	glLineWidth(2.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(345 + xpos, 400);
	glVertex2f(550 + xpos, 400);

	glVertex2f(550 + xpos, 400);
	glVertex2f(550 + xpos, 855);

	glVertex2f(345 + xpos, 750);
	glVertex2f(450 + xpos, 750);

	glVertex2f(450 + xpos, 750);
	glVertex2f(450 + xpos, 855);

	glEnd();
	glFlush();


}
void draw_bogie(float x, float y)
{
	/*creating object*/
	glBegin(GL_QUADS);
	glVertex2f(900 - x + xpos, 750 - y);
	glVertex2f(1200 - x + xpos, 750 - y);
	glVertex2f(1200 - x + xpos, 400 - y);
	glVertex2f(900 - x + xpos, 400 - y);
	glEnd();
	glFlush();

	/*creating object outline*/
	glLineWidth(2.0);
	glColor3f(0, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(900 - x + xpos, 750 - y);
	glVertex2f(1200 - x + xpos, 750 - y);
	glVertex2f(1200 - x + xpos, 400 - y);
	glVertex2f(900 - x + xpos, 400 - y);
	glEnd();
	glFlush();
}
void draw_con_line(float x, float y)/* connecting line for engine and bogies , bogies and bogies*/
{
	glLineWidth(15);
	glBegin(GL_LINES);
	glVertex2f(875 - x + xpos, 430 - y);
	glVertex2f(900 - x + xpos, 430 - y);
	glEnd();
	glFlush();
}
void rain()
{
	glPointSize(3);
	glBegin(GL_POINTS);
	for (i = 10; i <= 2000; i += 50)
	{
		for (j = -10000; j <= 90000; j += 100)
		{
			{
				glVertex2f(i, j);
				glVertex2f(i + 10, j + 10);
			}
		}
	}
	glEnd();

	glBegin(GL_POINTS);
	for (i = 10; i <= 2000; i += 35)
	{
		for (j = -10000; j <= 90000; j += 60)
		{
			glVertex2f(i, j);
			glVertex2f(i + 20, j + 20);
		}
	}

	glEnd();
	glFlush();
}
void translate()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	for (i = 0; i <= 2000; i += 25)
	{
		for (j = 0; j <= 90000; j += 50)
		{
			glTranslatef(i, j, 0);/*moving to origin*/
			glTranslatef(0, 0 + ypos, 0); /*translating*/
			glTranslatef(-i, -j, 0);/*moving to original position*/
			rain();
		}
	}
	for (i = 0; i <= 2000; i += 35)
	{
		for (j = 0; j <= 90000; j += 60)
		{
			glTranslatef(i, j, 0);/*moving to origin*/
			glTranslatef(0, 0 + ypos, 0); /*translating*/
			glTranslatef(-i, -j, 0);/*moving to original position*/
			rain();
		}
	}
	glPopMatrix();

}
void train()
{
	glColor3f(0, 0.4, 0.7);
	sky();/* sky */

	glColor3f(0, 0.5, 0);
	road();/* road */

	glLineWidth(5);
	glColor3f(1, 1, 1);/*track outline*/
	track();

	glLineWidth(5);
	glColor3f(1,1,1);/*track lines*/
	for (i = -50; i <= 1300; i += 65)
		slant(i, 0);

	glLineWidth(3);
	glColor3f(0, 0, 0);
	elec();/*electric wire  outline*/

	glLineWidth(4);
	glColor3f(0, 0, 0);
	elecline();//electric wire

	glColor3f(0.6, 1, 0.5);
	circle_en(375, 575, 175);/*circle on the left of engine*/

	glColor3f(0.6, 1, 0.5);
	semicircle(500, 850, 60);/*semicircle on the top of engine*/

	glColor3f(0.6, 1, 0.5);
	draw_engine();/*engine*/

	glColor3f(0.2, 1, 0.9);
	draw_bogie(325, 0);/* bogie 1*/

	glColor3f(0.2, 1, 0.9);
	draw_bogie(0, 0);/* bogie 2*/

	glColor3f(0.2, 1, 0.9);
	draw_bogie(-325, 0);/* bogie 3*/

	glColor3f(0, 0, 0);
	draw_con_line(325, 0);/* connecting line bw engine and bogie 1*/

	glColor3f(0, 0, 0);
	draw_con_line(0, 0);/* connecting line bw bogie 1 and bogie 2*/

	glColor3f(0, 0, 0);
	draw_con_line(-325, 0);/* connecting line bw bogie 2 and bogie 3*/

	glColor3f(0, 0, 0);
	small_recte();/*bottom line for engine*/

	glColor3f(0, 0, 0);
	small_rect(325, 0);/*bottom line for bogie 1*/

	glColor3f(0, 0, 0);
	small_rect(0, 0);/*bottom line for bogie 2*/

	glColor3f(0, 0, 0);
	small_rect(-325, 0);/*bottom line for bogie 3*/


/*------------------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(325, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-325, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(325, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-325, -400, 0);/*moving to original position*/


	glColor3f(0.4, 0.5, 0.3);
	circle(325, 400, 50);/*wheel 1 of engine*/
	glColor3f(0.8, 0.5, 0);
	circle(325, 400, 25);/*wheel 1 small of engine*/

	glPopMatrix();
	anglenew += 0.15;

	/*------------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(500, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-500, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(500, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-500, -400, 0);/*moving to original position*/


	glColor3f(0.4, 0.5, 0.3);
	circle(500, 400, 50);/*wheel 2 of engine*/
	glColor3f(0.8, 0.5, 0);
	circle(500, 400, 25);/*wheel 2 small of engine*/

	glPopMatrix();
	anglenew += 0.15;

	/*----------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(625, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-625, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(625, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-625, -400, 0);/*moving to original position*/


	glColor3f(0.4, 0.5, 0.3);
	circle(625, 400, 50);/*wheel 1 of bogie 1*/
	glColor3f(0.8, 0.5, 0);
	circle(625, 400, 25);/*wheel 1 small of bogie 1*/

	glPopMatrix();
	anglenew += 0.15;

	/*-----------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(825, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-825, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(825, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-825, -400, 0);/*moving to original position*/


	glColor3f(0.4, 0.5, 0.3);
	circle(825, 400, 50);/*wheel 2 of bogie 1*/
	glColor3f(0.8, 0.5, 0);
	circle(825, 400, 25);/*wheel 2 small of bogie 1*/

	glPopMatrix();
	anglenew += 0.15;

	/*------------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(950, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-950, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(950, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-950, -400, 0);/*moving to original position*/


	glColor3f(0.4, 0.5, 0.3);
	circle(950, 400, 50);/*wheel 1 of bogie 2*/
	glColor3f(0.8, 0.5, 0);
	circle(950, 400, 25);/*wheel 1 small of bogie 2*/

	glPopMatrix();
	anglenew += 0.15;

	/*----------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(1150, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-1150, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(1150, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-1150, -400, 0);/*moving to original position*/

	glColor3f(0.4, 0.5, 0.3);
	circle(1150, 400, 50);/*wheel 2 of bogie 2*/
	glColor3f(0.8, 0.5, 0);
	circle(1150, 400, 25);/*wheel 2 small of bogie 2*/

	glPopMatrix();
	anglenew += 0.15;

	/*----------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(1275, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-1275, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(1275, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-1275, -400, 0);/*moving to original position*/

	glColor3f(0.4, 0.5, 0.3);
	circle(1275, 400, 50);/*wheel 1 of bogie 3*/
	glColor3f(0.8, 0.5, 0);
	circle(1275, 400, 25);/*wheel 1 small of bogie 3*/

	glPopMatrix();
	anglenew += 0.15;

	/*----------------------------------------------------------------------------------------------------*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(1475, 400, 0);/*moving to origin*/
	glTranslatef(0 + xpos, 0, 0); /*translating*/
	glTranslatef(-1475, -400, 0);/*moving to original position*/

	glPushMatrix();
	glTranslatef(1475, 400, 0);/*moving to origin*/
	glRotatef(anglenew, 0, 0, 1);/*rotating*/
	glTranslatef(-1475, -400, 0);/*moving to original position*/

	glColor3f(0.4, 0.5, 0.3);
	circle(1475, 400, 50);/*wheel 2 of bogie 3*/
	glColor3f(0.8, 0.5, 0);
	circle(1475, 400, 25);/*wheel 2 small of bogie 3*/

	glPopMatrix();
	anglenew += 0.15;



	/*-----------------------------------------------------------------------------------------------------------*/


	glColor3f(0, 0.5, 0.9);
	window(325, 0);/* window 1 of bogie 1*/

	glColor3f(0, 0.5, 0.9);
	window(325 - 90, 0);/* window 2 of bogie 1*/

	glColor3f(0, 0.5, 0.9);
	window(325 - 180, 0);/* window 3 of bogie 1*/

	glColor3f(0, 0.5, 0.9);
	window(0, 0);/* window 1 of bogie 2*/

	glColor3f(0, 0.5, 0.9);
	window(-90, 0);/* window 2 of bogie 2*/

	glColor3f(0, 0.5, 0.9);
	window(-180, 0);/* window 3 of bogie 2*/

	glColor3f(0, 0.5, 0.9);
	window(0-325, 0);/* window 1 of bogie 3*/

	glColor3f(0, 0.5, 0.9);
	window(-90-325, 0);/* window 2 of bogie 3*/

	glColor3f(0, 0.5, 0.9);
	window(-180-325, 0);/* window 3 of bogie 3*/


	glColor3f(0, 0.5, 0.9);
	windowe();/* window of engine*/
	glPopMatrix();
}
void timer(int a)/*timer function in order to translate train*/
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer, 0);
	if (xpos > -1700)
		xpos -= 2;
}
void timer1(int a)/*timer function in order to call the train function again and again*/
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer1, 0);
	if (xpos <= -1700)
	{
		xpos = 1300;
	}
	else
	{
		xpos -= 2;
	}
}
void timer2(int a)/*timer function in order to translate rain*/
{
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, timer2, 0);
	if (ypos <= -1190)
	{
		ypos = 1300;
	}
	else
	{
		ypos -= 1;
	}
}
void output(int x, int y, float r, float g, float b, char *string)/*displaying text on screen*/
{
	glColor3f(r, g, b);
	glRasterPos2f(x, y);
	int len, i;
	len = (int)strlen(string);
	for (i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}
void display1()/*calling output function*/
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	output(450, 1200, 1, 0, 1, "BNM INSTITUTE OF TECHNOLOGY");
	output(310, 1050, 0.2, 0, 1, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	output(540, 900, 0, 0.5, 0, "A MINI PROJECT ON");
	output(540, 750, 0.9, 0, 0, "TRAIN SIMULATION");
	output(100, 600, 0, 0.5, 0, "BY");
	output(100, 530, 0.1, 0.7, 0.5, "NAME : NISHIKA TIKU");
	output(100, 460, 0.1, 0.7, 0.5, "USN : 1BG16CS070");
	output(1000, 600, 0, 0.5, 0, "GUIDE");
	output(1000, 530, 0.6, 0.5, 0.9, "MRS. RANJANA MA'AM");
	output(520, 200, 1, 1, 1, "PRESS ENTER TO START");
	glutSwapBuffers();
}
void display2()/*calling train function*/
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	train();
	output(550, 1200, 1, 1, 1, "PRESS S or s TO RAIN");
	output(550, 1150, 1, 1, 1, "PRESS T or t TO STOP RAIN");
	glutSwapBuffers();
}
void display3()/*calling train as well as rain function*/
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);
	train();
	glColor3f(0.2, 0.9, 1);
	translate();
	output(550, 1200, 1, 1, 1, "PRESS S or s TO RAIN");
	output(550, 1150, 1, 1, 1, "PRESS T or t TO STOP RAIN");
	glutSwapBuffers();
}
void keynew(unsigned char key, int x, int y)/*stopping rain*/
{
	if (key == 't' || key=='T')
	{
		glutHideWindow();
		glutSetWindow(win);
	}
}
void keybd(unsigned char key, int x, int y)/*to enable raining*/
{
	if (key == 's' || key=='S')
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(1300, 1300);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("TRAIN");
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0, 1300, 0, 1300);
		glutDisplayFunc(display3);
		glutKeyboardFunc(keynew);
		glutTimerFunc(0, timer, 0);
		glutTimerFunc(1000, timer1, 0);
		glutTimerFunc(0, timer2, 0);
		glutMainLoop();
	}
}
void key(unsigned char key, int x, int y)
{
	if (key == 13)/*enter key*/
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
		glutInitWindowSize(1300, 1300);
		glutInitWindowPosition(0, 0);
		win = glutCreateWindow("TRAIN");
		glMatrixMode(GL_PROJECTION);
		gluOrtho2D(0, 1300, 0, 1300);
		glutDisplayFunc(display2);
		glutKeyboardFunc(keybd);
		glutTimerFunc(0, timer, 0);
		glutTimerFunc(0, timer1, 0);
		glutTimerFunc(0, timer2, 0);
		glutMainLoop();
	}
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1300, 1300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("cover page");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1300, 0, 1300);
	glutDisplayFunc(display1);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}
