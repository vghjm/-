#include <iostream>
using namespace std;

int D, N;
int oven[300000][2], dow[300000];

int main() {
    scanf("%d %d", &D, &N);
    int oven_min = 987654321;
    for(int i=0; i<D; i++){
        scanf("%d", &oven[i][0]);
        if(oven_min > oven[i][0]){
            oven_min = oven[i][0];
        }
        oven[i][1] = oven_min;
    }
    for(int i=0; i<N; i++){
        scanf("%d", &dow[i]);
    }
    
    int oven_pos = D;
    for(int i=0; i<N; i++){
        while(oven_pos--){
            if(oven[oven_pos][0] >= dow[i] && oven[oven_pos][1] >= dow[i]){
                break;
            }
        }
        if(oven_pos<0) break;
    }

    printf("%d", oven_pos+1);
    
    return 0;
}



