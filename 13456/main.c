#include <stdio.h>

int arr[100];

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
        }
        int hd=0;
        int temp;
        for(int i=0; i<N; i++){
            scanf("%d", &temp);
            if(temp!=arr[i]) hd++;
        }
        printf("%d\n", hd);
    }
    return 0;
}