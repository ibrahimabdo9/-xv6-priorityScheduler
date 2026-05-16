#include "kernel/types.h"
#include "user/user.h"

int main() {
    int pid1, pid2, pid3;

    pid1 = fork();
    if(pid1 == 0) {
        setpriority(1);
        printf("High priority process running (priority 1)\n");
        exit(0);
    }

    pid2 = fork();
    if(pid2 == 0) {
        setpriority(5);
        printf("Medium priority process running (priority 5)\n");
        exit(0);
    }

    pid3 = fork();
    if(pid3 == 0) {
        setpriority(10);
        printf("Low priority process running (priority 10)\n");
        exit(0);
    }

    wait(0);
    wait(0);
    wait(0);

    printf("Test done!\n");
    exit(0);
}
