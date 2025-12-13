/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:10:39 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/24 17:44:08 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *c);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;

	len_src = ft_strlen(src);
	if (len_src + 1 < dstsize)
		ft_memcpy(dst, src, len_src + 1);
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize -1);
		dst[dstsize - 1] = '\0';
	}
	return (len_src);
}
