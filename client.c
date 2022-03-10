/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:29:43 by wzouf             #+#    #+#             */
/*   Updated: 2022/03/10 15:57:25 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minitalk.h"

void	binary(int pid, int nb)
{
	int	i;

	i = 8;
	while (i)
	{
		i--;
		if (nb & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
	}
}

void	ft_handler(int sig)
{
	(void) sig;
	printf("Signal recieved\n");
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	if (argc != 3)
		return (ft_printf("Error : arguments\n"), 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || kill(pid, 0) != 0)
		return (ft_printf("Wrong pid!\n"), 1);
	i = 0;
	signal(SIGUSR1, ft_handler);
	while (argv[2][i])
	{
		binary(pid, argv[2][i]);
		i++;
	}
	binary (pid, 0);
}
