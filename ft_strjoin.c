/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:53:40 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/17 21:04:10 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const	*s2)
{
	char	*f;
	char	*se;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	se = (char *)s2;
	f = (char *)s1;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!ptr)
		return (ptr);
	while (f && f[i] != '\0')
		ptr[i++] = f[j++];
	j = 0;
	while (se && se[j] != '\0')
		ptr[i++] = se[j++];
	ptr[i] = '\0';
	return (ptr);
}