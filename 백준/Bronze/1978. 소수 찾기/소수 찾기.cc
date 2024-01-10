#include <iostream>
#include <cmath>
using namespace std;

int arr[100];

bool isPrime(int num){
    if(num<2) return false;
    
    int sqr = sqrt(num);
    for (int k=2; k<=sqr; k++){
        if(num%k==0)
            return false;
    }
    return true;
}


int main(){
    int N;
    cin >> N;
    for (int i=0; i<N; i++){
        cin>>arr[i];
    }
    
    int sum=0;
    for (int j=0; j<N; j++){
        if(isPrime(arr[j]))
            sum+=1;
    }
    cout << sum;
    return 0;
    
}