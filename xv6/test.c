#include "types.h"
#include "user.h"

void t1(void);
void t2(void);

int
main(void)
{
  t1();
  // t2();

  exit();
}

void
t1(void)
{
  printf(1, "initial memory...\n");
  myMemory();
  printf(1, "\n");

  int pages = 10; // every mb means extra page???

  int x;
  for (x = 0; x < pages; x++)
    sbrk(4096);

  printf(1, "alloc'ed...\n");
  myMemory();
  printf(1, "\n");

  for (x = 0; x < pages; x++)
    sbrk(-4096);

  printf(1, "dealloc'ed...\n");
  myMemory();
  printf(1, "\n");
}

void
t2(void)
{
  int pid;

  if ((pid = fork()) == 0)
  {
    myMemory();

    int x;
    for (x = 0; x < 100; x++)
      sbrk(4096);

    myMemory();

    for (x = 0; x < 100; x++)
      sbrk(-4096);

    myMemory();
  }
  else
  {
    wait();
  }
}
