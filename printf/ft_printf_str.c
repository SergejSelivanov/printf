/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:58:14 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:58:16 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_str(char *str, char *flags, int *star, int *res_value)
{
	int length;
	int flag;
	int width;

	length = 0;
	width = 0;
	flag = ft_str_length_init(star, &flags, &length, &str);
	if (ft_strchr(flags, '.'))
	{
		ft_str_width_init(star, flags, str, &width);
		if (ft_strchr(flags, '-'))
		{
			if (width != 0)
				*res_value += ft_str_wnz(&width, str, &length);
			else
				*res_value += ft_str_wnz2(&length);
		}
		else
			*res_value += ft_str_wzall(width, str, length);
	}
	else
		*res_value += ft_nw_str(&length, str, flags);
	if (flag == 1)
		free(str);
}

int		ft_str_length_init(int *star, char **flags, int *length, char **str)
{
	int		flag;
	char	*joined_str;

	flag = 0;
	joined_str = NULL;
	if (star[0] != 0)
	{
		if (star[0] < 0)
		{
			joined_str = ft_strjoin("-", *flags);
			*flags = joined_str;
			star[0] = star[0] * -1;
		}
		*length = star[0];
	}
	else
	{
		*length = ft_atoi(*flags);
		if (*length < 0)
			*length = *length * -1;
	}
	if (*str == NULL)
		*str = ft_null_str_opt(&flag, str);
	free(joined_str);
	return (flag);
}

void	ft_str_width_init(int *star, char *flags, char *str, int *width)
{
	int j;

	j = 0;
	if (star[1] == 0)
	{
		while (!ft_strchr(".", flags[j]))
			j++;
		j++;
		while (!ft_strchr("s", flags[j]))
		{
			if (ft_strchr("0123456789", flags[j]))
				*width = *width * 10 + (flags[j] - '0');
			j++;
		}
	}
	else if (star[1] < 0)
		*width = ft_strlen(str);
	else
		*width = star[1];
}

int		ft_str_wnz(int *width, char *str, int *length)
{
	int i;
	int how_much_alp;

	how_much_alp = 0;
	i = 0;
	while (*str && (*width)--)
	{
		write(1, str, 1);
		i++;
		str++;
		how_much_alp++;
	}
	while ((*length)-- > how_much_alp)
	{
		i++;
		write(1, " ", 1);
	}
	return (i);
}

int		ft_str_wnz2(int *length)
{
	int i;

	i = 0;
	while ((*length)-- > 0)
	{
		i++;
		write(1, " ", 1);
	}
	return (i);
}
