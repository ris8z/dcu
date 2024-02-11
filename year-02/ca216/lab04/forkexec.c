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


    /*printf("%s\n", command);
    while(*argument_list){
        printf("%s\n", *argument_list++);
    };*/

    run_command(command, argument_list, wait, &status);
    /*
    printf("Before calling execvp()\n");

    printf("Creating another process using fork()... \n");


    pid = fork();
    if( pid == -1 ){
        //an error occured with the forking process
        printf("Error with the forking process");
        return 1;
    }else if( pid == 0 ){
        //newly spawned child process. This well be taken over by "ls -l"
        int status_code = execvp(command, argument_list);

        printf("ls -l has taken controlf of this child process. This won't execute unless it termiate wrong!\n");
        
        if( status_code == -1 ){
            printf("Terminated Incorrectly\n");
            return 1;
        }
    }else{
        //old parent process. The c programm will come here

        //we wait for the child process to finish if we need
        if(wait)
            waitpid(pid, &status, WUNTRACED);

        printf("This line will be printed\n");
    }
*/

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
