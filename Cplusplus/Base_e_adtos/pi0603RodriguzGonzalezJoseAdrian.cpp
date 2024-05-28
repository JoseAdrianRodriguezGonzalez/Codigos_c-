/**
 * @file pi0603RodriguzGonzalezJoseAdrian.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2024-05-24
 *
 * @copyright Copyright (c) 2024
 *
 *
 *
 *
 * 1 ID producto int
 * Nombre del producto string
 * precio float
 * categoria
 * cantidad en stock int
 * peso del producto
 *
 */
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
/****Creacion de estructuras*/
struct cantidades {
    string categoria = "Sin categoria";
    int cantidad = 0;
    float peso = 0.0;
};
struct producto {
    int iD = 0;
    string Nombre = "Sin nombre";
    float precio = 0.0;
    cantidades c;
};
/***Verifca si es un digito**/
bool esNumeroValido(const string& str);
/**Creacion de lista de productos */
void pedirCantidadProductos(int& cantidad);
void CrearLista(producto*& arreglo, const int& cantidades);
void datosIndividuales(producto& p);
void liberarLista(producto* p);
void agregarProductos(producto*& arreglo, int& nProductos, const int& nuevosProductos);
/*******/
/****Mostrar datos*/
void MostrarTodos(producto* p, int nDat);
/**Menu principal***/
void menu(producto*& p);
/**Ordenamiento de cantidades menor mayor, ID,precio, peso,cantidad*/
void porMenorID(producto* p, int ndat);
void porMayorID(producto* p, int ndat);
void porMayorPrecio(producto* p, int ndat);
void porMenorPrecio(producto* p, int ndat);
void porMayorCantidad(producto* p, int ndat);
void porMenorCantidad(producto* p, int ndat);
void porMayorPeso(producto* p, int ndat);
void porMenorPeso(producto* p, int ndat);

/******Menu de cada uno de los datos cuantitativos*/
void ordenarID(producto*& p, int ndat);
void ordenarPrecio(producto*& p, int ndat);
void ordenarCantidad(producto*& p, int ndat);
void ordenarPeso(producto*& p, int ndat);
/****Ordenar strings*/
void AscendenteAZ(producto* p, int ndat);
void DescendenteZA(producto* p, int ndat);
void ordenarNombre(producto* p, int ndat);
void AscendenteCateAZ(producto* p, int ndat);
void DescendenteCateZA(producto* p, int ndat);
void OrdenarCategoria(producto* p, int ndat);
void MenuOrdenar(producto*& p, int ndat);

/*Crear archvio csv***/
void CSVCrear(producto* p, int ndat);
void LeerCSV(producto*& p, int& ndat, int& nRen, bool estate,string &nombre);
void LeerCSV(string*& Renglon, int& nRen,string &nombre);
void AgregarCSV(producto*& p, int& ndat, int nRen,string & nombre);
void actualizarArreglo(producto*& p, int& ndat, string*& tokens);
/*BUSCAR DATOS**/
void BaseDeDatosBuscar(producto*& p, int& ndat);
void BuscarId(producto*& p, int ndat);
void BuscarNombre(producto*& p, int& ndat);
void BuscarPrecio(producto*& p, int& ndat);
void BuscarCategoria(producto*& p, int& ndat);
void BuscarCantidad(producto*& p, int& ndat);
void BuscarPeso(producto*& p, int& ndat);
/***Modifiicar*/
void MenuModificar(producto*& p, int& ndat);
/**Eliminar registroo*/
void EliminarRegistro(producto*& p, int& ndat);
/**Principal*****/
int main(void) {
    producto* p = nullptr;
    menu(p);
    return 0;
}
/**Validar si es un digito***/
bool esNumeroValido(const string& str) {
    for (char c : str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}


/**Funciones de agregar datos**/
void pedirCantidadProductos(int& cantidad) {
    cout << "\nAgregar mas productos";
    do {
        cout << "\nCuantos productos requiere? ";
        cin >> cantidad; cin.ignore(256, '\n');
    } while (cantidad < 1);
}
void CrearLista(producto*& arreglo, const int& cantidades) {
    arreglo = new producto[cantidades];
    for (int i = 0; i < cantidades; i++) {
        cout << "Producto numero" << i + 1;
        datosIndividuales(arreglo[i]);
    }
}
void datosIndividuales(producto& p) {
    cout << "\nIngrese el ID:   ";
    cin >> p.iD; cin.ignore(256, '\n');
    cout << "\nIngrese el nombre del producto:  ";
    getline(cin, p.Nombre); cin.ignore(256, '\n');
    cout << "\nIngrese el precio del producto:  ";
    cin >> p.precio; cin.ignore(256, '\n');
    cout << "Ingrese la cantidad de productos:   ";
    cin >> p.c.cantidad; cin.ignore(256, '\n');
    cout << "Ingrese la categoría del productos:   ";
    getline(cin, p.c.categoria); cin.ignore(256, '\n');
    cout << "Ingrese el peso del producto:   ";
    cin >> p.c.peso; cin.ignore(256, '\n');
}
void liberarLista(producto* p) {
    delete[]p;
}
void agregarProductos(producto*& arreglo, int& nProductos, const int& nuevosProductos) {
    producto* nuevoArreglo = new producto[nProductos + nuevosProductos];

    for (int i = 0; i < nProductos; i++) {
        nuevoArreglo[i] = arreglo[i];
    }

    for (int i = 0; i < nuevosProductos; i++) {
        cout << "Producto nuevo número " << nProductos + i + 1 << endl;
        datosIndividuales(nuevoArreglo[nProductos + i]);
    }

    delete[] arreglo;
    arreglo = nuevoArreglo;
    nProductos += nuevosProductos;
}

/**Mostrar los datos en pantalla*/

void MostrarTodos(producto* p, int nDat) {
    for (int i = 0; i < nDat; i++) {
        cout << "\nRegistro numero" << i + 1;
        cout << "\nID:\t" << p[i].iD;
        cout << "\nNombre del producto:\t" << p[i].Nombre;
        cout << "\nPrecio del producto:\t" << p[i].precio;
        cout << "\nCategoria del producto:\t" << p[i].c.categoria;
        cout << "\nCantidad del producto:\t" << p[i].c.cantidad;
        cout << "\nPeso ddel producto:\t" << p[i].c.peso;
    }
}

/*Ordenamiento datos cuantitativos**/
void porMenorID(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].iD < menor.iD) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void porMayorID(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].iD > mayor.iD) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }

}
void ordenarID(producto*& p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar enteros: ";
        cout << "\n1.- Ordenar por el mayor ";
        cout << "\n2.- Ordenar por el menor ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        porMayorID(p, ndat);
        break;
    case 2:
        porMenorID(p, ndat);
        break;
    default:
        break;
    }
}
void porMayorPrecio(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].precio > mayor.precio) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void porMenorPrecio(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].precio < menor.precio) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void ordenarPrecio(producto*& p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar precio: ";
        cout << "\n1.- Ordenar por el mayor ";
        cout << "\n2.- Ordenar por el menor ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        porMayorPrecio(p, ndat);
        break;
    case 2:
        porMenorPrecio(p, ndat);
        break;
    default:
        break;
    }

}
void porMayorCantidad(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.cantidad > mayor.c.cantidad) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void porMenorCantidad(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.cantidad < menor.c.cantidad) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void ordenarCantidad(producto*& p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar cantidad: ";
        cout << "\n1.- Ordenar por el mayor ";
        cout << "\n2.- Ordenar por el menor ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        porMayorCantidad(p, ndat);
        break;
    case 2:
        porMenorCantidad(p, ndat);
        break;
    default:
        break;
    }

}
void porMayorPeso(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.peso > mayor.c.peso) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void porMenorPeso(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.peso < menor.c.peso) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void ordenarPeso(producto*& p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar por peso: ";
        cout << "\n1.- Ordenar por el mayor ";
        cout << "\n2.- Ordenar por el menor ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        porMayorPeso(p, ndat);
        break;
    case 2:
        porMenorPeso(p, ndat);
        break;
    default:
        break;
    }
}
/***Orddena los sstrings****/
void AscendenteAZ(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].Nombre < menor.Nombre) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void DescendenteZA(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].Nombre > mayor.Nombre) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void ordenarNombre(producto* p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar por peso: ";
        cout << "\n1.- Ordenar por de la A-Z ";
        cout << "\n2.- Ordenar por el Z-A ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        AscendenteAZ(p, ndat);
        break;
    case 2:
        DescendenteZA(p, ndat);
        break;
    default:
        break;
    }
}
void AscendenteCateAZ(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMenor = posicion;
        producto menor = p[posMenor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.categoria < menor.c.categoria) {
                menor = p[k];
                posMenor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMenor];
        p[posMenor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void DescendenteCateZA(producto* p, int ndat) {
    for (int posicion = 0; posicion < ndat - 1; posicion++) {
        int posMayor = posicion;
        producto mayor = p[posMayor];
        for (int k = posicion + 1; k < ndat; k++) {
            if (p[k].c.categoria > mayor.c.categoria) {
                mayor = p[k];
                posMayor = k;
            }
        }
        producto aux = p[posicion];
        p[posicion] = p[posMayor];
        p[posMayor] = aux;
        // ArregloMostrar(ptr,nDat);
    }
}
void OrdenarCategoria(producto* p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nOrdenar por peso: ";
        cout << "\n1.- Ordenar por de la A-Z ";
        cout << "\n2.- Ordenar por el Z-A ";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        AscendenteCateAZ(p, ndat);
        break;
    case 2:
        DescendenteCateZA(p, ndat);
        break;
    default:
        break;
    }
}
/*Meru de ordenar**/
void MenuOrdenar(producto*& p, int ndat) {
    string opcion;
    bool digito;
    int opDig = 0;
    do
    {
        cout << "\nComo le gustaria ordernar sus productos?";
        cout << "\n1.-Por ID";
        cout << "\n2.-Por nombre";
        cout << "\n3.-Por precio";
        cout << "\n4.-Por categoria";
        cout << "\n5.-Por cantidad";
        cout << "\n6.-Por peso";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        ordenarID(p, ndat);
        break;
    case 2:
        ordenarNombre(p, ndat);
        break;
    case 3:
        ordenarPrecio(p, ndat);
        break;

    case 4:
        OrdenarCategoria(p, ndat);
        break;

    case 5:
        ordenarCantidad(p, ndat);
        break;

    case 6:
        ordenarPeso(p, ndat);
        break;

    default:
        break;
    }
}
/*Crear csv**/
void CSVCrear(producto* p, int ndat) {
    ofstream archivo;
    string nombre = "data";
    archivo.open(nombre + ".csv");
    if (!archivo) {
        cout << "Hubo un error al escribrir en el archivo";
        return;
    }
    archivo << "ID,Nombre,Precio,Categoria,Cantidad,Peso\n";
    for (int i = 0; i < ndat - 1; i++) {
        archivo << p[i].iD << "," << p[i].Nombre << "," << p[i].precio << "," << p[i].c.categoria << "," << p[i].c.cantidad << "," << p[i].c.peso << "," << "\n";
    }
    archivo << p[ndat - 1].iD << "," << p[ndat - 1].Nombre << "," << p[ndat - 1].precio << "," << p[ndat - 1].c.categoria << "," << p[ndat - 1].c.cantidad << "," << p[ndat - 1].c.peso << "\n";
    archivo.close();
}
void AgregarCSV(producto*& p, int& ndat, int nRen,string &nombre) {
    string cadenaform, renglonprimero;
    string* Renglon = new string[nRen];
    LeerCSV(Renglon, nRen,nombre);
    if (!Renglon)
        return;
    for (int i = 1; i < nRen; i++) {
        renglonprimero = Renglon[i];
        string* tokens = new string[6];
        int pos = 0;
        for (unsigned int k = 0; k < renglonprimero.length(); k++)
        {
            if (renglonprimero[k] != ',')
                cadenaform += renglonprimero[k];
            if (renglonprimero[k] == ',' || k == renglonprimero.length() - 1) {
                tokens[pos] = cadenaform;
                pos++;
                cadenaform = "";
            }
        }
        if (!ndat) ndat = i;
        actualizarArreglo(p, ndat, tokens);
        delete[] tokens;
    }
    delete[] Renglon;

}
void actualizarArreglo(producto*& p, int& ndat, string*& tokens) {

    producto* nuevoArreglo = new producto[ndat + 1];
    if (ndat > 0) {
        if (p == nullptr) {
            nuevoArreglo[ndat - 1].iD = stoi(tokens[0]);
            nuevoArreglo[ndat - 1].Nombre = tokens[1];
            nuevoArreglo[ndat - 1].precio = stof(tokens[2]);
            nuevoArreglo[ndat - 1].c.categoria = tokens[3];
            nuevoArreglo[ndat - 1].c.cantidad = stoi(tokens[4]);
            nuevoArreglo[ndat - 1].c.peso = stof(tokens[5]);
            p = nuevoArreglo;
        }
        else {
            for (int i = 0; i < ndat; i++) {
                nuevoArreglo[i] = p[i];
            }
            nuevoArreglo[ndat].iD = stoi(tokens[0]);
            nuevoArreglo[ndat].Nombre = tokens[1];
            nuevoArreglo[ndat].precio = stof(tokens[2]);
            nuevoArreglo[ndat].c.categoria = tokens[3];
            nuevoArreglo[ndat].c.cantidad = stoi(tokens[4]);
            nuevoArreglo[ndat].c.peso = stof(tokens[5]);
            delete[] p;
            p = nuevoArreglo;
            ndat++;
        }
    }

}

void LeerCSV(producto*& p, int& ndat, int& nRen, bool estate,string &nombre) {
    ifstream archivo;
    if (estate) {
        cout << "Ubicacion del archivo, (sin la extension):  ";
        getline(cin, nombre);
        archivo.open(nombre + ".csv");
        if (!archivo.is_open()) {
            cout << "En la direccion " << nombre + ".csv" << " No existe ese archivo";
            return;
        }
        string Renglon;
        nRen = 0;
        while (getline(archivo, Renglon))
        {
            cout << "\n Renglon" << ++nRen << ": " << Renglon;
        }
        cout << "\n Se leyeron: " << nRen << " renglones.";
        archivo.close();
        string opcion;
        bool digito;
        int opDig = 0;
        do {
            cout << "Quieres actualizar la base de datos con el CSV";
            cout << "\n1.-Si ";
            cout << "\n2.-No ";
            cout << "\n Escoge la opcion:    ";
            getline(cin, opcion);
            if (!esNumeroValido(opcion))digito = false;
            else {
                opDig = stoi(opcion);
                digito = true;
            }
        } while (!digito || opDig < 0);
        if (opDig == 1) {
            AgregarCSV(p, ndat, nRen,nombre);
        }
    }
    else {
        cout << "Ubicacion del archivo, (sin la extension):  ";
        getline(cin, nombre);
        archivo.open(nombre + ".csv");
        if (!archivo.is_open()) {
            cout << "En la direccion " << nombre + ".csv" << " No existe ese archivo";
            return;
        }
        string Renglon;
        nRen = 0;
        while (getline(archivo, Renglon))
        {
            ++nRen;
        }
    }

}

void LeerCSV(string*& Renglon, int& nRen,string &nombre) {
    ifstream archivo;
    archivo.open(nombre + ".csv");
    if (!archivo.is_open()) {
        cout << "En la direccion " << nombre + ".csv" << " No existe ese archivo";
        return;
    }
    archivo.clear();
    archivo.seekg(0, ios::beg);
    int contador = 0;
    string linea = "";
    while (getline(archivo, linea))
    {
        Renglon[contador] = linea;
        contador++;
    }
    archivo.close();

}
/*Menu*/
/*Buscar**/

void BuscarId(producto*& p, int ndat) {
    int id = 0;
    bool encontrado = false;
    cout << "\nQue id gusta encontrar?  ";
    cin >> id; cin.ignore(256, '\n');

    for (int i = 0; i < ndat; i++) {
        if (p[i].iD == id) {
            cout << "\n Se encontró el ID en el registro con numero: " << i+1;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "\n No se encontro ese ID";
}
void BuscarNombre(producto*& p, int& ndat) {
    string nombre = "";
    bool encontrado = false;
    cout << "\nQue Nombre gusta encontrar?  ";
    getline(cin, nombre);
    for (int i = 0; i < ndat; i++) {
        if (p[i].Nombre == nombre) {
            cout << "\n Se encontro el nombre en el registro con numero: " << i + 1;
            encontrado = true;
        }
    }
    if(!encontrado)
       cout << "\n No se encontro ese nombre";

}
void BuscarPrecio(producto*& p, int& ndat) {
    float Precio = 0;
    bool encontrado = false;
    cout << "\nQue precio gusta encontrar?  ";
    cin >> Precio; cin.ignore(256, '\n');
    for (int i = 0; i < ndat; i++) {
        if (p[i].precio == Precio) {
            cout << "\n Se encontro el Precio en el registro con numero: " << i + 1;
            encontrado = true;
        }
    }
    if(!encontrado) 
        cout << "\n No se encontro ese precio";
}
void BuscarCategoria(producto*& p, int& ndat) {
    string categoria = "";
    bool encontrado = false;
    cout << "\nQue categoria gusta buscar?  ";
    getline(cin, categoria);
    for (int i = 0; i < ndat; i++) {
        if (p[i].c.categoria == categoria) {
            cout << "\n Se encontro la categoria en el registro con numero: " << i + 1;
            encontrado = true;
        }
  
    }
    if(!encontrado)
         cout << "\n No se encontro esa categoria";
}
void BuscarCantidad(producto*& p, int& ndat) {
    int cantidad = 0;
    bool encontrado = false;
    cout << "\nQue cantidad gusta buscar?  ";
    cin >> cantidad; cin.ignore(256, '\n');
    for (int i = 0; i < ndat; i++) {
        if (p[i].c.cantidad == cantidad) {
            cout << "\n Se encontro esa cantidad en el registro con numero: " << i + 1;
            encontrado = true;
        }
    }
    if(!encontrado)
            cout << "\n No se encontro esa cantidad";
}
void BuscarPeso(producto*& p, int& ndat) {
    float peso = 0;
    bool encontrado = false;
    cout << "\nQue peso gusta buscar?  ";
    cin >> peso; cin.ignore(256, '\n');
    for (int i = 0; i < ndat; i++) {
        if (p[i].c.peso == peso) {
            cout << "\n Se encontro el peso en el registro con numero: " << i + 1;
            encontrado = true;
        }
    }
    if(!encontrado)
        cout << "\n No se encontro ese peso";
}

void BaseDeDatosBuscar(producto*& p, int& ndat) {
    string opcion = "";
    bool digito = false;
    int opDig = 0;
    if (!ndat) {
        cout << "No hay registros que buscar en la base de datos";
        return;
    }
    do
    {
        cout << "\nQue le gustaria buscar?";
        cout << "\n1.-Por ID";
        cout << "\n2.-Por nombre";
        cout << "\n3.-Por precio";
        cout << "\n4.-Por categoria";
        cout << "\n5.-Por cantidad";
        cout << "\n6.-Por peso";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        BuscarId(p, ndat);
        break;
    case 2:
        BuscarNombre(p, ndat);
        break;
    case 3:
        BuscarPrecio(p, ndat);
        break;

    case 4:
        BuscarCategoria(p, ndat);
        break;

    case 5:
        BuscarCantidad(p, ndat);
        break;

    case 6:
        BuscarPeso(p, ndat);
        break;
    default:
        break;
    }
}

/*Modificar un registro*/
void MenuModificar(producto*& p, int& ndat) {
    if (ndat < 1 || p == nullptr) {
        cout << "Aun no hay registros";
        return;
    }
    int registro = 0;
    cout << "Que registro quieres modificar?";
    cin >> registro; cin.ignore(256, '\n');
    string opcion;
    bool digito;
    int opDig = 0;
    if (!(registro > 0 || registro <= ndat)) {
        cout << "Esta fuera de rango";
        return;
    }
    do
    {
        cout << "\nQue quires modiificar";
        cout << "\n1.-ID";
        cout << "\n2.-nombre";
        cout << "\n3.-precio";
        cout << "\n4.-categoria";
        cout << "\n5.-cantidad";
        cout << "\n6.-peso";
        cout << "\n7.-Todo";
        cout << "\n Escoge la opcion:    ";
        getline(cin, opcion);
        if (!esNumeroValido(opcion))digito = false;
        else {
            opDig = stoi(opcion);
            digito = true;
        }
    } while (!digito || opDig < 0);
    switch (opDig)
    {
    case 1:
        cout << "Modifique el ID:  ";
        cin >> p[registro-1].iD; cin.ignore(256, '\n');
        break;
    case 2:
        cout << "Modifique el nombre: ";
        getline(cin, p[registro-1].Nombre);
        break;
    case 3:
        cout << "Modifique el precio: ";
        cin >> p[registro-1].precio; cin.ignore(256, '\n');
        break;

    case 4:
        cout << "Modifique la cantidad: ";
        getline(cin,p[registro-1].c.categoria);
        break;

    case 5:
        cout << "Modifique la cantidad: ";
        cin >> p[registro-1].c.cantidad; cin.ignore(256, '\n');
        break;

    case 6:
        cout << "Modifique el peso: ";
        cin >> p[registro-1].c.peso; cin.ignore(256, '\n');
        break;

    case 7:
        datosIndividuales(p[registro-1]);
        break;
    default:
        break;

    }
}

void EliminarRegistro(producto*& p, int &ndat) {
    if (ndat < 1 || p == nullptr) {
        cout << "Aun no hay registros";
        return;
    }
    int registro = 0;
    cout << "Que registro quieres eliminar?";
    cin >> registro; cin.ignore(256, '\n');
    if (!(registro > 0 || registro <= ndat)) {
        cout << "Esta fuera de rango";
        return;
    }
    p[registro - 1] = p[ndat - 1];
    ndat--;

}
void menu(producto * &p) {
    string opcionpri;
    string nombre = "";
    bool sino;
    int opdig;
    int nRen = 0;
    int cantidad, viejacantidad = 0;
    do {
        string opcion;
        bool digito;
        int opDig = 0;
        do {
            cout << "Base de datos de productos de una tienda de abarrotes:";
            cout << "\nMenu de acciones";
            cout << "\n1.-Agregar productos";
            cout << "\n2.-Mostrar productos";
            cout << "\n3.-Ordenar los produuctos";
            cout << "\n4.-Crear CSV";
            cout << "\n5.-Leer CSV";
            cout << "\n6.-Buscar un dato";
            cout << "\n7.-Modificar registro";
            cout << "\n8.-Eliminar registro";
            cout << "\n9.-Liberar valores";
            cout << "\n0.-Salir";
            cout << "\nQue quiere hacer?:  ";
            getline(cin, opcion);
            if (!esNumeroValido(opcion))digito = false;
            else {
                opDig = stoi(opcion);
                digito = true;
            }
        } while (!digito || opDig < 0);
        string opcionA;
        bool digitoA;
        int opDigA = 0;
        switch (opDig) {
        case 1:
            do {
                cout << "\nQuieres agregarlos manualmente o tienes un CSV?";
                cout << "\n1.-  Agregar manualmente: ";
                cout << "\n2.- Agregar por CSV: ";
                cout << " \n Escoge una opcion: ";
                getline(cin, opcionA);
                if (!esNumeroValido(opcionA))digitoA = false;
                else {
                    opDigA = stoi(opcionA);
                    digitoA = true;
                }
            } while (!digitoA || opDigA < 0);
            switch (opDigA)
            {
            case 1:
                if (p == nullptr) {
                    pedirCantidadProductos(cantidad);
                    CrearLista(p, cantidad);
                    viejacantidad = cantidad;
                }
                else {
                    pedirCantidadProductos(cantidad);
                    agregarProductos(p, viejacantidad, cantidad);
                }
                break;
            case 2:
                LeerCSV(p, viejacantidad, nRen, false, nombre);
                AgregarCSV(p, viejacantidad, nRen, nombre);
                break;
            }
            break;
        case 2:
            MostrarTodos(p, viejacantidad);
            break;
        case 3:
            MenuOrdenar(p, viejacantidad);
            break;
        case 4:
            CSVCrear(p, viejacantidad);
            break;
        case 5:
            LeerCSV(p, viejacantidad, nRen, true, nombre);
            break;
        case 6:
            BaseDeDatosBuscar(p, viejacantidad);
            break;
        case 7:
            MenuModificar(p, viejacantidad);
            break;
        case 8:
            EliminarRegistro(p,viejacantidad);
            break;
        case 9:
            liberarLista(p);
            break;
        case 0:
            return;
        }
        do {
            cout << "\nQuieres volver al menu principal?";
            cout << "\n1-.Si";
            cout << "\n2-.No\nEscoge la opcion:   ";
            getline(cin, opcionpri);
            if (!esNumeroValido(opcionpri))sino = false;
            else {
                opdig = stoi(opcionpri);
                sino = true;
            }
        } while (!sino || opdig < 1 || opdig>2);
    } while (opdig == 1);
}