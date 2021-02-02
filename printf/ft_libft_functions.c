/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Wjena <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 15:37:57 by Wjena             #+#    #+#             */
/*   Updated: 2020/07/24 15:38:05 by Wjena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strrchr(const char *str, int ch)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			j = i;
		i++;
	}
	if (j == 0)
	{
		if (str[0] == ch)
			return ((char *)str);
		else
			return (NULL);
	}
	return ((char *)str + j);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*arr;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	arr = (char*)malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		arr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		arr[i] = s2[j];
		j++;
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*a;
	int		j;

	if (!src)
		return (NULL);
	j = 0;
	i = 0;
	while (src[i])
		i++;
	a = (char*)malloc(i + 1);
	if (a == NULL)
		return (NULL);
	while (src[j])
	{
		a[j] = src[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_strchr(const char *str, int ch)
{
	int i;

	if (!str)
		return (NULL);
	i = 0;
	if (ch == '\0')
		return ((char *)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == ch)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
