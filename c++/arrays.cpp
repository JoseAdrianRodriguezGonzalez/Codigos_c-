#include "arraysp.cpp"

int main(){
    size_t longsize;
    requestData(&longsize);
    cout<<longsize<<endl;
    double x[longsize];
    fixed(longsize,0,x);
    showArray(x,longsize);
    randomNumbers(x,longsize);
    showArray(x,longsize);
    randomNumbers(x,longsize,10,8);
    showArray(x,longsize);
    cout<<"El promedio es: "<<mean(x,longsize)<<endl;
    cout<<"El valor mas alto es: "<<highestValue(x,longsize)<<endl;
    cout<<"La posicion del valor mas alto es: "<<poshighestValue(x,longsize)<<endl;
    cout<<"El valor menor es: "<<lessValue(x,longsize)<<endl;
    cout<<"La posicion del valor menor es: "<<poslessValue(x,longsize)<<endl;
    bubblesort(x,longsize);
    showArray(x,longsize);
    double moda1;
    int rep;
    moda(x,longsize,moda1,rep);
    cout<<"El numero que mas se repite es el: "<<moda1<<"\n con "<< rep<<" repeticiones";
}