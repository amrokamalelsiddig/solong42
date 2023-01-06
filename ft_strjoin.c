/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:53:40 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 11:43:15 by aelsiddi         ###   ########.fr       */
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

int	move_char(int c, t_map *m)
{
	int	current_loc;

	current_loc = locate_char(m);
	if (c == 13 || c == 65362)
		move_up(m, current_loc, 'P');
	else if (c == 0 || c == 65361)
		move_left(m, current_loc, 'P');
	else if (c == 1 || c == 65364)
		move_down(m, current_loc, 'P');
	else if (c == 2 || c == 65363)
		move_right(m, current_loc, 'P');
	else if (c == 53 || c == 99 || c == 65307)
		exiting(m, 3);
	print_move(m);
	draw(m);
	return (0);
}
