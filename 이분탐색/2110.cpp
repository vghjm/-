#include <iostream>
#include <algorithm>
using namespace std;

int N, C;
int pos[200000];

int main() {
    scanf("%d %d", &N, &C);
    for(int i=0; i<N; i++){
        scanf("%d", &pos[i]);
    }
    sort(pos, pos+N);
    
    int left = 1; // min interval
    int right = pos[N-1] - pos[0]; // max interval
    int d = 0;
    int ans = 0;
    
    while(left <= right){
        int pre = pos[0];
        int mid = (left + right)/2;
        int cnt = 1;
        
        for(int i=1; i<N; i++){
            d = pos[i] - pre;
            if(mid <= d){
                cnt++;
                pre = pos[i];
            }
        }
        
        if(cnt >= C){
            left = mid+1;
            ans = mid;
        }else{
            right = mid-1;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}
