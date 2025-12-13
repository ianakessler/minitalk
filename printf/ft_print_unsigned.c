/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:09:00 by iaratang          #+#    #+#             */
/*   Updated: 2025/09/02 15:21:45 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_print_unsigned(n / 10);
	}
	write(1, &"0123456789"[n % 10], 1);
	i++;
	return (i);
}
