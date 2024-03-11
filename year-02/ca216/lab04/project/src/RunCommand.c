#include "RunCommand.h"
#include <stdio.h>
#include <unistd.h>

#define CHILD 0
#define FORK_FAILD -1
#define EXECVP_FAILD -1

void run_command(Command *c)
{
    pid_t ourPid = fork()

    if(ourPid == FORK_FAILD){
        //error message
        return
    }

    if(ourPid == CHILD){
        char *argv[2] = {"ls", 0};
        
        int status = execvp(argv[0], argv);
        
        if(status == EXECVP_FAILD){
            //error message
            return
        }
    }

    //PARENT
    wait(NULL);
}
