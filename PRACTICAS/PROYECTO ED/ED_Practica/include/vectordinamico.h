/**
  * @file vectordinamico.h
  * @brief Fichero cabecera de la plantilla de vector dinamico
  * @date Octubre 2019
  */
#ifndef _VD_H
#define _VD_H

/**
 * @brief Define una clase plantilla de vector dinamico 
 * @tparam T Tipo generico para usar el vector dinamico.
 */

template <class T>

/**
  *  @brief T.D.A. VD
  *
  *  Una instancia @e c del tipo de datos abstracto @c VD es un objeto
  *  que contiene un puntero de tipo T, un numero n con el tamanio del vector 
  *  y un reservados con el espacio total reservado. Tambien cuenta con 
  * funciones privadas que reajustan el tamanio, copian un vector dinamico en 
  * el objeto implicito y un liberar que libera la memoria del puntero datos.
  *
  * @author Angel Solano Corral 
  * @author Javier Ramirez Pulido
  * @date Octubre 2019
  */

class VD{
	
	private:
            /**
            * @page repVD Rep del TDA VD
            *
            * @section invVD Invariante de la representacion
            *
            * El invariante es 
            * 0<=n<=reservados,
            * reservados>=0.
            * 
            * @section faVD Funcion de abstraccion
            * Un objeto valido rep del TDA VD representa al vector de tamanio n:
            * { datos[0], datos[1], ..., datos[n-1] }
            */
		T *datos; /**< puntero de tipo T */
		int n; /**< tamanio de datos ocupado */
		int reservados; /**< espacio reservado para datos */
		/**
                * @brief Modifica el espacio reservado de datos
                * @param nuevo_tam el nuevo espacio reservado para datos 
                * @pre nuevo_tam no puede ser menor que el reservados actual 
                * o se perderian datos
                */
                void resize(int nuevo_tam);
                /**
                * @brief Copia en el objeto implicito el vector dinamico pasado 
                * como parametro
                * @param v vector dinamico del que copiar los datos
                */
		void copiar(const VD<T> &v);
                /**
                * @brief Libera memoria ocupada por el puntero datos del objeto
                * implicito
                */
		void liberar();
	public:
                /**
                * @brief Constructor de la clase con parametros
                * @param tam el espacio reservado para datos y el tamanio con el 
                * que se inicializa el vector. Por defecto tiene el valor 10
                * @return Crea el vector dinamico con esas dimensiones y el
                * numero de usados n en 0 porque esta vacio.
                * @pre tam >= 0
                */
		VD(int tam=10);
                /**
                * @brief Constructor por copia de la clase
                * @param original el vector dinamico del que se copian los datos
                * en el objeto implicito que se esta creando
                * @return Crea el vector dinamico con las mismas caracteristicas
                * que el vector dinamico pasado como parametro.
                */
		VD(const VD<T> &original);
                /**
                * @brief Destructor de la clase que siempre que el vector datos
                * no este vacio pone n y reservados a 0 y libera el espacio 
                * ocupado por el puntero datos
                */
		~VD();
                /**
                * @brief Sobrecarga del operador =
                * @param o vector dinamico que asignar al objeto implicto 
                * @return Devuelve el objeto implicito que tras ser modificado
                * tiene las mismas caracteristicas que el vector dinamico 
                * pasado como parametro
                */  
		VD<T> &operator=(const VD<T> &o);
                /**
                * @brief Sobrecarga del operador []
                * @param i posicion que quiero devolver/modificar del puntero 
                * datos del objeto de tipo VD implicito
                * @return Devuelve el valor almacenado en esa posicion del
                * puntero datos
                */  
		T &operator[](int i){return datos[i];}
                /**
                * @brief Sobrecarga del operador [] constante, valor no 
                * modificable usado para ser asignado
                * @param i posicion que quiero devolver del puntero datos del 
                * objeto de tipo VD implicito
                * @return Devuelve el valor almacenado en esa posicion del
                * puntero datos
                */  
		const T &operator[](int i)const{return datos[i];}
                /**
                * @brief Consultor del tamanio usado por el puntero datos
                * @return Devuelve el tamanio del puntero de datos del objeto 
                * implicito
                */
		int size()const{return n;}
                /**
                * @brief Comprueba si el tamanio ocupado es el maximo posible 
                * dentro de los reservados, y si lo es, utiliza la funcion
                * resize() para duplicar el espacio reservado de datos. Tras 
                * esto, inserta en la posicion pos el dato nuevo, haciendo las 
                * correspondientes modificaciones en el resto de posiciones.
                * @param dato Nuevo dato de tipo T a aniadir en datos 
                * @param pos Posicion en la que aniadir dato
                */
		void Insertar(const T &dato, int pos);
                /**
                * @brief Borra el elemento que se encuentra en la posicion 
                * pasada como parametro en pos. Si el tamanio utilizado de datos
                * es menor que una cuarta parte del espacio reservado para este
                * se reduce reservados a la mitad de tamanio.
                *  
                * @param pos posicion del dato a borrar de datos
                */
		void Borrar(int pos);
               
};

#include "vectordinamico.cpp"
#endif

