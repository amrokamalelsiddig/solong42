/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:02:52 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 10:37:36 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>    
# include "minilibx/mlx.h"

typedef struct map
{
	int		count_e;
	int		count_p;
	int		count_c;
	int		collect_path;
	int		d_i;
	int		d_j;
	int		c_moves;
	int		c_moves_screen;
	int		width;
	int		hight;
	int		valid;
	int		size;
	int		fd;
	int		fd2;
	int		fd3;
	int		mo_flag;
	int		img_w;
	int		img_h;
	int		current_location;
	int		coin_valid;
	int		en_loc;
	char	*map;
	char	*map_2;
	char	*addr;
	char	*wall;
	char	*ground;
	char	*exit;
	char	*collectable;
	char	*player;
	char	*player_s;
	char	*enemy;
	char	*file_name;
	void	*mlx;
	void	*win;
	void	*i_wall;
	void	*i_floor;
	void	*i_door;
	void	*i_char;
	void	*i_clc;
	void	*i_eney;
}		t_map;

//******** so_long.c **********************//
void	draw(t_map *m);
void	print_move(t_map *map);
void	ft_init_xlm(t_map *map);
int		mlx_close(int keycode, t_map *map);
void	fill_map(t_map *map);
int		check_char(char buffer);
int		element_validation(t_map *map);
int		validation(t_map *map);
int		border_validation(t_map *map);
///******* error.c ***********************//
void	error_handling(int i);
void	error_handling1(int i, int fd, t_map *m);
void	exiting(t_map *map, int flag);
//******** print_map ********************//
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	check_cond(char *av);
//********* Path*************************//
void	find_path(t_map *m);
int		check_box(t_map *m, int current_loc);
//************* movment ***********************//
void	move_up(t_map *m, int current_loc, char self);
void	move_down(t_map *m, int current_loc, char self);
void	move_right(t_map *m, int current_loc, char self);
void	move_left(t_map *m, int current_loc, char self);
void	ft_putnbr_fd(int n, int fd);
void	death(int loc_p, int loc_e, int loc_en);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_in(t_map *m, int hight, int width);
int		enemy_move(t_map *m);
//******** msic .c *************//
int		locate_char(t_map *m);
int		locate_enemy(t_map *m);
int		locate_exit(t_map *m);
size_t	ft_strlen(const char *s);
//******** itoa.c **************//
char	*ft_itoa(int n);
//******** ft_strjoin **********//
char	*ft_strjoin(char const *s1, char const	*s2);
int		move_char(int c, t_map *m);
//*******init.c *****************//
void	ft_init(t_map *map);
void	valid(char *av, t_map *map);
char	*pic_path(t_map *map, int i, char c);
void	rest_z(t_map *map);
void	next_block(t_map *m);
#endif

//top -pid 48423 -stats "pid,command,MEM" 
