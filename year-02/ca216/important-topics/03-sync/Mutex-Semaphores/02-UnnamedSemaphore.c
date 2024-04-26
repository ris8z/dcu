#include <stdio.h>
#include <semaphore.h>


int main(void){
  sem_t sem;

  //create and ititzialize it to 1
  sem_init(&sem, 0, 1);

  //acquire semaphore
  sem_wait(&sem);

  //critcal section

  //realse the semaphore
  sem_post(&sem);

  return 0;
}