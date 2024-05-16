#include<stdio.h>
#define w 101
#define h 51

char output[h][w];

void clear();
void plot(float x, float y, char c);
void display();

int main(void){

    clear();
    plot(5,5, 'A');
    plot(-5,5, 'B');
    plot(-5,-5, 'C');
    plot(5,-5, 'D');
    plot(0,0, 'O');  
    display();


    return 0;
}


void clear(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            output[i][j] = ' ';
}

void plot(float x, float y, char c){
    output[-((int) y) + (h / 2)][(int) x + (w / 2)] = c;
}

void display(){
    printf("\x1b[H");
    for(int i = 0; i < h + 2; i++){
        for(int j = 0; j < w + 2; j++){

            if(i == 0 || i == (h + 1)){
                putchar('-');
                continue;
            }

            if(j == 0 || j == (w + 1)){
                putchar('|');
                continue;
            }

            if(output[i - 1][j - 1] != ' '){
                putchar(output[i - 1][j - 1]);
                continue;
            }
            
            if(i - 1 == (h / 2)){
                putchar('-');
                continue;
            }

            if(j - 1 == (w / 2)){
                putchar('|');
                continue;
            }

            putchar(output[i - 1][j - 1]);
        }
        putchar('\n');
    }
}