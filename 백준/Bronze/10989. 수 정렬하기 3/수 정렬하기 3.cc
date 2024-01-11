#include <iostream>
#include <algorithm>
using namespace std;

// 입력 받는 수가 10000이하 자연수이므로 이를 인덱스로 보자
// 단순히 배열 생성 후 sort => 메모리 초과
// 해당 문제는 메모리 제한이 8mb

int arr[10001]={0,}; // 배열 원소가 해당 인덱스에 대한 카운트 개념이 됨
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++){
        int num;
        cin>>num;
        arr[num]+=1;
    }
    
    for (int i=1; i<=10000; i++){
        for (int j=0; j<arr[i]; j++)
            cout<<i<<"\n";
    }
    
    return 0;
}