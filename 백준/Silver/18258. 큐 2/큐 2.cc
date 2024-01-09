#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, num; string str;
    queue <int> q;
    cin >> N;
    
    for (int i = 0; i<N; i++){
        cin >> str;
        if (str =="push"){
            cin >> num;
            q.push(num);
        }
        else if (str == "pop"){
           if (!q.empty()){
               cout<< q.front() << "\n";
               q.pop();
           }
            else
                cout<< "-1" <<"\n"; 
        }
        else if (str == "front"){
            if (!q.empty())
                cout<< q.front() << "\n";
            else
                cout<< "-1" <<"\n";
        }
        else if (str == "back"){
            if (!q.empty())
                cout<< q.back() << "\n";
            else
                cout<< "-1" <<"\n";
        }
        else if (str == "empty"){
            if (!q.empty())
                cout<<"0"<<"\n";
            else
                cout<<"1"<<"\n";
        }
        else
            cout<<q.size()<<"\n";
    }
    return 0;
}