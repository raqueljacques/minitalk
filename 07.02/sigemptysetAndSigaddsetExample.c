#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	main(void)
{
	//Initializes an empty signal set
	sigset_t	signal_set;
	
	sigemptyset(&signal_set);

	sigaddset(&signal_set, SIGINT);
	
	//Block SIGINT
	sigprocmask(SIG_BLOCK, &signal_set, NULL);
	printf("SIGINT bloqueado!\n");

	sleep(5);

	//Unblock SIGINT
	sigprocmask(SIG_UNBLOCK, &signal_set, NULL);
	printf("SIGINT desbloqueado!");

	while (1)
	{
		sleep(1);
	}
	return 0;
}
