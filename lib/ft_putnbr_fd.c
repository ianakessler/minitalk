/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:21:06 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/31 15:41:14 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -2147483647)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0 && n > -2147483647)
	{
		ft_putchar('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar(n + '0', fd);
	}
}

static void	ft_putchar(char c, int fd)
{
	write(fd, &c, 1);
}
