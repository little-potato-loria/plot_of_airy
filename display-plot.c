#include "global.h"
#include "plot.h"
#include <time.h>
#include <stdlib.h>
unsigned int lastClickTime = 0;
int lastClickX = 0, lastClickY = 0;
const int doubleClickThreshold = 500; 
float dv = 0.05;
void saveData() {
	char filename[256];
	snprintf(filename, sizeof(filename), "data_of_%.2f_%.2f.txt", x0, y00);
	FILE* file = fopen(filename, "a");
	if (file) {
		int j = 0;
		for (float xx = max(min_x, x0); xx < max_x; xx += dt) {
			fprintf(file, "%f, %f\n", xx, yrem[j]);
			++j;
		}
		fclose(file);
	}
	printf("已保存\n");
}
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        unsigned int currentTime = glutGet(GLUT_ELAPSED_TIME);
        int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
        int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
        x0 = min_x + (float)x / windowWidth * (max_x - min_x);
        y00 = max_y - (float)y / windowHeight * (max_y - min_y);
        printf("Mouse clicked at: (%f, %f)\n", x0, y00);
        calculate(y00, v0, x0);
        if (currentTime - lastClickTime < doubleClickThreshold &&
            abs(x - lastClickX) < 10 && abs(y - lastClickY) < 10) {
            saveData();
        }
        lastClickTime = currentTime;
        lastClickX = x;
        lastClickY = y;
        glutPostRedisplay(); 
    }
}
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':  
        exit(0);
        break;
    case 'w':  
		v0 += dv;
        break;
    case 's':
		v0 -= dv;
        break;
    case 'a':  
        dv *= 2;
        break;
    case 'd':
		dv /= 2;
        break;
    case 'e':
		printf("x0=%f,v0=%f,y0=%f\n",x0,v0,y00);
    case'r':
		printf("请输入初始y：");
		scanf("%f", &y00);
        break;
    case'f':
		printf("请输入初始dy/dx：");
        scanf("%f", &v0);
        break;
    case'v':
		printf("请输入初始x："); 
        scanf("%f", &x0);
        break;
    default:
        break;
    }
    calculate(y00, v0, x0);
    glutPostRedisplay();  
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    gluOrtho2D(min_x,max_x,min_y,max_y);
    drawAxes();
    drawTicks();
    glBegin(GL_LINE_STRIP);
    int i = 0;
    for (float xx = max(min_x,x0); xx < max_x; xx += dt) {
        glVertex2f(xx, yrem[i]);
        ++i;
    }
    glEnd();
	glFlush();
}

