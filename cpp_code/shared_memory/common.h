#ifndef _COMMON_H_
#define _COMMON_H_

#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

#define PATH_NAME "."
#define PROJ_EID 0x12
#define CATCH_SIZE 4096

key_t creat()
{
    key_t key = ftok(PATH_NAME, PROJ_EID);
    return key;
}


#endif // !_COMMON_H_