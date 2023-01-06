/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:40:58 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 10:24:24 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	fnd_ext(t_map *m, int p_pos)
{
	if (m->map[p_pos + 1] == 'E' || m->map[p_pos - 1] == 'E' || \
		m->map[p_pos + m->width] == 'E' || m->map[p_pos - m->width] == 'E')
		return (1);
	return (0);
}

int	check_box(t_map *m, int cur_loc)
{
	int	res;

	res = 0;
	if (m->map_2[cur_loc] == 'C')
		m->collect_path++;
	m->map_2[cur_loc] = 'z';
	if (fnd_ext(m, cur_loc))
		m->valid = 1;
	if (m->map_2[cur_loc - m->width] != '1' \
		&& m->map_2[cur_loc - m->width] != 'z'
		&& m->map_2[cur_loc - m->width] != 'E')
		res = check_box(m, cur_loc - m->width);
	if (m->map_2[cur_loc + 1] != '1' && m->map_2[cur_loc + 1] != 'z'
		&& m->map_2[cur_loc + 1] != 'E')
		res = check_box(m, cur_loc + 1);
	if (m->map_2[cur_loc + m->width] != '1' && \
	m->map_2[cur_loc + m->width] != 'z'
		&& m->map_2[cur_loc + m->width] != 'E')
		res = check_box (m, cur_loc + m->width);
	if (m->map_2[cur_loc - 1] != '1' && m->map_2[cur_loc - 1] != 'z'
		&& m->map_2[cur_loc - 1] != 'E')
		res = check_box (m, cur_loc - 1);
	return (res);
}

void	find_path(t_map *m)
{
	int	p_loc;

	p_loc = locate_char(m);
	if (!(check_box(m, p_loc)))
		return ;
}
