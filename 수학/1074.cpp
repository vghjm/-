#include <iostream>
#include <cmath>
using namespace std;

int N, R, C, ans, count;
void DFS(int n, int r, int c){
    if(n==0){ 
        ans = count+1;
        return ;
    }
    
    int half = pow(2, n-1);
    if(r > half && c > half){
        r-=half; c-=half;
        count+=3*pow(2, 2*(n-1));
    }else if(r > half){
        r-=half;
        count+=2*pow(2, 2*(n-1));
    }else if(c > half){
        c-=half;
        count+=1*pow(2, 2*(n-1));
    }
    DFS(n-1, r, c);
}

int main() {
    scanf("%d%d%d", &N, &R, &C);
    count = 0;
    DFS(N, R+1, C+1);
    printf("%d", ans-1);
    
    return 0;
}


