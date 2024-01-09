#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N, num; 
    string str;
    stack <int> s;
    cin >> N;
    
    for (int i = 0; i<N; i++){
        cin >> str;
        if (str =="push"){
            cin >> num;
            s.push(num);
        }
        else if (str == "pop"){
           if (!s.empty()){
               cout<< s.top() << endl;
               s.pop();
           }
            else
                cout<< "-1" <<endl; 
        }
        else if (str == "top"){
            if (!s.empty())
                cout<< s.top() << endl;
            else
                cout<< "-1" <<endl;
        }
        else if (str == "empty"){
            if (!s.empty())
                cout<<"0"<<endl;
            else
                cout<<"1"<<endl;
        }
        else
            cout<<s.size()<<endl;
    }
    return 0;
}