#include<iostream>
int main(){
    int array[10];
    std::cout<<sizeof(array)/sizeof(array[0]);
    return 0;
}