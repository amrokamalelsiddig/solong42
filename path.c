/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:40:58 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/18 14:39:48 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int locate_p(t_map *m)
{
    int i;
    i = m->width ;
    while (m->map[i] != 'P')
        i++;
    m->current_location  = i; 
    return (i);
}

int exit_finder(t_map *m, int i)
{
    if(m->map[i] == 'E')
        return (1);
    return (0);
}

int fnd_ext(t_map *m, int p_pos)
{
	if (m->map[p_pos + 1] == 'E'|| m->map[p_pos - 1] == 'E'||\
		m->map[p_pos + m->width] == 'E'|| m->map[p_pos - m->width] == 'E')
		return (1);
	return (0);
}

int check_box(t_map *m,int current_loc)
{
	int	res;
	
	res = 0;
	if (m->map_2[current_loc] == 'C')
		m->collect_path++;
	m->map_2[current_loc] = 'z';
	if (fnd_ext(m,current_loc))
		m->valid = 1;
	if (m->map_2[current_loc - m->width] != '1' && m->map_2[current_loc - m->width] != 'z'
		&& m->map_2[current_loc - m->width] != 'E')
		res = check_box(m,current_loc - m->width);
	if (m->map_2[current_loc + 1] != '1' && m->map_2[current_loc + 1] != 'z'
		&& m->map_2[current_loc + 1] != 'E')
		res = check_box(m,current_loc + 1);
	if (m->map_2[current_loc + m->width] != '1' && m->map_2[current_loc + m->width] != 'z'
		&& m->map_2[current_loc + m->width] != 'E')
		res = check_box(m,current_loc + m->width);
	if (m->map_2[current_loc - 1] != '1' && m->map_2[current_loc - 1] != 'z'
		&& m->map_2[current_loc - 1] != 'E')
		res = check_box(m,current_loc - 1);
	// rest_z(m);
	// free(m->map);	
	return (res);
}

void rest_z(t_map *map)
{
	int i;

	i = 0;
	while(map->map[i] != '\0')
	{
		if(map->map[i] == 'z')
			map->map[i] = '0';
		i++;
	}
}

void find_path(t_map *m)
{
    int p_loc;

    p_loc = locate_p(m);
    if (!(check_box(m, p_loc)))
        return ;
    print_map(m);
    Green();
    printf("\nSuccess >>>>>>>>>>>>>>>>> Valid Path Found\n");
    reset();
}
