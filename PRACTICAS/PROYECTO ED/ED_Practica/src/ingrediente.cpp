#include "ingrediente.h"
#include <stdlib.h>
#include <cstdlib>
using namespace std;

Ingrediente::Ingrediente(){

	nombre = "Undefined";
	num_calorias = 0;
	hidratosDeCarbono = 0;
	proteinas = 0;
	grasas = 0;
	fibra = 0;
	tipo = "Undefined";

}

Ingrediente::Ingrediente( string nombre, float num_calorias, float porc_hidratos, float porc_proteinas, float porc_grasas, float porc_fibra, string tipo){

	this->nombre = nombre;
	this->num_calorias = num_calorias;
	this->hidratosDeCarbono = porc_hidratos;
	this->proteinas = porc_proteinas;
	this->grasas = porc_grasas;
	this->fibra = porc_fibra;
	this->tipo = tipo;

}

ostream &operator << (ostream &o, const Ingrediente &ingrediente){
        
    cout << endl;
	o << ingrediente.getNombre() << " " << ingrediente.getNumCalorias() << " " << ingrediente.getHidratosDeCarbono()<< " " << ingrediente.getProteinas() << " " << ingrediente.getGrasas()  << " " << ingrediente.getFibra() << " " << ingrediente.getTipo();

	return o;

}

istream &operator >> (istream &i, Ingrediente &ingrediente){

	//cout << "Introduce el nombre, el numero de calorias, el porcentaje de hidratos de carbono, de proteinas, de grasas y de fibra y el tipo de ingrediente";
        
	string nombre, tipo, aux;
	float num_calorias, hidratosDeCarbono, proteinas, grasas, fibra;
        
        
	
            getline(i,nombre, ';');
            getline(i,aux, ';');
            num_calorias = atof(aux.c_str());
            getline(i,aux, ';');
            hidratosDeCarbono = atof(aux.c_str());
            getline(i,aux, ';');
            proteinas = atof(aux.c_str());
            getline(i,aux, ';');
            grasas = atof(aux.c_str());
            getline(i,aux, ';');
            fibra = atof(aux.c_str());
            getline(i,tipo);
               
            ingrediente.setNombre(nombre);
            ingrediente.setCalorias(num_calorias);
            ingrediente.setHidratosDeCarbono(hidratosDeCarbono);
            ingrediente.setProteinas(proteinas);
            ingrediente.setGrasas(grasas);
            ingrediente.setFibra(fibra);
            ingrediente.setTipoIngrediente(tipo);
            
        
        
	
	return i;


}