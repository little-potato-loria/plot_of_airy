#include "global.h"
#include "plot.h"

void drawAxes() {
    glColor3f(1.0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(0.98 * min_x + 0.02 * max_x, 0.98 * min_y + 0.02 * max_y);
    glVertex2f(0.98 * max_x + 0.02 * min_x, 0.98 * min_y + 0.02 *max_y);
    glVertex2f(0.98 * min_x + 0.02 * max_x, 0.98 * min_y + 0.02 *max_y);
    glVertex2f(0.98 * min_x + 0.02 * max_x, 0.98 * max_y + 0.02 *min_y);
    glEnd();
}
void drawTicks() {
    glColor3f(1.0, 0, 0);
    for (float xx = min_x; xx <= max_x; xx +=(max_x-min_x)/20.0) {
        glBegin(GL_LINES);
        glVertex2f(xx, min_y);
        glVertex2f(xx, min_y+0.05*(max_y-min_y));
        glEnd();
        glRasterPos2f(xx, min_y+0.06*(max_y-min_y));
        char buf[10];
        snprintf(buf, sizeof(buf), "%.1f", xx);
        for (char* p = buf; *p; p++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
        }
    }
    for (float yy = min_y; yy <= max_x; yy += (max_y - min_y) / 20.0) {
        glBegin(GL_LINES);
        glVertex2f(min_x,yy);
        glVertex2f(min_x + 0.05 * (max_y - min_y),yy);
        glEnd();
        glRasterPos2f(min_x + 0.06 * (max_x - min_x),yy);
        char buf[10];
        snprintf(buf, sizeof(buf), "%.1f", yy);
        for (char* p = buf; *p; p++) {
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *p);
        }
    }
}
