/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:17:04 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/13 12:17:22 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *infos_sigaction, void *empty)
{
	static t_signal	config;
	(void) empty;

	if (config.client_pid != infos_sigaction->si_pid)
	{
		config.bits_received = 0;
		config.current_char = 0;
		config.client_pid = infos_sigaction->si_pid;
	}
	if (signal == SIGUSR1)
		config.current_char |= (1<<config.bits_received);
	config.bits_received++;
	if (config.bits_received == 8)
	{
		if (config.current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", config.current_char);
		config.bits_received = 0;
		config.current_char = 0;
	}
	if (infos_sigaction->si_pid > 0)
		kill(infos_sigaction->si_pid, SIGUSR1);
}

int main(void)
{
	pid_t				pid;
	struct sigaction	s_sigaction;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sigemptyset(&s_sigaction.sa_mask);
	s_sigaction.sa_flags = SA_SIGINFO;
	s_sigaction.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &s_sigaction, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &s_sigaction, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
