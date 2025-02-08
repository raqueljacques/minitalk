#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("The process id is %d\n", pid);
    return (0);
}