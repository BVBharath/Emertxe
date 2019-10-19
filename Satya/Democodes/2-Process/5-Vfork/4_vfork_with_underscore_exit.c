#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int global = 5;

int main(int argc, char **argv) {
    int local;
    pid_t pid;
    
    local = 50;

    printf("before vfork\n");

    if((pid = vfork()) < 0) {
        perror("fork error");
        exit(1);
    }
    else if (pid == 0) {
        global++;
        local++;
        printf("child: pid=%d, global=%d, local=%d\n", getpid(), global, local);
        _exit(0);
    }

    printf("pid=%d, global=%d, local=%d\n", getpid(), global, local);
    exit(0);
}
