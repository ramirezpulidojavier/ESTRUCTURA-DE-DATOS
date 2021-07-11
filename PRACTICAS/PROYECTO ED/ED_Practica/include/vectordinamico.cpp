template <class T>

		
	void VD<T>::resize(int nuevo_tam){
		
		T *aux = new T[nuevo_tam];
		int minimo = (n < nuevo_tam)?n:nuevo_tam;

		
		for (int i = 0; i < minimo; i++)
			aux[i] = datos[i];
		
		reservados = nuevo_tam;
		n = minimo;
                delete []datos;
		datos = aux;
			
	}

template <class T>

	void VD<T>::liberar(){
		delete []datos;
                datos = nullptr;
	}

template <class T>

	void VD<T>::copiar(const VD<T> &v){

		liberar();
		n = v.n;
		reservados = v.reservados;
		datos = new T[reservados];

		for(int i = 0; i < v.n; i++)
			datos[i] = v.datos[i];
		
	}

template <class T>
	
    VD<T>::VD(int tam){
            
        if (tam <= 0){
            reservados = 0;
            n = 0;
            datos = nullptr;
        }else{

            datos = new T[tam];
            n = 0;
            reservados = tam;

       }
    }

template <class T>

	VD<T>::VD(const VD<T> &original){		
		copiar(original);		
	}

template <class T>

	VD<T>::~VD(){

		if (datos != 0){
			reservados = 0;
			n = 0;
			liberar();
		}
                
	}

template <class T> 

	VD<T> &VD<T>::operator=(const VD<T> &o){
		
		if (this != &o)
                    copiar(o);

		return *this;
			
	}

template <class T>

	void VD<T>::Insertar(const T &dato, int pos){

		if ((n+1) == reservados){
			resize(reservados*2);
		}
		
		for (int i = pos; i < n; i++)
			datos[i+1] = datos[i];
		
		n++;
		datos[pos] = dato;	

	}

template <class T>
		
	void VD<T>::Borrar(int pos){
		
		for (int i = pos; i < n - 1; i++)
			datos[i] = datos[i+1];
		
		if (n < reservados/4)
			resize(reservados/2);		

		n--;
	}


