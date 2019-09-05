#include <stdio.h>
#include <string.h>

short cnt16[256] = {
	0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
	4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
};

int bitCount(unsigned long long n){
	return cnt16[n & 0xffu] + cnt16[(n>>8) & 0xffu] + cnt16[(n>>16) & 0xffu] + cnt16[(n>>24) & 0xffu]
	+ cnt16[(n>>32) & 0xffu] + cnt16[(n>>40) & 0xffu] + cnt16[(n>>48) & 0xffu] + cnt16[(n>>56) & 0xffu];	
}


int main(void) {
    unsigned long long arr[2][3125];
    char ch;
    int count[2]={0, 0}, size[2]={0, 0};
    for(int i=0; i<2; i++){
        while((ch=getchar())!='\n'){
            arr[i][size[i]] = arr[i][size[i]]<<1;
            if(ch=='1')
                arr[i][size[i]]+=1;
            count[i]++;
            if(count[i]>=64){
                size[i]++;
                count[i]=0;
            }
        }
        arr[i][size[i]] = arr[i][size[i]] << (64-count[i]);
    }
    

    int Q;
    scanf("%d", &Q);
    while(Q--){
        int p1, p2, l, count=0;
        scanf("%d %d %d", &p1, &p2, &l);
        int pos[2] = {p1/64, p2/64};
        int res[2] = {p1%64, p2%64};
        int pos_end[2] = {(p1+l)/64, (p2+l)/64};
        int res_end[2] = {(p1+l)%64, (p2+l)%64};
        
        unsigned long long temp[2] = {0, 0};
        if((pos[0]==pos_end[0]) &&(pos[1]==pos_end[1])){
            //1th
            for(int i=0; i<2; i++){
                temp[i] = (arr[i][pos[i]] << res[i]) >> (64 - l);
            }
            count += bitCount(temp[0]^temp[1]);
        }else if((pos[0]!=pos_end[0]) && (pos[1]!=pos_end[1])){
            //2th
            int big=0, small=1;
            if(res[0]<res[1]){
                big = 1; small = 0;
            }
            temp[big] = (arr[big][pos[big]] << res[big]) >> res[big];
            temp[small] = (arr[small][pos[small]] << res[small]) >> res[big];
            count += bitCount(temp[big]^temp[small]);
            
            for(int i=1; i<pos_end[big]-pos[big]; i++){
                temp[big] = arr[big][pos[big]+i];
                temp[small] = (arr[small][pos[small]+i-1] << (64 - res[big] + res[small])) | (arr[small][pos[small]+i] >> (res[big] - res[small]));
                count += bitCount(temp[big]^temp[small]);
            }
            
            temp[big] = (arr[big][pos_end[big]] >> (64-res_end[big]));
            temp[small] = ((arr[small][pos_end[small]-1] << (64 - res[big] + res[small])) >> (64 - res_end[big])) | (arr[small][pos_end[small]] >> (64 - res_end[small]));
            count += bitCount(temp[big]^temp[small]);
            
        }else{
            //3th
            int a=0, b=1;
            if(pos[1]!=pos_end[1]){
                a=1; b=0;
            }
            temp[a] = ((arr[a][pos[a]] << res[a]) >>  64 - l)| (arr[a][pos_end[a]] >>(64-res_end[a]));
            temp[b] = ((arr[b][pos[b]] << res[b]) >> (res[b] + 64 - res_end[b]));
            count += bitCount(temp[a]^temp[b]);
        }
        
        printf("%d\n", count);
    }
    
        
    return 0;
}