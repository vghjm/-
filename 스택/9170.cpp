#include <iostream>
#include <string>
#include <cctype>
#include <stack>
using namespace std;

string s;

int calc(){
    stack<int> var, op;
    while(!s.empty()){
        switch(s.back()){
            case ')': s.pop_back(); var.push(calc()); break;
            case '(': 
                s.pop_back();
                while(!op.empty()){
                    int a = var.top();
                    var.pop();
                    int b = var.top();
                    var.pop();
                    if(op.top() > 0){
                        var.push(a+b);
                    }else{
                        var.push(a-b);
                    }
                    op.pop();
                }
                return var.top();
            case '+': 
                s.pop_back();
                if(s.back()!='('){
                    op.push(1);
                }
                break;
            case '-':
                s.pop_back();
                if(s.back()!='('){
                    op.push(-1);
                }else{
                    int temp = var.top();
                    var.pop();
                    var.push(temp * -1);
                }
                break;
            default : var.push(s.back()-'0'); s.pop_back();
        }
    }
    
    while(!op.empty()){
        int a = var.top();
        var.pop();
        int b = var.top();
        var.pop();
        if(op.top() > 0){
            var.push(a+b);
        }else{
            var.push(a-b);
        }
        op.pop();
    }
    return var.top();
}


int main() {
    while(1){
        cin>>s;
        if(s.empty()) break;
        string k = s;
        //printf("%s = %d\n", k.c_str(), calc());
        printf("%d\n", calc());
    }
    
    return 0;
}