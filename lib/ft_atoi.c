/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 18:40:10 by iaratang          #+#    #+#             */
/*   Updated: 2025/07/30 17:52:48 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		i;
	int		signal;
	long	res;

	res = 0;
	i = 0;
	signal = 1;
	while (str[i])
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				signal = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + (str[i] - '0');
			i++;
		}
		return (res * signal);
	}
	return (0);
}
