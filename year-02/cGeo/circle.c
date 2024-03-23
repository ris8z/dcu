#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

#define H 101
#define W 101

int main(){

    char output[H][W];

    for( int i = 0; i < H; i++ )
    {
        for( int j = 0; j < W; j++ )
        {
            output[i][j] = ' ';
        }
    }
    
    float alfa;
    int count = 0;
    float x;
    float y;
    int xp;
    int yp;

    int r = 5;
    int xoffset = 8;

    for(alfa = 0; alfa < 2 * PI; alfa += 0.07){
        //each cicle print a point of the circle
        x = r * cos(alfa) + xoffset;
        y = r * sin(alfa);
        z = 0;
        xp = (int) x + (W / 2);
        yp = (int) y + (H / 2);
        output[yp][xp] = '#';
    }

    
    printf("\x1b[H");
    
    for( int i = 0; i < H; i++ )
    {
        for( int j = 0; j < W; j++)
        {
            if(i == H / 2 && j == W / 2){
            putchar('o');
            }
            else
            {
            putchar(output[i][j]);
            }
        }
        putchar('\n');
    }
    

    return 0;
}
