#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
void moda(double *x,size_t nDat,double &moda,int &repeticiones);
void showArray(double* data, size_t SizeOfArray);
void requestData(size_t* SizeOfArray);
void fixed(size_t n,double value,double array[]);
void randomNumbers(double* data,size_t SizeOfArray);
void randomNumbers(double* data,size_t SizeOfArray,double min,double max);
double mean(double *data,size_t SizeOfArray);
double highestValue(double *data, size_t SizeOfArray);
double lessValue(double *data, size_t SizeOfArray);
size_t poshighestValue(double *data, size_t SizeOfArray);
size_t poslessValue(double *data, size_t SizeOfArray);
void bubblesort(double *data,size_t SizeOfArray);