/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:44:47 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:44:50 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int				ft_atoi(const char *str)
{
	int		j;
	long	numb;
	int		sgn;

	if (!str)
		return (0);
	j = 0;
	numb = 0;
	sgn = 1;
	while (str[j] == '\v' || str[j] == '\t' || str[j] == '\n'
	|| str[j] == '\f' || str[j] == '\r' || str[j] == ' ')
		j++;
	if (str[j] == '-' || str[j] == '+')
		if (str[j++] == '-')
			sgn = -1;
	while (str[j] >= '0' && str[j] <= '9')
	{
		if (numb > (numb * 10 + (str[j] - '0')))
			return (sgn > 0 ? -1 : 0);
		numb = (numb * 10) + (str[j++] - '0');
	}
	return ((int)(numb * sgn));
}

int				count_tens(int n, int sign)
{
	int		i;

	i = 0;
	if (sign == 0)
	{
		while (n > 9)
		{
			n /= 10;
			i++;
		}
	}
	else
	{
		while (-n > 9)
		{
			n /= 10;
			i++;
		}
	}
	return (i + 1);
}

int				if_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static void		ft_fill_arr(int n, int n1, char *arr, int sign)
{
	int		i;
	int		j;
	int		k;

	k = 1;
	i = 0;
	j = 1;
	while (i < count_tens(n, if_negative(n)))
	{
		while (j < count_tens(n, if_negative(n)))
		{
			n1 /= 10;
			j++;
		}
		n1 %= 10;
		arr[if_negative(n) + i] = n1 + '0';
		n1 = n * sign;
		i++;
		k++;
		j = k;
	}
	arr[if_negative(n) + i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*arr;
	int		n1;
	int		sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	n1 = n * sign;
	arr = (char *)malloc(sizeof(char) *
			(count_tens(n, if_negative(n)) + if_negative(n) + 1));
	if (arr == NULL)
		return (NULL);
	if (if_negative(n) == 1)
		arr[0] = '-';
	ft_fill_arr(n, n1, arr, sign);
	return (arr);
}
