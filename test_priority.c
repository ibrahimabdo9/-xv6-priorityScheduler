#include "kernel/types.h"
#include "user.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    int pid1, pid2;
    int status;

    pid1 = fork();
    if (pid1 == 0) {
        set_priority(10);
        while(1) {
        }
    }

    pid2 = fork();
    if (pid2 == 0) {
        set_priority(1);
        while(1) {
        }
    }

   int status;
    wait(&status);
    wait(&status);
    return 0;
}
