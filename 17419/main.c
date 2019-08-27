#include <stdio.h>

int main(void) {
    int N;
    int temp;
    scanf("%d", &N);
    int count = 0;
    //scanf("%")
    for(int i=0; i<N; i++){
        scanf("%1d", &temp);
        if(temp) count++;
    }
    printf("%d",count);
    return 0;
}