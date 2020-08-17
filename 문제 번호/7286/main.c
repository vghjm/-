#include <stdio.h>
#define SIZE 1001
#define AlPHABET 26

int keyboard[SIZE][AlPHABET];
int k_size;
int tape[SIZE];
int t_size;

void print();
void toggle(char ch, int k);
void init();

int main(void) {
    int T;
    scanf("%d", &T);
    //printf("T: %d\n", T);
    for(int i=0; i<T; i++){
        int n;
        scanf("%d", &n);
        //printf("n: %d\n", n);
        init();
        k_size=n;
        for(int j=0; j<n; j++){
            int a, b;
            char ch[3];
            scanf("%s %d %d", ch, &a, &b);
            //printf("input: %c %d %d\n", ch[0], a, b);
            
            for(int k=a; k<b; k++){
                toggle(ch[0], k);
            }
        }
        
        /*test
        printf("\ntest\n");
        printf("ith ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
        for(int q=0; q<10; q++){
            printf("%d:  ", q);
            for(int w=0; w<26; w++){
                printf("%d", keyboard[q][w]);
            }
            printf("\n");
        }
        printf("End---------------------------------------\n");
        */
        
        print();
    }
    
    
    
    return 0;
}

void print(){
    for(int i=0; i<SIZE; i++){
        int sum=0;
        for(int j=0; j<AlPHABET; j++){
            sum+=keyboard[i][j];
        }
        
        if(sum!=0){
            tape[t_size] = sum;
            t_size++;
        }
    }
    //printf("\nAns\n>");
    for(int i=0; i<t_size; i++){
        printf("%c", tape[i]+64);
    }
    printf("\n");
}

void toggle(char ch, int k){
    if(keyboard[k][(int)ch-65]==0){
        keyboard[k][(int)ch-65] = 1; 
    }else {
        keyboard[k][(int)ch-65] = 0; 
    }
}

void init(){
    k_size = 0;
    t_size = 0;
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<AlPHABET; j++){
            keyboard[i][j] = 0;
        }
        tape[i] = 0;
    }
}