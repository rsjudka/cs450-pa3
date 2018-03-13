#include "types.h"
#include "user.h"

int
main(void)
{
  printf(1, "start pages: %d\n", myMemory());

  int x;
  for (x = 0; x < 10; x++)
    sbrk(4096);

  printf(1, "alloc'ing pages: %d\n", myMemory());

  for (x = 0; x < 10; x++)
    sbrk(-4096);

  printf(1, "freeing pages: %d\n", myMemory());
  
  exit();
}
