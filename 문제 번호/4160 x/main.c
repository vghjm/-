#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N, arr[24], arr_size;

int comp (void *first, void *second) {
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int po(int n){
    int rtn=1;
    for(int i=0; i<n; i++){
        rtn*=2;
    }
    return rtn;
}

void swip(){
    for(int i=0; i<arr_size; i++){
        if(arr[i]==0){
            int t=1;
            for(int j=i+1; j<arr_size; j++){
                if(arr[j]!=0){
                    arr[i] = arr[j];
                    arr[j] = 0;
                    t=0;
                    break;
                }
            }
            if(t) break;
        }
    }
}
int check(int mask){
    int rtn=0;

    for(int i=0; i<N; i++){
        if(mask%2==1){
            rtn+=arr[i];
        }
        mask=mask>>1;
    }

    return rtn;
}

int find_pattern(){
    int target = arr[N];
    int nn = po(N);
    int rtn = 0;
    
    for(int i=1; i<nn; i++){
        if(target==check(i)){
            rtn = i;
            break;
        }
    }

    return rtn;
}

void del(int pattern){
    int len = arr_size;
    arr[N] = 0;
    int dd=1;

    for(int i=0; i<len; i++){
        if(pattern%2==1){
            arr[i] = 0;
            N--;
            dd++;
        }
        pattern = pattern>>1;
    }
    swip();
    arr_size-=dd;

}



int main(void) {
    
    while(1) {
        scanf("%d", &N);
        if(N==0) break;
        memset(arr, 0, sizeof(int)*24);
        for(int i=0; i<N; i++){
            scanf("%d", &arr[i]);
        }
        qsort(arr, N, sizeof(int), comp);
        
        
        arr_size = N;
        int pattern;
        while(N){
            N--;
            if(pattern = find_pattern()){
                del(pattern);
            }
            if(arr_size<1) break;
        }
        
        int ans=0;
        for(int i=0; i<arr_size; i++){
            ans+=arr[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}