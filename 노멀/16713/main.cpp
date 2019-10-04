#include <iostream>
using namespace std;

int main() {
    int N, Q;
    scanf("%d%d",&N,&Q);
    int *arr = new int[N+1];
    int a;
    arr[0] = 0;
    for(int i=1; i<=N; i++){
        scanf("%d", &a);
        arr[i] = arr[i-1]^a;
    }
    int s, e;
    int ans = 0;
    while(Q--){
        scanf("%d%d", &s, &e);
        ans^=arr[s-1]^arr[e];
    }
    printf("%d", ans);
    
    return 0;
}