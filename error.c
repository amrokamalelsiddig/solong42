/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:16:22 by aelsiddi          #+#    #+#             */
/*   Updated: 2023/01/06 10:05:41 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_handling(int i)
{
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
	exit(1);
}

void	error_handling1(int i, int fd, t_map *m)
{
	(void)m;
	if (fd >= 1)
	{
		close(fd);
	}
	if (i == 1)
		printf("map unvalied \n");
	else if (i == 3)
		ft_putstr_fd("\nborder unvalid\n", 1);
	else if (i == 8)
		printf("\nFileError : 3No Valid Path \n");
	else if (i == 11)
		printf("\n issue with width/hight\n");
	exit(1);
}

void	exiting(t_map *map, int flag)
{
	if (map->fd > 0)
		close(map->fd);
	if (map->fd2 > 0)
		close(map->fd2);
	if (map->fd3 > 0)
		close(map->fd3);
	if (flag == 1)
		ft_putstr_fd(">>>>> Game Over <<<<<\n", 1);
	if (flag == 2)
	{
		ft_putstr_fd(">>>>> NOOB !! <<<<<\n", 1);
	}
	if (flag == 3)
	{
		ft_putstr_fd(">>>>> Evaluator Gave up <<<<<\n", 1);
	}
	exit(0);
}
