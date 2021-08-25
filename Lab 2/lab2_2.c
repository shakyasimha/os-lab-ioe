#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i,d;
    int DEL1=1, DEL2=100000;
    char c;

    if(!fork()) {
        for(c='a';c<='z';c++) {
            printf("%c\t",c);
            fflush(stdout);
        
            for(d = 0; d < DEL1; d++);
        }
        exit(0);
    }
    else {
        for(i=0;i<=10;i++) {
            printf("%d\t",i);
            fflush(stdout);
        
            for(d = 0; d < DEL2; d++);
        }
        exit(0);
    }

}