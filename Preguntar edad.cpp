#include<iostream>
using namespace std;
int main() {
	int edad,diferencia;
	char nombre [10];
	int respuesta;
	do {
		cout << "Hola,Como te llamas?  ";
		cin >> nombre;
		cout << "\nCuantos años tienes?  ";
		cin >> edad;
		if (edad < 18)
		{
			diferencia = 18 - edad;
			cout << "Hola " << nombre << " Me llamo julian y soy mayor que tu por " << diferencia <<" anios";
		}
		if (edad > 18)
		{
			diferencia = edad - 18;
			cout << "Hola " << nombre << " Me llamo julian y soy menor que tu por " << diferencia <<" anios";
		}
		if (edad == 18)
		{
			cout << "Hola " << nombre << " Me llamo julian y tengo la misma edad que tu";
		}
		cout << "\nQuieres que le pregunte a alguien mas?\n 1.Si \t2.No ";
		cin >> respuesta;
	} while (respuesta == 1);
	return 0;
}