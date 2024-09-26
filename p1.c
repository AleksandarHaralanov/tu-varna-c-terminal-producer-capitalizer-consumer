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

    char *buffer;
    buffer = (char *)getmem(520621646);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        PS(capitalizedBufferFullSemaphore);
        PS(capitalizedBufferSemaphore);
        PS(sharedMemorySemaphore);

        printf("%c\n", *buffer);

        VS(bufferEmptySemaphore);
        VS(sharedMemorySemaphore);
        VS(capitalizedBufferSemaphore);

        for (int i = 0; i < 1000000; i++);
    }

    sem_remove(sharedMemorySemaphore);
    sem_remove(bufferEmptySemaphore);
    sem_remove(bufferFullSemaphore);
    sem_remove(capitalizedBufferSemaphore);
    sem_remove(capitalizedBufferEmptySemaphore);
    sem_remove(capitalizedBufferFullSemaphore);

    printf("\nConsumer process ended\n");
}
