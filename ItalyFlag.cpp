#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>

void init() {
    glClearColor(0.137255, 0.556863, 0.419608, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 60.0, 0.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glColor3ub(0, 140, 69);
    glRecti(0,0,20,100);

    glColor3ub(244, 249, 255);
    glRecti(20,0,40,100);

    glColor3ub(205, 33, 42);
    glRecti(40,0,60,100);



    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(600, 400);


    glutCreateWindow("FLAG OF ITALY");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
