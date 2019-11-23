#include <iostream>
#include <vector>
using namespace std;
/* 행렬 구조체 */
struct Mat {
    vector<vector<double>> data;
    Mat(int n) { data.resize(n, vector<double>(n,0)); }
    double* operator [] (int idx) {
        return &data[idx][0];
    }
    void swapRow(int i, int j) {
        if(i==j) return;
        for(int k=0;k<data.size();k++)
            swap(data[i][k], data[j][k]);
    }
    void setIdentity() {
        for(int i=0;i<data.size();i++)
            for(int j=0;j<data.size();j++)
                if(i==j) data[i][j]=1;
                else data[i][j]=0;
    }
};
int main() {
    int n;
    scanf("%d",&n);
    /* n*n 크기의 행렬 a,b 생성 */
    Mat a(n),b(n);
    /* 행렬 입력 */
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%lf", &a[i][j]);
    }
    // B는 단위행렬로 설정
    b.setIdentity();
    for(int k=0; k<n; k++) {
        int t=k-1;
        while(t+1<n && !a[++t][k]);
        if(t==n-1 && !a[t][k]) { printf("no inverse"); return -1; }
        a.swapRow(k,t), b.swapRow(k,t);
        double d=a[k][k];
        /* k행 k열에 해당하는 수로 k행의 각 숫자를 나눔 */
        for(int j=0; j<n; j++)
            a[k][j]/=d, b[k][j]/=d;
        /* k행을 제외한 다른 행에 숫자를 곱하고 더하는 과정 */
        for(int i=0; i<n; i++)
            if(i!=k) {
                double m = a[i][k];
                for(int j=0; j<n; j++) {
                    if(j>=k) a[i][j]-=a[k][j]*m;
                    b[i][j]-=b[k][j]*m;
                }
            }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            printf("%.6f ", b[i][j]);
        puts("");
    }
    return 0;
}

