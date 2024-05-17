#include<stdio.h>
#include<math.h>
#include<unistd.h>

#define PI 3.141592653589793238462643383279502884197

#define w 100
#define h 50

char output[h][w];

void clear();
void plot(float x, float y, char c);
void display();

//da capire perche zprimo e' cosi grande nella mia mente dovrebbe essere piu' piccolo

int main(void){
    //main equation x*x + y * y + z * z == 1
    float alfa, beta;
    float startX,startY,startZ;
    float circleX,circleY,circleZ;
    float donutX, donutY, donutZ;
    float gammaX, gammaY, gammaZ;
    float x, y, z;
    float xPrimo, yPrimo, Zprimo;
    float R1, R2;//R1 radius of the circle, R2 the distance between the origin and the centere of the circle

    R1 = 1;
    R2 = 2; //if r2 is = to 0 we build a sphere otherwise a torus
    float k2 = 5;

    startX = R1; startY = 0; startZ = 0;

    float gamma = 0;
    float teta = 0;
    //Zprimo = (k2 * 3 * h)/(8 * (R1 + R2));//31.25
    Zprimo = 30;

    for(;;){
        clear();
        for(alfa = 0; alfa < 2 * PI; alfa += 0.2){
            //rotation on the y to get a circle
            circleX = startX * cos(alfa) - startY * sin(alfa);
            circleY = startX * sin(alfa) + startY * cos(alfa);
            circleZ = startZ;

            //move the circole xs R2 unit from the origin
            circleX += R2;

            for(beta = 0; beta < 2 * PI; beta += 0.2){
                //rotateing the circle on the y to get each point of the donut
                donutX = circleX * cos(beta) - circleZ * sin(beta);
                donutY = circleY;
                donutZ = circleX * sin(beta) + circleZ * cos(beta);

                //futher rotation
                
                //rotation on the x
                gammaX = donutX;
                gammaY = donutY * cos(gamma) + donutZ * sin(gamma);
                gammaZ = - donutY * sin(gamma) + donutZ * cos(gamma);

                //rotation on the z
                x = gammaX * cos(teta) - gammaY * sin(teta);
                y = gammaX * sin(teta) + gammaY * cos(teta);
                z = gammaZ;

                //push the donut k2 faraway from the origin
                z += k2;

                xPrimo = (x * Zprimo) / z;
                yPrimo = (y * Zprimo) / z;
                //printf("(%.2f,%.2f,%.2f) (%.2f,%.2f)\n", x, y, z, xPrimo, yPrimo);
                
                plot(xPrimo,yPrimo,'#');
            }
        }
        display();
        gamma += 0.04;
        teta += 0.02;
        usleep(15000);
    }

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