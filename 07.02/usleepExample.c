#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Sleeping for 500000 microseconds...\n");
    usleep(500000); // The program waits 500000 microseconds that is 0.5 seconds
    printf("Done sleeping.\n");
    return 0;
}
