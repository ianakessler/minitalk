/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 16:06:06 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/30 17:10:15 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*fill_word(const char *s, int start, int end);
static int	count_words(const char *s, char c);
static void	*ft_free(char **strs, int count);
static void	init_vars(size_t *i, size_t *j);

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	int		start_word;

	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res || !s)
		return (NULL);
	init_vars(&i, &j);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			start_word = i;
			while (s[i] && s[i] != c)
				i++;
			res[j] = fill_word(s, start_word, i);
			if (!res[j++])
				return (ft_free(res, j - 1));
		}
	}
	res[j] = 0;
	return (res);
}

static void	init_vars(size_t *i, size_t *j)
{
	*i = 0;
	*j = 0;
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *s, int start, int end)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc((end - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = 0;
	return (res);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}
