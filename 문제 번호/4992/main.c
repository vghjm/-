#include <stdio.h>

int N;
int R;
int arr[51];

void init(int size){
    for(int i=1; i<=size; i++){
        arr[i] = size - i + 1;
    }
}

void hanafuda(int p, int c){
    int temp[60];
    for(int i=0; i<c; i++){
        temp[i] = arr[p+i];
    }
    for(int i=p-1; i>0; i--){
        arr[i+c] = arr[i];
    }
    for(int i=0; i<c; i++){
        arr[i+1] = temp[i];
    }
}

int main(void) {
    
    while(1){
        scanf("%d %d", &N, &R);
        if(N==0 & R==0) break;
        init(N);
        for(int i=0; i<R; i++){
            int p, c;
            scanf("%d %d", &p, &c);
            hanafuda(p, c);
        }
        printf("%d\n", arr[1]);
    }
    return 0;
}