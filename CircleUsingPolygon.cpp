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
void makeCircle(int r, int x_center, int y_center){

    int deg =0;
    double x, y, theta;

    glPointSize(7);
    glBegin(GL_POLYGON);

    while( deg <360){
        theta = (deg *M_PI)/180;
        x = x_center+r*cos(theta);
        y = y_center+r * sin(theta);
        deg++;
        glVertex2d(x,y);
    }

    glEnd();



}
void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    glColor3f(1.0f,1.0f,0.0f);

    makeCircle(10,20,15);

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
