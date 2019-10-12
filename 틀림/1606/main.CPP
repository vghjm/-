#include <iostream>
using namespace std;

int main() {
    int a, b, r, c;
    scanf("%d %d", &a, &b);
    
    if(b==0){
        r = a;
        c = 0;
    }else{
        r = a+b-1;
        c = b;
    }
    //printf("r:%d, c:%d\n", r, c);
    unsigned long long int ans = 3*r*(r+1)+1+c;
    printf("%llu", ans);
    
    
    return 0;
}






