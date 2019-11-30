#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void dfs(int m, vector<int> v1, vector<int> v2){
    if(m==0){
        for(int t : v1){
            printf("%d ", t);
        }
        printf("\n");
    }else{
        m--;
        int n = v2.size();
        vector<int> temp;
        //vector<vector<int>> list(n, v2);
        for(int i=0; i<n; i++){
            //vector<int>::iterator iter = list[i].begin();
            //list[i].erase(iter+i);
            v1.push_back(v2[i]);
            dfs(m, v1, v2);
            v1.pop_back();
        }
    }
    
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<int> v1, v2;
    for(int i=1; i<=n; i++){
        v2.push_back(i);
    }
    dfs(m, v1, v2);
    
    return 0;
}