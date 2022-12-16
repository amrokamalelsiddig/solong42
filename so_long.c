/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelsiddi <aelsiddi@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 22:18:26 by aelsiddi          #+#    #+#             */
/*   Updated: 2022/12/15 08:23:48 by aelsiddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_map	map;

	(void)ac;
	map.FD = open(argv[1],O_RDONLY);
	if (map.FD <= 0)
		error_handling(1);
	map.FD2 = open(argv[1],O_RDONLY);
	if (map.FD2 <= 0)
		error_handling(1);
	
	ft_init(&map);
	printf("fd is : %d\n", fd);
	dimension(&map);
	fill_map(&map);
	print_map(&map);
}
