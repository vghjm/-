#include <iostream>
using namespace std;
typedef unsigned long long int ulld;

const char output[2] = {'-', '*'};
ulld A, B, t;
char ans[160];
int mode;


ulld gcd(ulld a, ulld b){
	ulld c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main() {
    scanf("%llu%llu", &A, &B);
    t = gcd(B, A);
    A/=t; B/=t;
    if(A>=B-A){
        mode = 0;
        t = A;
    }else{
        mode = 1;
        t = B-A;
    } 
    int c = 0;
    while(t){
        if(t%2==0) ans[c] = '*';
        else ans[c] = '-';
        t/=2;
        c++;
    }
    if(c>60){
        printf("-1");
    }else if(A==0){
        cout<<'-';
    }else if(A==B){
        cout<<'*';
    }else{
        for(int j=0; j<c; j++){
            if(ans[j]!=ans[0]){
                cout<<output[mode];
            }else{
                cout<<output[!mode];
            }
        }
    }
    
    
    return 0;
}