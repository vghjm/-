#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
 
 
typedef struct Node //��� ����
{
    int data;
    struct Node *next;
}Node;
 
typedef struct Stack //Stack ����ü ����
{
    Node *top;    //�� �� ���(���� �ֱٿ� ������ ���)
}Stack;
 
void InitStack(Stack *stack);//���� �ʱ�ȭ
int IsEmpty(Stack *stack); //������ ������� Ȯ��
void Push(Stack *stack, int data); //���ÿ� ����
int Pop(Stack *stack); //���ÿ��� ����
 
int main(void)
{
    char str[100];
    Stack stack;
    int fail = 0;
    int first = 1;
    
    InitStack(&stack);
    while(gets(str)){
        //printf("\nScript: %s\n", str);
        for(int i=0; i<100; i++){
            if(str[i]=='.'){
                //printf("find .\n");
                //printf(">find . isEmpty: %d, fail: %d, i=%d\n", IsEmpty(&stack), fail, i);
                
                if(!first){
                    printf("\n");
                }else {
                    first = 0;
                }
                if(i==0){
                    //printf("End Function");
                    return 0;
                }
                if(IsEmpty(&stack) && fail==0){
                    printf("yes");
                }else {
                    printf("no");
                }
                
                
                
                InitStack(&stack);
                fail = 0;
                break;
            }else if(str[i]=='('){
                //printf(">find ( i=%d\n", i);
                Push(&stack, 1);
            }else if(str[i]==')'){
                //printf(">find ) i=%d\n", i);
                if(IsEmpty(&stack)||Pop(&stack) != 1){
                    fail = 1;
                }
            }else if(str[i]=='['){
                //printf(">find [ i=%d\n", i);
                Push(&stack, 2);
            }else if(str[i]==']'){
                //printf(">find ] i=%d\n", i);
                if(IsEmpty(&stack)||Pop(&stack) != 2){
                    fail = 1;
                }
            }
        }
    }
    
    return 0;
}
void InitStack(Stack *stack)
{
    stack->top = NULL; //���� �ʱ�ȭ������ top�� NULL�� ����
    while(!IsEmpty(stack)){
        Pop(stack);
    }
}
 
int IsEmpty(Stack *stack)
{
    return stack->top == NULL;    //top�� NULL�̸� �� ����    
}
void Push(Stack *stack, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //��� ����
    now->data = data;//������ ����
    now->next = stack->top;//now�� next��ũ�� ���� top���� ����   
    stack->top = now;   //������ �� ���� now�� ����
}
int Pop(Stack *stack)
{
    Node *now;
    int re;
    if (IsEmpty(stack))
    {
        return 0;
    }
    now = stack->top;//now�� top���� ����
    re = now->data;//���� ���� now�� data�� ����
 
    stack->top = now->next;//top�� now�� next�� ����
    free(now);//�ʿ������ �޸� ����
    return re;
}