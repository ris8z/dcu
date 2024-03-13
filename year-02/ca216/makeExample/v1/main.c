#include <stdio.h>
#include "hellomake.h"
#include "add.h"

int main() {
  // call a function in another file
  myPrintHelloMake();

  printf("%d", add(5,2));
  return(0);
}
