#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 3  // Number of child processes
#define ITERATIONS 50    // Number of iterations for workload (to generate scheduler logs)

void workload() {
  for (int i = 0; i < ITERATIONS; i++) {
    // Do some work (no printing)
    asm volatile("");  // Prevent compiler optimizations
  }
}

int main() {
  setpriority(getpid(), 1);  // Set parent process priority to 1

  int pid;
  int priorities[NUM_PROCESSES] = {2, 3, 4};  // Priorities for child processes

  // Create child processes
  for (int i = 0; i < NUM_PROCESSES; i++) {
    pid = fork();
    if (pid == 0) {
      // Child process
      setpriority(getpid(), priorities[i]);  // Set child process priority
      workload();  // Run workload
      exit();  // Exit after workload completes
    }
  }

  // Parent process: lower its own priority after creating children
  setpriority(getpid(), 5);

  // Wait for child processes to finish
  for (int i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }

  exit();
}
