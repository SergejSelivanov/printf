/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:57:20 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:57:22 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_ptr(long long n, char *flags, int *res_value, int *star)
{
	char	*b;
	int		length;
	char	*joined_str;

	b = (n == 0 && ft_strchr(flags, '.')) ? "" : ft_itoa_hex_ptr(n);
	if (star[0] != 0)
	{
		if (star[0] < 0)
		{
			joined_str = ft_strjoin("-", flags);
			flags = joined_str;
			free(joined_str);
			star[0] = star[0] * -1;
		}
		length = star[0];
	}
	else
	{
		length = ft_atoi(flags);
		if (length < 0)
			length = length * -1;
	}
	ft_options_ptr(flags, res_value, &length, b);
}

void	ft_options_ptr(char *flags, int *res_value, int *length, char *b)
{
	if (ft_strchr(flags, '-'))
	{
		ft_putstr_fd("0x", 1);
		*res_value += 2;
		ft_putstr_fd(b, 1);
		*res_value += ft_strlen(b);
		while ((*length)-- > (int)ft_strlen(b) + 2)
		{
			*res_value += 1;
			write(1, " ", 1);
		}
	}
	else
	{
		while ((*length)-- > (int)ft_strlen(b) + 2)
		{
			*res_value += 1;
			write(1, " ", 1);
		}
		ft_putstr_fd("0x", 1);
		*res_value += 2;
		ft_putstr_fd(b, 1);
		*res_value += ft_strlen(b);
	}
}
