/*index to jump file
 * main () j 233
 * windowChange () 219
 * renderScene () 175
 * KeyUseMan () 124
 * drawbody() 100
 * releaseKey() 89
 * pressKey() 78
 * pos() 69
 * dir() 64
 * mouseMove() 54
 * mouseButton() 42
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
//#include <GLUT/glew.h>
#else
#include <GL/glut.h>
//#include <GL/glew.h>
#endif
#include <math.h>
float FRACTION = 0.1f ;
//vars applicable for triangle colours
float red = 1.0f , blue = 1.0f , green = 1.0f;
//var applicable for angle variations
float angle = 0.0f;
float anglex = 0.0f;
float angley = 0.0f;
float anglez = 0.0f;
//vars for camera angle
float lx = 0.0f , lz = -1.0f , x = 0.0f , z = 5.0f;
//vars for cam
float dx = 0 ;
float da = 0.0f;
// mouse vars
float xOrigin = -1;


void mouseButton (int button, int state , int x , int y) {
//only if mouse left pressed
   if (button == GLUT_LEFT_BUTTON){
      if(state == GLUT_UP) {
         angle += da;
         xOrigin = -1;
      } else {
      //state Glut_down
      xOrigin = x;
      }
   }
}
void mouseMove(int x , int y){
   if(xOrigin >= 0){
      //upadate da
      da = (x - xOrigin)*0.001f;
      //update cam dir
      lx = sin(angle + da);
      lx = - cos(angle + da);
   } else da = 0.0f ;
}

void pos(float dx){
x += dx * lx * FRACTION;
z += dx * lz * FRACTION;
}

void dir(float da)
{
angle += da;
lx = sin(angle);
lz = -cos(angle);

}


void pressKey(int key , int xx , int yy){
   switch (key) {
      case GLUT_KEY_LEFT : da += -0.01f ; break;
      case GLUT_KEY_RIGHT : da += 0.01f; break;
      case GLUT_KEY_UP : dx += 0.5f; break;
      case GLUT_KEY_DOWN : dx += -0.5f; break;

   }
}

void releaseKey(int key , int xx , int yy){
   switch (key) {

      case GLUT_KEY_LEFT :
      case GLUT_KEY_RIGHT : da = 0.0f; break;
      case GLUT_KEY_UP :
      case GLUT_KEY_DOWN : dx = 0; break;

   }
}

void drawbody() {
   glColor3f(0.0f,1.0f,1.0f);
   //code for body
   glTranslatef(0.0f,0.75f,0.0f);
   glutSolidSphere(0.75f,20,20);
   // code for head
   glColor3f(1.0f,0.0f,1.0f);
   glTranslatef(0.0f,1.0f,0.0f);
   glutSolidSphere(0.25f,20,20);
   // code for the eye
   glPushMatrix();
   glColor3f(0.0f,0.0f,0.0f);
   glTranslatef(0.05f,0.10f,0.18f);
   glutSolidSphere(0.05f,10,10);
   glTranslatef(-0.1f,0.0f,0.0f);
   glutSolidSphere(0.05f,10,10);
   glPopMatrix();
   // code for nose
   glColor3f(1.0f,0.5f,0.5f);
   glutSolidCone(0.08f,0.5f,10,2);

}


void KeyUseMan(unsigned char key, int xx ,int yy){

      switch (key) {

         case  27 :
            exit(0);
            break;
         /*
         case  GLUT_KEY_LEFT  :
            angle -= 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
         case  GLUT_KEY_RIGHT  :
            angle += 0.01f;
            lx = sin(angle);
            lz = -cos(angle);
            break;
         case  GLUT_KEY_UP  :
            x += lx * FRACTION;
            z += lz * FRACTION;
            break;
         case  GLUT_KEY_DOWN  :
            x -= lx * FRACTION;
            z -= lz * FRACTION;
            break;
         */


      }

 /*        else if (key == 'r') {
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT)
                  red = 0.0;
            else
                  red = 1.0;
         }
         else if (key == 'g') {
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT)
                  green = 0.0;
            else
                  green = 1.0;
         }

         else if (key == 'b') {
            int mod = glutGetModifiers();
            if (mod == GLUT_ACTIVE_ALT)
                  blue = 0.0;
            else
                  blue = 1.0;
         }*/
}

void renderScene(void) {
 if(dx)
    pos(dx);
 if(da)
   dir(da);
   // clear Colour and depth buffers
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // reset transormations
   glLoadIdentity();
   // set the camera
   gluLookAt(
         x     , 1.0f, z,
         x + lx, 1.0f, z + lz,
         0.0f, 1.0f, 0.0f);
  // glRotatef(angle, 1.0f, 1.0f, 1.0f);
  //set colours
   glColor3f(red,green,blue);
   //drawbody();
   //glBegin(GL_TRIANGLES);
   //glVertex3f(-2.0f, -2.0f,0.0f);
   //glVertex3f(2.0f, 0.0f, 0.0f);
   //glVertex3f(0.0f, 2.0f, 0.0f);
   //glEnd();
   //angle += 0.1f;
   // glutSwapBuffers();
   glBegin(GL_QUADS);
      glVertex3f(-100.0f,0.0f,-100.0f);
      glVertex3f(-100.0f,0.0f,100.0f);
      glVertex3f(100.0f,0.0f,100.0f);
      glVertex3f(100.0f,0.0f,-100.0f);
   glEnd();
   for (int i = -3; i < 3 ; i++)
      for (int j = -3 ; j < 3 ; j++) {
         glPushMatrix();
         glTranslatef(i*10.0,0,j*10.0);
         drawbody();
         glPopMatrix();
      }
   glutSwapBuffers();
}



//the things which are to be taken care on the resize of the window size are given below
void windowChange(GLsizei w , GLsizei h ) {
 if (h == 0)
    h=1; //preventing from getting infinity by x / 0 ;-)
 float aspect = w / h ;
  //projection matrics
  glMatrixMode(GL_PROJECTION);
  //reset matrix
  glLoadIdentity();
  //view point to max window size;
  glViewport(0,0,w,h);
  gluPerspective(45,aspect,1,1000);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

//printf("GL_VERSION= %s\n",GL_VERSION);
      // init GLUT and create Window
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowPosition(100,100);
   glutInitWindowSize(320,320);
   glutCreateWindow("body");
   // register callbacks
   glutDisplayFunc(renderScene);
   //call to take care of resize
   glutReshapeFunc(windowChange);
   glutIdleFunc(renderScene);
   glutKeyboardFunc(KeyUseMan);
   //glutSpecialFunc(KeyUseMan);
   glutSpecialFunc(pressKey);
   // ignore repeat
   glutIgnoreKeyRepeat(1);
   glutSpecialUpFunc(releaseKey);
   // mouse call back functions
   glutMouseFunc(mouseButton);
   glutMotionFunc(mouseMove);
   //OpenGL init
   glEnable(GL_DEPTH_TEST);

   // enter GLUT event processing cycl
   glutMainLoop();
   return 1;
}
