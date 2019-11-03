#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX_N 22
#define INF 987654321
using namespace std;

struct Point{
    //row, column
    int r, c;
    Point(int r1, int c1): r(r1), c(c1) {}
};

struct Shark{
    int r, c, size, numberOfEat, time_;
    Shark(int r1, int c1, int size1): r(r1), c(c1), size(size1), numberOfEat(0), time_(0) {}
    void eatting(int time_){
        numberOfEat++;  
        this->time_+=time_;
        if(numberOfEat>=size){
            size++;
            numberOfEat=0;
        }
    }
};

int N;
int map[MAX_N][MAX_N];
Shark* shark;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void init(){
    scanf("%d", &N);
    //outter space
    for(int i=0; i<=N+1; i++) map[i][0] = map[i][N+1] = INF;
    for(int j=1; j<=N; j++) map[0][j] = map[N+1][j] = INF;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int temp_input;
            scanf("%d", &temp_input);
            if(temp_input==9){
                shark = new Shark(i, j, 2);
            }
            map[i][j] = temp_input;
        }
    }
}

bool comp(Point* a, Point* b){
    //row fitst, column second
    if(a->r == b->r){
        return a->c < b->c;
    }else{
        return a->r < b->r;
    }
}

bool find_fish(){
    bool visit_map[MAX_N][MAX_N];
    queue<Point*> search_area[2];
    vector<Point*> find_list;
    //switch the search_area easily
    bool toggle = 0;
    //return value
    int rtn = 0;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            visit_map[i][j] = 0;
        }
    }
    int r = shark->r, c = shark->c;
    visit_map[r][c] = 1;
    search_area[toggle].push(new Point(r, c));
    bool find = 0;
    int dist = 0;
    int shark_size = shark->size;
    while(!search_area[toggle].empty()){
        //BFS
        while(!search_area[toggle].empty()){
            int now_r = search_area[toggle].front()->r;
            int now_c = search_area[toggle].front()->c;
            search_area[toggle].pop();
            
            for(int i=0; i<4; i++){
                int next_r = now_r + dr[i];
                int next_c = now_c + dc[i];
                if(map[next_r][next_c] <= shark_size && !visit_map[next_r][next_c]){
                    visit_map[next_r][next_c] = 1;
                    search_area[!toggle].push(new Point(next_r, next_c));
                    if(map[next_r][next_c]!=shark_size && map[next_r][next_c]!=0){
                        find = 1;
                        find_list.push_back(new Point(next_r, next_c));
                    }
                }
            }
        }
        
        dist++;
        toggle=!toggle;
        if(find){
            //move shark and eat
            if(find_list.size()!=1){
                sort(find_list.begin(), find_list.end(), comp);
            }
            int new_r = find_list.front()->r;
            int new_c = find_list.front()->c;
            map[r][c] = 0;
            map[new_r][new_c] = 9;
            shark->eatting(dist);
            shark->r = new_r;
            shark->c = new_c;
            rtn = 1;
            break;
        }
    }
    
    return rtn;
}


int main() {
    //input here
    init();
    
    while(find_fish()){
        //test code;
        //printf("pos %d, %d, size:%d, numberOfEat:%d, time:%d\n", shark->r, shark->c, shark->size, shark->numberOfEat, shark->time_);
    }
    
    //no fish found
    printf("%d", shark->time_);
    
    
    return 0;
}
