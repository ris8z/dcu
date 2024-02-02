/*
And remove the wait(None) and while(1); from the
parent process
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
        printf("I am the parent %d\n", pid);
    }

    return 0;
}
/*
Having a look with ‘top’, we can see process ID (the
child) is still running!

Who is the parent process? (it’s systemd)

Because this child process became orphaned,
systemd (PID=1), inherited the process as a child

Run:
pstree –a
Can you find the running child process with its new
parent systemd (PID=1)?

We should terminate it, because it’s just using up
CPU cycles
*/
