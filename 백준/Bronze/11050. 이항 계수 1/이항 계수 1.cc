#include <iostream>
using namespace std;

int main(){
    int N, K, mul=1;
    cin >> N >> K;
    for (int i=0; i<K; i++){
        mul *= (N-i);
    }
    for (int i=2; i<=K; i++){
        mul /= i;
    }
    
    cout<<mul;
    return 0;
}