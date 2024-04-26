#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <semaphore.h>

int main(void){
  sem_t *sem;

  //create the semaphore a startalo a 1
   sem = sem_open("SEM", O_CREAT, 0666, 1);

  //aquire
  sem_wait(sem);

  //critical section

  //realse
  sem_post(sem);

  return 0;
}