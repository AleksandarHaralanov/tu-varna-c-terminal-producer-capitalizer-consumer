#include <stdio.h>
#include <shared.h>

int main() {
    sem_t sharedMemorySemaphore;
    sem_t bufferEmptySemaphore;
    sem_t bufferFullSemaphore;
    sem_t capitalizedBufferSemaphore;
    sem_t capitalizedBufferEmptySemaphore;
    sem_t capitalizedBufferFullSemaphore;

    sharedMemorySemaphore = sem_init(120621646);
    bufferEmptySemaphore = sem_init(220621646);
    bufferFullSemaphore = sem_init(320621646);
    capitalizedBufferSemaphore = sem_init(1120621646);
    capitalizedBufferEmptySemaphore = sem_init(2220621646);
    capitalizedBufferFullSemaphore = sem_init(3320621646);

    sem_set(sharedMemorySemaphore, 1);
    sem_set(bufferEmptySemaphore, 1);
    sem_set(bufferFullSemaphore, 0);
    sem_set(capitalizedBufferSemaphore, 1);
    sem_set(capitalizedBufferEmptySemaphore, 1);
    sem_set(capitalizedBufferFullSemaphore, 0);

    char *buffer;
    buffer = (char *)getmem(420621646);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        PS(bufferEmptySemaphore);
        PS(sharedMemorySemaphore);
        PS(capitalizedBufferSemaphore);

        *buffer = ch;

        VS(sharedMemorySemaphore);
        VS(bufferFullSemaphore);
        VS(capitalizedBufferSemaphore);

        for (int i = 0; i < 1000000; i++);
    }

    printf("Producer process ended\n");
}
