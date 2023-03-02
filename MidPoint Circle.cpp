#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
using namespace std;
double x, y, p;
int r;
void display();
void init();
int main(int argc, char** argv) {
    cout  << "Enter Radius of the circle : " << endl;
    cin >> r;
    x=0;
    y=r;
    p = 1-r;
    cout << "P\tX\t\Y\t2X\t2Y" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);


    glutCreateWindow("Mid Point Circle Algorithm");
    glutDisplayFunc(display);
    init();
    glutMainLoop();



    return 0;

}

void display() {

    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    //we will draw here
    //glColor3ub(255, 241, 168);
    glClearColor(1.0f, 1.0f, 0.0f, 0.0);
    glPointSize(2);
    glBegin(GL_POINTS);

        while(x<=y){
            cout << p << "\t";
            x+=1;
            if(p < 0){
                p += (2*x + 1);
            }
            else{
                y-=1;
                p += (2*x - 2*y + 1);

            }
            cout << x << "\t" << y << "\t"
            << 2*x << "\t" << 2*y << endl;
            glVertex2f(x, y);
            glVertex2f(y, x);
            glVertex2f(-x,y);
            glVertex2f(-y,x);
            glVertex2f(-x,-y);
            glVertex2f(-y,-x);
            glVertex2f(x,-y);
            glVertex2f(y,-x);

        }
    glEnd();
    //display the frame buffer
    glFlush();

}

void init() {
    glClearColor(0.0f, 0.0f, 1.0f, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40.0, 40.0, -40.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
}
