/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vail.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:18:26 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 11:40:00 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char buffer)
{
	if (buffer == '0' || buffer == '1' || buffer == 'C' \
		|| buffer == 'P' || buffer == 'E' || buffer == 'N' \
		|| buffer == '\n')
		return (1);
	else
		return (0);
}

int	element_validation(t_map *map)
{
	char	buffer;

	map->fd = open(map->file_name, O_RDONLY);
	while (read(map->fd, &buffer, 1))
	{
		if (buffer == 'C')
			map->count_c = map->count_c + 1;
		else if (buffer == 'P')
			map->count_p = map->count_p + 1 ;
		else if (buffer == 'E')
			map->count_e = map->count_e + 1 ;
	}
	close(map->fd);
	if (!(map->count_c > 0 && map->count_p > 0 && map->count_e > 0) \
		|| (map->count_p > 1))
		error_handling(9);
	return (1);
}

int	validation(t_map *map)
{
	char	buff;
	int		v_width;

	map->width = 0;
	map->hight = 1;
	v_width = 0;
	while (read(map->fd2, &buff, 1) && check_char(buff) && buff != '\n' )
		map->width++;
	while (read(map->fd2, &buff, 1) && check_char(buff))
	{
		if (buff == '\n')
		{
			map->hight++;
			if (v_width == map->width)
				v_width = 0;
			else if (v_width != map->width)
				error_handling1(3, map->fd3, map);
		}
		else if (buff != '\n')
			v_width++;
	}
	map->hight++;
	ft_in(map, map->hight, map->width);
	return (map->width * map->hight);
}

int	border_validation(t_map *map)
{
	int	i;
	int	z;

	z = (map->width * (map->hight - 1));
	i = 0;
	while (i < map->width)
	{
		if (map->map[i] == '1' && map->map[z] == '1' )
		{
			i++;
			z++;
		}
		else
			error_handling(4);
	}
	i = 1;
	while (i <= map->hight)
	{
		if (map->map[i - 1] == '1' && map->map[map->width * i - 1] == '1')
			i++;
		else
			error_handling(5);
	}
	return (1);
}

void	valid(char *av, t_map *map)
{
	check_cond(av);
	map->fd = open(av, O_RDONLY);
	if (!(map->fd))
		exiting(map, 4);
	element_validation(map);
	if (validation(map) < 0)
		error_handling1(11, map->fd2, NULL);
	map->fd3 = map->fd;
	fill_map(map);
	if (border_validation(map) != 1)
		error_handling(3);
	check_box(map, locate_char(map));
	if (!(map->valid == 1) || map->collect_path != map->count_c)
		error_handling(8);
}
