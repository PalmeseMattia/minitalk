/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpalmese <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 21:50:55 by dpalmese          #+#    #+#             */
/*   Updated: 2024/05/24 22:07:50 by dpalmese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include "../libft/libft.h"

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c = c << 1;
	else if (signum == SIGUSR2)
		c = (c << 1) | 1;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	kill(info -> si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server Running...\nPID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
