#include "common.h"
#include <iostream>
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

    int shmid = shmget(key, CATCH_SIZE, IPC_CREAT | IPC_EXCL | 0666);
    std::cout << "creat shared memory sucessful." << std::endl;

    char *ptr = (char *)shmat(shmid, nullptr, 0);
    std::cout << "link shared memory sucessful." << std::endl;

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << ptr << std::endl;
    }

    shmdt(ptr);
    std::cout << "unlink shared memory sucessful." << std::endl;

    shmctl(shmid, IPC_RMID, nullptr);
    std::cout << "delete shared memory sucessful." << std::endl;

    return 0;
}