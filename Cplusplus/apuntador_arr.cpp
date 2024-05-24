#include<iostream>
using namespace std;
int main(){
    int ndat=0;
    /**pedir la longitud de la cadena*/
	do{
		cout<<"Ingrese un dato: ";
		cin>>ndat; cin.ignore(256,'\n');
	}while(ndat< 1);
	double x[ndat]={}; //es un apuntador el nombre del arreglo apuntador constante
    //en c++ el nombre de un arreglo es un apuntador al primer dato del arreglo

    //un apuntador variable
    double *ptr;//genera un puntero que no se casa a una dirección de memoria 
    ptr=x;//se emparejan a la misma direecion de memoria
    //cout<<"Direccion ptr: "<<ptr<<"Dirrecion x"<<&x;
    //a partir de aqui se pueden usar ambos de forma indistinta
    cout<<"Los datos del arreglo son: ";
    for(int k=0;k<ndat;k++)
		cout<<" "<<ptr[k];//muestra los datos 
	srand(time(NULL));//semilla generadora
    for(int k=0;k<ndat;k++)
        ptr[k]=rand()%10-5;//genera numeros aleatorios entre 0 y 9
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
    return 0 ;
}