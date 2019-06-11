/**

* @file Turtle.cpp
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Turtle
	
*/

#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <GL/glut.h> 

#include "turtle.h"
using namespace std;

Turtle t;
/** "drawsnow() " esta funcion permite dibujar las diferentes figuras utilizando las funciones de Turtle. */
void drawsnow()   //Funcion Dibujar
{
   	t.reset();
   	t.positionini(-0.5, -0.2);
   	t.setvalue(0.0);
   	

	    t.forward(0.1);
	    t.left(60);
	    t.forward(0.1);
	    t.right(120);
	    t.forward(0.1);
	    t.right(60);
	    t.forward(0.1);
	    
	    //t.forward(0.1);
	    t.left(60);
	    t.forward(0.1);
	    t.right(120);
	    t.forward(0.1);
	    t.right(60);
	    //t.forward(0.1);
	    
	    t.forward(0.1);
	    t.left(60);
	    t.forward(0.1);
	    t.right(120);
	    t.forward(0.1);
	    t.right(60);
	    t.forward(0.1);
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

/** " main() " El main es la ventana principal, la función main se encarga de dirigir el algoritmo que da solución al mismo. */
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
