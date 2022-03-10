/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:52:08 by wzouf             #+#    #+#             */
/*   Updated: 2022/03/10 15:44:11 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	handler(int sig, siginfo_t *info, void *unused)
{
	static int	pid;
	static char	y;
	static int	i;

	(void) unused;
	if (pid != info->si_pid)
	{
		i = 0;
		y = 0;
		pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		y = (y << 1) + 1;
	else
		y = y << 1;
	i++;
	if (i == 8)
	{
		if (y == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &y, 1);
		i = 0;
		y = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction (SIGUSR1, &sa, NULL);
	sigaction (SIGUSR2, &sa, NULL);
	ft_printf("my pid is : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
