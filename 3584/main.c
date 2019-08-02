#include <stdio.h>
#include <stdlib.h>

//void Printing_array(int *arr, int n, char *s);
//int Find_dept(int *tree, int index);
//int Find_anc_by_deptcmp(int *tree, int *dept, int a, int b);

//int test_mode_on = 0;
int tree_m[10001];
int dept_m[10001];
/*
void Print(int n){
    printf("\n Tree \n");
    for(int i=1; i<n+1; i++){
        printf(" %d ", tree_m[i]);
    }
    printf("\n Dept \n");
    for(int i=1; i<n+1; i++){
        printf(" %d ", dept_m[i]);
    }
    printf("\n");
}
*/

int main(void) {
    int test_case;
    int node_n;
    int a, b;
    //int *tree, *dept;
    int ans;
    int first=1;
    
    scanf("%d", &test_case);
    for(int k=0; k<test_case; k++){
        //Init - make empty tree
        scanf("%d", &node_n);
        for(int i=0; i<10001; i++){
            tree_m[i]= 0;
            dept_m[i]=0;
        }
        //if(test_mode_on) printf("node_n= %d\n", node_n);
        //tree = (int *)malloc(sizeof(int) * (node_n+1));
        //dept = (int *)malloc(sizeof(int) * (node_n+1));
        
        //Init - allocate
        //printf("test case %d, n  %d", test_case, node_n);
        
        for(int i=0; i<node_n-1; i++){
            scanf("%d %d", &a, &b);
            //if(test_mode_on) printf("up= %d, down= %d\n", a, b);
            tree_m[b] = a;
        }
        //if(test_mode_on) Printing_array(tree, node_n, "tree");
        
        //Init - calc dept
        for(int i=1; i<node_n+1; i++){
            //dept[i] = Find_dept(tree, i);
            int p = i;
            int d = 1;
            while(tree_m[p]!=0){
                p=tree_m[p];
                d++;
            }
            dept_m[i]=d;
        }
        //if(test_mode_on) Printing_array(dept, node_n, "dept");
        //Print(node_n);
        
        //Calc
        scanf("%d %d", &a, &b);
        //if(test_mode_on) printf("\ninput: %d, %d\n", a, b);
        //ans = Find_anc_by_deptcmp(tree, dept, a, b);
        //printf("find %d %d\n", a ,b);
        
        while(a!=b){
            if(dept_m[a] >= dept_m[b]){
                a=tree_m[a];
            }else {
                b=tree_m[b];
            }
        }
        
        if(!first) printf("\n");
        printf("%d", a);
        /*
        ans = a;
        //if(test_mode_on){
        //    printf("\nans: %d\n");    
        //}else {
            if(!first) printf("\n");
            printf("%d", ans);
        //}
        //free(tree);
        //free(dept);
        */
        first=0;
        
    }//end for
    
    return 0;
}
/*
void Printing_array(int *arr, int n, char *s){
    printf("\n show %s \n", s);
    for(int i=1; i<n+1; i++){
        printf(" %d ", arr[i]);
    }
    printf("\n -------------\n");
}
*/
/*
int Find_dept(int *tree, int index){
    if(tree[index]==0) return 1;
    return Find_dept(tree, tree[index]) + 1;
}
int Find_anc_by_deptcmp(int *tree, int *dept, int a, int b){
    if(a == b){
        //if(test_mode_on) printf("\n find %d\n", a);
        return a;    
    }else if(dept[a] >= dept[b]){
        //if(test_mode_on) printf("\ndept[%d] >= dept[%d] / %d >= %d\n", a, b, dept[a], dept[b]);
        return Find_anc_by_deptcmp(tree, dept, tree[a], b);
    }else if(dept[a] < dept[b]){
        //if(test_mode_on) printf("\ndept[%d] < dept[%d] / %d < %d\n", a, b, dept[a], dept[b]);
        return Find_anc_by_deptcmp(tree, dept, a, tree[b]);    
    } 
}
*/




