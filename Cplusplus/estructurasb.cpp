#include<iostream>
using namespace std;
struct datPer{
    string name;
    int edad;
    float altura;
    float peso;
};
datPer DatPerCaptura();
void DatPerCaptura(datPer &dp);
void DatPerMostrar(const datPer &dp);
int main(){
    cout<<"Estructuras...";   
    datPer dp;
    DatPerCaptura(dp);
    DatPerMostrar(dp);
    return 0;
}
datPer DatPerCaptura(){
    datPer dp;
    cout<<"\n\nNombre: ? ";
    getline(cin,dp.name);
    cout<<"\n\nEdad: ?";
    cin>>dp.edad; cin.ignore();
    cout<<"\n\nAltura: ?";
    cin>>dp.altura; cin.ignore();
    cout<<"\n\nPeso: ?";
    cin>>dp.peso; cin.ignore();
    return dp;
}
void DatPerCaptura(datPer &dp){
    cout<<"\n\nNombre: ? ";
    getline(cin,dp.name);
    cout<<"\n\nEdad: ?";
    cin>>dp.edad; cin.ignore();
    cout<<"\n\nAltura: ?";
    cin>>dp.altura; cin.ignore();
    cout<<"\n\nPeso: ?";
    cin>>dp.peso; cin.ignore();
  
}
void DatPerMostrar(const datPer &dp){
    cout<<"\n\nDatos personales: ";
    cout<<"\n\nNombre:  "<<dp.name;
    cout<<"\n\nEdad:  "<<dp.edad;
    cout<<"\n\nAltura:  "<<dp.altura;
    cout<<"\n\nPeso:  "<<dp.peso;
    
}