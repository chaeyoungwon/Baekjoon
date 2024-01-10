#include <iostream>
using namespace std;

int main(){
    int a, b, c;
    while (1){
        cin >> a >> b >> c;
        if (a+b+c ==0)
            break;
        if (a*a + b*b == c*c)
            cout<<"right"<<"\n"; 
        else if(a*a + c*c == b*b)
            cout<<"right"<<"\n";
        else if(b*b + c*c == a*a)
            cout<<"right"<<"\n"; 
        else
            cout<<"wrong"<<"\n";
    }
    return 0;
}