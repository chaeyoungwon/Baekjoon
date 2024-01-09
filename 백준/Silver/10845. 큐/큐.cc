#include <iostream>
#include <queue>
using namespace std;

int main(){
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
               cout<< q.front() << endl;
               q.pop();
           }
            else
                cout<< "-1" <<endl; 
        }
        else if (str == "front"){
            if (!q.empty())
                cout<< q.front() << endl;
            else
                cout<< "-1" <<endl;
        }
        else if (str == "back"){
            if (!q.empty())
                cout<< q.back() << endl;
            else
                cout<< "-1" <<endl;
        }
        else if (str == "empty"){
            if (!q.empty())
                cout<<"0"<<endl;
            else
                cout<<"1"<<endl;
        }
        else
            cout<<q.size()<<endl;
    }
    return 0;
}