#include<iostream>
class Point{
    private:
        int x,y;
    public:
        Point(int _x,int _y):x(_x),y(_y){std::cout<<"Constructor\n";}
        //constructor copia
        //Se necesita como buena práctia, ya que si lo dejamos sin el constructor se puede quedar inutilizado al pasarle vairables no nativas
        Point(const Point &_p){
            this->x=_p.x;
            this->y=_p.y;
            std::cout<<"Constructor copia!\n";
        }
        ~Point(){
            std::cout<<"Destructor";
        }
        void imprimir(){
            std::cout<<"x: "<<x<<" y: "<<y;
        }
        void get(int _x,int _y){
            this->x=_x;
            this->y=_y;
        }
};
Point func();
int main(){
    Point pointer(2,3);
    pointer.imprimir();
    pointer.get(3,6);
    pointer.imprimir();
    std::cout<<"Aun no";
    Point pointer1=func();
        std::cout<<"Aun si";
    return 0;
}
Point func(){
    Point p2(6,1);
    std::cout<<"hey";
    return p2;
}