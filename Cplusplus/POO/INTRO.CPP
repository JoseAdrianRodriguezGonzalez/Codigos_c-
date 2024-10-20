#include<iostream>
using namespace std;
// ::=> operador de resoución de alcance, esto permite acceder a las funciones
namespace espacio1{
    int myInt=10;
    void imprimir(){
        std::cout<<"Espacio 1: "<<myInt<<"\n";
    }
}
class num{
    
    //otodo lo que este dentro de la clase de nombre tendrá acceso
    private:
        int x;
        int y;
    public:
    num(){ //siempre se imprime al ccrear un objeto
        std::cout<<"constructor\n";
        x=0;
        y=0;
    }
    ~num(){//permite destruir el objeto de aquí y libera la memoria   
        std::cout<<"destructor";
    }
        void imprimir(int x,int y){
            std::cout<<"X: "<<x<<"\nY: "<<y;
        }
};//protected accede por medio de clases derivadas, herencia
int main(){
    espacio1::imprimir();
    num n1; //n1 es una instancia. Una instancia es un objeto
    n1.imprimir(3,45);
    return 0;
}