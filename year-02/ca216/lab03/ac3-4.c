/*
This programs forks a separate process
using the fork()/exec() system calls.
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
        execlp("/bin/ls", "ls", NULL);

        printf("Do I execute?\n");// The answer is no
        /* But Why?
        “The exec() family of functions replaces the current process image with a new
        process image.”
        So, after fork(), in the child process,
        the process image (i.e., the code, data,etc) are replaced,
        meaning the code to print this line has been replaced.
        */
    }
    else {//parent process
          //parent process will wait for the  child to complete
        printf("I am the parent %d\n", pid);
        child_pid = wait(&status);

        printf("Child Complete, {pid=%d} with status=%d\n", child_pid, status);
    }


    return 0;
}
/*
Strace command:

Let’s use ‘strace’ to see what system calls are made
by newproc-posix

>stace ./a.out

When we run this, we can see a lot of system calls are
made by this program... Two important ones to spot are:
1. clone() <- this is the system call fork() uses to clone a
process (creating a child process)
2. write() <- this is used in places to write text to stdout

---------------------
Where’s the execution of /bin/ls in strace?
We need to tell strace to trace child process as they
are created by currently traced process using ‘-f’ (see
‘man strace’)

>strace -f ./a.out
With a bit of digging we can find a line like this
execve("/bin/ls", ["ls"], ......)
exelcp is a wrapper for the execve() (the system call)
*/
