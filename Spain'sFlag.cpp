#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>

void init() {
    glClearColor(0.137255, 0.556863, 0.419608, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glColor3f(0.0f,0.0f,0.0f);
    glRecti(0,60, 100,40);

      glColor3f(1.0f,0.0f,0.0f);
    glRecti(0,20, 100,40);

      glColor3f(1.0f,1.0f,0.0f);
      glRecti(0,0, 100,20);

    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(750, 450);


    glutCreateWindow("SPAIN'S Flag");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
