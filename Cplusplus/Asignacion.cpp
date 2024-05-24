#include<iostream>

using namespace std;
double* arregloNuevo(int &nD);
int main(){
    int nD;
    double* ptr=arregloNuevo(nD);
   
    /////Todo
    if(!ptr)
    {
        cout<<"no hay memoria";
        return -1;
    }
    for(int k=0;k<nD;k++)
        ptr[k]=0.0;
    
    for(int k=0;k<nD;k++)
        cout<<ptr[k]<<" ";
   if(ptr) delete[]ptr; //liberas memori
    return 0;
}
double* arregloNuevo(int &nD){
    do{
        cout<<"Ingrese la cantidad de datos que guste: ";
        cin>>nD; cin.ignore(256,'\n');    
    }while(nD<1);
     double *ptr=new double[nD];
     return ptr;    
}