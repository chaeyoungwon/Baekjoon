#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N, num; string str;
    deque <int> d;
    cin >> N;
    
    for (int i = 0; i<N; i++){
        cin >> str;
        if (str =="push_front"){
            cin >> num;
            d.push_front(num);
        }
        else if (str =="push_back"){
            cin >> num;
            d.push_back(num);
        }
        else if (str == "pop_front"){
           if (!d.empty()){
               cout<< d.front() << "\n";
               d.pop_front();
           }
            else
                cout<< "-1" <<"\n"; 
        }
        else if (str == "pop_back"){
           if (!d.empty()){
               cout<< d.back() << "\n";
               d.pop_back();
           }
            else
                cout<< "-1" <<"\n"; 
        }
        else if (str == "front"){
            if (!d.empty())
                cout<< d.front() << "\n";
            else
                cout<< "-1" <<"\n";
        }
        else if (str == "back"){
            if (!d.empty())
                cout<< d.back() << "\n";
            else
                cout<< "-1" <<"\n";
        }
        else if (str == "empty"){
            if (!d.empty())
                cout<<"0"<<"\n";
            else
                cout<<"1"<<"\n";
        }
        else
            cout<<d.size()<<"\n";
    }
    return 0;
}