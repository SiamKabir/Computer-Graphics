#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

void makeCircle(int r, int x_center, int y_center){
    int deg =0;
    double x,y, theta;

    glBegin(GL_POLYGON);

    while(deg<360){
        theta = (deg * M_PI) /100;
        x = x_center + r* cos(theta);
        y = y_center + r* sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();

}
void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 100.0, 0.0, 60.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here


    glColor3ub(255,255,255);
    glRecti(0,0,100,60);
    glColor3f(1.0, 0.0,0.0);
    makeCircle(20,50,30);
    //display the frame buffer
    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(750, 450);


    glutCreateWindow("BD FLAG");
    glutDisplayFunc(display);
    init();
    glutMainLoop();

    return 0;

}
