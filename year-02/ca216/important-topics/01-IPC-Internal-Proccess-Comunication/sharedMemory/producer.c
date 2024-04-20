#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

//gcc producer.c -o producer -lrt
int main(void)
{
  const int SIZE = 4096;
  const char *name = "OS";
  const char *message0 = "Studing ";
  const char *message1 = "Operating System ";
  const char *message2 = "Is Fun!";

  int shm_fd;
  void *ptr;

  //create the shared memory segment
  shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

  //set the size of the shared memory segment
  ftruncate(shm_fd, SIZE);


  //we map the shared memory segment to a pointer so its easier to use
  ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  if(ptr == MAP_FAILED)
  {
    printf("Map failed\n");
    return -1;
  }

  //Now we write to the shared memory segment
  //Note we must increment the value of ptr after each write

  sprintf(ptr, "%s", message0);
  ptr += strlen(message0);

  sprintf(ptr, "%s", message1);
  ptr += strlen(message1);

  sprintf(ptr, "%s", message2);
  ptr += strlen(message2);

  return 0;
}