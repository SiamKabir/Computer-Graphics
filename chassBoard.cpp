#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<cmath>
#include<stdbool.h>

#define black 0
#define white 1


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    bool state = white;
    for (int i = 0; i <= 80; i += 10)
    {
        for (int j = 0; j<= 80; j+=10)
        {
            if(state==white)
            {
                glColor3ub(255,255,255);
                state=black;
            }else{
                glColor3ub(0, 0, 0);
                state=white;
            }
            glBegin(GL_QUADS);

            glVertex2i(i, j);
            glVertex2i(i, j+10);
            glVertex2i(i+10, j+10);
            glVertex2i(i+10, j);

            glEnd();

        }
    }

    glFlush();

}
void init(){
    glClearColor(0.0, 0.5, 0.0, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0f, 80.0f, 0.0f, 80.0f);
    glMatrixMode(GL_MODELVIEW);
}
 //coand line argument and pointer argument
int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Chess Board");
    //display callback Function
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;
}
