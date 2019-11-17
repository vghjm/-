#include <iostream>
#define MOD 1000000007
using namespace std;


long long mul(long long x, long long y, long long p) {
    long long ans = 1;
    while (y > 0) {
        if (y%2 != 0) {
            ans *= x;
            ans %= p;
        }
        x *= x;
        x %= p;
        y/=2;
    }
    return ans;
}

int M;

int main() {
    long long ans = 0;
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int n, s;
        scanf("%d %d", &n, &s);
        long long reverse_n = mul(n, MOD-2, MOD);
        //cout<<b_reverse<<"\n";
        ans += (reverse_n * s) % MOD;
    }
    
    cout<<ans%MOD;
    
    
    return 0;
}












