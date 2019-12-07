#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MXV = 1e5;
int V, E, dfsn[MXV], depth, finished[MXV], cnt;
vector<int> adj[MXV];
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
            if(t==curr) break;
        }
        cnt++;
        sort(currSCC.begin(), currSCC.end());
        SCC.push_back(currSCC);
    }
    
    return rtn;
}

int main() {
    scanf("%d%d", &V, &E);
    for(int i=0, a, b; i<E; i++){
        scanf("%d%d", &a, &b);
        adj[a-1].push_back(b-1);
    }
    for(int i=0; i<V; i++){
        if(!dfsn[i]) DFS(i);
    }
    
    sort(SCC.begin(), SCC.end());
    printf("%d\n", cnt);
    for(auto& currSCC : SCC){
        for(int t : currSCC){
            printf("%d ", t+1);
        }
        puts("-1");
    }
    
    return 0;
}





