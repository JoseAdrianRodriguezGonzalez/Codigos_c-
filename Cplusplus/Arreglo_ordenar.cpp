#include<iostream>
using namespace std;
int ArregloMostrar(double *ptr,int nDat);//RECUERDA QUE NO ES NECESARIO PONER EN EL PROTOTIPO NO SE NECESARIO COLOCAR EL NOMVRE DE LA VARIABLE
int numerosAleatorios(double *ptr,int nDat,double mini,double max);
int numerosAleatorios(double *ptr,int nDat);
int ArregloFijarValor(double *ptr, int nDat, double num);
double ArregloPromedio(double *ptr,int nDat);
void ArregloPromedio(double *ptr,int nDat,double &prom);
void ArregloOrdenPorMenor(double *ptr,int nDat);
double ArregloMediana(double *ptr,int nDat);
int main(){
    int ndat=0;
    /**pedir la longitud de la cadena*/
	do{
		cout<<"Ingrese un dato: ";
		cin>>ndat; cin.ignore(256,'\n');
	}while(ndat< 1);
    
	double x[ndat]={}; //es un apuntador el nombre del arreglo apuntador constante
    //en c++ el nombre de un arreglo es un apuntador al primer dato del arreglo
    //un apuntador variable}
    //int ndat=8;
    ArregloMostrar(x,ndat);
    numerosAleatorios(x,ndat,-100,50);   
    ArregloOrdenPorMenor(x,ndat);
    ArregloMostrar(x,ndat);
    double mediana=ArregloMediana(x,ndat);
    cout<<"\nLa mediana de los datos es "<<mediana;
    //cout<<"Direccion ptr: "<<ptr<<"Dirrecion x"<<&x;
    //double prom=ArregloPromedio(x,ndat);
   // cout<<"el promedio delos datos es "<<prom<<"\n";
  //  ArregloPromedio(x,ndat,prom);
  //  cout<<"el promedio delos datos es "<<prom<<"\n";
  //  ArregloFijarValor(x,ndat,7.6543);
	/*//genera numeros aleatorios entre 0 y 9
    cout<<"Los datos en el arreglo son: ";
    for(int k=0;k<ndat;k++)
		cout<<" "<<ptr[k];
    double valor=0.0;
    cout<<"\n Sumar los datos";
    for(int k=0;k<ndat;k++)
        valor+=ptr[k];
    cout<<"\nLa suma de los datos es: "<<valor;
    cout<<"\nEl promedio de los datos es: "<<valor/ndat;
    double *ptr2=ptr;
    
    double mayor=ptr2[0];
    for(int k=1;k<ndat;k++)
        if(ptr2[k]>mayor) mayor=ptr2[k];
    cout<<"\nEl numero mayor es: "<<mayor;
    //el menor
    double menor=ptr2[0];
    for(int k=1;k<ndat;k++)
        if(ptr2[k]<menor)menor=ptr2[k];
    cout<<"\nel numero menor es: "<<menor;
    //int* ptr3=(int *) 4;//
*/  
    return 0 ;
}
int ArregloMostrar(double *ptr,int nDat){
    cout<<"Los datos de arreglo son \n";
    for(int k=0;k<nDat;k++)
		cout<<" "<<ptr[k];   
    cout<<"\n";
    return 0;
}
int numerosAleatorios(double *ptr,int nDat,double mini, double max){
    srand(time(NULL));//semilla generadora
    if(mini>max){
        double aux;
        aux=max;
        max=mini;
        mini=aux;
    } 
    int range=(int)max-(int)mini+1;
    for(int k=0;k<nDat;k++)
        ptr[k]=mini+rand()%range;
    ArregloMostrar(ptr,nDat);
    return 0;
}
int numerosAleatorios(double *ptr,int nDat){
    srand(time(NULL));//semilla generadora   
    for(int k=0;k<nDat;k++)
        ptr[k]=rand()%100;
    ArregloMostrar(ptr,nDat);
    return 0;
}
int ArregloFijarValor(double *ptr, int nDat, double num){
    for(int k=0;k<nDat;k++)
        ptr[k]=num;
    ArregloMostrar(ptr,nDat);
    return 0;
}
double ArregloPromedio(double *ptr,int nDat){
    double valor=0;
    for(int k=0;k<nDat;k++)
        valor+=ptr[k];
    return valor/(double)nDat;
}
void ArregloPromedio(double *ptr,int nDat,double &prom){
    prom=0;
    for(int k=0;k<nDat;k++)
        prom+=ptr[k];
    prom/=nDat;
}
void ArregloOrdenPorMenor(double *ptr,int nDat){
    //buscar el menor
    for(int posicion=0;posicion<nDat-1;posicion++){
        int posMenor=posicion;
        double menor=ptr[posMenor];
        for(int k=posicion+1;k<nDat;k++){
            if(ptr[k]<menor){
                menor=ptr[k];
                posMenor=k;
            }
        }
        double aux=ptr[posicion];
        ptr[posicion]=ptr[posMenor];
        ptr[posMenor]=aux;
       // ArregloMostrar(ptr,nDat);
    }
    
    //mostramos como vamos
}
double ArregloMediana(double *arr,int nDat){
    double mediana=0;
    //hacemos una copia de arr [] en ptr[]
    double ptr[nDat];
    for(int k=0;k<nDat;k++)
        ptr[k]=arr[k];
    //ordenamos la copia
    ArregloOrdenPorMenor(ptr,nDat);
    mediana=ptr[nDat/2];
    return mediana;
}