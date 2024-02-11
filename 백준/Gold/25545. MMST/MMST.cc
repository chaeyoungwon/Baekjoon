#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef long long ll;
vector<int> maxst,minst,randst;
vector<tuple<int,int,int,int>> graph;
int parents[200200],n,m;
bool cycle;
int FIND(int x){
    if(parents[x] == x) return x;
    return parents[x] = FIND(parents[x]);
}
void Kruskal(vector<int> &s){
    for(auto [w,u,v,i] : graph){
        u=FIND(u), v=FIND(v);
        if(u != v){
            parents[u] = v;
            s.push_back(i);
        }
        else cycle = 1;
    }
}
void make_minst(){
    for(int i=0; i<=n; i++)
        parents[i] = i;
    sort(graph.begin(),graph.end());
    Kruskal(minst);
}
void make_maxst(){
    for(int i=0; i<=n; i++)
        parents[i] = i;
    sort(graph.rbegin(),graph.rend());
    Kruskal(maxst);
}
void make_randst(){
    for(int i=0; i<=n; i++)
        parents[i] = i;
    random_shuffle(graph.begin(),graph.end());
    Kruskal(randst);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b,c; cin>>a>>b>>c;
        graph.push_back({c,a,b,i});
    }
    make_maxst(); sort(maxst.begin(),maxst.end());
    make_minst(); sort(minst.begin(),minst.end());
    if(!cycle) cout << "NO";
    else{
        cout << "YES\n";
        while(1){
            randst.clear();
            make_randst(); sort(randst.begin(),randst.end());
            if(minst != randst && maxst != randst){
                for(auto i : randst)
                    cout << i << ' ';
                break;
            }
        }
    }
    return 0;
}