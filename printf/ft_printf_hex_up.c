/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:51:14 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:51:16 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_hex_up(unsigned int numb, char *flags,
	int *star, int *res_value)
{
	char	symb;
	int		length;
	int		width;

	symb = '\0';
	length = 0;
	width = 0;
	flags = ft_length_init(flags, star, &length, &symb);
	if (ft_strchr(flags, '.') && star[1] >= 0)
	{
		ft_hex_init_width(&width, star, flags);
		if (width <= 0 && numb == 0 && star[1] != 0)
			ft_hex_znazw(&length, res_value, 3, numb);
		else if (width <= 0 && numb == 0 && star[1] == 0)
			ft_hex_znazw(&length, res_value, 0, numb);
		else if (width > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			(!ft_strchr(flags, '-')) ? ft_h_up_wll1(&width, res_value, &length,
			numb) : (*res_value += ft_h_up_wll2(&width, &length, numb, &symb));
		}
		else
			*res_value += ft_hex_up_wsl(flags, &length, numb, &symb);
	}
	else
		*res_value += ft_hex_up_nd(flags, &length, numb, &symb);
}

void	ft_h_up_wll1(int *width, int *res_value, int *length, int numb)
{
	while ((*length)-- - *width > 0)
	{
		*res_value += 1;
		write(1, " ", 1);
	}
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
	{
		*res_value += 1;
		write(1, "0", 1);
	}
	*res_value += ft_strlen(ft_itoa_hex_upper(numb));
	ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
}

int		ft_h_up_wll2(int *width, int *length, int numb, char *symb)
{
	int buf;
	int i;

	i = 0;
	buf = *width;
	while ((*width)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
	{
		i++;
		write(1, "0", 1);
	}
	i += ft_strlen(ft_itoa_hex_upper(numb));
	ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	while ((*length)-- - buf > 0)
	{
		i++;
		write(1, &*symb, 1);
	}
	return (i);
}

int		ft_hex_up_wsl(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, " ", 1);
		}
		i += ft_strlen(ft_itoa_hex_upper(numb));
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
		i += ft_strlen(ft_itoa_hex_upper(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}

int		ft_hex_up_nd(char *flags, int *length, int numb, char *symb)
{
	int i;

	i = 0;
	if (!ft_strchr(flags, '-'))
	{
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
		i += ft_strlen(ft_itoa_hex_upper(numb));
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
	}
	else
	{
		ft_putstr_fd(ft_itoa_hex_upper(numb), 1);
		i += ft_strlen(ft_itoa_hex_upper(numb));
		while ((*length)-- > (int)ft_strlen(ft_itoa_hex_upper(numb)))
		{
			i++;
			write(1, &*symb, 1);
		}
	}
	return (i);
}
