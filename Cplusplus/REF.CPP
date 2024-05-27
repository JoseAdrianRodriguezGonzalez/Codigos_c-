#include<iostream>
#include<clocale>
using namespace std;
float cubo(float x);
void cubo(float x,float &cubo);//sobrecarga de funciones
int main (){
    setlocale(LC_CTYPE,"spanish");
   // cout<<"Oña 
   //void *  es in apuntador generico, puede tomar 
   /*
   float var =123.235;
   cout<<"\nvar="<<var;
   float *refe=&var;
   cout<<"\nvar="<<var<<"\nrefe="<<*refe;
*/
    float var=2;
    float cb=cubo(var);
    float cu=0;
    cout<<"\ncb="<<cb;
    
   return 0;
}
float cubo(float x){
    return x*x*x;
}
void cubo(float x,float &cubo){
    cubo=x*x*x;
}
/**
 * EN la sobrecarga pueden haber distitnas caracteristicas que pueden cambiar
 * 
 */