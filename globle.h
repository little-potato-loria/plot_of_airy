#ifndef GLOBAL_H
#define GLOBAL_H
#define ChuanXing
#define NUM 4096
#define _CRT_SECURE_NO_WARNINGS 1
extern float x0,v0,y00;
extern double dt;
extern double yrem[4096];
extern float min_x, max_x, min_y, max_y;
inline double func(double t, double yy, double v);
void drawAxes();
void drawTicks();
#ifdef ChuanXing
void DiTui(double t, double* yy, double* v);
void calculate(double yy, double v, double xx);
#endif
void display();
void mouseClick(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
#endif
