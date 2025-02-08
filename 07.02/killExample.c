#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int	main()
{
	//get the current process id
	pid_t pid = getpid();
	//send the signal to the process
	int result = kill(pid, SIGKILL);
	//check if the signal was sent
	if (result == 0)
	{
		printf("Signal sent successfully\n");
	}
	else
	{
		printf("Error sending signal\n");
	}
	return(0);
}