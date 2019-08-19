#include <stdio.h>
#include <math.h>
#include <ctype.h>


typedef int bool;
#define true 1
#define false 0

int A, B;
int arr[1000];
int size;

int divin(int n){
    int last[1200];
    int count=0;
    //bool is_sqrt=true;
    int rt=1;

    for(int i=2; i<=n; i++){
        if(n%i==0){
            last[count]=i;
            count++;
            n/=i;
            i=1;
        }
    }
    /*
    for(int i=0; i<count; i++){
        printf(" %d ", last[i]);
    }
    printf("\n");
    */
    for(int i=0; i<count; i++){
        if(i<count && last[i] != last[i+1]){
            //is_sqrt=false;
            rt*=last[i];
        }else{
            i++;
        }
    }
    return rt;
    //printf("rt: %d", rt);
}

int main(void) {
    /*
    scanf("%d%d", &a, &b);
    //printf("%d /  %f", (int)(sqrt(a*b)), sqrt(a*b));
    //if((int)(sqrt(a*b)) - sqrt(a*b) ==0.0) printf("\ndd");
    
    int count = 0;
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if((int)(sqrt(i*j)) - sqrt(i*j) ==0.0) count++;
            //if(isint(sqrt(i*j))) count++;
        }
    }
    printf("%d", count);
    */
    scanf("%d %d", &A, &B);
    if(A<B){
        int temp = A;
        A = B;
        B = temp;
    }
    //printf("A:%d, B:%d\n", A, B);
    for(size=1; size<=1000; size++){
        if(size*size<=A){
             arr[size-1]=size*size;
        }else{
            break;
        }
    }
    size--;
    /*
    printf("arr[%d]\n", size);
    for(int i=0; i<size; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n");
    */
    
    int count=0;
    int rt;
    for(int i=1; i<=B; i++){
        
        if((rt=divin(i))==1){
            count+=size;
        }else {
            for(int j=0; j<size; j++){
                if(arr[j]*rt <= A){
                    count++;
                }else{
                    break;
                }
            }
        }
        //printf("%d-th, count:%d, rt:%d, \n", i, count, rt);
    }
    
    //printf("\ndiv %d\n", divin(2));
    printf("%d", count);
    
    return 0;
}