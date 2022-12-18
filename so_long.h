/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:02:52 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/18 18:36:45 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>    
# include "mlx.h"

typedef struct map
{
	int     count_e;
	int     count_p;
	int     count_c;
	int 	collect_path;
	int     count_moves;
	int     count_moves_screen;
	char    *map;
	char	*map_2;
	int     width;
	int     hight;
	int     valid;
	int     size;
	int     fd;
	int     fd2;
	int 	fd3;
	void	*mlx;
	void	*window;
	void	*img_wall;
	void	*img_floor;
	void	*img_door;
	void	*img_char;
	void 	*img_clc;
	void 	*img_eney;
	int		mo_flag;
	int		img_w;
	int		img_h;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*wall;
	char	*ground;
	char	*exit;
	char	*collectable;
	int		coin_valid;
	char	*player;
	char	*player_s;
	char	*enemy;
	int     current_location;
	char	*file_name;
}		t_map;
//******** so_long.c **********************//
int 	check_char(char buffer);
int 	element_validation(t_map *map);
int 	validation(t_map* map);
void 	fill_map(t_map *map);
int 	border_validation(t_map *map);
///******* error.c ***********************//
void	error_handling(int i);
void	error_handling1(int i,int fd,t_map *m);
void 	exiting(t_map *map, int flag);
//******** print_map ********************//
void 	print_map(t_map *map);
//********* Path*************************//
int 	check_box(t_map *m,int current_loc);
void 	find_path(t_map *m);
//************* colors **********************//
void 	red();
void 	reset();
void 	Green();
void 	yellow();
void 	Black();
void 	Cyan();
//************* movment ***********************//
int		move_char(int c, t_map *m);
void 	move_up(t_map *m, int current_loc, char self, char enemy);
void	move_down(t_map *m, int current_loc, char self, char enemy);
void	move_right(t_map *m, int current_loc, char self, char enemy);
void	move_left(t_map *m, int current_loc, char self, char enemy);
void	draw(t_map *m);
int		enemy_move(t_map *m);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void	print_move(t_map *map);
int 	locate_enemy(t_map *m);
void	death(int loc_p, int loc_e, int loc_en);
int 	locate_exit(t_map *m);
size_t	ft_strlen(const char *s);
void 	ft_in(t_map *m, int hight, int width);
char	*ft_itoa(int n);
void 	ft_init_xlm(t_map *map);
int 	locate_element(t_map *m, char c);
int 	locate_char(t_map *m);
int 	locate_enemey(t_map *m);
int 	locate_exit(t_map *m);
char	*ft_strjoin(char const *s1, char const	*s2);
//*******init.c *******************
void 	ft_init(t_map *map);
void 	check_cond(char *av);
void 	valid(char *av, t_map *map);
char 	*pic_path(t_map *map,int i, char c);
void 	rest_z(t_map *map);
#endif

//top -pid 48423 -stats "pid,command,MEM" 

// gcc so.c error.c ft_itoa.c init.c path.c movment.c print.c term.c vail.c color.c -lmlx -lXext -lX11