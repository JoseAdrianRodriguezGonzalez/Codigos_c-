#include<vector>
#include<iostream>
#include<fstream>
struct User{
    std::string _name;
    int _nua;
    User(std::string name,int nua): _name(name),_nua(nua){}
};
class IFile{//C# ->interface
//Todas las funcIones deben ser virtuales 
//No debe de tener variables miembros
    public:
        virtual bool open()=0;
        virtual bool save(std::string name)=0;

};
class CSVFile :public IFile{
    private:
    std::vector<User> _users;
    public:
    CSVFile(std::vector<User> v){
        this->_users=v;
    }
    bool open() override{

    }
    //result pattern
    bool save(std::string name) override{
        std::ofstream file(name);
        if(file.is_open()){
            for(const auto & user : _users){
                file<<user._name<<","<<user._nua<<"\n";
            }
            file.close();
            return true;
        }
        file.close();
        std::cerr<<"Error al abrir archivo\n";
        return false;
    }
};
/**Las estructuras tiene todo lo mismo que las clases a excepción de los métodos de acceso */
int main(){
    User user("Adrian",148661);
    std::vector<User> users;//User * users=new []
    users.push_back(user);
    users.push_back(User("Marco",282999));
    for (const auto & user :users){
        std::cout<<user._name<<",";
        std::cout<<user._nua<<"\n";
    }
    CSVFile fi(users);
    fi.save("users.csv");
    return 0;
}

////  cpp,hpp libreria 
//  Cada vez que cierra el programa se guarda el csv
// Investigar si std::ostream, concatena, trunca o ¿que hace?
// SETS 