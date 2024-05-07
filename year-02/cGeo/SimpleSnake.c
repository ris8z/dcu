#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//define
#define ROW 10
#define COL 20

//structs
struct snake{
    int r;
    int c;
    struct snake* next;
};

struct apple{
    int r;
    int c;
};

//typedefs
typedef struct snake snake;
typedef struct apple apple;

//global vars
char grid[ROW][COL];
int score = 0;
snake* Snake = NULL;
apple Apple;

//functions
void clear_grid();
void display_grid();
void display_score();
void init_snake();
void increase_snake();
void move_snake(snake* node, int r, int c);
void draw_snake();
void generate_random_apple();
void draw_apple();
int get_next_move_cord(int output[2]);
int check_collision(snake* node, int r, int c);
void game_over();

int main(void)
{
    int newRC[2] = {0};// 0 -> row, 1 -> col
    int r,c;
    srand(time(NULL));

    init_snake();
    generate_random_apple();

    while(1)
    {
        //printf("diocae %d %d\n", Snake -> r, Snake -> c);
        clear_grid();
        draw_snake();
        draw_apple();
        display_grid();
        
        if(get_next_move_cord(newRC) == -1)
            continue;
        
        //printf("ci arrivo seee\n");
        r = newRC[0];
        c = newRC[1];

        if(check_collision(Snake, r, c) == 1)
        {
            game_over();
        }

        if(r == Apple.r && c == Apple.c)
        {
            increase_snake(r, c);
            generate_random_apple();
            score += 10;
            continue;
        }
        
        move_snake(Snake, r, c);
    }

    return 0;
}

void clear_grid()
{
    for(int i = 0; i < ROW; i++)
        for(int j = 0; j < COL; j++)
            grid[i][j] = ' ';
}

void display_grid()
{
    printf("\x1b[H"); //clear the screen
    display_score();
    for(int i = 0; i < ROW + 2; i++)
    {
        for(int j = 0; j < COL + 2; j++)
        {
            if(i == 0 || i == ROW + 1)
            {
                printf("-");
                continue;
            }
            if(j == 0 || j == COL + 1)
            {
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

void display_score()
{
    printf("\033[0;31m");
    printf("CURRENT SCORE: %d\n", score);
    printf("\033[0m");
}


void init_snake()
{
    Snake = malloc(sizeof(Snake));
    if(!Snake)
    {
        printf("Memory allocation error");
        exit(0);
    }
    Snake -> r = rand() % ROW;
    Snake -> c = rand() % COL;
    Snake -> next = NULL;
}

void increase_snake(int r, int c)
{
    snake* new_head = malloc(sizeof(snake));
    if(!new_head)
    {
        printf("Memory allocation error");
        exit(0);
    }
    new_head -> r = r;
    new_head -> c = c;
    new_head -> next = Snake;
    Snake = new_head;
}

void move_snake(snake* node, int r, int c)
{
    if(!node)
        return;
    move_snake(node -> next, node -> r, node -> c);
    node -> r = r;
    node -> c = c;
}

void draw_snake()
{
    snake *tmp = Snake;
    while(tmp)
    {
        grid[tmp -> r][tmp -> c] = '1';
        tmp = tmp -> next;
    }
}

void generate_random_apple()
{
    do
    {
        Apple.r = rand() % ROW;
        Apple.c = rand() % COL;
    }while(grid[Apple.r][Apple.c] == '1');
}

void draw_apple()
{
    grid[Apple.r][Apple.c] = '0';
}

int get_next_move_cord(int output[2])
{
    int nextRow = Snake -> r;
    int nextCol = Snake -> c;
    char tmp = getchar();
    switch(tmp)
    {
        case 'w':
            nextRow = (Snake -> r - 1 + ROW) % ROW;
            break;
        case 's':
            nextRow = (Snake -> r + 1) % ROW;
            break;
        case 'a':
            nextCol = (Snake -> c - 1 + COL) % COL;
            break;
        case 'd':
            nextCol = (Snake -> c + 1) % COL;
            break;
        default:
            return -1;
    }
    output[0] = nextRow;
    output[1] = nextCol;
    return 1;
}

int check_collision(snake* node, int r, int c)
{
    if(!node)
        return -1;
    if(node -> r == r && node -> c == c)
        return 1;
    return check_collision(node -> next, r, c);
}

void game_over()
{
    printf("\x1b[H");
    printf("\033[0;31m");
    printf("GAME OVER FINAL SCORE: %d\n", score);
    printf("\033[0m");
    exit(0);
}
