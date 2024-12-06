#include "types.h"
#include "stat.h"
#include "user.h"


#define NUM_PROCESSES 3
#define ITERATIONS 50


void workload() {
  for (int i = 0; i <= ITERATIONS; i++)
    sleep(1); // Sleep for 1 tick
}


int main() {
  int pid;

  // Create child processes
  for (int i = 0; i < NUM_PROCESSES; i++) {
    pid = fork();
    // Child process
    if (pid == 0) {
        setpriority(getpid(), NUM_PROCESSES - i);
        workload();
        exit();
    }
  }
  // Parent process
  for (int i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }
  exit();
}
