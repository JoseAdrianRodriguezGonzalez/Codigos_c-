#include<iostream>
class car{
    private:
        std::string a="mundo";
        int edad;
    public:
        void MostrarMensaje(){
            std::cout<<"Hola "<<this->a;
        }
        void asignacion(int edad){
            this->edad=edad;
            if(edad>130){
                std::cout<<"Error";
                return;
            }
            if(edad<0){
                std::cout<<"Error";
                return;
            }
            std::cout<<"Tienes"<<edad;
        }
        int obtener(){
            return this->edad;
        }
        //En este caso this es un apuntador, y por lo tanto necesita el operador de flecha
        //->operador de resolucion para objetos
        //ecapsulamiento, manera de protección de datos que podrían ser sensibles
};
int main(){
    car carro1;
    carro1.asignacion(2);
    carro1.MostrarMensaje();
    std::cout<<"Obtuviste los datos"<<carro1.obtener();
    return 0;
}
//cosmic