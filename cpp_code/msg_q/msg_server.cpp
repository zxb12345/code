#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    key_t key = creat();
    if (key < 0)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int msg_id = msgget(key, IPC_CREAT | 0666);
    
    message msg;
    if (msgrcv(msg_id, &msg, sizeof(msg.mtext), 1, 0) == -1)
    {
        perror("msgrcv");
        exit(EXIT_FAILURE);
    }

    printf("recive message: %s\n", msg.mtext);

    if (msgctl(msg_id, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}