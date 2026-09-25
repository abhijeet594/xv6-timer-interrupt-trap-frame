#include "types.h"
#include "stat.h"
#include "user.h"

#define N 100000

int
main(void)
{
  int pid;
  int i;

  counter_reset();

  pid = fork();

  if(pid < 0){
    printf(1, "fork failed\n");
    exit();
  }

  if(pid == 0){
    for(i = 0; i < N; i++)
      counter_inc();

    exit();
  }

  for(i = 0; i < N; i++)
    counter_inc();

  wait();

  printf(1, "Expected counter: %d\n", 2 * N);
  printf(1, "Actual counter:   %d\n", counter_get());

  exit();
}
