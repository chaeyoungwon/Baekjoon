#include <iostream>
#include <stack>
using namespace std;

int main(){
    int K, num;
    stack <int> s;
    
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>num;
        if(num!=0)
            s.push(num);
        else
            s.pop();
    }
    int sum=0;
    for(int j=0;j<K;j++){
        if(!s.empty()){
            sum+=s.top();
            s.pop();
        }
    }
    cout<<sum;
    return 0;

}
