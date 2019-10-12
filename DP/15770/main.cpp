#include <iostream>
using namespace std;

bool sub[10001][10001];

int main() {
    int Q;
    char s[10001];
    char input;
    int q_count[10001];
    scanf("%d ", &Q);
    
    
    int now = 0;
    while(Q--){
        scanf("%c", &input);

        if(input=='-'){
            s[now] = 0;
            for(int i=1; i<=now; i++){
                sub[now][i] = 0;
            }
            q_count[now] = 0;
            now--;
        }else{
            now++;
            s[now] = input;
            int count = q_count[now-1]+1;
            
            for(int i=1; i<now; i++){
                if(s[i]==s[now]&&sub[now-1][i+1]){
                    count++;
                    sub[now][i] = 1;
                }
            }
            sub[now][now] = 1;
            if(s[now-1]==s[now]){
                count++;
                sub[now][now-1] = 1;
            }
            
            q_count[now] = count;
            
        }
        printf("%d ", q_count[now]);
    }
    return 0;
}










