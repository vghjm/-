#include <iostream>
#include <utility>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1000;
int N, K;
pii pos[MAX+2];
int visit[MAX+2];

int dist(int s, int e){
    int x = pos[e].first - pos[s].first;
    int y = pos[e].second - pos[s].second;
    return (int)ceil(sqrt(x*x + y*y) / 10);
}

bool BFS(int mid){
    memset(visit, -1, sizeof(visit));
    queue<int> q;
    visit[0] = 0;
    q.push(0);
    int end = N+1;
    
    while(!q.empty()){
        int curr = q.front();
        int k = visit[curr];
        q.pop();
        if(curr == end){
            //printf("%d\n", k);
            if(visit[end]<=K+1) return 1;
            else return 0;
        }
        
        for(int next=1; next<=N+1; next++){
            if(visit[next]!=-1) continue;
            if(dist(curr, next) <= mid){
                q.push(next);
                visit[next] = k + 1;
            }
        }
    }
    
    return 0;
}

int main() {
    scanf("%d%d", &N, &K);
    for(int i=1, x, y; i<=N; i++){
        scanf("%d%d", &x, &y);
        pos[i] = make_pair(x, y);
    }
    pos[0] = make_pair(0, 0);
    pos[N+1] = make_pair(10000, 10000);
    
    int l=0, r=dist(0, N+1);
    //printf("%d\n", r);
    while(l <= r){
        int mid = (l+r)/2;
        if(BFS(mid)) r = mid - 1;
        else l = mid + 1;
    }
    
    printf("%d", l);
    
    
    return 0;
}








