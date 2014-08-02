#include <stdio.h>
#include <stdlib.h>
#if defined(__APPLE__)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


void display(void){
   glClearColor(0.0,0.0,0.0,1.0);
   glClear(GL_COLOR_BUFFER_BIT);

   glColorMask(1.0,0.0,0.0,0.0);
   glBegin(GL_QUADS);
      glVertex2f(-0.5 ,-0.5);
      glVertex2f(0.5 ,-0.5);
      glVertex2f(0.5 ,0.5);
      glVertex2f(-0.5 ,0.5);
   glEnd();
   glFlush();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);// Initialize GLUT
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
