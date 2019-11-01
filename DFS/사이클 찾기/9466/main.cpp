#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int partner[100001], state[100001];
int ans, unique_number;

void make_team(int s){
    state[s] = unique_number;
    while(1){
        int _next = partner[s];
        if(state[_next] == 0){
            state[_next] = unique_number;
            s = _next;
        }else if(state[_next] == unique_number){
            int end = _next, start = _next;
            ans--;
            while(1){
                if(partner[start]!=end){
                    start = partner[start];
                    ans--;
                }else{
                    break;
                }
            }
            break;
        }else{
            break;
        }
    }
}

int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        fill(state, state+N+1, 0);
        for(int i=1; i<=N; i++){
            scanf("%d", &partner[i]);
        }
        ans = N; unique_number=1;
        for(int i=1; i<=N; i++){
            if(!state[i]){
                make_team(i);
                unique_number++;
            }
        }
        
        printf("%d\n", ans);
        
    }
    return 0;
}