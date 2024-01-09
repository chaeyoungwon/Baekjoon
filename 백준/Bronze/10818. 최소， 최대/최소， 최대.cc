#include <iostream>
using namespace std;

int arr[1000000];

int main(){
    int N;
    cin >> N;
    
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    int min=arr[0];
    int max=arr[0];
    
    for (int j=0; j<N; j++){
        if(min>arr[j])
            min=arr[j];
        
        if(max<arr[j])
            max=arr[j];
    }
    
    cout<<min<<" "<<max;
    return 0;
    
}