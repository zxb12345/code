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

    int msg_id = msgget(key, IPC_CREAT);
    
    message msg;
    msg.mtype = 1;
    strcpy(msg.mtext, "Hello form client.");
    if (msgsnd(msg_id, &msg, sizeof(msg.mtext), 0) == -1)
    {
        perror("msgsnd");
        exit(EXIT_FAILURE);
    }

    return 0;
}