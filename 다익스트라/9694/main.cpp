#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct data{
    int  now, cost, last;
    vector<int> pre;
    data(int n1, int c1, int l1): now(n1), cost(c1), last(l1) {}
    data* descendant(int to, int c){
        data* temp = new data(to, this->cost+c, c);
        temp->pre.assign(this->pre.begin(), this->pre.end());
        return temp;
    }
};

bool comp(data* a, data* b){
    int a_ = a->cost;
    int b_ = b->cost;
    if(a_==b_){
        return a->last < b->last;
    }else{
        return a_ < b_;
    }
    
}
struct tree{
    int to, cost;
    tree(int t1, int c1): to(t1), cost(c1) {}
};


int main() {
    int N, M, T;
    scanf("%d", &T);
    for(int test_case = 1; test_case<=T; test_case++){
        scanf("%d%d", &N, &M);
        vector<tree*> rel[20];
        vector<data*> end_list;
        queue<data*> q;
        for(int i=0; i<N; i++){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            rel[a].push_back(new tree(b, c));
            rel[b].push_back(new tree(a, c));
        }
        
        int max = 4*M;
        q.push(new data(0, 0, 0));
        while(!q.empty()){
            data *curr = q.front();
            q.pop();
            curr->pre.push_back(curr->now);
            
            for(tree* t: rel[curr->now]){
                //printf("\nnow %d \n", curr->now);
                if(t->cost+curr->cost <= max){
                    q.push(curr->descendant(t->to, t->cost));
                }
                //printf("\t\tpush %d %d %d %d\n", t->to, node, t->cost+curr.cost, t->cost);
            }
            if(curr->now == M-1){
                end_list.push_back(curr);
                if(curr->cost < max) max = curr->cost;
                //printf("end: %d ", curr->cost);
            }else{
                delete curr;
            }
        }
        
        sort(end_list.begin(), end_list.end(), comp);
        printf("Case #%d:", test_case);
        if(end_list.size() > 0 ){
            vector<int> ans = end_list[0]->pre;
            for(int a: ans){
                printf(" %d", a);
            }
            //printf(" size:%d", ans.size());
        }else{
            printf(" -1");
        }
        
        printf("\n");
    }
    return 0;
}