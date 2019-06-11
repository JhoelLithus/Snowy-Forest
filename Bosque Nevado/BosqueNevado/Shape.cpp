#include <sstream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#include "Shape.h"
/**

* @file Shape.cpp
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title SHAPE	
	
*/
using namespace std;
Turtle t;

/** "keyboard() " esta funcion permite dibujar las diferentes figuras utilizando el teclado. */
void keyboard(unsigned char key, int x, int y)
{
   	AbstractSimple* abst =new PaintElaborado();
	Tree* a = abst->getTree();
	Flower* f = abst->getFlower();
	Snow* n = abst->getSnow();
	switch (key)
	{	
		case 27:             // ESCAPE key
			exit (0);
		break;	
		case 'a':
			a->Draw(t);
		break;
		case 'f':
			f->Draw(t);
		break;
		case 'n':
			n->Draw(t);
		break;
	}
}
/** " printbitmap() " esta funcion esta relacionada a la libreria opengl, la cual nos permite colocar texto a la interfaz */
void printbitmap(const string msg, double x, double y)
{
   glRasterPos2d(x, y);
   for (string::const_iterator ii = msg.begin(); ii != msg.end(); ++ii)
    	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *ii);
}
/** " display() " esta funcion esta relacionada a la libreria opengl, la cual nos permite dibujar diferentes objetos */
void display()
{
   glLineWidth(1.0);  //Grosor de linea
   glColor3d(0.5, 0.0, 0.9); //Color del dibujo

	    printbitmap("Salir = ESC", -0.9, 0.9);
	    printbitmap("Arbol = a", -0.8, 0.7);
	    printbitmap("Flor = f", -0.2, 0.7);
	    printbitmap("Nieve = n", 0.4, 0.7);
   glFlush();
}

/** " main() " El main es la ventana principal, la función main se encarga de dirigir el algoritmo que da solución al mismo. */
int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

   	glutInitWindowSize(500, 500);  //tamaño de la pantalla
   	glutInitWindowPosition(50, 50);
   	glutCreateWindow("Turtle C++");
	  
   	glutDisplayFunc(display); // Pantalla de Graficos
   	glutKeyboardFunc(*keyboard);
	glClearColor(1.0, 1.0, 1.0, 0.0);  //Fondo
	glFlush();
   	glutMainLoop();

    return 0;
}
