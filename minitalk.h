/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jburlama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 21:49:53 by jburlama          #+#    #+#             */
/*   Updated: 2024/01/29 21:50:21 by jburlama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include "libft/libft.h"

// client
void	signal_send(int pid, char *message);
void	signal_handler(int signal, siginfo_t *info, void *context);
void	char_send(int pid, char c);

// server
void	signal_handler(int signal, siginfo_t *info, void *context);
char	*str_append(char *str, char c);
void	str_print(char	**str, int pid);
#endif
