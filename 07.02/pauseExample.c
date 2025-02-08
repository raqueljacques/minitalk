#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int signum) {
    printf("Received signal %d! Exiting...\n", signum);
}

int main(void) {
    signal(SIGINT, handle_signal);

    printf("Entering pause... Press Ctrl+C to exit.\n");
    pause();  // Wait for a signal to be received
    printf("This will only execute if pause() is interrupted by a signal.\n");

    return 0;
}
