#include <iostream>
using namespace std;

int N;
int map[64][64];

void q_tree(int y1, int x1, int y2, int x2){
    int t = map[y1][x1];
    bool out = 0;
    for(int i=y1; i<y2; i++){
        for(int j=x1; j<x2; j++){
            if(map[i][j] != t){
                out=1;
                break;
            }
        }
        if(out) break;
    }
    if(out){
        printf("(");
        q_tree(y1, x1, (y1+y2)/2, (x1+x2)/2);
        q_tree(y1, (x1+x2)/2, (y1+y2)/2, x2);
        q_tree((y1+y2)/2, x1, y2, (x1+x2)/2);
        q_tree((y1+y2)/2, (x1+x2)/2, y2, x2);
        printf(")");
    }else{
        printf("%d", t);
    }
}

int main() {
    scanf("%d ", &N);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            char c;
            scanf("%c", &c);
            map[i][j] = c - '0';
        }
        getchar();
    }
    q_tree(0, 0, N, N);
    
    return 0;
}