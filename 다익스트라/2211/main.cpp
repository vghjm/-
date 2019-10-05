#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
 
#define INF 987654321
 
using namespace std;
 
typedef pair<int, int> pii;
//first dist, second number
vector<pii> v[1001];
int dist[1001];
int parent[1001];
 
int main(){
    int N, M;
    scanf("%d%d", &N, &M);
 
    for (int i = 0; i < M; i++){
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
 
        v[A].push_back(pii(B, C));
        v[B].push_back(pii(A, C));
    }
 
    fill(dist, dist + 1001, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0,1));
    dist[1] = 0;
 
    while (!pq.empty()){
        int curr_id = pq.top().second;
        int curr_d = pq.top().first;
        
        pq.pop();
 
        if (dist[curr_id] < curr_d)
            continue;
            
        for(pii p: v[curr_id]){
            int next_id = p.first;
            int next_d = p.second + curr_d;
 
            if (dist[next_id] > next_d){
                dist[next_id] = next_d;
                pq.push(pii(next_d, next_id));
                parent[next_id] = curr_id;
            }
        }
    }
 
    printf("%d\n", N-1);
 
    for (int i=2; i<=N; i++)
        printf("%d %d\n", parent[i], i);
    
    return 0;
}

