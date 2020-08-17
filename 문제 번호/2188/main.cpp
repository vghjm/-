#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX_V = 410;
const int INF = 9999999;

struct Edge{
    int to, c, f;
    Edge *dual;
    Edge(): Edge(-1, 0) {}
    Edge(int to1, int c1): to(to1), c(c1), f(0), dual(nullptr){}
    int spare(){
        return c - f;
    }
    void addFlow(int flow){
        f += flow;
        dual->f -=flow;
    }
};

int main() {
    int N, M;
    vector<Edge*> adj[MAX_V];
    int S=401, E=402;
    scanf("%d %d", &N, &M);
    for(int i=201; i<=N+200; i++){
        Edge *e1 = new Edge(i, 1);
        Edge *e2 = new Edge(S, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[i].push_back(e2);
        adj[S].push_back(e1);
        int s;
        scanf("%d", &s);
        for(int j=1; j<=s; j++){
            int si;
            scanf("%d", &si);
            Edge *e11 = new Edge(si, 1);
            Edge *e22 = new Edge(i, 0);
            e11->dual = e22;
            e22->dual = e11;
            adj[i].push_back(e11);
            adj[si].push_back(e22);
        }
    }
    for(int i=1; i<=M; i++){
        Edge *e1 = new Edge(E, 1);
        Edge *e2 = new Edge(i, 0);
        e1->dual = e2;
        e2->dual = e1;
        adj[E].push_back(e2);
        adj[i].push_back(e1);
    }
    int total=0;
    while(1){
        int prev[MAX_V];
        fill(prev, prev+MAX_V, -1);
        queue<int> Q;
        Q.push(S);
        Edge *path[MAX_V] = {0};
        
        while(!Q.empty()&&prev[E]==-1){
            int curr = Q.front();
            Q.pop();
            for(Edge *e : adj[curr]){
                int next = e->to;
                if(e->spare()>0&&prev[next]==-1){
                    Q.push(next);
                    prev[next] = curr;
                    path[next] = e;
                    if(next==E) break;
                }
            }
        }
        if(prev[E]==-1) break;
        
        int flow = INF;
        for(int i=E; i!=S; i=prev[i])
            flow = min(flow, path[i]->spare());
        for(int i=E; i!=S; i=prev[i])
            path[i]->addFlow(flow);
        total+=flow;
    }
    
    printf("%d\n", total);
    
    
    
    
    return 0;
}

















