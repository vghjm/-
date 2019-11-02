#include <iostream>
#include <stack>
using namespace std;

int T;

int main() {
    scanf("%d", &T);
    while(T--){
        stack<char> st;
        char arr[51];
        scanf("%s", arr);
        for(int i=0; i<51; i++){
            if(!arr[i]){
                if(st.empty()){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
                break;
            }
            if(arr[i]=='('){
                st.push(arr[i]);
            }else{
                if(st.empty()){
                    printf("NO\n");
                    break;
                }
                st.pop();
            }
        }
    }
    return 0;
}