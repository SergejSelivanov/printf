/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:41:06 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:41:09 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;

	ptr = dest;
	while (len && ptr)
	{
		*ptr = val;
		ptr++;
		len--;
	}
	return (dest);
}

void	ft_putchar_fd(char c, int fd)
{
	if (!(write(fd, &c, 1)))
		return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	int i;

	i = n;
	if (i == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	if (i < 10)
	{
		ft_putchar_fd(i + '0', fd);
		return ;
	}
	ft_putnbr_fd(i / 10, fd);
	ft_putnbr_fd(i % 10, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int x;

	if (!s)
		return ;
	x = 0;
	while (s[x])
	{
		if (write(fd, &s[x], 1))
			x++;
		else
			return ;
	}
}
