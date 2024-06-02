#include<stdio.h>
#include<math.h>
#include<unistd.h>

#define PI 3.141592653589793238462643383279502884197

#define w 160
#define h 80

char output[h][w];
float zBuffer[h][w];
void Zclear();
void clear();
void plot(int x, int y, char c);
void display();

int main(void){
    //main equation x*x + y * y + z * z == 1
    float alfa, beta;
    float circleX,circleY,circleZ;
    float x, y, z;
    float xPrimo, yPrimo, Zprimo;
    float R1, R2;//R1 radius of the circle, R2 the distance between the origin and the centere of the circle
    
    R1 = 1;
    R2 = 2; //if r2 is = to 0 we build a sphere otherwise a torus
    float k2 =5;

    

    float gamma = 0;
    float teta = 0;
    Zprimo = (k2 * 3 * h)/(8 * (R1 + R2));
    //Zprimo = 31;

    float startNormX;
    float startNormY;

    float normX, normY, normZ;
    
    float LightX=0, LightY=1, LightZ=-1;
    float MagnitueL = sqrt(LightX * LightX + LightY * LightY + LightZ * LightZ);
    LightX /= MagnitueL;
    LightY /= MagnitueL;
    LightZ /= MagnitueL;

    float Light;

    printf("\x1b[H");
    for(;;){
        clear();
        Zclear();
        for(alfa = 0; alfa < 2 * PI; alfa += 0.07){

            circleX = R2 + R1 * cos(alfa);
            circleY = R1 * sin(alfa);

            startNormX = cos(alfa);
            startNormY = sin(alfa);

            for(beta = 0; beta < 2 * PI; beta += 0.02){
                x =  circleX*(cos(beta)*cos(teta) - sin(beta)*sin(gamma)*sin(teta))
                    -circleY*(cos(gamma)*sin(teta));

                y =  circleX*(cos(beta)*sin(teta) + sin(beta)*sin(gamma)*cos(teta))
                    +circleY*(cos(gamma)*cos(teta));
                
                z =  circleX*(sin(beta)*cos(gamma))
                    -circleY*(sin(gamma));

                normX = startNormX*(cos(beta)*cos(teta) - sin(beta)*sin(gamma)*sin(teta))
                    -startNormY*(cos(gamma)*sin(teta));

                normY = startNormX*(cos(beta)*sin(teta) + sin(beta)*sin(gamma)*cos(teta))
                    +startNormY*(cos(gamma)*cos(teta));
                
                normZ = startNormX*(sin(beta)*cos(gamma))
                    -startNormY*(sin(gamma));

                Light = (normX * LightX) + (normY * LightY) + (normZ * LightZ);

                xPrimo = (x * Zprimo) / (z + k2) + w/2;
                yPrimo = -((y * Zprimo) / (z + k2)) + h/2;

                int gridX = (int) xPrimo;
                int gridY = (int) yPrimo;
            
                int a = 0 <= gridX && gridX < w;
                int b = 0 <= gridY && gridY < h;
                
                if(a && b){
                    float ooz = 1 / (z + k2);

                    if(ooz > zBuffer[gridY][gridX]){
                        zBuffer[gridY][gridX] = ooz;
                        Light *= 12;
                        char c = ".,-~:;=!*#$@"[Light > 0 ? (int) Light : 0];
                        plot(gridX, gridY, c);
                    }
                }
            }
        }
        display();
        gamma += 0.04;
        teta += 0.02;
        usleep(10000);
    }

    return 0;
}

void clear(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            output[i][j] = ' ';
}

void Zclear(){
    for(int i = 0; i < h; i++)
        for(int j = 0; j < w; j++)
            zBuffer[i][j] = 0;
}

void plot(int x, int y, char c){
    output[(int) y][(int) x] = c;
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
