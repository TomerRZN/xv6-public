#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 3  // Number of child processes

void workload(int id, int priority) {
  for (int i = 0; i < 10; i++) {
    sleep(5);  // Sleep to make scheduling observable
  }
}

int main() {
  int pid;

  // Create NUM_PROCESSES child processes
  for (int i = 0; i < NUM_PROCESSES; i++) {
    pid = fork();
    if (pid == 0) {
      // Child process: set priority and run workload
      int priority = NUM_PROCESSES - i;  // Assign priorities (e.g., 5, 4, 3, 2, 1)
      setpriority(getpid(), priority);  // Set priority using system call
      workload(getpid(), priority);
      exit();  // Exit after completing workload
    }
  }

  // Parent waits for all child processes to finish
  for (int i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }

  exit();
}
