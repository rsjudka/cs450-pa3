#include "types.h"
#include "user.h"

void t1(void);
void t2(void);
void t3(void);

int
main(void)
{
  t1();
  // t2();
  // t3();

  exit();
}

void
t1(void)
{
  printf(1, "initial memory...\n");
  myMemory();
  printf(1, "\n");

  int pages = 10;

  int x;
  for(x = 0; x < pages; x++)
    sbrk(4096);

  printf(1, "alloc'ed...\n");
  myMemory();
  printf(1, "\n");

  for(x = 0; x < pages; x++)
    sbrk(-4096);

  printf(1, "dealloc'ed...\n");
  myMemory();
  printf(1, "\n");
}

void
t2(void)
{
  printf(1, "parent memory...\n");
  myMemory();
  printf(1, "\n");

  int pid;

  if((pid = fork()) == 0){
    printf(1, "child memory...\n");
    myMemory();
    printf(1, "\n");

    int pages = 56664; // max 56664

    int x;
    for(x = 0; x < pages; x++)
      sbrk(4096);

    printf(1, "alloc'ed...\n");
    myMemory();
    printf(1, "\n");

    for(x = 0; x < pages; x++)
      sbrk(-4096);

    printf(1, "dealloc'ed...\n");
    myMemory();
    printf(1, "\n");
  }
  else
    wait();
}

void
t3(void)
{
  printf(1, "memory...\n");
  myMemory();
  printf(1, "\n");

  int *x = (int *)malloc(262144);

  printf(1, "malloc'ed memory...\n");
  myMemory();
  printf(1, "\n");

  free(x);

  printf(1, "freed memory...\n");
  myMemory();
  printf(1, "\n");

}
