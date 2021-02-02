/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 16:00:59 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 16:01:01 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wsl_uns(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, " ", 1);
		}
		i += ft_count_digits(numb);
		ft_putnbr_fd_unsigned(numb, 1);
	}
	else
	{
		ft_putnbr_fd_unsigned(numb, 1);
		i += ft_count_digits(numb);
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

int		ft_wz_unsg(char *flags, char *symb, int *length, int numb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
		i += ft_count_digits(numb);
		ft_putnbr_fd_unsigned(numb, 1);
	}
	else
	{
		ft_putnbr_fd_unsigned(numb, 1);
		i += ft_count_digits(numb);
		while ((*length)-- > ft_count_digits(numb))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}
