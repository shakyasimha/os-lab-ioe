#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int p[2], pid;
    pipe(p);
    pid = fork();

    if(pid == 0) 
        printf("in the child p[0] is %d p[1] is %d\n", p[0], p[1]);
    else 
        printf("in the parent p[0] is %d p[1] is %d\n", p[0], p[1]);

    return 0;
}