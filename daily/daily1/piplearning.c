/**
 * 使用fork()创建进程
 * 从父进程创建两个子进程
 * 两个子进程通过pip传递消息
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/wait.h>
#include <fcntl.h>

#define WRITE_END 1 //定义管道的写端
#define READ_END 0 //定义管道的读端

int main(int argc, char *argv[]){
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("pipe failed");
        exit(1);
    }

    __pid_t rc1 = fork();
    if (rc1 < 0)
    {
        perror("fork failed");
        exit(1);
    }

    if (rc1 == 0)
    {
        // 第一个子进程 rc1 只读数据，关闭管道的写端
        close(pipefd[WRITE_END]);
        char buffer[100];
        read(pipefd[READ_END], buffer, sizeof(buffer));
        printf("rc1 received the message: %s\n", buffer);
        close(pipefd[READ_END]); 
        exit(0);
    }

    if (rc1 > 0) {
        // 父进程继续，创建第二个子进程 rc2
        __pid_t rc2 = fork();
        if (rc2 < 0) {
            perror("fork failed");
            exit(1);
        } else if (rc2 == 0) {
            // 第二个子进程 rc2 写数据，关闭管道的读端
            close(pipefd[READ_END]);
            char message[] = "Hello, world!";
            write(pipefd[WRITE_END], message, strlen(message) + 1);
            close(pipefd[WRITE_END]); 
            exit(0);
        }

        // 父进程等待两个子进程结束
        waitpid(rc2, NULL, 0);
        waitpid(rc1, NULL, 0);
    }
    return 0;
}
//pipe通信机制
//read()会因为管道中没有数据而被阻塞，直到有数据可读，防止死锁
//write()会因为缓冲区已满而被阻塞，直到有空间可写，防止数据丢失
//单向通信：数据只能从一个方向流向另一个方向
//半双工：只能从一端读取数据，另一端写入数据