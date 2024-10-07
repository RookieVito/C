#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char* argv[]){
    int rc = fork();
    if(rc < 0){
        perror("error");
        exit(1);
    }else if(rc == 0){
        printf("hello\n");
        exit(0);
    }else{
        // wait(NULL);
        waitpid(rc, NULL, 0);
        printf("goodbye\n");
    }
    return 0;
}
