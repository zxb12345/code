#ifndef _COMMON_H_
#define _COMMON_H_

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define PROJ_EID 0x12

struct message
{
    long mtype;
    char mtext[100];
};

key_t creat()
{
    key_t key = ftok(".", PROJ_EID);
    return key;
}

#endif // !_COMMON_H_