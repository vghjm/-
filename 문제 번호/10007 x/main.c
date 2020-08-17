#include <stdio.h>
#include <malloc.h>
#include <float.h>

int K;
int N;
int ans[1000];
int count;

typedef struct Node {
    float value;
    int state;
    struct Node *next;
} Node;

Node *head, *tail, *mid;
float pivot;

int main(void) {
    scanf("%d %d", &K, &N);
    head = (Node*)malloc(sizeof(Node));
    tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    mid = tail;
    pivot = FLT_MAX;
    for(int i=0; i<N; i++){
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(y1*x2 > y2*x1){
            //insert_next((float) y2 / x2, (float) y1 / x1);
            Node *a, *temp;
            float v1=(float)y2/x2, v2=(float)y1/x1;
            a = (Node*)malloc(sizeof(Node));
            a->value = v1;
            a->state = 0;
            if(v1>pivot){
                temp=mid;
            }else {
                temp=head;
                mid = a;
                pivot = v1;
            }
            while(temp->next!=tail && temp->next->value <= v1){
                temp=temp->next;
            }
            a->next=temp->next;
            temp->next = a;
            a=(Node*)malloc(sizeof(Node));
            a->value=v2;
            a->state = 1;
            while(temp->next!=tail && temp->next->value <= v2){
                temp=temp->next;
            }
            a->next=temp->next;
            temp->next = a;
        }else {
            Node *a, *temp=head;
            float v1=(float)y1/x1, v2=(float)y2/x2;
            a = (Node*)malloc(sizeof(Node));
            a->value = v1;
            a->state = 0;
            if(v1>pivot){
                temp=mid;
            }else {
                temp=head;
                mid = a;
                pivot = v1;
            }
            while(temp->next!=tail && temp->next->value <= v1){
                temp=temp->next;
            }
            a->next=temp->next;
            temp->next = a;
            a=(Node*)malloc(sizeof(Node));
            a->value=v2;
            a->state = 1;
            while(temp->next!=tail && temp->next->value <= v2){
                temp=temp->next;
            }
            a->next=temp->next;
            temp->next = a;
        }
    }
    /*
    for(int i=0; i<N; i++){
        printf("%dth-line %f ~ %f\n", i+1, arr[0][i], arr[1][i]);
    }
    printf("\n");
    */
    
    Node *temp=head;
    int level=0, max=0;
    count = 0;
    while(temp->next!=tail){
        if(temp->next->state==0){
            //printf("op(%2.2f) ", temp->next->value);
            level++;
            if(level>max) max=level;
        }else {
            //printf("cl(%2.2f) ", temp->next->value);
            level--;
            if(level==0){
                ans[count] = max;
                count++;
                max = 0;
            }
        }
        temp=temp->next;
    }
    //printf("\n");
    
    /*
    printf("ans\n");
    for(int i=0; i<count; i++){
        printf(" %d ", ans[i]);
    }
    printf("\n");
    */
    int d=0;
    for(int i=0; i<K; i++){
        int max = -1, pos=-1;
        for(int i=0; i<count; i++){
            if(ans[i] > max){
                max=ans[i];
                pos=i;
            }
        }
        if(pos==-1){
            max = 0;
        }else{
            ans[pos] = -2;
        }
        d+=max;
    }
    printf("%d", d);

    //end();
    return 0;
}


















