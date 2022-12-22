/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:16:22 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/22 16:53:07 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_handling(int i)
{
    red();
    if (i == 1)
        ft_putstr_fd("map unvalied \n", 1);
    else if (i == 3)
        ft_putstr_fd("\nborder unvalid\n", 1);
    else if (i == 4)
        ft_putstr_fd("\nUpper / Lower boarder is not valid\n", 1);
    else if (i == 5)
        ft_putstr_fd("\nside boarder not valid\n", 1);
    else if (i == 6)
        ft_putstr_fd("\nreading error\n", 1);
    else if (i == 7)
        ft_putstr_fd("\nFailed >> Moved outside map boarder\n", 1);
    else if (i == 8)
        ft_putstr_fd("\nError : No Valid Path \n", 1);
    else if (i == 9)
        ft_putstr_fd("Failed >> 1 or More of Required Element Missing  \n", 1);
    else if (i == 10)
        ft_putstr_fd("\n invalid : File extension not ber\n", 1);
    else if (i == 11)
        ft_putstr_fd("\n issue with width/hight\n", 1);
    reset();
    exit(1);
}

void error_handling1(int i,int fd,t_map *m)
{
	(void)m;
	if(fd >-1)
	{
		close(fd);
	}
    red();
    if (i == 1)
        printf("map unvalied \n");
    else if (i == 8)
        printf("\nFileError : 3No Valid Path \n");
	else if (i == 11)
		printf("\n issue with width/hight\n");
    reset();
    exit(1);
}


void exiting(t_map *map, int flag)
{
    mlx_destroy_window(map->mlx,map->window);
    if (map->map)
        free(map->map);
    if (map->map_2)
        free(map->map_2);
    if (map->fd > 0)
        close(map->fd);
    if (flag == 1)      
        write(1,">>>>> Game Over <<<<<\n",22);
    if (flag == 2)
        write(1,">>>>> DIE HARD NOOB !! <<<<<\n",30);
    if (flag == 3)
        write(1,">>>>> Evaluator Gave up <<<<<\n",30);
    exit(1);
}