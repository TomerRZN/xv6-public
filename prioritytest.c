#include "types.h"
#include "stat.h"
#include "user.h"


int main() {
  setpriority(getpid(), 1);  // Set parent process priority to 1

  int pid = fork();

  // Child process
  if (pid == 0) {
    setpriority(getpid(), 2);  // Set child process priority
    int count = 0;
    while(count < 100000);
        count++;

  // Parent process
  else {
    setpriority(getpid(), 3); // Let the child finish first
    wait();
  }
  exit();
}
