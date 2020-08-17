#include <stdio.h>
#include <stdbool.h>

int N;
int arr[1000];
bool used[1000];

bool all_used(){
    for(int i=0; i<N; i++){
        if(used[i] == false) return false;
    }
    return true;
}
int main(void) {
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        used[i] = false;
    }
    
    int count=1;
    int heigth=0;
    int min=1001;
    int pos = -1;
    while(1){
        for(int i=0; i<N; i++){
            if(used[i]==false && arr[i] >= heigth && arr[i] <min){
                pos = i;
                min = arr[i];
            }
        }
        if(pos==-1){
            if(all_used()) break;
            count++;
            heigth = 0;
            min = 1001;
            pos = -1;
        }else {
            heigth++;
            used[pos] = true;
            min = 1001;
            pos=-1;
        }
    }
    printf("%d", count);
    return 0;
}