/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:58:59 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:59:01 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_wz1_str(char *str, int *width, int *length)
{
	int how_much_alp;
	int k;
	int i;

	i = 0;
	how_much_alp = 0;
	k = 0;
	while (*str && (*width)--)
	{
		str++;
		how_much_alp++;
		k++;
	}
	while (k > 0)
	{
		k--;
		str--;
	}
	while ((*length)-- > how_much_alp)
	{
		i++;
		write(1, " ", 1);
	}
	return (i);
}

int		ft_wz2_str(char *str, int buf)
{
	int i;

	i = 0;
	while (*str && buf--)
	{
		i++;
		write(1, str, 1);
		str++;
	}
	return (i);
}

int		ft_nw_str(int *length, char *str, char *flags)
{
	int i;

	i = 0;
	if (ft_strchr(flags, '-'))
	{
		ft_putstr_fd(str, 1);
		i += ft_strlen(str);
		while ((*length)-- > (int)ft_strlen(str))
		{
			i += 1;
			write(1, " ", 1);
		}
	}
	else
	{
		while ((*length)-- > (int)ft_strlen(str))
		{
			i += 1;
			write(1, " ", 1);
		}
		i += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	return (i);
}

int		ft_str_wzall(int width, char *str, int length)
{
	int buf;
	int i;

	i = 0;
	buf = width;
	if (width != 0)
	{
		i += ft_wz1_str(str, &width, &length);
		i += ft_wz2_str(str, buf);
	}
	else
		i += ft_str_wnz2(&length);
	return (i);
}

char	*ft_null_str_opt(int *flag, char **str)
{
	*flag = 1;
	*str = ft_strdup("(null)");
	return (*str);
}
