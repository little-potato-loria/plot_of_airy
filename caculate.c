#include "globle.h"
#include <math.h>
#ifndef ChuanXing
#include<omp.h>
#endif

inline double func(double t, double yy, double v) {
    return t*yy;
}
#ifndef ChuanXing
/*something*/
#endif
#ifdef ChuanXing
/*v=dy/dt,d^2y/dt^2=func*/
void DiTui(double* yy, double* v) {
    double k1, k2, k3, k4, l1, l2, l3, l4;
    k1 = dt * (*v);
    l1 = dt * func(t,*yy, *v);
    k2 = dt * (*v + 0.5 * l1);
    l2 = dt * func(t + dt / 2, *yy + 0.5 * k1, *v + 0.5 * l1);
    k3 = dt * (*v + 0.5 * l2);
    l3 = dt * func(t + dt / 2, *yy + 0.5 * k2, *v + 0.5 * l2);
    k4 = dt * (*v + l3);
    l4 = dt * func(t + dt, *yy + k3, *v + l3);
    *yy = *yy + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
    *v = *v + (l1 + 2 * l2 + 2 * l3 + l4) / 6;
}
void caculate(double yy,double v,double x) {
    for (int j = 0; j < NUM;j++) {
        yrem[j] = yy;
        rk4(t, &yy, &v);
        t += dt;
        j++;
    }
}
#endif
