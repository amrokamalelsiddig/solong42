/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:35:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/02 12:42:22 by aelsiddi         ###   ########.fr       */
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
			exiting(m,1);
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
			exiting(m,1);
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
			exiting(m,1);
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
			exiting(m,1);
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
	print_move(m);
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

int enemy_move(t_map *m)
{
    int enemy_loc;
    static int flag=0;

    enemy_loc = locate_enemy(m);
    if(m->map[enemy_loc + 1 ] == '0' && flag == 0) 
    {
        m->map[enemy_loc] = '0';
        enemy_loc++;
        m->map[enemy_loc] = 'N';

    }
    else if (m->map[enemy_loc - 1 ] == '0' )
    {
        flag = 1;
        m->map[enemy_loc] = '0';
        enemy_loc--;
        m->map[enemy_loc] = 'N';
        if (m->map[enemy_loc - 1 ] == '1' )
    flag =0;
    }
	else if (m->map[enemy_loc + 1 ] || m->map[enemy_loc - 1 ])
		exiting(m,2);
    usleep(100000);
    draw(m);
	return (0);
}