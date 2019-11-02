#include <iostream>
#include <stack>
using namespace std;

char input[31];
stack<int> st;
int top_value, sum;

bool is_valid(){
    stack<char> check_st;
    for(int i=0; i<31; i++){
        if(!input[i]) break;
        switch(input[i]){
            case '(': check_st.push(input[i]); break;
            case '[': check_st.push(input[i]); break;
            case ')':
                if(check_st.empty()) return 0;
                if(check_st.top()!='(') return 0;
                check_st.pop();
                break;
            case ']':
                if(check_st.empty()) return 0;
                if(check_st.top()!='[') return 0;
                check_st.pop();
                break;
        }
    }

    if(check_st.empty()){
        return 1;
    }
    return 0;
}

int main() {
    scanf("%s", input);
    if(!is_valid()){
        printf("0");
    }else{
        for(int i=0; i<31; i++){
            if(!input[i]) break;
            switch(input[i]){
                case '(': st.push(-2); break;
                case '[': st.push(-3); break;
                case ')': 
                    if(st.top()==-2){
                        sum = 1;
                    }else{
                        sum=0;
                        while((top_value=st.top())!=-2){
                            st.pop();
                            sum+=top_value;
                        }
                    }
                    st.pop();
                    st.push(sum*2);
                    break;
                    
                case ']':
                    if(st.top()==-3){
                        sum = 1;
                    }else{
                        sum=0;
                        while((top_value=st.top())!=-3){
                            st.pop();
                            sum+=top_value;
                        }
                    }
                    st.pop();
                    st.push(sum*3);
                    break;
            }
        }
        sum = 0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        printf("%d", sum);
    }
    
    return 0;
}