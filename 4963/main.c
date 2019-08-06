#include <stdio.h>

int map[51][51];	//지도 정보
//대충 구현한 큐
int dx[10000];	//x좌표, 높이	
int dy[10000];	//y좌표, 너비
int count;		//데이터의 수

int find_some_land(int w, int h, int *x, int *y);	//아무 섬을 발견, 없으면 false
int find_near_land(int w, int h, int x, int y);	//주위 섬을 없애고 큐에 넣음

int main(void) {
    int w, h;
    int first=1;
    
    while(1){
        scanf("%d %d", &w, &h);
        if(w==0 && h==0) break;
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d", &map[i][j]);
            }
        }
        
        int x=-1;
        int y=-1;
        int island=0;
        while(find_some_land(w, h, &x, &y)){
            count=-1;
            island++;
            map[x][y] = 0;
            find_near_land(w, h, x, y);
            while(count>=0){
                x=dx[count];
                y=dy[count];
                count--;
                find_near_land(w, h, x, y);
            }
        }
      
        if(!first){
            printf("\n");
        }
        printf("%d", island);
        first=0;
    }
    
    return 0;
}

int find_near_land(int w, int h, int x, int y){
    
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            if(((-1< x+i)&&(x+i < h)) && ((-1< y+j)&&(y+j < w))){
                if(map[x+i][y+j]==1){
                    count++;
                    map[x+i][y+j] = 0;
                    dx[count] = x+i;
                    dy[count] = y+j;
                    
                }
            }
        }
    }
}

int find_some_land(int w, int h, int *x, int *y){
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            if(map[i][j]!=0){
                *x = i;
                *y = j;
                return 1;
            }
        }
    }
    
    return 0;
}