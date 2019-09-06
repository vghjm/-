#include <stdio.h>

int isRepeat(int n){
    int ten[10] = {0};
    while(n){
        if(ten[n%10]==0){
            ten[n%10] = 1;
        }else{
            return 1;
        }
        n/=10;
    }
    return 0;
}
int arr[1000001];

int main(void) {
    int test= 26195083;
    int count_N=0;
    for(int i=1; i<=test; i++){
        if(!isRepeat(i)){
            count_N++;
            arr[count_N] = i;
        }
    }
    int input;
    while(1){
        scanf("%d", &input);
        if(input==0) break;
        printf("%d\n", arr[input]);
    }
    return 0;
}