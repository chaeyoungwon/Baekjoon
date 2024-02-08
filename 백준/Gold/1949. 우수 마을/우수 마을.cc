#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 10001
using namespace std;

int N;
int pop[SIZE];
int used[SIZE];
vector<int> road[SIZE], tree[SIZE];
int dp[SIZE][2];

void makeTree(int node, int parent) {
    for (int nextnode : road[node]) {
        if (nextnode != parent) {
            tree[node].push_back(nextnode);
            makeTree(nextnode, node);
        }
    }
}

int dfs(int node, bool selected) {
    if (dp[node][selected])
        return dp[node][selected];

    int ret = 0;
    for (int nextnode : tree[node]) {
        int case_1 = dfs(nextnode, false);
        int case_2 = 0;
        if (!selected)
            case_2 = dfs(nextnode, true);
        ret += max(case_1, case_2);
    }
    if (selected)
        ret += pop[node];
    return dp[node][selected] = ret;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> pop[i];
    for (int j = 0; j < N - 1; j++) {
        int a, d;
        cin >> a >> d;
        road[a].push_back(d);
        road[d].push_back(a);
    }
    used[1] = true;
    makeTree(1, -1);
    int ret = max(dfs(1, 0), dfs(1, 1));
    cout << ret;
    return 0;
}
