#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void sig_handler(int signum, siginfo_t *info, void *context)
{
	if (signum == SIGUSR1)
		ft_printf("0 ");
	else if (signum == SIGUSR2)
		ft_printf("1 ");
	ft_printf("Received from %d\n", info -> si_pid);
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
