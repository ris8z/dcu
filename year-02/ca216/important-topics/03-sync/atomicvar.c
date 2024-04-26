#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int acnt = 0;
int cnt = 0;

int f(void* thr_data)
{
  for(int n = 0; n < 10; n++){
    ++cnt;
    ++acnt;
  }
}

int main(void)
{
  thrd_t thr[10];
  for(int n = 0; n < 10; n++){
    thrd_create(&thr[n], f, NULL);
  }
  for(int n = 0; n < 10; n++){
    thrd_join(thr[n], NULL);
  }

  printf("atmoic var is %d\n", acnt);
  printf("notmal var is %d\n", cnt);
  
  return 0;
}