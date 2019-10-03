#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main() {
    char trans[]="__AB_C";
    int target[31];
    int my[31];
    int N, M;
    string str;
    cin>>N>>M>>str;
 
    //trans char to int
    for(int i=0; i<N; i++){
        switch(str[i]){
            case 'A': target[i] = 2; break;
            case 'B': target[i] = 3; break;
            case 'C': target[i] = 5; break;
        }
    }
    
    
    int bottom = 2;
    for(int i=N-1; i>0; i--){
        int tar = target[i];
        int other = 10-bottom-tar;
        
        if(tar!=bottom){
            int need_count = pow(2, i);
            if(M>=need_count){
                M-=need_count;
                bottom = other;
                my[i] = tar;
            }else{
                my[i] = bottom;
                int temp = i;
                while(temp--)
                    target[temp] = other;
            }
        }else{
            my[i] = tar;
        }
    }
    if(M){
        my[0] = target[0];
    }else{
        my[0] = bottom;
    }
    for(int i=0; i<N; i++){
        printf("%c", trans[my[i]]);
    }
    
    return 0;
}