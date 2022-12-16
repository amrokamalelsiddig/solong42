/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:02:52 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 08:05:34 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>    
// # include "minilibx/mlx.h"

typedef struct map
{
	int		fd;
	int		fd2;
	int		c_enemy;
	int		c_player;
	int		c_wall;
	int 	c_collect;
	int 	c_exit;
	char	*file_name;
	char	*map;
	int		hight;
    int		width;
    int		size;
    int		count_moves; 
}t_map;

//libft.c	while(read(fd,&buff,1) > 0 && buff != '\0')

int	ft_nbrlen(int nbr);
char		*ft_strdup(const char	*s1);
size_t		ft_strlen(const char *s);

//ft_itoa.c
char		*ft_itoa(int n);

//validation.c
int			check_char(int fd);
int			file_ext(char *str);
int 		validation(t_map *map, char *str);
int 		count_validation(t_map *map);
int 		dimension(t_map* map);


//output.c
void	print_map(t_map *m);
void	ft_putstr_fd(char	*s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);

//error.c
void error_handling(int i);

//ft_init.c
void ft_init(t_map *map);
void in_dimension(t_map *map, int hight, int width);


void fill_map(t_map *map);

#endif