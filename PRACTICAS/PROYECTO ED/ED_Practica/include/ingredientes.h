/**
  * @file ingredientes.h
  * @brief Fichero cabecera del TDA Ingredientes
  * @date Octubre 2019
  */
#ifndef _Ingredientes_H
#define _Ingredientes_H
#include "ingrediente.h"
#include "vectordinamico.h"


using namespace std;

/**
  *  @brief struct Posicion
  *
  *  Una instancia @e c del tipo @c Posicion es un objeto
  *  que contiene un int position con un valor que muestra una posicion de algun
  *  vector y un bool esta con la informacion de si un elemento se encuentra 
  *  en ese mismo vector o no.
  *
  * @date Octubre 2019
  */

struct Posicion{

	int position;
	bool esta;

};
/**
  *  @brief T.D.A. Ingredientes
  *
  *  Una instancia @e c del tipo de datos abstracto @c Ingredientes es un objeto
  *  que contiene un vector dinamico de tipo ingrediente con el conjunto de 
  *  objetos Ingrediente ordenados alfabeticamente según su nombre y un vector
  *  dinamico de tipo int con los indices del vector datos ordenados 
  *  alfabeticamente por tipo y en caso de tener el mismo tipo, por nombre 
  *  alfabeticamente.
  *
  *
  * @author Angel Solano Corral 
  * @author Javier Ramirez Pulido
  * @date Octubre 2019
  */
class Ingredientes{

	private:
            /**
            * @page repIngredientes Rep del TDA Ingredientes
            *
            * @section invIngrediente Invariante de la representacion
            *
            * El invariante es 
            * datos.size()>=0,
            * indice.size()>=0.
            * 
            * @section faIngredientes Funcion de abstraccion
            * Un objeto valido rep del TDA Ingrediente representa al vector de 
            * tamanio n:
            * { rep.datos[0], rep.datos[1], ..., rep.datos[n-1] },
            * { rep.indice[0], rep.indice[1], ..., rep.indice[n-1] }
            *
            */
	    VD<Ingrediente> datos; /**< vector con ingredientes ordenados alfabeticamente por nombre */
	    VD<int> indice; /**< vector con posiciones de datos siguiendo un orden alfabetico por tipo y nombre */

	public:
		/**
                * @brief Constructor por defecto de la clase. Crea el objeto 
                * ingredientes con el vector datos y el vector indice vacios.
                */
                Ingredientes();
                /**
                * @brief Comprueba si el Ingrediente nuevo esta dentro del 
                * vector datos. Si no lo esta, lo aniade en la posicion indicada
                * para seguir el orden alfabetico por nombres y aniade su indice
                * en el vector Indice tambien ordenado pero por tipo, si ya se
                * encuentra dentro del vector no hace nada.
                *  
                * @param nuevo Ingrediente a aniadir en ambos vectores
                */
		void Insertar (const Ingrediente &nuevo);
		/**
                * @brief Comprueba si el Ingrediente nuevo esta dentro del 
                * vector datos. Si lo esta, lo borra actualizando la posicion
                * del resto de elementos y elimina el objeto del vector indice
                * actualizando el valor de las posiciones que se ven afectadas, 
                * si no lo encuentra dentro del vector, no hace nada.
                *  
                * @param ali nombre del Ingrediente a borrar de ambos vectores
                */
                void Borrar(const string &ali);
                /**
                * @brief Entrada de un objeto de tipo Ingredientes desde istream
                * @param is stream de entrada
                * @param ings Ingredientes que recibe el valor
                * @return El Ingredientes leido en ings
                * @pre La entrada sera leer ingrediente de is uno a uno mientras
                * se pueda e ir aniadiendolo en ings con la funcion insertar
                */
		friend istream &operator >> (istream &is, Ingredientes &ings);
                /**
                * @brief Salida de un objeto tipo Ingredientes a ostream
                * @param os stream de salida
                * @param ings Ingredientes a escribir
                * @post Se obtiene en \a os la cadena (nombre calorias 
                * HidratosDeCarbono Proteinas Grasas Fibra Tipo) tantas veces  
                * como elementos haya en el vector de datos, usando el 
                * operator<< de la clase ingrediente
                */
		friend ostream &operator << (ostream &os, Ingredientes &ings);
		/**
                * @brief llama al destructor tanto de datos como de indice
                */
                void Clear();
                /**
                * @brief Sobrecarga del operador []
                * @param pos posicion que quiero devolver/modificar del vector 
                * indice del objeto de tipo Ingredientes implicito
                * @return Devuelve el valor almacenado en esa posicion del
                * vector indice
                */  
                int &operator[](int pos);
                /**
                * @brief Sobrecarga del operador [] constante, valor no 
                * modificable usado para ser asignado
                * @param pos posicion que quiero devolver del vector indice del 
                * objeto de tipo Ingredientes implicito
                * @return Devuelve el valor almacenado en esa posicion del
                * vector indice
                */  
                const int &operator[](int pos)const;
                /**
                * @brief Consultor del elemento que se encuentra en la posicion
                * i del vector datos del objeto de tipo Ingredientes implicito
                * @param i posicion que quiero devolver del vector datos del 
                * objeto de tipo Ingredientes implicito
                * @return Devuelve el ingrediente que se encuentra en la 
                * posicion i de datos
                */
		Ingrediente getIngredientePorNombre(int i)const;
                /**
                * @brief Obtiene la informacion del ingrediente almacenado en el
                * vector datos con el nombre que le pasamos como parametro.
                * @param name nombre del ingrediente del cual quiero obtener  
                * la informacion
                * @return Devuelve una cadena de texto con la informacion 
                * completa del ingrediente 
                * @exception devuelve un mensaje de error si no existe ningun
                * ingrediente llamado como le pedimos
                */
		string getInformacionPorNombre(string name)const;
                /**
                * @brief Obtiene un objeto de tipo Ingredientes que contiene 
                * todos los ingredientes del tipo especificado en el parametro
                * @param tipo nombre del tipo del que quiero obtener todos los 
                * ingredientes del vector datos del objeto implicito
                * @return Devuelve un objeto de tipo Ingredientes que contiene 
                * todos los ingredientes del tipo especificado en el parametro 
                */
		Ingredientes getIngredientesPorTipo(string tipo);
                /**
                * @brief Sustituye el ingrediente que se encuentra en la 
                * posicion i del vector datos por el ingrediente ing pasado como 
                * parametro
                * @param i posicion del vector datos en el que tengo que 
                * insertar el otro parametro
                * @param ing ingrediente que tengo que insertar en datos en la 
                * posicion especificada 
                */
		void setIngrediente(int i, Ingrediente ing);
                /**
                * @brief Realiza un busqueda binaria recusiva que busca la 
                * posicion en el vector indice en la que deberia entrar el 
                * ingrediente nuevo segun su tipo y su nombre.
                * @param inicio Valor que indica el inicio del vector indice
                * @param final Valor que indica el final del vector indice
                * @param nuevo Ingrediente que quiero insertar en el vector y al
                * que se le busca posicion
                * @return Devuelve un objeto de tipo Posicion que contiene 
                * la posicion donde insertar y un booleano que indica si está
                * o no ese ingrediente 
                * @post Como el ingrediente previamente tiene que haber sido 
                * añadido en datos, el booleano que devuelve tiene que ser 
                * siempre false
                */
                Posicion buscarIndice(int inicio, int final, const Ingrediente &nuevo); 
                /**
                * @brief Realiza un busqueda binaria recursiva que busca la 
                * posicion en el vector datos en la que deberia ser añadido el 
                * ingrediente nuevo segun su nombre.
                * @param inicio Valor que indica el inicio del vector indice
                * @param final Valor que indica el final del vector indice
                * @param nuevo Ingrediente que quiero insertar en el vector y al
                * que se le busca posicion
                * @return Devuelve un objeto de tipo Posicion que contiene 
                * la posicion donde insertar y un booleano que indica si está
                * o no ese ingrediente 
                */
                Posicion buscarDatos(int inicio, int final, const Ingrediente &nuevo); //MODIFICARRRRRRRRRRRRRRR
                /**
                * @brief Realiza un busqueda binaria que busca la posicion en el
                * vector datos en la que deberia ser añadido un ingrediente 
                * segun el nombre pasado como parametro.
                * @param ali nombre del ingrediente al que hay que buscar la 
                * posicion correcta dentro del vector donde insertar
                * @return Devuelve un objeto de tipo Posicion que contiene 
                * la posicion donde insertar y un booleano que indica si está
                * o no ese ingrediente 
                */
                Posicion buscarDatosNombre(const string &ali);
                /**
                * @brief Realiza un busqueda binaria en el vector indice que 
                * busca en que posicion se encuentra almacenado el numero que se
                * le pasa como argumento.
                * @param index numero que es buscado entre los valores 
                * almacenados por el vector indice
                * @return Devuelve un objeto de tipo Posicion que contiene 
                * la posicion donde insertar y un booleano que indica si está
                * o no ese ingrediente 
                * @post Como el ingrediente previamente tiene que haber sido 
                * añadido en datos, el booleano que devuelve tiene que ser 
                * siempre false
                */
                Posicion buscarIndicePorIndice(int index);
                /**
                * @brief Consultor del tamanio del vector de datos
                * @return Devuelve el tamanio del vector de datos del objeto 
                * implicito
                */
                int size()const;
                /**
                * @brief Imprime por pantalla el tipo de todos los elementos 
                * contenidos en el vector datos del objeto implicito
                * @param os stream de salida
                * @post Se obtiene por pantalla un listado del tipo de cada 
                * ingrediente que haya en el vector datos aunque sean repetidos
                */
                ostream &ImprimirPorTipo(ostream &os);
                /**
                * @brief Obtiene un ingrediente de los almacenados en el vector
                * datos con el nombre que le pasamos como parametro.
                * @param nombre es el nombre del ingrediente a devolver
                * @return Si encuentra dentro de datos un ingrediente que se 
                * llame como se pide en el parametro, lo devuelve 
                * como se le indica
                * @exception devuelve un ingrediente nulo si no existe ningun
                * ingrediente llamado como le pedimos
                */
                Ingrediente get(string nombre)const;
                /**
                * @brief Crea un vector dinamico de tipo string y va aniadiendo
                * a este, sin repetir, los tipos de todos los ingredientes 
                * almacenados en el vector datos.
                * @return Devuelve un vector dinamico que contiene sin repetir
                * todos los tipos de ingrediente que aparecen dentro del vector 
                * datos.
                */
                VD<string> getTipos()const;
                /**
                * @brief Calcula el valor medio de calorias, porcentaje de 
                * hidratos de carbono, de proteinas, de grasas y de fibra  de 
                * todos los elementos del tipo especificado como parametro 
                * @param tipo Tipo de ingrediente del que quiero obtener la 
                * media de los valores nutricionales 
                * @param cal Numero de calorias resultante de calcular la media 
                * de calorias de todos los ingredientes de tipo tipo
                * @param hdc Porcentaje de hidratos de carbono resultante de 
                * calcular la media de hidratos de todos los ingredientes de 
                * tipo tipo
                * @param prote Porcentaje de proteinas resultante de calcular la 
                * media de proteinas de todos los ingredientes de tipo tipo
                * @param grasas Porcentaje de grasas resultante de calcular la 
                * media de grasas de todos los ingredientes de tipo tipo
                * @param fibra Porcentaje de fibra resultante de calcular la 
                * media de fibra de todos los ingredientes de tipo tipo
                * @post Ninguna de las medias obtenidas puede ser mayor que 100
                * excepto la del numero de calorias, y ninguna de ellas menor 
                * que 0.
                */
                void media(string tipo, float &cal, float &hdc, float &prote, float &grasas, float &fibra );
                /**
                * @brief Calcula la desviacion de los valores de calorias, 
                * porcentaje de hidratos de carbono, de proteinas, de grasas y 
                * de fibra  de todos los elementos del tipo especificado como 
                * parametro.
                * @param tipo Tipo de ingrediente del que quiero obtener la 
                * desviacion de los valores nutricionales 
                * @param cal Numero de calorias resultante de calcular la desviacion 
                * de calorias de todos los ingredientes de tipo tipo
                * @param hdc Porcentaje de hidratos de carbono resultante de 
                * calcular la desviacion de hidratos de todos los ingredientes de 
                * tipo tipo
                * @param prote Porcentaje de proteinas resultante de calcular la 
                * desviacion de proteinas de todos los ingredientes de tipo tipo
                * @param grasas Porcentaje de grasas resultante de calcular la 
                * desviacion de grasas de todos los ingredientes de tipo tipo
                * @param fibra Porcentaje de fibra resultante de calcular la 
                * desviacion de fibra de todos los ingredientes de tipo tipo
                * @post Ninguna de las desviaciones obtenidas puede ser menor
                * que 0.
                */
                void desviacion(string tipo, float &cal, float &hdc, float &prote, float &grasas, float &fibra );
                /**
                * @brief Calcula cual es el valor maximo de calorias, hidratos 
                * de carbono, proteinas, grasas y fibra de todos los 
                * ingredientes del tipo especificado y especifica que 
                * ingrediente es el que contiene dicho valor. 
                * @param tipo Tipo de ingrediente del que quiero obtener el 
                * valor maximo de cada valor nutricional. 
                * @param cal Numero de calorias mas alto de todos los ingredientes
                * del tipo tipo
                * @param hdc Porcentaje de hidratos de carbono mas alto de todos
                * los ingredientes del tipo tipo
                * @param prote Porcentaje de proteinas mas alto de todos los 
                * ingredientes del tipo tipo
                * @param grasas Porcentaje de grasas mas alto de todos los ingredientes
                * del tipo tipo
                * @param fibra Porcentaje de fibra mas alto de todos los ingredientes
                * del tipo tipo
                * @param mayor_cal Ingrediente que tiene el numero mas alto de calorias
                * @param mayor_hdc Ingrediente que tiene el numero mas alto de hidratos de carbono
                * @param mayor_prote Ingrediente que tiene el numero mas alto de proteinas
                * @param mayor_grasas Ingrediente que tiene el numero mas alto de grasas
                * @param mayor_fibra Ingrediente que tiene el numero mas alto de fibra
                */
                void Ingredientes::maximo(string tipo, float& cal, float& hdc, float& prote, float& grasas, float& fibra, Ingrediente &mayor_cal, Ingrediente &mayor_hdc, Ingrediente &mayor_prote, Ingrediente &mayor_grasas,Ingrediente &mayor_fibra);
                /**
                * @brief Calcula cual es el valor minimo de calorias, hidratos 
                * de carbono, proteinas, grasas y fibra de todos los 
                * ingredientes del tipo especificado y especifica que 
                * ingrediente es el que contiene dicho valor. 
                * @param tipo Tipo de ingrediente del que quiero obtener el 
                * valor minimo de cada valor nutricional. 
                * @param cal Numero de calorias mas bajo de todos los ingredientes
                * del tipo tipo
                * @param hdc Porcentaje de hidratos de carbono mas bajo de todos
                * los ingredientes del tipo tipo
                * @param prote Porcentaje de proteinas mas bajo de todos los 
                * ingredientes del tipo tipo
                * @param grasas Porcentaje de grasas mas bajo de todos los ingredientes
                * del tipo tipo
                * @param fibra Porcentaje de fibra mas bajo de todos los ingredientes
                * del tipo tipo
                * @param menor_cal Ingrediente que tiene el numero mas bajo de calorias
                * @param menor_hdc Ingrediente que tiene el numero mas bajo de hidratos de carbono
                * @param menor_prote Ingrediente que tiene el numero mas bajo de proteinas
                * @param menor_grasas Ingrediente que tiene el numero mas bajo de grasas
                * @param menor_fibra Ingrediente que tiene el numero mas bajo de fibra
                */
                void Ingredientes::minimo(string tipo, float& cal, float& hdc, float& prote, float& grasas, float& fibra, Ingrediente &menor_cal, Ingrediente &menor_hdc, Ingrediente &menor_prote, Ingrediente &menor_grasas, Ingrediente &menor_fibra);

};
#endif