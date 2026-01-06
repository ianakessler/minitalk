/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:17:28 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/13 15:03:58 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int g_signal_flag = 0;

static void set_signal_flag(int signal)
{
	if (signal == SIGUSR1)
		g_signal_flag = 1;
}

void	send_signal(pid_t pid, unsigned char c)
{
	int i;

	i = 0;
	while (i < 8)
	{
		g_signal_flag = 0;
		if (((c >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		while (g_signal_flag == 0)
			pause();
	}
}

static void	print_usage(void)
{
	ft_printf("Wrong number of arguments...\n");
	ft_printf("Usage: ./client <SERVER_PID> <MESSAGE_STRING>\n");
	exit(0);
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sigaction;
	pid_t				server_pid;
	int					i;

	if (argc != 3)
		print_usage();
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0 || kill(server_pid, 0) == -1)
		return (1);
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = 0;
	s_sigaction.sa_handler = set_signal_flag;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		send_signal(server_pid, (unsigned char)argv[2][i]);
		i++;
	}
	send_signal(server_pid, '\0');
	return (0);
}
