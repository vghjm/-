#include <iostream>
#include <string>
using namespace std;

string s;
int size;

int calc(int pos){
    if(s[pos]=='1'){
        if(++pos<size&&s[pos]=='0'&&++pos<size&&s[pos]=='0'){
            while(++pos<size&&s[pos]=='0');
            if(pos<size){
                int count=0;
                while(++pos<size&&s[pos]=='1') {count++;}
                if(pos>=size) return 1;
                if(++pos<size&&s[pos]=='1'){
                    return calc(pos-1);
                }else if(pos<size&&s[pos]=='0'&&count!=0){
                    return calc(pos-2);
                }
            }
        }
    }else{
        if(++pos<size&&s[pos]=='1'){
            if(++pos>=size) return 1;
            return calc(pos);
        }
    }
    
    return 0;
}
int main() {
    int t;
    cin>>t;
    
    for(int i=0; i<t; i++){
        cin>>s;
        size = s.size();
        if(calc(0)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    
    return 0;
}