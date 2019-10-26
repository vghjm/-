#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

int main() {
    scanf("%d %d", &N, &M);
    int pack = 1001, each = 1001;
    for(int i=0; i<M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        pack = min(pack, a);
        each = min(each, b);
    }
    
    int ans = 0;
    if(pack<each*6) ans += pack*(N/6);
    else ans+=each*(N/6)*6;
    N%=6;
    if(pack>N*each) ans += N*each;
    else ans+=pack;
    
    printf("%d", ans);
    
    
    
    return 0;
}