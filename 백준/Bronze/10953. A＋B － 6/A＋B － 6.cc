#include <iostream>
using namespace std;
int main(){
    int T;
    cin>>T;
    
    for (int j=0; j<T; j++){
        string arr;
        cin>>arr;
        
        int mid = arr.find(',');
        string num1 = arr.substr(0, mid);
        string num2 = arr.substr(mid+1);
        
        cout<<stoi(num1)+stoi(num2)<<"\n";
    }
}