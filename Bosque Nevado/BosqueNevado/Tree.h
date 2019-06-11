#ifndef TREE_H_
#define TREE_H_

#include <iostream>
#include <string>

#include "Turtle.h"
/**

* @file Tree.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Tree.h
	
*/
using namespace std;

// TREE Create class Trunk
/** 
Declaracion de la Clase Trunk: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Trunk te permite dibujar el tronco de un arbol.
*/
class Trunk
{
	/** 
	En el " Public " van todas las funciones que el usuario va a utilizar.
	*/
    public:
    	/** 
		La funcion Draw de la clase Trunk dibuja el tronco de una arbol. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
       void Draw(Turtle t)
       {
       		t.reset();
   			t.positionini(-0.5, -0.8);
   			t.setvalue(0.0);
   			
	        t.forward(0.15);
	       	t.left(90);
	       	t.forward(1.2);
	       	t.left(90);
	       	t.forward(0.15);
	       	t.left(90);
	       	t.forward(1.2);
	   }
};

//TREE Create class Branch
/** 
Declaracion de la Clase Branch: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Branch te permite dibujar la rama de un arbol.
*/
class Branch
{
    public:
    	/** 
		La funcion Draw de la clase Branch dibuja la rama de un arbol. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
        void Draw(Turtle t)
        {
        	t.reset();
   			t.positionini(-0.35, 0.2);
   			t.setvalue(0.0);
   			
	        t.forward(0.6);
	       	t.left(90);
	       	t.forward(0.1);
	       	t.left(90);
	       	t.forward(0.6);
	       	t.left(90);
	       	t.forward(0.1);
		}
};
/** 
Declaracion de la Clase Leaf: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Leaf te permite dibujar la hoja de un arbol.
*/
class Leaf
{
    public:
    	/** 
		La funcion Draw de la clase Leaf dibuja la hoja de un arbol. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
        void Draw(Turtle t)
        {
        	t.reset();
   			t.positionini(0.25, 0.2);
   			t.setvalue(0.0);
   	
			glColor3f(0.0, 1.0, 0.0);
		    t.forward(0.05);
		    t.left(60);
		    t.forward(0.05);
		    t.right(120);
		    t.forward(0.05);
		    t.right(60);
		    t.forward(0.05);
		    
		    t.left(60);
		    t.forward(0.05);
		    t.right(120);
		    t.forward(0.05);
		    t.right(60);
		    
		    t.forward(0.05);
		    t.left(60);
		    t.forward(0.05);
		    t.right(120);
		    t.forward(0.05);
		    t.right(60);
		    t.forward(0.05);
		}
};

//Class Tree
/** 
Declaracion de la Clase Tree: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Tree contiene a las clases Trunk, Branch y Leaf. porque un arbol esta compuesta por tronco, ramas y hojas.
*/
class Tree
{
	/** En el " Public " van todas las funciones que el usuario va a utilizar */
    public:
    	/** @brief La clase Tree llama a las clases, las cuales contiene; porque un arbol esta compuesta por tronco, ramas y hojas */
		/** @param Trunk* trunk -> Apunta a las direccion de la clases Trunk y de sus funciones */
		/** @param Branch* branch -> Apunta a las direccion de la clases Branch y de sus funciones */
        /** @param Leaf* leaf -> Apunta a las direccion de la clases Leaf y de sus funciones */
		Trunk* trunk;
        Branch* branch;
        Leaf* leaf;
    	 /** 
		@brief La funcion Draw de la clase Tree dibuja el tronco, las ramas y la hoja de un arbol. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
        void Draw(Turtle t)
        { 
        	/** trunk->Draw(t) -> Llama a funcion Draw de la clase Trunk */
            trunk->Draw(t);
            /** branch->Draw(t) -> Llama a funcion Draw de la clase Branch */
            branch->Draw(t);
            /** leaf->Draw(t) -> Llama a funcion Draw de la clase Leaf */
            leaf->Draw(t);

        }
};

//Class TBuilder
/** 
Declaracion de la Clase Builder: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Builder, "Es un patron de diseño", la cual crea diferentes objetos.
*/
class TBuilder
{
    public:
        virtual Trunk* getTrunk()= 0;
        virtual Branch* getBranch()= 0;
        virtual Leaf* getLeaf()= 0;
};


//Class Basic Tree
/** 
Declaracion de la Clase BasicTree: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase BasicTree Crea un tipo de ARBOL, dependiendo de ciertas caracteristicas, en este caso solo es un arbol basica.
Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
*/
class BasicTree : public TBuilder
{
	/**
	Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
	*/
    public:
        Trunk* trunk;
        Branch* branch;
        Leaf* leaf;
        
        void setTrunk()
        {
            trunk = new Trunk();
        }
        Trunk* getTrunk()
        {
            return trunk;
        }
        
        void setBranch()
        {
            branch = new Branch();
        }
        Branch* getBranch()
        {
            return branch;
        }
        
        void setLeaf()
        {
            leaf = new Leaf();
        }
        Leaf* getLeaf()
        {
            return leaf;
        } 
};

//Clase Director
/** 
Declaracion de la Clase Director: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Director Seleciona el tipo de arbol de acuerdo a las a lo que necestice el usuario.
Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
*/
class TDirector
{
    TBuilder* Tbuilder;

    public:
        void setBuilder(TBuilder* newBuilder)
        {
            Tbuilder = newBuilder;
        }

        Tree* getBuilder()
        {
            Tree* tree = new Tree();
            BasicTree* basic=new BasicTree();
            tree->trunk = basic->getTrunk();
            tree->branch = basic->getBranch();
            tree->leaf = basic->getLeaf();
            
            return tree;
        }

        Tree* getTree()
        {
            Tree* tree = new Tree();

            tree->trunk = Tbuilder->getTrunk();
            tree->branch = Tbuilder->getBranch();
            tree->leaf = Tbuilder->getLeaf();

            return tree;
        }
};
#endif
