#include<iostream>
#include<memory>
class Array{
    private: 
        std::unique_ptr<int[]>datos;
        int size;
        int capacity;
    public:
        Array(){
            this->datos=nullptr;
            this->capacity=0;
            this->size=0;
        }
        Array(int _capacity){
            this->capacity=_capacity;
            this->datos=std::make_unique<int[]>(this->capacity);
            this->size=0;
        }
        ~Array(){

        }
    void setdata(int _data){
        if(this->size<this->capacity){
            this->datos[this->size++]=_data;
        }
        else{
            std::cout<<"LLeno";
        }
        
    }
    void getData(){
        for(int i=0;i<this->capacity;i++){
            std::cout<<this->datos[i]<<", ";
        }
    }
};
int main(){
    Array array(2);
    array.setdata(10);
    array.setdata(12);
    array.getData();
    return 0;
}