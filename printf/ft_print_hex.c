/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:48:18 by iaratang          #+#    #+#             */
/*   Updated: 2025/09/02 15:23:43 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, int lcase)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_print_hex(n / 16, lcase);
	}
	if (lcase == 0)
	{
		write(1, &"0123456789abcdef"[n % 16], 1);
	}
	else
	{
		write(1, &"0123456789ABCDEF"[n % 16], 1);
	}
	i++;
	return (i);
}
