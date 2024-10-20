#include<iostream>
class A{
    public:
        void suma(int a,int b){
            std::cout<<a+b;
        }
        void suma(float a,float b){
            std::cout<<a+b;
        }
};
int main(){
    A alo;
    alo.suma(2,3); 
    return 0;
}