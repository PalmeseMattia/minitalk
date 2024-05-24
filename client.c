#include <signal.h>
#include "libft/libft.h"

volatile sig_atomic_t ack_received = 0;

void ack_handler(int signum)
{
	ack_received = 1;
}

/*
 * This function sends characters through UNIX signals.
 * After sending a SIGUSR based on the bit to send, the
 * client will wait for an ack from the server.
 * The sleep will prevent busy waiting.
 */
void send_char(char c, int pid)
{
	int bit;
	int i;

	i = 7;
	while (i >= 0)
	{
		ack_received = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		while(!ack_received)
			usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: <PID> <MESSAGE>\n");
		exit(EXIT_FAILURE);
	}
	if (!ft_strisnum((const char *)argv[1]))
		exit(EXIT_FAILURE);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
	{
		ft_printf("PID is less than 0!\n");
		exit(EXIT_FAILURE);
	}
	message = argv[2];
	signal(SIGUSR1, ack_handler);
	while (*message)
	{
		send_char(*message, pid);
		message++;
    }
	ft_printf("Done\n");
    return (0);
}
