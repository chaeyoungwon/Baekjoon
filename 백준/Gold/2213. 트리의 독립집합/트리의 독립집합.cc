#include<bits/stdc++.h>
#define N 10001
using namespace std;
 
vector <int> an, Gr[N];
int n, r, c[N], dp[N][2];
 
int f(int p, int q, int o)
{
    int& t(dp[p][o]);
    if (!~t)
    {
        t = o ? c[p] : 0;
        for (int i : Gr[p])
            if (i ^ q)
                t += max(f(i, p, 0), o ? 0 : f(i, p, 1));
    }
    return t;
}
void Solve(int p, int q, int o)
{
    if (o) an.push_back(p);
    for (int i : Gr[p])
        if (i ^ q)
            Solve(i, p, o ? 0 : dp[i][1] > dp[i][0]);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp); cin >> n;
    for (int i(1); i <= n; cin >> c[i++]);
    for (int i, j, o{}; ++o < n;)
        cin >> i >> j, Gr[i].push_back(j), Gr[j].push_back(i);
    cout << max(f(1, 0, 0), f(1, 0, 1)) << '\n';
 
    Solve(1, 0, dp[1][1] > dp[1][0]);
    sort(an.begin(), an.end());
 
    for (int i : an) cout << i << ' ';
}