#include<iostream>
#include<fstream>
using namespace std;
int tokensDesdeCadena(string cadena,string token[],int nMaxDatos);
void mostrar(string token[],int data);
int main(){
    string cadena="1.11,alfa bravo,2.22,charlie,3.33,delta";
    int nMaxTokens = 10;
    string token[nMaxTokens];
    int nTokens = tokensDesdeCadena(cadena,token,nMaxTokens);
    cout<<"la cantidad de tokens encontrados fueron de:\n "<<nTokens;
    mostrar(token,nTokens);
}
int tokensDesdeCadena(string cadena,string token[],int nMaxDatos){
    string cadenaform;
    int pos=0;
    for(unsigned int i=0;i<cadena.length();i++){
        if(cadena[i]!=',')
            cadenaform+=cadena[i];
        if((cadena[i]==','||i==cadena.length()-1)&&pos<nMaxDatos){
            token[pos]=cadenaform;
            pos++;
            cadenaform="";
        }
    }
    return pos;
}
void mostrar(string token[],int data){
    cout<<"\nLos tokens ya separados por comas son\n";
    for(int i=0;i<data;i++){
        cout<<" \""<<token[i]<<"\"";
    }
}