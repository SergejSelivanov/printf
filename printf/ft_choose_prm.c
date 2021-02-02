/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_prm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:01:53 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 16:01:56 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_choose_prm(char param, char *flags, va_list ap, int *res_value)
{
	int *star;

	star = (int *)malloc(sizeof(int) * 2);
	star = ft_check_star(flags, ap, star);
	if (param == 'c')
		ft_printf_char(va_arg(ap, int), flags, res_value, star);
	if (param == '%')
		ft_printf_char('%', flags, res_value, star);
	if (param == 'd' || param == 'i')
		ft_printf_nbr(va_arg(ap, int), flags, star, res_value);
	if (param == 's')
		ft_printf_str(va_arg(ap, char *), flags, star, res_value);
	if (param == 'u')
		ft_printf_unsigned(va_arg(ap, int), flags, star, res_value);
	if (param == 'x')
		ft_printf_hex_low(va_arg(ap, unsigned int), flags, star, res_value);
	if (param == 'X')
		ft_printf_hex_up(va_arg(ap, unsigned int), flags, star, res_value);
	if (param == 'p')
		ft_printf_ptr(va_arg(ap, long long), flags, res_value, star);
	free(star);
}

int			*ft_check_star(char *flags, va_list ap, int *star)
{
	int i;
	int j;

	i = 0;
	j = 0;
	star[0] = 0;
	star[1] = 0;
	while (flags[i] && ft_strchr(flags, '*'))
	{
		if (flags[i] == '*')
			j++;
		i++;
	}
	if (j == 2)
	{
		star[0] = va_arg(ap, int);
		star[1] = va_arg(ap, int);
	}
	else if (j > 0 && ft_strrchr(flags, '*') >
	ft_strrchr(flags, '.') && ft_strrchr(flags, '.'))
		star[1] = va_arg(ap, int);
	else if (j > 0)
		star[0] = va_arg(ap, int);
	return (star);
}

const char	*ft_search_flags2(const char *s, char **flags, int *i)
{
	if (*s == '-')
	{
		if (!ft_strchr(*flags, '-'))
		{
			(*flags)[*i] = *s;
			*i += 1;
		}
		s++;
	}
	else if (*s == '0')
	{
		if (ft_strchr(*flags, '-') || !(*(s - 1) == '0'))
		{
			(*flags)[*i] = *s;
			*i += 1;
		}
		s++;
	}
	else
	{
		(*flags)[*i] = *s;
		s++;
		*i += 1;
	}
	return (s);
}
