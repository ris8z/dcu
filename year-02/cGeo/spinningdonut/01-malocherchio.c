//test for rotation on the z line to get a circle centred in xy origin with radius 1
#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793238462643383279502884197

int main(void){
    //main equation x*x + y*y = 1;
    float alfa;
    float startX,startY;
    float x,y;

    startX = 1; startY = 0;
    for(alfa = 0; alfa < 2 * PI; alfa += 0.2){
        x = startX * cos(alfa) - startY * sin(alfa);
        y = startX * sin(alfa) + startY * cos(alfa);

        printf("(%.2f,%.2f,0.00) (1 == %.2f)\n", x, y, (x * x) + (y * y));
    }
    return 0;
}