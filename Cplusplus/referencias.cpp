#include<iostream>
using namespace std;
int Intercambio(int &x,int &y);
int main(){
    int x=2;
    int y=3;
    cout<<"\n"<<x<<"\n"<<y;
    Intercambio(x,y);
    cout<<"\n"<<x<<"\n"<<y ;   
    return 0;
} // namespace std;
int Intercambio(int &x,int &y){
    int aux;
    aux=x;
    x=y;
    y=aux;
}
