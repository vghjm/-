#include <iostream>
#include <stack>
#include <vector>
using namespace std;

char input[100];
vector<char> output;
stack<char> st;

int op_priority(char op){
    if(op=='+'||op=='-') return 1;
    if(op=='*'||op=='/') return 2;
    if(op=='(') return 0;
    return -1;
}

int main() {
    scanf("%s", input);
    
    for(int i=0; i<100; i++){
        if(!input[i]) break;
        if(input[i]>='A'){
            output.push_back(input[i]);
        }else{
            if(input[i]==')'){
                char temp;
                while((temp = st.top())!='('){
                    st.pop();
                    output.push_back(temp);
                }
                st.pop();
            }else{
                if(st.empty()||input[i]=='('){
                    st.push(input[i]);
                }else{
                    int top_p, now_p = op_priority(input[i]);
                    while(!st.empty()){
                        top_p = op_priority(st.top());
                        if(now_p <= top_p){
                            output.push_back(st.top());
                            st.pop();
                        }else{
                            st.push(input[i]);
                            break;
                        }
                    }
                    if(st.empty()) st.push(input[i]);
                }
            }
        }
    }
    
    while(!st.empty()){
        output.push_back(st.top());
        st.pop();
    }
    
    for(char c : output){
        printf("%c", c);
    }
    
    return 0;
}