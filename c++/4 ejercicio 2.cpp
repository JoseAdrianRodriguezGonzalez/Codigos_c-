#include<iostream>
using namespace std;
int main(){
	float precio;
	float IVA = .16, resultado=0, Multiplicacion=0;
	cout<<"Digite un precio: ";
	cin>> precio ;
	Multiplicacion= precio*IVA;
	resultado = Multiplicacion+ precio;
	cout<< "El iva es igual a: "<< resultado;
	return 0;	
	
}
