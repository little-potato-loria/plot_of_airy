#include "global.h"
#include <stdio.h>
int main(int argc, char** argv) {
    printf("欢迎！以下是简短说明：\n"); 
    printf("------------------\n"); 
    printf("右键单击改变初值x0、y0\n");
    printf("------------------\n");
    printf("右键双击保存数据\n");
    printf(" ------------------\n");
	printf("键盘操作：\n");
	printf("q：退出\n"); 
    printf("e：显示当前初值\n");
	printf("w：增加dy/dx\n");   
	printf("s：减小dy/dx\n");
	printf("a：加速dy/dx变化\n");
	printf("d：减速dy/dx变化\n");
	printf("r：重设当前y初值\n");
	printf("f：重设当前dy/dx初值\n");
	printf("v：重设当前x初值\n");
	printf(" ------------------\n");
    printf("  请输入初始dy / dx：");
    scanf("%f", &v0);
    calculate(y00, v0, x0);
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutCreateWindow("made by dhy");
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouseClick);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
