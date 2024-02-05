#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <cstring>

inline int id(int i, int j){ return i*555+j; }
int n, m;
char arr[555][555];
vector <pair<int,int>> v[303030];
int dist[303030];

void add(int s, int e, int x){
    v[s].emplace_back(e,x);
    v[e].emplace_back(s,x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin>>arr[i][j];
        }
    }
    for (int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(arr[i][j] == '/'){
                add(id(i-1, j-1), id(i, j), 1);
                add(id(i-1, j), id(i, j-1), 0);
            }
            else{
                add(id(i-1, j-1), id(i, j), 0);
                add(id(i-1, j), id(i, j-1), 1);
            }
        }
    }
    
    memset(dist, 0x3f, sizeof dist);
    priority_queue<pair<int,int>> pq; 
    pq.emplace(0, id(0, 0)); 
    dist[id(0, 0)] = 0;
	while(pq.size()){
		int now = pq.top().second, cst = -pq.top().first; 
        pq.pop();
		if(cst > dist[now]) continue;
		for(auto i : v[now]) if(dist[i.first] > cst + i.second){
			dist[i.first] = cst + i.second; pq.emplace(-dist[i.first], i.first);
		}
	}
	int res = dist[id(n, m)];
	if(res < 1e9) cout << res;
    else cout<<"NO SOLUTION";
    
}