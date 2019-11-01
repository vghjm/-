#include <iostream>
#include <algorithm>
#include <stack>
#define MXSIZE 4097
using namespace std;

int T, S_m, S_c, S_i;
int arr[100001];
char code[MXSIZE];
int input[MXSIZE];
int link[MXSIZE];


int arr_point, code_point, input_point, line_count, max_code_point;

void Brainfuck(){
    char cd = code[code_point];
    
    switch(cd){
        case '-': arr[arr_point] = (arr[arr_point] - 1) < 0 ? 255 : arr[arr_point] - 1; break;
        case '+': arr[arr_point] = (arr[arr_point] + 1) % 256; break;
        case '<': arr_point = (arr_point - 1) < 0 ? S_m - 1 : arr_point - 1; break;
        case '>': arr_point = (arr_point + 1) % S_m; break;
        case '[':
            if(arr[arr_point]==0){
                code_point = link[code_point];
            }
            break;
        case ']':
            if(arr[arr_point]!=0){
                code_point = link[code_point];
            }
            break;
        case '.': break;
        case ',': arr[arr_point] = input_point >= S_i ? 255 : input[input_point++]; break;
    }
    code_point++;
    line_count++;
    max_code_point = code_point > max_code_point ? code_point : max_code_point;
}

int main() {
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d ", &S_m, &S_c, &S_i);
        fill(arr, arr+S_m, 0);
        fill(code, code+S_c, 0);
        fill(input, input+S_i, 0);
        fill(link, link+4096, 0);
        
        stack<int> st;
        for(int i=0; i<S_c; i++){
            scanf("%c", &code[i]);
            if(code[i]=='['){
                st.push(i);
            }else if(code[i]==']'){
                int temp = st.top();
                st.pop();
                link[i] = temp;
                link[temp] = i;
            }
        }
        getchar();
        
        for(int i=0; i<S_i; i++){
            scanf("%c", &input[i]);
        }
        getchar();
        
        arr_point=0; code_point=0; input_point=0; line_count=0; max_code_point=0;
        while(1){
            Brainfuck();
            if(line_count==50000000){
                printf("Loops %d %d\n", link[max_code_point], max_code_point);
                break;
            }
            if(code_point == S_c){
                printf("Terminates\n");
                break;
            }
        }
        
    }
    return 0;
}