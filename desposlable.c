/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   desposlable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:52:21 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/10/23 15:59:42 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int locate_enemy(t_map *m)
{
	int i;

	i = m->width;
	while (m->map[i] != 'N')
		i++;
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
