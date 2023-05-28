#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void init() {
    glClearColor(0.137255, 0.556863, 0.419608, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 80.0, 0.0, 80.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0,1.0,0);
    glVertex2d(30,10);
    glVertex2d(10,10);
    glVertex2d(20,30);

    glColor3f(0.0,1.0,0.0);
    glVertex2d(40,30);
    glVertex2d(40,0);
     //glVertex2d(50,20);
    glEnd();
    //display the frame buffer
    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);


    glutCreateWindow("Chess Board");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
