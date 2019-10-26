#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 1000

int N;
int arr[MAX_N];

int main() {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+N);
    
    int ans = 0;
    for(int i=0; i<N; i++){
        int c = arr[i];
        ans += c*(N-i);
    }
    
    printf("%d", ans);
    
    return 0;
}