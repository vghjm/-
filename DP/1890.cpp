#include <iostream>
using namespace std;
typedef unsigned long long ull;

int N, jump[101][101];
ull map[101][101];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &jump[i][j]);
        }
    }
    map[1][1] = 1;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==N && j==N) break;
            if(j+jump[i][j]<=N) map[i][j+jump[i][j]]+=map[i][j];
            if(i+jump[i][j]<=N) map[i+jump[i][j]][j]+=map[i][j];
        }
    }
    
    printf("%llu", map[N][N]);
    return 0;
}