#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 3  // Number of child processes

int main() {

  int pid;
  // Create NUM_PROCESSES child processes
  for (int i = 0; i < NUM_PROCESSES; i++) {
    pid = fork();
    if (pid == 0) {
      // Child process: set priority and run workload
      int priority = NUM_PROCESSES - i + 1;
      setpriority(getpid(), priority);
      sleep(100);
      exit();
    }
  }

  // Parent waits for all child processes to finish
  for (int i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }

  exit();
}
