#include "arraysp.hpp"
void requestData(size_t* SizeOfArray){
    int n;
    do{
    cout<< "which size do you need for your array: ";
    cin>>n;
    }while(n<0);
    *SizeOfArray=(size_t) n;
}
void fixed(size_t n,double value,double array[]){
    for(size_t i=0;i<n;i++){
        array[i]=value;
    }
    
}
void showArray(double* data, size_t SizeOfArray){
    for(size_t i=0;i<SizeOfArray;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
void randomNumbers(double* data,size_t SizeOfArray){
    srand(time(NULL));
    for(size_t i=0;i<SizeOfArray;i++){
        data[i]=rand()%100;
    }
}
void randomNumbers(double* data,size_t SizeOfArray,double min, double max){
    do{
        cout<<"Escriba el intervalo que guste:";
        cout<<"\nValor minimo: ";
        cin>>min;
        cout<<"\nValor maximo: ";
        cin>>max;
    }while(max<min);
   /* if(max<min){
        double aux=min;
        min=max;
        max=aux;
    }*/
    int range=(int)max-(int)min+1;
    srand(time(NULL));
    for(size_t i=0;i<SizeOfArray;i++){
        data[i]=min+rand()%range;
    }
}
double mean(double *data,size_t SizeOfArray){
    double sum;
    for(size_t i=0;i<SizeOfArray;i++){
        sum+=data[i];
    }
    return sum/(double )SizeOfArray;
}
double highestValue(double *data, size_t SizeOfArray){
    double mayor=data[0];
    for(size_t i=0;i<SizeOfArray;i++){
        if(mayor<data[i])
            mayor=data[i];
    }
    return mayor;
}
double lessValue(double *data, size_t SizeOfArray){
    double menor=data[0];
    for(size_t i=0;i<SizeOfArray;i++){
        if(menor>data[i])
            menor=data[i];
    }
    return menor;
}
size_t poshighestValue(double *data, size_t SizeOfArray){
    size_t pos=0;
    double mayor=data[pos];
    for(size_t i=0; i<SizeOfArray;i++){
        if(mayor<data[i]){
            mayor=data[i];
            pos=i;
        }
    }
    return pos;
}
size_t poslessValue(double *data, size_t SizeOfArray){
    size_t pos=0;
    double menor=data[pos];
    for(size_t i=0;i<SizeOfArray; i++){
        if(menor>data[i]){
            menor=data[i];
            pos=i;
        }
    }
    return pos;
}
void bubblesort(double *data,size_t SizeOfArray){
 
    for (size_t i = 0; i < SizeOfArray-1; i++)
    {
        size_t pos=i;
        double sort=data[pos];
        for (size_t j = pos+1; j < SizeOfArray; j++)
        {
            if(sort<data[j]){
                sort=data[j];
                pos=j;
            }
        }
        double aux=data[i];
        data[i]=data[pos];
        data[pos]=aux;
    }
    
}

void moda(double *x,size_t nDat,double &moda,int &repeticiones){
    double high=round(highestValue(x,nDat)),low=round(lessValue(x,nDat));
    int range=high-low+1;
    double hist[range]={};
    for(size_t i=0;i<nDat;i++)
        hist[(int)(round(x[i])-low)]++;
    moda=poshighestValue(hist,range)+low;
    repeticiones=highestValue(hist,range);
}
