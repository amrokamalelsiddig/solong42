/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desposlable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:52:21 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 02:33:43 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	locate_enemy(t_map *m)
{
	int	i;

	i = 0;
	while (m->map[i] != 'N' && i <= m->size)
		i++;
	if (m->current_location == m->size)
		return (0);
	else
		m->current_location = i;
	return (i);
}

int	locate_exit(t_map *m)
{
	int	i;

	i = m->width;
	while (m->map[i] != 'E')
		i++;
	m->current_location = i;
	return (i);
}

int	locate_char(t_map *m)
{
	int	i;

	i = 0;
	while (m->map[i] != 'P')
		i++;
	m->current_location = i;
	return (i);
}
