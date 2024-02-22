#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    const char* fifo_file = "my_fifo";
    if (mkfifo(fifo_file, 0666) == -1)
    {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    int fd = open(fifo_file, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    read(fd, buffer, sizeof(buffer));

    printf("server process received: %s\n", buffer);
    close(fd);

    unlink(fifo_file);

    return 0;
}