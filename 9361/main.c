#include <stdio.h>
#include <limits.h>
#include <math.h>

long arr[31];
int N;
int order[31];

int calc(){
    int size=1;
    for(int i=1; i<=N; i++){
        long min=LONG_MAX;
        int pos=0;
        for(int j=1; j<=N; j++){
            if(arr[j] < min && order[j]==0){
                min = arr[j];
                pos = j;
            }    
        }
        order[pos] = size;
        size++;
    }
    /*
    printf("order\n>");
    for(int i=1; i<=N; i++){
        printf(" %d ", order[i]);
    }
    printf("\n");
    */
    int sum=0;
    for(int i=1; i<=N; i++){
        sum += abs(order[i] - i);
        //printf("val: %d, sum: %d\n", abs(order[i] - i), sum);
    }
    
    return sum / 2;
}

void init(){
    for(int i=1; i<=N; i++){
        order[i] = 0;
    }
}
int main(void) {
    int T;
    scanf("%d", &T);
    
    init();
    for(int i=1; i<=T; i++){
        scanf("%d", &N);
        init();
        for(int j=1; j<=N; j++){
            scanf("%d", &arr[j]);
        }
        int ans = calc();
        printf("Case #%d: %d\n", i, ans);
    }
    return 0;
}