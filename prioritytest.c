#include "types.h"
#include "stat.h"
#include "user.h"


#define NUM_CHILDREN 3
#define ITERATIONS 50


void workload() {
  for (int i = 0; i <= ITERATIONS; i++)
    sleep(1);
}


int main() {
  int pid;

  // Create child processes
  for (int i = 0; i < NUM_CHILDREN; i++) {
    pid = fork();
    // Child process
    if (pid == 0) {
        setpriority(getpid(), NUM_CHILDREN - i);
        workload();
        exit();
    }
  }
  // Parent process
  wait();
  exit();
}
