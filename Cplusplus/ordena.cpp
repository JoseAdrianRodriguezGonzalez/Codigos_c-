#include<iostream>
using namespace std;
int main(){
    int Ndat=5;
    int x[]={2,-3,5,2-12};
    for(int j=0;j<Ndat-1;j++){
        int pos=j;
        int posMayor=x[pos];
        for(int i=1;i<Ndat;i++){
            if(posMayor<x[i]){
                posMayor=x[i];
                pos=i;
            }
        }
        int aux=x[j];
        x[j]=x[pos];
        x[pos]=aux;
    }

    cout<<orden;
}