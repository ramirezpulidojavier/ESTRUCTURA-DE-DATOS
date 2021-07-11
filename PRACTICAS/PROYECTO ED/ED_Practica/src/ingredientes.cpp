#include "ingredientes.h"
#include "vectordinamico.h"

Ingredientes::Ingredientes(){
	
    VD<Ingrediente> datos_null(0);
    VD<int> indice_null(0);
    
    datos = datos_null;
    indice = indice_null;

}


void Ingredientes:: Clear(){

    datos.~VD();
    indice.~VD();

}

Posicion Ingredientes::buscarDatos(int inicio, int final, const Ingrediente &ingrediente){
    
    Posicion posDatos;
    
    if (inicio < final){
        int mitad = (inicio + final) / 2;
        if (datos[mitad].getNombre() == ingrediente.getNombre() && datos[mitad].getTipo() == ingrediente.getTipo()){
            posDatos.esta = true;
            posDatos.position = mitad;
            return posDatos;
        }
        else{
            if (datos[mitad].getNombre() < ingrediente.getNombre())
                return buscarDatos(mitad + 1, final, ingrediente);
            else
                return buscarDatos(inicio, mitad, ingrediente);
        }
    }
    else{
        posDatos.esta = false;
        posDatos.position = inicio;
        return posDatos;
    }
}

/*
Posicion Ingredientes::buscarDatos(const Ingrediente &nuevo){


	bool encontrado=false;
	Posicion posd;
	int izquierda=0, derecha=datos.size();
        int medio=(izquierda+derecha)/2;
        
	while(izquierda<derecha && !encontrado){
	
		
		if(datos[medio].getNombre()==nuevo.getNombre() && datos[medio].getTipo() == nuevo.getTipo()){

			encontrado=true;
			
		}else{

			if(datos[medio].getNombre()<nuevo.getNombre()){

				izquierda=medio+1;

			}else{

				derecha=medio;

			}

		}		

	}

	if (!encontrado){
		posd.position = izquierda;
		posd.esta = false;
	}
	else{
		posd.position = medio;
		posd.esta = true;
	}

	return posd;

}
*/

int &Ingredientes::operator[](int pos){

    if(pos>=0 && pos < indice.size())
        return indice[pos];
    
}

const int &Ingredientes::operator[](int pos)const{
    if(pos>=0 && pos < indice.size())
        return indice[pos];
}

Posicion Ingredientes::buscarIndice(int inicio, int final, const Ingrediente &ingrediente){
    
    Posicion posIndice;
    
    if (inicio < final){
        
        int mitad = (inicio + final) / 2;
        
        if (datos[indice[mitad]].getNombre() == ingrediente.getNombre() && datos[indice[mitad]].getTipo() == ingrediente.getTipo()){
            
            posIndice.esta = true;
            posIndice.position = mitad;
            return posIndice;
            
        }
        else{
            if (datos[indice[mitad]].getTipo() < ingrediente.getTipo())
                return buscarIndice(mitad+1, final, ingrediente);
            else
                return buscarIndice(inicio, mitad, ingrediente);
        }
    }
    else{
        posIndice.esta = false;
        posIndice.position = inicio;
        return posIndice;
    }
        
}
/*
Posicion Ingredientes::buscarIndice(const Ingrediente &nuevo){

	Posicion posi;

	int izq = 0, der = indice.size();
		
	while (izq < der){
		
		int mitad = (izq + der) / 2;

		int aux = indice[mitad];		

		if (datos[aux].getTipo() == nuevo.getTipo()){
				
			if (datos[aux].getNombre() < nuevo.getNombre())
				der = mitad;
			else
				izq = mitad + 1;
					
		}
		else if (datos[aux].getTipo() < nuevo.getTipo())
			der = mitad;
		else
			izq = mitad + 1;
				

	}

	posi.position = izq;
	posi.esta = false;

	return posi;

}
*/

Posicion Ingredientes::buscarDatosNombre(const string &ali){


    bool encontrado=false;
    Posicion posd;
    int izquierda=0, derecha=datos.size();
    int medio;
    while(izquierda<derecha && !encontrado){

        medio=(izquierda+derecha)/2;
        if(datos[medio].getNombre()==ali){

            encontrado=true;

        }else{

            if(datos[medio].getNombre()<ali){

                izquierda=medio+1;

            }else{

                derecha=medio;

            }

        }

    }

    if (!encontrado){
        posd.position = izquierda;
        posd.esta = false;
    }
    else{
        posd.position = medio;
        posd.esta = true;
    }

    return posd;

}

Posicion Ingredientes::buscarIndicePorIndice(int index){

    Posicion posi;

    int izq = 0;
    int der = indice.size();

    while (izq < der){

        int mitad = (izq + der) / 2;

        int aux = indice[mitad];

        if (datos[aux].getTipo() == datos[index].getTipo()){

            if (datos[aux].getNombre() < datos[index].getNombre())
                der = mitad;
            else
                izq = mitad + 1;

        }
        else if (datos[aux].getTipo() < datos[index].getTipo())
            der = mitad;
        else
            izq = mitad + 1;


    }

    posi.position = izq;
    posi.esta = false;

    return posi;

}


void Ingredientes::Insertar(const Ingrediente &nuevo){

	Posicion posd = buscarDatos(0,indice.size(),nuevo);
	Posicion posi = buscarIndice(0,indice.size(),nuevo);

	posd = buscarDatos(0, indice.size(), nuevo);

	if (!posd.esta){

		posi = buscarIndice(0, indice.size(), nuevo);
		
		for (int i = 0; i < indice.size(); i++){
			if (indice[i]>=posd.position)
				indice[i] ++;
		}

		datos.Insertar(nuevo, posd.position);
                
                int contador = posi.position;
                bool continuar = true;
                
                if (datos.size() > 1){
                    while (contador < indice.size() && datos[indice[contador]].getTipo() == nuevo.getTipo() && continuar){
                        if (datos[indice[contador]].getNombre() > nuevo.getNombre())
                            continuar = false;
                        else
                            contador ++;
                    }
                }
                
                indice.Insertar(posd.position, contador);
                
		//indice.Insertar(posd.position, posi.position);
        }
        else
            datos[posd.position] = nuevo;

           
}

void Ingredientes::Borrar (const string &ali){

    Posicion posd;
    Posicion posi;

    posd = buscarDatosNombre(ali);


    if(posd.esta){

            posi=buscarIndicePorIndice(posd.position);

            for (int i = 0; i < indice.size(); i++){
                if (indice[i]>=posd.position)
                    indice[i] --;
            }

            datos.Borrar(posd.position);
            indice.Borrar(posi.position);




        }
}



Ingrediente Ingredientes::getIngredientePorNombre(int i)const{

	return datos[i];

}

string Ingredientes::getInformacionPorNombre(string name) const{

	bool continua=true;

	for(int i = 0; i < datos.size() && continua; i++){
	
		if(name==datos[i].getNombre()){
                        continua=false;	
			return "El alimento es " + name + ", tiene " + to_string(datos[i].getNumCalorias()) + " calorias, " + to_string(datos[i].getProteinas()) + "% de proteinas, " + to_string(datos[i].getGrasas()) + "% de grasas, " + to_string(datos[i].getFibra()) + "% de fibra, " + to_string(datos[i].getHidratosDeCarbono()) + " %de hidratos de carbono y es de tipo " + datos[i].getTipo();
		}

	}
	if(continua){

		return "No se ha encontrado ningun alimento que se llame " + name;

	}

}

Ingredientes Ingredientes::getIngredientesPorTipo(string tipo){

    Ingredientes aux;

    for(int i = 0; i < datos.size();i++){

        if(datos[i].getTipo()==tipo){
        	aux.Insertar(datos[i]);  
	}
        
    }

    return aux;

}

VD<string> Ingredientes::getTipos()const{
    
    VD<string> aux;
    int contador = 0;
    bool encontrado;
    
    for (int i = 0; i < datos.size(); i++){
        encontrado = false;
        for(int j = 0; j < aux.size() && !encontrado; j++){
            if (datos[i].getTipo() == aux[j])
                encontrado = true;
        }
    
        if (!encontrado){
            aux.Insertar(datos[i].getTipo(), contador);
            contador ++;
        }
    }
        
        
}

void Ingredientes::setIngrediente(int i, Ingrediente ing){

	Borrar(datos[i].getNombre());
	Insertar(ing);

}

int Ingredientes::size()const{
    
    return datos.size();
    
}

istream &operator >>(istream &is, Ingredientes &ings){
	
	ings.Clear();  
 
	Ingrediente ing;

	while (is>>ing){

		ings.Insertar(ing);
	
	}
	
	return is;

}

ostream &operator << (ostream &os, Ingredientes &ings){	

    cout << "\nVECTOR DATOS: \n";
    
    for (int i = 0; i < ings.datos.size(); i++){
        
        cout << ings.getIngrediente(i);
        cout << endl;
        
    }
    
    cout << "\nVECTOR INDICE: \n";
    
    for (int i = 0; i < ings.datos.size(); i++){
        
        cout << ings.getIndice(i);
        cout << endl;
        
    }

    return os;


}

ostream &Ingredientes::ImprimirPorTipo(ostream &os){
    
    for (int i = 0; i < indice.size(); i++){
        int posicion = indice[i];
        os << datos[posicion] << " ";
    }

    return os;
    
}

Ingrediente Ingredientes::get(string nombre)const{
    
    bool encontrado = false;
    
    for (int i = 0; i < datos.size(); i ++){
        if (nombre == datos[i].getNombre()){
            encontrado = true;
            return datos[i]; 
        }
            
    }
    
    if (!encontrado){
        Ingrediente nulo;
        return nulo;   
    } 
    
    
}
