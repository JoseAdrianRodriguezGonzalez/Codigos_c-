#include<iostream>
using namespace std;
int main (){
	//cout<<"Hola";	
	int ndat;//puede ser definido en tiempo de ejecución
	
	do{
		cout<<"Ingrese un dato";
		cin>>ndat;
	}while(ndat<=0);
	
	double x[ndat]={}; //un arreglo de nDat numeros tipo double
	//Los indices empiezan en 0
	//y van hasta nDat-1
	for(int k=0;k<ndat;k++)
		x[k]=10*k+k;
	for(int k=0;k<ndat;k++)
		cout<<" "<<x[k];
	return 0;
}