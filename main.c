#include "globle.h"
#include <stdio.h>
int main(int argc, char** argv) {
    printf("«Î ‰»Îdy/dx£∫");
    scanf("%f", v0);
    caculate(y0, v0, x0);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 700);
    glutCreateWindow("made by dhy");
    glutMouseFunc(mouseClick);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}