#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> arr, node;

int init(int n, int l, int r){
    if(l==r) return node[n]=arr[l];
    int mid = (l+r) / 2;
    const int lval = init(n*2, l, mid);
    const int rval = init(n*2+1,mid+1, r);
    return node[n]=min(lval, rval);
}

int update(int n, int s, int e, int i, int x){
    if (e < i || i < s) return node[n];
    if (i <= s && e <= i) return node[n] = x; 
    const int m = (s + e) / 2;
    const int lval = update(2*n, s, m, i, x); 
    const int rval = update(2*n+1, m+1, e, i, x); 
    return node[n] = min(lval, rval);
}

int query(int n, int s, int e, int qs, int qe) { 
    if (e < qs || qe < s) return INT_MAX;
    if (qs <= s && e <= qe) return node[n]; 
    const int m = (s + e) / 2;
    const int lval = query(2*n, s, m, qs, qe);
    const int rval = query(2*n+1, m+1, e, qs, qe); 
    return min(lval, rval);
}
                           
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N;
    arr.resize(N+1);
    node.resize(4*(N+1));
    
    for (int i=1; i<=N; i++){
        cin>>arr[i];
    }
    init(1,1,N);
    
    cin >> M;
    
    while(M--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            update(1, 1, N, b, c);
            arr[b]=c;
        } 
        else cout<<query(1,1,N,b,c)<<'\n';
    }
    return 0;
}             