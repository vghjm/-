#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int h, o, temp;
    int N;
    int arr[3][100000];
    int D;

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &h, &o);
        if(o<h){
            temp = h;
            h = o;
            o = temp;
        }
        arr[0][i] = h+100000000;
        arr[1][i] = o+100000000;
        arr[2][i] = arr[1][i] - arr[0][i];
    }
    scanf("%d", &D);
    int *rail = (int*)calloc(100000000, sizeof(int));

    int size;
    for(int i=0; i<N; i++){
        if(arr[2][i] <= D){
            for(int j=arr[1][i]-D; j<=arr[0][i]; j++){
                if(j<0) continue;
                if(j<100000000){
                    rail[j]++;
                }
            }
        }
    }
    
    int max = -1;
    for(int i=0; i<100000000; i++){
        if(rail[i] > max) max = rail[i];
        rail[i] = 0;
    }
    
    int rail_max=0;
    for(int i=0; i<N; i++){
        if(arr[2][i] <= D){
            for(int j=arr[1][i]-D; j<=arr[0][i]; j++){
                if(j<100000000) continue;
                if(j==200000000){
                    rail_max++;
                }else{
                    rail[j-100000000]++;
                }
                
            }
        }
    }
    
    for(int i=0; i<100000000; i++){
        if(rail[i] > max) max = rail[i];
    }
    if(rail_max>max) max=rail_max;

    
    printf("%d\n", max);
    
    
    return 0;
}