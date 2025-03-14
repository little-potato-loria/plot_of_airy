#include "globle.h"
#include "plot.h"
#include <time.h>
#include <stdlib.h>
time_t lastClickTime = 0;
int lastClickX = 0, lastClickY = 0;
const int doubleClickThreshold = 500; 
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        time_t currentTime = glutGet(GLUT_ELAPSED_TIME);
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        x0 = min_x + (float)x / windowWidth * (max_x - min_x);
        y0 = max_y - (float)y / windowHeight * (max_y - min_y);
        printf("Mouse clicked at: (%f, %f)\n", x0, y0);
        caculate(y0, v0, x0);
        if (currentTime - lastClickTime < doubleClickThreshold &&
            abs(x - lastClickX) < 10 && abs(y - lastClickY) < 10) {
            char filename[256];
            snprintf(filename, sizeof(filename), "data_of_%.2f_%.2f.txt", x0, y0);
            FILE* file = fopen(filename, "a");
            if (file) {
                int j = 0;
                for (float xx = min_x; xx < max_x; xx += dt) {
                    fprintf(file, "%f, %f\n", xx, yrem[j]);
                    ++i;
                }
                fclose(file);
            }
            printf("saved")
        }
        lastClickTime = currentTime;
        lastClickX = x;
        lastClickY = y;
        glutPostRedisplay(); 
    }
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(min_x,max_x,min_y,max_y);
    drawAxes();
    drawTicks();
    glBegin(GL_LINE_STRIP);
    int i = 0;
    for (float xx = min_x; xx < max_x; xx += dt) {
        glVertex2f(xx, yrem[i]);
        ++i;
    }
    glEnd();
}
