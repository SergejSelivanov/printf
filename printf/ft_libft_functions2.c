/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:42:54 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:42:57 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_itoa_hex(unsigned int value)
{
	static char	rep[] = "0123456789abcdef";
	static char	buf[50];
	char		*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}

char	*ft_itoa_hex_upper(unsigned int value)
{
	static char	rep[] = "0123456789ABCDEF";
	static char	buf[50];
	char		*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}

char	*ft_itoa_hex_ptr(unsigned long value)
{
	static char				rep[] = "0123456789abcdef";
	static char				buf[50];
	char					*ptr;

	ptr = &buf[49];
	*ptr = '\0';
	if (value == 0)
		*--ptr = rep[value % 16];
	while (value != 0)
	{
		*--ptr = rep[value % 16];
		value /= 16;
	}
	return (ptr);
}

void	ft_putnbr_fd_long(long n, int fd)
{
	long i;

	i = n;
	if (i == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
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

void	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	long long			mlt;
	int					digits;
	unsigned long long	now;
	int					buf;

	digits = 1;
	mlt = 1;
	now = n / 10;
	while (now != 0)
	{
		digits++;
		now /= 10;
	}
	buf = digits;
	while (digits > 1)
	{
		mlt *= 10;
		digits--;
	}
	while (buf-- > 0)
	{
		ft_putchar_fd(n / mlt + 48, fd);
		n %= mlt;
		mlt /= 10;
	}
}
