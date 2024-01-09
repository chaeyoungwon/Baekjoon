#include <iostream>
#include <stack>
using namespace std;

int main(){
    // cin, cout, endl: 입출력 버퍼를 지우면서 작동
    ios_base::sync_with_stdio(false); // 동기화되어있던 C++의 표준 스트림을 비활성화시켜줌
	cin.tie(NULL); // cin과 cout의 묶음을 풀어줌
    int N, num; 
    int order;
    stack <int> s;
    cin >> N;
    
    for (int i = 0; i<N; i++){
        cin >> order;
        if (order == 1){
            cin >> num;
            s.push(num);
        }
        else if (order == 2){
           if (!s.empty()){
               cout<< s.top() << "\n";
               s.pop();
           }
            else
                cout<< "-1" <<"\n"; 
        }
        else if (order == 3){
            cout<<s.size()<<"\n";
        }
        else if (order == 4){
            if (!s.empty())
                cout<<"0"<<"\n";
            else
                cout<<"1"<<"\n";
        }
        else{
            if (!s.empty())
                cout<< s.top() << "\n";
            else
                cout<< "-1" <<"\n";   
        }
    }
    return 0;
}