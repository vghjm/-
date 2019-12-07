#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 1e5+1;
int N, M, depth, SN, dfsn[MAX], finished[MAX], sn[MAX];
vector<int> adj[MAX];
vector<vector<int>> SCC;
stack<int> st;

int sccStart;
int sccCash[MAX];
bool sccHasRest[MAX];
int sccIn[MAX];
vector<int> sccAdj[MAX];
    
queue<int> Q;
int sccMax[MAX];
bool arrivable[MAX];
    
int DFS(int curr){
    dfsn[curr] = ++depth;
    st.push(curr);
    
    int result = dfsn[curr];
    for(int next : adj[curr]){
        if(dfsn[next]==0) result = min(result, DFS(next));
        else if(!finished[next]) result = min(result, dfsn[next]);
    }
    
    if(result==dfsn[curr]){
        vector<int> currSCC;
        while(1){
            int t = st.top();
            st.pop();
            finished[t] = true;
            currSCC.push_back(t);
            sn[t] = SN;
            if(t==curr) break;
        }
        SN++;
        SCC.push_back(currSCC);
    }
    
    return result;
}

int main() {
    scanf("%d%d", &N, &M);
    for(int i=0, s, e; i<M; i++){
        scanf("%d%d", &s, &e);
        adj[s-1].push_back(e-1);
    }
    for(int i=0; i<N; i++){
        if(dfsn[i]==0) DFS(i);
    }
    
    int S, P, cash[MAX];
    bool hasRest[MAX]={0};
    for(int i=0, c; i<N; i++){
        scanf("%d", cash+i);
    }
    scanf("%d%d", &S, &P);
    S--;
    for(int i=0, p; i<P; i++){
        scanf("%d", &p);
        hasRest[p-1] = true;
    }
    
    
    for(int i=0; i<N; i++){
        int si = sn[i];
        sccCash[si] += cash[i];
        if(i==S) sccStart = si;
        if(hasRest[i]) sccHasRest[si] = true;
        
        for(int j : adj[i]){
            int sj = sn[j];
            if(si == sj) continue;
            sccAdj[si].push_back(sj);
            sccIn[sj]++;
        }
    }
    
    
    for(int i=0; i<SN; i++){
        sccMax[i] = sccCash[i];
        if(i==sccStart) arrivable[i] = true;
        if(sccIn[i]==0) Q.push(i);
    }
    
    while(!Q.empty()){
        int curr = Q.front();
        Q.pop();
        for(int next : sccAdj[curr]){
            if(arrivable[curr]){
                sccMax[next] = max(sccMax[next], sccMax[curr] + sccCash[next]);
                arrivable[next] = true;
            }
            if(--sccIn[next]==0) Q.push(next);
        }
    }
    
    int result = 0;
    for(int i=0; i<SN; i++)
        if(sccHasRest[i] && arrivable[i]) result = max(result, sccMax[i]);
    printf("%d\n", result);
    
    
    
    
    return 0;
}



