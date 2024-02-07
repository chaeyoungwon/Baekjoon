#include <iostream>
using namespace std;

long long exEuclid(long long a, long long b, long long &s, long long &t) {
    if (b == 0) {
        s = 1; 
        t = 0;
        return a;
    }
    long long gcd = exEuclid(b, a % b, s, t);
    long long temp = t;
    t = s - (a / b) * t;
    s = temp;

    if (s <= 0) {
        s += b;
        t -= a;
    }
    return gcd;
}

int main() {
    long long n, a;
    cin >> n >> a;
    long long c, k;
    long long g = exEuclid(a, n, c, k);
    if (g != 1)
        cout << n - a << ' ' << -1;
    else
        cout << n - a << ' ' << c;
    return 0;
}
