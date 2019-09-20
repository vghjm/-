#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

struct point{
    int x;
    int y;
    point(): point(-1, -1) {}
    point(int x1, int y1): x(x1), y(y1) {}
    bool operator ==(point *p){
        return x==p->x && y==p->y;
    }
    void operator =(point *p){
        x = p->x;
        y = p->y;
    }
};


int main() {
    point input[1000];
    
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        input[i] = new point(x, y);
    }
    
    int ans = -1;
    for(int i=0; i<N; i++){
        float deg[1000];
        int count[1000];
        int size=0;
        for(int j=i+1; j<N; j++){
            int dx = input[i].x - input[j].x;
            int dy = input[i].y - input[j].y;
            float temp;
            if(dx==0){
                temp = numeric_limits<float>::max();
            }else{
                temp = (float)dy/dx;
            }

            bool not_found=true;
            for(int k=0; k<size; k++){
                if(deg[k]==temp){ 
                    count[k]++;
                    not_found = false;
                    break;
                }
            }
            if(not_found){
                deg[size] = temp;
                count[size] = 1;
                size++;
            } 
        }
        
        int max = -1;
        for(int j=0; j<size; j++){
            if(count[j] > max){
                max = count[j];
            }
        }
        
        if(max > ans) ans = max;
    }
    
    if(ans < 2){
        printf("-1");
    }else{
        printf("%d", ans+1);
    }
    
    
    
    return 0;
}