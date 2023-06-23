#include<GL/glut.h>
#include<math.h>

void display()
{
	glClearColor(0.0f,0.5f,0.5f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
        glTranslatef(-1.0,-1.0,0.0);
    // Translate to the bottom left corner of the window
        glPushMatrix();
         glRotatef(180,0.0,1.0,0.0);
   
    // Define the radius and number of segments for the curved rectangle
    float radius = 0.7;
    int numSegments = 20;

    // Draw the curved rectangle
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(radius, radius);  // Center of the rectangle

    for (int i = 0; i <= numSegments; ++i)
    {
        float angle = i * 3.0 * M_PI / numSegments;
        float x = radius * cos(angle);
        float y = radius * sin(angle);
        glVertex2f(x, y);
    }

    glEnd();
        glPopMatrix();

    glFlush();
	glutSwapBuffers();
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);//used to initialize the environment initial setup
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(800,800);
	glutInitWindowPosition(1,0);
	glutCreateWindow("Flappy Cloud");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
