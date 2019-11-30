#include <iostream>
#include <vector>
using namespace std;

void dfs(int m, vector<int> p, vector<int> v){
    if(m==0){
        for(int t : p){
            printf("%d ", t);
        }
        printf("\n");
    }else{
        m--;
        int n = v.size();
        vector<int> temp;
        vector<vector<int>> list(n, temp);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(j!=i) list[j].push_back(v[i]);
            }
        }
        for(int i=0; i<n; i++){
            p.push_back(v[i]);
            dfs(m, p, list[i]);
            p.pop_back();
        }
    }
    
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    vector<int> temp;
    dfs(m, temp, v);
    
    return 0;
}