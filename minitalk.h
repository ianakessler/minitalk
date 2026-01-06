/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:05:20 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/13 14:50:54 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

# define _DEFAULT_SOURCE

# include "lib/libft.h"
# include "printf/ft_printf.h"

# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_signal
{
	unsigned char	current_char;
	int				client_pid;
	int				bits_received;
}					t_signal;

#endif
