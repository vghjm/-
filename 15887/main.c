#include <stdio.h>

int main(void) {
    int op_N = 0;
    int N;
    int card[1001];
    int op[1000][2];
    
    scanf("%d", &N);
    //printf("N: %d, Start card:", N);
    for(int i=1; i<=N; i++){
        scanf("%d", &card[i]);
        //printf(" %d", card[i]);
    }
    //printf("\n");
    
    for(int i=1; i<=N; i++){
        int k;
        if(card[i]==i) continue;
        for(k=i+1; k<=N; k++){
            if(card[k]==i) break;
        }
        op[op_N][0] = i;
        op[op_N][1] = k;
        op_N++;
        for(int j=0; j<(k-i+1)/2; j++){
            int temp = card[i+j];
            card[i+j] = card[k-j];
            card[k-j] = temp;
        }
    }
    //printf("op array, op_N: %d\n", op_N);
    printf("%d\n", op_N);
    for(int i=0; i<op_N; i++){
        printf("%d %d\n", op[i][0], op[i][1]);
    }
    //printf("end array\n");
    
    //printf("N: %d, End card:", N);
    //for(int i=1; i<=N; i++){
        //printf(" %d", card[i]);
    //}
    //printf("\n");
    
    //printf("%d", (1+2)/2);
    
    return 0;
}