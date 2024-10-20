#include<iostream>
#include<string>
int main(){
    int x=121;
    std::string stringx=std::to_string(x);
    std::string inv="";
    int j=0;
    for(int i=stringx.length();i>=0;i--){
        
        inv[j]=stringx[i];
        j++;
    }
    std::cout<<inv<<"\n";
    std::cout<<stringx[0];
    if(stringx==inv){
        std::cout<<"Si";
    }
    return 0;
}