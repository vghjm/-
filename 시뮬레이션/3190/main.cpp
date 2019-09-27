#include <iostream>
using namespace std;

int DIR[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

struct Body{
    int x, y;
    Body *next;
    Body(int x1, int y1): x(x1), y(y1), next(nullptr) {}
};

struct Snake{
    Body *head;
    Body *tail;
    int size, dir;
    Snake(int start_x, int start_y){
        head = tail = new Body(start_x, start_y);
        tail->next = head;
        size = 1;
        dir = 1;
    }
    void add_snake(int x, int y){
        Body *temp = new Body(x, y);
        head->next = temp;
        head = temp;
        size++;
    }
    void del_snake(){
        Body *temp = tail;
        tail = tail->next;
        delete temp;
        size--;
    }
    int get_head(int is_y){
        if(is_y) return head->y;
        return head->x;
    }
    int get_tail(int is_y){
        if(is_y) return tail->y;
        return tail->x;
    }
    int get_size(){
        return size;
    }
    int get_dir(){
        return dir;
    }
    void set_dir(int _dir){
        dir = _dir;
    }
};

struct Map{
    int n;
    int arr[105][105];
    Snake *sn;
    char info[10001];
    Map(int n1): n(n1) {
        for(int i=0; i<n+2; i++){
            arr[0][i] = arr[n+1][i] = 1;
        }
        for(int i=1; i<=n+1; i++){
            arr[i][0] = arr[i][n+1] = 1;
        }
        sn = new Snake(1, 1);
        arr[1][1] = 3;
        
        for(int i=1; i<=10000; i++){
            info[i] = '0';
        }
    }
    void add_apple(int x, int y){
        arr[y][x] = 2;
    }
    void add_op(int t, char c){
        info[t] = c;
    }
    int snake_move(){
        int cant_move = 0;
        int next_x = sn->get_head(0) + DIR[sn->get_dir()][0];
        int next_y = sn->get_head(1) + DIR[sn->get_dir()][1];
        
        switch(arr[next_y][next_x]){
            case 0: 
                sn->add_snake(next_x, next_y); 
                arr[next_y][next_x] = 3;
                arr[sn->get_tail(1)][sn->get_tail(0)] = 0;
                sn->del_snake();
                break;
            case 1: cant_move = 1; break;
            case 2: 
                sn->add_snake(next_x, next_y); 
                arr[next_y][next_x] = 3;
                break;
            case 3: cant_move = 1; break;
        }
        
        return cant_move;
    }
    void run_op(int t){
        int pre_dir = sn->get_dir();
        switch(info[t]){
            case 'L': pre_dir--; break;
            case 'D': pre_dir++; break;
        }
        if(pre_dir==-1) pre_dir = 3;
        if(pre_dir==4) pre_dir = 0;
        sn->set_dir(pre_dir);
    }
    void show(){
        for(int i=0; i<=n+1; i++){
            for(int j=0; j<=n+1; j++){
                printf("%2d", arr[i][j]);
            }
            printf("\n");
        }
        printf("-----------------------\n\n");
    }
};

int main() {
    int N, K;   cin>>N>>K;
    Map *map = new Map(N);
    for(int i=0; i<K; i++){
        int x, y;   cin>>y>>x;
        map->add_apple(x, y);
    }
    
    int L;  cin>>L;
    for(int i=0; i<L; i++){
        int x; char c;  cin>>x>>c;
        map->add_op(x, c);
    }
    
    
    
    //printf("start!!----\n");
    //map->show();
    int t=0;
    while(1){
        t++;
        
        if(map->snake_move()){
            break;
        }
        map->run_op(t);
        
        //printf("--time:%d--\n", t);
        //map->show();
    }
    //printf("end!!----\n");
    //map->show();
    printf("%d", t);
    
    return 0;
}