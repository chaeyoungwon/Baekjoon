#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a[3];
    while (true){
        for(int i=0; i<3; i++)
            cin >>a[i];
        if (a[0]==0 && a[1]==0 && a[2]==0) break;
        
        sort(a, a+3);
        if (a[2]>=a[0]+a[1]){
            cout<<"Invalid"<<"\n";
        }
        else if (a[0]==a[1] && a[1]==a[2]){
            cout<<"Equilateral"<<"\n";
        }
        else if (a[0]!=a[1] && a[1]!=a[2] && a[0]!=a[2]){
            cout<<"Scalene"<<"\n";
        }
        else{
            cout<<"Isosceles"<<"\n";
        }
        
    }
}