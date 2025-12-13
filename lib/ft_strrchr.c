/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:53:18 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/23 20:15:47 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (str[i])
	{
		if (str[i] == (unsigned char) c)
		{
			last = i;
		}
		i++;
	}
	if (str[i] == (unsigned char) c)
		last = i;
	if (last >= 0)
		return ((char *)&str[last]);
	return (NULL);
}
