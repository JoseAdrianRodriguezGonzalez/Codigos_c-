#include<string>

class Box{
    private:
    float peso;
    std::string color; 
    public:
        Box(){//contructor
            peso =0;
            color = "sin color";
        } 
         Box(float peso, string color){
            this -> peso = peso;
            this->color = color;
         }
        ~Box(){} //destructor
};