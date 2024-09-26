#include <stdio.h>
#include <shared.h>
#include <ctype.h>

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
    char *capitalizedBuffer;
    buffer = (char *)getmem(420621646);
    capitalizedBuffer = (char *)getmem(520621646);

    for (char ch = 'A'; ch <= 'Z'; ++ch) {
        PS(bufferFullSemaphore);
        PS(sharedMemorySemaphore);
        PS(capitalizedBufferSemaphore);

        char temp = *buffer;
        *capitalizedBuffer = toupper(temp);

        VS(sharedMemorySemaphore);
        VS(capitalizedBufferSemaphore);
        VS(capitalizedBufferFullSemaphore);

        for (int i = 0; i < 1000000; i++);
    }

    printf("\nCapitalization finished");
}
