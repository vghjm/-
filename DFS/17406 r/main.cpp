#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;
 
struct ROT {
    int y, x, s;
}arr[10];
 
bool visit[10];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, M, K, dab = INF;
 
void rotate(const ROT rot, vector<vector<int> > &map) {
    const int s = rot.s;
    const int y = rot.y - 1;
    const int x = rot.x - 1;
    for (int k = 1; k <= s; k++) {
        int x_ = x - k;
        int y_ = y - k;
        int tmp = map[y_][x_];
        int dir = 0;
        int input;
        do {
            int nx = x_ + dx[dir];
            int ny = y_ + dy[dir];
            input = tmp;
            tmp = map[ny][nx];
            map[ny][nx] = input;
            x_ = nx; y_ = ny;
            if (x_ == x + k && y_ == y - k) dir = 1;
            if (x_ == x + k && y_ == y + k) dir = 2;
            if (x_ == x - k && y_ == y + k) dir = 3;
        } while (x_ != x - k || y_ != y - k);
    }
}
 
void dfs(int d, int oper, vector<vector<int> > map) {
    if (oper != -1) rotate(arr[oper], map);
    if (d == K) {
        for (int i = 0; i < N; i++) {
            int tmp = 0;
            for (int j = 0; j < M; j++)
                tmp += map[i][j];
            dab = tmp > dab ? dab : tmp;
        }
        return;
    }
    for (int i = 0; i < K; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        dfs(d + 1, i, map);
        visit[i] = false;
    }
}
 
int main(void) {
    cin >> N >> M >> K;
    vector<vector<int> > map(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];
    for (int i = 0; i < K; i++)
        cin >> arr[i].y >> arr[i].x >> arr[i].s;
    dfs(0, -1, map);
    cout << dab << endl;
    return 0;
}
