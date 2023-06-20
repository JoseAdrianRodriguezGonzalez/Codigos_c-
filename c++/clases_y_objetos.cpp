#include<iostream>		//Se incluyen las librerías iostream y stdlib
#include<stdlib.h>	
using namespace std;		//Se usa el std para entrada y salida de datos

class Persona{	//Se crea la clase
	private:		//Se encapsulan los datos
		int edad;		//Atributos edad y nombre(parte de la abstracción)
		string nombre;
public:		//Las funciones se hacen públicas 
	Persona(int, string);		//Se crea un constructor
	void leer();		//Método "leer"
	void correr();		//Método "correr"
	
};
//Se crea el constructor de la clase Persona con sus atributos
Persona::Persona(int _edad, string _nombre){
	edad= _edad;		
	nombre= _nombre;
};
void Persona::leer(){		//Se hace funcionar el metodo "leer"
	cout<<"Soy "<<nombre<<"y estoy leyendo un libro"<<"y tengo "<<edad<<" años"<<endl;
	
}
void Persona::correr(){		//Se hace funcionar el metodo "correr"
	cout<<"Soy "<<nombre<<" y estoy corriendo una maraton"<<endl;
}
int main(){
	Persona p1=Persona(20, "juan");	//Se crea el objeto con los atributos de edad y nombre
	p1.correr();		//Se activa el metodo correr
	p1.leer();
	return 0;
}
