#include <stdio.h>
#define max(a,b) a>b ? a:b

int dp[1000];
int a[1000];

int main(void) {
    int N;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++)
        scanf("%d", &a[i]);
        
    for(int i=0; i<N; i++){
        dp[i]=a[i];
        for(int j=0; j<i; j++){
            if(a[j]>a[i] && dp[j]+a[i]>dp[i]){
                dp[i] = dp[j]+a[i];
            }
        }
    }
    
    int ans=0;
    for(int i=0; i<N; i++){
        ans = max(ans, dp[i]);
    }
    printf("%d", ans);
    
    return 0;
}