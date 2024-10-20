#include<iostream>
class Box{
    private:
        int Wide;
        int Large;
        int Height;
    public:
    //: Operador de herencia
        Box(int W,int L,int H):Wide(W),Large(L),Height(H){}
//solo un destructor 
        ~Box(){
            std::cout<<"Destructor";
        }     
};
int main(){
    Box box1(12,32,43),box2(10,23,1),box3(23,12,65);
    std::cout<<"Heeeeey";
    return 0;
}