#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][300][300];
struct point{
    int x, y, n, m;
    int dx, dy, l;
    point(int y1, int x1, int n1, int m1): x(x1), y(y1), n(n1), m(m1){
        dx = dy = l = 0;
        n--; m--;
    }
    void move_n(int r){
        for(int i=0; i<r; i++){
            move();
        }
    }
    void move(){
        switch(l){
            case 0:
                if(++dy==n) l++;
                break;
            case 1:
                if(++dx==m) l++;
                break;
            case 2:
                if(--dy==0) l++;
                break;
            case 3:
                if(--dx==0) l=0;
                break;
        }
    }
    int get_x(){
        return x+dx;
    }
    int get_y(){
        return y+dy;
    }
};

int main() {
    int N, M, R;
    cin>>N>>M>>R;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[0][i][j];
        }
    }
    
    int n = N, m = M;
    for(int i=0; i<min(N, M)/2; i++){
        point *p1 = new point(i, i, n, m);
        point *p2 = new point(i, i, n, m);
        int count = 2*(n+m-2);
        int r = R%count;
        
        p2->move_n(r);
        for(int j=0; j<count; j++){
            arr[1][p2->get_y()][p2->get_x()] = arr[0][p1->get_y()][p1->get_x()];
            p1->move();
            p2->move();
        }
        n-=2; m-=2;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d ", arr[1][i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}