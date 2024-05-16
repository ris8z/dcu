#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793238462643383279502884197

int main(void){
    //main equation x*x + y * y + z * z == 1
    float alfa, beta;
    float startX,startY,startZ;
    float circleX,circleY,circleZ;
    float x, y, z;
    float R1, R2;//R1 radius of the circle, R2 the distance between the origin and the centere of the circle

    R1 = 1;
    R2 = 0; //if r2 is = to 0 we build a sphere otherwise a torus

    startX = R1; startY = 0; startZ = 0;
    
    for(alfa = 0; alfa < 2 * PI; alfa += 0.2){
        circleX = startX * cos(alfa) - startY * sin(alfa);
        circleY = startX * sin(alfa) + startY * cos(alfa);
        circleZ = startZ;

        circleX += R2;

        for(beta = 0; beta < 2 * PI; beta += 0.2){
            x = circleX * cos(beta) - circleZ * sin(beta);
            y = circleY;
            z = circleX * sin(beta) + circleZ * cos(beta);
            printf("(%.2f,%.2f,%.2f) (1 == %.2f)\n", x, y, z, (x * x) + (y * y) + (z * z));
        }
    }
    return 0;
}