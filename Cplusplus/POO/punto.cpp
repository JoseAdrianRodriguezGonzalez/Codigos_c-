#include<iostream>
class Point{
    private:
        int x,y;
    public:
        Point(int _x,int _y){
            this->x=_x;
            this->y=_y;
            std::cout<<"Clase base !!";          
        }
};
class Point3: public Point{
    protected:
        int z;
    public:
        Point3(): Point(0,0), z(0){}
};
int main (){
    return 0;
}