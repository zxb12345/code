#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int fds[2];
    if (pipe(fds) == -1)
    {
        perror("pipe");
        exit(1);
    }

    if (fork() == 0)
    {
        close(fds[0]);
        sleep(3);
        write(fds[1], "aaaaaaaaab", 10);
        close(fds[1]);
        exit(0);
    }
    else
    {
        close(fds[1]);
        char buf[100] = {};
        printf("before read\n");
        read(fds[0], buf, 100);
        printf("after read\n");
        close(fds[0]);
        printf("[%s]\n", buf);
        exit(0);
    }
}