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
    float beta;
    int count = 0;
    float x;
    float y;
    float z;
    int xp;
    int yp;

    int r = 5;
    int R;
    int xoffset = 10;
    
    float op = 15; // offset profondita'
    float df = 1.678; //distanza focale(coefficente di ingrandimento)
                                              //
                // xp = (df * x) / (z + op)
    printf("%f\n", df);

    for(alfa = 0; alfa < 2 * PI; alfa += 0.07){
        //each cicle print a point of the circle
        x = r * cos(alfa) + xoffset;
        y = r * sin(alfa);
        
        R = x;
        for(beta = 0; beta < 2 * PI; beta += 0.02){
            x = R * cos(beta);
            z = R * sin(beta);
            printf("(%.2f, %.2f, %.2f) alfa=%.2f ", x, y, z, alfa);
            xp = (int) (df * x) / (z + op) + (W / 2);
            yp = (int) (df * y) / (z + op) + (H / 2);
            printf("(%d,%d)\n", xp, yp);

            if((0 <= yp && yp < H) && (0 <= xp && xp < W))
                output[yp][xp] = '#';
        }

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
