#include <iostream>
#include <algorithm>
using namespace std;

int N, d, ans;
bool num[10];

int digit(int k){
    int rtn = 0, t;
    while(1){
        rtn++;
        t = k%10;
        if(num[t]==false) return -1;
        k/=10;
        if(k==0) break;
    }
    
    return rtn;
}

int main() {
    scanf("%d%d", &N, &d);
    for(int i=0; i<10; i++) num[i] = true;
    for(int i=0, k; i<d; i++){
        scanf("%d", &k);
        num[k] = false;
    }
    
    ans = abs(N-100);
    for(int i=0, n; i<=999999; i++){
        n = digit(i);
        if(n==-1) continue;
        n+=abs(N-i);
        ans = min(ans, n);
    }
    
    printf("%d", ans);
    
    return 0;
}



