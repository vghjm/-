#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#define mod 1000000007
using namespace std;
const int MXN = 3e5;
int n, k, p, ind[2][MXN], r[2][MXN], s, od[MXN];
vector<int> adj[2][MXN];
priority_queue<int> pq;
void f(int t) {
    for (int i = 0; i < k; i++) if (!ind[t][i]) pq.push(-i);
    int i = 0;
    while (!pq.empty()) {
        int h = -pq.top();
        pq.pop();
        r[t][h] = od[i++];
        for (auto it : adj[t][h]) if (!--ind[t][it]) pq.push(-it);
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 0, x, y; i < p; i++) {
        scanf("%d%d", &x, &y);
        adj[0][x].push_back(y);
        adj[1][y].push_back(x);
        ind[0][y]++;
        ind[1][x]++;
    }
    for (int i = 0; i < k; i++) od[i] = k - 1 - i;
    f(0);
    for (int i = 0; i < k; i++) od[i] = n - k + i;
    f(1);
    for (int i = k; i--;) s = ((long long)s*n + r[1][i] - r[0][i] + mod ) % mod;
    printf("%d", s);
    return 0;
}