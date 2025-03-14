#ifndef GLOBAL_H
#define GLOBAL_H
#define ChuanXing
extern int NUM;
extern float x0,v0,y0;
extern double dt;
extern double yrem[NUM];
extern float min_x, max_x, min_y, max_y;
inline double func(double t, double yy, double v);
void drawAxes();
void drawTicks();
#ifdef ChuanXing
void DiTui(double* yy, double* v);
void caculate(double yy, double v, double xx);
#endif
void display();
void mouseClick(int button, int state, int x, int y);
#endif