/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:54:54 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:54:56 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wz1_nbr(int numb, int *length, char *symb)
{
	int i;

	i = 0;
	while ((*length)-- > count_tens(numb, if_negative(numb))
	+ if_negative(numb))
	{
		i++;
		write(1, &*symb, 1);
	}
	ft_putnbr_fd_long(numb, 1);
	i += count_tens(numb, if_negative(numb)) + if_negative(numb);
	return (i);
}

int		ft_wz2_nbr(int *numb, int *length, char *symb)
{
	int i;

	i = 0;
	if (*symb == ' ')
		ft_wz21_nbr(numb, length, symb, &i);
	else
	{
		*numb = *numb * -1;
		write(1, "-", 1);
		i++;
		while ((*length)-- > count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb) + 1)
		{
			i++;
			write(1, &*symb, 1);
		}
		ft_putnbr_fd_long(*numb, 1);
	}
	i += count_tens(*numb, if_negative(*numb)) + if_negative(*numb);
	return (i);
}

int		ft_wz3_nbr(int *numb, int *length, char *symb)
{
	int i;

	i = 0;
	if (*length >= count_tens(*numb, if_negative(*numb))
	+ if_negative(*numb) && *numb >= 0)
		i += *length - (count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb));
	else if (*length >= count_tens(*numb, if_negative(*numb))
	+ if_negative(*numb) + 1)
		i += *length - (count_tens(*numb, if_negative(*numb))
		+ if_negative(*numb));
	if (*numb == -2147483648 && *length != 0)
		i--;
	ft_wz31_nbr(numb, length, symb, &i);
	i += count_tens(*numb, if_negative(*numb)) + if_negative(*numb);
	return (i);
}

void	ft_minint(int *width, int *length, int which_case, int *res_value)
{
	if (which_case == 1)
	{
		if (*length >= 8)
			*length -= 8;
		else
			*length = 0;
		*res_value += 8;
	}
	else if (which_case == 2)
	{
		if (*width >= 8)
			*width -= 8;
		else
			*width = 0;
	}
}

int		ft_nbr_wzall(char *flags, int numb, int length, char symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		if (numb >= 0)
			i += ft_wz1_nbr(numb, &length, &symb);
		else
			i += ft_wz2_nbr(&numb, &length, &symb);
	}
	else
		i += ft_wz3_nbr(&numb, &length, &symb);
	return (i);
}
