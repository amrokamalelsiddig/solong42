/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 18:21:55 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void draw(t_map *m)
{
	int j;
	int i;
	int counter;

	counter = 0;
	j = 0;
	i = 0; // width counter  
	while(counter <= m->size)
	{
		if (m->map[counter] == '1')
			mlx_put_image_to_window(m->mlx, m->window, m->img_wall, j, i);
		else if(m->map[counter] == '0' || m->map[counter] == 'z' )
			mlx_put_image_to_window(m->mlx, m->window, m->img_floor, j, i);
		else if(m->map[counter] == 'E')
			mlx_put_image_to_window(m->mlx, m->window, m->img_door, j, i);
		else if(m->map[counter] == 'P')
			mlx_put_image_to_window(m->mlx, m->window, m->img_char, j, i);
		else if(m->map[counter] == 'C')
			mlx_put_image_to_window(m->mlx, m->window, m->img_clc, j, i);
		else if(m->map[counter] == 'N')
			mlx_put_image_to_window(m->mlx, m->window, m->img_eney, j, i);
		j = j + 48;
		if (j == (m->width * 48))
		{
			j=0;
			i+=48;
		}
		counter++;
	}
	mlx_string_put(m->mlx, m->window, 10, 10, 0xFFFF5615, ft_itoa(m->count_moves));
}

void print_move(t_map *map)
{
	write(1, "MOVES", 6);
	ft_putnbr_fd(map->count_moves, 1);
	write(1, "\n", 1);
}

void	ft_init_xlm(t_map *map)
{
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx,(map->width * 48), \
		(map->hight * 48), "hello world");
	map->img_wall = mlx_xpm_file_to_image(map->mlx,\
		"./img/tile2.xpm",&map->img_w, &map->img_h);
	map->img_floor = mlx_xpm_file_to_image(map->mlx,\
		"./img/free_tile.xpm",&map->img_w, &map->img_h);
	map->img_door = mlx_xpm_file_to_image(map->mlx,\
		"./img/door.xpm",&map->img_w, &map->img_h);
	map->img_char = mlx_xpm_file_to_image(map->mlx,\
	"./img/char.xpm",&map->img_w, &map->img_h);
	map->img_clc = mlx_xpm_file_to_image(map->mlx,"./img/coin1.xpm",\
		&map->img_w, &map->img_h);
	map->img_eney = mlx_xpm_file_to_image(map->mlx, "./img/enemy.xpm", \
		&map->img_w, &map->img_h);
}

int	main(int ac, char **argv)
{
	t_map	map;

	(void)ac;
	map.file_name = argv[1];
	map.fd = open(argv[1],O_RDONLY);
	if (map.fd <= 0)
		error_handling(1);
	map.fd2 = open(argv[1],O_RDONLY);
	if (map.fd2 <= 0)
		error_handling(1);
	ft_init(&map);
	// printf("%d\n",check_cond(argv[1]));
	vaild(argv[1],&map);

	ft_init_xlm(&map);
	// print_map(&map);
	draw(&map);
	mlx_key_hook(map.window, move_char, &map);
	mlx_loop_hook(map.mlx, enemy_move, &map);
	mlx_loop(map.mlx);
	return (0);
}
