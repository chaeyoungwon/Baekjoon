#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_SIZE = 2000;
const int MAX_EDGES = MAX_SIZE * (MAX_SIZE - 1)/2 + 1;
vector<pair<int, int>> arr(MAX_EDGES);
vector<long long> fenwick(MAX_SIZE + 1);

void add(int pos, int val){
    while(pos<=MAX_SIZE){
        fenwick[pos] +=val;
        pos += (pos & -pos);
    }
}

long long sum(int pos){
    long long r = 0;
    while(pos){
        r+=fenwick[pos];
        pos &= (pos-1);
    }return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    for (int i=0; i < M; i++){
        cin >> arr[i].first>> arr[i].second;
    }
    
    sort(arr.begin(), arr.begin()+M);
    long long l = 0;
    for (int i=M-1;i>=0;--i){
        l += sum(arr[i].second -1);
        add(arr[i].second, 1);
    }cout << l;
}