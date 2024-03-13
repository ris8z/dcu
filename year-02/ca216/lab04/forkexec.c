#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void run_command(char *command, char **arg_list, int wait, int *pstatus);

int main(int argc, char **argv){

    pid_t pid;    
    //char *command = "ls";
    //char *argument_list[] = {"ls", "-l", NULL};
    int status;
    int wait = 1;
    char *command = argv[1];
    char **argument_list = argv + 1;

    run_command(command, argument_list, wait, &status);

    return 0;
}

void run_command(char *command, char **arg_list, int wait, int *pstatus){

    printf("Before calling execvp we create another process with fork()\n");
    pid_t pid = fork();

    if(pid == -1){
        printf("Error while forking!\n");
    }else if(pid == 0){
        //child process that will be taken over by our command process called with execvp
        int status_code = execvp(command, arg_list);
        printf("Our command has taken control of this child process. This won't execute unless it termiate wrong!\n");
        if(status_code == -1){
            printf("Erorr with execvp\n");
        }
    }else{
        //parent process
        if(wait)
            waitpid(pid, pstatus, WUNTRACED);

        printf("Hello from parent process\n");
    }
}
