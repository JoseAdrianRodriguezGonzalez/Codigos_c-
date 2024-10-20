#include<iostream>
#include<cstring>
class MyString{
    private:
        char*data;
    public:
    MyString(const char * _string){
         this->data= new char[std::strlen(_string)+1];
        std::strcpy(this->data,_string);
    }
    MyString(const MyString &_string){
        this->data= new char[std::strlen(_string.data)+1];
        std::strcpy(this->data,_string.data);
    }
    ~MyString(){
         delete[] this->data;
    }
    void print(){
        std::cout<<this->data<<"\n";
    }
};
int main(){
    MyString Hi("Hello ffff");
    MyString Hi2=Hi;
    Hi.print();
    Hi2.print();
    return 0;
}