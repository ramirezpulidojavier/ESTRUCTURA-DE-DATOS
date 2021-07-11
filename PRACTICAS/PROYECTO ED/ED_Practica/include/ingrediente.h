/**
  * @file ingrediente.h
  * @brief Fichero cabecera del TDA Ingrediente
  * @date Octubre 2019
  */
#ifndef _Ingrediente_H
#define _Ingrediente_H
#include <string>
#include <iostream>

using namespace std;

/**
  *  @brief T.D.A. Ingrediente
  *
  * Una instancia @e c del tipo de datos abstracto @c Ingrediente es un objeto
  * que contiene la informacion relacionada con un ingrediente, como su nombre, 
 *  su numero de calorias, el porcentaje de hidratos de carbono, de grasas, de 
 *  proteinas, de fibra y un nombre que especifica el tipo de alimento que es 
 *  (pescado, carne, etc.)
  *
  *
  * @author Angel Solano Corral 
  * @author Javier Ramirez Pulido
  * @date Octubre 2019
  */

class Ingrediente{

	private:
    /**
      * @page repIngrediente Rep del TDA Ingrediente
      *
      * @section invIngrediente Invariante de la representacion
      *
      * El invariante es num_calorias>=0,
      * 0 <= hidratosDeCarbono <= 100,
      * 0 <= proteinas <=100,
      * 0 <= grasas <= 100,
      * 0 <= fibra <= 100,
      * 0 <= hidratosDeCarbono + proteinas + grasas + fibra <= 100.
      *
      * @section faIngrediente Funcion de abstraccion
      *
      * Un objeto valido @e rep del TDA Ingrediente representa al valor
      *
      * (rep.nombre, rep.num_calorias, rep.hidratosDeCarbono, rep.proteinas, rep.grasas, rep.fibra, rep.tipo)
      *
      */
		string nombre; /**< nombre del Ingrediente */
		float num_calorias; /**< numero de calorias del Ingrediente */
		float hidratosDeCarbono; /**< porcentaje de hidratos de carbono */
		float proteinas; /**< porcentaje de proteinas */
		float grasas; /**< porcentaje de grasas */
		float fibra; /**< porcentaje de fibra */
		string tipo; /**< tipo */

	public:
		/**
                * @brief Constructor por defecto de la clase. Crea el 
                * Ingrediente de nombre y tipo "Undefined" y el porcentaje de
                * grasas, fibra, proteinas, hidratos de carbono y el numero de
                * calorias con valor 0.
                */
		Ingrediente();
                /**
                * @brief Constructor de la clase con parametros
                * @param nombre nombre del ingrediente a crear
                * @param num_calorias numero de calorias que tendra el 
                * ingrediente
                * @param porc_hidratos porcentaje de hidratos de carbono que 
                * tiene
                * @param porc_proteinas porcentaje de proteinas que tiene
                * @param porc_grasas porcentaje de grasas que tiene
                * @param porc_fibra porcentaje de fibra que tiene
                * @param tipo nombre del tipo de alimento (carne, fruta, etc.)
                * @return Crea el Ingrediente con esas caracteristicas
                * @pre tanto los valores de porc_hidratos, porc_proteinas, 
                * porc_grasas y porc_fibra, como la suma de ellos, debe ser 
                * menor o igual que 100 porque son porcentajes
                */
		Ingrediente(string nombre, float num_calorias, float porc_hidratos, float porc_proteinas, float porc_grasas, float porc_fibra, string tipo);
		/**
                * @brief Consultor de nombre
                * @return Devuelve el nombre del ingrediente
                */
                string getNombre()const{return nombre;}
                /**
                * @brief Consultor del porcentaje de proteinas
                * @return Devuelve el porcentaje de proteinas del ingrediente
                */
		float getProteinas()const{return proteinas;}
                /**
                * @brief Consultor del porcentaje de grasas
                * @return Devuelve el porcentaje de grasas del ingrediente
                */
		float getGrasas()const{return grasas;}
                /**
                * @brief Consultor del porcentaje de fibra
                * @return Devuelve el porcentaje de fibra del ingrediente
                */
		float getFibra()const{return fibra;}
                /**
                * @brief Consultor del porcentaje de hidratos de carbono
                * @return Devuelve el porcentaje de hidratos de carbono del ingrediente
                */
		float getHidratosDeCarbono()const{return hidratosDeCarbono;}
		/**
                * @brief Consultor del numero de calorias
                * @return Devuelve el numero de calorias del ingrediente
                */
                float getNumCalorias()const{return num_calorias;}
		/**
                * @brief Consultor del tipo
                * @return Devuelve el tipo del ingrediente
                */
                string getTipo()const{return tipo;}
		/**
                * @brief Modificador del atributo nombre
                * @param nombre nuevo nombre del ingrediente
                * @return Asigna al objeto implicito el nombre nombre
                */
                void setNombre(string nombre){this->nombre = nombre;}
		/**
                * @brief Modificador del atributo num_calorias
                * @param num_calorias nuevo numero de calorias del ingrediente
                * @return Asigna al objeto implicito el numero de calorias num_calorias
                */
                void setCalorias(float num_calorias){this->num_calorias = num_calorias;}
		/**
                * @brief Modificador del atributo hidratosDeCarbono
                * @param porc_hidratos nuevo porcentaje de hidratos de carbono del ingrediente
                * @return Asigna al objeto implicito el porcentaje de hidratos de carbono
                */
                void setHidratosDeCarbono(float porc_hidratos){this->hidratosDeCarbono = porc_hidratos;}
		/**
                * @brief Modificador del atributo proteinas
                * @param porc_proteinas nuevo porcentaje de proteinas del ingrediente
                * @return Asigna al objeto implicito el porcentaje de proteinas
                */
                void setProteinas(float porc_proteinas){this->proteinas = porc_proteinas;}
		/**
                * @brief Modificador del atributo grasas
                * @param porc_grasas nuevo porcentaje de grasas del ingrediente
                * @return Asigna al objeto implicito el porcentaje de grasas
                */
                void setGrasas(float porc_grasas){this->grasas = porc_grasas;}
		/**
                * @brief Modificador del atributo fibra
                * @param porc_fibra nuevo porcentaje de fibra del ingrediente
                * @return Asigna al objeto implicito el porcentaje de fibra
                */
                void setFibra(float porc_fibra){this->fibra = porc_fibra;}
		/**
                * @brief Modificador del atributo tipo
                * @param tipo nuevo tipo del ingrediente
                * @return Asigna al objeto implicito el tipo tipo
                */
                void setTipoIngrediente(string tipo){this->tipo = tipo;}
		/**
                * @brief Salida de un ingrediente a ostream
                * @param o stream de salida
                * @param ingrediente Ingrediente a escribir
                * @post Se obtiene en \a o la cadena (nombre calorias 
                * HidratosDeCarbono Proteinas GrasasnFibra Tipo)
                */
                friend ostream &operator << (ostream &o, const Ingrediente &ingrediente); 
		/**
                * @brief Entrada de un Ingrediente desde istream
                * @param i stream de entrada
                * @param ingrediente Ingrediente que recibe el valor
                * @return El Ingrediente leido en ingrediente
                * @pre La entrada tiene el formato (nombre, calorias, porcentaje
                * de hidratos de carbono, proteinas, grasas y fibra, el tipo de 
                * ingrediente)
                */
                friend istream& operator >> (istream &i, Ingrediente &ingrediente); 
		
		
		

};



#endif
