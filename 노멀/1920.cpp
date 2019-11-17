#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

int main() {
    int N, M;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        int a;
        scanf("%d", &a);
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    scanf("%d", &M);
    for(int i=0; i<M; i++){
        int a;
        scanf("%d", &a);
        if(find(arr.begin(), arr.end(), a)!=arr.end()){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    return 0;
}