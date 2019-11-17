#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int N, K;
    cin >> N >> K;
    int low = 1, high = K;
    int result = -1;

    while(low <= high){
        int cnt = 0;
        int mid = (low + high) / 2;
        for (int i = 1; i <= N; i++)
            cnt += min(mid / i, N); //mid���� ���� j�� ��(i * j <= mid)
        if (cnt < K)
            low = mid + 1;
        else{
            result = mid;
            high = mid - 1;
        }
    }
    cout << result;

    return 0;

}