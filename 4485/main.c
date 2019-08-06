#include <stdio.h>
#include <limits.h>
#define min(a, b) (((a)>(b)) ? (b):(a))

int cave[126][126];
int al[126][126];
int visit[126][126];

int main(void) {
    int N;
    int t=1;
    int first=1;
    
    while(1){
        scanf("%d", &N);
        if(N==0)
            break;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                scanf("%d", &cave[i][j]);
                //initial al
                al[i][j] = INT_MAX;
                visit[i][j] = 0;
            }
        }
        
        //calc
        al[0][0] = cave[0][0];
        al[0][1] = al[0][0] + cave[0][1];
        al[1][0] = al[0][0] + cave[1][0];
        visit[0][0] = 1;
        
        while(1){
            int x=-1;
            int y=-1;
            int minimal=INT_MAX;
        
            for(int i=0; i<N; i++){
                for(int j=0; j<N; j++){
                    if(visit[i][j]==0 && al[i][j]<minimal){
                        x=i;
                        y=j;
                        minimal = al[i][j];
                    }
                }
            }
            if(x==-1 || y==-1) break;
            visit[x][y] = 1;
            if(y-1>=0){
                al[x][y-1] = min(al[x][y]+cave[x][y-1], al[x][y-1]);
                if(al[x][y]+cave[x][y-1] < al[x][y-1] && visit[x][y-1]==1)
                    visit[x][y-1] = 0;
            }
            if(y+1<N){
                al[x][y+1] = min(al[x][y]+cave[x][y+1], al[x][y+1]);
                if(al[x][y]+cave[x][y+1] < al[x][y+1] && visit[x][y+1]==1)
                    visit[x][y+1] = 0;
            }
            if(x-1>=0){
                al[x-1][y] = min(al[x][y]+cave[x-1][y], al[x-1][y]);
                if(al[x][y]+cave[x-1][y] < al[x-1][y] && visit[x-1][y]==1)
                    visit[x-1][y] = 0;
            }
            if(x+1<N){
                al[x+1][y] = min(al[x][y]+cave[x+1][y], al[x+1][y]);
                if(al[x][y]+cave[x+1][y] < al[x+1][y] && visit[x+1][y]==1)
                    visit[x+1][y] = 0;
            }
        }
        
        if(!first){
            printf("\n");
        }
        first=0;
        printf("Problem %d: %d", t, al[N-1][N-1]);
        t++;
        
    }//E: while
        
    
    return 0;
}