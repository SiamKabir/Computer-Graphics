#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
float bx = 10;
int  x_pos =0, y_pos =0;
double deg=0, axis=0;
int r = 255,g =81, b =54;  // home color
 int j=255, k = 148, l = 57; //sun color change and press h for white color and trun into moon
 int sk1 =156, sk2 =234, sk3 =247; // press o to change cloor of sky; glColor3ub(156,234,247);
void init()
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glOrtho(0,850,0,650,0,850);

}

void keyboard(unsigned char key, int w, int h) {
    switch(key) {
        case 'a':
        case 'A':
            x_pos-=10;
            glutPostRedisplay();
            break;

        case 'd':
        case 'D':
            x_pos+=10;
            glutPostRedisplay();
            break;

        case 'w':
        case 'W':
            y_pos+=10;
            glutPostRedisplay();
            break;

        case 's':
        case 'S':
            y_pos-=10;
            glutPostRedisplay();
            break;

        case 'm':
        case 'M':
            deg+=10;
            axis=5;
        glutPostRedisplay();

        case 'r':
        case 'R':
            r = 255;
            g = 0;
            b = 0;
            glutPostRedisplay();
            break;

        case 'h':
        case 'H':
            j = 255;
            k = 255;
            l = 255;
            glutPostRedisplay();
            break;

        case 'b':
        case 'B':
            r = 0;
            g = 0;
            b = 255;
            glutPostRedisplay();
            break;

        case 'o':
        case 'O':
            sk1 = 0;
            sk2 = 0;
            sk3= 0;
            glutPostRedisplay();
            break;
    }
    if(key == 27) exit(0);

}
void makeCircle(double r, int x_center, int y_center){

    int deg =0;
    double x, y, theta;

    glPointSize(7);
    glBegin(GL_POLYGON);

    while( deg <360)
    {
        theta = (deg *M_PI)/180;
        x = x_center+r*cos(theta);
        y = y_center+r * sin(theta);
        deg++;
        glVertex2d(x,y);
    }
    glEnd();

}

void innerCircle(double r, int x_center, int y_center){
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

void boatCircle(double r, int x_center, int y_center){
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

void personCircle(double r, int x_center, int y_center){
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

void house(){


    glColor3ub(r,g,b);
    glBegin(GL_POLYGON);// top
             glVertex2i(0,300);
             glVertex2i(50,400);
             glVertex2i(250,400);
             glVertex2i(300,300);
    glEnd();

    glColor3ub(251,243,236);
    glRecti(20,220,280,300);

    glColor3ub(241,170,144);
    glRecti(240,220,280,270);

    glColor3ub(0,0,0);           //upper
    glRecti(100,400,150,425);

    glColor3ub(0,0,0);          //window
    glRecti(50,250,80,280);

     glColor3ub(0,0,0);
    glRecti(150,250,180,280);

    glColor3ub(0,0,0);
    innerCircle(5,247,250);

    }

void person(){
     glPushMatrix();
    glTranslatef(x_pos,y_pos,0);
    glRotatef(deg,0,0,axis);

     glColor3ub(247,247,247); //head
     personCircle(15,500,300);

     glColor3ub(0,0,0);//eye 1
     personCircle(2,491,300);

     glColor3ub(0,0,0);//eye 2
     personCircle(2,510,300);

     glColor3ub(0,0,0);
     glBegin(GL_LINES); //mouth
         glVertex2i(495,290);
         glVertex2i(506,290);

    glEnd();
     glColor3ub(247,247,247); // body
     glBegin(GL_LINES);
        glVertex2i(500,290);
        glVertex2i(500,240);
     glEnd();

     glColor3ub(247,247,247); //hand-1
     glBegin(GL_LINES);
        glVertex2i(500,290);
        glVertex2i(470,270);
     glEnd();

     glColor3ub(247,247,247); //hand-2
     glBegin(GL_LINES);
        glVertex2i(500,290);
        glVertex2i(530,270);
     glEnd();

     glColor3ub(247,247,247); //foot-1
     glBegin(GL_LINES);
        glVertex2i(500,240);
        glVertex2i(490,230);
     glEnd();

     glColor3ub(247,247,247); //foot-2
     glBegin(GL_LINES);
        glVertex2i(500,240);
        glVertex2i(508,230);
     glEnd();

    glColor3ub(0,0,255);
    glBegin(GL_TRIANGLES);// 1 tree_leef 1
         glVertex2i(500,284);
         glVertex2i(490,242);
         glVertex2i(510,242);
    glEnd();


     glPopMatrix();





}

void boat(){
     glPushMatrix();
     glTranslatef(bx, 0, 0);

     glColor3ub(0,0,0);
     glBegin(GL_POLYGON);// boat
         glVertex2i(150,110);
         glVertex2i(200,50);
         glVertex2i(300,50);
         glVertex2i(340,110);
         glVertex2i(310,50);
         glVertex2i(180,50);
    glEnd();

      glBegin(GL_POLYGON);// boat
         glVertex2i(100,110);
         glVertex2i(200,50);
         glVertex2i(300,50);
         glVertex2i(390,110);
         glVertex2i(310,50);
         glVertex2i(180,50);
    glEnd();

     glColor3ub(0,125,65);
     glBegin(GL_POLYGON);// boat
         glVertex2i(180,110);
         glVertex2i(200,150);
         glVertex2i(300,150);
         glVertex2i(320,110);
    glEnd();

     glColor3ub(255,0,0);//boat circle red
     boatCircle(16,250,130);



      glColor3ub(0,0,0); //strip-1
     glBegin(GL_LINES);
        glVertex2i(200,110);
        glVertex2i(200,150);
     glEnd();

     glColor3ub(0,0,0);//strip-2
     glBegin(GL_LINES);
        glVertex2i(230,110);
        glVertex2i(230,150);
     glEnd();

      glColor3ub(0,0,0);//strip-3
     glBegin(GL_LINES);
        glVertex2i(260,110);
        glVertex2i(260,150);
     glEnd();

     glColor3ub(0,0,0);//strip-4
     glBegin(GL_LINES);
        glVertex2i(280,110);
        glVertex2i(280,150);
     glEnd();

     glColor3ub(0,0,0);//strip-5
     glBegin(GL_LINES);
        glVertex2i(300,110);
        glVertex2i(300,150);
     glEnd();

     glColor3ub(0,0,0);//strip-6
     glBegin(GL_LINES);
        glVertex2i(200,130);
        glVertex2i(300,130);
     glEnd();
    glPopMatrix();

    bx += .05;
    if (bx > 850)
        bx = -850;
    glutPostRedisplay();



}

void tree(){

    glColor3ub(207,123,50);
    glRecti(260,400,300,460);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);// 1 tree_leef 1
         glVertex2i(170,460);
         glVertex2i(370,460);
         glVertex2i(272,550);
    glEnd();

    glColor3ub(0,126,63);
     glBegin(GL_TRIANGLES);// 1 tree_leef 2
         glVertex2i(190,510);
         glVertex2i(361,510);
         glVertex2i(272,590);
    glEnd();

    glColor3ub(0,150,63);
     glBegin(GL_TRIANGLES);// 1 tree_leef 3
         glVertex2i(200,560);
         glVertex2i(350,560);
         glVertex2i(280,650);
    glEnd();

     glColor3ub(207,123,50);
    glRecti(650,360,690,530);

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);//  2 tree_leef 1
         glVertex2i(550,480);
         glVertex2i(790,480);
         glVertex2i(670,550);
    glEnd();

    glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);//  2 tree_leef 2
         glVertex2i(570,520);
         glVertex2i(670,600);
         glVertex2i(770,520);
    glEnd();

      glColor3ub(0,126,63);
    glBegin(GL_TRIANGLES);//  2 tree_leef 3
         glVertex2i(600,570);
         glVertex2i(740,570);
         glVertex2i(670,650);
    glEnd();


}

void display() {
    //clear the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
     glColor3ub(sk1,sk2,sk3);//light blue
     glRecti(0,450,850,650);

     glColor3ub(j,k,l); // sun
     makeCircle(50,450,580);

     glBegin(GL_POLYGON);  // Ground
         glColor3ub(166,225,86);
         glVertex2i(0,0);
         glVertex2i(0,450);
         glVertex2i(40,550);
         glVertex2i(140,615);
         glVertex2i(200,590);
         glVertex2i(250,540);
         glVertex2i(300,450);
         glVertex2i(400,450);
         glVertex2i(450,500);
         glVertex2i(520,450);
         glVertex2i(600,450);
         glVertex2i(850,650);
         glVertex2i(850,0);
    glEnd();

     glColor3ub(101,166,201);//river
     glRecti(0,0,850,200);

     tree();
     house();
     person();
     boat();
     glFlush();
     glutSwapBuffers();

}
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(500, 100);
    glutInitWindowSize(900, 900);


    glutCreateWindow("VILLAGE");
    glutDisplayFunc(display);
    init();

    glutKeyboardFunc(keyboard);
    //glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;

}
