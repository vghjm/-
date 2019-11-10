#include <iostream>
using namespace std;
#define MOD 1000 

int main() {
    int N;
    unsigned long long b;
    int array[65][5][5];
    int ans[65][5][5];
    scanf("%d %llu", &N, &b);
    
    for(int i=0; i<N; i++){
        ans[0][i][i] = 1;
        for(int j=0; j<N; j++){
            scanf("%d", &array[1][i][j]);
        }
    }
    
    for(int i=2; i<65; i++){
        for(int x=0; x<N; x++){
            for(int y=0; y<N; y++){
                unsigned long long temp=0;
                for(int z=0; z<N; z++){
                    temp += array[i-1][x][z]*array[i-1][z][y];
                }
                array[i][x][y] = temp % MOD;
            }
        }
    }
    
    int cou=0;
    for(int i=1; i<65; i++){
        if(b%2){
            for(int x=0; x<N; x++){
                for(int y=0; y<N; y++){
                    unsigned long long temp=0;
                    for(int z=0; z<N; z++){
                        temp += (ans[cou][x][z]*array[i][z][y]) % MOD;
                    }
                    ans[cou+1][x][y] = temp % MOD;
                }
            }
            cou++;
        }
        b/=2;
        if(b==0) break;
    }
    for(int x=0; x<N; x++){
        for(int y=0; y<N; y++){
            printf("%d ", ans[cou][x][y]);
        }
        printf("\n");
    }    
    
    return 0;
}