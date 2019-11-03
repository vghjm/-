#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int arr[10001];
vector<int> pattern[5];
int side[5][2];
int range[5][2];
int state[5];

int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }
    
    int pt = 0, pre;
    //a-pattern;
    range[0][0] = 0;
    for(int i=1; i<=N; i++){
        switch(pt){
            case 0:
                
                if(arr[i]!=i){
                    range[pt][1] = i-1;
                    pt++;
                    pre = arr[i];
                    range[pt][0] = i;
                }else{
                    pattern[pt].push_back(arr[i]);
                    break;
                }
            case 1:
                if(abs(pre-arr[i])>1){
                    range[pt][1] = i-1;
                    pt++;
                    pre = arr[i];
                    range[pt][0] = i;
                }else{
                    pattern[pt].push_back(arr[i]);
                    pre = arr[i];
                    break;
                }
            case 2:
                if(abs(pre-arr[i])>1){
                    range[pt][1] = i-1;
                    pt++;
                    pre = arr[i];
                    range[pt][0] = i;
                }else{
                    pattern[pt].push_back(arr[i]);
                    pre = arr[i];
                    break;
                }
            case 3:
                if(abs(pre-arr[i])>1){
                    range[pt][1] = i-1;
                    pt++;
                    range[pt][0] = i;
                }else{
                    pattern[pt].push_back(arr[i]);
                    pre = arr[i];
                    break;
                }
            case 4:
                pattern[pt].push_back(arr[i]);
        }
    }
    range[4][1] = N;
    
    for(int i=0; i<5; i++){
        if(pattern[i].empty()){
            state[i] = 1;
            side[i][0] = side[i][1] = 100000*i;
        }else{
            if(pattern[i].front() > pattern[i].back()){
                state[i] = -1;
                side[i][0] = pattern[i].back();
                side[i][1] = pattern[i].front();
            }else{
                state[i] = 1;
                side[i][0] = pattern[i].front();
                side[i][1] = pattern[i].back();
            }
        }
    }
    
    for(int i=0; i<5; i++){
        printf("pattern-%d, state:%d, side: %d~%d, range: %d~%d\n\t", i, state[i], side[i][0], side[i][1], range[i][0], range[i][1]);
        for(int j : pattern[i]){
            printf(" %d ", j);
        }
        printf("\n");
    }
    
    if(side[1][0] > side[2][0]){
        if(side[2][0] > side[3][0]){
            printf("%d %d\n", range[1][0], range[3][1]);
            printf("%d %d", range[2][0], range[2][1]);
        }else{
            printf("%d %d\n", range[1][0], range[2][1]);
            printf("%d %d", range[2][0], range[3][1]);
        }
    }else if(side[2][0] > side[3][0]){
        printf("%d %d\n", range[2][0], range[3][1]);
        printf("%d %d", range[1][0], range[2][1]);
    }else{
        //not twisted
        for(int i=1; i<=3; i++){
            if(state[i]==-1){
                printf("%d %d\n", range[i][0], range[i][1]);
            }
        }
    }
    
    
    return 0;
}
















