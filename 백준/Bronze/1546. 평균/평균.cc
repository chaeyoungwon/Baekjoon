#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    double arr[1000]={0};
    for (int i=0; i<N; i++){
        int score;
        cin >> score;
        arr[i]= score;
    }
    
    double max = arr[0];
    for (int j=0;j<N;j++){
        if (max < arr[j])
            max = arr[j];
    }
    
    double sum=0;
    for (int k=0;k<N;k++){
        arr[k] = arr[k]/max*100;
        sum += arr[k];
    }
    
    cout<<sum/N;
    return 0;
}