#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin>>N;
    
    for (int i=1; i<N; i++){ //1부터 찾아보기
        
        int sum = i; // 분해한 값들의 합 + 기존 값 = 생성자
        int temp = i; // 기존 i 변동 x 하도록
        
        while(temp!=0){
            sum+=temp%10;
            temp/=10;
        } // 분해합 구하기
        
        if (N == sum){ //분해합이 N과 같다면 i 출력 (가장 작은 생성자를 출력해야하므로 이 경우가 발생하면 바로 return해서 종료)
            cout<<i<<"\n";
            return 0;
        }
        
    }
    cout<<"0"<<"\n"; //생성자가 없을 경우
    return 0;
}