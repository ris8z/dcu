#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>

//gcc consumer.c -o consumer -lrt
int main(void)
{
  const char *name = "OS";
  const int SIZE = 4096;

  int shm_fd;
  void *ptr;
  int i;

  //open shared memory segemtn
  shm_fd = shm_open(name, O_RDONLY, 0666);
  if( shm_fd == -1 )
  {
    printf("shared memory failed\n");
    exit(-1);
  }

  //map the shared memory into ptr
  ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
  if( ptr == MAP_FAILED )
  {
    printf("Map failed\n");
    exit(-1);
  }

  //now read from the ptr
  printf("%s\n", (char *) ptr);

  //remove the shared memory segemnt

  if( shm_unlink(name) == -1 )
  {
    printf("Error removing %s\n", name);
    exit(-1);
  }

  return 0;
}