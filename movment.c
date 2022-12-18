/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:35:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/18 15:34:56 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_capture(int key, t_map *m)
{
	(void) key;
	(void) *m;
	return (0);
}

void 	move_up(t_map *m, int current_loc, char self, char enemy)
{
	(void)enemy;
	if (m->map[current_loc - m->width] != '1')
	{
		if (m->map[current_loc - m->width] == 'N' ||m->map[current_loc - m->width] == 'E' )
			exit(0);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location - m->width;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->count_moves++;
	}
}

void	move_down(t_map *m, int current_loc, char self, char enemy)
{
	(void)enemy;		
	if (m->map[current_loc + m->width] != '1')
	{
		if (m->map[current_loc + m->width] == 'N' || m->map[current_loc + m->width] == 'E' )
			exit(0);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location + m->width;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->count_moves++;
	}
}

void	move_right(t_map *m, int current_loc, char self, char enemy)
{
	(void)enemy;
	if (m->map[current_loc + 1] != '1' )
	{
		if (m->map[current_loc + 1] == 'N' ||m->map[current_loc + 1] == 'E' )
			exit(0);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location + 1;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->count_moves++;
	}
}

void	move_left(t_map *m, int current_loc, char self, char enemy)
{
	(void)enemy;
	if (m->map[current_loc - 1] != '1' ) 
	{
		if (m->map[current_loc - 1] == 'N' || m->map[current_loc - 1] == 'E' )
			exit(0);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location - 1;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->count_moves++;
	}
}

int		move_char(int c, t_map *m)
{
	int	current_loc;

	current_loc = locate_char(m);
	if (c == 13 || c == 65362) 
		move_up(m, current_loc, 'P', 'N');
	else if (c == 0 || c ==  65361)
		move_left(m, current_loc, 'P', 'N');
	else if (c == 1 || c == 65364)
		move_down(m, current_loc, 'P', 'N');
	else if (c == 2 || c == 65363 )
		move_right(m, current_loc, 'P', 'N');
	else if (c == 53 || c == 99 || c == 65307)
		exiting(m,1);
	draw(m);
	return (0);
}

int locate_char(t_map *m)
{
	int i;

	i = 0;
	while (m->map[i] != 'P')
		i++;
	m->current_location = i; 
	return (i);
}

int locate_enemey(t_map *m)
{
	int i;

	i = 0;
	while (m->map[i] != 'N')
		i++;
	m->current_location = i; 
	return (i);
}

int enemy_move(t_map *map)
{
    int enemy_loc;
    //int n;
    static int flag=0;
   // flag = 0;//1 to right 0 to left 

    enemy_loc = locate_enemey(map);
    if(map->map[enemy_loc + 1 ] == '0' && flag == 0) 
    {
        map->map[enemy_loc] = '0';
        enemy_loc++;
        map->map[enemy_loc] = 'N';

    }
    else if (map->map[enemy_loc - 1 ] == '0' )
    {
        flag = 1;
        map->map[enemy_loc] = '0';
        enemy_loc--;
        map->map[enemy_loc] = 'N';
        if (map->map[enemy_loc - 1 ] == '1' )
    flag =0;
    }
    usleep(100000);
    draw(map);
	return 0;
}