#include <iostream>
#include <cmath>
using namespace std;

int calc(int a, char c, int b){
    switch(c){
        case '-': return a - b;
        case '+': return a + b;
        case '*': return a * b;
    }    
}
    
int main() {
    int N;
    char s[21];
    int partial[20][1025];
    int type[20][1025];
    
    scanf("%d ", &N);
    for(int i=0; i<N; i++){
        scanf("%c", &s[i]);
        //printf("%c", s[i]);
    }
    if(N==1){
        printf("%d", s[0]-'0');
        return 0;
    }
    partial[0][0] = s[0] - '0';
    partial[1][0] = calc(s[0]-'0', s[1], s[2]-'0');
    type[0][0] = 1;
    type[1][0] = 1;
    
    for(int i=4; i<N; i+=2){
        int now = i/2;
        int count = 0;
        for(int j=0; j<pow(2, now-2); j++){
            if(type[now-1][j]==1){
                partial[now][count] = calc(partial[now-1][j], s[i-1], s[i]-'0');
                type[now][count++] = 1;
                partial[now][count] = calc(partial[now-2][j/2], s[i-3], calc(s[i-2]-'0', s[i-1], s[i]-'0'));
                type[now][count++] = 2;
            }else if(type[now-1][j]==2){
                partial[now][count] = calc(partial[now-1][j], s[i-1], s[i]-'0');
                type[now][count++] = 1;
                partial[now][count] =  -987654321;
                type[now][count++] = 0;
            }else{
                partial[now][count] =  -987654321;
                type[now][count++] = 0;
                partial[now][count] =  -987654321;
                type[now][count++] = 0;
            }
        }
    }
    
    int max = -987654321;
    int now = N/2;
    
    for(int i=0; i<pow(2, now-1); i++){
        if(type[now][i]&&partial[now][i]>max){
            max = partial[now][i];
        }
        //printf("%d ",partial[now][i]);
    }
    //printf("\n");
    
    printf("%d", max);
    
    return 0;
}








