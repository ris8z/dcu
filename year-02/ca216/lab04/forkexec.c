#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<fcntl.h>

void run_command(char *command, char **arg_list, int wait, int output);

int main(int argc, char **argv){

    pid_t pid;    
    int wait = 1;
    char *command = argv[1];
    char **argument_list = argv + 1;

    int file_desc = open("t.txt", O_CREAT | O_APPEND | O_WRONLY );// >>
    //int file_desc = open("t.txt", O_CREAT | O_TRUNC | O_WRONLY); // >

    run_command(command, argument_list, wait, file_desc);
    printf("ao");

    return 0;
}

void run_command(char *command, char **arg_list, int wait, int output){

    printf("Before calling execvp we create another process with fork()\n");
    pid_t pid = fork();

    if(pid == -1){
        printf("Error while forking!\n");
    }else if(pid == 0){
        //child process that will be taken over by our command process called with execvp
        if(output > 0){
            dup2(output, STDOUT_FILENO); //ridirect the output to the file pointed by input
            close(output);
        }
        int status_code = execvp(command, arg_list);
        printf("Our command has taken control of this child process. This won't execute unless it termiate wrong!\n");
        if(status_code == -1){
            printf("Erorr with execvp\n");
        }
    }else{
        //parent process
        if(wait)
            waitpid(pid, NULL, WUNTRACED);

        printf("Hello from parent process\n");
    }
}
