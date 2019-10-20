#include <iostream>
using namespace std;
#define INF 987654321

int T, N;

int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        int arr[100001];
        int cut = INF;
        arr[0] = cut;
        for(int i=1; i<=N; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            arr[a] = b;
        }
        
        int ans = 0;
        for(int i=1; i<=N; i++){
            if(arr[i] < cut){
                ans++;
                cut = arr[i];
            }
        }
        
        printf("%d\n", ans);
    }
    return 0;
}










