#include <iostream>
#include <vector>
using namespace std;

#define SIZE 5000001

vector<int> Prime(SIZE, 0);

void eratosthenes(int N) {
    fill(Prime.begin(), Prime.begin() + (N + 1), 0); 
    for (int i = 2; i <= N; ++i) { 
        if (!Prime[i]) {
            for (int j = i; j <= N; j += i) { 
                if (Prime[j] == 0)
                    Prime[j] = i;
            }
        }
    }
}

void Factorization(int num){
    while (num > 1){
        cout << Prime[num] << ' ';
        num /= Prime[num];
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;
    eratosthenes(SIZE);

    for (int T = 0; T < t; T++){
        int num;
        cin >> num;
        Factorization(num);
    }

    return 0;
}
