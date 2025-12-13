/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 16:41:16 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/12 17:18:13 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_num(unsigned long n, const char *hex_chars);

int	ft_print_pointer(void *ptr)
{
	unsigned long	pointer_num;
	const char		*hex_str;
	int				i;

	i = 0;
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	pointer_num = (unsigned long) ptr;
	hex_str = "0123456789abcdef";
	write(1, "0x", 2);
	i += 2;
	if (pointer_num >= 16)
	{
		i += print_num(pointer_num / 16, hex_str);
	}
	write(1, &"0123456789abcdef"[pointer_num % 16], 1);
	i++;
	return (i);
}

static int	print_num(unsigned long n, const char *hex_chars)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += print_num(n / 16, hex_chars);
	}
	write(1, &"0123456789abcdef"[n % 16], 1);
	i++;
	return (i);
}
