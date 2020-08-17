#include <iostream>
using namespace std;
#define MAX_N 1000

int T, N, L;

int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &L, &N);
        int l = L+1;
        int r = -1;
        int m = 0;
        while(N--){
            int t;
            scanf("%d", &t);
            if(t>r) r = t;
            if(t<l) l = t;
            int mid = min(t, L-t);
            if(mid > m) m = mid;
        }
        printf("%d %d\n", m, max(L-l, r));
    }
    
    return 0;
}