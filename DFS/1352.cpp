#include <iostream>
#include <stack>
using namespace std;

int arr[10000];
stack<int> st;

int dfs(int pos, int ch, int r){
    if(r<pos) return -1;
    if(r==pos){
        arr[pos] = ch;
        for(int i=1; i<pos; i++){
            st.push(ch);
        }
        
        return pos+1;
    }
    for(int i=pos; i>0; i--){
        int rtn = dfs(pos+i, ch+1, r-pos);
        if(rtn!=-1){
            arr[pos] = ch;
            for(int j=1; j<pos; j++){
                st.push(ch);
            }
            return rtn;
        }
    }
    
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);
    int pos = dfs(1, 0, n);
    if(pos!=-1){
        pos=1;
        while(!st.empty()){
            int t = st.top();
            st.pop();
            while(arr[++pos]!=0);
            arr[pos] = t;
        }
        for(int i=1; i<=n; i++){
            printf("%c", arr[i]+'A');
        }
    }else{
        printf("-1");
    }
    return 0;
}