#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;

void drawsnow()   //Funcion Dibujar
{
	
	Tree* tree;
	Turtle t;
    TDirector Tdirector;
    BasicTree basictree;

    Tdirector.setBuilder(&basictree);
    tree = Tdirector.getTree();
    tree->Draw(t);

    cout <<endl<<endl;

}
/** " display() " esta funcion esta relacionada a la libreria opengl, la cual nos permite dibujar diferentes objetos */
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glLineWidth(2.0);  //Grosor de linea
   glColor3d(0.5, 0.0, 0.9); //Color del dibujo
   drawsnow();  //Funcion que Grafica

   glMatrixMode(GL_PROJECTION);
   glPushMatrix();
	    glLoadIdentity();
	    gluOrtho2D(-1., 1., -1., 1.);
   
   glFlush();
}


int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   glutInitWindowSize(500, 500);  //tamaño de la pantalla
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Turtle C++");

	glClearColor(1.0, 1.0, 1.0, 0.0);  //Fondo
   //init();  // Color de fondo Blanco
   glutDisplayFunc(display); // Pantalla de Graficos
	
	Turtle t;
	t.forward(100);
   glutMainLoop();

    return 0;
}

