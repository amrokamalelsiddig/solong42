/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:40:58 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 18:09:07 by aelsiddi         ###   ########.fr       */
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

// int	ft_isnext_e(int ppos, t_map *map)
// {
// 	if (map->map[ppos - map->width] == 'E' || map->map[ppos + 1] == 'E'
// 		|| map->map[ppos + map->width] == 'E' || map->map[ppos - 1] == 'E')
// 		return (1);
// 	return (0);
// }

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
	if (m->map[current_loc] == 'C')
		m->collect_path++;
	m->map[current_loc] = 'z';
	if (fnd_ext(m,current_loc))
		m->valid = 1;
	if (m->map[current_loc - m->width] != '1' && m->map[current_loc - m->width] != 'z'
		&& m->map[current_loc - m->width] != 'E')
		res = check_box(m,current_loc - m->width);
	if (m->map[current_loc + 1] != '1' && m->map[current_loc + 1] != 'z'
		&& m->map[current_loc + 1] != 'E')
		res = check_box(m,current_loc + 1);
	if (m->map[current_loc + m->width] != '1' && m->map[current_loc + m->width] != 'z'
		&& m->map[current_loc + m->width] != 'E')
		res = check_box(m,current_loc + m->width);
	if (m->map[current_loc - 1] != '1' && m->map[current_loc - 1] != 'z'
		&& m->map[current_loc - 1] != 'E')
		res = check_box(m,current_loc - 1);
	return (res);
}

// int check_box(t_map *m,int current_loc)
// {
//     int width = m->width ;
//     if((m->map[current_loc] == 'E'))
//     {
//         print_map(m);
//         return 1;
//     }
//     if (((current_loc < (width + 1)) || (current_loc > (m->size - width))))
//     {
//         print_map(m);
//         error_handling(7);
//         return 0;
//     }
//     // top condation 
//     if(((/*(m->map[current_loc - width] == 0) ||*/ (m->map[current_loc - width] != 'Z' )) 
//         &&( current_loc - width > width) && (m->map[current_loc - width] != '1' )))
//     {
//         if(exit_finder(m,current_loc -1))
//             return 1;
//         m->map[current_loc - width ] = 'Z';
//         printf("Top to %i %c\n", current_loc - width,m->map[current_loc - width]);
//         current_loc = current_loc - width;
//         check_box(m,(current_loc));
//     }
//     // left condation 
//     else if(((m->map[current_loc - 1] == 0 )|| (m->map[current_loc - 1] != 'Z' )) 
//         && (m->map[current_loc - 1] != '1' ))
//     {
//         if(exit_finder(m,current_loc -1))
//             return 1;
//         m->map[current_loc - 1 ] = 'Z';
//         printf("Left to %i %c\n",current_loc - 1,m->map[current_loc - 1]);
//         current_loc = current_loc - 1;
//         check_box(m,(current_loc ));
//     }
//     //bottom condation 
//     else if(((m->map[current_loc + width] == 0 ) || (m->map[current_loc + width] != 'Z' )) 
//         && (m->map[current_loc + width] != '1' ))
//     {
//         if(exit_finder(m,current_loc + width))
//             return 1;
//         m->map[current_loc + width ] = 'Z';
//         printf("Bottom  to %i %c\n", current_loc + width,m->map[current_loc + width]);
//         current_loc = current_loc + width;
//         check_box(m,(current_loc ));
//     }
//     // right condation 
//     else if(((m->map[current_loc + 1] == 0)||(m->map[current_loc + 1] != 'Z')) 
//         && (m->map[current_loc + 1] != '1'))
//     {
//         if(exit_finder(m,current_loc + 1))
//             return 1;
//         m->map[ current_loc + 1 ] = 'Z';
//         printf("Right to %i %c\n",current_loc + 1,m->map[current_loc + 1]);
//         current_loc = current_loc + 1;
//         check_box(m,(current_loc ));
//     }
//     else
//     {
//         print_map(m);
//         error_handling(8);
//         return (0);
//     }
// }

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
