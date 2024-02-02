/*
with two while loops we made our 2 procces last infinitly
This is a hack to keep both of these processes from
terminating so that we can examine them using
‘pstree’ and ‘ps’

Before we run our program we find out the PID of the bash using ‘echo $$’:

Then we run our program:

Open a separate terminal window and run:
top
Press s, then .2, and press enter (this will cause top to
update every .2 seconds)

We can see our parent and child process running with 100%
cpu each (because of the infinite loop/while (1); code)

We can view the process tree (staring from the bash
instance) downward using pstree:
>pstree -p (pid of the bash)

We should now kill both of these processes using the
‘kill’ command
>kill (pidofprocess)
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
pid_t pid;
pid_t child_pid;
    //fork a child process
    pid = fork();

    int status;

    if(pid < 0) {// error occured
        fprintf(stderr, "Fork Failed\n");
        return 1;
    }
    else if (pid == 0) {// child process
        printf("I am the child %d\n", pid);
        while(1);
    }
    else {//parent process
          //parent process will wait for the  child to complete
        printf("I am the parent %d\n", pid);
        while(1);
        child_pid = wait(&status);

        printf("Child Complete, {pid=%d} with status=%d\n", child_pid, status);
    }


    return 0;
}
