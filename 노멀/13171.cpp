#include <iostream>
using namespace std;
#define MOD 1000000007 

int main() {
    unsigned long long a, b, a_x[65], ans = 1;
    scanf("%llu %llu", &a, &b);
    a_x[1] = a % MOD;
    for(int i=2; i<65; i++){
        a_x[i] = (a_x[i-1] * a_x[i-1]) % MOD;
    }
    
    for(int i=1; i<65; i++){
        if(b%2){
            ans= (ans * a_x[i]) % MOD;
        }
        b/=2;
        if(!b) break;
    }
    printf("%llu", ans);
    
    return 0;
}