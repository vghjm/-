#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int arr[100000];
queue<int> q[2];
int count, d;
void A(int n){
    int next = n+1;
    if(next<100000&&arr[next]==-1){
        //printf("A->%d in %d\n", next, count);
        arr[next] = count;
        q[!d].push(next);
    }
}
void B(int n){
    int next = 2*n;
    if(next<100000){
       if(next>9999){
           next-=10000;
       }else if(next>999){
           next-=1000;
       }else if(next>99){
           next-=100;
       }else if(next>9){
           next-=10;
       }else{
           next-=1;
       }
       if(next>=0&&arr[next]==-1){
           //printf("B->%d in %d\n", next, count);
           arr[next] = count;
           q[!d].push(next);
       }
    }
}
int main() {
    int n, t, g;
    cin>>n>>t>>g;
    for(int i=0; i<100000; i++){
        arr[i] = -1;
    }
    
    
    arr[n] = 0;
    count=1;
    d=0;
    q[d].push(n);
    while(arr[g]==-1&&count<=t){
        while(!q[d].empty()){
            int next = q[d].front();
            q[d].pop();
            A(next);
            B(next);
        }
        d=!d;
        count++;
    }
    if(arr[g]==-1) printf("ANG");
    else printf("%d", arr[g]);
    
    return 0;
}






