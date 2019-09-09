#include <stdio.h>

long D[2][10001];

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    
    D[0][0] = 1; D[1][0] = 1;
    int d_count = 0;
    while(n--){
        int coin;
        scanf("%d", &coin);
        for(int i=1; i<=k; i++){
            if(i>=coin){
                D[!d_count][i] = D[d_count][i] + D[!d_count][i-coin];
            }else {
                D[!d_count][i] = D[d_count][i];
            }
        }
        d_count = !d_count;
    }
    printf("%d", D[d_count][k]);
    
    return 0;
}