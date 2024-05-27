#include "arreglos.hpp"
int datos(){
    int ndat=0;
    do{
		cout<<"Ingrese un dato: ";
		cin>>ndat; cin.ignore(256,'\n');
	}while(ndat< 1);
    return ndat;
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
void maximo(double *ptr, int ndat, double &mayor){
    mayor=ptr[0];
    for(int k=1;k<ndat;k++)
        if(ptr[k]>mayor) mayor=ptr[k];
}
void maximoPos(double *ptr, int ndat, double &mayor,int &posMax){
    posMax=0;
    mayor=ptr[posMax];
    for(int k=1;k<ndat;k++){
        if(ptr[k]>mayor){
          mayor=ptr[k];  
          posMax=k;
        } 
    }
}
void minimo(double *ptr, int ndat, double &menor){
    menor=ptr[0];
    for(int k=1;k<ndat;k++)
        if(ptr[k]<menor) menor=ptr[k];
}
void ArregloModa(double *ptr,int ndat,double &moda,int &nRepeticiones){
    double menor,mayor;
    minimo(ptr,ndat,menor); 
    menor=round(menor);
    maximo(ptr,ndat,mayor);
    mayor=round(mayor);
  //  cout<<menor<<","<<mayor;
    int nBins= mayor-menor+1;
    double histo[nBins]={};
  //  ArregloMostrar(histo,nBins);
    for(int k=0;k<ndat;k++)
        histo[(int)(round(ptr[k])-menor)]++;
    double maxen=0;
    int pos;
    maximoPos(histo,nBins,maxen,pos);
  //  cout<<"max "<<maxen<<"pos"<<pos;
  //  ArregloMostrar(histo,nBins);
    moda=pos+menor;
    nRepeticiones=maxen;
}
