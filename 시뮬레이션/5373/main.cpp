#include <iostream>
using namespace std;

const char DIR_T[6]  = {'U', 'D', 'F', 'B', 'L', 'R'};
const char COLOR[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
const int DIR[6][8] = {
        { 0,  2,  4,  6,  1,  3,  5,  7},
        {18, 16, 14, 12, 17, 15, 13, 19},
        { 6,  4, 16, 18,  5, 10, 17, 11},
        {12, 14,  2,  0, 13,  9,  1,  8},
        { 0,  6, 18, 12,  7, 11, 19,  8},
        { 4,  2, 14, 16,  3,  9, 15, 10}
    };
const int DICE[6][4] = {
        {2, 4, 3, 5},
        {2, 5, 3, 4},
        {0, 5, 1, 4},
        {0, 4, 1, 5},
        {0, 2, 1, 3},
        {0, 3, 1, 2}
    };

struct Cube{
    char face[6];
    Cube(){
        for(int i=0; i<6; i++)
            face[i] = 'x';
    };
    void spin(int dir_number, int is_clockwise){
        if(is_clockwise){
            char temp = face[DICE[dir_number][3]];
            for(int i=3; i>0; i--)
                face[DICE[dir_number][i]] = face[DICE[dir_number][i-1]];
            face[DICE[dir_number][0]] = temp;
        }else {
            char temp = face[DICE[dir_number][0]];
            for(int i=0; i<3; i++)
                face[DICE[dir_number][i]] = face[DICE[dir_number][i+1]];
            face[DICE[dir_number][3]] = temp;
        }
    };
};

struct Cubing{
    Cube *cu[20];
    
    Cubing(){
        for(int i=0; i<20; i++)
            cu[i] = new Cube();
        for(int i=0; i<6; i++)
            for(int j : DIR[i])
                cu[j]->face[i] = COLOR[i];
    };
    void spin(int dir_number, int is_clockwise){
        if(is_clockwise){
            Cube *temp1 = cu[DIR[dir_number][3]];
            for(int i=3; i>0; i--)
                cu[DIR[dir_number][i]] = cu[DIR[dir_number][i-1]];
            cu[DIR[dir_number][0]] = temp1;
            Cube *temp2 = cu[DIR[dir_number][7]];
            for(int i=7; i>4; i--)
                cu[DIR[dir_number][i]] = cu[DIR[dir_number][i-1]];
            cu[DIR[dir_number][4]] = temp2;
            for(int i : DIR[dir_number])
                cu[i]->spin(dir_number, is_clockwise);
        }else {
            Cube *temp1 = cu[DIR[dir_number][0]];
            for(int i=0; i<3; i++)
                cu[DIR[dir_number][i]] = cu[DIR[dir_number][i+1]];
            cu[DIR[dir_number][3]] = temp1;
            Cube *temp2 = cu[DIR[dir_number][4]];
            for(int i=4; i<7; i++)
                cu[DIR[dir_number][i]] = cu[DIR[dir_number][i+1]];
            cu[DIR[dir_number][7]] = temp2;
            for(int i : DIR[dir_number])
                cu[i]->spin(dir_number, is_clockwise);
        }
    };
    void show(){
        printf("%c%c%c\n%c%c%c\n%c%c%c\n",
                cu[0]->face[0], cu[1]->face[0], cu[2]->face[0],
                cu[7]->face[0],       'w'     , cu[3]->face[0],
                cu[6]->face[0], cu[5]->face[0], cu[4]->face[0]);
    }
};

int main() {
    int T;
    scanf("%d", &T);
    Cubing cube;

    while(T--){
        int N;
        scanf("%d", &N);
        Cubing cube;
        
        while(N--){
            char dir, cl;
            cin >> dir >> cl;
            int dir_number, is_clockwise;
            if(cl=='+'){
                is_clockwise = 1;
            }else{
                is_clockwise = 0;
            }
            for(int i=0; i<6; i++)
                if(dir==DIR_T[i]) dir_number=i;
            cube.spin(dir_number, is_clockwise);
        }
        cube.show();
    }
    
    return 0;
}
