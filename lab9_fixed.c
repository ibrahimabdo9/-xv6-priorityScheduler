#
include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 1000000

void demo_access_bug() {
    int *a = malloc(SIZE * sizeof(int));
    long sum = 0;
    clock_t t1 = clock();
    for (int i = 0; i < SIZE; i++)
        sum += a[i];
    clock_t t2 = clock();
    printf("Access time: %f sec\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
    free(a);
}

void demo_leak_bug() {
    int *leak = malloc(1024);
    printf("Leaked 1 KB\n");
    free(leak);
}

void recurse_bug(int n) {
    if (n > 1000) return;
    int buf[100];
    recurse_bug(n + 1);
}

void demo_paging_bug() {
    int *p = malloc(SIZE * sizeof(int));
    p[0] = 1;
    printf("First element = %d\n", p[0]);
    free(p);
}

int main() {
    demo_access_bug();
    demo_leak_bug();
    recurse_bug(0);
    demo_paging_bug();
    return 0;
}
