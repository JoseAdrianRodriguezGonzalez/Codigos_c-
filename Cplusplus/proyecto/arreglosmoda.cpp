
#include "arreglos.cpp"
void ArregloModa(double *ptr,int ndat,double &moda,int &nRepeticiones);
int main(){
    /**pedir la longitud de la cadena*/
//	int ndat=datos();
 //   cout<<ndat;
//	double x[ndat]={}; //es un apuntador el nombre del arreglo apuntador constante
 //   ArregloMostrar(x,ndat);
 //   numerosAleatorios(x,ndat, 0, 10);
 //   ArregloMostrar(x,ndat);
  //  cout<<"El numero que mas se repite es el "<<moda;
  //  cout<<"\nSe repite "<<nRepeticiones<<" veces";
    //en c++ el nombre de un arreglo es un apuntador al primer dato del arreglo
    //un apuntador variable}
    //int ndat=8;
 //el archivo objeto o es el que usas para la biblioteca
    //proeba dirigida
    int ndat=7;
    double x[ndat]={7,2,3,-7,-7,3,1};
    ArregloMostrar(x,ndat);
    double moda=-1;
    int nRepeticiones=-1;
    ArregloModa(x,ndat,moda,nRepeticiones);
    cout<<"El numero que mas se repite es el "<<moda;
    cout<<"\nSe repite "<<nRepeticiones<<" veces";
    return 0;
}
