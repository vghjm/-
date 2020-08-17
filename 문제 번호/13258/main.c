#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    int me, you=0;
    scanf("%d", &me);
    for(int i=1; i<N; i++){
        int temp;
        scanf("%d", &temp);
        if(temp>0) you+=temp;
    }
    int J, C;
    scanf("%d %d", &J, &C);
    
    printf("%.18lf",me+(me / (double)(me+you)) * J * C);
    
    return 0;
}