#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int pid;
    pid = fork();

    if(pid==0)
    {
        printf("i am child, my process ID id %d\n",getpid()); 
        printf("i am a child and my parent's ID is %d\n",getppid());
        sleep(20);
    }

    else
    {
        //sleep(20);
        printf("I am the parent and my process ID is %d\n",getpid());
        printf("I am the parent's process ID is %d\n",getppid());
    }

    return 0;
}