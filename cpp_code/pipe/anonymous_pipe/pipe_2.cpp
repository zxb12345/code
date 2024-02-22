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
        close(1);
        dup(fds[1]);
        close(fds[1]);
        execlp("ls", "ls", "-l", NULL);
        exit(0);
    }
    else
    {
        close(fds[1]);
        close(0);
        dup(fds[0]);
        close(fds[0]);
        execlp("wc", "wc", "-l", NULL);
        exit(0);
    }
}