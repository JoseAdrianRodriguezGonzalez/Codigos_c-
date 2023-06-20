#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int a,b,c;
	float resultado1,resultado2;
	cout<<"Valor a:";
	cin>>a;
	cout<<"Valor b:";
	cin>>b;
	cout<<"Valor c:";
	cin>>c;
	resultado1= (-b+sqrt(pow(b,2)-4*(a*c)))/(2*a);
	resultado2=(-b-sqrt(pow(b,2)-4*(a*c)))/(2*a);
	cout<<"x1: "<<resultado1<<endl;
	cout<<"x2: "<<resultado2;
	return 0;
}
