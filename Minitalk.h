/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 11:29:20 by wzouf             #+#    #+#             */
/*   Updated: 2022/03/10 15:45:23 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stdio.h>
# define PTAB "0123456789abcdef"
# define XTAB "0123456789ABCDEF"

void	binary(int pid, int nb);
void	ft_handler(int sig);
void	handler(int sig, siginfo_t *info, void *unused);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
void	ft_compare(char c, va_list args);
int		ft_printf(const char *s, ...);
void	ft_putchar(char c);
void	printhex(unsigned int nb);
void	printp(unsigned long nb);
void	printhexm(unsigned int nb);
int		ft_atoi(const char *str);

int		g_count;

#endif