#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void sig_handler(int signum, siginfo_t *info, void *context)
{
	static int count = 0;
	static char c;

	if (signum == SIGUSR1)
		write(1, "0", 1);
	else if (signum == SIGUSR2)
		write(1, "1", 1);
	count++;
	kill(info -> si_pid, SIGUSR1);
}

int main()
{
	struct sigaction sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server Running...\nPID: %d\n", getpid());
	while(1)
	{
		pause();
	}
	return (0);
}
