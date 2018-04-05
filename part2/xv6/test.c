#include "types.h"
#include "user.h"

void t1(void);
void t2(void);
void t3(void);
void t4(void);
void t5(void);
void t6(void);
void t7(void);
void t8(void);
void t9(void);
void t10(void);
void t11(void);
void t12_1(void);
void t12_2(void);

int
main(int argc, char **argv)
{
  switch(atoi(argv[1])){
    case 1:
      t1();
      break;
    case 2:
      t2();
      break;
    case 3:
      t3();
      break;
    case 4:
      t4();
      break;
    case 5:
      t5();
      break;
    case 6:
      t6();
      break;
    case 7:
      t7();
      break;
    case 8:
      t8();
      break;
    case 9:
      t9();
      break;
    case 10:
      t10();
      break;
    case 11:
      t11();
      break;
    case 12:
      printf(1, "reaching stack page size limit...\n");
      t12_1();
      printf(1, "\n");
      printf(1, "exceeding stack page size limit...\n");
      t12_2();
      break;
    default:
      printf(1, "missing test number\n");
  }

  printf(1, "\n");
  exit();
}

void
t1(void)
{
  printf(1, "TEST PROCESS\n");
  myMemory();
}

void
t2(void)
{
  printf(1, "adding 4096 bytes to memory...\n");
  sbrk(4096);
  myMemory();
}

void
t3(void)
{
  printf(1, "adding 4097 bytes to memory...\n");
  sbrk(4097);
  myMemory();
}

void
t4(void)
{
  printf(1, "adding 1024 bytes to memory...\n");
  sbrk(1024);
  myMemory();
  printf(1, "\n");

  printf(1, "adding 1024 bytes to memory...\n");
  sbrk(1024);
  myMemory();
}

void
t5(void)
{
  printf(1, "adding 4096 pages to memory...\n");
  int x;
  for(x = 0; x < 4096; x++)
    sbrk(4096);
  myMemory();
}

void
t6(void)
{
  printf(1, "adding 1048576 pages to memory...\n");
  int x;
  for(x = 0; x < 1048576; x++){
    if((int)sbrk(4096) == -1)
      break;
  }
  myMemory();
}

void
t7(void)
{
  printf(1, "adding 4096 pages to memory...\n");
  int x;
  for(x = 0; x < 4096; x++)
    sbrk(4096);
  myMemory();
  printf(1, "\n");

  printf(1, "removing 4096 pages from memory...\n");
  for(x = 0; x < 4096; x++)
    sbrk(-4096);
  myMemory();
}

void
t8(void)
{
  printf(1, "adding and subsequently removing 4096 pages to memory...\n");
  int x;
  for(x = 0; x < 4096; x++){
    sbrk(4096);
    sbrk(-4096);
  }
  myMemory();
}

void
t9(void)
{
  printf(1, "PARENT PROCESS\n");
  printf(1, "adding 1 page to memory...\n");
  sbrk(4096);
  myMemory();
  printf(1, "\n");

  printf(1, "forking child process...\n");
  int pid;
  if((pid = fork()) == 0){
    printf(1, "CHILD PROCESS\n");
    myMemory();
    exit();
  }
  else
    wait();
}

void
t10(void)
{
  printf(1, "TEST PROCESS\n");
  printf(1, "adding 1 page to memory...\n");
  sbrk(4096);
  myMemory();
  printf(1, "\n");

  printf(1, "exec'ing new process...\n");
  char *x[2] = {"test", "1"};
  exec(x[0], x);
}

void
t11(void){
  char *x[1] = {"test_s"};
  exec(x[0], x);
}

void
t12_1(void)
{
  int large_stack[992];
  memset(large_stack, 0, sizeof(int));
  myMemory();
}

void
t12_2(void)
{
  int large_stack[993];
  memset(large_stack, 0, sizeof(int));
  myMemory();
}

// James Guerrera-Sapone - A20365203 
// Robert Judka - A20348051