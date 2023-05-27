#include<GL/glut.h>
#include<math.h>
void display()
{

	glClear(GL_COLOR_BUFFER_BIT);
	    // Set the viewport
    	glViewport(0, 0, 800, 600);

    	// Set the projection matrix
    	glMatrixMode(GL_PROJECTION);
    	glLoadIdentity();
    	glOrtho(0, 800, 0, 600, -1, 1);

    	// Set the modelview matrix
    	glMatrixMode(GL_MODELVIEW);
    	glLoadIdentity();

    	// Draw a circle
    	glColor3f(1.0f, 0.0f, 0.0f);  // Set color to red
   	 glTranslatef(100.0f, 300.0f, 0.0f);  // Translate to the left side of the screen
   	 int numSegments = 100;
   	 float radius = 50.0f;
   	 glBegin(GL_TRIANGLE_FAN);
   	 glVertex2f(0.0f, 0.0f);  // Center of the circle
   	 for (int i = 0; i <= numSegments; ++i) {
       		 float angle = i * (2.0f * M_PI / numSegments);
        	float x = radius * cos(angle);
        	float y = radius * sin(angle);
        	glVertex2f(x, y);
   	 }
   	 glEnd();
	glutSwapBuffers();
	
}

int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800,800);
	glutCreateWindow("opengl test");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
