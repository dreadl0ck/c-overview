#include <sys/shm.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) 
{
    int shmid = shmget(IPC_PRIVATE, 1024, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("error requesting shared memory!");
        return EXIT_FAILURE;
    }

    void *shmaddr = shmat(shmid, 0, SHM_RDONLY);
    if (shmaddr != NULL) {
        printf("successfully attached shared memory segment: %p\n", shmaddr);
    }

    if (shmdt(shmaddr) < 0) {
        perror("Error detaching shared memory segment!");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
