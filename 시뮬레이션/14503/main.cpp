#include <iostream>
using namespace std;

int map[52][52];
struct robot{
    int r, c, deg;
    int clean_count, wall_count;
    robot(int r1, int c1, int deg1): r(r1), c(c1), deg(deg1), clean_count(0), wall_count(0) {}
    int check(){
        switch(deg){
            case 0:
                deg = 3;
                if(map[r][c-1]){
                    return ++wall_count;
                }else{
                    c--;
                }
                break;
            case 1:
                deg = 0;
                if(map[r-1][c]){
                    return ++wall_count;
                }else{
                    r--;
                }
                break;
            case 2:
                deg = 1;
                if(map[r][c+1]){
                    return ++wall_count;
                }else{
                    c++;
                }
                break;
            case 3:
                deg = 2;
                if(map[r+1][c]){
                    return ++wall_count;
                }else{
                    r++;
                }
                break;
        }
        wall_count = 0;
        map[r][c] = 2;
        clean_count++;
        return 0;
    }
    int back(){
        switch(deg){
            case 0:
                if(map[r+1][c]==1) return 0;
                r++;
                break;
            case 1:
                if(map[r][c-1]==1) return 0;
                c--;
                break;
            case 2:
                if(map[r-1][c]==1) return 0;
                r--;
                break;
            case 3:
                if(map[r][c+1]==1) return 0;
                c++;
                break;
        }
        wall_count = 0;
        return 1;
    }
};

int main() {
    int N, M, r, c, deg;
    cin>>N>>M;
    cin>>r>>c>>deg;
    robot *bot = new robot(r+1, c+1, deg);
    
    for(int i=0; i<=M+1; i++){
        map[0][i] = map[N+1][i] = 1;
    }
    for(int i=1; i<N+1; i++){
        map[i][0] = map[i][M+1] = 1;
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];   
        }
    }
    
    bot->clean_count++;
    map[r+1][c+1] = 2;
    while(bot->check()!=4 || bot->back()){}
    printf("%d", bot->clean_count);
    
    return 0;
}