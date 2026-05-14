#include "types.h"
#include "user/user.h"
#include "stdio.h"
#include "stdlib.h"

int main() {
    int pid1, pid2;

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

    wait();
    wait();
    return 0;
}
