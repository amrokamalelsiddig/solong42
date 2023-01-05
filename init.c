/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:52:21 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 03:43:31 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init(t_map *map)
{
	map->count_c = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->c_moves = 0;
	map->c_moves_screen = 0;
	map->collect_path = 0;
	map->d_i = 0;
	map->d_j = 0;
}

void	ft_in(t_map *m, int hight, int width)
{
	m->hight = hight;
	m->width = width;
	m->size = hight * width;
}


void	next_block(t_map *m)
{
	m->d_j = m->d_j + 48;
	if (m->d_j == (m->width * 48))
	{
		m->d_i = m->d_i + 48;
		m->d_j = 0;
	}
}
