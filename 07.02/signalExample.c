#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signum)
{
	printf("Received SIGINT! %d\n", signum);
	exit(0);
}

int	main()
{
	//Set the signal_handler for both signals
	signal(SIGINT, signal_handler); //CTRL+C
	signal(SIGTERM, signal_handler);//KILL

	while (1)
	{
		//Do something
	}
	return(0);
}
