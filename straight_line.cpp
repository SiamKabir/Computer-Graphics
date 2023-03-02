#include <GL/gl.h> //base opengl hearders that provide OpenGl functions
#include <GL/glu.h> //set of utility functions
#include <GL/glut.h>
//create and manages the window
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //clear the frame buffer
    glColor3i(0.0f,1.0f,1.0f);
    glBegin(GL_LINES);
        glVertex2i(5,5);
        glVertex2i(15,10);
   glEnd();
glFlush();

}

void init()
{
           glClearColor(1.0f,0.50f,.50f,0);
           glMatrixMode(GL_PROJECTION); // which matrix is the current matrix
           glLoadIdentity(); //replace the current matrix with the identity matrix
           gluOrtho2D(0.0f,20.0f,0.0f,20.0f); // set the clipping area
          glMatrixMode(GL_PROJECTION);
}
int main(int argc, char** argv)
{
               glutInit(&argc, argv); // initialize the GLUT library
               glutInitDisplayMode(GLUT_RGB);
               glutInitWindowPosition(100, 300);
               glutInitWindowSize(300, 300);
               glutCreateWindow("FIRST CLASS OF PC-F Section");
               glutDisplayFunc(display);
              init();
              glutMainLoop(); // event processing loop
return 0;
 }
