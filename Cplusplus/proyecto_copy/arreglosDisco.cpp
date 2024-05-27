#include "arreglos.cpp"
#include<fstream>
//en una linea, escribir los tokens
using namespace std;
int  Arreglo_A_Disco(double *x,int ndat,string filename);
int leerarchivo(string filename);
int main(){
    cout<<"hello world";
    double x[]={1,2,3,4,5};
    //Datos en pantalla
    cout<<"\nLos datos en el archivo a mostrar son";
    ArregloMostrar(x,5);

    string FileName="datos.csv";
//    ofstream archivo(FileName);//abrimos
    
  //  archivo<<"\n//Los datos en el archivo a mostrar son";
   // archivo<<"\n#include<stdio.h>\nint main(){\n\tprintf(\"Hola\");\n\treturn 0;\n }";
    ArregloMostrar(x,5);
    
    Arreglo_A_Disco(x, 5,FileName);
    cout<<"Presiona <Enter> para continuar con una lectura";
    cin.get();
    leerarchivo(FileName);

    return 0;
}
int  Arreglo_A_Disco(double *x,int ndat,string filename){
    ofstream archivo;
    archivo.open(filename,ios::app);//open(file, mode)
    //para agregar daots al final del archivo
    //ios::binary;//para binarios
    if(!archivo){
        cout<<"Error al abrir el archivo de escritura.\n";
        return -1;
    }
    for(int i=0;i<ndat-1;i++)
        archivo<<x[i]<<",";
    archivo<<x[ndat-1]<<"\n";
    archivo.close();//cerramos
    return 0;
}
int leerarchivo(string filename){
    ifstream archivoEnt;
    
    //abro el mismo archivo
    archivoEnt.open(filename);
    if(!archivoEnt.is_open()){
        cout<<"\n error al abrir el archivo de lectura";
        return -1;
    }
    string renglon;
    int nRen=0;
    while(getline(archivoEnt,renglon)){
        cout<<"\nRenglón "<< ++nRen<<": "<<renglon;
    }
    cout<<"Se leyeron "<<nRen<<" reglones.";
    archivoEnt.close();
    return 0;
}