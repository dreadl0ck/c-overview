#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NUM_THREADS 500

pthread_t threads[NUM_THREADS];
int client_count = 0;
int sock;
char *string = "Hey was geht ab?\n";

void sigHandler(int signalCode) 
{
    puts("closing socket...");
    close(sock);
    exit(EXIT_SUCCESS);
}

void *handleConn(void *fd) 
{
    send((int)fd, string, strlen(string), 0);
    shutdown((int)fd, SHUT_RDWR);
    sleep(3);
    client_count--;
    pthread_exit(NULL);
}

int main(void) 
{

    int option = 1;

    // 1. Socket anlegen
    sock = socket(AF_INET, SOCK_STREAM, 0);

    // set socketopt to SO_REUSEADDR
    if((setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*) &option, sizeof(option))) < 0) {
        perror("setsockopt failed!");
        close(sock);
        exit(2);
    }

    // 2. Binden einer addresse an den socket
    struct sockaddr_in server;
    server.sin_family = PF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);
    if ((bind(sock, (struct sockaddr *) &server, sizeof(server))) < 0) {
        perror("ERROR binding to port");
        exit(1);
    }

    // 3. Auf Anfragen warten
    listen(sock, NUM_THREADS);

    puts("Listening on 127.0.0.1:8080 ...");

    socklen_t client_len = sizeof(server);

    signal(SIGINT, sigHandler);

    while (1 && client_count <= NUM_THREADS ) 
	{

        // 4. Verbindungen akzeptieren
        struct sockaddr_in client;
        int fd;

        fd = accept(sock, (struct sockaddr *) &client, &client_len);

        if (fd > 0) 
		{
            if (client_count < NUM_THREADS) 
			{
                printf("client connected! (%d/%d)\n", client_count, NUM_THREADS);
                client_count++;
                int rc;
                rc = pthread_create(&threads[client_count], NULL, handleConn, (void*)fd);
            } else {
                puts("no more clients allowed!");
                close(fd);
            }
        }
    }

    pthread_exit(NULL);
    return EXIT_SUCCESS;
}
