/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaratang <iaratang@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 12:19:00 by iaratang          #+#    #+#             */
/*   Updated: 2025/12/13 12:03:05 by iaratang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_print_hex(unsigned int n, int lcase);
int	ft_printf(const char *format, ...);
int	ft_print_unsigned(unsigned int n);
int	ft_strchr_printf(char c, char *set);
int	ft_print_pointer(void *ptr);
int	ft_print_str(char *str);
int	ft_print_number(int n);
int	ft_print_char(char c);

#endif
