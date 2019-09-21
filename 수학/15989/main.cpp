#include <iostream>
using namespace std;

int main() {
    int T;
    int arr[10001];
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 3;
    for(int i=4; i<10001; i++){
        arr[i] = arr[i-3] + i/2 + 1;
    }
    scanf("%d", &T);
    while(T--){
        int N;
        scanf("%d", &N);
        printf("%d\n", arr[N]);
    }
    return 0;
}