#include <iostream>
#include <vector>

struct Persona{
    std::string nombre;
    int nua;
    Persona(std::string _nombre, int _nua){
        nombre = _nombre;
        nua = _nua;
    }
};

struct Libro{
    std::string autor;
    std::string titulo;
    unsigned int copias;
    Libro(std::string _autor,std::string _titulo, unsigned int _copias){
        autor = _autor;
        titulo = _titulo;
        copias = _copias;
    }
};

class Biblioteca{
private:
    std::vector<Persona> personas;
    std::vector<Libro> libros;
public:
    void agregarPersona(Persona persona)
    {
        personas.push_back(persona);
    }
    void mostrarUsuarios(){
        // for(size_t i = 0; i < personas.size(); i++)
        for (const auto & persona : personas)
        {
            std::cout << "Nombre: " << persona.nombre;
            std::cout << ", NUA: " << persona.nua << std::endl;
        }
    }
    void agregarLibro(Libro libro)
    {
        libros.push_back(libro);
    }
    void mostrarLibros(){
        // for(size_t i = 0; i < personas.size(); i++)
        for (const auto & libro : libros)
        {
            std::cout << "Autor: " << libro.autor;
            std::cout << ", Titulo: " << libro.titulo;
            std::cout << ", Copias: " << libro.copias << std::endl;
        }
    }
    Libro buscarlibro(std::string titulo)
    {
        for (const auto & libro : libros)
        {
            if(libro.titulo == titulo)
                return libro;
        }
        return Libro("","",0);
    }

};
int main() {
    Biblioteca biblioteca;
    biblioteca.agregarPersona(Persona("Juan", 102334));
    biblioteca.agregarPersona(Persona("Pepe", 102335));

    biblioteca.agregarLibro(Libro("George Orwell", "1984", 4));
    biblioteca.agregarLibro(Libro("Juan Rulfo", "El llano en llamas", 5));
    biblioteca.agregarLibro(Libro("Isabella Allende", "Como agua para chocolate", 3));
    biblioteca.agregarLibro(Libro("Jose Emilio Pacheco", "Batallas en el desierto", 2));
    biblioteca.mostrarUsuarios();
    biblioteca.mostrarLibros();

    Libro librito = biblioteca.buscarlibro("Como agua para chocolate");
    return 0;
}