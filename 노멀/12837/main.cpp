#include <iostream>
using namespace std;

long long data[1000001];
long long arr[1001];

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);
    while(Q--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a==1){
            data[b]+=c;
            arr[b/1000]+=c;
        }else{
            int s = b/1000;
            int e = c/1000;
            long long ans = 0;
            if(s==e){
                for(int i=b; i<=c; i++){
                    ans+=data[i];
                }
            }else{
                for(int i=b; i<(s+1)*1000; i++){
                    ans+=data[i];
                }
                for(int i=s+1; i<e; i++){
                    ans+=arr[i];
                }
                for(int i=e*1000; i<=c; i++){
                    ans+=data[i];
                }
            }
            
            
            
            printf("%lld\n", ans);
        }
    }
    
    return 0;
}