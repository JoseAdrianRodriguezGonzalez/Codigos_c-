#include<iostream>//input-output stream
#include<ctime>
#include<cmath>
#include<fstream>//file
using namespace std;
int ArregloMostrar(double* ptr, int nDat);//RECUERDA QUE NO ES NECESARIO PONER EN EL PROTOTIPO NO SE NECESARIO COLOCAR EL NOMVRE DE LA VARIABLE
int numerosAleatorios(double* ptr, int nDat, double mini, double max);
int numerosAleatorios(double* ptr, int nDat);
int ArregloFijarValor(double* ptr, int nDat, double num);
double ArregloPromedio(double* ptr, int nDat);
void ArregloPromedio(double* ptr, int nDat, double& prom);
void ArregloOrdenPorMenor(double* ptr, int nDat);
double ArregloMediana(double* ptr, int nDat);
int datos();
void maximo(double *ptr, int ndat, double &mayor);
void minimo(double *ptr, int ndat, double &menor);
void maximoPos(double *ptr, int ndat, double &mayor,int &posMax);
void ArregloModa(double *ptr,int ndat,double &moda,int &nRepeticiones);