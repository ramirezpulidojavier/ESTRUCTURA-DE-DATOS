/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mimain.cpp
 * Author: angel
 *
 * Created on 23 de octubre de 2019, 19:18
 */

#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include <fstream>
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
 /******************************************************************************************/
 //SECTION 1: Test sobre la lectura de un ingrediente
 //Ingrediente debe tener operadores de consulta y de modificacion por cada parametros
 //ademas de sobrecarga de lectura y escritura
 string nf =argv[1];
 ifstream f(nf);
 if (!f){
    cout<<"No puedo abrir "<<nf<<endl;
    return 0;
 }
 //Quitamos la primera linea
 string linea;
 getline(f,linea);


 
/*
 
 cout<<endl<<"Ahora probamos la sobrecarga de salida:\t"<<i<<endl;

 cout<<"\n Pulsa una tecla para continuar...."<<endl;
 cin.get();
 
 /******************************************************************************************/
 //SECTION 2: Test sobre el objeto Ingredientes. En primer lugar comprobamos que la sobrecarga de entrada/salida
 //esta bien. Y por lo tanto la operaciÃ³n de insertar
 //Ponemos el puntero del fichero al principio
 /*
 f.seekg(0);
 Ingredientes all_ingre;
 cout<<"Lectura de todos los ingredientes"<<endl;
 f>>all_ingre;
 

 //Comprobamos que hemos hecho bien la lectura
 cout<<"Los ingredientes ordenados por nombre..."<<endl<<endl;
 cout<<all_ingre<<endl;;
 cout<<"Pulse una tecla para continuar..."<<endl<<endl;
 cin.get();
 /******************************************************************************************/
 //Section 3: Sobre ingredientes comprobamos  que la indexacion por tipo funciona
/*
  cout<<"Imprimos por tipo "<<endl;
  all_ingre.ImprimirPorTipo(cout);

  cout<<endl<<"Pulse una tecla para continuar..."<<endl<<endl;
  cin.get();

 /******************************************************************************************/
 //SECTION 4: Sobre ingredientes comprobamos consultar por nombre, size y borrar
 
 /*
  cout<<endl<<endl;
  cout<<"El numero de ingredientes son "<<all_ingre.size()<<endl;

  cout<<"Dime un nombre de ingrediente:";
  string n;
  getline(cin,n);
  Ingrediente ing=all_ingre.get(n);
  if (ing.getNombre()!="Undefined"){
    cout<<"InformaciÃ³n del ingrediente "<<ing<<endl;
    cout<<"Pulse una tecla para continuar...."<<endl;
    cin.get();

    //borra por nombre del ingrediente
    all_ingre.Borrar(n);
    cout<<"Tras el borrado de "<<ing.getNombre()<<" los ingredientes son:"<<endl<<all_ingre;
    cout<<"Numero de ingredientes tras el borrado son "<<all_ingre.size()<<endl;
    cout<<"Pulse una tecla para continuar ...."<<endl;
    cin.get();
    cout<<"Ahora los vemos ordenados por tipo"<<endl;
    all_ingre.ImprimirPorTipo(cout);
   }
   else{
       cout<<"El ingrediente "<<n<<" no aparece "<<endl;

   }
  cout<<endl<<"Pulse una tecla para continuar..."<<endl<<endl;
  cin.get();
  /******************************************************************************************/
  //SECTION 5: Obtiene los tipos diferentes y los  ingredientes de un tipo concreto
 /*  
 VD<string> tipos=all_ingre.getTipos();
   cout<<"Los tipos de alimentos son:"<<endl;
   for (int i=0;i<tipos.size(); ++i){
      cout<<tipos[i]<<endl;
   }
   cout<<"Pulse una tecla para continuar "<<endl;
   cin.get();

   string tipo="Molusco";
   Ingredientes ingre_tipo=all_ingre.getIngredientesPorTipo(tipo);
   cout<<"Los ingredientes de tipo "<<tipo<<" son: "<<endl<<ingre_tipo<<endl;
   */
}
