/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 17:01:10 by yidrissi          #+#    #+#             */
/*   Updated: 2023/01/06 04:01:36 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_nbrlen(int nbr)
{
	int	len;
	int	mod;

	len = 1;
	if (nbr > 0)
		mod = nbr / 10;
	else
	{
		mod = -nbr / 10;
		len++;
	}	
	while (mod > 0)
	{
		len++;
		mod = mod / 10;
	}
	return (len);
}

char	*ft_strdup(const char	*s1)
{
	char	*s;
	char	*ptr;
	int		i;

	i = 0;
	s = (char *)s1;
	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	free(ptr);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_reverse(char *src)
{
	char	temp;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((const char *)src);
	while (i < len / 2)
	{
		temp = src[i];
		src[i] = src[len - 1 - i];
		src[len - 1 - i] = temp;
		i++;
	}
	return (src);
}

static char	*ft_handle(int z)
{
	if (z == 0)
		return (ft_strdup("0"));
	return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*result;
	int		temp;
	int		mod;
	int		i;

	i = 0;
	temp = n;
	if (n == 0 || n == -2147483648)
		return (ft_handle(n));
	if (temp < 0)
		temp = -temp;
	result = (char *)malloc(ft_nbrlen(n) + 1);
	if (!result)
		return (0);
	while (temp > 0)
	{
		mod = temp % 10;
		result[i] = mod + '0';
		temp = temp / 10;
		i++;
	}
	if (n < 0)
		result[i++] = '-';
	result[i] = '\0';
	free(result);
	return (ft_reverse(result));
}
