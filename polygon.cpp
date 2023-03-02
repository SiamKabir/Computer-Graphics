#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<cmath>

void init() {
    glClearColor(0.137255, 0.556863, 0.419608, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-60.0, 60.0, -60.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glColor3f(1.0f,1.0f,0.0f);


      glBegin(GL_POLYGON);


        glVertex2i(25,25);
        glVertex2i(25,40);
        glVertex2i(40,30);
        glVertex2i(30,10);
        glVertex2i(20,10);

      glEnd();



    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);


    glutCreateWindow("POLYGON");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
