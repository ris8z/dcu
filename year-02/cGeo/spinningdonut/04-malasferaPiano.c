#include<stdio.h>
#include<math.h>

#define PI 3.141592653589793238462643383279502884197

#define w 101
#define h 51

char output[h][w];

void clear();
void plot(float x, float y, char c);
void display();

int main(void){
    //main equation x*x + y * y + z * z == 1
    float alfa, beta;
    float startX,startY,startZ;
    float circleX,circleY,circleZ;
    float x, y, z;
    float R1, R2;//R1 radius of the circle, R2 the distance between the origin and the centere of the circle

    R1 = 8;
    R2 = 12; //if r2 is = to 0 we build a sphere otherwise a torus

    startX = R1; startY = 0; startZ = 0;
    clear();

    for(alfa = 0; alfa < 2 * PI; alfa += 0.2){
        circleX = startX * cos(alfa) - startY * sin(alfa);
        circleY = startX * sin(alfa) + startY * cos(alfa);
        circleZ = startZ;

        circleX += R2;

        for(beta = 0; beta < 2 * PI; beta += 0.2){
            x = circleX * cos(beta) - circleZ * sin(beta);
            y = circleY;
            z = circleX * sin(beta) + circleZ * cos(beta);
            //printf("(%.2f,%.2f,%.2f) (1 == %.2f)\n", x, y, z, (x * x) + (y * y) + (z * z));
            plot(x,y,'#');
        }
    }

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