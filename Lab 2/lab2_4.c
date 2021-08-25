#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i = 0, j = 0, pid;
    pid = fork();

    if(pid == 0) {
        printf("\n");

        for(i = 0; i < 25; ++i) 
            printf("%d\t", i);
        
        printf("\n");
    }
    else {
        if(pid > 0) {
            wait(0);
            for(j = 25; i < 500; ++j) 
                printf("%d", i);
        }
    }

    return 0;
}