#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<signal.h>

void sighandler(int signum){
    printf("Received a signal %d\n", signum);
}

int main(int argc, char **argv){

    signal(SIGINT, sighandler);
    
    if(argc < 2){
        printf("not enough arguments\n");
        return 1;
    }

    int N = atoi(argv[1]);
    int value_sleep;
    int i;

    for(i = 0; i < N; i++){
        printf("we'll wait 5 second, from pid = %d\n", (int)getpid());
        value_sleep = sleep(5);
    }

    printf("the return value of sleep function on the last iteration(i = %d) is %d\n", i, value_sleep);


    return 0;
}
