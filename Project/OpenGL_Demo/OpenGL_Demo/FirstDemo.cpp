//第一个练习，绘制各种几何图形
#include "stdafx.h" 
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void DrawPoints(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5.0f);
	glBegin(GL_POINTS);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5f, 0.5f);

	glEnd();
	glFlush();
}

void DrawLines(void){
	glClear(GL_COLOR_BUFFER_BIT);
	
	glEnable(GL_LINE_STRIP);
	glLineStipple(2, 0x0F0F);
	glLineWidth(5.0f);
	glBegin(GL_LINES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.5f, 0.5f);
	glEnd();
	glFlush();
}

void DrawRect(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glRectf(-0.5f, -0.5f, 0.5f, 0.5f);
	glFlush();
}
const GLfloat Pi = 3.1415926536f;
const GLfloat Radius = 0.5f;
const int n = 120;
void DrawMyCircle(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++){
		glVertex2f(Radius*cos(2 * Pi / n*i), Radius*sin(2 * Pi / n*i));
	}
	glEnd();
	glFlush();
}

void DrawMyFiveAngleStar(void){
	GLfloat a = 1 / (2 - 2 * cos(72 * Pi / 180));
	GLfloat bx = a * cos(18 * Pi / 180);
	GLfloat by = a * sin(18 * Pi / 180);
	GLfloat cy = -a * cos(18 * Pi / 180);
	GLfloat
		PointA[2] = { 0, a },
		PointB[2] = { bx, by },
		PointC[2] = { 0.5, cy },
		PointD[2] = { -0.5, cy },
		PointE[2] = { -bx, by };

	glClear(GL_COLOR_BUFFER_BIT);
	// 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出
	glBegin(GL_LINE_LOOP);
	glVertex2fv(PointA);
	glVertex2fv(PointC);
	glVertex2fv(PointE);
	glVertex2fv(PointB);
	glVertex2fv(PointD);

	glEnd();
	glFlush();
}
const GLfloat factor = 0.1f;

void DrawSinCurve(void){
	GLfloat x;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f, 1.0f);
	glEnd();
	glBegin(GL_LINE_STRIP);
	for (x = -1.0f / factor; x < 1.0f / factor; x += 0.01f){
		glVertex2f(x*factor, sin(x)*factor);
	}
	glEnd();
	glFlush();

}

void DrawPloygon(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glPolygonMode(GL_FRONT, GL_FILL);//设置正面为填充模式
	glPolygonMode(GL_BACK, GL_LINE);//设置反面为线形模式
	glFrontFace(GL_CCW);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(0.0f, 0.0f);
	//glVertex2f(-0.5f, 0.0f);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	//glVertex2f(0.5f, 0.0f);
	glEnd();
	glFlush();
}

void DrawLouKong(void){
	//static GLubyte Mask[128];
	static GLubyte Mask[128] =
	{
		0x00, 0x00, 0x00, 0x00,//  这是最下面的一行
		0x00, 0x00, 0x00, 0x00,
		0x03, 0x80, 0x01, 0xC0,//  麻
		0x06, 0xC0, 0x03, 0x60,//  烦
		0x04, 0x60, 0x06, 0x20,//  的
		0x04, 0x30, 0x0C, 0x20,//  初
		0x04, 0x18, 0x18, 0x20,//  始
		0x04, 0x0C, 0x30, 0x20,//  化
		0x04, 0x06, 0x60, 0x20,//  ，
		0x44, 0x03, 0xC0, 0x22,//  不
		0x44, 0x01, 0x80, 0x22,//  建
		0x44, 0x01, 0x80, 0x22,//  议
		0x44, 0x01, 0x80, 0x22,//  使
		0x44, 0x01, 0x80, 0x22,//  用
		0x44, 0x01, 0x80, 0x22,
		0x44, 0x01, 0x80, 0x22,
		0x66, 0x01, 0x80, 0x66,
		0x33, 0x01, 0x80, 0xCC,
		0x19, 0x81, 0x81, 0x98,
		0x0C, 0xC1, 0x83, 0x30,
		0x07, 0xE1, 0x87, 0xE0,
		0x03, 0x3F, 0xFC, 0xC0,
		0x03, 0x31, 0x8C, 0xC0,
		0x03, 0x3F, 0xFC, 0xC0,
		0x06, 0x64, 0x26, 0x60,
		0x0C, 0xCC, 0x33, 0x30,
		0x18, 0xCC, 0x33, 0x18,
		0x10, 0xC4, 0x23, 0x08,
		0x10, 0x63, 0xC6, 0x08,
		0x10, 0x30, 0x0C, 0x08,
		0x10, 0x18, 0x18, 0x08,
		0x10, 0x00, 0x00, 0x08 // 这是最上面的一行
	};
	
	FILE *fp;
	fp = fopen("mask.bmp", "rb");
	if (!fp){
		exit(0);
	}
	if (fseek(fp, -(int)sizeof(Mask), SEEK_END)){
		exit(0);
	}
	if (!fread(Mask, sizeof(Mask), 1, fp)){
		exit(0);
	}
	fclose(fp);
	glClearColor(0.5f, 0.5f, 0.5f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.3f, 0.5f, 0.1f);
	glEnable(GL_POLYGON_STIPPLE);
	glPolygonStipple(Mask);
	glRectf(-0.5f, -0.5f, 0.0f, 0.0f);
	glDisable(GL_POLYGON_STIPPLE);
	glRectf(0.5f, 0.5f, 0.0f, 0.0f);
	glFlush();
}

void GiveDiffColor(){
	int i;
	//glShadeModel(GL_FLAT);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 0.0f);
	for (i = 0; i <= 8; ++i){
		glColor3f(i & 0x04, i & 0x02, i & 0x01);
		glVertex2f(cos(i*Pi / 4), sin(i*Pi / 4));
	}
	glEnd();
	glFlush();
}

int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(800, 800);
	glutCreateWindow("OpenGL演示程序");
	glutDisplayFunc(&GiveDiffColor);
	glutMainLoop();
	return 0;
}





