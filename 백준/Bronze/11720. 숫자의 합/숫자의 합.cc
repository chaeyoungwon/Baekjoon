#include <iostream>
using namespace std;

int main(){
    int n;
    int sum=0;
    cin>>n;
    char arr[n];
    cin>>arr;
    for(int i=0;i<n;i++){
        sum+=arr[i]-'0';
    }
    cout<<sum;
}