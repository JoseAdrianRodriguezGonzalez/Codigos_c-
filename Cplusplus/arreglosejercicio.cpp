//ejercicio
#include<iostream>
#include<ctime>
//generar numero aleatorios
using namespace std;
int main (){
	//cout<<"Hola";	
	int ndat=0;//puede ser definido en tiempo de ejecución
	
	do{
		cout<<"Ingrese un dato";
		cin>>ndat;
	}while(ndat<=0);
	
	double x[ndat]={}; //un arreglo de nDat numeros tipo double
	//Los indices empiezan en 0
	//y van hasta nDat-1
	//for(int k=0;k<ndat;k++)
	//	x[k]=10*k+k;
    //asignacion
	srand(time(NULL));
    for(int k=0;k<ndat;k++){
        x[k]=rand()%10-5;
    }
        
    for(int k=0;k<ndat;k++)
		cout<<" "<<x[k];
    //La suma de los datos sumar todos los datos
    double valor=0.0;
    cout<<"\n Sumar los datos";
    for(int k=0;k<ndat;k++)
        valor+=x[k];
    cout<<"\nLa suma de los datos es: "<<valor;
    cout<<"\nEl promedio de los datos es: "<<valor/ndat;
    //el numero mayor
    double mayor=x[0];
    for(int k=1;k<ndat;k++)
        if(x[k]>mayor) mayor=x[k];
    cout<<"\nEl numero mayor es: "<<mayor;
    //el menor
    double menor=x[0];
    for(int k=1;k<ndat;k++)
        if(x[k]<menor)menor=x[k];
    cout<<"\nel numero menor es: "<<menor;
    //buscar los que sean pares:
    //numeros aleatorios
	return 0;
}