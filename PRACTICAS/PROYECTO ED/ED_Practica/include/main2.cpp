#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include <fstream>
#include <string>

using namespace std;
void MuestraParametros(){

    cout<<"1.- Dime el nombre del fichero con los ingredientes"<<endl;
}

int main(int argc, char *argv[])
{
  if (argc!=2){
      MuestraParametros();
      return 0;
 }
  ifstream f(argv[1]);
  if (!f){
      cout << "No se puede abrir el archivo";
      return 0;
  }

  //Se quita la primera linea
  string linea;
  getline(f, linea);

  f.seekg(0);

  Ingredientes nuevo ;

  cout << "Vamos a leer sus ingredientes: " << endl ;
  f >> nuevo ;

  nuevo.getIngredientesPorTipo(argv[2]);


    float sum_cal = 0;
    float sum_hdc = 0;
    float sum_prote = 0;
    float sum_grasas = 0;
    float sum_fibra = 0;


    


    nuevo.media(argv[2], sum_cal, sum_hdc, sum_prote, sum_grasas, sum_fibra);
    nuevo.desviacion(argv[2], sum_cal, sum_hdc, sum_prote, sum_grasas, sum_fibra);
    nuevo.maximo(argv[2], sum_cal, sum_hdc, sum_prote, sum_grasas, sum_fibra);
    nuevo.minimo(argv[2], sum_cal, sum_hdc, sum_prote, sum_grasas, sum_fibra);


}