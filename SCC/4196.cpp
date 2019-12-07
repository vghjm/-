#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MXN = 1e5;
int T, N, M, dfsn[MXN], depth, finished[MXN], cnt, sccn[MXN];
vector<int> adj[MXN];
stack<int> st;
vector<vector<int>> SCC;

int DFS(int curr){
    dfsn[curr] = ++depth;
    st.push(curr);
    
    int rtn = dfsn[curr];
    for(int next : adj[curr]){
        if(!dfsn[next]) rtn = min(rtn, DFS(next));
        else if(!finished[next]) rtn = min(rtn, dfsn[next]);
    }
    
    if(rtn==dfsn[curr]){
        vector<int> currSCC;
        while(1){
            int t = st.top();
            st.pop();
            currSCC.push_back(t);
            finished[t] = true;
            sccn[t] = cnt;
            if(t==curr) break;
        }
        cnt++;
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
    }
    
    return rtn;
}

void init(){
    depth = cnt = 0;
    SCC.clear();
    
    for(int i=0; i<N; i++){
        adj[i].clear();
    }
    memset(dfsn, 0, sizeof(dfsn));
    memset(sccn, 0, sizeof(sccn));
    memset(finished, 0, sizeof(finished));
}


int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);
        init();
        for(int i=0, x, y; i<M; i++){
            scanf("%d%d", &x, &y);
            adj[x-1].push_back(y-1);
        }
        for(int i=0; i<N; i++){
            if(!dfsn[i]) DFS(i);
        }
        
        int s_out[MXN] = {0};
        for(int i=0; i<N; i++){
            for(int j : adj[i]){
                if(sccn[i] != sccn[j]) s_out[sccn[j]]++;
            }
        }
        
        int ans = 0;
        for(int i=0; i<cnt; i++){
            if(s_out[i] == 0) ans++;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}





