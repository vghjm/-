#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define MAX_V 1001

struct Edge{
    int to;
    Edge(int to1): to(to1) {}
};

bool cmp(const Edge *e, const Edge *f){
    return e->to < f->to;
}

int main() {
    vector<Edge*> node[MAX_V];
    int prev[MAX_V];
    int ans[MAX_V];
    int N, M, S;
    scanf("%d%d%d", &N, &M, &S);
    for(int i=0; i<M; i++){
        int s, e;
        scanf("%d%d", &s, &e);
        node[s].push_back(new Edge(e));
        node[e].push_back(new Edge(s));
    }
    for(int i=1; i<=N; i++){
        sort(node[i].begin(), node[i].end(), cmp);
    }
    /*
    for(Edge* e:node[2])
        printf("%3d", e->to);
    printf("\n---------\n");
    */
    stack<int> st;
    fill(prev, prev+MAX_V+1, 0);
    st.push(S);
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        if(node[curr].size()){
            for(vector<Edge*>::iterator iter = node[curr].end()-1; iter>=node[curr].begin(); iter--){
                int next = (*iter)->to;
                //printf("    > %d\n", next);
                if(!prev[next]){
                    st.push(next);
                }
            }
        }
        if(!prev[curr]){
            prev[curr] = 1;
            printf("%d ", curr);
        }
    }
    printf("\n");
    
    queue<int> q;
    fill(prev, prev+MAX_V+1, 0);
    q.push(S);
    while(!q.empty()){  
        int curr = q.front();
        q.pop();
        if(node[curr].size()){
            for(Edge *e : node[curr]){
                int next = e->to;
                if(!prev[next]){
                    q.push(next);
                }
            }
        }
        if(!prev[curr]){
            prev[curr] = 1;
            printf("%d ", curr);
        }
    }
    
    return 0;
}

















