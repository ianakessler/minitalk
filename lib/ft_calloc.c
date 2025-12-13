/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:49:31 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/30 17:50:27 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = (void *)malloc(count * size);
	if (!tmp)
		return (NULL);
	while (tmp[i])
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
