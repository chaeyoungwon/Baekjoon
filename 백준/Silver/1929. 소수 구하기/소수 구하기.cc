#include <iostream>
#include <cmath>
using namespace std;

int arr[1000000];

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
    int M, N;
    cin >> M >> N;
    for (int i=0; i<N-M+1; i++){
        arr[i]=M+i;
    }
    for (int j=0; j<N-M+1; j++){
        if(isPrime(arr[j]))
            cout<<arr[j]<<"\n";
    }
    return 0;

}