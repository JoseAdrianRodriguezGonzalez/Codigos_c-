#include<iostream>
using namespace std;
struct datPer{
    string name;
    int edad;
    float altura;
};
int main(){
    cout<<"Estructuras...";   
    datPer dp;
    cout<<"\n\nNombre: ? ";
    getline(cin,dp.name);
    cout<<"\n\nEdad: ?";
    cin>>dp.edad; cin.ignore();
    cout<<"\n\nAltura: ?";
    cin>>dp.altura; cin.ignore();
    cout<<"\n\nDatos personales: ";
    cout<<"\n\nNombre:  "<<dp.name;
    cout<<"\n\nEdad:  "<<dp.edad;
    cout<<"\n\nAltura:  "<<dp.altura;
    
    return 0;
}