#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 5


int main(void) {
  int i;
  printf(1, "Testing scheduler with %d processes\n", NUM_PROCESSES);

  for (i = 0; i < NUM_PROCESSES; i++) {
    int pid = fork();
    if (pid < 0) {
      printf(1, "Fork failed\n");
      exit();
    } else if (pid == 0) {
      // Child process: sleep
      sleep(10);
    }
  }

  // Parent process: wait for all children
  for (i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }

  printf(1, "Scheduler test completed\n");
  exit();
}