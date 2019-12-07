#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 28
using namespace std;
const int MXN = 1e5;
int n, m, dfsn[MXN], cnt, SN;
vector<int> friend_list[MXN][MOD];
bool finished[MXN];
stack<int> S;
vector<vector<int>*> SCC;

bool cmp(vector<int> *a, vector<int> *b){
    return a->size() < b->size();
}

int DFS(int curr){
    dfsn[curr] = ++cnt;
    S.push(curr);
    
    int result = dfsn[curr];
    for(int next=0; next<n; next++){
        vector<int> &no_same_room = friend_list[curr][next%MOD];
        if(next!=curr && find(no_same_room.begin(), no_same_room.end(), next)==no_same_room.end()){
            if(dfsn[next]==0) result = min(result, DFS(next));
            else if(!finished[next]) result = min(result, dfsn[next]);
        }
    }
    
    if(result == dfsn[curr]){
        vector<int> *currSCC = new vector<int>;
        while(1){
            int t = S.top();
            S.pop();
            currSCC->push_back(t);
            finished[t] = true;
            if(t == curr) break;
        }
        SCC.push_back(currSCC);
        SN++;
    }
    return result;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i=0, u, v; i<m; i++){
        scanf("%d%d", &u, &v);
        friend_list[u-1][(v-1)%MOD].push_back(v-1);
        friend_list[v-1][(u-1)%MOD].push_back(u-1);
    }
    /*
    for(int i=0; i<n; i++){
        sort(friend_list[i].begin(), friend_list[i].end());
    }
    */
    for(int i=0; i<n; i++){
        if(dfsn[i]==0) DFS(i);
    }
    
    sort(SCC.begin(), SCC.end(), cmp);
    printf("%d\n", SN);
    for(auto& currSCC : SCC){
        printf("%zu ", currSCC->size());
    }
    
    return 0;
}









