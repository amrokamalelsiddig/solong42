/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:35:17 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 12:20:29 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_map *m, int current_loc, char self)
{
	if (m->map[current_loc - m->width] != '1')
	{
		if (m->map[current_loc - m->width] == 'N' \
		||m->map[current_loc - m->width] == 'E' )
			exiting(m, 5);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location - m->width;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->c_moves++;
	}
}

void	move_down(t_map *m, int current_loc, char self)
{	
	if (m->map[current_loc + m->width] != '1')
	{
		if (m->map[current_loc + m->width] == 'N' \
		|| m->map[current_loc + m->width] == 'E' )
			exiting(m, 5);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location + m->width;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->c_moves++;
	}
}

void	move_right(t_map *m, int current_loc, char self)
{
	if (m->map[current_loc + 1] != '1' )
	{
		if (m->map[current_loc + 1] == 'N'\
		||m->map[current_loc + 1] == 'E' )
			exiting(m, 5);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location + 1;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->c_moves++;
	}
}

void	move_left(t_map *m, int current_loc, char self)
{
	if (m->map[current_loc - 1] != '1' )
	{
		if (m->map[current_loc - 1] == 'N'\
		|| m->map[current_loc - 1] == 'E' )
			exiting(m, 5);
		m->map[m->current_location] = '0';
		m->current_location = m->current_location - 1;
		m->map[m->current_location] = self;
		if (self == 'P')
			m->c_moves++;
	}
}

int	enemy_move(t_map *m)
{
	static int	flag = 0;

	m->en_loc = locate_enemy(m);
	if (!(m->en_loc))
		return (0);
	if (m->map[m->en_loc + 1] == '0' && flag == 0)
	{
		m->map[m->en_loc] = '0';
		m->en_loc++;
		m->map[m->en_loc] = 'N';
	}
	else if ((m->map[m->en_loc - 1] == '0'))
	{
		flag = 1;
		m->map[m->en_loc] = '0';
		m->en_loc--;
		m->map[m->en_loc] = 'N';
		if (m->map[m->en_loc - 1] == '1' )
			flag = 0;
	}
	else if ((m->map[m->en_loc + 1] == 'P' || m->map[m->en_loc - 1] == 'P'))
		exiting(m, 2);
	usleep(100000);
	draw(m);
	return (1);
}
