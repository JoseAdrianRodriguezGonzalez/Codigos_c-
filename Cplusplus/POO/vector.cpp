#include<iostream>
#include<vector>
template <typename T>
class Vector{
    private:
        int size;
        int index;
        T *data;
    public:
    Vector(int _size): size(_size){
        this->index=0;
        this->data=new T[this->size];
    }
    ~Vector(){
        delete [] this->data;
    }
    void push(T value){
        if(this->index<this->size)
            this->data[this->index++]=value; //añado y luego incremento 
    }
    void print(){
        for(int i=0;i<this->index;i++){
            std::cout<<this->data[i]<<" "<<std::endl;
        }
    }
};
int main(){
    Vector<Vector<int>> vec3(10);
    Vector<std::string> vec1(20);
    vec1.push("Hola");
    vec1.print();
    std::vector<std::string> vec2;
    vec2.push_back("hola!");
    vec2.push_back("Soy Yahir");
    for(int i=0;i<vec2.size();i++){
        std::cout<<vec2[i]<<" "<<std::endl;
    }
}