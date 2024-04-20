#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int sum; //this data is shared by the threa(s)
void *runner(void *param); //threads call this function

int main(int argc, char *argv[]){
  pthread_t tid; //thread id
  pthread_attr_t attr;//set of thread attributes

  //set the default attributes of the thread
  pthread_attr_init(&attr);

  //create the thread
  pthread_create(&tid, &attr, runner, argv[1]);

  //wait for the thread to exit
  pthread_join(tid, NULL);

  printf("sum %d\n", sum);

}

void *runner(void *param){
  int i, upper = atoi(param);
  sum = 0;

  for(i = 1; i <= upper; i++)
    sum += i;

  pthread_exit(0);
}


/*
#define NUM_THREADS 10

pthread_t workers[NUM_THREADS];

for( int i = 0; i < NUM_THREADS; i++){
  pthread_join(workers[i], NULL);
}



you can cancel a thread witahout wating 
pthread_cancel(tid);
*/



// bool test_and_set(bool* ptr){
//   bool tmp = *ptr;
//   *ptr = true;
//   return tmp;
// }

// int Compare_and_swap(int *ptr, int expected, int new){
//   int tmp = *ptr
//   if( *ptr == excpected){
//     *ptr = new;
//   }
//   return  tmp;
// }

