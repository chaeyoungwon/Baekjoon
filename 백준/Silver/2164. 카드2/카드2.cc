#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue <int> q;
    int N;
    cin>>N;
    
    for(int i=1;i<=N;i++)
        q.push(i);
    
    while(q.size()>1){
        q.pop(); // 제일 위에 있는 카드를 버린다.
        q.push(q.front()); q.pop(); // 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다. 
    }
    cout<< q.front();
    return 0;
}