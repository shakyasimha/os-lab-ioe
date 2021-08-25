#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	if(!fork()) {
		printf("hello! i'm from child \n");
		printf("CurrentID: %d, ParentID: %d\n", getpid(), getppid());
	}
	else {
		printf("hello! i'm from parent\n");
		printf("CurrentID: %d, PresentID: %d\n", getpid(), getppid());
	}
	return 0;
}


