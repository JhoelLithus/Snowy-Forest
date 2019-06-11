#ifndef FLOWER_H_
#define FLOWER_H_

#include <iostream>
#include <string>

#include "Turtle.h"

/**

* @file Flower.h
* @version 1.0
* @date 09/05/2019
* @autor Jhoel Huallpar Dorado
* @title Class Flower.h
	
*/

using namespace std;

// FLOWER Create class Petal
/** 
Declaracion de la Clase Petal: La cual declara 
los datos PRIVADOS
" Las variable que van ser usadas a lo largo de todo la clase "
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Petal te permite dibujar los petalos de una flor.
*/
class Petal
{
	/** 
	En el " Public " van todas las funciones que el usuario va a utilizar.
	*/
    public:
    	/** 
		La funcion Draw de la clase Petal dibuja el petalo de una flor. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
       void Draw(Turtle t)
       {
       		t.reset();
   			t.positionini(-0.3, -0.03);
   			t.setvalue(0.0);
   			
	       	for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 10; j++)
			  	{
			  
			    	for (int k = 0; k < 4; k++)
					{
			          	t.forward(0.02);
			      		t.right(90);
			    	}
			   		t.forward(0.02);
			  	}
			  	t.right(80);
			}
	   }
};

//FLOWER Create class Stigma
/** 
Declaracion de la Clase Stigma: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La funcion Draw de la clase Stigma te permite dibujar el estigma de una flor.
*/
class Stigma
{
	/** 
	En el " Public " van todas las funciones que el usuario va a utilizar.
	*/
    public:
    	/** 
		La funcion Draw de la clase Stigma dibuja el petalo de una flor. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
        void Draw(Turtle t)
        {
        	t.reset();
   			t.positionini(-0.2, -0.08);
   			t.setvalue(0.0);
   			
   			glColor3d(1.0, 0.0, 0.0);
			     			
	        for (int i = 0; i < 360; i++) 
			{
				t.forward(0.0012);
			  	t.right(1);
			}
		}
};

//Class Flower
/** 
Declaracion de la Clase Flower: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Flower contiene a las clases Petal y Stigma. porque una flor esta compuesta por petalos y un estigma.
*/
class Flower
{
	/** En el " Public " van todas las funciones que el usuario va a utilizar */
    public:
    	/** @brief La clase flower llama a las clases, las cuales contiene; porque una flor esta compuestos de petalos y estigma. */
		/** @param Petal* petal -> Apunta a las direccion de la clases Petal y de sus funciones */
		/** @param Stigma* stigma -> Apunta a las direccion de la clases Stigma y de sus funciones */
        Petal* petal;
        Stigma* stigma;
        /** 
		@brief La funcion Draw de la clase Flower dibuja el petalo y el estigma de una flor. con la Libreria Turtle, la cual ya fue creada anteriormente.
		*/
		/** @param Turtle t -> Llama a la clase Turtle para que utilice las diferentes funciones de esta clase solo en esta funcion. */
        void Draw(Turtle t)
        { 
        	/** petal->Draw(t) -> Llama a funcion Draw de la clase Petal */
            petal->Draw(t);
            /** stigma->Draw(t) -> Llama a funcion Draw de la clase Petal */
            stigma->Draw(t);
        }
};

//Class Builder
/** 
Declaracion de la Clase Builder: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Builder, "Es un patron de diseño", la cual crea diferentes objetos.
*/
class Builder
{
    public:
        virtual Petal* getPetal()= 0;
        virtual Stigma* getStigma()= 0;
};

//Class Basic Flower
/** 
Declaracion de la Clase BasicFlower: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase BasicFlower Crea un tipo de FLOR, dependiendo de ciertas caracteristicas, en este caso solo es una flor basica.
Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
*/
class BasicFlower : public Builder
{
	/**
	Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
	*/
    public:
    	
        Petal* petal;
        Stigma* stigma;
        
        void setPetal()
        {
            petal = new Petal();
        }
        Petal* getPetal()
        {
            return petal;
        }
        
        void setStigma()
        {
            stigma = new Stigma();
        }
        Stigma* getStigma()
        {
            return stigma;
        } 
};

//Clase Director
/** 
Declaracion de la Clase Director: La cual declara 
los  dato PUBLICOS
" Declara las funcion que seran utilizadas por el usuario ".
La clase Director Seleciona el tipo de flor de acuerdo a las a lo que necestice el usuario.
Dentro la  funcion public se utiliza las funciones Get y SET, para asi no modificar los datos originales.
*/
class Director
{
    Builder* builder;

    public:
        void setBuilder(Builder* newBuilder)
        {
            builder = newBuilder;
        }

        Flower* getBuilder()
        {
            Flower* flower = new Flower();
            BasicFlower* basic=new BasicFlower();
            flower->petal = basic->getPetal();
            flower->stigma = basic->getStigma();
            
            return flower;
        }

        Flower* getFlower()
        {
            Flower* flower = new Flower();

            flower->petal = builder->getPetal();
            flower->stigma = builder->getStigma();

            return flower;
        }
};
#endif
