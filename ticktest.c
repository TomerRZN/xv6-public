#include "types.h"
#include "stat.h"
#include "user.h"

#define NUM_PROCESSES 3  // Number of child processes

void workload(int id) {
  for (int i = 0; i < 50; i++) {
    printf(1, "Process %d: iteration %d\n", id, i);
    // Sleep to make sure the CPU is not fully occupied
    sleep(10);
  }
}

int main() {
  int pid;

  // Create NUM_PROCESSES child processes
  for (int i = 0; i < NUM_PROCESSES; i++) {
    pid = fork();
    if (pid == 0) {
      // Child process: perform workload
      workload(getpid());
      exit();  // Child exits after completing its workload
    }
  }

  // Parent waits for all child processes to finish
  for (int i = 0; i < NUM_PROCESSES; i++) {
    wait();
  }

  printf(1, "Test completed.\n");
  exit();
}
