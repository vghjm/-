#include <iostream>
#include <vector>
using namespace std;
/* ��� ����ü */
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
    /* n*n ũ���� ��� a,b ���� */
    Mat a(n),b(n);
    /* ��� �Է� */
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            scanf("%lf", &a[i][j]);
    }
    // B�� ������ķ� ����
    b.setIdentity();
    for(int k=0; k<n; k++) {
        int t=k-1;
        while(t+1<n && !a[++t][k]);
        if(t==n-1 && !a[t][k]) { printf("no inverse"); return -1; }
        a.swapRow(k,t), b.swapRow(k,t);
        double d=a[k][k];
        /* k�� k���� �ش��ϴ� ���� k���� �� ���ڸ� ���� */
        for(int j=0; j<n; j++)
            a[k][j]/=d, b[k][j]/=d;
        /* k���� ������ �ٸ� �࿡ ���ڸ� ���ϰ� ���ϴ� ���� */
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

