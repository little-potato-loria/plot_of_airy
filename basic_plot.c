#include "globle.h"
#include "plot.h"

void drawAxes() {
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(min_x, min_y);
    glVertex2f(max_x, min_y);
    glVertex2f(min_x, min_y);
    glVertex2f(min_x, max_y);
    glEnd();
}
void drawTicks() {
    glColor3f(1.0, 1.0, 1.0);
    for (float xx = min_x; xx <= max_x; xx +=(x_max-x_min)/20.0) {
        glBegin(GL_LINES);
        glVertex2f(xx, y_min);
        glVertex2f(xx, y_min+0.05*(y_max-y_min));
        glEnd();
        glRasterPos2f(xx, y_min+0.06*(y_max-y_min));
        char buf[10];
        sprintf_s(buf, sizeof(buf), "%.1f", xx);
        for (char* p = buf; *p; p++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
        }
    }
    for (float yy = min_y; yy <= max_x; yy += (y_max - y_min) / 20.0) {
        glBegin(GL_LINES);
        glVertex2f(x_min,yy);
        glVertex2f(x_min + 0.05 * (y_max - y_min),yy);
        glEnd();
        glRasterPos2f(x_min + 0.06 * (x_max - x_min),yy);
        char buf[10];
        sprintf_s(buf, sizeof(buf), "%.1f", yy);
        for (char* p = buf; *p; p++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
        }
    }
}
