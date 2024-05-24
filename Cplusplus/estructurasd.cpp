#include<iostream>
#include<string>
using namespace std;
struct datPer{
    string name;
    int edad;
    float altura;
    float peso;
};
struct datAlu{
    datPer dp;
    int NUA;
    float prom;
};
datPer DatPerCaptura();
void DatPerCaptura(datPer &dp);
void DatPerMostrar(const datPer &dp);
void DatAluCaptura(datAlu &da);
void DatAluMostrar(const datAlu &da);
datAlu* nuevoArreglo(int &nD);
int main(){
    cout<<"Estructuras...";
    int nAl;
    cout<<"Cuantos alumnos? ";
    cin>>nAl;
    datAlu da[nAl];
    for(int i=0;i<nAl;i++)
        DatAluCaptura(da[nAl]);
    for(int i=0;i<nAl;i++)
        DatAluMostrar(da[nAld]);
    return 0;
}
datAlu* nuevoArreglo(int &nD){
    do{
        cout<<"Ingresa la cantidad de alumnos";
        cin>>nD; cin.ignore(256,'\n');
    }while(nD>1);
    datAlu *da=new datAlu[nD];
    return da;
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
    string str;
    cout<<"\n\nNombre: ? ";
    getline(cin,dp.name);
    cout<<"\n\nEdad: ?";
    getline(cin,str);
    dp.edad=stoi(str);
    cin.ignore(256,'\n');
    cout<<"\n\nAltura: ?";
    getline(cin,str);
    dp.altura=stof(str);
    cin.ignore(256,'\n');
    cout<<"\n\nPeso: ?";
    getline(cin,str);
    dp.peso=stof(str);
    cin.ignore();
}
void DatPerMostrar(const datPer &dp){
    cout<<"\n\nDatos personales: ";
    cout<<"\n\nNombre:  "<<dp.name;
    cout<<"\n\nEdad:  "<<dp.edad;
    cout<<"\n\nAltura:  "<<dp.altura;
    cout<<"\n\nPeso:  "<<dp.peso;
}
void DatAluCaptura(datAlu &da){
    DatPerCaptura(da.dp);
    cout<<"NUA: ?";
    cin>>da.NUA;
    cout<<"Promedio: ?";
    cin>>da.prom;
}
void DatAluMostrar(const datAlu &da){
    cout<<"\n\nDatos del estudiante";
    DatPerMostrar(da.dp);
    cout<<"\n\nNUA: "<<da.NUA;
    cout<<"\n\nPromedio: "<<da.prom;
}