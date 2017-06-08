#include <signal.h>
#include <stdio.h>

// demonstrate signal handling on UNIX systems

void mySigHandler(int signalCode) 
{
    switch (signalCode) {
        case SIGINT:
        puts("caught SIGINT!");

        // signal default
        signal(SIGINT, SIG_DFL);
    }
}

int main(void) 
{
    // set handler
    puts("setting custom handler for SIGINT...");
    signal(SIGINT, mySigHandler);

    // ignore signal
    puts("ignoring SIGABRT...");
    signal(SIGABRT, SIG_IGN);
	
    // send a signal to current process
    puts("sending SIGABRT to current process...");
    raise(SIGABRT);

    // send SIG to process
    puts("sending SIGINT to current process...");
    kill(getpid(), SIGINT);

    // restore signal default
    puts("restoring signal defaults...");
    signal(SIGABRT, SIG_DFL);
    signal(SIGINT, SIG_DFL);
	
    printf("send a SIGINT with ctrl-C to quit the loop\n");
    while (1) {}
}
