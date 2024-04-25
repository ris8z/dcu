#include<stdio.h>
#include<math.h>


#define ROW 20
#define COL 20

char grid[ROW][COL];

void init_grid();
void display_grid();

int main(void){
    



    return 0;
}
void init_grid(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            grid[i][j] = ' '; 
    }
}

void display_grid(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++)
            printf("%c", grid[i][j]);

        printf("\n");
    }
}
