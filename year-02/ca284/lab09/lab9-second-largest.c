/*
    author = Giuseppe Esposito
    description = we take an array as input from command line and we need to output the second largest element
    date = 9/11/2023
    approach =
    -we dinamically store the array with the first two fuctiona allocate_memory and fill_array
    -we find the second largest by going trough all the array once, recording the first largest and the second
    with two if statment and then we return the second largest
*/
#include<stdio.h>
#include<stdlib.h>



void allocate_memory(float **p, int N);
void fill_array(float **p, int N, char **pi);

float min(float a, float b);
float max(float a, float b);
float find_second_largest(float *p, int N);



int main(int argc, char *argv[]){
    float *pa = NULL;
    int N = argc - 1;
    
    fill_array(&pa, N, argv + 1);
    printf("%.1f\n",find_second_largest(pa, N));
    
    free(pa);
    pa = NULL;

    return 0;
}



void allocate_memory(float **p, int N){
    *p = (float*)malloc(N * sizeof(float));
    if(*p == NULL){
        printf("Memory Error\n");
    }
}

void fill_array(float **p, int N, char **pi){
    allocate_memory(p, N);

    if(*p == NULL){
        return;
    }

    for(int i = 0; i < N; i++)
        *(*p + i) = atof(*(pi + i));
}



float max(float a, float b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

float min(float a, float b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

float find_second_largest(float *p, int N){
    float f_larg = max(*(p), *(p + 1));//first largest
    float s_larg = min(*(p), *(p + 1));//second largest
    float n, tmp;

    for(unsigned int i = 2; i < N; i++){
        n = *(p + i);
        /*if n is great then the first largest, we update the value of the first largest and the we update
        the value of the second with the previous value of the first

        but if n is smaller then the first largest does not mean that can not be larger then the second,
        in that case we need just to update the value of second largest to n
        */
        if(n > f_larg){
            tmp = f_larg;
            f_larg = n;
            s_larg = tmp;
        }else if(n > s_larg && n < f_larg){
            s_larg = n;
        }
    }

    return s_larg;
}
