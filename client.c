#include <signal.h>
#include "libft/libft.h"

/*
 * This function sends character through UNIX signals.
 * After sending a SIGUSR based on the bit to send, the
 * client will wait for an ack from the server.
 * The sleep will prevent busy waiting.
 */
volatile sig_atomic_t ack_received = 0;

void ack_handler(int signum)
{
	ft_printf("ack received\n");
	ack_received = 1;
}

void send_char(char c, int pid)
{
	int bit;
	int i;

	i = 7;
	ft_printf("Sending char %c\n", c);
	while (i >= 0)
	{
		ack_received = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		ft_printf("bit %d sent.\n", bit);
		while(!ack_received)
			usleep(1000);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	signal(SIGUSR1, ack_handler);
	ft_printf("Message to send: %s\n", message);
	while (*message)
	{
		send_char(*message, pid);
		message++;
    }
    return (0);
}