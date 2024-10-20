#include<iostream>
int main(){
    int b;
    int *a=&b;
    
    //a=b;
    *a=34;
    std::cout<<*a<<"  "<<&b;
}