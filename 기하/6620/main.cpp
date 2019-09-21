#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int in_range(int a, int b, int a1, int b1){
    return (a1<=a&&b<=b1)||(a<=a1&&a1<=b)||(a<=b1&&b1<=b);
}

struct line{
    float A, B;
    int X1, Y1, X2, Y2;
    int vertical;
    line(int x1, int y1, int x2, int y2): X1(x1), Y1(y1), X2(x2), Y2(y2){
        if(x1 == x2){
            vertical = 1;
            A = numeric_limits<float>::max();
            B = x1;
        }else {
            vertical = 0;
            A = (float) (y2 - y1) / (x2 - x1);
            B = y1 - A*x1;
        }
        if(y1 > y2){
            Y1 = y2; Y2 = y1;
        }
        if(x1 > x2){
            X1 = x2; X2 = x1;
        }
    }
    int intersect(line *l) {
        int x1 = l->X1, y1 = l->Y1, x2 = l->X2, y2 = l->Y2;
        float a = l->A, b = l->B;
        if(!(in_range(X1, X2, x1, x2)&&in_range(Y1, Y2, y1, y2))) return 0;
        if(A==a){
            if(B==b){
                if(vertical){
                    return in_range(Y1, Y2, y1, y2);
                }else{
                    return 1;
                }
            }else {
                return 0;
            }
        }else if(vertical||l->vertical){
            float y;
            if(vertical){
                y = a*X1+b; // (X1, y)
                if(Y1<y&&y<Y2&&x1<X1&&X1<x2) return 1;
                return 0;
            }else{
                y = A*x1+B; // (x1, y)
                if(y1<y&&y<y2&&X1<x1&&x1<X2) return 1;
                return 0;
            }
        }else {
            float x = (B-b) / (a-A); //(x, ~)
            if(X1<x&&x<X2&&x1<x&&x<x2) return 1;
            return 0;
        }
    }
};

int main() {
    int N;
    while(1){
        scanf("%d", &N);
        if(!N) break;
        
        int simple = 1;
        vector<line*> L;
        int xf, yf;
        scanf("%d %d", &xf, &yf);
        int x1 = xf, y1 = yf;
        for(int i=1; i<N; i++){
            int x2, y2;
            scanf("%d %d", &x2, &y2);
            L.push_back(new line(x1, y1, x2, y2));
            x1 = x2; y1 = y2;
        }
        L.push_back(new line(x1, y1, xf, yf));
        //printf("%f ", L[N-1]->a);
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                if(L[i]->intersect(L[j])){
                    simple = 0;
                    break;
                }
            }
            if(!simple) break;
        }
        
        if(simple){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}















