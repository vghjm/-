#include <iostream>
#include <algorithm>
using namespace std;

long long len[10000];

int main() {
    long long K, N;
    scanf("%lld %lld", &K, &N);
    for(int i=0; i<K; i++){
        scanf("%lld", &len[i]);
    }
    
    sort(len, len+K);
    long long min = 1, max = len[K-1], mid, count;
    //printf("%d %d", min, max);
    if(N!=1){
        while(min<=max){
            mid = (min+max)/2;
            count = 0;
            for(int i=0; i<K; i++){
                count += len[i]/mid;
            }
            if(count >= N){
                min = mid+1;
            }else{
                max = mid-1;
            }
        }
        //printf("mid: %d\n", mid);
        
    }
    
    printf("%lld", max);
    
    
    
    return 0;
}