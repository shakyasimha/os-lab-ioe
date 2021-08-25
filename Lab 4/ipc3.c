#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define MSGSZ 16

int main() {
    char *msg1 = ("hello one");
    char *msg2 = ("hello two");
    char *msg3 = ("hello three");
    char inbuf[MSGSZ];

    int p[2];
    pipe(p);

    write(p[1], msg1, MSGSZ);
    write(p[1], msg2, MSGSZ);
    write(p[1], msg3, MSGSZ);

    for(int j = 0; j < 3; ++j) {
        read(p[0], inbuf, MSGSZ);
        printf("%s\n", inbuf);
    }

    exit(0);
    return 0;
}