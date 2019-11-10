#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int p, q, r;
int ans;
string s;
int point_s;

int formula(){
    int rtn;
    int a, b;
    switch(s[point_s++]){
        case '-' : rtn = 2 - formula(); break;
        case '(' : 
            a = formula();
            if(s[point_s++] == '*'){
                b = formula();
                point_s++;
                rtn = min(a, b);
            }else{
                b = formula();
                point_s++;
                rtn = max(a, b);
            }
            break;
        case 'P' : rtn = p; break;
        case 'Q' : rtn = q; break;
        case 'R' : rtn = r; break;
        default : rtn = s[point_s-1] - '0';
    }
    
    return rtn;
}

int main() {
    while(1){
        cin>>s;
        if(s[0] == '.') break;
        
        ans = 0;
        for(p=0; p<3; p++){
            for(q=0; q<3; q++){
                for(r=0; r<3; r++){
                    point_s = 0;
                    if(formula() == 2){
                        ans ++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}