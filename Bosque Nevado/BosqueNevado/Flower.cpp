#include <iostream>
#include <string>
#include "Flower.h"

using namespace std;

void drawsnow()   //Funcion Dibujar
{
	
	Flower* flower;
	Turtle t;
    Director director;
    BasicFlower basicflower;

    director.setBuilder(&basicflower);
    flower = director.getFlower();
    flower->Draw(t);

    cout <<endl<<endl;
/*
    //Build a Complex Tree
    //cout << "Complex Tree" <<endl<<endl;
    director.setBuilder(&complexflower);
    flower = director.getFlower();
    flower->specifications();
*/
}
/** " display() " esta funcion esta relacionada a la libreria opengl, la cual nos permite dibujar diferentes objetos */
void display()
{
   glClear(GL_COLOR_BUFFER_BIT);

   glLineWidth(0.07);  //Grosor de linea
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

