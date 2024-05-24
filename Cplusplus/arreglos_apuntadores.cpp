#include<iostream>
using namespace std;
int main(){
    int ndat=0;
    /**pedir la longitud de la cadena*/
	do{
		cout<<"Ingrese un dato: ";
		cin>>ndat; cin.ignore(256,'\n');
	}while(ndat< 1);
	double x[ndat]={}; //La variable del arreglo
    cout<<"Los datos del arreglo son: ";
    for(int k=0;k<ndat;k++)
		cout<<" "<<x[k];//muestra los datos 
/*	srand(time(NULL));//semilla generadora
    for(int k=0;k<ndat;k++)
        x[k]=rand()%10-5;//genera numeros aleatorios entre 0 y 9
    cout<<"Los datos en el arreglo son: ";
    for(int k=0;k<ndat;k++)
		cout<<" "<<x[k];
    double valor=0.0;
    cout<<"\n Sumar los datos";
    for(int k=0;k<ndat;k++)
        valor+=x[k];
    cout<<"\nLa suma de los datos es: "<<valor;
    cout<<"\nEl promedio de los datos es: "<<valor/ndat;
    double mayor=x[0];
    for(int k=1;k<ndat;k++)
        if(x[k]>mayor) mayor=x[k];
    cout<<"\nEl numero mayor es: "<<mayor;
    //el menor
    double menor=x[0];
    for(int k=1;k<ndat;k++)
        if(x[k]<menor)menor=x[k];
    cout<<"\nel numero menor es: "<<menor;
 */
    return 0 ;
}