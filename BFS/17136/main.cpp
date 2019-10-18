#include <iostream>
#include <queue>
using namespace std;

struct map{
    int x, y;
    int D[10][10];
    int p[6];
    map(): x(0), y(0) {
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                D[i][j] = 0;
            }
        }
        for(int i=1; i<6; i++){
            p[i] = 0;
        }
    }
    map(map *temp, int x, int y, int k){
        this->x = x;
        this->y = y;
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                this->D[i][j] = temp->D[i][j];
            }
        }
        for(int i=x; i<x+k; i++){
            for(int j=y; j<y+k; j++){
                this->D[i][j] = 0;
            }
        }
        for(int i=1; i<6; i++){
            this->p[i] = temp->p[i];
        }
        this->p[k]++;
    }
    int rtn(){
        int ans = 0;
        for(int i=1; i<6; i++){
            ans+=p[i];
        }
        return ans;
    }
};

queue<map*> q[2];
int q_type;
int input[10][10];

bool can(map *temp, int x, int y, int k){
    if(temp->p[k]>=5) return false;
    for(int i=x; i<x+k; i++){
        for(int j=y; j<y+k; j++){
            if(i>=10||j>=10||!temp->D[i][j]){
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    map *S = new map();
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            scanf("%d", &(S->D[i][j]));
        }
    }
    
    q[q_type].push(S);
    while(true){
        map *temp = q[q_type].front();
        q[q_type].pop();
        bool out = false;
        for(int i=temp->x; i<10; i++){
            for(int j=0; j<10; j++){
                //printf("%d %d > ", i, j);
                if(temp->D[i][j]){
                    //printf("%d %d\n", i, j);
                    out = true;
                    for(int k=5; k>0; k--){
                        if(can(temp, i, j, k)){
                            q[!q_type].push(new map(temp, i, j, k));
                        }
                    }
                    break;
                }
            }
            if(out) break;
        }
        if(!out){
            int ans = temp->rtn();
            //printf(">p1 %d\n", temp->p[1]);
            printf("%d", ans);
            break;
        }
        if(q[q_type].empty()){
            if(q[!q_type].empty()){
                printf("-1");
                break;
            }
            q_type=!q_type;
        }
    }
    
    
    
    
    
    
    
    
    
    
    return 0;
}
















