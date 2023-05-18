#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
int x_pos = 0, y_pos = 0;
double deg=0, axis=0;
void reshape(int w, int h) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float h2wRatio = (float)h/(float)w;
    float w2hRatio = (float)w/(float)h;
    if(w <= h)
        gluOrtho2D(-20, 100, -20, 100*h2wRatio);
    else
        gluOrtho2D(-20, 100*w2hRatio, -20, 100);
    glMatrixMode(GL_MODELVIEW);
}
void keyboard(unsigned char key, int w, int h) {
    switch(key) {
        case 'a':
        case 'A':
            x_pos-=1;
            glutPostRedisplay();
            break;

        case 'd':
        case 'D':
            x_pos+=1;
            glutPostRedisplay();
            break;

        case 'w':
        case 'W':
            y_pos+=1;
            glutPostRedisplay();
            break;

        case 's':
        case 'S':
            y_pos-=1;
            glutPostRedisplay();
            break;
        case 'm':
        case 'M':
            deg+=5;
            axis=1;
        glutPostRedisplay();
    }
    if(key == 27) exit(0);

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
void inCircle(int r, int x_center, int y_center){

    int deg =0;
    double x, y, theta;

    glPointSize(0.5);
    glBegin(GL_POINTS);

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
    glPushMatrix();
    glTranslatef(x_pos,y_pos,0);
    glRotatef(deg,0,0,axis);

    glColor3ub(171,82,54);
    glBegin(GL_POLYGON);
          glVertex2i(10,5);
          glVertex2i(10,15);
          glVertex2i(17,29);
          glVertex2i(60,29);
          glVertex2i(75,15);
          glVertex2i(80,15);
          glVertex2i(80,5);
     glEnd();
     glColor3ub(29,43,83);
     glRecti(22,15,30,20);

     glColor3ub(29,43,83);
     glRecti(50,15,58,20);

     glColor3f(0.0f,0.0f,0.0f);
     makeCircle(5,25,6);

     glColor3f(1.0f,1.0f,1.0f);
     inCircle(3,25,6);

     glColor3f(0.0f,0.0f,0.0f);
     makeCircle(5,60,6);

     glColor3f(1.0f,1.0f,1.0f);
     inCircle(3,60,6);

    glPopMatrix();
    glFlush();

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(700, 700);


    glutCreateWindow("Car");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;

}
