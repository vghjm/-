#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin>>s;
    
    int ans=0;
    while(!s.empty()){
        switch(s.back()){
            case '=':
                s.pop_back();
                if(s.back() == 'c' || s.back() == 's'){
                    s.pop_back();
                    ans++;
                }else if(s.back() == 'z'){
                    s.pop_back();
                    if(s.back() == 'd'){
                        s.pop_back();
                        ans++;
                    }else{
                        ans++;
                    }
                }else{
                    ans++;
                }
                break;
            case '-':
                s.pop_back();
                if(s.back() == 'c' || s.back() == 'd'){
                    s.pop_back();
                    ans++;
                }else{
                    ans++;
                }
                break;
            case 'j':
                s.pop_back();
                if(s.back() == 'l' || s.back() == 'n'){
                    s.pop_back();
                    ans++;
                }else{
                    ans++;
                }
                break;
            default : s.pop_back(); ans++; 
        }
    }
    
    printf("%d", ans);
    return 0;
}