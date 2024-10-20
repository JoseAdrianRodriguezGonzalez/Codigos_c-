#include<iostream>
//Defina el concepto de herencia en C++. ¿Cuál es su proposito principal y como mejora la reutilización de código en la 
//programación orientada a objetos?
int main(){
    //Mecanismo POO, creamos nueva clase a partir de otra.
    //Reutilización de código
    //extendemos las funcionalidades de la clase.

}

//Pregunta 2
/*
2.-Explique la diferencia entre una función virtual y virtual pura.
Función virtual pura no esta definida.
definir una clase abstracta.
*/
//Pregunta 3
/*
¿Qué es el polimorfismo en tiempo de ejecución y como se implementa en C++?
Mencione qué rol juegan las funciones virtuales en este proceso.
diferente implementación de una función a través de un puntero. Se implementa con funciones virtuales
*/
//Pregunta 4
/*
¿Que es una plantilla de función en C++?, describe como las plantillas pueden mejorar la flexibilidad del código. Proporcione un ejemplo simple( sin necesidad de codificarlo).
//Función generica. trabaja con cualquier tipo de dato, ahorramos código, ya que una sola definición puede ser utilizada para muchos datos.
*/
//Preguna 5
/*
¿Cual es la relación entre el polimorfismo y las funciones virtuales?, ¿por que es necesario tener destructores virtuales cuando usamos herencia en C++?
sin funciones virtuales no hay polimorfismo en tiempo de ejecución
sin destructor virtual no, se destruye el constructor de la clase apuntadora.
*/
//Pregunta 6
/**
 *
 * 
 */
//Pregunta 7
/*
Utilizando plantillas, escriba una función genérica 'maxValue' que tome dos parametros  decualquier tipo y devuelva el mayor de los dos.Luego, utilicela para compara dos valores de tipo 'int
 y 'double'.
*/
//Pregunta 8
/*
*/
class Figura{
    public:
    virtual double calcularArea()=0;
};
class Cuadrado : public Figura{
    public:
    int lado;
    Cuadrado (int _lado): lado(_lado){}
    double calcularArea() override{
        return lado*lado;
    }
};
class Cuadrado : public Figura{
    public:
    int radio;
    Cuadrado (int _lado): radio(_lado){}
    double calcularArea() override{
        return radio*radio*3.1415;
    }
};