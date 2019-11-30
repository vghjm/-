#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    stack<int> b;
    vector<vector<int>> f;
    vector<int> temp;
    temp.resize(1);
    for(int i=n; i>0; i--){
        int op;
        scanf("%d", &op);
        switch(op){
            case 1: 
                temp[0] = i;
                f.push_back(temp);
                temp.clear();
                //temp.resize(1);
            case 2: temp.push_back(i); break;
            case 3: b.push(i); break;
        }
    }
    
    for(vector<int> v : f){
        for(int t : v){
            printf("%d ", t);
        }
        //printf("\n");
    }
    while(!b.empty()){
        int t = b.top();
        b.pop();
        printf("%d ", t);
    }
    
    
    return 0;
}