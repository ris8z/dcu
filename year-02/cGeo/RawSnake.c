#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 10
#define COL 20

char grid[ROW][COL];

typedef struct snake snake;
typedef struct apple apple;

struct snake{
    int x;
    int y;
    snake* next;
};

struct apple{
    int x;
    int y;
};


snake* Snake = NULL;
apple Apple;
int SCORE = 0;

void clear_grid();
void display_grid();

void init_Snake();
void increase_Snake(int x, int y);
void draw_Snake();

void generate_random_apple();
void draw_Apple();
void get_move();
int check_collsion(snake* node, int x, int y);

int main(void){
    srand(time(NULL));
    init_Snake();
    generate_random_apple();

    while(1){
        clear_grid();
        draw_Snake();
        draw_Apple();
        display_grid();
        get_move();
    }

    return 0;
}

void clear_grid(){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            grid[i][j] = ' ';
        }
    }
}

void display_grid(){
    printf("\x1b[H");

    printf("\033[0;31m");
    printf("CURRENT SCORE: %d\n",  SCORE);
    printf("\033[0m");
    for(int i = 0; i < ROW + 2; i++){
        for(int j = 0; j < COL + 2; j++){
            if(i == 0 || i == ROW + 1){
                printf("-");
                continue;
            }

            if(j == 0 || j == COL + 1){
                printf("|");
                continue;
            }

            if(grid[i - 1][j - 1] == '0')
                printf("\033[0;31m");
            
            if(grid[i - 1][j - 1] == '1')
                printf("\033[0;32m");


            printf("%c", grid[i - 1][j - 1]);
            printf("\033[0m"); 
        }

        printf("\n");
    }
}

void init_Snake(){
    Snake = malloc(sizeof(Snake));
    Snake -> x = rand() % COL;
    Snake -> y = rand() % ROW;
    Snake -> next = NULL;
}

void increase_Snake(int x, int y){
    snake* new_head = malloc(sizeof(snake));
    new_head -> x = x;
    new_head -> y = y;
    new_head -> next = Snake;
    Snake = new_head;
}

void draw_Snake(){
    snake *tmp = Snake;
    while(tmp){
        grid[tmp -> y][tmp -> x] = '1';
        tmp = tmp -> next;
    }
}

void generate_random_apple(){
    do{
        Apple.x = rand() % COL;
        Apple.y = rand() % ROW;
    }while(grid[Apple.y][Apple.x] == '1');
}

void draw_Apple(){
    grid[Apple.y][Apple.x] = '0';
}

void move(snake* node, int x, int y){
    if(node){
        move(node -> next, node -> x, node -> y);
        node -> x = x;
        node -> y = y;
    }
}

void get_move(){
    char tmp = getchar();
    int next_x = Snake -> x;
    int next_y = Snake -> y;

    switch (tmp)
    {
    case 'w':
        next_y = (Snake -> y - 1 + ROW) % ROW;
        break;
    case 's':
        next_y =  (Snake -> y + 1) % ROW;       
        break;
    case 'a':
        next_x = (Snake  -> x - 1 + COL) % COL;
        break;
    case 'd':
        next_x = (Snake -> x + 1) % COL;
        break;
    default:
        return;
    }


    if(check_collsion(Snake, next_x, next_y) == 1){
        printf("\x1b[H");
        printf("\033[0;31m");
        printf("GAME OVER FINAL SCORE: %d\n",  SCORE);
        printf("\033[0m");
        exit(0);
    }

    if(next_x == Apple.x && next_y == Apple.y){
        increase_Snake(next_x, next_y);
        generate_random_apple();
        SCORE += 10;
        return;
    }
        
    move(Snake, next_x, next_y);
}

int check_collsion(snake* node, int x, int y){
    if(node){
        if(node -> x == x && node -> y == y){
            return 1;
        }
        return check_collsion(node -> next, x, y);
    }else{
        return -1;
    }
}
