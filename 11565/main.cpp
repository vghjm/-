#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string A, B;
int parity(){
    int rtn=0;
    for(int i=0; i<A.size(); i++){
        if(A[i]=='1') rtn=!rtn;
    }
    return rtn;
}

int main() {
    
    cin >> A >> B;
    
    int size_a = A.size();
    int size_b = B.size();
    
    
    int count_a = 0, count_b = 0;
    if(parity()){
        count_a++;
    }
    
    int S_a=0, End=0, S_b=0;
    for(int i=S_a; i<size_a; i++){
        if(A[i]=='1') count_a++;
    }
    for(int i=S_b; i<size_b; i++){
        if(B[i]=='1') count_b++;
    }
    if(count_a < count_b) End++;
    
    if(End){
        printf("DEFEAT");
    }else{
        printf("VICTORY");
    }
    
    
    return 0;
}