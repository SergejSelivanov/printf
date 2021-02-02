/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:47:14 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:47:18 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

const char	*ft_take_prm(const char *s,
			int kol_par, va_list ap, int *res_value)
{
	char	*flags;
	char	param;

	if (!(flags = (char *)malloc(ft_strlen(s) + 1)))
		return (++s);
	ft_memset(flags, '\0', ft_strlen(s) + 1);
	param = '\0';
	while (kol_par-- > 0)
	{
		s = ft_printf_textb_param(s, res_value);
		s = ft_search_flags(s, &flags, &param);
		if (param == '%')
		{
			kol_par--;
			ft_choose_prm(param, flags, ap, res_value);
		}
		else
			ft_choose_prm(param, flags, ap, res_value);
		ft_memset(flags, '\0', ft_strlen(s) + 1);
	}
	free(flags);
	return (s);
}

const char	*ft_search_flags(const char *s, char **flags, char *param)
{
	int i;

	i = 0;
	s++;
	while (ft_strchr("0.*-123456789", *s))
		s = ft_search_flags2(s, flags, &i);
	if (ft_strchr("cspdiuxX%", *s))
	{
		*param = *s;
		(*flags)[i] = '\0';
	}
	else
	{
		*param = '\0';
		(*flags)[0] = '\0';
	}
	return (++s);
}

const char	*ft_printf_textb_param(const char *s, int *res_value)
{
	int b_par;
	int i;

	i = 0;
	b_par = 0;
	while (s[i] && s[i] != '%')
	{
		write(1, &s[i], 1);
		i++;
		b_par++;
	}
	*res_value += b_par;
	return (s + i);
}

int			ft_kol_params(const char *s)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			res++;
			i++;
		}
		else
			i++;
	}
	return (res);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	int		res_value;
	int		kol_par;

	va_start(ap, s);
	res_value = 0;
	kol_par = ft_kol_params(s);
	s = ft_take_prm(s, kol_par, ap, &res_value);
	s = ft_printf_textb_param(s, &res_value);
	va_end(ap);
	return (res_value);
}
