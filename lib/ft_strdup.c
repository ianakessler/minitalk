/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:11:29 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/24 18:25:39 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy_s1;
	size_t	i;

	i = 0;
	cpy_s1 = (char *)malloc(ft_strlen(s1) + 1);
	if (!cpy_s1)
		return (NULL);
	while (s1[i])
	{
		cpy_s1[i] = s1[i];
		i++;
	}
	cpy_s1[i] = 0;
	return (cpy_s1);
}
