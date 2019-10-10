#include <iostream>
#include <utility>
#include <queue>
using namespace std;
#define N_SIZE 18

int MAP[N_SIZE][N_SIZE];

struct pipe{
    int x, y, deg;
    pipe(int x1, int y1, int deg1): x(x1), y(y1), deg(deg1) {}
    void operator=(pipe p){
        x=p.x; y=p.y; deg=p.deg;
    }
    bool operator==(pipe p){
        return x==p.x&&y==p.y;
    }
    bool can_move(int to){
        int rtn;
        switch(to){
            case 0: rtn = !MAP[x][y+1]; break;
            case 1: rtn = !(MAP[x][y+1]||MAP[x+1][y+1]||MAP[x+1][y]); break;
            case 2: rtn = !MAP[x+1][y]; break;
        }
        //if(rtn) printf("move %d\n", to);
        return rtn;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d", &MAP[i][j]);
        }
    }
    for(int i=0; i<=N+1; i++){
        MAP[0][i] = MAP[N+1][i] = 1;
    }
    for(int i=1; i<=N; i++){
        MAP[i][0] = MAP[i][N+1] = 1;
    }
    
    int ans = 0;
    pipe S = pipe(1, 2, 0);
    pipe E = pipe(N, N, 0);
    queue<pipe> q;
    q.push(S);
    while(!q.empty()){
        pipe curr = q.front();
        q.pop();
        if(curr==E){
            ans++;
            continue;
        }
        int x = curr.x;
        int y = curr.y;
        switch(curr.deg){
            case 0:
                if(curr.can_move(0)) q.push(pipe(x, y+1, 0));
                if(curr.can_move(1)) q.push(pipe(x+1, y+1, 1));
                break;
            case 1:
                if(curr.can_move(0)) q.push(pipe(x, y+1, 0));
                if(curr.can_move(1)) q.push(pipe(x+1, y+1, 1));
                if(curr.can_move(2)) q.push(pipe(x+1, y, 2));
                break;
            case 2:
                if(curr.can_move(1)) q.push(pipe(x+1, y+1, 1));
                if(curr.can_move(2)) q.push(pipe(x+1, y, 2));
                break;
        }
        
    }
    
    printf("%d", ans);
    
    return 0;
}














