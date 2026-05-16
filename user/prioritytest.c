#include "kernel/types.h"
#include "user/user.h"

void test_setpriority() {
    printf("\n--- Test 1: setpriority() and getpriority() ---\n");

    setpriority(3);
    int p = getpriority();
    if(p == 3)
        printf("PASS: setpriority(3) -> getpriority() returned %d\n", p);
    else
        printf("FAIL: expected 3, got %d\n", p);

    setpriority(7);
    p = getpriority();
    if(p == 7)
        printf("PASS: setpriority(7) -> getpriority() returned %d\n", p);
    else
        printf("FAIL: expected 7, got %d\n", p);
}

void test_invalid() {
    printf("\n--- Test 2: Invalid priority values ---\n");

    int r1 = setpriority(0);
    if(r1 == -1)
        printf("PASS: setpriority(0) correctly rejected\n");
    else
        printf("FAIL: setpriority(0) should return -1\n");

    int r2 = setpriority(11);
    if(r2 == -1)
        printf("PASS: setpriority(11) correctly rejected\n");
    else
        printf("FAIL: setpriority(11) should return -1\n");

    int r3 = setpriority(-5);
    if(r3 == -1)
        printf("PASS: setpriority(-5) correctly rejected\n");
    else
        printf("FAIL: setpriority(-5) should return -1\n");
}

void test_execution_order() {
    printf("\n--- Test 3: Execution order by priority ---\n");

    int pid1 = fork();
    if(pid1 == 0) {
        setpriority(1);
        printf("Process A - priority 1 (highest) - running\n");
        exit(0);
    }

    int pid2 = fork();
    if(pid2 == 0) {
        setpriority(5);
        printf("Process B - priority 5 (medium) - running\n");
        exit(0);
    }

    int pid3 = fork();
    if(pid3 == 0) {
        setpriority(10);
        printf("Process C - priority 10 (lowest) - running\n");
        exit(0);
    }

    wait(0);
    wait(0);
    wait(0);
    printf("Execution order test done\n");
}

void test_equal_priority() {
    printf("\n--- Test 4: Equal priorities ---\n");

    int pid1 = fork();
    if(pid1 == 0) {
        setpriority(5);
        printf("Process X - priority 5\n");
        exit(0);
    }

    int pid2 = fork();
    if(pid2 == 0) {
        setpriority(5);
        printf("Process Y - priority 5\n");
        exit(0);
    }

    wait(0);
    wait(0);
    printf("Equal priority test done\n");
}

void test_boundary() {
    printf("\n--- Test 5: Boundary values (1 and 10) ---\n");

    int r1 = setpriority(1);
    int p1 = getpriority();
    if(r1 == 0 && p1 == 1)
        printf("PASS: setpriority(1) works correctly\n");
    else
        printf("FAIL: setpriority(1) failed\n");

    int r2 = setpriority(10);
    int p2 = getpriority();
    if(r2 == 0 && p2 == 10)
        printf("PASS: setpriority(10) works correctly\n");
    else
        printf("FAIL: setpriority(10) failed\n");
}

int main() {
    printf("========================================\n");
    printf("   Priority Scheduler - Full Test Suite  \n");
    printf("========================================\n");

    test_setpriority();
    test_invalid();
    test_boundary();
    test_equal_priority();
    test_execution_order();

    printf("\n========================================\n");
    printf("         All tests completed!\n");
    printf("========================================\n");

    exit(0);
}
