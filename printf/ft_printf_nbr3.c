/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:55:55 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:55:57 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_nbr_wslall(int numb, int width, int length, char *flags)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (numb >= 0)
			i += ft_wsl1_nbr(numb, &length, flags, &width);
		else
		{
			i += ft_wsl2_nbr(&numb, &width, &length);
			i += ft_wsl3_nbr(&width, numb);
		}
	}
	else
		i += ft_wsl4_nbr(numb, &length, flags);
	return (i);
}

int		ft_nbr_wblall(int numb, int width, int length, char *flags)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (numb >= 0)
			i += ft_wbl1_nbr(numb, &length, &width);
		else
			i += ft_wbl2_nbr(numb, &length, &width);
	}
	else
	{
		if (numb >= 0)
			i += ft_wbl3_nbr(numb, flags, &length, &width);
		else
			i += ft_wbl4_nbr(numb, &width, &length, flags);
	}
	return (i);
}

void	ft_wz31_nbr(int *numb, int *length, char *symb, int *i)
{
	if (*numb >= 0)
	{
		ft_putnbr_fd_long(*numb, 1);
		while ((*length)-- > count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb))
			write(1, &*symb, 1);
	}
	else
	{
		*numb = *numb * -1;
		write(1, "-", 1);
		*i += 1;
		ft_putnbr_fd_long(*numb, 1);
		while ((*length)-- > count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb) + 1)
			write(1, &*symb, 1);
	}
}

void	ft_wz21_nbr(int *numb, int *length, char *symb, int *i)
{
	if (*numb == -2147483648)
	{
		*length -= 1;
		*i += 1;
	}
	while ((*length)-- > count_tens(*numb, if_negative(*numb))
	+ if_negative(*numb))
	{
		*i += 1;
		write(1, &*symb, 1);
	}
	*numb == -2147483648 ? ft_putnbr_fd(*numb, 1) : ft_putnbr_fd_long(*numb, 1);
}

void	ft_length_short(int numb, int *width, int *length, int *res_value)
{
	if (numb == -2147483648)
		ft_minint(width, length, 1, res_value);
}
