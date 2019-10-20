#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int INF = 1e9+1;

int N;

int main(){
    scanf("%d", &N);
    P arr[1000000];
    for(int i=0; i<N; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        arr[i] = P(s, e);
    }
    sort(arr, arr+N);
 
    int result = 0, l = -INF, r = -INF;
    for(int i=0; i<N; i++){
        if(r < arr[i].first){
            result += r-l;
            l = arr[i].first;
            r = arr[i].second;
        }
        else r = max(r, arr[i].second);
    }
    result += r-l; 
    printf("%d\n", result);
}

