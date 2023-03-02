#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
void display();
void init();
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("GL_LINE_STRIP");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}
void display() {
   glColor3f(0.0f, 1.0f, 0.0f);
   for(int i=0; i<=35; i+=2)
   {
    glLineWidth(i);
    glBegin(GL_LINE_STRIP);
       glVertex2f(15, i);
       glVertex2f(18, i);
    glEnd();
 }
   glFlush();}
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 50.0, 0.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}
