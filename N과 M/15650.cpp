#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int n, int m, vector<int> v, queue<int> q){
    if(n==0){
        if(v.size() == m){
            for(int t : v){
                printf("%d ", t);
            }
            printf("\n");
        }
    }else{
        n--;
        int d = q.front();
        q.pop();
        v.push_back(d);
        dfs(n, m, v, q);
        v.pop_back();
        dfs(n, m, v, q);
    }
    
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    queue<int> q;
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    vector<int> v;
    dfs(n, m, v, q);
    
    return 0;
}