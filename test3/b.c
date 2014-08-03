/*
 * this is a sample file coded solving tutorial from teh
 *web site "http://www.lighthouse3d.com"
 * the max code is from the site but configured to run on mac
 * for better navigation use vim
 *
 */
#include <stdio.h>
#include <stdlib.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
//#define N 4
GLdouble width , height;
//defining the ints holding the vertices
GLuint vertexArray, vertexBuffer;

//cudedata enter

GLfloat gCubeVertexData[216] =
{
       // Data layout for each line below is:
       //     // positionX, positionY, positionZ,     normalX, normalY, normalZ,
       //
0.5f, -0.5f, -0.5f,        1.0f, 0.0f, 0.0f,
0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f,
0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f,
0.5f, -0.5f, 0.5f,         1.0f, 0.0f, 0.0f,
0.5f, 0.5f, -0.5f,         1.0f, 0.0f, 0.0f,
0.5f, 0.5f, 0.5f,          1.0f, 0.0f, 0.0f,

0.5f, 0.5f, -0.5f,         0.0f, 1.0f, 0.0f,
-0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f,
0.5f, 0.5f, 0.5f,          0.0f, 1.0f, 0.0f,
-0.5f, 0.5f, -0.5f,        0.0f, 1.0f, 0.0f,
-0.5f, 0.5f, 0.5f,         0.0f, 1.0f, 0.0f,

-0.5f, 0.5f, -0.5f,        -1.0f, 0.0f, 0.0f,
-0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f,
-0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f,
-0.5f, 0.5f, 0.5f,         -1.0f, 0.0f, 0.0f,
-0.5f, -0.5f, -0.5f,       -1.0f, 0.0f, 0.0f,
-0.5f, -0.5f, 0.5f,        -1.0f, 0.0f, 0.0f,

-0.5f, -0.5f, -0.5f,       0.0f, -1.0f, 0.0f,
0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f,
-0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f,
-0.5f, -0.5f, 0.5f,        0.0f, -1.0f, 0.0f,
0.5f, -0.5f, -0.5f,        0.0f, -1.0f, 0.0f,
0.5f, -0.5f, 0.5f,         0.0f, -1.0f, 0.0f,

0.5f, -0.5f, -0.5f,        0.0f, 0.0f, -1.0f,
-0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f,
0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f,
0.5f, 0.5f, -0.5f,         0.0f, 0.0f, -1.0f,
-0.5f, -0.5f, -0.5f,       0.0f, 0.0f, -1.0f,
-0.5f, 0.5f, -0.5f,        0.0f, 0.0f, -1.0f,

0.5f, 0.5f, 0.5f,          0.0f, 0.0f, 1.0f,
-0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f,
0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f,
0.5f, -0.5f, 0.5f,         0.0f, 0.0f, 1.0f,
-0.5f, 0.5f, 0.5f,         0.0f, 0.0f, 1.0f,
-0.5f, -0.5f, 0.5f,        0.0f, 0.0f, 1.0f
};
//cubedata end

void initGL(){
   glClearColor(0.0,0.0,0.0,1.0);
   glClearDepth(1.0);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

   }

void display(void){

   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(1.5f, 0.0f, -7.0f);
   glBegin(GL_QUADS);
   // Front
   glColor3f(0.0f, 1.0f, 0.0f);     // Green
   glVertex3f( 1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f( 1.0f, 1.0f, 1.0f);
   // Bottom face (y = -1.0f)
   glColor3f(0.0f, 1.0f, 0.0f); // Orange
   glVertex3f( 1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f( 1.0f, -1.0f, -1.0f);
   // Front face (z = 1.0f)
   glColor3f(0.0f, 0.0f, 1.0f); // Red
   glVertex3f( 1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f( 1.0f, -1.0f, 1.0f);
   // Back face (z = -1.0f)
   glColor3f(0.0f, 0.0f, 1.0f); // Yellow
   glVertex3f( 1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f( 1.0f, 1.0f, -1.0f);
   // Left face (x = -1.0f)
   glColor3f(1.0f, 1.0f, 1.0f); // Blue
   glVertex3f(-1.0f, 1.0f, 1.0f);
   glVertex3f(-1.0f, 1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   // Right face (x = 1.0f)
   glColor3f(0.0f, 0.0f, 0.0f); // Magenta
   glVertex3f(1.0f, 1.0f, -1.0f);
   glVertex3f(1.0f, 1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, 1.0f);
   glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd();
   glLoadIdentity();

   glTranslatef(-1.5f,0.0f,-6.0f);
   glutSwapBuffers();
}

void reshape (GLsizei w , GLsizei h)
{

   width = (GLdouble) w;
   height = (GLdouble) h;
   GLfloat aspect;
   //if(width > height) it is only compressing the x with respective to aspect.
   aspect = (GLfloat)width / (GLfloat)height;
   //else
   //aspect = (GLfloat)height / (GLfloat)width;

   glViewport(0, 0, width, height);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);// Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE);
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("Test3"); // Create a window with the given title
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutReshapeFunc(reshape);
   initGL();
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
