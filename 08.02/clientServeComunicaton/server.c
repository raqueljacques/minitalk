/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:17:26 by rdos-san          #+#    #+#             */
/*   Updated: 2025/02/08 12:18:59 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		printf("Hello world!\n");
	}
	else if (signum == SIGUSR2)
	{
		printf("The random number is: %d\n", rand() % 100);
	}
}

int	main()
{
	struct	sigaction action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	printf("Server PID: %d\n", getpid());

	while (1) {
		pause();
	}

	return 0;
}
