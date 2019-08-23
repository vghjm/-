#include <stdio.h>

int main(void) {
    int n, m;
    int map[251][251];
    
    scanf("%d %d", &n, &m);
    int u, v, b;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            map[i][j] = (i==j) ? 0 : 10000;
        }
    }
    for(int i=0; i<m; i++){
        scanf("%d %d %d", &u, &v, &b);
        if(b){
            map[u][v] = 0;
            map[v][u] = 0;
        }else {
            map[u][v] = 0;
            map[v][u] = 1;
        }
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(map[i][k] + map[k][j] < map[i][j]) map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
    /*
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            printf(" %d ", map[i][j]);
        }
        printf("\n");
    }
    */
    int k;
    scanf("%d", &k);
    int s, e;
    for(int i=0; i<k; i++){
        scanf("%d %d", &s, &e);
        printf("%d\n", map[s][e]);
    }
    
    return 0;
}