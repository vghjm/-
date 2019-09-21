#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct point{
    int x, y;
    point(int x1, int y1): x(x1), y(y1) {}
};

int calc(point *i, point *j, point *k){
    float angle;
    if(i->x==j->x){
        if(k->x > i->x) return 1;
        return 0;
    }else {
        angle = (float)(i->y - j->y) / (i->x - j->x);
        if(k->y > (angle*(k->x - i->x) + (float)i->y)) return 1;
        return 0;
    }
}

int main() {
    int N;
    int ans = 0;
    scanf("%d", &N);
    
    vector<point*> pan, no_pan;
    for(int i=0; i<N; i++){
        int x, y;
        string s;
        cin>>x>>y>>s;
        if(s=="LOVELYZ"){
            pan.push_back(new point(x, y));
        }else {
            no_pan.push_back(new point(x, y));
        }
    }
    
    
    int size = no_pan.size();
    for(int i=0; i<size; i++){
        point *main = no_pan[i];
        
        for(int j=i+1; j<size; j++){
            point *sub = no_pan[j];
            int type = -1;
            
            for(int k=0; k<size; k++){
                if(k==i||k==j) continue;
                point *test = no_pan[k];

                if(calc(main, sub, test)){
                    if(type==-1) type=1;
                    if(type==0) type=2;
                }else{
                    if(type==-1) type=0;
                    if(type==1) type=2;
                }
                
            }
            
            if(type!=2){
                //find
                int count = 0;
                for(int k=0; k<pan.size(); k++){
                    if(calc(main, sub, pan[k])!=type) count++;
                }
                if(count > ans) ans = count;
            }
            
        }
        
    }
    
    printf("%d", ans);
    
    
    return 0;
}