/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:15:43 by iaratang          #+#    #+#             */
/*   Updated: 2025/08/08 14:21:29 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *) src;
	if (!dst && !src)
		return (dst);
	if (ptr_dst > ptr_src)
	{
		while (len--)
			*(ptr_dst + len) = *(ptr_src + len);
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*(ptr_dst++) = *(ptr_src++);
			i++;
		}
	}
	return (dst);
}
