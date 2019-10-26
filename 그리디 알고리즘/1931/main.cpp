#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int N;
pair<int, int> arr[100000];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d %d", &arr[i].second, &arr[i].first);
    }
    sort(arr, arr+N);
    
    int ans = 1;
    //int s = arr[0].second;
    int e = arr[0].first;
    for(int i=1; i<N; i++){
        if(e <= arr[i].second){
            e = arr[i].first;
            ans++;
        }
    }
    
    printf("%d", ans);
    
    return 0;
}