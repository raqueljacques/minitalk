/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdos-san <rdos-san@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:03:06 by rdos-san          #+#    #+#             */
/*   Updated: 2025/02/08 12:17:17 by rdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <server_pid> <signal_type>\n", argv[0]);
		printf("Signal types: 1 for SIGUSR1, 2 for SIGUSR2\n");
		return 1;
	}

	int	server_pid = atoi(argv[1]);
	int	signal_type = atoi(argv[2]);

	if (signal_type == 1)
	{
		kill(server_pid, SIGUSR1);
	}
	else if (signal_type == 2)
	{
		kill(server_pid, SIGUSR2);
	}
	else
	{
		printf("Invalid signal type! Use 1 for SIGUSR1, 2 for SIGUSR2\n");
	}

	return 0;
}
