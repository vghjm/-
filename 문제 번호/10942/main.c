#include <stdio.h>

int arr[2001][2001];
int N;
int M;

int main(void) {
    
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[0][i+1]);
        arr[i+1][0] = arr[0][i+1];
    }
    /*
    printf("arr1\n");
    for(int i=0; i<=N; i++){
        for(int k=0; k<=N; k++){
            printf(" %d ", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    */
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            arr[i][j] = 0;
        }
    }
    for(int i=0; i<N; i++){
        for(int k=1; k<=N-i; k++){
            if(i==0){
                arr[k][i+k] = 1;  
            }else if(i==1){
                if(arr[k][0] == arr[0][i+k]){
                    arr[k][i+k] = 1;    
                }
            }else{
                if(arr[k+1][i+k-1]==1 && arr[k][0] == arr[0][k+i]){
                    arr[k][i+k] = 1;
                }
            }
        }
    }
    /*
    printf("arr2\n");
    for(int i=0; i<=N; i++){
        for(int k=0; k<=N; k++){
            printf(" %d ", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    */
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        //printf("\n%d\n", arr[a][b]);
        printf("%d\n", arr[a][b]);
    }
    return 0;
}