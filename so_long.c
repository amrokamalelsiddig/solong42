/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 09:41:28 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_map *m)
{
	int	counter;

	counter = 0;
	m->d_j = 0;
	m->d_i = 0;
	while (counter <= m->size)
	{
		if (m->map[counter] == '1')
			mlx_put_image_to_window(m->mlx, m->win, m->i_wall, m->d_j, m->d_i);
		else if (m->map[counter] == '0' || m->map[counter] == 'z' )
			mlx_put_image_to_window(m->mlx, m->win, m->i_floor, m->d_j, m->d_i);
		else if (m->map[counter] == 'E')
			mlx_put_image_to_window(m->mlx, m->win, m->i_door, m->d_j, m->d_i);
		else if (m->map[counter] == 'P')
			mlx_put_image_to_window(m->mlx, m->win, m->i_char, m->d_j, m->d_i);
		else if (m->map[counter] == 'C')
			mlx_put_image_to_window(m->mlx, m->win, m->i_clc, m->d_j, m->d_i);
		else if (m->map[counter] == 'N')
			mlx_put_image_to_window(m->mlx, m->win, m->i_eney, m->d_j, m->d_i);
		next_block(m);
		counter++;
	}
	mlx_string_put(m->mlx, m->win, 10, 15, 0xFFFF5615, ft_itoa(m->c_moves));
}

void	print_move(t_map *map)
{
	if (map->c_moves_screen != map->c_moves)
	{
		map->c_moves_screen = map->c_moves;
		ft_putstr_fd("Number of moves\t: ", 1);
		ft_putnbr_fd(map->c_moves_screen, 1);
		write(1, "\n", 1);
	}
}

void	ft_init_xlm(t_map *map)
{
	map->mo_flag = 0;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, (map->width * 48), \
		(map->hight * 48), "hello world");
	map->i_wall = mlx_xpm_file_to_image(map->mlx, \
		"./img/wall.xpm", &map->img_w, &map->img_h);
	map->i_floor = mlx_xpm_file_to_image(map->mlx, \
		"./img/empty.xpm", &map->img_w, &map->img_h);
	map->i_door = mlx_xpm_file_to_image(map->mlx, \
		"./img/exit.xpm", &map->img_w, &map->img_h);
	map->i_clc = mlx_xpm_file_to_image(map->mlx, "./img/collect.xpm", \
		&map->img_w, &map->img_h);
	map->i_char = mlx_xpm_file_to_image(map->mlx, \
	"./img/player.xpm", &map->img_w, &map->img_h);
	map->i_eney = mlx_xpm_file_to_image(map->mlx, \
	"./img/enemy1.xpm", &map->img_w, &map->img_h);
	if (!(map->win) || !(map->i_wall) || !(map->i_floor) \
	|| !(map->i_door) || !(map->i_clc) || !(map->i_char) || \
	!(map->i_eney))
		exit(0);
}

int	mlx_close(int keycode, t_map *map)
{
	(void)keycode;
	exiting(map, 3);
	return (0);
}

int	main(int ac, char **argv)
{
	t_map	map;

	(void)ac;
	map.file_name = argv[1];
	map.fd = open(argv[1], O_RDONLY);
	map.fd2 = open(argv[1], O_RDONLY);
	if (map.fd <= 0 || map.fd2 <= 0)
		exiting(&map, 1);
	ft_init(&map);
	valid(argv[1], &map);
	ft_init_xlm(&map);
	draw(&map);
	mlx_key_hook(map.win, move_char, &map);
	mlx_loop_hook(map.mlx, enemy_move, &map);
	mlx_hook(map.win, 17, 1L << 0, mlx_close, &map);
	mlx_loop(map.mlx);
	return (0);
}
