/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:52:21 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 08:07:48 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_init(t_map *map)
{
	map->fd2 = map->fd;
	map->c_enemy = 0;
	map->c_player = 0;
	map->c_wall =  0;
	map->c_collect = 0;
	map->c_exit = 0;
}

void in_dimension(t_map *map, int hight, int width)
{
    map->hight = hight;
    map->width = width;
    map->size = hight * width;
    map->count_moves = 0;
}