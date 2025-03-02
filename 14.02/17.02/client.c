/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:52:33 by rdos-san          #+#    #+#             */
/*   Updated: 2025/02/14 19:52:35 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int send_char(int pid, char c)
{
    int i;

    i = 0;
    while (i < 8)
    {
        // c is a char that id 1 byte long (8 bits).
        // The & operator is used to check if the bit is 1 or 0.
        // The reference in c will be in the last bit.
        // The c & 1 will be 1 if the last bit is 1 and 0 if the last bit is 0.
        // Is compared with 1 because 1 binary is 00000001 and we want to check the last bit.
        /*
            example C = 'A'  (01000001)
            1º 
                c = 01000001
                c & 1 ->
                    01000001
                    00000001 (mask)
                    --------
                    00000001
                    (send SIGUSR1)
                c >>= 1 → 00100000
            2º
                c = 00100000
                c & 1 ->
                    00100000
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)
                c >>= 1 -> 00010000
            3º
                c = 00010000
                c & 1 ->
                    00010000
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)
                c >>= 1 -> 00001000
            4º
                c = 00001000
                c & 1 ->
                    00001000
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)
                c >>= 1 -> 00000100
            5º
                c = 00000100
                c & 1 ->
                    00000100
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)
                c >>= 1 -> 00000010
            6º
                c = 00000010
                c & 1 -> 
                    00000010
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)
                c >>= 1 -> 00000001
            7º
                c = 00000001
                c & 1 ->
                    00000001
                    00000001 (mask)
                    --------
                    00000001
                    (send SIGUSR1)
                c >>= 1 -> 00000000
            8º
                c = 00000000
                c & 1 ->
                    00000000
                    00000001 (mask)
                    --------
                    00000000
                    (send SIGUSR2)              
        */
        if (c & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        // The >> operator is used to move the bits to the right. Doing this, the last bit will be the next bit.
        c >>= 1;
        i++;
        usleep(100);
    }
    return (0);
}

int send_message(int pid, char *message)
{
    int i;

    i = 0;
    while (message[i] != '\0')
    {
        send_char(pid, message[i]);
        i++;
    }
    send_char(pid, '\0');
    return (0);
}

// The server must be able to send the message to the client.
int main(int agrc, char **argv)
{
    int pid;
    char *message;

    if (agrc != 3)
    {
        ft_printf("The input must be: ./client [PID] [message]\n");
        return (1);
    }

    pid = ft_atoi(argv[1]);
    if (!pid)
    {
        ft_printf("The PID is invalid.\n");
        return (1);
    }
    message = argv[2];
    if (message[0] == '\0')
    {
        ft_printf("The message is invalid.\n");
        return (1);
    }
    send_message(pid, message);
    return (0);
}
