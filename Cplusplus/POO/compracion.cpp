#include<iostream>
int max (int a,int b){
    return (a>b) ? a:b;
}
float max(float a,float b){
    return (a>b)?a:b;
}/*
template <typename T>
T max (T a, T b ){
    return (a>b)?a:b;
}*/
template <typename T>
class MinMax{
    public:
     T max(T a,T b){
        return (a>b)?a:b;
    }
    T min(T a,T b){
        return (a<b)?a:b;
    }
};
int main(){
    MinMax<int> minmax;
    std::cout<<minmax.max(10,20)<<"\n";
        std::cout<<minmax.min(10,20)<<"\n";
}