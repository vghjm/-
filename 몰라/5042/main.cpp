#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int tree[2000];

int main() {
    int n, l, w;
    cin>>n>>l>>w;
    
    for(int i=0; i<n; i++){
        cin>>tree[i];
    }
    sort(tree, tree+n);
    long double dist = (long double)(2*l)/(long double)(n-2);
    long double ans=0.0f;
    //printf("%.10Lf\n", dist);
    for(int i=0; i<n/2; i++){
        long double case1, case2;
        case1 = sqrt(pow(abs((long double)tree[2*i]-(long double)i*dist), 2)+pow(w, 2))+abs((long double)tree[2*i+1]-(long double)i*dist);
        case2 = sqrt(pow(abs((long double)tree[2*i+1]-(long double)i*dist), 2)+pow(w, 2))+abs((long double)tree[2*i]-(long double)i*dist);
        if(case1<case2){
            ans+=case1;
        }else{
            ans+=case2;
        } 
        
    }
    
    printf("%.10Lf", ans);
    
    return 0;
}