#ifndef SHAPE_H_
#define SHAPE_H_

#include<iostream>

#include "Tree.h"
#include "Flower.h"
#include "Particle.h"

using namespace std;

/**

* @file Shape.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Shape.h
	
*/
/** 
Declaracion de la Clase AbstractSimple: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
*/
class AbstractSimple
{
	public:
		/**
		los datos publicos de la clase Abstract Hace referencia a la clase Tree, Flower y Particle,
		ademas de estos deben ser de tipo virtual.
		virtual Tree* getTree()=0 -> Hace referencia a getTree de la clase Tree
		virtual Flower* getFlower()=0 -> Hace referencia a getFlower de la clase Flower
		virtual Particle* getParticle()=0 -> Hace referencia a getParticle de la clase Particle
		*/
		virtual Tree* getTree()=0;
		virtual Flower* getFlower()=0;
		virtual Snow* getSnow()=0;
	
};
/** 
La Clase PaintElaborado, hace referencia a las librerias Tree, Flower y Particle, con sus respectivas clases, metodos y funciones.
*/
class PaintElaborado:public AbstractSimple
{
	public:
		/** 
		Tree* getTree() -> realiza las funciones establecidad en la libreria Tree.h
		*/
		Tree* getTree()
		{
			Tree* tree;
		    TDirector Tdirector;
		    tree = Tdirector.getBuilder();
		    //tree->Draw(t);
		    
		    return tree;
		}
		/** 
		Flower* getFlower() -> realiza las funciones establecidad en la libreria Flower.h
		*/
		Flower* getFlower()
		{
			Flower* flower;
			Director director;
			flower=director.getBuilder();
			//flower->Draw(t);
				
			return flower;
		}
		/** 
		Particle* getParticle() -> realiza las funciones establecidad en la libreria Particle.h
		*/
		Snow* getSnow()
		{
			Snow *snow = new Snow(15);
			return snow;
		}
		
};
#endif
