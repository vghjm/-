#include <iostream>
using namespace std;

int main() {
    int N, arr[5000];
    scanf("%d%d%d", &N, &arr[0], &arr[1]);
    
    int count = 2;
    int ans = 2;
    for(int i=0; i<N-2; i++){
        scanf("%d", &arr[i+2]);
        if((arr[i]<=arr[i+1]&&arr[i+1]<=arr[i+2])||(arr[i]>=arr[i+1]&&arr[i+1]>=arr[i+2])){
            if(count > ans) ans = count;
            count = 2;
        }else{
            count++;
        }
    }
    if(count > ans) ans = count;
    printf("%d", ans);
    
    
    return 0;
}













