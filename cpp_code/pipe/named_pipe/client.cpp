#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    const char* fifo_file = "my_fifo";
    // if (mkfifo(fifo_file, 0666) == -1)
    // {
    //     perror("mkfifo");
    //     exit(EXIT_FAILURE);
    // }

    int fd = open(fifo_file, O_WRONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    const char *message = "Hello from client";
    write(fd, message, strlen(message) + 1);

    close(fd);

    return 0;
}