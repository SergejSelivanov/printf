/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:46:09 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:46:13 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_char(char symb, char *flags, int *res_value, int *star)
{
	int		length;
	char	delim;

	length = 0;
	delim = '\0';
	flags = ft_length_init(flags, star, &length, &delim);
	if (ft_strchr(flags, '-'))
	{
		write(1, &symb, 1);
		while (length-- > 1)
		{
			write(1, &delim, 1);
			*res_value += 1;
		}
	}
	else
	{
		while (length-- > 1)
		{
			write(1, &delim, 1);
			*res_value += 1;
		}
		write(1, &symb, 1);
	}
	*res_value += 1;
}
