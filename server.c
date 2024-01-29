/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:00:45 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/29 22:03:38 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %i\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(1);
	while (42)
	{
		pause();
		usleep(1);
	}
}

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static char	c;
	static int	bit;
	static char	*str;

	(void) context;
	if (signal == SIGUSR1)
	{
		c |= (1 << bit);
		bit++;
	}
	else if (signal == SIGUSR2)
		bit++;
	if (bit == 8)
	{
		if (c == 0)
			str_print(&str, info->si_pid);
		else
			str = str_append(str, c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	str_print(char **str, int pid)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		write(1, &(*str)[i], 1);
		i++;
	}
	free(*str);
	*str = 0;
	kill(pid, SIGUSR2);
}

char	*str_append(char *str, char c)
{
	static int	len;
	char		*str_new;

	if (!str)
	{
		len = 1;
		str_new = ft_calloc(sizeof(*str), len + 1);
		if (str_new == NULL)
			exit(3);
		str_new[0] = c;
		return (str_new);
	}
	str_new = ft_calloc(sizeof(*str_new), len + 2);
	if (!str_new)
	{
		free(str);
		exit(2);
	}
	str_new = ft_memmove(str_new, str, len + 1);
	str_new[len] = c;
	len++;
	free(str);
	return (str_new);
}
