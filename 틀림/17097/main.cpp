#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_N 500002

int print(int n, int *output){
    int max=0;
    int level=0;
    int k;
    int i;
    for(i=n+1; i>0; i--){
        level+=output[i];
        if(level>=i-1){
            printf("%d ", i-1);
            break;
        }
    }
    //printf("%d ", max);
    return i-1; 
}
int main() {
    int N, A, B, Q, P, L, R;
    pair<int, int> input[MAX_N];
    int output[MAX_N];
    int pre;
    
    //init();
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>A>>B;
        input[i] = make_pair(A, B);
        output[A]--;
        output[B+1]++;
    }
    
    pre = print(N, output);
    
    cin>>Q;
    for(int i=0; i<Q; i++){
        int changed = 0;
        cin>>P>>L>>R;
        int l = input[P].first;
        int r = input[P].second;
        input[P].first = L;
        input[P].second = R;
        
        output[l]++;
        output[r+1]--;
        output[L]--;
        output[R+1]++;
        if(pre <= r || pre <=R){
            pre = print(N, output);
        }else {
            printf("%d ", pre);
        }
        
    }
    
    return 0;
}