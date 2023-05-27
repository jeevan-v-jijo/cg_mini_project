#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define WIDTH 800
#define HEIGHT 600

// Bird position
float bird_x = WIDTH / 4;
float bird_y = HEIGHT / 2;
float bird_radius = 20;

// Bird jump velocity
float jump_velocity = 0;
float gravity = 0.2;

// Bird jump variables
int is_jumping = 0;

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(0, 0, 0, 1);
}

void drawBird()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1, 1, 0);
    float x, y;
    for (int i = 0; i < 360; i++)
    {
        x = bird_x + bird_radius * cos(i * 3.14159 / 180.0);
        y = bird_y + bird_radius * sin(i * 3.14159 / 180.0);
        glVertex2f(x, y);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    drawBird();

    glFlush();
    glutSwapBuffers();
}

void update(int value)
{
    if (is_jumping)
    {
        // Apply gravity to the bird
        jump_velocity -= gravity;
        bird_y += jump_velocity;

        // Check if bird has touched the ground
        if (bird_y <= bird_radius)
        {
            bird_y = bird_radius;
            jump_velocity = 0;
            is_jumping = 0;
        }
    }

    // Redraw the scene
    glutPostRedisplay();

    // Update the scene every 10 milliseconds
    glutTimerFunc(10, update, 0);
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 32) // Space key
    {
        // Increment the jump velocity on each space bar press
        jump_velocity += 5;

        // Set the jumping flag
        is_jumping = 1;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Flappy Bird");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
