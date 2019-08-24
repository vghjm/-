#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {false, true} bool;
bool check[10001];
int dist[10001];
int from[10001];
char how[10001];

typedef struct Node{
    short data;
    struct Node *next;
} Node;
typedef struct Queue{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue q;

void Init();
int IsEmpty();
void Enqueue(short data);
short Dequeue();

void print(int n, int m) {
	if (n == m) return;
	print(n, from[m]);
	printf("%c", how[m]);
}

int main(void) {
	int T;
	scanf("%d", &T);

	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
        Init();
		memset(check, false, sizeof(check));
		memset(dist, 0, sizeof(dist));
		memset(how, 0, sizeof(how));
		memset(from, 0, sizeof(from));

		check[a] = true;
		dist[a] = 0;
		from[a] = -1;
		Enqueue(a);
		
		while (!IsEmpty()){
			short now = Dequeue();
			
			short next = (now * 2) % 10000;
			if (check[next] == false) {
				Enqueue(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'D';
			}
			next = now ? now-1 : 9999;
			if (check[next] == false) {
				Enqueue(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'S';
			}
			next = (now % 1000) * 10 + now / 1000;
			if (check[next] == false) {
				Enqueue(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'L';
			}
			next = (now / 10) + (now % 10) * 1000;
			if (check[next] == false) {
				Enqueue(next);
				check[next] = true;
				dist[next] = dist[now] + 1;
				from[next] = now;
				how[next] = 'R';
			}
		}
		print(a, b);
		printf("\n");
	}

	return 0;
}

void Init(){
    q.head = q.tail = NULL;
    q.size = 0;
}
int IsEmpty(){
    return q.size == 0;
}
void Enqueue(short data){
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = data;
    now->next = NULL;
    if (IsEmpty()){
        q.head = now;
    }else {
        q.tail->next = now;
    }
    q.tail = now;  
    q.size++;
}
short Dequeue(){
    short re = -1;
    Node *now;

    if (IsEmpty()){
        return re;
    }
    now = q.head;
    re = now->data;
    q.head = now->next;
    free(now);
    q.size--;
    
    return re;
}
