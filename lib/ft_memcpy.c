/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 15:48:43 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/23 20:27:58 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	if (!src && !dst)
		return (dst);
	ptr_dst = (unsigned char *) dst;
	ptr_src = (unsigned char *) src;
	while (n > 0)
	{
		*(ptr_dst++) = *(ptr_src++);
		n--;
	}
	return (dst);
}
