/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:55:44 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/29 22:07:55 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context);

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		return (1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	signal_send(ft_atoi(argv[1]), argv[2]);
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (signal == SIGUSR1)
		return ;
	else if (signal == SIGUSR2)
	{
		ft_printf("Message sent!\n");
		exit (0);
	}
}

void	signal_send(int pid, char *message)
{
	int	i;

	if (pid == 0)
		exit(1);
	while (*message)
	{
		char_send(pid, *message);
		message++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		pause();
	}
}

void	char_send(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
			pause();
		}
		else
		{
			kill(pid, SIGUSR2);
			pause();
		}
		i++;
	}
}
