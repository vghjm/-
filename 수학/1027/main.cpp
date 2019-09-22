#include <iostream>
#include <limits>
using namespace std;

int main() {
    int arr[2][50];
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[0][i]);
        arr[1][i] = 0;
    }
    
    for(int i=0; i<N-1; i++){
        double low = (double) (arr[0][i+1] - arr[0][i]);
        arr[1][i]++;
        arr[1][i+1]++;
        for(int j=i+2; j<N; j++){
            double deg = (double) (arr[0][j] - arr[0][i]) / (j - i);
            if(deg > low){
                arr[1][i]++;
                arr[1][j]++;
                low = deg;
            }
        }
    }
    int max = -1;
    for(int i=0; i<N; i++){
        if(arr[1][i] > max) max = arr[1][i];
    }
    printf("%d", max);
    
    return 0;
}