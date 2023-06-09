#include <iostream>
#include <math.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

using namespace std;

double X1, Y1, X2, Y2;

void LineDDA(void)
{
  double dx = (X2 - X1);
  double dy = (Y2 - Y1);
  double steps;
  float xInc, yInc, x = X1, y = Y1;

  steps = (abs(dx) >= abs(dy)) ? (abs(dx)) : (abs(dy));
  xInc = dx / (float)steps;
  yInc = dy / (float)steps;

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POINTS);
  glVertex2d(x, y);
  int k;
  for (k = 1; k <= steps; k++)
  {
    x += xInc;
    y += yInc;
    glVertex2d(x, y);
  }
  glEnd();

  glLineWidth(5);
  glBegin(GL_LINES);
  glVertex2i(glutGet(GLUT_WINDOW_WIDTH) / 2, 0);
  glVertex2i(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_HEIGHT));
  glVertex2i(0, glutGet(GLUT_WINDOW_HEIGHT) / 2);
  glVertex2i(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT) / 2);
  glEnd();

  glFlush();
}

void Init()
{
  glClearColor(0.0, 1.0, 0.0, 0);
  glColor3f(0.0, 0.0, 0.0);
  gluOrtho2D(0, 640, 0, 480);
}

int main(int argc, char **argv)
{
  cout << "Enter two end points of the line to be drawn:\n";
  cout << "Enter Point1(X1, Y1):\n";
  cin >> X1 >> Y1;
  cout << "Enter Point2(X2, Y2):\n";
  cin >> X2 >> Y2;

  X1 = X1 + 320;
  Y1 = Y1 + 240;
  X2 = X2 + 320;
  Y2 = Y2 + 240;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(640, 480);
  glutCreateWindow("DDA_Line");
  Init();
  glutDisplayFunc(LineDDA);
  glutMainLoop();

  return 0;
}


