#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

//The sigaction structure is like
// struct sigaction {
//Function to be called when the signal is received, is a pointer to a function that takes an integer as an argument, this integer is the signal number
//     void (*sa_handler)(int);
//Set of signals that will be blocked while the signal is being handled
//     sigset_t sa_mask;
//Flags that will be used to modify the behavior of the signal
//     int sa_flags;

//Function that will be called when the signal is received
void    signal_handler(int signum) {
    printf("Received signal %d\n", signum);
    exit(0);

    //To restore the default signal handler
    /*struct sigaction action;
    action.sa_handler = SIG_DFL; 
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    sigaction(SIGINT, &action, NULL);*/
}

int main(void) {
    // Create a sigaction structure
    struct sigaction action;
    // Set the signal handler to the function signal_handler
    action.sa_handler = signal_handler;
    //Means that no signals will be blocked while the signal is being handled, sa_mask is empty
    sigemptyset(&action.sa_mask);
    //No flags are set
    action.sa_flags = 0;

    // Set the signal handler for SIGINT
    // SIGINT is the signal that is sent when the user presses Ctrl+C
    // The signal handler will be called when the signal is received
    sigaction(SIGINT, &action, NULL);

    while (1) {
    // Do some work
    }

  return 0;
}