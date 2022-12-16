/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:52:21 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 18:09:22 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_map *map)
{
	map->count_c = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->count_moves = 0;
	map->collect_path = 0;
}

void	ft_in(t_map *m, int hight, int width)
{
	m->hight = hight;
	m->width = width;
	m->size = hight * width;
}
