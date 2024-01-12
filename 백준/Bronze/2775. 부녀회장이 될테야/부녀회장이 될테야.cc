#include <iostream>
using namespace std;

int get(int K, int N){
    if (N == 1) return 1;
    if (K == 0) return N;
    return (get(K-1, N)+ get(K, N-1));   
}

int main(){
    int T; //Test case 수
    cin>>T;
    for (int i = 0; i<T; i++){
        int K, N; //K층 N호
        cin>>K>>N;
        cout<<get(K,N)<<"\n";
    }
        // 문제 이해 ex 0층의 1호 = 1명;
        // 1층의 3호에 살려면 1+2+3
        // 2층의 3호에 살려면 1 2 3 1 1+2 "1+2+3" 1 "4" 7 : 따옴표들의 합
        // K-1층의 1호~N호의 합 = K-1층의 N호 + K층의 N-1호
        // 왜냐하면 k층의 n-1호는 직전 사람들을 다 합한 값
        
}