#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAX_N 30

struct point{
    int x, y, d, limit;
    bool visit;
    point() {visit=0;}
    point(int x1, int y1, int d1): x(x1), y(y1), d(d1) { visit = 0;}
};

int N, M, D;
int input[MAX_N][MAX_N];
point ss[MAX_N][MAX_N];
point *map[MAX_N][MAX_N+MAX_N][MAX_N];
int c[MAX_N][MAX_N+MAX_N-1];

int simul(int A, int B, int C){
    int l=1, r=D, max_count=N, count=0;
    int find_a, find_b, find_c;
    vector<point*> find;
    //int sub_map[MAX_V][MAX_V];
    
    for(int i=0; i<max_count; i++){
        find_a = find_b = find_c = 0;
        for(int j=l+i; j<=r+i; j++){
            if(!find_a){
            for(int k=0; k<c[A][j]; k++){
                if(map[A][j][k]->limit>i && map[A][j][k]->d>=i){
                    if(!map[A][j][k]->visit){
                        map[A][j][k]->visit=1;
                        map[A][j][k]->d = i;
                        count++;
                        find.push_back(map[A][j][k]);
                        //printf("A(%d, %d)/%d ", map[A][j][k]->x, map[A][j][k]->y, j);
                    }
                    find_a = 1;
                    break;
                }
            }
            }
            if(!find_b){
            for(int k=0; k<c[B][j]; k++){
                if(map[B][j][k]->limit>i && map[B][j][k]->d>=i){
                    if(!map[B][j][k]->visit){
                        map[B][j][k]->visit = 1;
                        map[B][j][k]->d = i;
                        count++;
                        find.push_back(map[B][j][k]);
                        //printf("B(%d, %d)/%d ", map[B][j][k]->x, map[B][j][k]->y, j);
                    }
                    find_b = 1;
                    break;
                }
            }
            }
            if(!find_c){
            for(int k=0; k<c[C][j]; k++){
                if(map[C][j][k]->limit>i && map[C][j][k]->d>=i){
                    if(!map[C][j][k]->visit){
                        map[C][j][k]->visit=1;
                        map[C][j][k]->d = i;
                        count++;
                        find.push_back(map[C][j][k]);
                        //printf("C(%d, %d)/%d ", map[C][j][k]->x, map[C][j][k]->y, j);
                    }
                    find_c = 1;
                    break;
                }
            }
            }
            if(find_a&&find_b&&find_c){
                break;
            }
        }
    }
    
    for(point* t:find){
        t->d = 1000;
        t->visit=0;
    }
    
    
    return count;
}



int main() {
    
    scanf("%d %d %d", &N, &M, &D);
    for(int x=0; x<N; x++){
        for(int y=0; y<M; y++){
            scanf("%d", &input[x][y]);
        }
    }
    
    for(int i=0; i<M; i++){
        for(int j=N-1; j>-1; j--){
            if(input[j][i]){
                ss[j][i].x=j;
                ss[j][i].y=i;
                ss[j][i].d=1000;
                ss[j][i].limit=N-j;
                for(int k=0; k<M; k++){
                    map[k][N-j+abs(k-i)][c[k][N-j+abs(k-i)]++] = &ss[j][i];
                }
            }
        }
    }
    
    int max = -1;
    for(int A=0; A<M-2; A++){
        for(int B=B+1; B<M-1; B++){
            for(int C=B+1; C<M; C++){
                int temp = simul(A, B, C);
                if(temp>max) max = temp;
                //printf("\n%d\n", max);
            }
        }
    }
    
    printf("%d", max);
    
    
    return 0;
}



