#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
double x_pos =0, y_pos =0;
void init(){
    glClearColor(1.0,1.0,1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 40.0, 0.0, 40.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 27:
        exit(0);
        break;
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
        }

}
void display() {
    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    glRecti(10+x_pos,10+y_pos,20+x_pos,20+y_pos);
    glFlush();

}
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(300, 100);
    glutInitWindowSize(500, 500);


    glutCreateWindow("Transformation");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();

    return 0;

}
