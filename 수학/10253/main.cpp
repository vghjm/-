#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T, a, b;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &a, &b);
        int x=2;
        while(1){
            double _a = (double)b/a;
            if(_a==ceil(_a)){
                printf("%d\n", b/a);
                break;
            }
            _a = (double)(b+1)/a;
            x=ceil(_a);
            if(_a==x){
                printf("%d\n", x*b);
                break;
            }else{
                a = a*x-b;
                b*=x;
            }
        }
    }
    
    return 0;
}