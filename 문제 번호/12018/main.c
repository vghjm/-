#include <stdio.h>
#include <limits.h>

int N;
int M;
int sub[100];
int P;
int L;
int need_point[100];

int find_nth(int n){
    int max;
    int pos;
    int point = 1;
    for(int i=0; i<n; i++){
        max = INT_MIN;
        pos = -1;
        for(int j=0; j<P; j++){
            if(sub[j] >= max && sub[j] != -1){
                max = sub[j];
                pos = j;
            }
        }
        
        if(pos==-1) return 1;
        point = sub[pos];
        sub[pos] = -1;
        if(i==n-1) return point;
        
    }
    
    return 1;
}

int lowest(){
    int min = INT_MAX;
    int pos = -1;
    for(int i=0; i<N; i++){
        if(need_point[i] < min && need_point[i] != -1){
            min = need_point[i];
            pos = i;
        }
    }
    
    if(pos==-1) return 0;
    need_point[pos] =-1;
    
    return min;
}

int main(void) {
    
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        scanf("%d %d", &P, &L);
        for(int j=0; j<P; j++){
            scanf("%d", &sub[j]);
        }
        need_point[i] = find_nth(L);
    }
    
    /*
    printf("Point\n> ");
    for(int i=0; i<N; i++){
        printf(" %d ", need_point[i]);
    }
    printf("\n");
    */
    
    int count=0;
    int val;
    while((val = lowest())){
        if(M>=val){
            M-=val;
            count++;
        }else {
            break;
        }
    }
    
    //printf("\ncount: %d\n", count);
    printf("%d", count);
    
    return 0;
}