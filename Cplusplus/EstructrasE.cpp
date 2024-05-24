#include<iostream>
#include<string>
using namespace std;
struct datPer{
    string name="SinNombre";
    int edad=0;
    float altura=0.0;
    float peso=0.0;
};
struct datAlu{
    datPer dp;
    int NUA=0;
    float prom=0.0;
};
datPer DatPerCaptura();
void DatPerCaptura(datPer &dp);
void DatPerMostrar( datPer dp);
void DatAluCaptura(datAlu &da);
void DatAluMostrar( datAlu da);
datAlu* nuevoArreglo(int &nD);
void AluMostrarArreglo(datAlu *da,int nAl);
void AluCapturaArreglo(datAlu *da,int nAl);
void AluOrdenPorProm(datAlu *ptr,int nDat);
int main(){
    cout<<"Estructuras...";
    int nAl;
    cout<<"Cuantos alumnos? ";
    cin>>nAl;
    datAlu da[nAl];
    void DatPerMostrar(d)
    /*
    AluCapturaArreglo(da,nAl);
    AluMostrarArreglo(da,nAl);
    AluOrdenPorProm(da,nAl);
    AluMostrarArreglo(da,nAl);*/
    return 0;
}
////////
void AluOrdenPorProm(datAlu *ptr,int nDat){
    //buscar el menor
    for(int posicion=0;posicion<nDat-1;posicion++){
        int posMenor=posicion;
        datAlu menor=ptr[posMenor];
        for(int k=posicion+1;k<nDat;k++){
            if(ptr[k].prom<menor.prom){
                menor=ptr[k];
                posMenor=k;
            }
        }
        datAlu aux=ptr[posicion];
        ptr[posicion]=ptr[posMenor];
        ptr[posMenor]=aux;
       // ArregloMostrar(ptr,nDat);
    }
    
    //mostramos como vamos
}
void AluCapturaArreglo(datAlu *da,int nAl){
    for(int i=0;i<nAl;i++){
        cout<<"Alumno["<<i+1<<"]";
        DatAluCaptura(da[i]);
    }
}
void AluMostrarArreglo(datAlu *da,int nAl){
    for(int i=0;i<nAl;i++)
        DatAluMostrar(da[i]);
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
    getline(cin,dp.name);cin.ignore(256,'\n');
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
void DatPerMostrar(datPer dp){
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
void DatAluMostrar( datAlu da){
    cout<<"\n\nDatos del estudiante";
    DatPerMostrar(da.dp);
    cout<<"\n\nNUA: "<<da.NUA;
    cout<<"\n\nPromedio: "<<da.prom;
}
