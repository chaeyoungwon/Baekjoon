#include <iostream>
#include <queue>
#include <algorithm>
#define SIZE 500001
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, A, B, result = 0;
    bool visited[SIZE][2]={};
    cin>>T>>A>>B;
    
    queue<pair<int, bool>> q;
    q.push({0,0});
    visited[0][0]=1;
    
    while(!q.empty()){
        int hungry = q.front().first;
        bool water = q.front().second;
        q.pop();
        
        result = max(result, hungry);
        if(hungry+A <= T && !visited[hungry+A][water]){
            q.push({hungry+A, water});
            visited[hungry+A][water]=1;
        }
        if(hungry+B <= T && !visited[hungry+B][water]){
            q.push({hungry+B, water});
            visited[hungry+B][water]=1;
        }
        if(!water && !visited[hungry/2][!water]){
            q.push({hungry/2, !water});
            visited[hungry/2][!water]=1;
        }
        
    }cout<<result<<"\n";
    return 0;
    
}