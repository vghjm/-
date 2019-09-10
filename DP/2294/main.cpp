#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    int arr[10001];
    vector<int> A;
    
    int N, K;
    scanf("%d%d", &N, &K);
    
    while(N--){
        int temp;
        scanf("%d", &temp);
        if(temp<=K)
            A.push_back(temp);
    }
    
    arr[0] = 0;
    for(int i=1; i<=K; i++)
        arr[i] = -1;
    
    
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(),A.end()),A.end());
    
    for(int i=A.size()-1; i>=0; i--)
        for(int j=0; j<=K; j++){
            int pre = j - A[i];
            if (pre >= 0 && arr[pre] != -1&&(arr[j] == -1 || arr[j] > arr[pre] + 1))
                arr[j] = arr[pre] + 1;
        }

    printf("%d", arr[K]);   
   
    return 0;
}