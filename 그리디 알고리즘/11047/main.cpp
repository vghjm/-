#include <iostream>
using namespace std;

int N, K;
int coin[10];

int main() {
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++){
        scanf("%d", &coin[i]);
    }
    
    int c = N - 1;
    int ans = 0;
    while(1){
        int temp = K-coin[c];
        if(temp>0){
            ans++;
            K-=coin[c];
        }else if(temp<0){
            c--;
        }else{
            ans++;
            break;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}