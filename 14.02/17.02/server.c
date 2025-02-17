/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:52:43 by rdos-san          #+#    #+#             */
/*   Updated: 2025/02/14 19:52:45 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void signal_handler(int signum)
{
    // The character and the index must be static because the signal handler is called multiple times.
    static char c = 0;
    static int i = 0;

    //Is not necessary to check SIGUSR2 because the char is initialized to 0.
    if (signum == SIGUSR1)
    // OR operator: 1 or 0 = 1; 1 or 1 = 1; 0 or 0 = 0
        // << operator: 1 << 0 = 1; 1 << 1 = 10; 1 << 2 = 100; 1 << 3 = 1000]
        /* << operator:
            00000001 << 0 = 00000001;
            00000001 << 1 = 00000010;
            00000001 << 2 = 00000100;
            00000001 << 3 = 00001000;
        */
        /* |= operator:
            00000000 |= 00000001 = 00000001;
            00000001 |= 00000010 = 00000011;
            00000011 |= 00000100 = 00000111;
        */
        c |= (1 << i);
        /*
            00000000 |= (1 << 0) = 00000001
            00000001 |= (1 << 1) = 00000011
            00000011 |= (1 << 2) = 00000111
            00000111 |= (1 << 3) = 00001111
            00001111 |= (1 << 4) = 00011111
            00011111 |= (1 << 5) = 00111111
            00111111 |= (1 << 6) = 01111111
            01111111 |= (1 << 7) = 11111111
        */
    i++;
    if (i == 8)
    {
        // If the character is the null character, print a new line and reset the character and the index.
        // Why the null character? Because the client sends the null character to indicate the end of the message.
        if (c == '\0')
            ft_printf("\n");
        else
            ft_printf("%c", c);
        i = 0;
        c = 0;
    }
}


// The server must be able to receive the signal from the client and display the message.
int main(void)
{
    struct  sigaction action;

    ft_printf("*****Server is running*****\n");
    ft_printf("Server's PID: %d\n", getpid());

    sigemptyset(&action.sa_mask);
    action.sa_handler = signal_handler;
    action.sa_flags = 0;
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);

    //SIGUSR1: bit 1
    //SIGUSR2: bit 0

    while (1)
        pause();
}
