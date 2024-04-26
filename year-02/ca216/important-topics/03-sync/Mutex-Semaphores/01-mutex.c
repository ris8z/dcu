#include <stdio.h>
#include <pthread.h>



int main(void){
  pthread_mutex_t mutex;
  //create a mutex
  pthread_mutex_init(&mutex, NULL);

  //acquire the mutex lock
  pthread_mutex_lock(&mutex);

  //critical section

  //realse the mutex lock

  pthread_mutex_unlock(&mutex);
  
  return 0;
}