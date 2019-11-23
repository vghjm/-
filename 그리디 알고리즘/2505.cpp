#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;

vector<int> v[2];
int n;

void my_swap(int d, int l, int r){
    stack<int> st;
    for(int i=l; i<=r; i++){
        st.push(v[d][i]);
    }
    for(int i=l; i<=r; i++){
        int temp = st.top();
        st.pop();
        v[d][i] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    v[0].resize(n+1); v[1].resize(n+1);
    // 입력 벡터 2개 준비
    for(int i=1; i<=n; i++){
        int t;
        scanf("%d", &t);
        v[0][i] = v[1][i] = t;
    }
    
    //1차 탐색, 왼쪽부터 부족한 작은 수를 채움
    int count=0;
    vector<pair<int, int>> ans;
    for(int i=1; i<=n; i++){
        if(v[0][i]!=i){
            int j=i;
            while(v[0][++j]!=i);
            my_swap(0, i, j);
            count++;
            ans.push_back(make_pair(i, j));
        }
        if(count>2) break;
    }
    
    //정답이 아닌경우, 2차 탐색, 오른쪽부터 부족한 큰 수를 채움
    if(count>2){
        count = 0;
        ans.clear();
        for(int i=n; i>=1; i--){
            if(v[1][i]!=i){
                int j=i;
                while(v[1][--j]!=i);
                my_swap(1, j, i);
                count++;
                ans.push_back(make_pair(j, i));
            }
            if(count>2) break;
        }
    }
    
    //정답 출력
    if(count==2){
        printf("%d %d\n", ans[0].first, ans[0].second);
        printf("%d %d", ans[1].first, ans[1].second);
    }else if(count==1){
        printf("%d %d\n", ans[0].first, ans[0].second);
        printf("1 1");
    }else if(count==0){
        printf("1 1\n1 1");
    }
    
    return 0;
}
















