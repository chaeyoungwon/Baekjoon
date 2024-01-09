#include <iostream>
#include <algorithm>
using namespace std;

int n[1000000]; //배열의 범위가 커 전역변수로
int N, M;

void binary_search(int x){
    int left = 0, mid = 0, right = N-1;
    while(left<=right){
        mid = (left+right)/2;
        if(n[mid]==x){
            cout<<1<<"\n";
            return;
        }
        else if (n[mid]>x)
            right = mid -1;
        else
            left = mid +1;
    } cout <<0<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>n[i];
    sort(n, n+N);
    
    cin>>M;
    int x;
    for(int j=0;j<M;j++){
        cin>>x;
        binary_search(x);
    }
    return 0;
}