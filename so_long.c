/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:54:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/18 18:38:46 by aelsiddi         ###   ########.fr       */
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
	mlx_string_put(m->mlx, m->window, 5, 10, 0xFFFF5615, ft_itoa(m->count_moves));
}

void print_move(t_map *map)
{
	if (map->count_moves_screen != map->count_moves)
	{
		map->count_moves_screen = map->count_moves;
		write(1, "Number of moves\t: ", 19);
		ft_putnbr_fd(map->count_moves_screen, 1);
		write(1, "\n", 1);
	}
}

void	ft_init_xlm(t_map *map)
{
	map->mo_flag = 0;
	map->mlx = mlx_init();
	map->window = mlx_new_window(map->mlx,(map->width * 48), \
		(map->hight * 48), "hello world");
	map->img_wall = mlx_xpm_file_to_image(map->mlx,\
		"./img/wall.xpm",&map->img_w, &map->img_h);
	map->img_floor = mlx_xpm_file_to_image(map->mlx,\
		"./img/empty.xpm",&map->img_w, &map->img_h);
	map->img_door = mlx_xpm_file_to_image(map->mlx,\
		"./img/exit.xpm",&map->img_w, &map->img_h);
	map->img_clc = mlx_xpm_file_to_image(map->mlx,"./img/collect.xpm",\
		&map->img_w, &map->img_h);

	map->img_char = mlx_xpm_file_to_image(map->mlx,"./img/player.xpm",&map->img_w, &map->img_h);
	// map->img_char = mlx_xpm_file_to_image(map->mlx,pic_path(map,1,'P'),&map->img_w, &map->img_h);
	map->img_eney = mlx_xpm_file_to_image(map->mlx, "./img/enemy1.xpm", &map->img_w, &map->img_h);
	
}

char *pic_path(t_map *map,int i, char c)
{
	char *res;
	char *holder;
	
	if (i = 1 && c == 'P')
	{
		if ( map->mo_flag < 17)
		{
			holder = ft_itoa(map->mo_flag);
			res = ft_strjoin("./img/ch_xpm/",holder);
			res = ft_strjoin(res,"r.xpm");
			map->mo_flag++;
		}
		map->mo_flag = 0;
		res = "./img/ch_xpm/0r.xpm";
	}
	return (res);
}

int	mlx_close(int keycode, t_map *map)
{
	exiting(map,3);
	return (0);
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
	valid(argv[1],&map);
	ft_init_xlm(&map);
	// print_move(&map);
	draw(&map);
	mlx_key_hook(map.window, move_char, &map);
	mlx_hook(map.window, 17, 1L << 0, mlx_close, &map);
	mlx_loop_hook(map.mlx, enemy_move, &map);
	mlx_loop(map.mlx);
	return (0);
}
