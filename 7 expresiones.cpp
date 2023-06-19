#include<iostream>
using namespace std;

int main(){
 float a,b,c,d,e,f,resultado=0;
 cout<<"Digite a: ";cin>>a;
 cout<<"Digite b: ";cin>>b;
 cout<<"Digite c: ";cin>>c;
 cout<<"Digite d: ";cin>>d;
 cout<<"Digite e: ";cin>>e;
 cout<<"Digite f: ";cin>>f;
 
 resultado=(a+(b/c))/(d+(e/f));
 cout.precision(1);
 cout<<"\nSu resultado es: "<<resultado<<endl;
 return 0;	 
}
