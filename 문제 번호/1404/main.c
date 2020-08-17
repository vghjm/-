#include <stdio.h>

int arr[8][8];
int prob[4][8];
double ans[8];

int main(void) {
    for(int i=0; i<8; i++){
        int temp;
        arr[i][i] = 100;
        for(int j=i+1; j<8; j++){
            scanf("%d",&temp);
            arr[i][j] = temp;
            arr[j][i] = 100-temp;
        }
    }
    /*
    printf("arr\n");
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    */
    
    //round 1
    for(int i=0; i<4; i++){
        prob[0][2*i] = arr[2*i][2*i+1];
        prob[0][2*i+1] = arr[2*i+1][2*i];
    }
    /*
    printf("\nround 1\n");
    for(int i=0; i<8; i++){
        printf(" %4d ", prob[0][i]);
    }
    printf("\n");
    */
    //round 2
    for(int i=0; i<2; i++){
        prob[1][4*i+0] = prob[0][4*i+0] * (prob[0][4*i+2]*arr[4*i+0][4*i+2] + prob[0][4*i+3]*arr[4*i+0][4*i+3]);
        prob[1][4*i+1] = prob[0][4*i+1] * (prob[0][4*i+2]*arr[4*i+1][4*i+2] + prob[0][4*i+3]*arr[4*i+1][4*i+3]);
        prob[1][4*i+2] = prob[0][4*i+2] * (prob[0][4*i+0]*arr[4*i+2][4*i+0] + prob[0][4*i+1]*arr[4*i+2][4*i+1]);
        prob[1][4*i+3] = prob[0][4*i+3] * (prob[0][4*i+0]*arr[4*i+3][4*i+0] + prob[0][4*i+1]*arr[4*i+3][4*i+1]);
    }
    /*
    printf("\nround 2\n");
    for(int i=0; i<8; i++){
        printf(" %6d ", prob[1][i]);
    }
    printf("\n");
    */
    
    //round 3
    for(int i=0; i<4; i++){
        ans[i] = prob[1][i] * 0.00000000000001 * (
                            prob[1][4] * arr[i][4] +
                            prob[1][5] * arr[i][5] +
                            prob[1][6] * arr[i][6] +
                            prob[1][7] * arr[i][7] );
    }
    for(int i=4; i<8; i++){
        ans[i] = prob[1][i] * 0.00000000000001 * (
                            prob[1][0] * arr[i][0] +
                            prob[1][1] * arr[i][1] +
                            prob[1][2] * arr[i][2] +
                            prob[1][3] * arr[i][3] );
    }
    
    
    //print
    for(int i=0; i<8; i++){
        //ans[i] = prob[2][i] / 1000000.0;
        printf("%.9f ", ans[i]);
    }
    
    
    
    
    
    
    return 0;
}