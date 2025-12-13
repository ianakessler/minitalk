/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:59:07 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/24 15:25:32 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	chr;
	size_t			i;

	chr = (unsigned char) c;
	ptr = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == chr)
			return ((unsigned char *)&ptr[i]);
		i++;
	}
	return (NULL);
}
