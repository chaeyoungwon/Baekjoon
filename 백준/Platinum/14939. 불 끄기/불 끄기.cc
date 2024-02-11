#include <iostream>
using namespace std;

int num = 1000;                 
bool state[10][10];             
bool fixedState[10][10];        

void click(int row, int col)    
{
    state[row][col] = !state[row][col];
    if(row-1 >= 0) state[row-1][col] = !state[row-1][col];
    if(row+1 < 10) state[row+1][col] = !state[row+1][col];
    if(col-1 >= 0) state[row][col-1] = !state[row][col-1];
    if(col+1 < 10) state[row][col+1] = !state[row][col+1];
}

int check()                                       
{
    int temp = 0;
    for(int r = 1 ; r < 10 ; r++){
        for(int c = 0 ; c < 10 ; c++){
            if(state[r-1][c])                       
            {
                click(r, c);
                temp++;
            }
        }
    }
    for(int r = 0 ; r < 10 ; r++){
        for(int c = 0 ; c < 10 ; c++){
            if(state[r][c] == true) return 1000;   
        }
    }
    return temp;
}

int main(void){
    char temp;
    for(int r = 0 ; r < 10 ; r++){
        for(int c = 0 ; c < 10 ; c++){
            cin >> temp;
            if(temp == 'O') fixedState[r][c] = true;        
        }
    }
    for(int p = 0 ; p < 1024 ; p++){                                                      
        for(int r = 0 ; r < 10 ; r++){
            for(int c = 0 ; c < 10 ; c++){
                state[r][c] = fixedState[r][c];
            }
        }
        int ret = 0;
        for(int i = 0 ; i < 10 ; i++){
            if(p & (1 << i)){   
                ret++;                                     
                click(0, i);
            }
        }
        ret += check();                                 
        if(ret < num) num = ret;                            
    }

    cout << (num == 1000 ? -1 : num) << '\n';               
}