/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:54:11 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:54:14 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wbl4_nbr(int numb, int *width, int *length, char *flags)
{
	int		i;
	int		buf;
	char	symb;

	symb = ' ';
	if (ft_strchr("0", *flags))
		symb = '0';
	i = 0;
	buf = *width;
	numb = numb * -1;
	write(1, "-", 1);
	i++;
	while ((*width)-- > count_tens(numb, if_negative(numb)) + if_negative(numb))
	{
		i++;
		write(1, "0", 1);
	}
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	ft_putnbr_fd_long(numb, 1);
	while ((*length)-- - buf > 1)
	{
		write(1, &symb, 1);
		i++;
	}
	return (i);
}

int		ft_wsl1_nbr(int numb, int *length, char *flags, int *width)
{
	int i;

	i = 0;
	if (numb >= 0)
	{
		while ((*length)-- > count_tens(numb, if_negative(numb))
		+ if_negative(numb))
		{
			i++;
			if (ft_strchr(flags, '*') && *width == 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
		i += count_tens(numb, if_negative(numb)) + if_negative(numb);
		ft_putnbr_fd_long(numb, 1);
	}
	return (i);
}

int		ft_wsl2_nbr(int *numb, int *width, int *length)
{
	int i;

	i = 0;
	*numb = *numb * -1;
	if (*width > count_tens(*numb, if_negative(*numb)) + if_negative(*numb))
	{
		while ((*length)-- - (*width - count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb) + 1)
		> count_tens(*numb, if_negative(*numb)) + if_negative(*numb))
		{
			i++;
			write(1, " ", 1);
		}
	}
	else
	{
		while ((*length)-- > count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb) + 1)
		{
			i++;
			write(1, " ", 1);
		}
	}
	return (i);
}

int		ft_wsl3_nbr(int *width, int numb)
{
	int i;

	i = 0;
	write(1, "-", 1);
	i++;
	while ((*width)-- > count_tens(numb, if_negative(numb)) + if_negative(numb))
	{
		i++;
		write(1, "0", 1);
	}
	ft_putnbr_fd_long(numb, 1);
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	return (i);
}

int		ft_wsl4_nbr(int numb, int *length, char *flags)
{
	int		i;
	char	symb;

	i = 0;
	symb = ' ';
	if (ft_strchr("0", *flags))
		symb = '0';
	ft_putnbr_fd_long(numb, 1);
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	while ((*length)-- > count_tens(numb, if_negative(numb))
	+ if_negative(numb))
	{
		i++;
		write(1, &symb, 1);
	}
	return (i);
}
