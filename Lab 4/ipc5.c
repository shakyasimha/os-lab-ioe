#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define msgsz 16

int main() {
    char *msg = "hello!";
    char inbuf[msgsz];
    int p[2], pid, j;

    pipe(p);
    pid = fork();

    if(pid > 0) {
        close(p[0]);
        write(p[1], msg, msgsz);
    }

    if(pid == 0) {
        close(p[1]);
        read(p[0], inbuf, msgsz);
        printf("%s\n", inbuf);
    }

    exit(0);
    return 0;
}
