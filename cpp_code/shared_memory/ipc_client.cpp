#include <iostream>
#include "common.h"
#include <thread>
#include <chrono>

int main()
{
    key_t key = creat();
    std::cout << "key is: " << key << std::endl;

    if (key < 0)
    {
        std::cout << "ftok key failed." << std::endl;
        return 0; 
    }

    int shmid = shmget(key, CATCH_SIZE, IPC_CREAT);
    std::cout << "creat shared memory sucessful." << std::endl;

    char* ptr = (char*)shmat(shmid, nullptr, 0);
    std::cout << "link shared memory sucessful." << std::endl;

    int count = 0;
    while (count <= 26)
    {
        ptr[count] = 'A' + count;
        ++count;
        ptr[count] = '\0';
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    shmdt(ptr);
    std::cout << "unlink shared memory sucessful." << std::endl;
    
    return 0;
}