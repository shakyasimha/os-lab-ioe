#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int fd[2];
    pipe(fd);
    char c;
    int exflag=0;

    if(!fork()) {
        close(fd[0]);
        printf("press a key: ");
        scanf("%c",&c);
        exflag=1;
        write(fd[1], &exflag, sizeof(int));
        close(fd[1]);
        exit(0);
    }
    else {
        close(fd[1]);
        int y;
        read(fd[0], &y,sizeof(int));
        close(fd[0]);
        while(!y);
        printf("i got the character\n");
    }
}