#include<iostream>
using namespace std;
int main(){
    int nRen;
    int nCol;
    do{
        cout<<"Cuantos renglones quiere: ";
        cin>>nRen;
        cout<<"Cuantas columnas requiere: ";
        cin>>nCol;
    }while(nRen<1&&nCol<1);
    double mat[nRen][nCol];//2 renglones, 3 columnas
    for(int r=0;r<nRen;r++)
        for(int c=0;c<nCol;c++)
            mat[r][c]=1.0;
    for(int r=0;r<nRen;r++){
        for(int c=0;c<nCol;c++)
            cout<<mat[r][c]<<" ";
        cout<<"\n";
    }
    double *p=&mat[0][0];
    for(int k=0;k<nCol*nRen;k++)
        cout<<p[k];
}